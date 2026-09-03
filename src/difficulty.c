#include "global.h"
#include "data.h"
#include "event_data.h"
#include "script.h"
#include "constants/battle.h"
#include "constants/flags.h"
#include "constants/trainers.h"

// Baseline trainer level for each badge count, ported from the HnS 1.x fork
// (sBadgeCountLevelTable in its src/battle_setup.c). Four levels per badge
// through the eighth, then three - the curve flattens once Kanto starts.
//
// Sized by its own initialiser rather than NUM_BADGES so it works in every
// build: the HnS target has 16 badges, Emerald and FireRed have 8, and an
// 8-badge build simply never indexes past entry 8.
static const u8 sBadgeCountLevelTable[] =
{
     4,  8, 12, 16, 20, 24, 28, 35, 39,  //  0-8 badges
    40, 43, 46, 49, 52, 55, 58, 61,      // 9-16 badges
};

// The fork read VAR_NUM_BADGES here but counted badge FLAGS in GetScaledLevel,
// so its two scaling layers could disagree. Both go through this one function
// instead. Flags are also the portable choice: VAR_NUM_BADGES only exists in
// vars_hns.h, while FLAG_BADGE01_GET and NUM_BADGES are defined in all three
// flag headers.
u32 GetBadgeCount(void)
{
    u32 badgeCount = 0;
    u32 i;

    for (i = FLAG_BADGE01_GET; i < FLAG_BADGE01_GET + NUM_BADGES; i++)
    {
        if (FlagGet(i))
            badgeCount++;
    }

    if (badgeCount >= ARRAY_COUNT(sBadgeCountLevelTable))
        badgeCount = ARRAY_COUNT(sBadgeCountLevelTable) - 1;

    return badgeCount;
}

// Decodes a party mon's .lvl field. Levels up to MAX_LEVEL are literal and pass
// through untouched; anything above it is LEVEL_BASED_ON_BADGE plus a signed
// offset, resolved against the player's badge count. See the comment on
// LEVEL_BASED_ON_BADGE in include/constants/trainers.h.
u32 ResolveTrainerMonLevel(u32 lvlField)
{
    s32 level;

    if (lvlField <= MAX_LEVEL)
        return lvlField;

    level = (s32)sBadgeCountLevelTable[GetBadgeCount()] + ((s32)lvlField - LEVEL_BASED_ON_BADGE);

    if (level < 1)
        level = 1;
    if (level > MAX_LEVEL)
        level = MAX_LEVEL;

    return (u32)level;
}

// The single entry point used at party creation: resolves a badge-relative
// level, then applies the optional difficulty offset on top.
u32 GetScaledTrainerMonLevel(u32 lvlField)
{
    s32 level = (s32)ResolveTrainerMonLevel(lvlField);

    if (B_LEVEL_SCALING_DIFFICULTY)
    {
        enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();
        u32 badgeCount = GetBadgeCount();
        s32 scaling;

        if (FlagGet(FLAG_IS_CHAMPION))
            scaling = 10;
        else if (badgeCount >= 6)
            scaling = 6;
        else if (badgeCount >= 3)
            scaling = 3;
        else if (badgeCount >= 1)
            scaling = 2;
        else
            scaling = 1;

        // Signed on purpose. The fork did this arithmetic on a u8, so an EASY
        // subtraction that went below zero wrapped to ~250 and was then clamped
        // UP to MAX_LEVEL - turning a low-level mon into a level 100 one. The
        // clamps below only work if the intermediate cannot wrap.
        if (difficulty == DIFFICULTY_HARD)
            level += scaling;
        else if (difficulty == DIFFICULTY_EASY)
            level -= scaling;

        if (level < 1)
            level = 1;
        if (level > MAX_LEVEL)
            level = MAX_LEVEL;
    }

    return (u32)level;
}

enum DifficultyLevel GetCurrentDifficultyLevel(void)
{
    if (!B_VAR_DIFFICULTY)
        return DIFFICULTY_NORMAL;

    return VarGet(B_VAR_DIFFICULTY);
}

void SetCurrentDifficultyLevel(enum DifficultyLevel desiredDifficulty)
{
    if (!B_VAR_DIFFICULTY)
        return;

    if (desiredDifficulty > DIFFICULTY_MAX)
        desiredDifficulty = DIFFICULTY_MAX;

    VarSet(B_VAR_DIFFICULTY, desiredDifficulty);
}

enum DifficultyLevel GetBattlePartnerDifficultyLevel(u16 partnerId)
{
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    if (partnerId > TRAINER_PARTNER(PARTNER_NONE))
        partnerId -= TRAINER_PARTNER(PARTNER_NONE);

    if (difficulty == DIFFICULTY_NORMAL)
        return DIFFICULTY_NORMAL;

    if (gBattlePartners[difficulty][partnerId].party == NULL)
        return DIFFICULTY_NORMAL;

    return difficulty;
}

enum DifficultyLevel GetTrainerDifficultyLevel(u16 trainerId)
{
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    if (difficulty == DIFFICULTY_NORMAL)
        return DIFFICULTY_NORMAL;

    if (gTrainers[difficulty][trainerId].party == NULL)
        return DIFFICULTY_NORMAL;

    return difficulty;
}

void Script_IncreaseDifficulty(void)
{
    enum DifficultyLevel currentDifficulty;

    if (!B_VAR_DIFFICULTY)
        return;

    currentDifficulty = GetCurrentDifficultyLevel();

    if (currentDifficulty++ > DIFFICULTY_MAX)
        return;

    Script_RequestEffects(SCREFF_V1);
    Script_RequestWriteVar(B_VAR_DIFFICULTY);

    SetCurrentDifficultyLevel(currentDifficulty);
}

void Script_DecreaseDifficulty(void)
{
    enum DifficultyLevel currentDifficulty;

    if (!B_VAR_DIFFICULTY)
        return;

    currentDifficulty = GetCurrentDifficultyLevel();

    if (!currentDifficulty)
        return;

    Script_RequestEffects(SCREFF_V1);
    Script_RequestWriteVar(B_VAR_DIFFICULTY);

    SetCurrentDifficultyLevel(--currentDifficulty);
}

void Script_GetDifficulty(void)
{
    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = GetCurrentDifficultyLevel();
}

void Script_SetDifficulty(struct ScriptContext *ctx)
{
    enum DifficultyLevel desiredDifficulty = ScriptReadByte(ctx);

    Script_RequestEffects(SCREFF_V1);
    Script_RequestWriteVar(B_VAR_DIFFICULTY);

    SetCurrentDifficultyLevel(desiredDifficulty);
}
