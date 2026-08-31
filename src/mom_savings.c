#include "global.h"
#include "mom_savings.h"
#include "main.h"
#include "item.h"
#include "random.h"
#include "constants/items.h"
#include "constants/decorations.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "event_data.h"
#include "string_util.h"
#include "strings.h"
#include "script.h"
#include "menu_helpers.h"
#include "money.h"
#include "menu.h"
#include "task.h"
#include "sound.h"
#include "constants/songs.h"
#include "text_window.h"
#include "palette.h"
#include "window.h"
#include "bg.h"
#include "fieldmap.h"
#include "constants/map_types.h"
#include "decoration_inventory.h"
#include "randomizer.h"
#include "difficulty.h"
#include "constants/characters.h"

extern const u8 EventScript_MomGiftCall_Item[];
extern const u8 EventScript_MomGiftCall_Berry[];
extern const u8 EventScript_MomGiftCall_Decoration[];
extern const u8 EventScript_MomGiftCall_Rare[];

#define MAX_PLAYER_MONEY 9999999
#define MOM_GIFT_STARTER_DOLL 0xFFFF


static const struct MomGiftSequential sMomGifts_Sequential[] = {
    {ITEM_SUPER_POTION,      900,    600,   FALSE},
    {ITEM_REPEL,             4000,   270,   FALSE},
    {ITEM_SILK_SCARF,        7000,   600,   FALSE},
    {MOM_GIFT_STARTER_DOLL,  10000,  1000,   TRUE},
    {ITEM_MOON_STONE,        15000,  2100,  FALSE},
    {ITEM_HYPER_POTION,      19000,  1200,  FALSE},
    {ITEM_LEFTOVERS,         30000,  1500,  FALSE},
    {ITEM_CHOICE_BAND,       40000,  100,   FALSE},
    {DECOR_SNORLAX_DOLL,     50000,  22800, TRUE},
    {ITEM_MASTER_BALL,       100000, 50000, FALSE},
};

#define MOM_ITEMS_SEQUENTIAL_COUNT ARRAY_COUNT(sMomGifts_Sequential)

/*  normalGiftFlags bits 0..MOM_ITEMS_SEQUENTIAL_COUNT-1 mark which sequential
 *  gifts have already been given
 *
 *  This is recorded rather than inferred. Asking "is the item in
 *  sMomRareItemTable?" looks equivalent and is not: ITEM_MOON_STONE sits in both
 *  that table and the sequential ladder, so the milestone gift would be
 *  announced as a bargain hunt.
 */
#define MOM_FLAG_GIFT_IS_RARE (1 << 15)
STATIC_ASSERT(MOM_ITEMS_SEQUENTIAL_COUNT <= 15, MomRareFlagCollidesWithGiftFlags);

static const u16 sMomGifts_Berries[] = {
    ITEM_PECHA_BERRY,
    ITEM_RAWST_BERRY,
    ITEM_CHERI_BERRY,
    ITEM_ORAN_BERRY,
    ITEM_CHESTO_BERRY,
    ITEM_ASPEAR_BERRY,
    ITEM_PERSIM_BERRY,
};

#define MOM_BERRIES_COUNT ARRAY_COUNT(sMomGifts_Berries)

/*  Badge-tiered purchases, ported over. Between the sequential milestone gifts above, Mom
 *  spends the savings on something useful, and what she can reach scales with
 *  the player's badges: a 9-wide window slides up sMomItemTable as the tier
 *  rises
 */

// Cumulative percentages, one per window slot. Index 0 is the cheapest item in
// the current tier and the most likely; index 8 is the priciest and rarest.
// The last entry is the fallthrough - Mom_CheckBadgeTierPurchase never tests it,
// so its value only documents that the ladder ends at 100.
static const u16 sMomItemProbabilities[] = { 30, 42, 53, 63, 72, 80, 87, 94, 100 };

