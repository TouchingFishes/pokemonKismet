#include "global.h"
#include "data.h"
#include "event_data.h"
#include "starter_generation.h"
#include "constants/opponents.h"
#include "constants/pokedex.h"
#include "constants/species.h"
#include "constants/vars.h"

// Elm's six trios, indexed [region][slot]. Slot order is fixed at
// Grass / Fire / Water in every generation, which is what lets the rival's
// type-matched held items and support rosters survive the substitution.
static const u16 sStarterTable[STARTER_REGION_COUNT][STARTER_SLOT_COUNT] =
{
    [STARTER_REGION_JOHTO]  = { SPECIES_CHIKORITA, SPECIES_CYNDAQUIL, SPECIES_TOTODILE },
    [STARTER_REGION_KANTO]  = { SPECIES_BULBASAUR, SPECIES_CHARMANDER, SPECIES_SQUIRTLE },
    [STARTER_REGION_HOENN]  = { SPECIES_TREECKO,   SPECIES_TORCHIC,    SPECIES_MUDKIP   },
    [STARTER_REGION_SINNOH] = { SPECIES_TURTWIG,   SPECIES_CHIMCHAR,   SPECIES_PIPLUP   },
    [STARTER_REGION_UNOVA]  = { SPECIES_SNIVY,     SPECIES_TEPIG,      SPECIES_OSHAWOTT },
    [STARTER_REGION_KALOS]  = { SPECIES_CHESPIN,   SPECIES_FENNEKIN,   SPECIES_FROAKIE  },
};

// The regions in generational order, which is not the order the constants are
// numbered in - Kanto is gen 1 but region 1, Johto is gen 2 but region 0.
// The secondary dex window is laid out with this, so it reads 1, 3, 4 when the
// player picked Johto.
static const u8 sRegionsByGeneration[STARTER_REGION_COUNT] =
{
    STARTER_REGION_KANTO,
    STARTER_REGION_JOHTO,
    STARTER_REGION_HOENN,
    STARTER_REGION_SINNOH,
    STARTER_REGION_UNOVA,
    STARTER_REGION_KALOS,
};

// Each generation's nine species as national dex numbers, in the order they
// occupy a dex window: the three lines Grass, Fire, Water, each base to final.
static const enum NationalDexOrder sStarterDexBlocks[STARTER_REGION_COUNT][STARTER_BLOCK_SIZE] =
{
    [STARTER_REGION_JOHTO] =
    {
        NATIONAL_DEX_CHIKORITA, NATIONAL_DEX_BAYLEEF,   NATIONAL_DEX_MEGANIUM,
        NATIONAL_DEX_CYNDAQUIL, NATIONAL_DEX_QUILAVA,   NATIONAL_DEX_TYPHLOSION,
        NATIONAL_DEX_TOTODILE,  NATIONAL_DEX_CROCONAW,  NATIONAL_DEX_FERALIGATR,
    },
    [STARTER_REGION_KANTO] =
    {
        NATIONAL_DEX_BULBASAUR,  NATIONAL_DEX_IVYSAUR,    NATIONAL_DEX_VENUSAUR,
        NATIONAL_DEX_CHARMANDER, NATIONAL_DEX_CHARMELEON, NATIONAL_DEX_CHARIZARD,
        NATIONAL_DEX_SQUIRTLE,   NATIONAL_DEX_WARTORTLE,  NATIONAL_DEX_BLASTOISE,
    },
    [STARTER_REGION_HOENN] =
    {
        NATIONAL_DEX_TREECKO, NATIONAL_DEX_GROVYLE,   NATIONAL_DEX_SCEPTILE,
        NATIONAL_DEX_TORCHIC, NATIONAL_DEX_COMBUSKEN, NATIONAL_DEX_BLAZIKEN,
        NATIONAL_DEX_MUDKIP,  NATIONAL_DEX_MARSHTOMP, NATIONAL_DEX_SWAMPERT,
    },
    [STARTER_REGION_SINNOH] =
    {
        NATIONAL_DEX_TURTWIG,  NATIONAL_DEX_GROTLE,   NATIONAL_DEX_TORTERRA,
        NATIONAL_DEX_CHIMCHAR, NATIONAL_DEX_MONFERNO, NATIONAL_DEX_INFERNAPE,
        NATIONAL_DEX_PIPLUP,   NATIONAL_DEX_PRINPLUP, NATIONAL_DEX_EMPOLEON,
    },
    [STARTER_REGION_UNOVA] =
    {
        NATIONAL_DEX_SNIVY,    NATIONAL_DEX_SERVINE,  NATIONAL_DEX_SERPERIOR,
        NATIONAL_DEX_TEPIG,    NATIONAL_DEX_PIGNITE,  NATIONAL_DEX_EMBOAR,
        NATIONAL_DEX_OSHAWOTT, NATIONAL_DEX_DEWOTT,   NATIONAL_DEX_SAMUROTT,
    },
    [STARTER_REGION_KALOS] =
    {
        NATIONAL_DEX_CHESPIN,  NATIONAL_DEX_QUILLADIN, NATIONAL_DEX_CHESNAUGHT,
        NATIONAL_DEX_FENNEKIN, NATIONAL_DEX_BRAIXEN,   NATIONAL_DEX_DELPHOX,
        NATIONAL_DEX_FROAKIE,  NATIONAL_DEX_FROGADIER, NATIONAL_DEX_GRENINJA,
    },
};

