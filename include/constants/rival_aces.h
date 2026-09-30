#ifndef GUARD_CONSTANTS_RIVAL_ACES_H
#define GUARD_CONSTANTS_RIVAL_ACES_H

// Silver's aces that ride on another family's party. Several starter regions
// share one party family (sRivalTrainerBase, src/starter_generation.c); where
// they do, the family's own ace is swapped for the matching line here, chosen by
// sRivalAceBase. The data is src/data/rival_aces_hns.party, compiled by
// trainerproc into gRivalAces (src/data.c).
//
// These are NOT trainer IDs. They index gRivalAces, not gTrainers, so they cost
// no trainer IDs and no trainer flags - the arrangement battle_partners uses.
//
// Each line is seven contiguous constants, one per encounter:
// GetRivalAceOverride adds the encounter (0-6) to a line's _1. Never insert
// between a line's members; add new lines at the end.
#define RIVAL_ACE_LINE(name)                                                   \
    RIVAL_ACE_##name##_1, RIVAL_ACE_##name##_2, RIVAL_ACE_##name##_3,          \
    RIVAL_ACE_##name##_4, RIVAL_ACE_##name##_5, RIVAL_ACE_##name##_6,          \
    RIVAL_ACE_##name##_7

enum RivalAce
{
    RIVAL_ACE_NONE, // keep the family's own ace
    RIVAL_ACE_LINE(BLAZIKEN),   // Hoenn Fire, on CYNDAQUIL's party
    RIVAL_ACE_LINE(INFERNAPE),  // Sinnoh Fire, on CYNDAQUIL's party
    RIVAL_ACE_LINE(SCEPTILE),   // Hoenn Grass, on TURTWIG's party
    RIVAL_ACE_LINE(SERPERIOR),  // Unova Grass, on TURTWIG's party
    RIVAL_ACE_LINE(CHESNAUGHT), // Kalos Grass, on TURTWIG's party
    RIVAL_ACE_LINE(EMBOAR),     // Unova Fire, on CYNDAQUIL's party
    RIVAL_ACE_LINE(SAMUROTT),   // Unova Water, on TOTODILE's party
    RIVAL_ACE_LINE(SWAMPERT),   // Hoenn Water, on SQUIRTLE's party
    RIVAL_ACE_COUNT
};

#endif // GUARD_CONSTANTS_RIVAL_ACES_H