// Cheap -> pricey. 18 entries: the window is 9 wide and the tier maxes at 9.
static const u16 sMomItemTable[] =
{
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_AWAKENING,
    ITEM_BURN_HEAL,
    ITEM_SUPER_POTION,
    ITEM_GREAT_BALL,
    ITEM_FULL_HEAL,
    ITEM_REPEL,
    ITEM_ULTRA_BALL,
    ITEM_HYPER_POTION,
    ITEM_ETHER,
    ITEM_REVIVE,
    ITEM_MAX_ETHER,
    ITEM_FULL_RESTORE,
    ITEM_MAX_REVIVE,
    ITEM_PP_UP,
    ITEM_NUGGET,
    ITEM_KINGS_ROCK,
};

// MOM_RARE_ITEM_CHANCE% of the time she ignores the tier window and picks here.
static const u16 sMomRareItemTable[] =
{
    ITEM_FIRE_STONE,
    ITEM_THUNDER_STONE,
    ITEM_WATER_STONE,
    ITEM_MOON_STONE,
    ITEM_SUN_STONE,
    ITEM_WISE_GLASSES,
    ITEM_MUSCLE_BAND,
    ITEM_RARE_CANDY,
};

// Articles for BufferMomGiftItemName(). Lower case: they sit mid-sentence.
static const u8 gText_MomArticle_A[]    = _("a");
static const u8 gText_MomArticle_An[]   = _("an");
static const u8 gText_MomArticle_Some[] = _("some");

#define MOM_RARE_ITEM_CHANCE 5   // percent
#define MOM_WINDOW_SIZE      ARRAY_COUNT(sMomItemProbabilities)
#define MOM_MAX_TIER         (ARRAY_COUNT(sMomItemTable) - MOM_WINDOW_SIZE)
#define MOM_DISCOUNT_NUM     9   // she shops the sales: 10% off
#define MOM_DISCOUNT_DEN     10

// Both are unsigned, so a table shorter than the window would not give a
// negative MOM_MAX_TIER - it would wrap to an enormous one, the tier clamp in
// Mom_CheckBadgeTierPurchase would never fire, and the window would run off the
// end of the table.
STATIC_ASSERT(ARRAY_COUNT(sMomItemTable) >= MOM_WINDOW_SIZE, MomItemTableShorterThanWindow);

/*  These only choose - they never spend. Storage can refuse the item (a full PC
 *  or a full decoration inventory), and money taken for a gift that never
 *  arrives is gone twice over, so Mom_CheckForGiftPurchase stores first and
 *  settles up afterwards. Each selector reports what the choice would cost.
 */
static bool8 Mom_CheckSequentialGifts(u32 balance, u16 *purchasedItem, u32 *giftIndex);
static void Mom_CommitSequentialGift(u32 giftIndex);
static bool8 Mom_CheckBadgeTierPurchase(u16 *purchasedItem, u16 *quantity, u32 *cost);
static bool8 Mom_CheckRandomBerries(u16 *purchasedItem, u32 *cost);
static bool8 Mom_AddItemToPC(u16 itemId, u16 quantity, bool8 isDecoration);

void InitMomSavings(void)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;
    mom->momsMoney = 0;
    mom->normalGiftFlags = 0;
    mom->isSavingMoney = FALSE;
    mom->isInitialized = TRUE;
}

void Mom_EnsureInitialized(void)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;

    if (mom->isInitialized == TRUE)
        return;

    mom->momsMoney = 0;
    mom->normalGiftFlags = 0;
    mom->isSavingMoney = FALSE;
    mom->isInitialized = TRUE;
}

void Mom_EnableSaving(bool8 enable)
{
    gSaveBlock1Ptr->momSavings.isSavingMoney = enable;
}

bool8 Mom_IsSavingEnabled(void)
{
    return gSaveBlock1Ptr->momSavings.isSavingMoney;
}

u32 Mom_GetBalance(void)
{
    return gSaveBlock1Ptr->momSavings.momsMoney;
}

// Returns the amount actually banked, like Mom_AutoDepositFromBattle
u32 Mom_TryDepositMoney(u32 amount)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;
    u32 capacity = MOM_MAX_MONEY - mom->momsMoney;

    if (amount > capacity)
        amount = capacity;

    mom->momsMoney += amount;

    Mom_CheckForGiftPurchase(mom->momsMoney, FALSE);
    return amount;
}

