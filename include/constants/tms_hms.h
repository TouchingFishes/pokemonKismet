#ifndef GUARD_CONSTANTS_TMS_HMS_H
#define GUARD_CONSTANTS_TMS_HMS_H

#if IS_HNS

#define FOREACH_TM(F) \
    F(DYNAMIC_PUNCH) /* TM01 - Cianwood Gym done */ \
    F(DRAGON_CLAW)   /* TM02 - Dragons Den Cavern, Route27 done */ \
    F(WATER_PULSE)   /* TM03 - Cerulean City Gym, Sootopolis City Gym 1F done */ \
    F(CALM_MIND)     /* TM04 - Goldenrod City Underground Storage, Mossdeep City Gym done */ \
    F(ROAR)          /* TM05 - Route114, Route32 done */ \
    F(TOXIC)         /* TM06 - Fuchsia City Gym, Route17 done */ \
    F(HAIL)          /* TM07 - Mahogany Town Gym done */ \
    F(BULK_UP)       /* TM08 - Dewford Town Gym, Olivine City Lighthouse, Route17 done */ \
    F(BULLET_SEED)   /* TM09 - Route104, National Park gate gift (was Route32) */ \
    F(HIDDEN_POWER)  /* TM10 - Fortree City House2, Lake Of Rage House1, Safari Zone Gate, Slateport City done */ \
    F(SUNNY_DAY)     /* TM11 - Goldenrod City Radio Tower 3F done */ \
    F(TAUNT)         /* TM12 - Burned Tower B1F, Route110 Trick House End, Route110 Trick House Entrance done */ \
    F(ICE_BEAM)      /* TM13 - Goldenrod City Game Corner, Mauville City Game Corner, Seafoam Islands B1F done */ \
    F(BLIZZARD)      /* TM14 - Celadon City Department Store 3F, Lilycove City Department Store 4F done */ \
    F(HYPER_BEAM)    /* TM15 - Celadon City Department Store 3F, Goldenrod City Game Corner, Lilycove City Department Store 4F, Saffron City Tunnel NS done */ \
    F(LIGHT_SCREEN)  /* TM16 - Celadon City Department Store 3F, Lilycove City Department Store 4F done */ \
    F(PROTECT)       /* TM17 - Goldenrod City Department Store 5F, Lilycove City Department Store 4F done */ \
    F(RAIN_DANCE)    /* TM18 - Slowpoke Well B2F done */ \
    F(GIGA_DRAIN)    /* TM19 - Celadon City Gym, Route123 done */ \
    F(SAFEGUARD)     /* TM20 - Goldenrod City Department Store 5F, Lilycove City Department Store 4F, Verdanturf Town Battle Tent Lobby done */ \
    F(FRUSTRATION)   /* TM21 - Celadon City Department Store 5F, Pacifidlog Town House2 done */ \
    F(SOLAR_BEAM)    /* TM22 - unplaced */ \
    F(IRON_TAIL)     /* TM23 - Olivine City Gym done */ \
    F(THUNDERBOLT)   /* TM24 - Goldenrod City Game Corner, Mauville City, Mauville City Game Corner done */ \
    F(THUNDER)       /* TM25 - Celadon City Department Store 3F, Lilycove City Department Store 4F, Route10 Power Plant Back Room done */ \
    F(EARTHQUAKE)    /* TM26 - Victory Road Kanto B2F done */ \
    F(RETURN)        /* TM27 - Fallarbor Town Cozmos House, Goldenrod City Department Store 5F, Pacifidlog Town House2 done */ \
    F(DIG)           /* TM28 - Celadon City Department Store 3F, National Park Normal, Route114 Fossil Maniacs House done */ \
    F(PSYCHIC)       /* TM29 - Mauville City Game Corner, Saffron City House1 done */ \
    F(SHADOW_BALL)   /* TM30 - Ecruteak City Gym done */ \
    F(BRICK_BREAK)   /* TM31 - Celadon City Department Store 3F, Route17, Sootopolis City House1 done */ \
    F(DOUBLE_TEAM)   /* TM32 - Mauville City Game Corner done */ \
    F(REFLECT)       /* TM33 - Celadon City Department Store 3F, Lilycove City Department Store 4F done */ \
    F(SHOCK_WAVE)    /* TM34 - Mauville City Gym, Vermilion City Gym done */ \
    F(FLAMETHROWER)  /* TM35 - Goldenrod City Game Corner, Mauville City Game Corner, Route28 done */ \
    F(SLUDGE_BOMB)   /* TM36 - Dewford Town Hall, Gate Route43 done */ \
    F(SANDSTORM)     /* TM37 - Route27 House done */ \
    F(FIRE_BLAST)    /* TM38 - Celadon City Department Store 3F, Lilycove City Department Store 4F done */ \
    F(ROCK_TOMB)     /* TM39 - Rustboro City Gym, Union Cave B1F done */ \
    F(AERIAL_ACE)    /* TM40 - Fortree City Gym, Mt Mortar 1F South, Route14 done */ \
    F(TORMENT)       /* TM41 - Route8, Slateport City Battle Tent Lobby done */ \
    F(FACADE)        /* TM42 - Petalburg City Gym, Route15, Slateport City Battle Tent Lobby done */ \
    F(SECRET_POWER)  /* TM43 - Lake Of Rage, Safari Zone Gate, Slateport City done */ \
    F(REST)          /* TM44 - Goldenrod City Game Corner, Lilycove City House2, Route31 done */ \
    F(ATTRACT)       /* TM45 - Goldenrod City Gym, Verdanturf Town Battle Tent Lobby done */ \
    F(THIEF)         /* TM46 - Rocket Hideout B2F, Slateport City Oceanic Museum 1F done */ \
    F(STEEL_WING)    /* TM47 - Granite Cave Stevens Room, Route28 House done */ \
    F(SKILL_SWAP)    /* TM48 - Saffron City Gym done */ \
    F(SNATCH)        /* TM49 - Route39 Farm House, SSTidal Rooms done */ \
    F(OVERHEAT)      /* TM50 - Lavaridge Town Gym 1F, Seafoam Islands Gym done */ \
    F(MIRROR_SHOT)   /* TM51 - Violet City done */ \
    F(FLAME_CHARGE)  /* TM52 - Route 20 done */ \
    F(ICE_PUNCH)     /* TM53 - Goldenrod City Department Store 5F done */ \
    F(MIMIC)         /* TM54 - Mahogany City (fork; not placed yet) */ \
    F(GRASS_KNOT)    /* TM55 - Route11 done */ \
    F(CHARGE_BEAM)   /* TM56 - Olivine City done */ \
    F(VENOSHOCK)     /* TM57 - Route 11 (fork; not placed yet) */ \
    F(ROCK_BLAST)    /* TM58 - Route10 done */ \
    F(ENERGY_BALL)   /* TM59 - Route15 done */ \
    F(SWIFT)         /* TM60 - Union Cave B1F done */ \
    F(MUD_SLAP)      /* TM61 - Cherrygrove Bay (fork; not placed yet) */ \
    F(SLEEP_TALK)    /* TM62 - Celadon City Apartments Roof House done */ \
    F(AVALANCHE)     /* TM63 - Ice Path B3F done */ \
    F(BEAT_UP)       /* TM64 - Stormy Beach (fork; not placed yet) */ \
    F(COSMIC_POWER)  /* TM65 - Ruins of Alph Outside done */ \
    F(SIGNAL_BEAM)   /* TM66 - New Bark Town (fork; not placed yet) */ \
    F(SWEET_SCENT)   /* TM67 - Ilex Forest / Route 34 Gate done */ \
    F(FIRE_PUNCH)    /* TM68 - Goldenrod City Department Store 5F done */ \
    F(ZAP_CANNON)    /* TM69 - Power Plant (fork; not placed yet) */ \
    F(FALSE_SWIPE)   /* TM70 - Goldenrod City Department Store 5F, Ilex Forest done */ \
    F(THUNDER_PUNCH) /* TM71 - Goldenrod City Department Store 5F done */ \
    F(DREAM_EATER)   /* TM72 - Viridian City done */ \
    F(POUNCE)        /* TM73 - Azalea Town Gym done */ \
    F(DRAGON_BREATH) /* TM74 - unplaced */ \
    F(NIGHTMARE)     /* TM75 - Route 31 (fork; not placed yet) */ \
    F(BRINE)         /* TM76 - Route19 done */ \
    F(FLING)         /* TM77 - Rock Tunnel B1F done */ \
    F(DRAIN_PUNCH)   /* TM78 - Route30 done, behind the lake (needs Surf) */ \
    F(ROOST)         /* TM79 - Violet City Gym done */ \
    F(WILL_O_WISP)   /* TM80 - Route14 done */ \
    F(PAYBACK)       /* TM81 - Route35 done */ \
    F(SILVER_WIND)   /* TM82 - Route6, Viridian Forest done */ \
    F(RECYCLE)       /* TM83 - Celadon City done */ \
    F(SHADOW_CLAW)   /* TM84 - Route42 done */ \
    F(X_SCISSOR)     /* TM85 - Route2 done */ \
    F(GYRO_BALL)     /* TM86 - Route13 done */ \
    F(HEX)           /* TM87 - unplaced */ \
    F(BODY_PRESS)    /* TM88 - Goldenrod City Department Store 5F done */ \
    F(PLUCK)         /* TM89 - Route40 done */ \
    F(DETECT)        /* TM90 - Goldenrod City Game Corner done */ \
    F(FLASH_CANNON)  /* TM91 - Route9 done */ \
    F(PSYSHOCK)      /* TM92 - Victory Road Kanto 1F done */ \
    F(SEED_BOMB)     /* TM93 - Goldenrod City Game Corner done */ \
    F(HONE_CLAWS)    /* TM94 - Route37 done */ \
    F(AQUA_RING)     /* TM95 - unplaced */ \
    F(BUG_BITE)      /* TM96 - Route39 done */ \
    F(EARTH_POWER)   /* TM97 - unplaced */ \
    F(METEOR_BEAM)   /* TM98 - Mt Silver Mountain Side done */ \
    F(TRICK_ROOM)    /* TM99 - Viridian City Gym done */ \
    F(GIGA_IMPACT)   /* TM100 - Goldenrod City Game Corner, Route49 done */

