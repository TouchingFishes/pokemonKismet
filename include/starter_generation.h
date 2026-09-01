#ifndef GUARD_STARTER_GENERATION_H
#define GUARD_STARTER_GENERATION_H

#include "constants/pokedex.h"

// Elm lets the player pick which generation's trio he offers. The choice lives
// in VAR_STARTER_REGION and drives three things: which species the three balls
// in his lab hold, which of Silver's twelve party families he uses, and where
// the four starter generations sit in the Johto dex.

#define STARTER_SLOT_GRASS  0
#define STARTER_SLOT_FIRE   1
#define STARTER_SLOT_WATER  2
#define STARTER_SLOT_COUNT  3

// Species per generation: 3 lines x 3 evolution stages.
#define STARTER_BLOCK_SIZE  9

// The two Johto dex windows the starters occupy. The chosen generation takes
// 1-9; the other three sit from 257 in generational order.
#define JOHTO_DEX_STARTERS_PRIMARY    JOHTO_DEX_CHIKORITA
#define JOHTO_DEX_STARTERS_SECONDARY  JOHTO_DEX_BULBASAUR

u32 GetStarterRegion(void);
u16 GetStarterForRegionAndSlot(u32 region, u32 slot);
void SetStarterSpeciesFromChoice(void);
u16 GetRivalTrainerIdForStarterChoice(u16 trainerId);
bool32 GetStarterJohtoDexEntry(u32 johtoNum, enum NationalDexOrder *natDexNum);

#endif // GUARD_STARTER_GENERATION_H
