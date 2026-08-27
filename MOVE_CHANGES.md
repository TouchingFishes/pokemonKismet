# MOVE_CHANGES.md

Move balance changes ported from `pokemonHnS` (the 1.x fork) into this tree's `src/data/moves_info.h`.

Each ported value is gated on the `CUSTOM_FOR_KISMET` config option rather than hardcoded, so both values live in the source and the config selects between them:

```c
.power = B_UPDATED_MOVE_DATA == CUSTOM_FOR_KISMET ? 200 : 150,
.accuracy = B_UPDATED_MOVE_DATA == CUSTOM_FOR_KISMET ? 85 : (B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85),
```

Set `B_UPDATED_MOVE_DATA` / `B_UPDATED_MOVE_TYPES` in `include/config/battle.h` back to `GEN_LATEST` to get stock expansion behaviour. Where 2.0's value was itself a gen-gated expression it is preserved verbatim as the else branch.

Regenerate with `py -3 .claude/gen_move_changes.py`. Do not hand-edit — it is read back out of the gated ternaries in `src/data/moves_info.h`, which are the authoritative record.

## Summary

| | |
|---|---:|
| Moves changed | 119 |
| Field changes applied | 164 |
| …whose base value is itself a gen-gated expression | 60 |
| Excluded by decision | 8 |
| Representation-only differences, not ported | 37 |

### Shipped as a separate custom move

The old fork gave these official moves a different move's mechanics. Porting the stats would overwrite a move that should stay stock, so the fork's version ships under its own constant and the official move is left alone. (The inverse of the reskin case, where a custom *name* hides an official move.)

- **FAIRY_WIND** → `MOVE_GLITTER_WIND` — differs in power, pp, type. The official `FAIRY_WIND` keeps 2.0's data.

### Excluded

- **BLOOD_MOON** accuracy — 2.0 keeps `100`, fork had `90`. Excluded by Moritz; deliberate exception.
- **BLOOD_MOON** type — 2.0 keeps `NORMAL`, fork had `GHOST`. Excluded by Moritz; deliberate exception.

### Conditional-Fairy types — deliberately not ported

Both trees let the player switch the Fairy type off, but with opposite polarity. The old fork stores the *fallback* type and upgrades to Fairy at runtime; 2.0 stores `TYPE_FAIRY` and downgrades through `sFairyMoveAltTypes` (`src/pokemon.c`) when the setting is off.

So the fork's stored type is an implementation detail, not a balance decision. Porting it **disables the feature**: `GetMoveType` keys off `type == TYPE_FAIRY`, so a move stored as `TYPE_NORMAL` never enters the branch and can no longer be turned back into a Fairy move. Kismet keeps 2.0's system, which is strictly more complete — 34 moves plus species types.

Where the fork's fallback differs from 2.0's, the difference belongs in `sFairyMoveAltTypes`, not here.

| Move | Fork's stored fallback | 2.0 `sFairyMoveAltTypes` |
|---|---|---|
| `CHARM` | NORMAL | NORMAL |
| `MOONBLAST` | NORMAL | DARK ← differs |
| `MOONLIGHT` | NORMAL | DARK ← differs |
| `PLAY_ROUGH` | NORMAL | NORMAL |
| `SPIRIT_BREAK` | DARK | FIGHTING ← differs |
| `SWEET_KISS` | NORMAL | NORMAL |

## Reverting

Nothing is hardcoded. `include/config/general.h` defines `CUSTOM_FOR_KISMET` as `(GEN_COUNT + 4)` — computed rather than a literal so the sentinel moves automatically if a generation is ever added. It sits above every real `GEN_x`, so all `>= GEN_x` tests still resolve to expansion's latest data as the fallback and all `== GEN_x` tests (which only ever target `GEN_1`–`GEN_5`) stay false. The `+ 4` claims the first slot after `overworld.h`'s `GEN_6_ORAS` / `GEN_8_PLA` / `TIME_DEBUG`, so no two sentinels share a number.

To restore stock expansion move data, set `B_UPDATED_MOVE_DATA` and/or `B_UPDATED_MOVE_TYPES` in `include/config/battle.h` back to `GEN_LATEST`. The two gates are independent: types and numeric data can be reverted separately.

