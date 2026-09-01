#include "global.h"
#include "event_data.h"
#include "starter_generation.h"
#include "constants/opponents.h"
#include "constants/pokedex.h"
#include "constants/species.h"
#include "constants/vars.h"

// Elm's four trios, indexed [region][slot]. Slot order is fixed at
// Grass / Fire / Water in every generation, which is what lets the rival's
// type-matched held items and support rosters survive the substitution.
static const u16 sStarterTable[STARTER_REGION_COUNT][STARTER_SLOT_COUNT] =
{
    [STARTER_REGION_JOHTO]  = { SPECIES_CHIKORITA, SPECIES_CYNDAQUIL, SPECIES_TOTODILE },
    [STARTER_REGION_KANTO]  = { SPECIES_BULBASAUR, SPECIES_CHARMANDER, SPECIES_SQUIRTLE },
    [STARTER_REGION_HOENN]  = { SPECIES_TREECKO,   SPECIES_TORCHIC,    SPECIES_MUDKIP   },
    [STARTER_REGION_SINNOH] = { SPECIES_TURTWIG,   SPECIES_CHIMCHAR,   SPECIES_PIPLUP   },
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
};

// Silver takes the starter that beats the player's, so each region has three
// party families of seven battles each. The families are numbered
// alphabetically rather than by generation, so this cannot be arithmetic.
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
        TRAINER_RIVAL_TREECKO_1_HNS, TRAINER_RIVAL_TORCHIC_1_HNS, TRAINER_RIVAL_MUDKIP_1_HNS,
    },
    [STARTER_REGION_SINNOH] =
    {
        TRAINER_RIVAL_TURTWIG_1_HNS, TRAINER_RIVAL_CHIMCHAR_1_HNS, TRAINER_RIVAL_PIPLUP_1_HNS,
    },
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

// Silver's parties for all four regions are already in trainers_hns.party, but
// every script still branches to the Johto trainer IDs. Rather than rewrite
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

// The Johto dex carries all four starter generations. The chosen one occupies
// slots 1-9; the other three run from 257 in generational order. Both windows
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
