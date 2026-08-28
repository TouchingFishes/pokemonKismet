#ifndef GUARD_DIFFICULTY_H
#define GUARD_DIFFICULTY_H

#include "constants/difficulty.h"
#include "script.h"

enum DifficultyLevel GetCurrentDifficultyLevel(void);
void SetCurrentDifficultyLevel(enum DifficultyLevel);

u32 GetBadgeCount(void);
u32 ResolveTrainerMonLevel(u32 lvlField);
u32 GetScaledTrainerMonLevel(u32 lvlField);

enum DifficultyLevel GetBattlePartnerDifficultyLevel(u16);
enum DifficultyLevel GetTrainerDifficultyLevel(u16);
void Script_IncreaseDifficulty(void);
void Script_DecreaseDifficulty(void);
void Script_GetDifficulty(void);
void Script_SetDifficulty(struct ScriptContext *);

#endif // GUARD_DIFFICULTY_H