// Silver takes the starter that beats the player's, so each region/slot pair
// needs a party family of seven battles. Several pairs SHARE a family - which
// ones is Moritz's design, not a rule to extend (2026-09-28):
//
//   TURTWIG's    Torterra, Sceptile, (Serperior, Chesnaught)
//   CYNDAQUIL's  Typhlosion, Blaziken, Infernape, (Emboar)
//   SQUIRTLE's   Blastoise, Swampert
//
// A pair on someone else's family gets its own ace from sRivalAceBase below.
// The families are numbered alphabetically rather than by generation, so this
// cannot be arithmetic.
static const u16 sRivalTrainerBase[STARTER_REGION_COUNT][STARTER_SLOT_COUNT] =
{
    [STARTER_REGION_JOHTO] =
    {
        TRAINER_RIVAL_CHIKORITA_1_HNS, TRAINER_RIVAL_CYNDAQUIL_1_HNS, TRAINER_RIVAL_TOTODILE_1_HNS,
    },
    [STARTER_REGION_KANTO] =
    {
        TRAINER_RIVAL_BULBASAUR_1_HNS, TRAINER_RIVAL_CHARMANDER_1_HNS, TRAINER_RIVAL_SQUIRTLE_1_HNS,
    },
    [STARTER_REGION_HOENN] =
    {
        TRAINER_RIVAL_TURTWIG_1_HNS, TRAINER_RIVAL_CYNDAQUIL_1_HNS, TRAINER_RIVAL_SQUIRTLE_1_HNS,
    },
    [STARTER_REGION_SINNOH] =
    {
        TRAINER_RIVAL_TURTWIG_1_HNS, TRAINER_RIVAL_CYNDAQUIL_1_HNS, TRAINER_RIVAL_PIPLUP_1_HNS,
    },
    [STARTER_REGION_UNOVA] =
    {
        TRAINER_RIVAL_TURTWIG_1_HNS, TRAINER_RIVAL_CYNDAQUIL_1_HNS, TRAINER_RIVAL_TOTODILE_1_HNS,
    },
    [STARTER_REGION_KALOS] =
    {
        TRAINER_RIVAL_TURTWIG_1_HNS, TRAINER_RIVAL_FENNEKIN_1_HNS, TRAINER_RIVAL_FROAKIE_1_HNS,
    },
};

// The ace that replaces a shared family's own, per region/slot: the _1 of a line
// in src/data/rival_aces_hns.party, or RIVAL_ACE_NONE to keep the family's ace.
// Written out in full, NONE included, so the map reads at a glance - and so
// .claude/rival_overlap.py can resolve every party the game fights from it.
static const u8 sRivalAceBase[STARTER_REGION_COUNT][STARTER_SLOT_COUNT] =
{
    [STARTER_REGION_JOHTO]  = { RIVAL_ACE_NONE,       RIVAL_ACE_NONE,        RIVAL_ACE_NONE },
    [STARTER_REGION_KANTO]  = { RIVAL_ACE_NONE,       RIVAL_ACE_NONE,        RIVAL_ACE_NONE },
    [STARTER_REGION_HOENN]  = { RIVAL_ACE_SCEPTILE_1, RIVAL_ACE_BLAZIKEN_1,  RIVAL_ACE_SWAMPERT_1 },
    [STARTER_REGION_SINNOH] = { RIVAL_ACE_NONE,       RIVAL_ACE_INFERNAPE_1, RIVAL_ACE_NONE },
    [STARTER_REGION_UNOVA]  = { RIVAL_ACE_SERPERIOR_1,  RIVAL_ACE_EMBOAR_1,    RIVAL_ACE_SAMUROTT_1 },
    [STARTER_REGION_KALOS]  = { RIVAL_ACE_CHESNAUGHT_1, RIVAL_ACE_NONE,        RIVAL_ACE_NONE },
};

#define RIVAL_BATTLE_COUNT 7

u32 GetStarterRegion(void)
{
    u32 region = VarGet(VAR_STARTER_REGION);

    // A save made before this feature existed reads 0, which is Johto - the
    // trio the game shipped with.
    if (region >= STARTER_REGION_COUNT)
        region = STARTER_REGION_JOHTO;

    return region;
}

u16 GetStarterForRegionAndSlot(u32 region, u32 slot)
{
    if (region >= STARTER_REGION_COUNT)
        region = STARTER_REGION_JOHTO;
    if (slot >= STARTER_SLOT_COUNT)
        slot = STARTER_SLOT_GRASS;

    return sStarterTable[region][slot];
}