// Returns the amount actually banked
u32 Mom_AutoDepositFromBattle(u32 amount)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;
    u32 oldBalance = mom->momsMoney;
    u32 capacity = MOM_MAX_MONEY - oldBalance;

    if (amount > capacity)
        amount = capacity;

    mom->momsMoney = oldBalance + amount;

    // Called even when nothing was banked: at the cap, spending is the only
    // thing that can bring the balance back down.
    Mom_CheckForGiftPurchase(mom->momsMoney, TRUE);
    return amount;
}

bool8 Mom_TryWithdrawMoney(u32 amount)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;

    if (mom->momsMoney < amount)
        return FALSE;

    mom->momsMoney -= amount;
    return TRUE;
}

bool8 Mom_CheckForGiftPurchase(u32 balance, bool8 isAutomatic)
{
    u16 purchasedItem = ITEM_NONE;
    u16 quantity = 1;
    bool8 isDecoration = FALSE;
    u32 giftIndex = 0;
    u32 cost = 0;

    if (FlagGet(FLAG_MOM_HAS_GIFT))
        return FALSE;

    // Nothing is waiting, so any rare marker left from the last gift is stale.
    // Cleared here rather than when the call is answered, so it cannot outlive
    // the gift it described.
    gSaveBlock1Ptr->momSavings.normalGiftFlags &= ~MOM_FLAG_GIFT_IS_RARE;

    if (Mom_CheckSequentialGifts(balance, &purchasedItem, &giftIndex))
    {
        // Read from the chosen row rather than searching the table by item id:
        // the starter doll resolves to a species-specific decoration below, and
        // the randomizer can replace an ordinary gift outright, so by the time
        // the item is added it may not appear in the table at all.
        isDecoration = sMomGifts_Sequential[giftIndex].isDecoration;

        if (purchasedItem == MOM_GIFT_STARTER_DOLL)
        {
            u16 starterChoice = VarGet(VAR_STARTER_MON);
            switch (starterChoice)
            {
                case 0:
                    purchasedItem = DECOR_CHIKORITA_DOLL;
                    break;
                case 1:
                    purchasedItem = DECOR_CYNDAQUIL_DOLL;
                    break;
                case 2:
                    purchasedItem = DECOR_TOTODILE_DOLL;
                    break;
                default:
                    purchasedItem = DECOR_TOGEPI_DOLL;
                    break;
            }
        }
        else
        {
#if RANDOMIZER_AVAILABLE
            if (!isDecoration && RandomizerFeatureEnabled(RANDOMIZE_FIELD_ITEMS))
                purchasedItem = RandomizeFoundItem(purchasedItem, 0, 0, 0);
#endif
        }

        quantity = 1;
        if (!Mom_AddItemToPC(purchasedItem, quantity, isDecoration))
            return FALSE;   // No room. Nothing spent, and the milestone stays unclaimed.

        Mom_CommitSequentialGift(giftIndex);

        VarSet(VAR_MOM_GIFT_ITEM, purchasedItem);
        VarSet(VAR_MOM_GIFT_QUANTITY, isDecoration ? 0 : quantity);
        FlagSet(FLAG_MOM_HAS_GIFT);

        return TRUE;
    }

    // Between milestones, Mom shops. Quantity defaults to the berry count and
    // is overwritten to 1 when she buys a real item, since berries come in
    // handfuls and purchases do not.
    quantity = MOM_BERRY_QUANTITY;
    if (isAutomatic && Mom_CheckBadgeTierPurchase(&purchasedItem, &quantity, &cost))
    {
        if (!Mom_AddItemToPC(purchasedItem, quantity, FALSE))
        {
            // No room in the PC. Nothing was spent, so drop the rare marker too
            // and leave the daily flag clear - she tries again on the next
            // deposit rather than losing the day.
            gSaveBlock1Ptr->momSavings.normalGiftFlags &= ~MOM_FLAG_GIFT_IS_RARE;
            return FALSE;
        }

        gSaveBlock1Ptr->momSavings.momsMoney -= cost;
        FlagSet(FLAG_DAILY_MOM_ITEM_GIFT);

        VarSet(VAR_MOM_GIFT_ITEM, purchasedItem);
        VarSet(VAR_MOM_GIFT_QUANTITY, quantity);
        FlagSet(FLAG_MOM_HAS_GIFT);

        return TRUE;
    }

    return FALSE;
}

