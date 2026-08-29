#ifndef GUARD_WEATHER_CLIMATE_H
#define GUARD_WEATHER_CLIMATE_H

#include "constants/map_types.h"

// The day is divided into slots of WEATHER_SLOT_MINUTES; slot 0 is midnight.
// A forecast must not cross midnight -- tomorrow's pattern has not been rolled
// yet -- so WEATHER_SLOTS_PER_DAY bounds any look-ahead.
#define WEATHER_SLOT_MINUTES  120
#define WEATHER_SLOTS_PER_DAY ((24 * 60) / WEATHER_SLOT_MINUTES)

u8 GetRegionalWeather(u8 mapSecId, enum MapType mapType);
u8 GetRegionalWeatherAtSlot(u8 mapSecId, u32 slot);
u32 GetCurrentWeatherSlot(void);
void RollDailyWeatherPattern(void);
void NoteResolvedWeather(u8 weather);
void TryUpdateDynamicWeather(void);
void TryResolveWeatherOnContinue(void);

#endif // GUARD_WEATHER_CLIMATE_H