#define FOREACH_HM(F) \
    F(CUT) \
    F(FLY) \
    F(SURF) \
    F(STRENGTH) \
    F(FLASH) \
    F(ROCK_SMASH) \
    F(WATERFALL) \
    F(WHIRLPOOL)

#else

#define FOREACH_TM(F) \
    F(FOCUS_PUNCH) \
    F(DRAGON_CLAW) \
    F(WATER_PULSE) \
    F(CALM_MIND) \
    F(ROAR) \
    F(TOXIC) \
    F(HAIL) \
    F(BULK_UP) \
    F(BULLET_SEED) \
    F(HIDDEN_POWER) \
    F(SUNNY_DAY) \
    F(TAUNT) \
    F(ICE_BEAM) \
    F(BLIZZARD) \
    F(HYPER_BEAM) \
    F(LIGHT_SCREEN) \
    F(PROTECT) \
    F(RAIN_DANCE) \
    F(GIGA_DRAIN) \
    F(SAFEGUARD) \
    F(FRUSTRATION) \
    F(SOLAR_BEAM) \
    F(IRON_TAIL) \
    F(THUNDERBOLT) \
    F(THUNDER) \
    F(EARTHQUAKE) \
    F(RETURN) \
    F(DIG) \
    F(PSYCHIC) \
    F(SHADOW_BALL) \
    F(BRICK_BREAK) \
    F(DOUBLE_TEAM) \
    F(REFLECT) \
    F(SHOCK_WAVE) \
    F(FLAMETHROWER) \
    F(SLUDGE_BOMB) \
    F(SANDSTORM) \
    F(FIRE_BLAST) \
    F(ROCK_TOMB) \
    F(AERIAL_ACE) \
    F(TORMENT) \
    F(FACADE) \
    F(SECRET_POWER) \
    F(REST) \
    F(ATTRACT) \
    F(THIEF) \
    F(STEEL_WING) \
    F(SKILL_SWAP) \
    F(SNATCH) \
    F(OVERHEAT)

#define FOREACH_HM(F) \
    F(CUT) \
    F(FLY) \
    F(SURF) \
    F(STRENGTH) \
    F(FLASH) \
    F(ROCK_SMASH) \
    F(WATERFALL) \
    F(DIVE)

#endif

#define FOREACH_TMHM(F) \
    FOREACH_TM(F) \
    FOREACH_HM(F)

#endif