static bool8 Mom_CheckSequentialGifts(u32 balance, u16 *purchasedItem, u32 *giftIndex)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;

    for (u32 i = 0; i < MOM_ITEMS_SEQUENTIAL_COUNT; i++)
    {
        if (mom->normalGiftFlags & (1 << i))
            continue;

        if (balance < sMomGifts_Sequential[i].threshold)
            continue;

        *purchasedItem = sMomGifts_Sequential[i].itemId;
        *giftIndex = i;

        return TRUE;
    }

    return FALSE;
}

// Marks the milestone spent. Every row costs less than the threshold that
// unlocks it, and the balance has already reached that threshold, so the
// subtraction cannot underflow.
static void Mom_CommitSequentialGift(u32 giftIndex)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;

    mom->normalGiftFlags |= (1 << giftIndex);
    mom->momsMoney -= sMomGifts_Sequential[giftIndex].cost;
}

static u32 Mom_GetDiscountedPrice(u16 itemId)
{
    return (GetItemPrice((enum Item)itemId) * MOM_DISCOUNT_NUM) / MOM_DISCOUNT_DEN;
}

/*  Mom shops once a day, which is how the fork paced it: TryMomPurchase sat
 *  behind FLAG_DAILY_MOM_ITEM_GIFT, so calling on her twice in a day bought
 *  nothing the second time.
 *
 *  2.0 paced it instead on the balance crossing a multiple of
 *  MOM_RANDOM_THRESHOLD, which does not survive contact with the fork's item
 *  table. That test is not a ratchet: her own purchase drops the balance back
 *  below the boundary it just crossed, so the next small deposit re-crosses it
 *  and she buys again. With deposits smaller than the item price - the normal
 *  early game, where a quarter of a trainer prize is tens of yen against a
 *  ~180 item - the savings pin to the boundary and never grow, which also puts
 *  every milestone past the first out of reach. It was tolerable in 2.0 only
 *  because the sole purchase there was a 100 berry.
 */
static bool8 Mom_CheckBadgeTierPurchase(u16 *purchasedItem, u16 *quantity, u32 *cost)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;
    u32 tier, roll, slot;
    u16 chosenItem;
    u32 price;

    if (FlagGet(FLAG_DAILY_MOM_ITEM_GIFT))
        return FALSE;

    bool8 isRare = FALSE;

    if ((Random() % 100) < MOM_RARE_ITEM_CHANCE)
    {
        chosenItem = sMomRareItemTable[Random() % ARRAY_COUNT(sMomRareItemTable)];
        isRare = TRUE;
    }
    else
    {
        // The window is sMomItemTable[tier .. tier + 8]. The table only reaches
        // MOM_MAX_TIER (9), so the ninth badge opens the top window and any
        // beyond it change nothing - HnS has 16 badges, the other builds 8.
        tier = GetBadgeCount();
        if (tier > MOM_MAX_TIER)
            tier = MOM_MAX_TIER;

        // Stops one short of the end so the last slot is the fallthrough. That
        // keeps slot within the window whatever the probability ladder says:
        // relying on it ending at exactly 100 would put slot at MOM_WINDOW_SIZE
        // the moment anyone retuned the last entry, reading one past the table.
        roll = Random() % 100;
        for (slot = 0; slot < MOM_WINDOW_SIZE - 1; slot++)
        {
            if (sMomItemProbabilities[slot] > roll)
                break;
        }

        chosenItem = sMomItemTable[tier + slot];
    }

    price = Mom_GetDiscountedPrice(chosenItem);

    // Priceless or unaffordable: fall back to a berry rather than skipping the
    // cycle entirely, which is what the fork did. Keeping the berry keeps 2.0's
    // content alive and means Mom never silently does nothing.
    if (price == 0 || price > mom->momsMoney)
        return Mom_CheckRandomBerries(purchasedItem, cost);

    *purchasedItem = chosenItem;
    *quantity = 1;
    *cost = price;

    // Set here rather than by the caller because only this function knows which
    // table the item came from. The caller clears it again if storage refuses
    // the item, and Mom_CheckForGiftPurchase clears it whenever nothing is
    // waiting, so it cannot describe a gift that was never bought.
    if (isRare)
        mom->normalGiftFlags |= MOM_FLAG_GIFT_IS_RARE;

    return TRUE;
}