60 of the 164 changes have a base value that is itself a gen-gated expression; those are preserved verbatim as the else branch, so reverting restores the full generational behaviour rather than a flattened snapshot.

## All changes

"2.0" is the base value being replaced; "HnS" is the ported value now in the tree.

| Move | Field | 2.0 | HnS | Was config |
|---|---|---:|---:|:---:|
| `ABSORB` | Power | 20 | **35** |  |
| `ABSORB` | PP | (B_UPDATED_MOVE_DATA >= GEN_4 ? 25 : 20) | **30** | yes |
| `AURA_SPHERE` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 90) | **90** | yes |
| `AURORA_BEAM` | Secondary chance | (B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33) | **15** | yes |
| `BARRAGE` | Power | 15 | **25** |  |
| `BEAT_UP` | Power | (B_UPDATED_MOVE_DATA >= GEN_5 ? 1 : 10) | **20** | yes |
| `BIND` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75) | **75** | yes |
| `BIND` | Power | 15 | **25** |  |
| `BLAST_BURN` | Accuracy | 90 | **100** |  |
| `BLAST_BURN` | Power | 150 | **200** |  |
| `BLAZE_KICK` | Accuracy | 90 | **100** |  |
| `BLAZE_KICK` | Secondary chance | 10 | **20** |  |
| `BLAZE_KICK` | Power | 85 | **90** |  |
| `BLAZE_KICK` | PP | 10 | **15** |  |
| `BLIZZARD` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_2 ? 70 : 90) | **75** | yes |
| `BLIZZARD` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120) | **120** | yes |
| `BONEMERANG` | Accuracy | 90 | **95** |  |
| `BONEMERANG` | Power | 50 | **55** |  |
| `BONE_CLUB` | Secondary chance | 10 | **20** |  |
| `BONE_CLUB` | Power | 65 | **75** |  |
| `BONE_CLUB` | PP | 20 | **25** |  |
| `BONE_RUSH` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80) | **80** | yes |
| `BUBBLE` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 40 : 20) | **25** | yes |
| `BUBBLE_BEAM` | Secondary chance | (B_UPDATED_MOVE_DATA >= GEN_2 ? 10 : 33) | **15** | yes |
| `BULLET_SEED` | Power | (B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10) | **20** | yes |
| `CLAMP` | Power | 35 | **50** |  |
| `COMET_PUNCH` | Accuracy | 85 | **100** |  |
| `COMET_PUNCH` | Power | 18 | **30** |  |
| `CONSTRICT` | Power | 10 | **40** |  |
| `COVET` | PP | (B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 40) | **20** | yes |
| `CRABHAMMER` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85) | **100** | yes |
| `CRABHAMMER` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90) | **110** | yes |
| `CRABHAMMER` | PP | 10 | **15** |  |
| `CROSS_POISON` | Secondary chance | 10 | **25** |  |
| `CROSS_POISON` | Power | 70 | **75** |  |
| `CRUSH_CLAW` | Secondary chance | 50 | **75** |  |
| `CURSE` | Type | (B_UPDATED_MOVE_TYPES >= GEN_5 ? GHOST : MYSTERY) | **MYSTERY** | yes |
| `CUT` | Crit stage | 0 | **1** |  |
| `CUT` | Power | 50 | **55** |  |
| `CUT` | Type | NORMAL | **BUG** |  |
| `DARK_PULSE` | Power | 80 | **95** |  |
| `DISABLE` | Accuracy | 100 | **80** |  |
| `DIZZY_PUNCH` | Power | 70 | **85** |  |
| `DOOM_DESIRE` | Power | (B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 120) | **150** | yes |
| `DOUBLE_SLAP` | Power | 15 | **20** |  |
| `DRAGON_CLAW` | additionalEffect | none | **DEF_MINUS_1 @30%** |  |
| `DRAGON_PULSE` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 90) | **95** | yes |
| `DRILL_PECK` | Crit stage | 0 | **1** |  |
| `DYNAMIC_PUNCH` | Accuracy | 50 | **60** |  |
| `DYNAMIC_PUNCH` | Power | 100 | **120** |  |
| `EGG_BOMB` | Accuracy | 75 | **85** |  |
| `EGG_BOMB` | additionalEffect | none | **FLINCH @15%** |  |
| `EGG_BOMB` | Power | 100 | **120** |  |
| `ENERGY_BALL` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 80) | **95** | yes |
| `EXTRASENSORY` | Secondary chance | 10 | **25** |  |
| `FIRE_BLAST` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120) | **120** | yes |
| `FIRE_FANG` | Accuracy | 95 | **90** |  |
| `FIRE_SPIN` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70) | **95** | yes |
| `FLAMETHROWER` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95) | **95** | yes |
| `FLY` | Accuracy | 95 | **100** |  |
| `FLY` | Power | (B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70) | **80** | yes |
| `FOUL_PLAY` | Power | 95 | **85** |  |
| `FRENZY_PLANT` | Accuracy | 90 | **100** |  |
| `FRENZY_PLANT` | Power | 150 | **200** |  |
| `FROST_BREATH` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40) | **50** | yes |
| `FURY_ATTACK` | Type | NORMAL | **FLYING** |  |
| `FURY_CUTTER` | Power | 40 | **20** |  |
| `FURY_SWIPES` | Power | 18 | **20** |  |
| `GIGA_DRAIN` | PP | 25 | **10** |  |
| `GRASS_WHISTLE` | Accuracy | 55 | **80** |  |
| `HEAT_WAVE` | Secondary chance | 10 | **20** |  |
| `HEAT_WAVE` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 100) | **100** | yes |
| `HEAVY_SLAM` | Power | 1 | **100** |  |
| `HIDDEN_POWER` | Type | NORMAL | **MYSTERY** |  |
| `HURRICANE` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120) | **120** | yes |
| `HYDRO_CANNON` | Accuracy | 90 | **100** |  |
| `HYDRO_CANNON` | Power | 150 | **200** |  |
| `HYDRO_PUMP` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120) | **120** | yes |
| `ICE_BEAM` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95) | **95** | yes |
| `ICE_FANG` | Accuracy | 95 | **90** |  |
| `ICICLE_SPEAR` | Power | (B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10) | **20** | yes |
| `JUMP_KICK` | Power | 100 | **90** |  |
| `JUMP_KICK` | PP | (B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 25) | **25** | yes |
| `KNOCK_OFF` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 20) | **40** | yes |
| `LEAF_STORM` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140) | **140** | yes |
| `LEECH_LIFE` | Power | 60 | **30** |  |
| `LUNGE` | Power | 80 | **70** |  |
| `LUSTER_PURGE` | Power | ((B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70) | **70** | yes |
| `MEGA_DRAIN` | Power | 40 | **55** |  |
| `MEGA_DRAIN` | PP | 25 | **20** |  |
| `METEOR_MASH` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 85) | **85** | yes |
| `METEOR_MASH` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 100) | **100** | yes |
| `MILK_DRINK` | PP | (B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10) | **10** | yes |
| `MIST_BALL` | Power | ((B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70) | **70** | yes |
| `MOONBLAST` | Secondary chance | 30 | **20** |  |
| `MOONBLAST` | PP | 15 | **10** |  |
| `MUDDY_WATER` | Secondary chance | 30 | **35** |  |
| `MUDDY_WATER` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95) | **105** | yes |
| `MUDDY_WATER` | Type | WATER | **GROUND** |  |
| `MUD_SLAP` | Power | 20 | **35** |  |
| `NATURE_POWER` | Power | 1 | **0** |  |
| `NEEDLE_ARM` | Power | 60 | **80** |  |
| `OCTAZOOKA` | Power | 65 | **85** |  |
| `OCTAZOOKA` | PP | 10 | **15** |  |
| `OVERHEAT` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140) | **140** | yes |
| `PETAL_DANCE` | Power | 120 | **100** |  |
| `PETAL_DANCE` | PP | (B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20) | **20** | yes |
| `PIN_MISSILE` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 85) | **85** | yes |
| `PIN_MISSILE` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 14) | **15** | yes |
| `POISON_FANG` | Power | 50 | **60** |  |
| `POISON_JAB` | PP | 20 | **15** |  |
| `POISON_STING` | Secondary chance | (B_UPDATED_MOVE_DATA >= GEN_2 ? 30 : 20) | **25** | yes |
| `POISON_TAIL` | Power | 50 | **80** |  |
| `POWDER_SNOW` | Secondary chance | 10 | **15** |  |
| `POWDER_SNOW` | Power | 40 | **45** |  |
| `PSYSHIELD_BASH` | Power | 70 | **90** |  |
| `RAZOR_WIND` | Power | 80 | **120** |  |
| `RAZOR_WIND` | Type | NORMAL | **FLYING** |  |
| `ROCK_BLAST` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80) | **80** | yes |
| `ROCK_TOMB` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50) | **70** | yes |
| `ROLLING_KICK` | Accuracy | 85 | **100** |  |
| `ROLLING_KICK` | Power | 60 | **75** |  |
| `SHADOW_PUNCH` | Power | 60 | **80** |  |
| `SIGNAL_BEAM` | Secondary chance | 10 | **20** |  |
| `SKULL_BASH` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 100) | **100** | yes |
| `SKY_ATTACK` | Accuracy | 90 | **100** |  |
| `SKY_ATTACK` | Power | 140 | **180** |  |
| `SKY_UPPERCUT` | Power | 85 | **110** |  |
| `SLUDGE_WAVE` | Accuracy | 100 | **85** |  |
| `SLUDGE_WAVE` | additionalEffect | POISON @10% | **POISON @15% + SPD_MINUS_1 @15%** |  |
| `SLUDGE_WAVE` | Power | 95 | **100** |  |
| `SMOG` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20) | **50** | yes |
| `SNORE` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 40) | **75** | yes |
| `SPIKE_CANNON` | Power | 20 | **30** |  |
| `SPIKE_CANNON` | Type | NORMAL | **BUG** |  |
| `SPIT_UP` | Power | 1 | **100** |  |
| `STOCKPILE` | PP | (B_UPDATED_MOVE_DATA >= GEN_4 ? 20 : 10) | **10** | yes |
| `SUBMISSION` | PP | (B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 25) | **25** | yes |
| `SUPERSONIC` | Accuracy | 55 | **65** |  |
| `SURF` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95) | **95** | yes |
| `TACKLE` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 95) | **95** | yes |
| `TACKLE` | Power | 40 | **35** |  |
| `TAKE_DOWN` | Power | 90 | **95** |  |
| `TELEPORT` | Priority | (B_UPDATED_MOVE_DATA >= GEN_8 ? -6 : 0) | **0** | yes |
| `THIEF` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40) | **50** | yes |
| `THRASH` | Power | (B_UPDATED_MOVE_DATA >= GEN_5 ? 120 : 90) | **100** | yes |
| `THRASH` | PP | (B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20) | **20** | yes |
| `THUNDER` | Accuracy | 70 | **75** |  |
| `THUNDER` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120) | **120** | yes |
| `THUNDERBOLT` | Power | (B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95) | **95** | yes |
| `THUNDER_FANG` | Accuracy | 95 | **90** |  |
| `THUNDER_WAVE` | PP | 20 | **15** |  |
| `TOXIC` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85) | **85** | yes |
| `TWINEEDLE` | Power | 25 | **35** |  |
| `TWIN_BEAM` | Power | 40 | **45** |  |
| `TWIN_BEAM` | PP | 10 | **15** |  |
| `TWISTER` | Power | 40 | **90** |  |
| `TWISTER` | Type | DRAGON | **FLYING** |  |
| `UPROAR` | Power | (B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 50) | **55** | yes |
| `VENOSHOCK` | PP | 10 | **20** |  |
| `WEATHER_BALL` | PP | 10 | **30** |  |
| `WRAP` | Accuracy | (B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85) | **85** | yes |
| `WRAP` | Power | 15 | **35** |  |
| `ZAP_CANNON` | Accuracy | 50 | **60** |  |