// callnative. Reads VAR_STARTER_REGION and VAR_STARTER_MON (the slot the player
// just walked up to), and writes VAR_TEMP_2 - the var Elm's lab script aliases
// as PLAYER_STARTER_SPECIES for its preview, cry and givemon.
void SetStarterSpeciesFromChoice(void)
{
    VarSet(VAR_TEMP_2, GetStarterForRegionAndSlot(GetStarterRegion(), VarGet(VAR_STARTER_MON)));
}

// Silver's parties for every region are in trainers_hns.party, but every
// script still branches to the Johto trainer IDs. Rather than rewrite
// twenty-one call sites across the maps, redirect the ID on the way out of
// GetTrainerStructFromId - which every other accessor funnels through, so the
// party preview, the match call and the prize-money lookup all follow.
u16 GetRivalTrainerIdForStarterChoice(u16 trainerId)
{
    u32 region, slot;

    if (!IS_HNS)
        return trainerId;

    if (trainerId < TRAINER_RIVAL_CHIKORITA_1_HNS
     || trainerId > TRAINER_RIVAL_TOTODILE_1_HNS + RIVAL_BATTLE_COUNT - 1)
        return trainerId;

    region = GetStarterRegion();
    if (region == STARTER_REGION_JOHTO)
        return trainerId;

    slot = (trainerId - TRAINER_RIVAL_CHIKORITA_1_HNS) / RIVAL_BATTLE_COUNT;
    return sRivalTrainerBase[region][slot]
         + (trainerId - TRAINER_RIVAL_CHIKORITA_1_HNS) % RIVAL_BATTLE_COUNT;
}

// The ace to swap into a shared family's party, or NULL to keep its own. Takes
// the SCRIPT's trainer ID - always a Johto one - like the function above, and
// recovers slot and encounter the same way. Called once per battle, from
// CreateNPCTrainerParty (src/battle_main.c), which does the swap.
//
// Only DIFFICULTY_NORMAL is populated in gRivalAces, and no rival party has a
// difficulty variant, so the ace does not follow the difficulty setting.
const struct TrainerMon *GetRivalAceOverride(u16 trainerId)
{
    u32 region, slot, encounter, ace;

    if (!IS_HNS)
        return NULL;

    if (trainerId < TRAINER_RIVAL_CHIKORITA_1_HNS
     || trainerId > TRAINER_RIVAL_TOTODILE_1_HNS + RIVAL_BATTLE_COUNT - 1)
        return NULL;

    region = GetStarterRegion();
    slot = (trainerId - TRAINER_RIVAL_CHIKORITA_1_HNS) / RIVAL_BATTLE_COUNT;
    encounter = (trainerId - TRAINER_RIVAL_CHIKORITA_1_HNS) % RIVAL_BATTLE_COUNT;
    ace = sRivalAceBase[region][slot];
    if (ace == RIVAL_ACE_NONE)
        return NULL;

    // A missing entry would leave .party NULL. Fall back to the family's own ace
    // rather than crash; .claude/rival_overlap.py is what catches the data error.
    if (gRivalAces[DIFFICULTY_NORMAL][ace + encounter].partySize == 0)
        return NULL;

    return &gRivalAces[DIFFICULTY_NORMAL][ace + encounter].party[0];
}

// The Johto dex carries all six starter generations. The chosen one occupies
// slots 1-9; the other five fill the secondary window in generational order.
// That window is sized from STARTER_REGION_COUNT, so adding a region means
// adding its nine JohtoDexOrder entries in the SAME change, or it overruns
// into the legendary birds. Both windows
// are resolved here, so sJohtoToNationalOrder only has to store the default
// layout (the player picked Johto).
//
// Returns FALSE for every dex slot outside the two windows, which is almost all
// of them - so the common path costs two range compares and never reads a var.
bool32 GetStarterJohtoDexEntry(u32 johtoNum, enum NationalDexOrder *natDexNum)
{
    u32 region, chosen, offset, block, slot, i, skipped;

    if (johtoNum >= JOHTO_DEX_STARTERS_PRIMARY
     && johtoNum < JOHTO_DEX_STARTERS_PRIMARY + STARTER_BLOCK_SIZE)
    {
        *natDexNum = sStarterDexBlocks[GetStarterRegion()][johtoNum - JOHTO_DEX_STARTERS_PRIMARY];
        return TRUE;
    }

    if (johtoNum >= JOHTO_DEX_STARTERS_SECONDARY
     && johtoNum < JOHTO_DEX_STARTERS_SECONDARY + (STARTER_REGION_COUNT - 1) * STARTER_BLOCK_SIZE)
    {
        offset = johtoNum - JOHTO_DEX_STARTERS_SECONDARY;
        block = offset / STARTER_BLOCK_SIZE;
        slot = offset % STARTER_BLOCK_SIZE;
        chosen = GetStarterRegion();

        for (i = 0, skipped = 0; i < STARTER_REGION_COUNT; i++)
        {
            region = sRegionsByGeneration[i];
            if (region == chosen)
                continue;

            if (skipped == block)
            {
                *natDexNum = sStarterDexBlocks[region][slot];
                return TRUE;
            }
            skipped++;
        }
    }

    return FALSE;
}