// Only reached from Mom_CheckBadgeTierPurchase, which has already checked the
// daily flag, so this does not re-check it.
static bool8 Mom_CheckRandomBerries(u16 *purchasedItem, u32 *cost)
{
    struct MomSavingsData *mom = &gSaveBlock1Ptr->momSavings;

    if (mom->momsMoney < MOM_BERRY_COST)
        return FALSE;

    u32 randomIndex = Random() % MOM_BERRIES_COUNT;
    u16 berryId = sMomGifts_Berries[randomIndex];

    *purchasedItem = berryId;
    *cost = MOM_BERRY_COST;

    return TRUE;
}

static bool8 Mom_GiftIsBerry(void)
{
    u16 item = VarGet(VAR_MOM_GIFT_ITEM);
    return (item >= ITEM_CHERI_BERRY && item <= ITEM_ENIGMA_BERRY);
}

// Did Mom turn up something out of the ordinary? See MOM_FLAG_GIFT_IS_RARE
// for why this is recorded at purchase rather than inferred from the item.
static bool8 Mom_GiftIsSpecial(void)
{
    return (gSaveBlock1Ptr->momSavings.normalGiftFlags & MOM_FLAG_GIFT_IS_RARE) != 0;
}

static bool8 Mom_GiftIsDecoration(void)
{
    return (VarGet(VAR_MOM_GIFT_QUANTITY) == 0);
}

bool8 Mom_TryTriggerGiftCall(void)
{
    u8 mapType = gMapHeader.mapType;

    if (!FlagGet(FLAG_MOM_HAS_GIFT))
        return FALSE;

    if (mapType != MAP_TYPE_ROUTE && mapType != MAP_TYPE_OCEAN_ROUTE
     && mapType != MAP_TYPE_CITY && mapType != MAP_TYPE_TOWN)
        return FALSE;

    if (Mom_GiftIsDecoration())
        ScriptContext_SetupScript(EventScript_MomGiftCall_Decoration);
    else if (Mom_GiftIsBerry())
        ScriptContext_SetupScript(EventScript_MomGiftCall_Berry);
    else if (Mom_GiftIsSpecial())
        ScriptContext_SetupScript(EventScript_MomGiftCall_Rare);
    else
        ScriptContext_SetupScript(EventScript_MomGiftCall_Item);

    return TRUE;
}

// ===== Money Input UI =====

#define MOM_MAX_INPUT 999999

enum {
    WIN_MOM_MONEY,
    WIN_MOM_INPUT,
    WIN_MOM_MESSAGE,
};

static const struct WindowTemplate sMomInputWindowTemplates[] = {
    [WIN_MOM_MONEY] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x001E,
    },
    [WIN_MOM_INPUT] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 11,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x018E,
    },
    [WIN_MOM_MESSAGE] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x01A2,
    },
    DUMMY_WIN_TEMPLATE
};

static u32 sMomInputAmount = 0;
static u32 sMomInputMaxAmount = 0;

#define tIsDeposit      data[0]
#define tWindowMoney    data[1]
#define tWindowInput    data[2]
#define tWindowMessage  data[3]

static void Task_MomInput_ShowMessage(u8 taskId);
static void Task_MomInput_InitAmountDialogue(u8 taskId);
static void Task_MomInput_HandleInput(u8 taskId);
static void MomInput_CleanupWindows(u8 taskId);

static void MomInput_DisplayMessage(u8 taskId, const u8 *text, TaskFunc callback)
{
    s16 *data = gTasks[taskId].data;
    DisplayMessageAndContinueTask(taskId, tWindowMessage, 10, 14, FONT_NORMAL, GetPlayerTextSpeedDelay(), text, callback);
    ScheduleBgCopyTilemapToVram(0);
}

