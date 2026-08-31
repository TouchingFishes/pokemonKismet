#ifndef GUARD_MOM_SAVINGS_H
#define GUARD_MOM_SAVINGS_H

#include "global.h"

#define MOM_BERRY_QUANTITY 5
#define MOM_BERRY_COST 100
#define MOM_MAX_MONEY 999999

// Share of a trainer battle's prize that Mom banks
#define MOM_SAVINGS_PERCENTAGE 25

struct MomGiftSequential
{
    u16 itemId;
    u32 threshold;
    u16 cost;
    bool8 isDecoration;
};

void Mom_EnableSaving(bool8 enable);
bool8 Mom_IsSavingEnabled(void);
u32 Mom_GetBalance(void);
u32 Mom_TryDepositMoney(u32 amount);
u32 Mom_AutoDepositFromBattle(u32 amount);
bool8 Mom_TryWithdrawMoney(u32 amount);
bool8 Mom_CheckForGiftPurchase(u32 balance, bool8 isAutomatic);
void Mom_EnsureInitialized(void);
void InitMomSavings(void);
bool8 Mom_TryTriggerGiftCall(void);
void Special_MomOpenDepositInput(void);
void Special_MomOpenWithdrawInput(void);

#endif // GUARD_MOM_SAVINGS_H