static void MomInput_PrintAmount(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(tWindowInput, PIXEL_FILL(1));
    PrintMoneyAmount(tWindowInput, 0, 1, sMomInputAmount, 0);
}

static void Task_MomInput_ShowMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    const u8 *text = tIsDeposit ? gText_MomHowMuchDeposit : gText_MomHowMuchWithdraw;
    MomInput_DisplayMessage(taskId, text, Task_MomInput_InitAmountDialogue);
}

static void Task_MomInput_InitAmountDialogue(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    DrawStdFrameWithCustomTileAndPalette(tWindowInput, FALSE, 1, 13);
    MomInput_PrintAmount(taskId);
    ScheduleBgCopyTilemapToVram(0);

    gTasks[taskId].func = Task_MomInput_HandleInput;
}

static void Task_MomInput_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput_MomVersion(&sMomInputAmount, sMomInputMaxAmount) == TRUE)
    {
        MomInput_PrintAmount(taskId);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        /*  Report what actually moved, not what was asked for. Both sides are
         *  capped, and sMomInputMaxAmount does not fully protect against that:
         *  the amount seeds at 1 while the cap can leave room for 0, because
         *  AdjustQuantityAccordingToDPadInput_MomVersion clamps only on D-pad
         *  input, never on entry
         */
        if (tIsDeposit)
        {
            u32 banked;

            RemoveMoney(&gSaveBlock1Ptr->money, sMomInputAmount);
            banked = Mom_TryDepositMoney(sMomInputAmount);
            if (banked < sMomInputAmount)
                AddMoney(&gSaveBlock1Ptr->money, sMomInputAmount - banked);

            gSpecialVar_0x8000 = banked;
        }
        else
        {
            u32 room = MAX_PLAYER_MONEY - GetMoney(&gSaveBlock1Ptr->money);
            u32 taken = min(sMomInputAmount, room);

            if (taken != 0 && Mom_TryWithdrawMoney(taken) == TRUE)
                AddMoney(&gSaveBlock1Ptr->money, taken);
            else
                taken = 0;

            gSpecialVar_0x8000 = taken;
        }

        MomInput_CleanupWindows(taskId);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        gSpecialVar_0x8000 = 0;

        MomInput_CleanupWindows(taskId);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

static void MomInput_CleanupWindows(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveMoneyLabelObject();

    ClearStdWindowAndFrameToTransparent(tWindowMoney, FALSE);
    ClearWindowTilemap(tWindowMoney);
    RemoveWindow(tWindowMoney);

    ClearStdWindowAndFrameToTransparent(tWindowInput, FALSE);
    ClearWindowTilemap(tWindowInput);
    RemoveWindow(tWindowInput);

    ClearDialogWindowAndFrameToTransparent(tWindowMessage, FALSE);
    ClearWindowTilemap(tWindowMessage);
    RemoveWindow(tWindowMessage);

    ScheduleBgCopyTilemapToVram(0);
}

static void MomInput_Open(bool8 isDeposit)
{
    u8 taskId = CreateTask(Task_MomInput_ShowMessage, 8);
    s16 *data = gTasks[taskId].data;

    tWindowMoney = AddWindow(&sMomInputWindowTemplates[WIN_MOM_MONEY]);
    tWindowInput = AddWindow(&sMomInputWindowTemplates[WIN_MOM_INPUT]);
    tWindowMessage = AddWindow(&sMomInputWindowTemplates[WIN_MOM_MESSAGE]);

    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(tWindowMoney, 1, BG_PLTT_ID(13));
    LoadMessageBoxGfx(tWindowMoney, 0xA, BG_PLTT_ID(14));
    PutWindowTilemap(tWindowMoney);
    PutWindowTilemap(tWindowMessage);

    tIsDeposit = isDeposit;
    sMomInputAmount = 1;

    if (isDeposit)
        PrintMoneyAmountInMoneyBoxWithBorder(tWindowMoney, 1, 13, GetMoney(&gSaveBlock1Ptr->money));
    else
        PrintMoneyAmountInMoneyBoxWithBorder(tWindowMoney, 1, 13, Mom_GetBalance());

    AddMoneyLabelObject(19, 11);

    if (isDeposit)
    {
        u32 momsRemainingCapacity = MOM_MAX_MONEY - Mom_GetBalance();
        u32 playersAvailableMoney = GetMoney(&gSaveBlock1Ptr->money);
        sMomInputMaxAmount = min(MOM_MAX_INPUT, min(playersAvailableMoney, momsRemainingCapacity));
    }
    else
    {
        u32 playersWalletCapacity = MAX_PLAYER_MONEY - GetMoney(&gSaveBlock1Ptr->money);
        u32 momsAvailableMoney = Mom_GetBalance();
        sMomInputMaxAmount = min(MOM_MAX_INPUT, min(momsAvailableMoney, playersWalletCapacity));
    }

    ScriptContext_Stop();
}

// FALSE when storage is full
static bool8 Mom_AddItemToPC(u16 itemId, u16 quantity, bool8 isDecoration)
{
    if (isDecoration)
        return DecorationAdd(itemId);

    return AddPCItem(itemId, quantity);
}

/*  Buffers the gift Mom is calling about so her dialogue can name it:
 *    gStringVar1 = the item's name
 *    gStringVar2 = the article to put in front of it
 *
 *  The article is the whole reason this is a special rather than a plain
 *  bufferitemname. Naming a dynamically chosen item breaks grammar in two ways,
 *  and both are covered here:
 *
 *    - "a" vs "an"      -> ANTIDOTE, AWAKENING, ETHER, ORAN BERRY, ULTRA BALL
 *    - mass/plural      -> LEFTOVERS, which must be "some", never "a"
 *
 *  Verified exhaustively against every item Mom can reach: the sequential
 *  ladder, sMomItemTable, sMomRareItemTable and the berries -- 34 in total, all
 *  correct under these rules. If items are ever added to those tables, re-check:
 *  the trap to watch for is a consonant-sounding vowel ("a UNIQUE...") or a
 *  vowel-sounding consonant ("an HOUR..."), neither of which occurs today.
 */
void BufferMomGiftItemName(void)
{
    u16 itemId = VarGet(VAR_MOM_GIFT_ITEM);
    const u8 *name = GetItemName((enum Item)itemId);
    u8 first;

    StringCopy(gStringVar1, name);

    first = gStringVar1[0];
    if (first >= CHAR_a && first <= CHAR_z)
        first -= (CHAR_a - CHAR_A);

    // Trailing S means a plural or mass noun, unless it is a double S.
    {
        u32 len = StringLength(gStringVar1);
        u8 last = len ? gStringVar1[len - 1] : EOS;
        u8 prev = len > 1 ? gStringVar1[len - 2] : EOS;

        if (last == CHAR_S && prev != CHAR_S)
        {
            StringCopy(gStringVar2, gText_MomArticle_Some);
            return;
        }
    }

    if (first == CHAR_A || first == CHAR_E || first == CHAR_I
     || first == CHAR_O || first == CHAR_U)
        StringCopy(gStringVar2, gText_MomArticle_An);
    else
        StringCopy(gStringVar2, gText_MomArticle_A);
}

void Special_MomEnableSaving(void)
{
    Mom_EnableSaving(TRUE);
}

void Special_MomDisableSaving(void)
{
    Mom_EnableSaving(FALSE);
}

void Special_MomGetBalance(void)
{
    u32 balance = Mom_GetBalance();
    ConvertIntToDecimalStringN(gStringVar1, balance, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar2, gText_PokedollarVar1);
    gSpecialVar_Result = balance;
}


void Special_MomIsSavingEnabled(void)
{
    gSpecialVar_Result = Mom_IsSavingEnabled();
}

void Special_MomEnsureInitialized(void)
{
    Mom_EnsureInitialized();
}

void Special_MomOpenDepositInput(void)
{
    MomInput_Open(TRUE);
}

void Special_MomOpenWithdrawInput(void)
{
    MomInput_Open(FALSE);
}

#undef tIsDeposit
#undef tWindowMoney
#undef tWindowInput
#undef tWindowMessage
