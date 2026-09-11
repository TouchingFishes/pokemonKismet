// Kismet's ability spreads sit here
//
// Consulted by GetSpeciesAbility (src/pokemon.c) when tx_Mode_Abilities == 1.
// All three slots are authoritative, slot 2 being the hidden ability
//
// The 226 rows where Kismet differs from 2.0 also show 2.0's spread, so
// a deliberate choice stays distinguishable from an inherited default.

static const struct KismetAbilities sKismetAbilities[] =
{
    { SPECIES_BULBASAUR,                 { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_CHLOROPHYLL          } }, //    1 bulbasaur
    { SPECIES_IVYSAUR,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_CHLOROPHYLL          } }, //    2 ivysaur
    { SPECIES_VENUSAUR,                  { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_CHLOROPHYLL          } }, //    3 venusaur
    { SPECIES_CHARMANDER,                { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_SOLAR_POWER          } }, //    4 charmander
    { SPECIES_CHARMELEON,                { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_SOLAR_POWER          } }, //    5 charmeleon
    { SPECIES_CHARIZARD,                 { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_SOLAR_POWER          } }, //    6 charizard
    { SPECIES_SQUIRTLE,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_RAIN_DISH            } }, //    7 squirtle
    { SPECIES_WARTORTLE,                 { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_RAIN_DISH            } }, //    8 wartortle
    { SPECIES_BLASTOISE,                 { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_RAIN_DISH            } }, //    9 blastoise
    { SPECIES_CATERPIE,                  { ABILITY_SHIELD_DUST,         ABILITY_NONE,                ABILITY_RUN_AWAY             } }, //   10 caterpie
    { SPECIES_METAPOD,                   { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_NONE                 } }, //   11 metapod
    { SPECIES_BUTTERFREE,                { ABILITY_COMPOUND_EYES,       ABILITY_NONE,                ABILITY_TINTED_LENS          } }, //   12 butterfree
    { SPECIES_WEEDLE,                    { ABILITY_SHIELD_DUST,         ABILITY_NONE,                ABILITY_RUN_AWAY             } }, //   13 weedle
    { SPECIES_KAKUNA,                    { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_NONE                 } }, //   14 kakuna
    { SPECIES_BEEDRILL,                  { ABILITY_SWARM,               ABILITY_NONE,                ABILITY_SNIPER               } }, //   15 beedrill
    { SPECIES_PIDGEY,                    { ABILITY_KEEN_EYE,            ABILITY_NONE,                ABILITY_BIG_PECKS            } }, //   16 pidgey   2.0: KEEN_EYE,TANGLED_FEET,BIG_PECKS
    { SPECIES_PIDGEOTTO,                 { ABILITY_KEEN_EYE,            ABILITY_NONE,                ABILITY_BIG_PECKS            } }, //   17 pidgeotto   2.0: KEEN_EYE,TANGLED_FEET,BIG_PECKS
    { SPECIES_PIDGEOT,                   { ABILITY_NO_GUARD,            ABILITY_NONE,                ABILITY_BIG_PECKS            } }, //   18 pidgeot   2.0: KEEN_EYE,TANGLED_FEET,BIG_PECKS
    { SPECIES_RATTATA,                   { ABILITY_SKITTISH,            ABILITY_GUTS,                ABILITY_HUSTLE               } }, //   19 rattata
    { SPECIES_RATICATE,                  { ABILITY_SKITTISH,            ABILITY_GUTS,                ABILITY_HUSTLE               } }, //   20 raticate
    { SPECIES_SPEAROW,                   { ABILITY_GUTS,                ABILITY_SNIPER,              ABILITY_SNIPER               } }, //   21 spearow   2.0: KEEN_EYE,NONE,SNIPER
    { SPECIES_FEAROW,                    { ABILITY_GUTS,                ABILITY_SNIPER,              ABILITY_SNIPER               } }, //   22 fearow   2.0: KEEN_EYE,NONE,SNIPER
    { SPECIES_EKANS,                     { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_UNNERVE              } }, //   23 ekans   2.0: INTIMIDATE,SHED_SKIN,UNNERVE
    { SPECIES_ARBOK,                     { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_UNNERVE              } }, //   24 arbok   2.0: INTIMIDATE,SHED_SKIN,UNNERVE
    { SPECIES_PICHU,                     { ABILITY_CUTE_CHARM,          ABILITY_STATIC,              ABILITY_LIGHTNING_ROD        } }, //  172 pichu   2.0: STATIC,NONE,LIGHTNING_ROD
    { SPECIES_PIKACHU,                   { ABILITY_CUTE_CHARM,          ABILITY_STATIC,              ABILITY_LIGHTNING_ROD        } }, //   25 pikachu   2.0: STATIC,NONE,LIGHTNING_ROD
    { SPECIES_RAICHU,                    { ABILITY_THICK_FAT,           ABILITY_STATIC,              ABILITY_LIGHTNING_ROD        } }, //   26 raichu   2.0: STATIC,NONE,LIGHTNING_ROD
    { SPECIES_SANDSHREW,                 { ABILITY_STURDY,              ABILITY_SAND_VEIL,           ABILITY_SAND_RUSH            } }, //   27 sandshrew   2.0: SAND_VEIL,NONE,SAND_RUSH
    { SPECIES_SANDSLASH,                 { ABILITY_ROUGH_SKIN,          ABILITY_SHARPNESS,           ABILITY_SAND_RUSH            } }, //   28 sandslash   2.0: SAND_VEIL,NONE,SAND_RUSH
    { SPECIES_NIDORAN_F,                 { ABILITY_POISON_POINT,        ABILITY_NONE,                ABILITY_HUSTLE               } }, //   29 nidoran_f   2.0: POISON_POINT,RIVALRY,HUSTLE
    { SPECIES_NIDORINA,                  { ABILITY_POISON_POINT,        ABILITY_NONE,                ABILITY_HUSTLE               } }, //   30 nidorina   2.0: POISON_POINT,RIVALRY,HUSTLE
    { SPECIES_NIDOQUEEN,                 { ABILITY_POISON_POINT,        ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //   31 nidoqueen   2.0: POISON_POINT,RIVALRY,SHEER_FORCE
    { SPECIES_NIDORAN_M,                 { ABILITY_POISON_POINT,        ABILITY_NONE,                ABILITY_HUSTLE               } }, //   32 nidoran_m   2.0: POISON_POINT,RIVALRY,HUSTLE
    { SPECIES_NIDORINO,                  { ABILITY_POISON_POINT,        ABILITY_NONE,                ABILITY_HUSTLE               } }, //   33 nidorino   2.0: POISON_POINT,RIVALRY,HUSTLE
    { SPECIES_NIDOKING,                  { ABILITY_POISON_POINT,        ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //   34 nidoking   2.0: POISON_POINT,RIVALRY,SHEER_FORCE
    { SPECIES_CLEFFA,                    { ABILITY_MAGIC_GUARD,         ABILITY_NONE,                ABILITY_FRIEND_GUARD         } }, //  173 cleffa   2.0: CUTE_CHARM,MAGIC_GUARD,FRIEND_GUARD
    { SPECIES_CLEFAIRY,                  { ABILITY_MAGIC_GUARD,         ABILITY_NONE,                ABILITY_FRIEND_GUARD         } }, //   35 clefairy   2.0: CUTE_CHARM,MAGIC_GUARD,FRIEND_GUARD
    { SPECIES_CLEFABLE,                  { ABILITY_MAGIC_GUARD,         ABILITY_NONE,                ABILITY_UNAWARE              } }, //   36 clefable   2.0: CUTE_CHARM,MAGIC_GUARD,UNAWARE
    { SPECIES_VULPIX,                    { ABILITY_FLASH_FIRE,          ABILITY_NONE,                ABILITY_DROUGHT              } }, //   37 vulpix
    { SPECIES_NINETALES,                 { ABILITY_FLASH_FIRE,          ABILITY_NONE,                ABILITY_DROUGHT              } }, //   38 ninetales
    { SPECIES_IGGLYBUFF,                 { ABILITY_CUTE_CHARM,          ABILITY_NONE,                ABILITY_FRIEND_GUARD         } }, //  174 igglybuff   2.0: CUTE_CHARM,COMPETITIVE,FRIEND_GUARD
    { SPECIES_JIGGLYPUFF,                { ABILITY_CUTE_CHARM,          ABILITY_NONE,                ABILITY_FRIEND_GUARD         } }, //   39 jigglypuff   2.0: CUTE_CHARM,COMPETITIVE,FRIEND_GUARD
    { SPECIES_WIGGLYTUFF,                { ABILITY_CUTE_CHARM,          ABILITY_NONE,                ABILITY_FRISK                } }, //   40 wigglytuff   2.0: CUTE_CHARM,COMPETITIVE,FRISK
    { SPECIES_ZUBAT,                     { ABILITY_INNER_FOCUS,         ABILITY_NONE,                ABILITY_INFILTRATOR          } }, //   41 zubat
    { SPECIES_GOLBAT,                    { ABILITY_INNER_FOCUS,         ABILITY_NONE,                ABILITY_INFILTRATOR          } }, //   42 golbat
    { SPECIES_CROBAT,                    { ABILITY_TECHNICIAN,          ABILITY_NONE,                ABILITY_INFILTRATOR          } }, //  169 crobat   2.0: INNER_FOCUS,NONE,INFILTRATOR
    { SPECIES_ODDISH,                    { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_RUN_AWAY             } }, //   43 oddish
    { SPECIES_GLOOM,                     { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_STENCH               } }, //   44 gloom   2.0: CHLOROPHYLL,NONE,STENCH
    { SPECIES_VILEPLUME,                 { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_EFFECT_SPORE         } }, //   45 vileplume   2.0: CHLOROPHYLL,NONE,EFFECT_SPORE
    { SPECIES_BELLOSSOM,                 { ABILITY_NATURAL_CURE,        ABILITY_NONE,                ABILITY_HEALER               } }, //  182 bellossom   2.0: CHLOROPHYLL,NONE,HEALER
    { SPECIES_PARAS,                     { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_DAMP                 } }, //   46 paras   2.0: EFFECT_SPORE,DRY_SKIN,DAMP
    { SPECIES_PARASECT,                  { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_DAMP                 } }, //   47 parasect   2.0: EFFECT_SPORE,DRY_SKIN,DAMP
    { SPECIES_VENONAT,                   { ABILITY_COMPOUND_EYES,       ABILITY_SHIELD_DUST,         ABILITY_RUN_AWAY             } }, //   48 venonat   2.0: COMPOUND_EYES,TINTED_LENS,RUN_AWAY
    { SPECIES_VENOMOTH,                  { ABILITY_SHIELD_DUST,         ABILITY_TINTED_LENS,         ABILITY_WONDER_SKIN          } }, //   49 venomoth
    { SPECIES_DIGLETT,                   { ABILITY_SAND_VEIL,           ABILITY_SKITTISH,            ABILITY_ARENA_TRAP           } }, //   50 diglett
    { SPECIES_DUGTRIO,                   { ABILITY_SAND_VEIL,           ABILITY_ARENA_TRAP,          ABILITY_SAND_FORCE           } }, //   51 dugtrio
    { SPECIES_MEOWTH,                    { ABILITY_PICKUP,              ABILITY_TECHNICIAN,          ABILITY_UNNERVE              } }, //   52 meowth
    { SPECIES_PERSIAN,                   { ABILITY_TECHNICIAN,          ABILITY_NONE,                ABILITY_UNNERVE              } }, //   53 persian   2.0: LIMBER,TECHNICIAN,UNNERVE
    { SPECIES_PSYDUCK,                   { ABILITY_OBLIVIOUS,           ABILITY_CLOUD_NINE,          ABILITY_SWIFT_SWIM           } }, //   54 psyduck   2.0: DAMP,CLOUD_NINE,SWIFT_SWIM
    { SPECIES_GOLDUCK,                   { ABILITY_PSI_CONDUIT,         ABILITY_CLOUD_NINE,          ABILITY_SWIFT_SWIM           } }, //   55 golduck
    { SPECIES_MANKEY,                    { ABILITY_VITAL_SPIRIT,        ABILITY_NONE,                ABILITY_DEFIANT              } }, //   56 mankey   2.0: VITAL_SPIRIT,ANGER_POINT,DEFIANT
    { SPECIES_PRIMEAPE,                  { ABILITY_RECKLESS,            ABILITY_NONE,                ABILITY_DEFIANT              } }, //   57 primeape   2.0: VITAL_SPIRIT,ANGER_POINT,DEFIANT
    { SPECIES_ANNIHILAPE,                { ABILITY_VITAL_SPIRIT,        ABILITY_INNER_FOCUS,         ABILITY_DEFIANT              } }, //  979 annihilape
    { SPECIES_GROWLITHE,                 { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_JUSTIFIED            } }, //   58 growlithe   2.0: INTIMIDATE,FLASH_FIRE,JUSTIFIED
    { SPECIES_ARCANINE,                  { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_JUSTIFIED            } }, //   59 arcanine   2.0: INTIMIDATE,FLASH_FIRE,JUSTIFIED
    { SPECIES_POLIWAG,                   { ABILITY_WATER_ABSORB,        ABILITY_DAMP,                ABILITY_SWIFT_SWIM           } }, //   60 poliwag
    { SPECIES_POLIWHIRL,                 { ABILITY_WATER_ABSORB,        ABILITY_DAMP,                ABILITY_SWIFT_SWIM           } }, //   61 poliwhirl
    { SPECIES_POLIWRATH,                 { ABILITY_SWIFT_SWIM,          ABILITY_WATER_ABSORB,        ABILITY_SWIFT_SWIM           } }, //   62 poliwrath   2.0: WATER_ABSORB,DAMP,SWIFT_SWIM
    { SPECIES_POLITOED,                  { ABILITY_SAP_SIPPER,          ABILITY_SAP_SIPPER,          ABILITY_DRIZZLE              } }, //  186 politoed   2.0: WATER_ABSORB,DAMP,DRIZZLE
    { SPECIES_ABRA,                      { ABILITY_SYNCHRONIZE,         ABILITY_INNER_FOCUS,         ABILITY_MAGIC_GUARD          } }, //   63 abra
    { SPECIES_KADABRA,                   { ABILITY_SYNCHRONIZE,         ABILITY_INNER_FOCUS,         ABILITY_MAGIC_GUARD          } }, //   64 kadabra
    { SPECIES_ALAKAZAM,                  { ABILITY_SYNCHRONIZE,         ABILITY_INNER_FOCUS,         ABILITY_MAGIC_GUARD          } }, //   65 alakazam
    { SPECIES_MACHOP,                    { ABILITY_NO_GUARD,            ABILITY_NONE,                ABILITY_STEADFAST            } }, //   66 machop   2.0: GUTS,NO_GUARD,STEADFAST
    { SPECIES_MACHOKE,                   { ABILITY_NO_GUARD,            ABILITY_NONE,                ABILITY_STEADFAST            } }, //   67 machoke   2.0: GUTS,NO_GUARD,STEADFAST
    { SPECIES_MACHAMP,                   { ABILITY_NO_GUARD,            ABILITY_NONE,                ABILITY_STEADFAST            } }, //   68 machamp   2.0: GUTS,NO_GUARD,STEADFAST
    { SPECIES_BELLSPROUT,                { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_GLUTTONY             } }, //   69 bellsprout
    { SPECIES_WEEPINBELL,                { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_GLUTTONY             } }, //   70 weepinbell
    { SPECIES_VICTREEBEL,                { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_GLUTTONY             } }, //   71 victreebel
    { SPECIES_TENTACOOL,                 { ABILITY_CLEAR_BODY,          ABILITY_LIQUID_OOZE,         ABILITY_RAIN_DISH            } }, //   72 tentacool
    { SPECIES_TENTACRUEL,                { ABILITY_CLEAR_BODY,          ABILITY_LIQUID_OOZE,         ABILITY_RAIN_DISH            } }, //   73 tentacruel
    { SPECIES_GEODUDE,                   { ABILITY_ROCK_HEAD,           ABILITY_STURDY,              ABILITY_SAND_VEIL            } }, //   74 geodude
    { SPECIES_GRAVELER,                  { ABILITY_ROCK_HEAD,           ABILITY_STURDY,              ABILITY_SAND_VEIL            } }, //   75 graveler
    { SPECIES_GOLEM,                     { ABILITY_ROCK_HEAD,           ABILITY_STURDY,              ABILITY_SAND_VEIL            } }, //   76 golem
    { SPECIES_PONYTA,                    { ABILITY_SKITTISH,            ABILITY_FLASH_FIRE,          ABILITY_FLAME_BODY           } }, //   77 ponyta
    { SPECIES_RAPIDASH,                  { ABILITY_FLAME_BODY,          ABILITY_FLASH_FIRE,          ABILITY_FLAME_BODY           } }, //   78 rapidash   2.0: RUN_AWAY,FLASH_FIRE,FLAME_BODY
    { SPECIES_SLOWPOKE,                  { ABILITY_OBLIVIOUS,           ABILITY_OWN_TEMPO,           ABILITY_REGENERATOR          } }, //   79 slowpoke
    { SPECIES_SLOWBRO,                   { ABILITY_OBLIVIOUS,           ABILITY_OWN_TEMPO,           ABILITY_REGENERATOR          } }, //   80 slowbro
    { SPECIES_SLOWKING,                  { ABILITY_ANALYTIC,            ABILITY_CLOUD_NINE,          ABILITY_REGENERATOR          } }, //  199 slowking   2.0: OBLIVIOUS,OWN_TEMPO,REGENERATOR
    { SPECIES_MAGNEMITE,                 { ABILITY_MAGNET_PULL,         ABILITY_STURDY,              ABILITY_ANALYTIC             } }, //   81 magnemite
    { SPECIES_MAGNETON,                  { ABILITY_MAGNET_PULL,         ABILITY_STURDY,              ABILITY_ANALYTIC             } }, //   82 magneton
    { SPECIES_MAGNEZONE,                 { ABILITY_MAGNET_PULL,         ABILITY_STURDY,              ABILITY_ANALYTIC             } }, //  462 magnezone
    { SPECIES_FARFETCHD,                 { ABILITY_KEEN_EYE,            ABILITY_SCRAPPY,             ABILITY_DEFIANT              } }, //   83 farfetchd   2.0: KEEN_EYE,INNER_FOCUS,DEFIANT
    { SPECIES_MLLOY,                     { ABILITY_INNER_FOCUS,         ABILITY_SCRAPPY,             ABILITY_NONE                 } }, // 1035 mlloy
    { SPECIES_DODUO,                     { ABILITY_SKITTISH,            ABILITY_HUSTLE,              ABILITY_TANGLED_FEET         } }, //   84 doduo
    { SPECIES_DODRIO,                    { ABILITY_VITAL_SPIRIT,        ABILITY_SCRAPPY,             ABILITY_TANGLED_FEET         } }, //   85 dodrio   2.0: RUN_AWAY,EARLY_BIRD,TANGLED_FEET
    { SPECIES_SEEL,                      { ABILITY_THICK_FAT,           ABILITY_NONE,                ABILITY_ICE_BODY             } }, //   86 seel   2.0: THICK_FAT,HYDRATION,ICE_BODY
    { SPECIES_DEWGONG,                   { ABILITY_THICK_FAT,           ABILITY_NONE,                ABILITY_ICE_BODY             } }, //   87 dewgong   2.0: THICK_FAT,HYDRATION,ICE_BODY
    { SPECIES_GRIMER,                    { ABILITY_STENCH,              ABILITY_STICKY_HOLD,         ABILITY_POISON_TOUCH         } }, //   88 grimer
    { SPECIES_MUK,                       { ABILITY_STENCH,              ABILITY_STICKY_HOLD,         ABILITY_POISON_TOUCH         } }, //   89 muk
    { SPECIES_SHELLDER,                  { ABILITY_SHELL_ARMOR,         ABILITY_SKILL_LINK,          ABILITY_OVERCOAT             } }, //   90 shellder
    { SPECIES_CLOYSTER,                  { ABILITY_SHELL_ARMOR,         ABILITY_SKILL_LINK,          ABILITY_OVERCOAT             } }, //   91 cloyster
    { SPECIES_GASTLY,                    { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //   92 gastly
    { SPECIES_HAUNTER,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //   93 haunter
    { SPECIES_GENGAR,                    { ABILITY_LEVITATE,            ABILITY_CURSED_BODY,         ABILITY_NONE                 } }, //   94 gengar
    { SPECIES_ONIX,                      { ABILITY_EARTH_EATER,         ABILITY_ROCK_HEAD,           ABILITY_WEAK_ARMOR           } }, //   95 onix   2.0: ROCK_HEAD,STURDY,WEAK_ARMOR
    { SPECIES_STEELIX,                   { ABILITY_EARTH_EATER,         ABILITY_ROCK_HEAD,           ABILITY_SHEER_FORCE          } }, //  208 steelix   2.0: ROCK_HEAD,STURDY,SHEER_FORCE
    { SPECIES_DROWZEE,                   { ABILITY_FILTER,              ABILITY_NONE,                ABILITY_INNER_FOCUS          } }, //   96 drowzee   2.0: INSOMNIA,FOREWARN,INNER_FOCUS
    { SPECIES_HYPNO,                     { ABILITY_FILTER,              ABILITY_NONE,                ABILITY_INNER_FOCUS          } }, //   97 hypno   2.0: INSOMNIA,FOREWARN,INNER_FOCUS
    { SPECIES_KRABBY,                    { ABILITY_HYPER_CUTTER,        ABILITY_SHELL_ARMOR,         ABILITY_SHEER_FORCE          } }, //   98 krabby
    { SPECIES_KINGLER,                   { ABILITY_HYPER_CUTTER,        ABILITY_SHELL_ARMOR,         ABILITY_SHEER_FORCE          } }, //   99 kingler
    { SPECIES_VOLTORB,                   { ABILITY_AFTERMATH,           ABILITY_NONE,                ABILITY_AFTERMATH            } }, //  100 voltorb   2.0: SOUNDPROOF,STATIC,AFTERMATH
    { SPECIES_ELECTRODE,                 { ABILITY_AFTERMATH,           ABILITY_NONE,                ABILITY_AFTERMATH            } }, //  101 electrode   2.0: SOUNDPROOF,STATIC,AFTERMATH
    { SPECIES_EXEGGCUTE,                 { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_HARVEST              } }, //  102 exeggcute
    { SPECIES_EXEGGUTOR,                 { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_HARVEST              } }, //  103 exeggutor
    { SPECIES_CUBONE,                    { ABILITY_ROCK_HEAD,           ABILITY_LIGHTNING_ROD,       ABILITY_BATTLE_ARMOR         } }, //  104 cubone
    { SPECIES_MAROWAK,                   { ABILITY_ROCK_HEAD,           ABILITY_LIGHTNING_ROD,       ABILITY_BATTLE_ARMOR         } }, //  105 marowak
    { SPECIES_TYROGUE,                   { ABILITY_GUTS,                ABILITY_NONE,                ABILITY_VITAL_SPIRIT         } }, //  236 tyrogue   2.0: GUTS,STEADFAST,VITAL_SPIRIT
    { SPECIES_HITMONLEE,                 { ABILITY_RECKLESS,            ABILITY_NONE,                ABILITY_UNBURDEN             } }, //  106 hitmonlee   2.0: LIMBER,RECKLESS,UNBURDEN
    { SPECIES_HITMONCHAN,                { ABILITY_PUGILIST,            ABILITY_NONE,                ABILITY_NONE                 } }, //  107 hitmonchan
    { SPECIES_HITMONTOP,                 { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_STEADFAST            } }, //  237 hitmontop   2.0: INTIMIDATE,TECHNICIAN,STEADFAST
    { SPECIES_LICKITUNG,                 { ABILITY_CLOUD_NINE,          ABILITY_ANALYTIC,            ABILITY_CLOUD_NINE           } }, //  108 lickitung   2.0: OWN_TEMPO,OBLIVIOUS,CLOUD_NINE
    { SPECIES_LICKILICKY,                { ABILITY_OWN_TEMPO,           ABILITY_OBLIVIOUS,           ABILITY_CLOUD_NINE           } }, //  463 lickilicky
    { SPECIES_KOFFING,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_STENCH               } }, //  109 koffing   2.0: LEVITATE,NEUTRALIZING_GAS,STENCH
    { SPECIES_WEEZING,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_STENCH               } }, //  110 weezing   2.0: LEVITATE,NEUTRALIZING_GAS,STENCH
    { SPECIES_RHYHORN,                   { ABILITY_LIGHTNING_ROD,       ABILITY_ROCK_HEAD,           ABILITY_RECKLESS             } }, //  111 rhyhorn
    { SPECIES_RHYDON,                    { ABILITY_SOLID_ROCK,          ABILITY_SOLID_ROCK,          ABILITY_RECKLESS             } }, //  112 rhydon   2.0: LIGHTNING_ROD,ROCK_HEAD,RECKLESS
    { SPECIES_RHYPERIOR,                 { ABILITY_LIGHTNING_ROD,       ABILITY_SOLID_ROCK,          ABILITY_RECKLESS             } }, //  464 rhyperior
    { SPECIES_HAPPINY,                   { ABILITY_NATURAL_CURE,        ABILITY_SERENE_GRACE,        ABILITY_FRIEND_GUARD         } }, //  440 happiny
    { SPECIES_CHANSEY,                   { ABILITY_NATURAL_CURE,        ABILITY_SERENE_GRACE,        ABILITY_HEALER               } }, //  113 chansey
    { SPECIES_BLISSEY,                   { ABILITY_NATURAL_CURE,        ABILITY_SERENE_GRACE,        ABILITY_HEALER               } }, //  242 blissey
    { SPECIES_TANGELA,                   { ABILITY_CHLOROPHYLL,         ABILITY_CHLOROPHYLL,         ABILITY_REGENERATOR          } }, //  114 tangela   2.0: CHLOROPHYLL,LEAF_GUARD,REGENERATOR
    { SPECIES_TANGROWTH,                 { ABILITY_CHLOROPHYLL,         ABILITY_EFFECT_SPORE,        ABILITY_REGENERATOR          } }, //  465 tangrowth   2.0: CHLOROPHYLL,LEAF_GUARD,REGENERATOR
    { SPECIES_KANGASKHAN,                { ABILITY_SCRAPPY,             ABILITY_NONE,                ABILITY_INNER_FOCUS          } }, //  115 kangaskhan   2.0: EARLY_BIRD,SCRAPPY,INNER_FOCUS
    { SPECIES_HORSEA,                    { ABILITY_SWIFT_SWIM,          ABILITY_SNIPER,              ABILITY_DAMP                 } }, //  116 horsea
    { SPECIES_SEADRA,                    { ABILITY_POISON_POINT,        ABILITY_SNIPER,              ABILITY_DAMP                 } }, //  117 seadra
    { SPECIES_KINGDRA,                   { ABILITY_SWIFT_SWIM,          ABILITY_SNIPER,              ABILITY_DAMP                 } }, //  230 kingdra
    { SPECIES_GOLDEEN,                   { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_LIGHTNING_ROD        } }, //  118 goldeen   2.0: SWIFT_SWIM,WATER_VEIL,LIGHTNING_ROD
    { SPECIES_SEAKING,                   { ABILITY_LIGHTNING_ROD,       ABILITY_NONE,                ABILITY_LIGHTNING_ROD        } }, //  119 seaking   2.0: SWIFT_SWIM,WATER_VEIL,LIGHTNING_ROD
    { SPECIES_STARYU,                    { ABILITY_NATURAL_CURE,        ABILITY_SAND_VEIL,           ABILITY_ANALYTIC             } }, //  120 staryu   2.0: ILLUMINATE,NATURAL_CURE,ANALYTIC
    { SPECIES_STARMIE,                   { ABILITY_NATURAL_CURE,        ABILITY_SAND_VEIL,           ABILITY_ANALYTIC             } }, //  121 starmie   2.0: ILLUMINATE,NATURAL_CURE,ANALYTIC
    { SPECIES_MIME_JR,                   { ABILITY_SOUNDPROOF,          ABILITY_FILTER,              ABILITY_TECHNICIAN           } }, //  439 mime_jr
    { SPECIES_MR_MIME,                   { ABILITY_COLOR_CHANGE,        ABILITY_NONE,                ABILITY_TECHNICIAN           } }, //  122 mr_mime   2.0: SOUNDPROOF,FILTER,TECHNICIAN
    { SPECIES_MR_RIME,                   { ABILITY_TANGLED_FEET,        ABILITY_SCREEN_CLEANER,      ABILITY_ICE_BODY             } }, //  866 mr_rime   [disabled by the regional-form gate]
    { SPECIES_SCYTHER,                   { ABILITY_SHARPNESS,           ABILITY_NONE,                ABILITY_STEADFAST            } }, //  123 scyther   2.0: SWARM,TECHNICIAN,STEADFAST
    { SPECIES_SCIZOR,                    { ABILITY_TECHNICIAN,          ABILITY_NONE,                ABILITY_LIGHT_METAL          } }, //  212 scizor   2.0: SWARM,TECHNICIAN,LIGHT_METAL
    { SPECIES_KLEAVOR,                   { ABILITY_SWARM,               ABILITY_SHEER_FORCE,         ABILITY_SHARPNESS            } }, //  900 kleavor
    { SPECIES_SMOOCHUM,                  { ABILITY_OBLIVIOUS,           ABILITY_NONE,                ABILITY_HYDRATION            } }, //  238 smoochum   2.0: OBLIVIOUS,FOREWARN,HYDRATION
    { SPECIES_JYNX,                      { ABILITY_OBLIVIOUS,           ABILITY_NONE,                ABILITY_DRY_SKIN             } }, //  124 jynx   2.0: OBLIVIOUS,FOREWARN,DRY_SKIN
    { SPECIES_ELEKID,                    { ABILITY_STATIC,              ABILITY_NONE,                ABILITY_VITAL_SPIRIT         } }, //  239 elekid
    { SPECIES_ELECTABUZZ,                { ABILITY_STATIC,              ABILITY_NONE,                ABILITY_VITAL_SPIRIT         } }, //  125 electabuzz
    { SPECIES_ELECTIVIRE,                { ABILITY_STATIC,              ABILITY_VITAL_SPIRIT,        ABILITY_VITAL_SPIRIT         } }, //  466 electivire   2.0: MOTOR_DRIVE,NONE,VITAL_SPIRIT
    { SPECIES_MAGBY,                     { ABILITY_FLAME_BODY,          ABILITY_FLAME_BODY,          ABILITY_VITAL_SPIRIT         } }, //  240 magby   2.0: FLAME_BODY,NONE,VITAL_SPIRIT
    { SPECIES_MAGMAR,                    { ABILITY_FLAME_BODY,          ABILITY_FLAME_BODY,          ABILITY_VITAL_SPIRIT         } }, //  126 magmar   2.0: FLAME_BODY,NONE,VITAL_SPIRIT
    { SPECIES_MAGMORTAR,                 { ABILITY_FLAME_BODY,          ABILITY_NONE,                ABILITY_VITAL_SPIRIT         } }, //  467 magmortar
    { SPECIES_PINSIR,                    { ABILITY_CHITINIZE,           ABILITY_HYPER_CUTTER,        ABILITY_MOXIE                } }, //  127 pinsir
    { SPECIES_TAUROS,                    { ABILITY_RECKLESS,            ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  128 tauros   2.0: INTIMIDATE,ANGER_POINT,SHEER_FORCE
    { SPECIES_MAGIKARP,                  { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_RATTLED              } }, //  129 magikarp
    { SPECIES_GYARADOS,                  { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_MOXIE                } }, //  130 gyarados
    { SPECIES_LAPRAS,                    { ABILITY_WATER_ABSORB,        ABILITY_SHELL_ARMOR,         ABILITY_HYDRATION            } }, //  131 lapras
    { SPECIES_DITTO,                     { ABILITY_LIMBER,              ABILITY_NONE,                ABILITY_IMPOSTER             } }, //  132 ditto
    { SPECIES_EEVEE,                     { ABILITY_SKITTISH,            ABILITY_ADAPTABILITY,        ABILITY_ANTICIPATION         } }, //  133 eevee
    { SPECIES_VAPOREON,                  { ABILITY_WATER_ABSORB,        ABILITY_WATER_ABSORB,        ABILITY_HYDRATION            } }, //  134 vaporeon
    { SPECIES_JOLTEON,                   { ABILITY_VOLT_ABSORB,         ABILITY_VOLT_ABSORB,         ABILITY_QUICK_FEET           } }, //  135 jolteon
    { SPECIES_FLAREON,                   { ABILITY_FLASH_FIRE,          ABILITY_FLASH_FIRE,          ABILITY_GUTS                 } }, //  136 flareon
    { SPECIES_ESPEON,                    { ABILITY_SYNCHRONIZE,         ABILITY_SYNCHRONIZE,         ABILITY_MAGIC_BOUNCE         } }, //  196 espeon
    { SPECIES_UMBREON,                   { ABILITY_SYNCHRONIZE,         ABILITY_SYNCHRONIZE,         ABILITY_INNER_FOCUS          } }, //  197 umbreon
    { SPECIES_LEAFEON,                   { ABILITY_GUTS,                ABILITY_NONE,                ABILITY_CHLOROPHYLL          } }, //  470 leafeon   2.0: LEAF_GUARD,LEAF_GUARD,CHLOROPHYLL
    { SPECIES_GLACEON,                   { ABILITY_FILTER,              ABILITY_NONE,                ABILITY_ICE_BODY             } }, //  471 glaceon   2.0: SNOW_CLOAK,SNOW_CLOAK,ICE_BODY
    { SPECIES_SYLVEON,                   { ABILITY_CUTE_CHARM,          ABILITY_CUTE_CHARM,          ABILITY_PIXILATE             } }, //  700 sylveon
    { SPECIES_PORYGON,                   { ABILITY_DOWNLOAD,            ABILITY_NONE,                ABILITY_ANALYTIC             } }, //  137 porygon   2.0: TRACE,DOWNLOAD,ANALYTIC
    { SPECIES_PORYGON2,                  { ABILITY_DOWNLOAD,            ABILITY_NONE,                ABILITY_ANALYTIC             } }, //  233 porygon2   2.0: TRACE,DOWNLOAD,ANALYTIC
    { SPECIES_PORYGON_Z,                 { ABILITY_DOWNLOAD,            ABILITY_NONE,                ABILITY_ANALYTIC             } }, //  474 porygon_z   2.0: ADAPTABILITY,DOWNLOAD,ANALYTIC
    { SPECIES_OMANYTE,                   { ABILITY_SWIFT_SWIM,          ABILITY_SHELL_ARMOR,         ABILITY_WEAK_ARMOR           } }, //  138 omanyte
    { SPECIES_OMASTAR,                   { ABILITY_WEAK_ARMOR,          ABILITY_SWIFT_SWIM,          ABILITY_WEAK_ARMOR           } }, //  139 omastar   2.0: SWIFT_SWIM,SHELL_ARMOR,WEAK_ARMOR
    { SPECIES_KABUTO,                    { ABILITY_CHITINIZE,           ABILITY_BATTLE_ARMOR,        ABILITY_SWIFT_SWIM           } }, //  140 kabuto
    { SPECIES_KABUTOPS,                  { ABILITY_CHITINIZE,           ABILITY_BATTLE_ARMOR,        ABILITY_SWIFT_SWIM           } }, //  141 kabutops
    { SPECIES_AERODACTYL,                { ABILITY_ROCK_HEAD,           ABILITY_NONE,                ABILITY_UNNERVE              } }, //  142 aerodactyl   2.0: ROCK_HEAD,PRESSURE,UNNERVE
    { SPECIES_MUNCHLAX,                  { ABILITY_PICKUP,              ABILITY_THICK_FAT,           ABILITY_GLUTTONY             } }, //  446 munchlax
    { SPECIES_SNORLAX,                   { ABILITY_THICK_FAT,           ABILITY_NONE,                ABILITY_GLUTTONY             } }, //  143 snorlax   2.0: IMMUNITY,THICK_FAT,GLUTTONY
    { SPECIES_ARTICUNO,                  { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_SNOW_CLOAK           } }, //  144 articuno
    { SPECIES_ZAPDOS,                    { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_STATIC               } }, //  145 zapdos
    { SPECIES_MOLTRES,                   { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_FLAME_BODY           } }, //  146 moltres
    { SPECIES_DRATINI,                   { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_MARVEL_SCALE         } }, //  147 dratini
    { SPECIES_DRAGONAIR,                 { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_MARVEL_SCALE         } }, //  148 dragonair
    { SPECIES_DRAGONITE,                 { ABILITY_MULTISCALE,          ABILITY_NONE,                ABILITY_MULTISCALE           } }, //  149 dragonite   2.0: INNER_FOCUS,NONE,MULTISCALE
    { SPECIES_MEWTWO,                    { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_UNNERVE              } }, //  150 mewtwo
    { SPECIES_MEW,                       { ABILITY_SYNCHRONIZE,         ABILITY_NONE,                ABILITY_NONE                 } }, //  151 mew
    { SPECIES_CHIKORITA,                 { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_LEAF_GUARD           } }, //  152 chikorita
    { SPECIES_BAYLEEF,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_LEAF_GUARD           } }, //  153 bayleef
    { SPECIES_MEGANIUM,                  { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_LEAF_GUARD           } }, //  154 meganium
    { SPECIES_CYNDAQUIL,                 { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_FLASH_FIRE           } }, //  155 cyndaquil
    { SPECIES_QUILAVA,                   { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_FLASH_FIRE           } }, //  156 quilava
    { SPECIES_TYPHLOSION,                { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_FLASH_FIRE           } }, //  157 typhlosion
    { SPECIES_TOTODILE,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  158 totodile
    { SPECIES_CROCONAW,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  159 croconaw
    { SPECIES_FERALIGATR,                { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  160 feraligatr
    { SPECIES_SENTRET,                   { ABILITY_SKITTISH,            ABILITY_KEEN_EYE,            ABILITY_FRISK                } }, //  161 sentret
    { SPECIES_FURRET,                    { ABILITY_CUTE_CHARM,          ABILITY_KEEN_EYE,            ABILITY_FRISK                } }, //  162 furret   2.0: RUN_AWAY,KEEN_EYE,FRISK
    { SPECIES_HOOTHOOT,                  { ABILITY_INSOMNIA,            ABILITY_KEEN_EYE,            ABILITY_TINTED_LENS          } }, //  163 hoothoot
    { SPECIES_NOCTOWL,                   { ABILITY_INSOMNIA,            ABILITY_ANALYTIC,            ABILITY_TINTED_LENS          } }, //  164 noctowl   2.0: INSOMNIA,KEEN_EYE,TINTED_LENS
    { SPECIES_LEDYBA,                    { ABILITY_SWARM,               ABILITY_NONE,                ABILITY_RATTLED              } }, //  165 ledyba   2.0: SWARM,EARLY_BIRD,RATTLED
    { SPECIES_LEDIAN,                    { ABILITY_IRON_FIST,           ABILITY_NONE,                ABILITY_IRON_FIST            } }, //  166 ledian   2.0: SWARM,EARLY_BIRD,IRON_FIST
    { SPECIES_SPINARAK,                  { ABILITY_SWARM,               ABILITY_INSOMNIA,            ABILITY_SNIPER               } }, //  167 spinarak
    { SPECIES_ARIADOS,                   { ABILITY_SNIPER,              ABILITY_INSOMNIA,            ABILITY_SNIPER               } }, //  168 ariados   2.0: SWARM,INSOMNIA,SNIPER
    { SPECIES_CHINCHOU,                  { ABILITY_VOLT_ABSORB,         ABILITY_ILLUMINATE,          ABILITY_WATER_ABSORB         } }, //  170 chinchou
    { SPECIES_LANTURN,                   { ABILITY_VOLT_ABSORB,         ABILITY_ILLUMINATE,          ABILITY_WATER_ABSORB         } }, //  171 lanturn
    { SPECIES_TOGEPI,                    { ABILITY_SERENE_GRACE,        ABILITY_NATURAL_CURE,        ABILITY_SUPER_LUCK           } }, //  175 togepi   2.0: HUSTLE,SERENE_GRACE,SUPER_LUCK
    { SPECIES_TOGETIC,                   { ABILITY_SERENE_GRACE,        ABILITY_NATURAL_CURE,        ABILITY_SUPER_LUCK           } }, //  176 togetic   2.0: HUSTLE,SERENE_GRACE,SUPER_LUCK
    { SPECIES_TOGEKISS,                  { ABILITY_HUSTLE,              ABILITY_SERENE_GRACE,        ABILITY_SUPER_LUCK           } }, //  468 togekiss
    { SPECIES_NATU,                      { ABILITY_SYNCHRONIZE,         ABILITY_ANALYTIC,            ABILITY_MAGIC_BOUNCE         } }, //  177 natu   2.0: SYNCHRONIZE,EARLY_BIRD,MAGIC_BOUNCE
    { SPECIES_XATU,                      { ABILITY_SYNCHRONIZE,         ABILITY_ANALYTIC,            ABILITY_MAGIC_BOUNCE         } }, //  178 xatu   2.0: SYNCHRONIZE,EARLY_BIRD,MAGIC_BOUNCE
    { SPECIES_MAREEP,                    { ABILITY_ILLUMINATE,          ABILITY_STATIC,              ABILITY_PLUS                 } }, //  179 mareep   2.0: STATIC,NONE,PLUS
    { SPECIES_FLAAFFY,                   { ABILITY_ILLUMINATE,          ABILITY_STATIC,              ABILITY_PLUS                 } }, //  180 flaaffy   2.0: STATIC,NONE,PLUS
    { SPECIES_AMPHAROS,                  { ABILITY_ILLUMINATE,          ABILITY_STATIC,              ABILITY_PLUS                 } }, //  181 ampharos   2.0: STATIC,NONE,PLUS
    { SPECIES_AZURILL,                   { ABILITY_THICK_FAT,           ABILITY_HUGE_POWER,          ABILITY_SAP_SIPPER           } }, //  298 azurill
    { SPECIES_MARILL,                    { ABILITY_HUGE_POWER,          ABILITY_NONE,                ABILITY_SAP_SIPPER           } }, //  183 marill   2.0: THICK_FAT,HUGE_POWER,SAP_SIPPER
    { SPECIES_AZUMARILL,                 { ABILITY_HUGE_POWER,          ABILITY_NONE,                ABILITY_SAP_SIPPER           } }, //  184 azumarill   2.0: THICK_FAT,HUGE_POWER,SAP_SIPPER
    { SPECIES_BONSLY,                    { ABILITY_STURDY,              ABILITY_ROCK_HEAD,           ABILITY_RATTLED              } }, //  438 bonsly
    { SPECIES_SUDOWOODO,                 { ABILITY_STURDY,              ABILITY_ROCK_HEAD,           ABILITY_RATTLED              } }, //  185 sudowoodo
    { SPECIES_HOPPIP,                    { ABILITY_AERILATE,            ABILITY_CHLOROPHYLL,         ABILITY_INFILTRATOR          } }, //  187 hoppip   2.0: CHLOROPHYLL,LEAF_GUARD,INFILTRATOR
    { SPECIES_SKIPLOOM,                  { ABILITY_AERILATE,            ABILITY_CHLOROPHYLL,         ABILITY_INFILTRATOR          } }, //  188 skiploom   2.0: CHLOROPHYLL,LEAF_GUARD,INFILTRATOR
    { SPECIES_JUMPLUFF,                  { ABILITY_AERILATE,            ABILITY_CHLOROPHYLL,         ABILITY_INFILTRATOR          } }, //  189 jumpluff   2.0: CHLOROPHYLL,LEAF_GUARD,INFILTRATOR
    { SPECIES_AIPOM,                     { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_SKILL_LINK           } }, //  190 aipom   2.0: RUN_AWAY,PICKUP,SKILL_LINK
    { SPECIES_AMBIPOM,                   { ABILITY_TECHNICIAN,          ABILITY_PICKUP,              ABILITY_SKILL_LINK           } }, //  424 ambipom
    { SPECIES_SUNKERN,                   { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_EARLY_BIRD           } }, //  191 sunkern   2.0: CHLOROPHYLL,SOLAR_POWER,EARLY_BIRD
    { SPECIES_SUNFLORA,                  { ABILITY_CHLOROPHYLL,         ABILITY_SOLAR_POWER,         ABILITY_SUNBLOOM             } }, //  192 sunflora
    { SPECIES_YANMA,                     { ABILITY_COMPOUND_EYES,       ABILITY_NONE,                ABILITY_FRISK                } }, //  193 yanma   2.0: SPEED_BOOST,COMPOUND_EYES,FRISK
    { SPECIES_YANMEGA,                   { ABILITY_COMPOUND_EYES,       ABILITY_NONE,                ABILITY_FRISK                } }, //  469 yanmega   2.0: SPEED_BOOST,TINTED_LENS,FRISK
    { SPECIES_WOOPER,                    { ABILITY_DAMP,                ABILITY_WATER_ABSORB,        ABILITY_UNAWARE              } }, //  194 wooper
    { SPECIES_QUAGSIRE,                  { ABILITY_DAMP,                ABILITY_WATER_ABSORB,        ABILITY_UNAWARE              } }, //  195 quagsire
    { SPECIES_MURKROW,                   { ABILITY_INSOMNIA,            ABILITY_ANALYTIC,            ABILITY_PRANKSTER            } }, //  198 murkrow   2.0: INSOMNIA,SUPER_LUCK,PRANKSTER
    { SPECIES_HONCHKROW,                 { ABILITY_INSOMNIA,            ABILITY_ANALYTIC,            ABILITY_MOXIE                } }, //  430 honchkrow   2.0: INSOMNIA,SUPER_LUCK,MOXIE
    { SPECIES_MISDREAVUS,                { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  200 misdreavus
    { SPECIES_MISMAGIUS,                 { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  429 mismagius
    { SPECIES_UNOWN,                     { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  201 unown
    { SPECIES_WYNAUT,                    { ABILITY_SHADOW_TAG,          ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  360 wynaut
    { SPECIES_WOBBUFFET,                 { ABILITY_SHADOW_TAG,          ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  202 wobbuffet
    { SPECIES_GIRAFARIG,                 { ABILITY_SAP_SIPPER,          ABILITY_NONE,                ABILITY_SAP_SIPPER           } }, //  203 girafarig   2.0: INNER_FOCUS,EARLY_BIRD,SAP_SIPPER
    { SPECIES_FARIGIRAF,                 { ABILITY_CUD_CHEW,            ABILITY_ARMOR_TAIL,          ABILITY_SAP_SIPPER           } }, //  981 farigiraf
    { SPECIES_PINECO,                    { ABILITY_STURDY,              ABILITY_NONE,                ABILITY_OVERCOAT             } }, //  204 pineco
    { SPECIES_FORRETRESS,                { ABILITY_OVERCOAT,            ABILITY_NONE,                ABILITY_OVERCOAT             } }, //  205 forretress   2.0: STURDY,NONE,OVERCOAT
    { SPECIES_DUNSPARCE,                 { ABILITY_SERENE_GRACE,        ABILITY_SKITTISH,            ABILITY_RATTLED              } }, //  206 dunsparce
    { SPECIES_DUNDRAG,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, // 1033 dundrag
    { SPECIES_DUNLONG,                   { ABILITY_CLOUD_NINE,          ABILITY_NONE,                ABILITY_NONE                 } }, // 1034 dunlong
    { SPECIES_GLIGAR,                    { ABILITY_HYPER_CUTTER,        ABILITY_SAND_VEIL,           ABILITY_IMMUNITY             } }, //  207 gligar
    { SPECIES_GLISCOR,                   { ABILITY_HYPER_CUTTER,        ABILITY_SAND_VEIL,           ABILITY_POISON_HEAL          } }, //  472 gliscor
    { SPECIES_SNUBBULL,                  { ABILITY_CUTE_CHARM,          ABILITY_NONE,                ABILITY_RATTLED              } }, //  209 snubbull   2.0: INTIMIDATE,RUN_AWAY,RATTLED
    { SPECIES_GRANBULL,                  { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_RATTLED              } }, //  210 granbull   2.0: INTIMIDATE,QUICK_FEET,RATTLED
    { SPECIES_QWILFISH,                  { ABILITY_POISON_POINT,        ABILITY_SWIFT_SWIM,          ABILITY_INTIMIDATE           } }, //  211 qwilfish
    { SPECIES_SHUCKLE,                   { ABILITY_STURDY,              ABILITY_NONE,                ABILITY_CONTRARY             } }, //  213 shuckle   2.0: STURDY,GLUTTONY,CONTRARY
    { SPECIES_HERACROSS,                 { ABILITY_GUTS,                ABILITY_NONE,                ABILITY_MOXIE                } }, //  214 heracross   2.0: SWARM,GUTS,MOXIE
    { SPECIES_SNEASEL,                   { ABILITY_KEEN_EYE,            ABILITY_NONE,                ABILITY_PICKPOCKET           } }, //  215 sneasel   2.0: INNER_FOCUS,KEEN_EYE,PICKPOCKET
    { SPECIES_WEAVILE,                   { ABILITY_SHARPNESS,           ABILITY_NONE,                ABILITY_PICKPOCKET           } }, //  461 weavile   2.0: PRESSURE,NONE,PICKPOCKET
    { SPECIES_TEDDIURSA,                 { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_HONEY_GATHER         } }, //  216 teddiursa   2.0: PICKUP,QUICK_FEET,HONEY_GATHER
    { SPECIES_URSARING,                  { ABILITY_GUTS,                ABILITY_NONE,                ABILITY_UNNERVE              } }, //  217 ursaring   2.0: GUTS,QUICK_FEET,UNNERVE
    { SPECIES_URSALUNA,                  { ABILITY_MINDS_EYE,           ABILITY_NONE,                ABILITY_UNNERVE              } }, //  901 ursaluna   2.0: GUTS,BULLETPROOF,UNNERVE
    { SPECIES_SLUGMA,                    { ABILITY_FLAME_BODY,          ABILITY_NONE,                ABILITY_WEAK_ARMOR           } }, //  218 slugma   2.0: MAGMA_ARMOR,FLAME_BODY,WEAK_ARMOR
    { SPECIES_MAGCARGO,                  { ABILITY_MAGMA_ARMOR,         ABILITY_NONE,                ABILITY_WEAK_ARMOR           } }, //  219 magcargo   2.0: MAGMA_ARMOR,FLAME_BODY,WEAK_ARMOR
    { SPECIES_SWINUB,                    { ABILITY_OBLIVIOUS,           ABILITY_NONE,                ABILITY_THICK_FAT            } }, //  220 swinub   2.0: OBLIVIOUS,SNOW_CLOAK,THICK_FAT
    { SPECIES_PILOSWINE,                 { ABILITY_THICK_FAT,           ABILITY_NONE,                ABILITY_THICK_FAT            } }, //  221 piloswine   2.0: OBLIVIOUS,SNOW_CLOAK,THICK_FAT
    { SPECIES_MAMOSWINE,                 { ABILITY_OBLIVIOUS,           ABILITY_SNOW_CLOAK,          ABILITY_THICK_FAT            } }, //  473 mamoswine
    { SPECIES_CORSOLA,                   { ABILITY_HUSTLE,              ABILITY_NATURAL_CURE,        ABILITY_REGENERATOR          } }, //  222 corsola
    { SPECIES_CORSOREEF,                 { ABILITY_SAP_SIPPER,          ABILITY_NATURAL_CURE,        ABILITY_NONE                 } }, // 1039 corsoreef
    { SPECIES_MANTYKE,                   { ABILITY_SWIFT_SWIM,          ABILITY_WATER_ABSORB,        ABILITY_WATER_VEIL           } }, //  458 mantyke
    { SPECIES_REMORAID,                  { ABILITY_HUSTLE,              ABILITY_NONE,                ABILITY_MOODY                } }, //  223 remoraid   2.0: HUSTLE,SNIPER,MOODY
    { SPECIES_MANTINE,                   { ABILITY_SWIFT_SWIM,          ABILITY_WATER_ABSORB,        ABILITY_WATER_VEIL           } }, //  226 mantine
    { SPECIES_OCTILLERY,                 { ABILITY_SUCTION_CUPS,        ABILITY_NONE,                ABILITY_MOODY                } }, //  224 octillery   2.0: SUCTION_CUPS,SNIPER,MOODY
    { SPECIES_KUJINOUGHT,                { ABILITY_WATER_VEIL,          ABILITY_NONE,                ABILITY_NONE                 } }, // 1040 kujinought
    { SPECIES_DELIBIRD,                  { ABILITY_SNOW_WARNING,        ABILITY_NONE,                ABILITY_INSOMNIA             } }, //  225 delibird   2.0: VITAL_SPIRIT,HUSTLE,INSOMNIA
    { SPECIES_SKARMORY,                  { ABILITY_KEEN_EYE,            ABILITY_STURDY,              ABILITY_WEAK_ARMOR           } }, //  227 skarmory
    { SPECIES_HOUNDOUR,                  { ABILITY_FLASH_FIRE,          ABILITY_NONE,                ABILITY_UNNERVE              } }, //  228 houndour   2.0: EARLY_BIRD,FLASH_FIRE,UNNERVE
    { SPECIES_HOUNDOOM,                  { ABILITY_ADAPTABILITY,        ABILITY_NONE,                ABILITY_UNNERVE              } }, //  229 houndoom   2.0: EARLY_BIRD,FLASH_FIRE,UNNERVE
    { SPECIES_PHANPY,                    { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_SAND_VEIL            } }, //  231 phanpy
    { SPECIES_DONPHAN,                   { ABILITY_STURDY,              ABILITY_NONE,                ABILITY_SAND_VEIL            } }, //  232 donphan
    { SPECIES_STANTLER,                  { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_SAP_SIPPER           } }, //  234 stantler   2.0: INTIMIDATE,FRISK,SAP_SIPPER
    { SPECIES_WYRDEER,                   { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_SAP_SIPPER           } }, //  899 wyrdeer   2.0: INTIMIDATE,FRISK,SAP_SIPPER
    { SPECIES_SMEARGLE,                  { ABILITY_OWN_TEMPO,           ABILITY_NONE,                ABILITY_MOODY                } }, //  235 smeargle   2.0: OWN_TEMPO,TECHNICIAN,MOODY
    { SPECIES_MILTANK,                   { ABILITY_THICK_FAT,           ABILITY_NONE,                ABILITY_SAP_SIPPER           } }, //  241 miltank   2.0: THICK_FAT,SCRAPPY,SAP_SIPPER
    { SPECIES_RAIKOU,                    { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_INNER_FOCUS          } }, //  243 raikou
    { SPECIES_ENTEI,                     { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_INNER_FOCUS          } }, //  244 entei
    { SPECIES_SUICUNE,                   { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_INNER_FOCUS          } }, //  245 suicune
    { SPECIES_LARVITAR,                  { ABILITY_GUTS,                ABILITY_NONE,                ABILITY_SAND_VEIL            } }, //  246 larvitar
    { SPECIES_PUPITAR,                   { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_NONE                 } }, //  247 pupitar
    { SPECIES_TYRANITAR,                 { ABILITY_GUTS,                ABILITY_SAND_STREAM,         ABILITY_UNNERVE              } }, //  248 tyranitar   2.0: SAND_STREAM,NONE,UNNERVE
    { SPECIES_LUGIA,                     { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_MULTISCALE           } }, //  249 lugia
    { SPECIES_HO_OH,                     { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_REGENERATOR          } }, //  250 ho_oh
    { SPECIES_CELEBI,                    { ABILITY_NATURAL_CURE,        ABILITY_NONE,                ABILITY_NONE                 } }, //  251 celebi
    { SPECIES_TREECKO,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_UNBURDEN             } }, //  252 treecko
    { SPECIES_GROVYLE,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_UNBURDEN             } }, //  253 grovyle
    { SPECIES_SCEPTILE,                  { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_UNBURDEN             } }, //  254 sceptile
    { SPECIES_TORCHIC,                   { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_SPEED_BOOST          } }, //  255 torchic
    { SPECIES_COMBUSKEN,                 { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_SPEED_BOOST          } }, //  256 combusken
    { SPECIES_BLAZIKEN,                  { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_SPEED_BOOST          } }, //  257 blaziken
    { SPECIES_MUDKIP,                    { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_DAMP                 } }, //  258 mudkip
    { SPECIES_MARSHTOMP,                 { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_DAMP                 } }, //  259 marshtomp
    { SPECIES_SWAMPERT,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_DAMP                 } }, //  260 swampert
    { SPECIES_POOCHYENA,                 { ABILITY_SKITTISH,            ABILITY_QUICK_FEET,          ABILITY_RATTLED              } }, //  261 poochyena
    { SPECIES_MIGHTYENA,                 { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_MOXIE                } }, //  262 mightyena   2.0: INTIMIDATE,QUICK_FEET,MOXIE
    { SPECIES_ZIGZAGOON,                 { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_QUICK_FEET           } }, //  263 zigzagoon   2.0: PICKUP,GLUTTONY,QUICK_FEET
    { SPECIES_LINOONE,                   { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_QUICK_FEET           } }, //  264 linoone   2.0: PICKUP,GLUTTONY,QUICK_FEET
    { SPECIES_WURMPLE,                   { ABILITY_SHIELD_DUST,         ABILITY_NONE,                ABILITY_RUN_AWAY             } }, //  265 wurmple
    { SPECIES_SILCOON,                   { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_NONE                 } }, //  266 silcoon
    { SPECIES_CASCOON,                   { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_NONE                 } }, //  268 cascoon
    { SPECIES_BEAUTIFLY,                 { ABILITY_SWARM,               ABILITY_NONE,                ABILITY_RIVALRY              } }, //  267 beautifly
    { SPECIES_DUSTOX,                    { ABILITY_SHIELD_DUST,         ABILITY_NONE,                ABILITY_COMPOUND_EYES        } }, //  269 dustox
    { SPECIES_LOTAD,                     { ABILITY_SWIFT_SWIM,          ABILITY_RAIN_DISH,           ABILITY_OWN_TEMPO            } }, //  270 lotad
    { SPECIES_LOMBRE,                    { ABILITY_SWIFT_SWIM,          ABILITY_RAIN_DISH,           ABILITY_OWN_TEMPO            } }, //  271 lombre
    { SPECIES_LUDICOLO,                  { ABILITY_SWIFT_SWIM,          ABILITY_RAIN_DISH,           ABILITY_OWN_TEMPO            } }, //  272 ludicolo
    { SPECIES_SEEDOT,                    { ABILITY_CHLOROPHYLL,         ABILITY_SKITTISH,            ABILITY_PICKPOCKET           } }, //  273 seedot
    { SPECIES_NUZLEAF,                   { ABILITY_CHLOROPHYLL,         ABILITY_SKITTISH,            ABILITY_PICKPOCKET           } }, //  274 nuzleaf
    { SPECIES_SHIFTRY,                   { ABILITY_AERILATE,            ABILITY_AERILATE,            ABILITY_PICKPOCKET           } }, //  275 shiftry   2.0: CHLOROPHYLL,WIND_RIDER,PICKPOCKET
    { SPECIES_TAILLOW,                   { ABILITY_GUTS,                ABILITY_NONE,                ABILITY_SCRAPPY              } }, //  276 taillow
    { SPECIES_SWELLOW,                   { ABILITY_GUTS,                ABILITY_NONE,                ABILITY_SCRAPPY              } }, //  277 swellow
    { SPECIES_WINGULL,                   { ABILITY_KEEN_EYE,            ABILITY_HYDRATION,           ABILITY_RAIN_DISH            } }, //  278 wingull
    { SPECIES_PELIPPER,                  { ABILITY_KEEN_EYE,            ABILITY_DRIZZLE,             ABILITY_RAIN_DISH            } }, //  279 pelipper
    { SPECIES_RALTS,                     { ABILITY_SYNCHRONIZE,         ABILITY_TRACE,               ABILITY_TELEPATHY            } }, //  280 ralts
    { SPECIES_KIRLIA,                    { ABILITY_SYNCHRONIZE,         ABILITY_TRACE,               ABILITY_TELEPATHY            } }, //  281 kirlia
    { SPECIES_GARDEVOIR,                 { ABILITY_SYNCHRONIZE,         ABILITY_TRACE,               ABILITY_TELEPATHY            } }, //  282 gardevoir
    { SPECIES_GALLADE,                   { ABILITY_SHARPNESS,           ABILITY_TRACE,               ABILITY_JUSTIFIED            } }, //  475 gallade   2.0: STEADFAST,SHARPNESS,JUSTIFIED
    { SPECIES_SURSKIT,                   { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_RAIN_DISH            } }, //  283 surskit
    { SPECIES_MASQUERAIN,                { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_UNNERVE              } }, //  284 masquerain
    { SPECIES_SHROOMISH,                 { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_QUICK_FEET           } }, //  285 shroomish   2.0: EFFECT_SPORE,POISON_HEAL,QUICK_FEET
    { SPECIES_BRELOOM,                   { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_TECHNICIAN           } }, //  286 breloom   2.0: EFFECT_SPORE,POISON_HEAL,TECHNICIAN
    { SPECIES_SLAKOTH,                   { ABILITY_TRUANT,              ABILITY_NONE,                ABILITY_NONE                 } }, //  287 slakoth
    { SPECIES_VIGOROTH,                  { ABILITY_VITAL_SPIRIT,        ABILITY_NONE,                ABILITY_NONE                 } }, //  288 vigoroth
    { SPECIES_SLAKING,                   { ABILITY_TRUANT,              ABILITY_NONE,                ABILITY_NONE                 } }, //  289 slaking
    { SPECIES_NINCADA,                   { ABILITY_COMPOUND_EYES,       ABILITY_NONE,                ABILITY_RUN_AWAY             } }, //  290 nincada
    { SPECIES_NINJASK,                   { ABILITY_SPEED_BOOST,         ABILITY_NONE,                ABILITY_INFILTRATOR          } }, //  291 ninjask
    { SPECIES_SHEDINJA,                  { ABILITY_WONDER_GUARD,        ABILITY_NONE,                ABILITY_NONE                 } }, //  292 shedinja
    { SPECIES_WHISMUR,                   { ABILITY_CACOPHONY,           ABILITY_SOUNDPROOF,          ABILITY_RATTLED              } }, //  293 whismur
    { SPECIES_LOUDRED,                   { ABILITY_CACOPHONY,           ABILITY_SOUNDPROOF,          ABILITY_SCRAPPY              } }, //  294 loudred
    { SPECIES_EXPLOUD,                   { ABILITY_CACOPHONY,           ABILITY_SOUNDPROOF,          ABILITY_SCRAPPY              } }, //  295 exploud
    { SPECIES_MAKUHITA,                  { ABILITY_THICK_FAT,           ABILITY_GUTS,                ABILITY_SHEER_FORCE          } }, //  296 makuhita
    { SPECIES_HARIYAMA,                  { ABILITY_THICK_FAT,           ABILITY_GUTS,                ABILITY_SHEER_FORCE          } }, //  297 hariyama
    { SPECIES_NOSEPASS,                  { ABILITY_TRANSISTOR,          ABILITY_NONE,                ABILITY_SAND_FORCE           } }, //  299 nosepass   2.0: STURDY,MAGNET_PULL,SAND_FORCE
    { SPECIES_PROBOPASS,                 { ABILITY_STURDY,              ABILITY_MAGNET_PULL,         ABILITY_SAND_FORCE           } }, //  476 probopass
    { SPECIES_SKITTY,                    { ABILITY_CUTE_CHARM,          ABILITY_NONE,                ABILITY_WONDER_SKIN          } }, //  300 skitty   2.0: CUTE_CHARM,NORMALIZE,WONDER_SKIN
    { SPECIES_DELCATTY,                  { ABILITY_CUTE_CHARM,          ABILITY_NONE,                ABILITY_WONDER_SKIN          } }, //  301 delcatty   2.0: CUTE_CHARM,NORMALIZE,WONDER_SKIN
    { SPECIES_SABLEYE,                   { ABILITY_KEEN_EYE,            ABILITY_NONE,                ABILITY_PRANKSTER            } }, //  302 sableye   2.0: KEEN_EYE,STALL,PRANKSTER
    { SPECIES_MAWILE,                    { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  303 mawile   2.0: HYPER_CUTTER,INTIMIDATE,SHEER_FORCE
    { SPECIES_ARON,                      { ABILITY_STURDY,              ABILITY_ROCK_HEAD,           ABILITY_HEAVY_METAL          } }, //  304 aron
    { SPECIES_LAIRON,                    { ABILITY_STURDY,              ABILITY_ROCK_HEAD,           ABILITY_HEAVY_METAL          } }, //  305 lairon
    { SPECIES_AGGRON,                    { ABILITY_LIGHTNING_ROD,       ABILITY_ROCK_HEAD,           ABILITY_HEAVY_METAL          } }, //  306 aggron   2.0: STURDY,ROCK_HEAD,HEAVY_METAL
    { SPECIES_MEDITITE,                  { ABILITY_PURE_POWER,          ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  307 meditite
    { SPECIES_MEDICHAM,                  { ABILITY_PURE_POWER,          ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  308 medicham
    { SPECIES_ELECTRIKE,                 { ABILITY_STATIC,              ABILITY_LIGHTNING_ROD,       ABILITY_MINUS                } }, //  309 electrike
    { SPECIES_MANECTRIC,                 { ABILITY_STATIC,              ABILITY_LIGHTNING_ROD,       ABILITY_MINUS                } }, //  310 manectric
    { SPECIES_PLUSLE,                    { ABILITY_PLUS,                ABILITY_NONE,                ABILITY_LIGHTNING_ROD        } }, //  311 plusle
    { SPECIES_MINUN,                     { ABILITY_MINUS,               ABILITY_NONE,                ABILITY_VOLT_ABSORB          } }, //  312 minun
    { SPECIES_VOLBEAT,                   { ABILITY_ILLUMINATE,          ABILITY_SWARM,               ABILITY_PRANKSTER            } }, //  313 volbeat
    { SPECIES_ILLUMISE,                  { ABILITY_OBLIVIOUS,           ABILITY_TINTED_LENS,         ABILITY_PRANKSTER            } }, //  314 illumise
    { SPECIES_BUDEW,                     { ABILITY_NATURAL_CURE,        ABILITY_POISON_POINT,        ABILITY_LEAF_GUARD           } }, //  406 budew
    { SPECIES_ROSELIA,                   { ABILITY_NATURAL_CURE,        ABILITY_POISON_POINT,        ABILITY_LEAF_GUARD           } }, //  315 roselia
    { SPECIES_ROSERADE,                  { ABILITY_NATURAL_CURE,        ABILITY_POISON_POINT,        ABILITY_TECHNICIAN           } }, //  407 roserade
    { SPECIES_GULPIN,                    { ABILITY_LIQUID_OOZE,         ABILITY_STICKY_HOLD,         ABILITY_GLUTTONY             } }, //  316 gulpin
    { SPECIES_SWALOT,                    { ABILITY_LIQUID_OOZE,         ABILITY_STICKY_HOLD,         ABILITY_GLUTTONY             } }, //  317 swalot
    { SPECIES_CARVANHA,                  { ABILITY_ROUGH_SKIN,          ABILITY_NONE,                ABILITY_SPEED_BOOST          } }, //  318 carvanha
    { SPECIES_SHARPEDO,                  { ABILITY_ROUGH_SKIN,          ABILITY_NONE,                ABILITY_SPEED_BOOST          } }, //  319 sharpedo
    { SPECIES_WAILMER,                   { ABILITY_WATER_VEIL,          ABILITY_NONE,                ABILITY_PRESSURE             } }, //  320 wailmer   2.0: WATER_VEIL,OBLIVIOUS,PRESSURE
    { SPECIES_WAILORD,                   { ABILITY_WATER_VEIL,          ABILITY_NONE,                ABILITY_PRESSURE             } }, //  321 wailord   2.0: WATER_VEIL,OBLIVIOUS,PRESSURE
    { SPECIES_NUMEL,                     { ABILITY_SAP_SIPPER,          ABILITY_NONE,                ABILITY_OWN_TEMPO            } }, //  322 numel   2.0: OBLIVIOUS,SIMPLE,OWN_TEMPO
    { SPECIES_CAMERUPT,                  { ABILITY_SOLID_ROCK,          ABILITY_NONE,                ABILITY_ANGER_POINT          } }, //  323 camerupt   2.0: MAGMA_ARMOR,SOLID_ROCK,ANGER_POINT
    { SPECIES_TORKOAL,                   { ABILITY_WHITE_SMOKE,         ABILITY_NONE,                ABILITY_SHELL_ARMOR          } }, //  324 torkoal   2.0: WHITE_SMOKE,DROUGHT,SHELL_ARMOR
    { SPECIES_SPOINK,                    { ABILITY_OWN_TEMPO,           ABILITY_ANALYTIC,            ABILITY_GLUTTONY             } }, //  325 spoink   2.0: THICK_FAT,OWN_TEMPO,GLUTTONY
    { SPECIES_GRUMPIG,                   { ABILITY_THICK_FAT,           ABILITY_ANALYTIC,            ABILITY_GLUTTONY             } }, //  326 grumpig   2.0: THICK_FAT,OWN_TEMPO,GLUTTONY
    { SPECIES_SPINDA,                    { ABILITY_OWN_TEMPO,           ABILITY_NONE,                ABILITY_CONTRARY             } }, //  327 spinda   2.0: OWN_TEMPO,TANGLED_FEET,CONTRARY
    { SPECIES_TRAPINCH,                  { ABILITY_HYPER_CUTTER,        ABILITY_ARENA_TRAP,          ABILITY_SHEER_FORCE          } }, //  328 trapinch
    { SPECIES_VIBRAVA,                   { ABILITY_LEVITATE,            ABILITY_LEVITATE,            ABILITY_LEVITATE             } }, //  329 vibrava
    { SPECIES_FLYGON,                    { ABILITY_LEVITATE,            ABILITY_LEVITATE,            ABILITY_LEVITATE             } }, //  330 flygon
    { SPECIES_CACNEA,                    { ABILITY_SAND_VEIL,           ABILITY_NONE,                ABILITY_WATER_ABSORB         } }, //  331 cacnea
    { SPECIES_CACTURNE,                  { ABILITY_SAND_VEIL,           ABILITY_NONE,                ABILITY_WATER_ABSORB         } }, //  332 cacturne
    { SPECIES_SWABLU,                    { ABILITY_NATURAL_CURE,        ABILITY_AERILATE,            ABILITY_CLOUD_NINE           } }, //  333 swablu   2.0: NATURAL_CURE,NONE,CLOUD_NINE
    { SPECIES_ALTARIA,                   { ABILITY_NATURAL_CURE,        ABILITY_AERILATE,            ABILITY_CLOUD_NINE           } }, //  334 altaria   2.0: NATURAL_CURE,NONE,CLOUD_NINE
    { SPECIES_ZANGOOSE,                  { ABILITY_IMMUNITY,            ABILITY_NONE,                ABILITY_TOXIC_BOOST          } }, //  335 zangoose
    { SPECIES_SEVIPER,                   { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_INFILTRATOR          } }, //  336 seviper
    { SPECIES_LUNATONE,                  { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  337 lunatone
    { SPECIES_SOLROCK,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  338 solrock
    { SPECIES_BARBOACH,                  { ABILITY_OBLIVIOUS,           ABILITY_NONE,                ABILITY_HYDRATION            } }, //  339 barboach   2.0: OBLIVIOUS,ANTICIPATION,HYDRATION
    { SPECIES_WHISCASH,                  { ABILITY_OBLIVIOUS,           ABILITY_NONE,                ABILITY_HYDRATION            } }, //  340 whiscash   2.0: OBLIVIOUS,ANTICIPATION,HYDRATION
    { SPECIES_CORPHISH,                  { ABILITY_HYPER_CUTTER,        ABILITY_NONE,                ABILITY_ADAPTABILITY         } }, //  341 corphish   2.0: HYPER_CUTTER,SHELL_ARMOR,ADAPTABILITY
    { SPECIES_CRAWDAUNT,                 { ABILITY_ADAPTABILITY,        ABILITY_NONE,                ABILITY_ADAPTABILITY         } }, //  342 crawdaunt   2.0: HYPER_CUTTER,SHELL_ARMOR,ADAPTABILITY
    { SPECIES_BALTOY,                    { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  343 baltoy
    { SPECIES_CLAYDOL,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  344 claydol
    { SPECIES_LILEEP,                    { ABILITY_SUCTION_CUPS,        ABILITY_NONE,                ABILITY_STORM_DRAIN          } }, //  345 lileep
    { SPECIES_CRADILY,                   { ABILITY_WATER_ABSORB,        ABILITY_NONE,                ABILITY_STORM_DRAIN          } }, //  346 cradily   2.0: SUCTION_CUPS,NONE,STORM_DRAIN
    { SPECIES_ANORITH,                   { ABILITY_BATTLE_ARMOR,        ABILITY_NONE,                ABILITY_SWIFT_SWIM           } }, //  347 anorith
    { SPECIES_ARMALDO,                   { ABILITY_BATTLE_ARMOR,        ABILITY_NONE,                ABILITY_SWIFT_SWIM           } }, //  348 armaldo
    { SPECIES_FEEBAS,                    { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_ADAPTABILITY         } }, //  349 feebas   2.0: SWIFT_SWIM,OBLIVIOUS,ADAPTABILITY
    { SPECIES_MILOTIC,                   { ABILITY_MARVEL_SCALE,        ABILITY_NONE,                ABILITY_CUTE_CHARM           } }, //  350 milotic   2.0: MARVEL_SCALE,COMPETITIVE,CUTE_CHARM
    { SPECIES_CASTFORM,                  { ABILITY_FORECAST,            ABILITY_NONE,                ABILITY_NONE                 } }, //  351 castform
    { SPECIES_KECLEON,                   { ABILITY_COLOR_CHANGE,        ABILITY_NONE,                ABILITY_PROTEAN              } }, //  352 kecleon
    { SPECIES_SHUPPET,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_CURSED_BODY          } }, //  353 shuppet   2.0: INSOMNIA,FRISK,CURSED_BODY
    { SPECIES_BANETTE,                   { ABILITY_CURSED_BODY,         ABILITY_NONE,                ABILITY_CURSED_BODY          } }, //  354 banette   2.0: INSOMNIA,FRISK,CURSED_BODY
    { SPECIES_DUSKULL,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_FRISK                } }, //  355 duskull
    { SPECIES_DUSCLOPS,                  { ABILITY_FILTER,              ABILITY_NONE,                ABILITY_FRISK                } }, //  356 dusclops   2.0: PRESSURE,NONE,FRISK
    { SPECIES_DUSKNOIR,                  { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_FRISK                } }, //  477 dusknoir
    { SPECIES_TROPIUS,                   { ABILITY_THICK_FAT,           ABILITY_NONE,                ABILITY_HARVEST              } }, //  357 tropius   2.0: CHLOROPHYLL,SOLAR_POWER,HARVEST
    { SPECIES_CHINGLING,                 { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  433 chingling
    { SPECIES_CHIMECHO,                  { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  358 chimecho
    { SPECIES_DECIBELLE,                 { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, // 1037 decibelle
    { SPECIES_ABSOL,                     { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_JUSTIFIED            } }, //  359 absol   2.0: PRESSURE,SUPER_LUCK,JUSTIFIED
    { SPECIES_SNORUNT,                   { ABILITY_INNER_FOCUS,         ABILITY_NONE,                ABILITY_MOODY                } }, //  361 snorunt   2.0: INNER_FOCUS,ICE_BODY,MOODY
    { SPECIES_GLALIE,                    { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_MOODY                } }, //  362 glalie   2.0: INNER_FOCUS,ICE_BODY,MOODY
    { SPECIES_FROSLASS,                  { ABILITY_INNER_FOCUS,         ABILITY_INSOMNIA,            ABILITY_CURSED_BODY          } }, //  478 froslass   2.0: SNOW_CLOAK,NONE,CURSED_BODY
    { SPECIES_SPHEAL,                    { ABILITY_OBLIVIOUS,           ABILITY_NONE,                ABILITY_OBLIVIOUS            } }, //  363 spheal   2.0: THICK_FAT,ICE_BODY,OBLIVIOUS
    { SPECIES_SEALEO,                    { ABILITY_OBLIVIOUS,           ABILITY_NONE,                ABILITY_OBLIVIOUS            } }, //  364 sealeo   2.0: THICK_FAT,ICE_BODY,OBLIVIOUS
    { SPECIES_WALREIN,                   { ABILITY_ICE_BODY,            ABILITY_NONE,                ABILITY_OBLIVIOUS            } }, //  365 walrein   2.0: THICK_FAT,ICE_BODY,OBLIVIOUS
    { SPECIES_CLAMPERL,                  { ABILITY_SHELL_ARMOR,         ABILITY_NONE,                ABILITY_RATTLED              } }, //  366 clamperl
    { SPECIES_HUNTAIL,                   { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_WATER_VEIL           } }, //  367 huntail
    { SPECIES_GOREBYSS,                  { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_HYDRATION            } }, //  368 gorebyss
    { SPECIES_RELICANTH,                 { ABILITY_SOLID_ROCK,          ABILITY_ROCK_HEAD,           ABILITY_STURDY               } }, //  369 relicanth   2.0: SWIFT_SWIM,ROCK_HEAD,STURDY
    { SPECIES_LUVDISC,                   { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_HYDRATION            } }, //  370 luvdisc
    { SPECIES_BAGON,                     { ABILITY_ROCK_HEAD,           ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  371 bagon
    { SPECIES_SHELGON,                   { ABILITY_ROCK_HEAD,           ABILITY_NONE,                ABILITY_OVERCOAT             } }, //  372 shelgon
    { SPECIES_SALAMENCE,                 { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_MOXIE                } }, //  373 salamence
    { SPECIES_BELDUM,                    { ABILITY_CLEAR_BODY,          ABILITY_NONE,                ABILITY_LIGHT_METAL          } }, //  374 beldum
    { SPECIES_METANG,                    { ABILITY_CLEAR_BODY,          ABILITY_NONE,                ABILITY_LIGHT_METAL          } }, //  375 metang
    { SPECIES_METAGROSS,                 { ABILITY_CLEAR_BODY,          ABILITY_ROCK_HEAD,           ABILITY_LIGHT_METAL          } }, //  376 metagross   2.0: CLEAR_BODY,NONE,LIGHT_METAL
    { SPECIES_REGIROCK,                  { ABILITY_CLEAR_BODY,          ABILITY_NONE,                ABILITY_STURDY               } }, //  377 regirock
    { SPECIES_REGICE,                    { ABILITY_CLEAR_BODY,          ABILITY_NONE,                ABILITY_ICE_BODY             } }, //  378 regice
    { SPECIES_REGISTEEL,                 { ABILITY_CLEAR_BODY,          ABILITY_NONE,                ABILITY_LIGHT_METAL          } }, //  379 registeel
    { SPECIES_LATIAS,                    { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  380 latias
    { SPECIES_LATIOS,                    { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  381 latios
    { SPECIES_KYOGRE,                    { ABILITY_DRIZZLE,             ABILITY_NONE,                ABILITY_NONE                 } }, //  382 kyogre
    { SPECIES_GROUDON,                   { ABILITY_DROUGHT,             ABILITY_NONE,                ABILITY_NONE                 } }, //  383 groudon
    { SPECIES_RAYQUAZA,                  { ABILITY_AIR_LOCK,            ABILITY_NONE,                ABILITY_NONE                 } }, //  384 rayquaza
    { SPECIES_JIRACHI,                   { ABILITY_SERENE_GRACE,        ABILITY_NONE,                ABILITY_NONE                 } }, //  385 jirachi
    { SPECIES_DEOXYS,                    { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  386 deoxys
    { SPECIES_TURTWIG,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_SHELL_ARMOR          } }, //  387 turtwig
    { SPECIES_GROTLE,                    { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_SHELL_ARMOR          } }, //  388 grotle
    { SPECIES_TORTERRA,                  { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_SHELL_ARMOR          } }, //  389 torterra
    { SPECIES_CHIMCHAR,                  { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_IRON_FIST            } }, //  390 chimchar
    { SPECIES_MONFERNO,                  { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_IRON_FIST            } }, //  391 monferno
    { SPECIES_INFERNAPE,                 { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_IRON_FIST            } }, //  392 infernape
    { SPECIES_PIPLUP,                    { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_COMPETITIVE          } }, //  393 piplup
    { SPECIES_PRINPLUP,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_COMPETITIVE          } }, //  394 prinplup
    { SPECIES_EMPOLEON,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_COMPETITIVE          } }, //  395 empoleon
    { SPECIES_STARLY,                    { ABILITY_KEEN_EYE,            ABILITY_NONE,                ABILITY_RECKLESS             } }, //  396 starly
    { SPECIES_STARAVIA,                  { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_RECKLESS             } }, //  397 staravia
    { SPECIES_STARAPTOR,                 { ABILITY_INTIMIDATE,          ABILITY_NONE,                ABILITY_RECKLESS             } }, //  398 staraptor
    { SPECIES_BIDOOF,                    { ABILITY_SIMPLE,              ABILITY_UNAWARE,             ABILITY_MOODY                } }, //  399 bidoof
    { SPECIES_BIBAREL,                   { ABILITY_SIMPLE,              ABILITY_UNAWARE,             ABILITY_MOODY                } }, //  400 bibarel
    { SPECIES_KRICKETOT,                 { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_RUN_AWAY             } }, //  401 kricketot
    { SPECIES_KRICKETUNE,                { ABILITY_SWARM,               ABILITY_NONE,                ABILITY_TECHNICIAN           } }, //  402 kricketune
    { SPECIES_SHINX,                     { ABILITY_RIVALRY,             ABILITY_INTIMIDATE,          ABILITY_GUTS                 } }, //  403 shinx
    { SPECIES_LUXIO,                     { ABILITY_RIVALRY,             ABILITY_INTIMIDATE,          ABILITY_GUTS                 } }, //  404 luxio
    { SPECIES_LUXRAY,                    { ABILITY_RIVALRY,             ABILITY_INTIMIDATE,          ABILITY_GUTS                 } }, //  405 luxray
    { SPECIES_CRANIDOS,                  { ABILITY_MOLD_BREAKER,        ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  408 cranidos
    { SPECIES_RAMPARDOS,                 { ABILITY_MOLD_BREAKER,        ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  409 rampardos
    { SPECIES_SHIELDON,                  { ABILITY_STURDY,              ABILITY_NONE,                ABILITY_SOUNDPROOF           } }, //  410 shieldon
    { SPECIES_BASTIODON,                 { ABILITY_STURDY,              ABILITY_NONE,                ABILITY_SOUNDPROOF           } }, //  411 bastiodon
    { SPECIES_BURMY,                     { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_OVERCOAT             } }, //  412 burmy
    { SPECIES_WORMADAM,                  { ABILITY_ANTICIPATION,        ABILITY_NONE,                ABILITY_OVERCOAT             } }, //  413 wormadam
    { SPECIES_MOTHIM,                    { ABILITY_SWARM,               ABILITY_NONE,                ABILITY_TINTED_LENS          } }, //  414 mothim
    { SPECIES_COMBEE,                    { ABILITY_HONEY_GATHER,        ABILITY_NONE,                ABILITY_HUSTLE               } }, //  415 combee
    { SPECIES_VESPIQUEN,                 { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_UNNERVE              } }, //  416 vespiquen
    { SPECIES_PACHIRISU,                 { ABILITY_RUN_AWAY,            ABILITY_PICKUP,              ABILITY_VOLT_ABSORB          } }, //  417 pachirisu
    { SPECIES_BUIZEL,                    { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_WATER_VEIL           } }, //  418 buizel
    { SPECIES_FLOATZEL,                  { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_WATER_VEIL           } }, //  419 floatzel
    { SPECIES_CHERUBI,                   { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_NONE                 } }, //  420 cherubi
    { SPECIES_CHERRIM,                   { ABILITY_FLOWER_GIFT,         ABILITY_NONE,                ABILITY_NONE                 } }, //  421 cherrim
    { SPECIES_SHELLOS,                   { ABILITY_STICKY_HOLD,         ABILITY_STORM_DRAIN,         ABILITY_SAND_FORCE           } }, //  422 shellos
    { SPECIES_GASTRODON,                 { ABILITY_STICKY_HOLD,         ABILITY_STORM_DRAIN,         ABILITY_SAND_FORCE           } }, //  423 gastrodon
    { SPECIES_DRIFLOON,                  { ABILITY_AFTERMATH,           ABILITY_UNBURDEN,            ABILITY_FLARE_BOOST          } }, //  425 drifloon
    { SPECIES_DRIFBLIM,                  { ABILITY_AFTERMATH,           ABILITY_UNBURDEN,            ABILITY_FLARE_BOOST          } }, //  426 drifblim
    { SPECIES_BUNEARY,                   { ABILITY_RUN_AWAY,            ABILITY_KLUTZ,               ABILITY_LIMBER               } }, //  427 buneary
    { SPECIES_LOPUNNY,                   { ABILITY_CUTE_CHARM,          ABILITY_KLUTZ,               ABILITY_LIMBER               } }, //  428 lopunny
    { SPECIES_GLAMEOW,                   { ABILITY_LIMBER,              ABILITY_OWN_TEMPO,           ABILITY_KEEN_EYE             } }, //  431 glameow
    { SPECIES_PURUGLY,                   { ABILITY_THICK_FAT,           ABILITY_OWN_TEMPO,           ABILITY_DEFIANT              } }, //  432 purugly
    { SPECIES_STUNKY,                    { ABILITY_STENCH,              ABILITY_AFTERMATH,           ABILITY_KEEN_EYE             } }, //  434 stunky
    { SPECIES_SKUNTANK,                  { ABILITY_STENCH,              ABILITY_AFTERMATH,           ABILITY_KEEN_EYE             } }, //  435 skuntank
    { SPECIES_BRONZOR,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_HEAVY_METAL          } }, //  436 bronzor   2.0: LEVITATE,HEATPROOF,HEAVY_METAL
    { SPECIES_BRONZONG,                  { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_HEAVY_METAL          } }, //  437 bronzong   2.0: LEVITATE,HEATPROOF,HEAVY_METAL
    { SPECIES_CHATOT,                    { ABILITY_KEEN_EYE,            ABILITY_TANGLED_FEET,        ABILITY_BIG_PECKS            } }, //  441 chatot
    { SPECIES_SPIRITOMB,                 { ABILITY_TECHNICIAN,          ABILITY_NONE,                ABILITY_INFILTRATOR          } }, //  442 spiritomb   2.0: PRESSURE,NONE,INFILTRATOR
    { SPECIES_GIBLE,                     { ABILITY_ROUGH_SKIN,          ABILITY_NONE,                ABILITY_ROUGH_SKIN           } }, //  443 gible   2.0: SAND_VEIL,NONE,ROUGH_SKIN
    { SPECIES_GABITE,                    { ABILITY_ROUGH_SKIN,          ABILITY_NONE,                ABILITY_ROUGH_SKIN           } }, //  444 gabite   2.0: SAND_VEIL,NONE,ROUGH_SKIN
    { SPECIES_GARCHOMP,                  { ABILITY_ROUGH_SKIN,          ABILITY_NONE,                ABILITY_ROUGH_SKIN           } }, //  445 garchomp   2.0: SAND_VEIL,NONE,ROUGH_SKIN
    { SPECIES_RIOLU,                     { ABILITY_INNER_FOCUS,         ABILITY_NONE,                ABILITY_PRANKSTER            } }, //  447 riolu   2.0: STEADFAST,INNER_FOCUS,PRANKSTER
    { SPECIES_LUCARIO,                   { ABILITY_INNER_FOCUS,         ABILITY_NONE,                ABILITY_JUSTIFIED            } }, //  448 lucario   2.0: STEADFAST,INNER_FOCUS,JUSTIFIED
    { SPECIES_HIPPOPOTAS,                { ABILITY_SAND_STREAM,         ABILITY_NONE,                ABILITY_SAND_FORCE           } }, //  449 hippopotas
    { SPECIES_HIPPOWDON,                 { ABILITY_SAND_STREAM,         ABILITY_NONE,                ABILITY_SAND_FORCE           } }, //  450 hippowdon
    { SPECIES_SKORUPI,                   { ABILITY_SHARPNESS,           ABILITY_BATTLE_ARMOR,        ABILITY_KEEN_EYE             } }, //  451 skorupi   2.0: BATTLE_ARMOR,SNIPER,KEEN_EYE
    { SPECIES_DRAPION,                   { ABILITY_SHARPNESS,           ABILITY_BATTLE_ARMOR,        ABILITY_KEEN_EYE             } }, //  452 drapion   2.0: BATTLE_ARMOR,SNIPER,KEEN_EYE
    { SPECIES_CROAGUNK,                  { ABILITY_ANTICIPATION,        ABILITY_DRY_SKIN,            ABILITY_POISON_TOUCH         } }, //  453 croagunk
    { SPECIES_TOXICROAK,                 { ABILITY_ANTICIPATION,        ABILITY_DRY_SKIN,            ABILITY_POISON_TOUCH         } }, //  454 toxicroak
    { SPECIES_CARNIVINE,                 { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  455 carnivine
    { SPECIES_FINNEON,                   { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_WATER_VEIL           } }, //  456 finneon   2.0: SWIFT_SWIM,STORM_DRAIN,WATER_VEIL
    { SPECIES_LUMINEON,                  { ABILITY_DRIZZLE,             ABILITY_NONE,                ABILITY_WATER_VEIL           } }, //  457 lumineon   2.0: SWIFT_SWIM,STORM_DRAIN,WATER_VEIL
    { SPECIES_SNOVER,                    { ABILITY_SOUNDPROOF,          ABILITY_SLUSH_RUSH,          ABILITY_SOUNDPROOF           } }, //  459 snover   2.0: SNOW_WARNING,NONE,SOUNDPROOF
    { SPECIES_ABOMASNOW,                 { ABILITY_SNOW_WARNING,        ABILITY_NONE,                ABILITY_SOUNDPROOF           } }, //  460 abomasnow
    { SPECIES_ROTOM,                     { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  479 rotom
    { SPECIES_UXIE,                      { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  480 uxie
    { SPECIES_MESPRIT,                   { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  481 mesprit
    { SPECIES_AZELF,                     { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  482 azelf
    { SPECIES_DIALGA,                    { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  483 dialga
    { SPECIES_PALKIA,                    { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  484 palkia
    { SPECIES_HEATRAN,                   { ABILITY_FLASH_FIRE,          ABILITY_NONE,                ABILITY_FLAME_BODY           } }, //  485 heatran
    { SPECIES_REGIGIGAS,                 { ABILITY_SLOW_START,          ABILITY_NONE,                ABILITY_NONE                 } }, //  486 regigigas
    { SPECIES_GIRATINA,                  { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  487 giratina
    { SPECIES_CRESSELIA,                 { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  488 cresselia
    { SPECIES_PHIONE,                    { ABILITY_HYDRATION,           ABILITY_NONE,                ABILITY_NONE                 } }, //  489 phione
    { SPECIES_MANAPHY,                   { ABILITY_HYDRATION,           ABILITY_NONE,                ABILITY_NONE                 } }, //  490 manaphy
    { SPECIES_DARKRAI,                   { ABILITY_BAD_DREAMS,          ABILITY_NONE,                ABILITY_NONE                 } }, //  491 darkrai
    { SPECIES_SHAYMIN,                   { ABILITY_NATURAL_CURE,        ABILITY_NONE,                ABILITY_NONE                 } }, //  492 shaymin
    { SPECIES_ARCEUS,                    { ABILITY_MULTITYPE,           ABILITY_NONE,                ABILITY_NONE                 } }, //  493 arceus
    { SPECIES_VICTINI,                   { ABILITY_VICTORY_STAR,        ABILITY_NONE,                ABILITY_NONE                 } }, //  494 victini
    { SPECIES_SNIVY,                     { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_CONTRARY             } }, //  495 snivy
    { SPECIES_SERVINE,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_CONTRARY             } }, //  496 servine
    { SPECIES_SERPERIOR,                 { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_CONTRARY             } }, //  497 serperior
    { SPECIES_TEPIG,                     { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_THICK_FAT            } }, //  498 tepig
    { SPECIES_PIGNITE,                   { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_THICK_FAT            } }, //  499 pignite
    { SPECIES_EMBOAR,                    { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_RECKLESS             } }, //  500 emboar
    { SPECIES_OSHAWOTT,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SHELL_ARMOR          } }, //  501 oshawott
    { SPECIES_DEWOTT,                    { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SHELL_ARMOR          } }, //  502 dewott
    { SPECIES_SAMUROTT,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SHELL_ARMOR          } }, //  503 samurott
    { SPECIES_PATRAT,                    { ABILITY_RUN_AWAY,            ABILITY_KEEN_EYE,            ABILITY_ANALYTIC             } }, //  504 patrat
    { SPECIES_WATCHOG,                   { ABILITY_ILLUMINATE,          ABILITY_KEEN_EYE,            ABILITY_ANALYTIC             } }, //  505 watchog
    { SPECIES_LILLIPUP,                  { ABILITY_VITAL_SPIRIT,        ABILITY_PICKUP,              ABILITY_RUN_AWAY             } }, //  506 lillipup
    { SPECIES_HERDIER,                   { ABILITY_INTIMIDATE,          ABILITY_SAND_RUSH,           ABILITY_SCRAPPY              } }, //  507 herdier
    { SPECIES_STOUTLAND,                 { ABILITY_INTIMIDATE,          ABILITY_SAND_RUSH,           ABILITY_SCRAPPY              } }, //  508 stoutland
    { SPECIES_PURRLOIN,                  { ABILITY_LIMBER,              ABILITY_UNBURDEN,            ABILITY_PRANKSTER            } }, //  509 purrloin
    { SPECIES_LIEPARD,                   { ABILITY_LIMBER,              ABILITY_UNBURDEN,            ABILITY_PRANKSTER            } }, //  510 liepard
    { SPECIES_PANSAGE,                   { ABILITY_GLUTTONY,            ABILITY_NONE,                ABILITY_OVERGROW             } }, //  511 pansage
    { SPECIES_SIMISAGE,                  { ABILITY_GLUTTONY,            ABILITY_NONE,                ABILITY_OVERGROW             } }, //  512 simisage
    { SPECIES_PANSEAR,                   { ABILITY_GLUTTONY,            ABILITY_NONE,                ABILITY_BLAZE                } }, //  513 pansear
    { SPECIES_SIMISEAR,                  { ABILITY_GLUTTONY,            ABILITY_NONE,                ABILITY_BLAZE                } }, //  514 simisear
    { SPECIES_PANPOUR,                   { ABILITY_GLUTTONY,            ABILITY_NONE,                ABILITY_TORRENT              } }, //  515 panpour
    { SPECIES_SIMIPOUR,                  { ABILITY_GLUTTONY,            ABILITY_NONE,                ABILITY_TORRENT              } }, //  516 simipour
    { SPECIES_MUNNA,                     { ABILITY_FOREWARN,            ABILITY_SYNCHRONIZE,         ABILITY_TELEPATHY            } }, //  517 munna
    { SPECIES_MUSHARNA,                  { ABILITY_FOREWARN,            ABILITY_SYNCHRONIZE,         ABILITY_TELEPATHY            } }, //  518 musharna
    { SPECIES_PIDOVE,                    { ABILITY_BIG_PECKS,           ABILITY_SUPER_LUCK,          ABILITY_RIVALRY              } }, //  519 pidove
    { SPECIES_TRANQUILL,                 { ABILITY_BIG_PECKS,           ABILITY_SUPER_LUCK,          ABILITY_RIVALRY              } }, //  520 tranquill
    { SPECIES_UNFEZANT,                  { ABILITY_BIG_PECKS,           ABILITY_SUPER_LUCK,          ABILITY_RIVALRY              } }, //  521 unfezant
    { SPECIES_BLITZLE,                   { ABILITY_LIGHTNING_ROD,       ABILITY_MOTOR_DRIVE,         ABILITY_SAP_SIPPER           } }, //  522 blitzle
    { SPECIES_ZEBSTRIKA,                 { ABILITY_LIGHTNING_ROD,       ABILITY_MOTOR_DRIVE,         ABILITY_SAP_SIPPER           } }, //  523 zebstrika
    { SPECIES_ROGGENROLA,                { ABILITY_SAND_FORCE,          ABILITY_NONE,                ABILITY_SAND_FORCE           } }, //  524 roggenrola   2.0: STURDY,WEAK_ARMOR,SAND_FORCE
    { SPECIES_BOLDORE,                   { ABILITY_SAND_FORCE,          ABILITY_NONE,                ABILITY_SAND_FORCE           } }, //  525 boldore   2.0: STURDY,WEAK_ARMOR,SAND_FORCE
    { SPECIES_GIGALITH,                  { ABILITY_SAND_STREAM,         ABILITY_NONE,                ABILITY_SAND_FORCE           } }, //  526 gigalith   2.0: STURDY,SAND_STREAM,SAND_FORCE
    { SPECIES_WOOBAT,                    { ABILITY_UNAWARE,             ABILITY_KLUTZ,               ABILITY_SIMPLE               } }, //  527 woobat
    { SPECIES_SWOOBAT,                   { ABILITY_UNAWARE,             ABILITY_KLUTZ,               ABILITY_SIMPLE               } }, //  528 swoobat
    { SPECIES_DRILBUR,                   { ABILITY_SAND_RUSH,           ABILITY_SAND_FORCE,          ABILITY_MOLD_BREAKER         } }, //  529 drilbur
    { SPECIES_EXCADRILL,                 { ABILITY_SAND_RUSH,           ABILITY_SAND_FORCE,          ABILITY_MOLD_BREAKER         } }, //  530 excadrill
    { SPECIES_AUDINO,                    { ABILITY_HEALER,              ABILITY_REGENERATOR,         ABILITY_KLUTZ                } }, //  531 audino
    { SPECIES_TIMBURR,                   { ABILITY_GUTS,                ABILITY_SHEER_FORCE,         ABILITY_IRON_FIST            } }, //  532 timburr
    { SPECIES_GURDURR,                   { ABILITY_GUTS,                ABILITY_SHEER_FORCE,         ABILITY_IRON_FIST            } }, //  533 gurdurr
    { SPECIES_CONKELDURR,                { ABILITY_GUTS,                ABILITY_SHEER_FORCE,         ABILITY_IRON_FIST            } }, //  534 conkeldurr
    { SPECIES_TYMPOLE,                   { ABILITY_SWIFT_SWIM,          ABILITY_HYDRATION,           ABILITY_WATER_ABSORB         } }, //  535 tympole
    { SPECIES_PALPITOAD,                 { ABILITY_SWIFT_SWIM,          ABILITY_HYDRATION,           ABILITY_WATER_ABSORB         } }, //  536 palpitoad
    { SPECIES_SEISMITOAD,                { ABILITY_SWIFT_SWIM,          ABILITY_POISON_TOUCH,        ABILITY_WATER_ABSORB         } }, //  537 seismitoad
    { SPECIES_THROH,                     { ABILITY_GUTS,                ABILITY_INNER_FOCUS,         ABILITY_MOLD_BREAKER         } }, //  538 throh
    { SPECIES_SAWK,                      { ABILITY_STURDY,              ABILITY_INNER_FOCUS,         ABILITY_MOLD_BREAKER         } }, //  539 sawk
    { SPECIES_SEWADDLE,                  { ABILITY_SWARM,               ABILITY_CHLOROPHYLL,         ABILITY_OVERCOAT             } }, //  540 sewaddle
    { SPECIES_SWADLOON,                  { ABILITY_LEAF_GUARD,          ABILITY_CHLOROPHYLL,         ABILITY_OVERCOAT             } }, //  541 swadloon
    { SPECIES_LEAVANNY,                  { ABILITY_SWARM,               ABILITY_CHLOROPHYLL,         ABILITY_OVERCOAT             } }, //  542 leavanny
    { SPECIES_VENIPEDE,                  { ABILITY_POISON_POINT,        ABILITY_SWARM,               ABILITY_SPEED_BOOST          } }, //  543 venipede
    { SPECIES_WHIRLIPEDE,                { ABILITY_POISON_POINT,        ABILITY_SWARM,               ABILITY_SPEED_BOOST          } }, //  544 whirlipede
    { SPECIES_SCOLIPEDE,                 { ABILITY_POISON_POINT,        ABILITY_SWARM,               ABILITY_SPEED_BOOST          } }, //  545 scolipede
    { SPECIES_COTTONEE,                  { ABILITY_PRANKSTER,           ABILITY_INFILTRATOR,         ABILITY_CHLOROPHYLL          } }, //  546 cottonee
    { SPECIES_WHIMSICOTT,                { ABILITY_PRANKSTER,           ABILITY_INFILTRATOR,         ABILITY_CHLOROPHYLL          } }, //  547 whimsicott
    { SPECIES_PETILIL,                   { ABILITY_CHLOROPHYLL,         ABILITY_OWN_TEMPO,           ABILITY_LEAF_GUARD           } }, //  548 petilil
    { SPECIES_LILLIGANT,                 { ABILITY_CHLOROPHYLL,         ABILITY_OWN_TEMPO,           ABILITY_LEAF_GUARD           } }, //  549 lilligant
    { SPECIES_BASCULIN,                  { ABILITY_RECKLESS,            ABILITY_ADAPTABILITY,        ABILITY_MOLD_BREAKER         } }, //  550 basculin
    { SPECIES_SANDILE,                   { ABILITY_SAND_STREAM,         ABILITY_NONE,                ABILITY_ANGER_POINT          } }, //  551 sandile   2.0: INTIMIDATE,MOXIE,ANGER_POINT
    { SPECIES_KROKOROK,                  { ABILITY_SAND_STREAM,         ABILITY_NONE,                ABILITY_ANGER_POINT          } }, //  552 krokorok   2.0: INTIMIDATE,MOXIE,ANGER_POINT
    { SPECIES_KROOKODILE,                { ABILITY_SAND_STREAM,         ABILITY_NONE,                ABILITY_ANGER_POINT          } }, //  553 krookodile   2.0: INTIMIDATE,MOXIE,ANGER_POINT
    { SPECIES_DARUMAKA,                  { ABILITY_HUSTLE,              ABILITY_NONE,                ABILITY_INNER_FOCUS          } }, //  554 darumaka
    { SPECIES_DARMANITAN,                { ABILITY_SHEER_FORCE,         ABILITY_NONE,                ABILITY_ZEN_MODE             } }, //  555 darmanitan
    { SPECIES_MARACTUS,                  { ABILITY_WATER_ABSORB,        ABILITY_CHLOROPHYLL,         ABILITY_STORM_DRAIN          } }, //  556 maractus
    { SPECIES_DWEBBLE,                   { ABILITY_STURDY,              ABILITY_SHELL_ARMOR,         ABILITY_WEAK_ARMOR           } }, //  557 dwebble
    { SPECIES_CRUSTLE,                   { ABILITY_STURDY,              ABILITY_SHELL_ARMOR,         ABILITY_WEAK_ARMOR           } }, //  558 crustle
    { SPECIES_SCRAGGY,                   { ABILITY_SHED_SKIN,           ABILITY_MOXIE,               ABILITY_INTIMIDATE           } }, //  559 scraggy
    { SPECIES_SCRAFTY,                   { ABILITY_SHED_SKIN,           ABILITY_MOXIE,               ABILITY_INTIMIDATE           } }, //  560 scrafty
    { SPECIES_SIGILYPH,                  { ABILITY_WONDER_SKIN,         ABILITY_MAGIC_GUARD,         ABILITY_TINTED_LENS          } }, //  561 sigilyph
    { SPECIES_YAMASK,                    { ABILITY_MUMMY,               ABILITY_NONE,                ABILITY_NONE                 } }, //  562 yamask
    { SPECIES_COFAGRIGUS,                { ABILITY_MUMMY,               ABILITY_NONE,                ABILITY_NONE                 } }, //  563 cofagrigus
    { SPECIES_TIRTOUGA,                  { ABILITY_SOLID_ROCK,          ABILITY_STURDY,              ABILITY_SWIFT_SWIM           } }, //  564 tirtouga
    { SPECIES_CARRACOSTA,                { ABILITY_SOLID_ROCK,          ABILITY_STURDY,              ABILITY_SWIFT_SWIM           } }, //  565 carracosta
    { SPECIES_ARCHEN,                    { ABILITY_DEFEATIST,           ABILITY_NONE,                ABILITY_NONE                 } }, //  566 archen
    { SPECIES_ARCHEOPS,                  { ABILITY_DEFEATIST,           ABILITY_NONE,                ABILITY_NONE                 } }, //  567 archeops
    { SPECIES_TRUBBISH,                  { ABILITY_STENCH,              ABILITY_STICKY_HOLD,         ABILITY_AFTERMATH            } }, //  568 trubbish
    { SPECIES_GARBODOR,                  { ABILITY_STENCH,              ABILITY_WEAK_ARMOR,          ABILITY_AFTERMATH            } }, //  569 garbodor
    { SPECIES_ZORUA,                     { ABILITY_ILLUSION,            ABILITY_NONE,                ABILITY_NONE                 } }, //  570 zorua
    { SPECIES_ZOROARK,                   { ABILITY_ILLUSION,            ABILITY_NONE,                ABILITY_NONE                 } }, //  571 zoroark
    { SPECIES_MINCCINO,                  { ABILITY_CUTE_CHARM,          ABILITY_TECHNICIAN,          ABILITY_SKILL_LINK           } }, //  572 minccino
    { SPECIES_CINCCINO,                  { ABILITY_CUTE_CHARM,          ABILITY_TECHNICIAN,          ABILITY_SKILL_LINK           } }, //  573 cinccino
    { SPECIES_GOTHITA,                   { ABILITY_FRISK,               ABILITY_COMPETITIVE,         ABILITY_SHADOW_TAG           } }, //  574 gothita
    { SPECIES_GOTHORITA,                 { ABILITY_FRISK,               ABILITY_COMPETITIVE,         ABILITY_SHADOW_TAG           } }, //  575 gothorita
    { SPECIES_GOTHITELLE,                { ABILITY_FRISK,               ABILITY_COMPETITIVE,         ABILITY_SHADOW_TAG           } }, //  576 gothitelle
    { SPECIES_SOLOSIS,                   { ABILITY_OVERCOAT,            ABILITY_MAGIC_GUARD,         ABILITY_REGENERATOR          } }, //  577 solosis
    { SPECIES_DUOSION,                   { ABILITY_OVERCOAT,            ABILITY_MAGIC_GUARD,         ABILITY_REGENERATOR          } }, //  578 duosion
    { SPECIES_REUNICLUS,                 { ABILITY_OVERCOAT,            ABILITY_MAGIC_GUARD,         ABILITY_REGENERATOR          } }, //  579 reuniclus
    { SPECIES_DUCKLETT,                  { ABILITY_KEEN_EYE,            ABILITY_BIG_PECKS,           ABILITY_HYDRATION            } }, //  580 ducklett
    { SPECIES_SWANNA,                    { ABILITY_KEEN_EYE,            ABILITY_BIG_PECKS,           ABILITY_HYDRATION            } }, //  581 swanna
    { SPECIES_VANILLITE,                 { ABILITY_OVERCOAT,            ABILITY_ICE_BODY,            ABILITY_WEAK_ARMOR           } }, //  582 vanillite   2.0: ICE_BODY,SNOW_CLOAK,WEAK_ARMOR
    { SPECIES_VANILLISH,                 { ABILITY_OVERCOAT,            ABILITY_ICE_BODY,            ABILITY_WEAK_ARMOR           } }, //  583 vanillish   2.0: ICE_BODY,SNOW_CLOAK,WEAK_ARMOR
    { SPECIES_VANILLUXE,                 { ABILITY_OVERCOAT,            ABILITY_ICE_BODY,            ABILITY_WEAK_ARMOR           } }, //  584 vanilluxe   2.0: ICE_BODY,SNOW_WARNING,WEAK_ARMOR
    { SPECIES_DEERLING,                  { ABILITY_CHLOROPHYLL,         ABILITY_SAP_SIPPER,          ABILITY_SERENE_GRACE         } }, //  585 deerling
    { SPECIES_SAWSBUCK,                  { ABILITY_CHLOROPHYLL,         ABILITY_SAP_SIPPER,          ABILITY_SERENE_GRACE         } }, //  586 sawsbuck
    { SPECIES_EMOLGA,                    { ABILITY_STATIC,              ABILITY_NONE,                ABILITY_MOTOR_DRIVE          } }, //  587 emolga
    { SPECIES_SHELMET,                   { ABILITY_HYDRATION,           ABILITY_SHELL_ARMOR,         ABILITY_OVERCOAT             } }, //  616 shelmet
    { SPECIES_KARRABLAST,                { ABILITY_SWARM,               ABILITY_SHED_SKIN,           ABILITY_NO_GUARD             } }, //  588 karrablast
    { SPECIES_ACCELGOR,                  { ABILITY_HYDRATION,           ABILITY_STICKY_HOLD,         ABILITY_UNBURDEN             } }, //  617 accelgor
    { SPECIES_ESCAVALIER,                { ABILITY_SWARM,               ABILITY_SHELL_ARMOR,         ABILITY_OVERCOAT             } }, //  589 escavalier
    { SPECIES_FOONGUS,                   { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_REGENERATOR          } }, //  590 foongus
    { SPECIES_AMOONGUSS,                 { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_REGENERATOR          } }, //  591 amoonguss
    { SPECIES_FRILLISH,                  { ABILITY_WATER_ABSORB,        ABILITY_CURSED_BODY,         ABILITY_DAMP                 } }, //  592 frillish
    { SPECIES_JELLICENT,                 { ABILITY_WATER_ABSORB,        ABILITY_CURSED_BODY,         ABILITY_DAMP                 } }, //  593 jellicent
    { SPECIES_ALOMOMOLA,                 { ABILITY_HEALER,              ABILITY_HYDRATION,           ABILITY_REGENERATOR          } }, //  594 alomomola
    { SPECIES_JOLTIK,                    { ABILITY_COMPOUND_EYES,       ABILITY_UNNERVE,             ABILITY_SWARM                } }, //  595 joltik
    { SPECIES_GALVANTULA,                { ABILITY_COMPOUND_EYES,       ABILITY_UNNERVE,             ABILITY_SWARM                } }, //  596 galvantula
    { SPECIES_FERROSEED,                 { ABILITY_IRON_BARBS,          ABILITY_NONE,                ABILITY_NONE                 } }, //  597 ferroseed
    { SPECIES_FERROTHORN,                { ABILITY_IRON_BARBS,          ABILITY_NONE,                ABILITY_ANTICIPATION         } }, //  598 ferrothorn
    { SPECIES_KLINK,                     { ABILITY_CLEAR_BODY,          ABILITY_OVERCOAT,            ABILITY_CLEAR_BODY           } }, //  599 klink   2.0: PLUS,MINUS,CLEAR_BODY
    { SPECIES_KLANG,                     { ABILITY_CLEAR_BODY,          ABILITY_OVERCOAT,            ABILITY_CLEAR_BODY           } }, //  600 klang   2.0: PLUS,MINUS,CLEAR_BODY
    { SPECIES_KLINKLANG,                 { ABILITY_CLEAR_BODY,          ABILITY_OVERCOAT,            ABILITY_CLEAR_BODY           } }, //  601 klinklang   2.0: PLUS,MINUS,CLEAR_BODY
    { SPECIES_TYNAMO,                    { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  602 tynamo
    { SPECIES_EELEKTRIK,                 { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  603 eelektrik
    { SPECIES_EELEKTROSS,                { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  604 eelektross
    { SPECIES_ELGYEM,                    { ABILITY_TELEPATHY,           ABILITY_SYNCHRONIZE,         ABILITY_ANALYTIC             } }, //  605 elgyem
    { SPECIES_BEHEEYEM,                  { ABILITY_TELEPATHY,           ABILITY_SYNCHRONIZE,         ABILITY_ANALYTIC             } }, //  606 beheeyem
    { SPECIES_LITWICK,                   { ABILITY_FLASH_FIRE,          ABILITY_FLAME_BODY,          ABILITY_INFILTRATOR          } }, //  607 litwick
    { SPECIES_LAMPENT,                   { ABILITY_FLASH_FIRE,          ABILITY_FLAME_BODY,          ABILITY_INFILTRATOR          } }, //  608 lampent
    { SPECIES_CHANDELURE,                { ABILITY_FLASH_FIRE,          ABILITY_FLAME_BODY,          ABILITY_INFILTRATOR          } }, //  609 chandelure
    { SPECIES_AXEW,                      { ABILITY_HYPER_CUTTER,        ABILITY_NONE,                ABILITY_UNNERVE              } }, //  610 axew   2.0: RIVALRY,MOLD_BREAKER,UNNERVE
    { SPECIES_FRAXURE,                   { ABILITY_HYPER_CUTTER,        ABILITY_NONE,                ABILITY_UNNERVE              } }, //  611 fraxure   2.0: RIVALRY,MOLD_BREAKER,UNNERVE
    { SPECIES_HAXORUS,                   { ABILITY_HYPER_CUTTER,        ABILITY_NONE,                ABILITY_UNNERVE              } }, //  612 haxorus   2.0: RIVALRY,MOLD_BREAKER,UNNERVE
    { SPECIES_CUBCHOO,                   { ABILITY_SLUSH_RUSH,          ABILITY_ICE_BODY,            ABILITY_RATTLED              } }, //  613 cubchoo   2.0: SNOW_CLOAK,SLUSH_RUSH,RATTLED
    { SPECIES_BEARTIC,                   { ABILITY_SLUSH_RUSH,          ABILITY_ICE_BODY,            ABILITY_SWIFT_SWIM           } }, //  614 beartic   2.0: SNOW_CLOAK,SLUSH_RUSH,SWIFT_SWIM
    { SPECIES_CRYOGONAL,                 { ABILITY_GLACIAL_DRIFT,       ABILITY_NONE,                ABILITY_NONE                 } }, //  615 cryogonal
    { SPECIES_STUNFISK,                  { ABILITY_STATIC,              ABILITY_LIMBER,              ABILITY_SAND_VEIL            } }, //  618 stunfisk
    { SPECIES_MIENFOO,                   { ABILITY_INNER_FOCUS,         ABILITY_NONE,                ABILITY_RECKLESS             } }, //  619 mienfoo   2.0: INNER_FOCUS,REGENERATOR,RECKLESS
    { SPECIES_MIENSHAO,                  { ABILITY_INNER_FOCUS,         ABILITY_NONE,                ABILITY_RECKLESS             } }, //  620 mienshao   2.0: INNER_FOCUS,REGENERATOR,RECKLESS
    { SPECIES_DRUDDIGON,                 { ABILITY_ROUGH_SKIN,          ABILITY_SHEER_FORCE,         ABILITY_MOLD_BREAKER         } }, //  621 druddigon
    { SPECIES_GOLETT,                    { ABILITY_IRON_FIST,           ABILITY_KLUTZ,               ABILITY_NO_GUARD             } }, //  622 golett
    { SPECIES_GOLURK,                    { ABILITY_IRON_FIST,           ABILITY_KLUTZ,               ABILITY_NO_GUARD             } }, //  623 golurk
    { SPECIES_PAWNIARD,                  { ABILITY_DEFIANT,             ABILITY_INNER_FOCUS,         ABILITY_PRESSURE             } }, //  624 pawniard
    { SPECIES_BISHARP,                   { ABILITY_DEFIANT,             ABILITY_INNER_FOCUS,         ABILITY_PRESSURE             } }, //  625 bisharp
    { SPECIES_KINGAMBIT,                 { ABILITY_DEFIANT,             ABILITY_SUPREME_OVERLORD,    ABILITY_PRESSURE             } }, //  983 kingambit
    { SPECIES_BOUFFALANT,                { ABILITY_RECKLESS,            ABILITY_SAP_SIPPER,          ABILITY_SOUNDPROOF           } }, //  626 bouffalant
    { SPECIES_RUFFLET,                   { ABILITY_HUSTLE,              ABILITY_NONE,                ABILITY_HUSTLE               } }, //  627 rufflet   2.0: KEEN_EYE,SHEER_FORCE,HUSTLE
    { SPECIES_BRAVIARY,                  { ABILITY_KEEN_EYE,            ABILITY_NONE,                ABILITY_DEFIANT              } }, //  628 braviary   2.0: KEEN_EYE,SHEER_FORCE,DEFIANT
    { SPECIES_VULLABY,                   { ABILITY_OVERCOAT,            ABILITY_ANALYTIC,            ABILITY_WEAK_ARMOR           } }, //  629 vullaby   2.0: BIG_PECKS,OVERCOAT,WEAK_ARMOR
    { SPECIES_MANDIBUZZ,                 { ABILITY_OVERCOAT,            ABILITY_ANALYTIC,            ABILITY_WEAK_ARMOR           } }, //  630 mandibuzz   2.0: BIG_PECKS,OVERCOAT,WEAK_ARMOR
    { SPECIES_HEATMOR,                   { ABILITY_GLUTTONY,            ABILITY_FLASH_FIRE,          ABILITY_WHITE_SMOKE          } }, //  631 heatmor
    { SPECIES_DURANT,                    { ABILITY_SWARM,               ABILITY_HUSTLE,              ABILITY_TRUANT               } }, //  632 durant
    { SPECIES_DEINO,                     { ABILITY_HUSTLE,              ABILITY_NONE,                ABILITY_NONE                 } }, //  633 deino
    { SPECIES_ZWEILOUS,                  { ABILITY_HUSTLE,              ABILITY_NONE,                ABILITY_NONE                 } }, //  634 zweilous
    { SPECIES_HYDREIGON,                 { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  635 hydreigon
    { SPECIES_LARVESTA,                  { ABILITY_FLAME_BODY,          ABILITY_NONE,                ABILITY_SWARM                } }, //  636 larvesta
    { SPECIES_VOLCARONA,                 { ABILITY_SHIELD_DUST,         ABILITY_NONE,                ABILITY_SWARM                } }, //  637 volcarona   2.0: FLAME_BODY,NONE,SWARM
    { SPECIES_COBALION,                  { ABILITY_JUSTIFIED,           ABILITY_NONE,                ABILITY_NONE                 } }, //  638 cobalion
    { SPECIES_TERRAKION,                 { ABILITY_JUSTIFIED,           ABILITY_NONE,                ABILITY_NONE                 } }, //  639 terrakion
    { SPECIES_VIRIZION,                  { ABILITY_JUSTIFIED,           ABILITY_NONE,                ABILITY_NONE                 } }, //  640 virizion
    { SPECIES_TORNADUS,                  { ABILITY_PRANKSTER,           ABILITY_NONE,                ABILITY_DEFIANT              } }, //  641 tornadus
    { SPECIES_THUNDURUS,                 { ABILITY_PRANKSTER,           ABILITY_NONE,                ABILITY_DEFIANT              } }, //  642 thundurus
    { SPECIES_RESHIRAM,                  { ABILITY_TURBOBLAZE,          ABILITY_NONE,                ABILITY_NONE                 } }, //  643 reshiram
    { SPECIES_ZEKROM,                    { ABILITY_TERAVOLT,            ABILITY_NONE,                ABILITY_NONE                 } }, //  644 zekrom
    { SPECIES_LANDORUS,                  { ABILITY_SAND_FORCE,          ABILITY_NONE,                ABILITY_SHEER_FORCE          } }, //  645 landorus
    { SPECIES_KYUREM,                    { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  646 kyurem
    { SPECIES_KELDEO,                    { ABILITY_JUSTIFIED,           ABILITY_NONE,                ABILITY_NONE                 } }, //  647 keldeo
    { SPECIES_MELOETTA,                  { ABILITY_SERENE_GRACE,        ABILITY_NONE,                ABILITY_NONE                 } }, //  648 meloetta
    { SPECIES_GENESECT,                  { ABILITY_DOWNLOAD,            ABILITY_NONE,                ABILITY_NONE                 } }, //  649 genesect
    { SPECIES_CHESPIN,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_BULLETPROOF          } }, //  650 chespin
    { SPECIES_QUILLADIN,                 { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_BULLETPROOF          } }, //  651 quilladin
    { SPECIES_CHESNAUGHT,                { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_BULLETPROOF          } }, //  652 chesnaught
    { SPECIES_FENNEKIN,                  { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_MAGICIAN             } }, //  653 fennekin
    { SPECIES_BRAIXEN,                   { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_MAGICIAN             } }, //  654 braixen
    { SPECIES_DELPHOX,                   { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_MAGICIAN             } }, //  655 delphox
    { SPECIES_FROAKIE,                   { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_PROTEAN              } }, //  656 froakie
    { SPECIES_FROGADIER,                 { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_PROTEAN              } }, //  657 frogadier
    { SPECIES_GRENINJA,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_PROTEAN              } }, //  658 greninja
    { SPECIES_BUNNELBY,                  { ABILITY_PICKUP,              ABILITY_CHEEK_POUCH,         ABILITY_HUGE_POWER           } }, //  659 bunnelby
    { SPECIES_DIGGERSBY,                 { ABILITY_PICKUP,              ABILITY_CHEEK_POUCH,         ABILITY_HUGE_POWER           } }, //  660 diggersby
    { SPECIES_FLETCHLING,                { ABILITY_SKITTISH,            ABILITY_BIG_PECKS,           ABILITY_GALE_WINGS           } }, //  661 fletchling
    { SPECIES_FLETCHINDER,               { ABILITY_IMMOLATE,            ABILITY_FLAME_BODY,          ABILITY_GALE_WINGS           } }, //  662 fletchinder
    { SPECIES_TALONFLAME,                { ABILITY_IMMOLATE,            ABILITY_FLAME_BODY,          ABILITY_GALE_WINGS           } }, //  663 talonflame
    { SPECIES_SCATTERBUG,                { ABILITY_SHIELD_DUST,         ABILITY_COMPOUND_EYES,       ABILITY_FRIEND_GUARD         } }, //  664 scatterbug
    { SPECIES_SPEWPA,                    { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_FRIEND_GUARD         } }, //  665 spewpa
    { SPECIES_VIVILLON,                  { ABILITY_SHIELD_DUST,         ABILITY_COMPOUND_EYES,       ABILITY_FRIEND_GUARD         } }, //  666 vivillon
    { SPECIES_LITLEO,                    { ABILITY_RIVALRY,             ABILITY_UNNERVE,             ABILITY_MOXIE                } }, //  667 litleo
    { SPECIES_PYROAR,                    { ABILITY_RIVALRY,             ABILITY_UNNERVE,             ABILITY_MOXIE                } }, //  668 pyroar
    { SPECIES_FLABEBE,                   { ABILITY_FLOWER_VEIL,         ABILITY_NONE,                ABILITY_SYMBIOSIS            } }, //  669 flabebe
    { SPECIES_FLOETTE,                   { ABILITY_FLOWER_VEIL,         ABILITY_NONE,                ABILITY_SYMBIOSIS            } }, //  670 floette
    { SPECIES_FLORGES,                   { ABILITY_FLOWER_VEIL,         ABILITY_NONE,                ABILITY_SYMBIOSIS            } }, //  671 florges
    { SPECIES_SKIDDO,                    { ABILITY_SAP_SIPPER,          ABILITY_NONE,                ABILITY_GRASS_PELT           } }, //  672 skiddo
    { SPECIES_GOGOAT,                    { ABILITY_SAP_SIPPER,          ABILITY_NONE,                ABILITY_GRASS_PELT           } }, //  673 gogoat
    { SPECIES_PANCHAM,                   { ABILITY_HUSTLE,              ABILITY_NONE,                ABILITY_SCRAPPY              } }, //  674 pancham   2.0: IRON_FIST,MOLD_BREAKER,SCRAPPY
    { SPECIES_PANGORO,                   { ABILITY_SCRAPPY,             ABILITY_NONE,                ABILITY_SCRAPPY              } }, //  675 pangoro   2.0: IRON_FIST,MOLD_BREAKER,SCRAPPY
    { SPECIES_FURFROU,                   { ABILITY_FUR_COAT,            ABILITY_NONE,                ABILITY_NONE                 } }, //  676 furfrou
    { SPECIES_ESPURR,                    { ABILITY_KEEN_EYE,            ABILITY_INFILTRATOR,         ABILITY_OWN_TEMPO            } }, //  677 espurr
    { SPECIES_MEOWSTIC,                  { ABILITY_KEEN_EYE,            ABILITY_INFILTRATOR,         ABILITY_PRANKSTER            } }, //  678 meowstic
    { SPECIES_HONEDGE,                   { ABILITY_NO_GUARD,            ABILITY_NONE,                ABILITY_NONE                 } }, //  679 honedge
    { SPECIES_DOUBLADE,                  { ABILITY_NO_GUARD,            ABILITY_NONE,                ABILITY_NONE                 } }, //  680 doublade
    { SPECIES_AEGISLASH,                 { ABILITY_STANCE_CHANGE,       ABILITY_NONE,                ABILITY_NONE                 } }, //  681 aegislash
    { SPECIES_SPRITZEE,                  { ABILITY_HEALER,              ABILITY_NONE,                ABILITY_AROMA_VEIL           } }, //  682 spritzee
    { SPECIES_AROMATISSE,                { ABILITY_HEALER,              ABILITY_NONE,                ABILITY_AROMA_VEIL           } }, //  683 aromatisse
    { SPECIES_SWIRLIX,                   { ABILITY_SWEET_VEIL,          ABILITY_NONE,                ABILITY_UNBURDEN             } }, //  684 swirlix
    { SPECIES_SLURPUFF,                  { ABILITY_SWEET_VEIL,          ABILITY_NONE,                ABILITY_UNBURDEN             } }, //  685 slurpuff
    { SPECIES_INKAY,                     { ABILITY_CONTRARY,            ABILITY_SUCTION_CUPS,        ABILITY_INFILTRATOR          } }, //  686 inkay
    { SPECIES_MALAMAR,                   { ABILITY_CONTRARY,            ABILITY_SUCTION_CUPS,        ABILITY_INFILTRATOR          } }, //  687 malamar
    { SPECIES_BINACLE,                   { ABILITY_TOUGH_CLAWS,         ABILITY_SNIPER,              ABILITY_PICKPOCKET           } }, //  688 binacle
    { SPECIES_BARBARACLE,                { ABILITY_TOUGH_CLAWS,         ABILITY_SNIPER,              ABILITY_PICKPOCKET           } }, //  689 barbaracle
    { SPECIES_SKRELP,                    { ABILITY_POISON_POINT,        ABILITY_POISON_TOUCH,        ABILITY_ADAPTABILITY         } }, //  690 skrelp
    { SPECIES_DRAGALGE,                  { ABILITY_POISON_POINT,        ABILITY_POISON_TOUCH,        ABILITY_ADAPTABILITY         } }, //  691 dragalge
    { SPECIES_CLAUNCHER,                 { ABILITY_MEGA_LAUNCHER,       ABILITY_NONE,                ABILITY_NONE                 } }, //  692 clauncher
    { SPECIES_CLAWITZER,                 { ABILITY_MEGA_LAUNCHER,       ABILITY_NONE,                ABILITY_NONE                 } }, //  693 clawitzer
    { SPECIES_HELIOPTILE,                { ABILITY_DRY_SKIN,            ABILITY_SAND_VEIL,           ABILITY_SOLAR_POWER          } }, //  694 helioptile
    { SPECIES_HELIOLISK,                 { ABILITY_DRY_SKIN,            ABILITY_SAND_VEIL,           ABILITY_SOLAR_POWER          } }, //  695 heliolisk
    { SPECIES_TYRUNT,                    { ABILITY_STRONG_JAW,          ABILITY_NONE,                ABILITY_STURDY               } }, //  696 tyrunt
    { SPECIES_TYRANTRUM,                 { ABILITY_STRONG_JAW,          ABILITY_NONE,                ABILITY_ROCK_HEAD            } }, //  697 tyrantrum
    { SPECIES_AMAURA,                    { ABILITY_REFRIGERATE,         ABILITY_NONE,                ABILITY_SNOW_WARNING         } }, //  698 amaura
    { SPECIES_AURORUS,                   { ABILITY_REFRIGERATE,         ABILITY_NONE,                ABILITY_SNOW_WARNING         } }, //  699 aurorus
    { SPECIES_HAWLUCHA,                  { ABILITY_LIMBER,              ABILITY_UNBURDEN,            ABILITY_MOLD_BREAKER         } }, //  701 hawlucha
    { SPECIES_DEDENNE,                   { ABILITY_CHEEK_POUCH,         ABILITY_PICKUP,              ABILITY_PLUS                 } }, //  702 dedenne
    { SPECIES_CARBINK,                   { ABILITY_CLEAR_BODY,          ABILITY_NONE,                ABILITY_STURDY               } }, //  703 carbink
    { SPECIES_GOOMY,                     { ABILITY_SAP_SIPPER,          ABILITY_HYDRATION,           ABILITY_GOOEY                } }, //  704 goomy
    { SPECIES_SLIGGOO,                   { ABILITY_SAP_SIPPER,          ABILITY_HYDRATION,           ABILITY_GOOEY                } }, //  705 sliggoo
    { SPECIES_GOODRA,                    { ABILITY_SAP_SIPPER,          ABILITY_HYDRATION,           ABILITY_GOOEY                } }, //  706 goodra
    { SPECIES_KLEFKI,                    { ABILITY_PRANKSTER,           ABILITY_NONE,                ABILITY_MAGICIAN             } }, //  707 klefki
    { SPECIES_PHANTUMP,                  { ABILITY_NATURAL_CURE,        ABILITY_FRISK,               ABILITY_HARVEST              } }, //  708 phantump
    { SPECIES_TREVENANT,                 { ABILITY_NATURAL_CURE,        ABILITY_FRISK,               ABILITY_HARVEST              } }, //  709 trevenant
    { SPECIES_PUMPKABOO,                 { ABILITY_PICKUP,              ABILITY_FRISK,               ABILITY_INSOMNIA             } }, //  710 pumpkaboo
    { SPECIES_GOURGEIST,                 { ABILITY_PICKUP,              ABILITY_FRISK,               ABILITY_INSOMNIA             } }, //  711 gourgeist
    { SPECIES_BERGMITE,                  { ABILITY_OWN_TEMPO,           ABILITY_ICE_BODY,            ABILITY_STURDY               } }, //  712 bergmite
    { SPECIES_AVALUGG,                   { ABILITY_OWN_TEMPO,           ABILITY_ICE_BODY,            ABILITY_STURDY               } }, //  713 avalugg
    { SPECIES_NOIBAT,                    { ABILITY_FRISK,               ABILITY_INFILTRATOR,         ABILITY_TELEPATHY            } }, //  714 noibat
    { SPECIES_NOIVERN,                   { ABILITY_FRISK,               ABILITY_INFILTRATOR,         ABILITY_TELEPATHY            } }, //  715 noivern
    { SPECIES_XERNEAS,                   { ABILITY_FAIRY_AURA,          ABILITY_NONE,                ABILITY_NONE                 } }, //  716 xerneas
    { SPECIES_YVELTAL,                   { ABILITY_DARK_AURA,           ABILITY_NONE,                ABILITY_NONE                 } }, //  717 yveltal
    { SPECIES_ZYGARDE,                   { ABILITY_AURA_BREAK,          ABILITY_NONE,                ABILITY_NONE                 } }, //  718 zygarde
    { SPECIES_DIANCIE,                   { ABILITY_CLEAR_BODY,          ABILITY_NONE,                ABILITY_NONE                 } }, //  719 diancie
    { SPECIES_HOOPA,                     { ABILITY_MAGICIAN,            ABILITY_NONE,                ABILITY_NONE                 } }, //  720 hoopa
    { SPECIES_VOLCANION,                 { ABILITY_WATER_ABSORB,        ABILITY_NONE,                ABILITY_NONE                 } }, //  721 volcanion
    { SPECIES_ROWLET,                    { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_LONG_REACH           } }, //  722 rowlet
    { SPECIES_DARTRIX,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_LONG_REACH           } }, //  723 dartrix
    { SPECIES_DECIDUEYE,                 { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_LONG_REACH           } }, //  724 decidueye
    { SPECIES_LITTEN,                    { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_INTIMIDATE           } }, //  725 litten
    { SPECIES_TORRACAT,                  { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_INTIMIDATE           } }, //  726 torracat
    { SPECIES_INCINEROAR,                { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_INTIMIDATE           } }, //  727 incineroar
    { SPECIES_POPPLIO,                   { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_LIQUID_VOICE         } }, //  728 popplio
    { SPECIES_BRIONNE,                   { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_LIQUID_VOICE         } }, //  729 brionne
    { SPECIES_PRIMARINA,                 { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_LIQUID_VOICE         } }, //  730 primarina
    { SPECIES_PIKIPEK,                   { ABILITY_KEEN_EYE,            ABILITY_SKILL_LINK,          ABILITY_PICKUP               } }, //  731 pikipek
    { SPECIES_TRUMBEAK,                  { ABILITY_KEEN_EYE,            ABILITY_SKILL_LINK,          ABILITY_PICKUP               } }, //  732 trumbeak
    { SPECIES_TOUCANNON,                 { ABILITY_KEEN_EYE,            ABILITY_SKILL_LINK,          ABILITY_SHEER_FORCE          } }, //  733 toucannon
    { SPECIES_YUNGOOS,                   { ABILITY_STAKEOUT,            ABILITY_STRONG_JAW,          ABILITY_ADAPTABILITY         } }, //  734 yungoos
    { SPECIES_GUMSHOOS,                  { ABILITY_STAKEOUT,            ABILITY_STRONG_JAW,          ABILITY_ADAPTABILITY         } }, //  735 gumshoos
    { SPECIES_GRUBBIN,                   { ABILITY_SWARM,               ABILITY_NONE,                ABILITY_NONE                 } }, //  736 grubbin
    { SPECIES_CHARJABUG,                 { ABILITY_BATTERY,             ABILITY_NONE,                ABILITY_NONE                 } }, //  737 charjabug
    { SPECIES_VIKAVOLT,                  { ABILITY_LEVITATE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  738 vikavolt
    { SPECIES_CRABRAWLER,                { ABILITY_HYPER_CUTTER,        ABILITY_IRON_FIST,           ABILITY_ANGER_POINT          } }, //  739 crabrawler
    { SPECIES_CRABOMINABLE,              { ABILITY_HYPER_CUTTER,        ABILITY_IRON_FIST,           ABILITY_ANGER_POINT          } }, //  740 crabominable
    { SPECIES_ORICORIO,                  { ABILITY_DANCER,              ABILITY_NONE,                ABILITY_NONE                 } }, //  741 oricorio
    { SPECIES_CUTIEFLY,                  { ABILITY_HONEY_GATHER,        ABILITY_SHIELD_DUST,         ABILITY_SWEET_VEIL           } }, //  742 cutiefly
    { SPECIES_RIBOMBEE,                  { ABILITY_HONEY_GATHER,        ABILITY_SHIELD_DUST,         ABILITY_SWEET_VEIL           } }, //  743 ribombee
    { SPECIES_ROCKRUFF,                  { ABILITY_KEEN_EYE,            ABILITY_VITAL_SPIRIT,        ABILITY_STEADFAST            } }, //  744 rockruff
    { SPECIES_LYCANROC,                  { ABILITY_KEEN_EYE,            ABILITY_SAND_RUSH,           ABILITY_STEADFAST            } }, //  745 lycanroc
    { SPECIES_WISHIWASHI,                { ABILITY_SCHOOLING,           ABILITY_NONE,                ABILITY_NONE                 } }, //  746 wishiwashi
    { SPECIES_MAREANIE,                  { ABILITY_MERCILESS,           ABILITY_LIMBER,              ABILITY_REGENERATOR          } }, //  747 mareanie
    { SPECIES_TOXAPEX,                   { ABILITY_MERCILESS,           ABILITY_LIMBER,              ABILITY_REGENERATOR          } }, //  748 toxapex
    { SPECIES_MUDBRAY,                   { ABILITY_OWN_TEMPO,           ABILITY_STAMINA,             ABILITY_INNER_FOCUS          } }, //  749 mudbray
    { SPECIES_MUDSDALE,                  { ABILITY_OWN_TEMPO,           ABILITY_STAMINA,             ABILITY_INNER_FOCUS          } }, //  750 mudsdale
    { SPECIES_DEWPIDER,                  { ABILITY_WATER_BUBBLE,        ABILITY_NONE,                ABILITY_WATER_ABSORB         } }, //  751 dewpider
    { SPECIES_ARAQUANID,                 { ABILITY_WATER_BUBBLE,        ABILITY_NONE,                ABILITY_WATER_ABSORB         } }, //  752 araquanid
    { SPECIES_FOMANTIS,                  { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_CONTRARY             } }, //  753 fomantis   2.0: LEAF_GUARD,NONE,CONTRARY
    { SPECIES_LURANTIS,                  { ABILITY_CHLOROPHYLL,         ABILITY_NONE,                ABILITY_CONTRARY             } }, //  754 lurantis   2.0: LEAF_GUARD,NONE,CONTRARY
    { SPECIES_MORELULL,                  { ABILITY_ILLUMINATE,          ABILITY_EFFECT_SPORE,        ABILITY_RAIN_DISH            } }, //  755 morelull
    { SPECIES_SHIINOTIC,                 { ABILITY_ILLUMINATE,          ABILITY_EFFECT_SPORE,        ABILITY_RAIN_DISH            } }, //  756 shiinotic
    { SPECIES_SALANDIT,                  { ABILITY_CORROSION,           ABILITY_NONE,                ABILITY_OBLIVIOUS            } }, //  757 salandit
    { SPECIES_SALAZZLE,                  { ABILITY_CORROSION,           ABILITY_NONE,                ABILITY_OBLIVIOUS            } }, //  758 salazzle
    { SPECIES_STUFFUL,                   { ABILITY_FLUFFY,              ABILITY_KLUTZ,               ABILITY_CUTE_CHARM           } }, //  759 stufful
    { SPECIES_BEWEAR,                    { ABILITY_FLUFFY,              ABILITY_KLUTZ,               ABILITY_UNNERVE              } }, //  760 bewear
    { SPECIES_BOUNSWEET,                 { ABILITY_LEAF_GUARD,          ABILITY_OBLIVIOUS,           ABILITY_SWEET_VEIL           } }, //  761 bounsweet
    { SPECIES_STEENEE,                   { ABILITY_LEAF_GUARD,          ABILITY_OBLIVIOUS,           ABILITY_SWEET_VEIL           } }, //  762 steenee
    { SPECIES_TSAREENA,                  { ABILITY_LEAF_GUARD,          ABILITY_QUEENLY_MAJESTY,     ABILITY_SWEET_VEIL           } }, //  763 tsareena
    { SPECIES_COMFEY,                    { ABILITY_FLOWER_VEIL,         ABILITY_TRIAGE,              ABILITY_NATURAL_CURE         } }, //  764 comfey
    { SPECIES_ORANGURU,                  { ABILITY_INNER_FOCUS,         ABILITY_TELEPATHY,           ABILITY_SYMBIOSIS            } }, //  765 oranguru
    { SPECIES_PASSIMIAN,                 { ABILITY_RECEIVER,            ABILITY_NONE,                ABILITY_DEFIANT              } }, //  766 passimian
    { SPECIES_WIMPOD,                    { ABILITY_WIMP_OUT,            ABILITY_NONE,                ABILITY_NONE                 } }, //  767 wimpod
    { SPECIES_GOLISOPOD,                 { ABILITY_EMERGENCY_EXIT,      ABILITY_NONE,                ABILITY_NONE                 } }, //  768 golisopod
    { SPECIES_SANDYGAST,                 { ABILITY_WATER_COMPACTION,    ABILITY_NONE,                ABILITY_SAND_VEIL            } }, //  769 sandygast
    { SPECIES_PALOSSAND,                 { ABILITY_WATER_COMPACTION,    ABILITY_NONE,                ABILITY_SAND_VEIL            } }, //  770 palossand
    { SPECIES_PYUKUMUKU,                 { ABILITY_INNARDS_OUT,         ABILITY_NONE,                ABILITY_UNAWARE              } }, //  771 pyukumuku
    { SPECIES_TYPE_NULL,                 { ABILITY_BATTLE_ARMOR,        ABILITY_NONE,                ABILITY_NONE                 } }, //  772 type_null
    { SPECIES_SILVALLY,                  { ABILITY_RKS_SYSTEM,          ABILITY_NONE,                ABILITY_NONE                 } }, //  773 silvally
    { SPECIES_MINIOR,                    { ABILITY_SHIELDS_DOWN,        ABILITY_NONE,                ABILITY_NONE                 } }, //  774 minior
    { SPECIES_KOMALA,                    { ABILITY_COMATOSE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  775 komala
    { SPECIES_TURTONATOR,                { ABILITY_SHELL_ARMOR,         ABILITY_NONE,                ABILITY_NONE                 } }, //  776 turtonator
    { SPECIES_TOGEDEMARU,                { ABILITY_IRON_BARBS,          ABILITY_LIGHTNING_ROD,       ABILITY_STURDY               } }, //  777 togedemaru
    { SPECIES_MIMIKYU,                   { ABILITY_DISGUISE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  778 mimikyu
    { SPECIES_BRUXISH,                   { ABILITY_DAZZLING,            ABILITY_STRONG_JAW,          ABILITY_WONDER_SKIN          } }, //  779 bruxish
    { SPECIES_DRAMPA,                    { ABILITY_BERSERK,             ABILITY_SAP_SIPPER,          ABILITY_CLOUD_NINE           } }, //  780 drampa
    { SPECIES_DHELMISE,                  { ABILITY_STEELWORKER,         ABILITY_NONE,                ABILITY_NONE                 } }, //  781 dhelmise
    { SPECIES_JANGMO_O,                  { ABILITY_BULLETPROOF,         ABILITY_SOUNDPROOF,          ABILITY_OVERCOAT             } }, //  782 jangmo_o
    { SPECIES_HAKAMO_O,                  { ABILITY_BULLETPROOF,         ABILITY_SOUNDPROOF,          ABILITY_OVERCOAT             } }, //  783 hakamo_o
    { SPECIES_KOMMO_O,                   { ABILITY_BULLETPROOF,         ABILITY_SOUNDPROOF,          ABILITY_OVERCOAT             } }, //  784 kommo_o
    { SPECIES_TAPU_KOKO,                 { ABILITY_ELECTRIC_SURGE,      ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  785 tapu_koko
    { SPECIES_TAPU_LELE,                 { ABILITY_PSYCHIC_SURGE,       ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  786 tapu_lele
    { SPECIES_TAPU_BULU,                 { ABILITY_GRASSY_SURGE,        ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  787 tapu_bulu
    { SPECIES_TAPU_FINI,                 { ABILITY_MISTY_SURGE,         ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  788 tapu_fini
    { SPECIES_COSMOG,                    { ABILITY_UNAWARE,             ABILITY_NONE,                ABILITY_NONE                 } }, //  789 cosmog
    { SPECIES_COSMOEM,                   { ABILITY_STURDY,              ABILITY_NONE,                ABILITY_NONE                 } }, //  790 cosmoem
    { SPECIES_SOLGALEO,                  { ABILITY_FULL_METAL_BODY,     ABILITY_NONE,                ABILITY_NONE                 } }, //  791 solgaleo
    { SPECIES_LUNALA,                    { ABILITY_SHADOW_SHIELD,       ABILITY_NONE,                ABILITY_NONE                 } }, //  792 lunala
    { SPECIES_NIHILEGO,                  { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  793 nihilego
    { SPECIES_BUZZWOLE,                  { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  794 buzzwole
    { SPECIES_PHEROMOSA,                 { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  795 pheromosa
    { SPECIES_XURKITREE,                 { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  796 xurkitree
    { SPECIES_CELESTEELA,                { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  797 celesteela
    { SPECIES_KARTANA,                   { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  798 kartana
    { SPECIES_GUZZLORD,                  { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  799 guzzlord
    { SPECIES_NECROZMA,                  { ABILITY_PRISM_ARMOR,         ABILITY_NONE,                ABILITY_NONE                 } }, //  800 necrozma
    { SPECIES_MAGEARNA,                  { ABILITY_SOUL_HEART,          ABILITY_NONE,                ABILITY_NONE                 } }, //  801 magearna
    { SPECIES_MARSHADOW,                 { ABILITY_TECHNICIAN,          ABILITY_NONE,                ABILITY_NONE                 } }, //  802 marshadow
    { SPECIES_POIPOLE,                   { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  803 poipole
    { SPECIES_NAGANADEL,                 { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  804 naganadel
    { SPECIES_STAKATAKA,                 { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  805 stakataka
    { SPECIES_BLACEPHALON,               { ABILITY_BEAST_BOOST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  806 blacephalon
    { SPECIES_ZERAORA,                   { ABILITY_VOLT_ABSORB,         ABILITY_NONE,                ABILITY_NONE                 } }, //  807 zeraora
    { SPECIES_MELTAN,                    { ABILITY_MAGNET_PULL,         ABILITY_NONE,                ABILITY_NONE                 } }, //  808 meltan
    { SPECIES_MELMETAL,                  { ABILITY_IRON_FIST,           ABILITY_NONE,                ABILITY_NONE                 } }, //  809 melmetal
    { SPECIES_GROOKEY,                   { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_GRASSY_SURGE         } }, //  810 grookey
    { SPECIES_THWACKEY,                  { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_GRASSY_SURGE         } }, //  811 thwackey
    { SPECIES_RILLABOOM,                 { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_GRASSY_SURGE         } }, //  812 rillaboom
    { SPECIES_SCORBUNNY,                 { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_LIBERO               } }, //  813 scorbunny
    { SPECIES_RABOOT,                    { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_LIBERO               } }, //  814 raboot
    { SPECIES_CINDERACE,                 { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_LIBERO               } }, //  815 cinderace
    { SPECIES_SOBBLE,                    { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SNIPER               } }, //  816 sobble
    { SPECIES_DRIZZILE,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SNIPER               } }, //  817 drizzile
    { SPECIES_INTELEON,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_SNIPER               } }, //  818 inteleon
    { SPECIES_SKWOVET,                   { ABILITY_CHEEK_POUCH,         ABILITY_NONE,                ABILITY_GLUTTONY             } }, //  819 skwovet
    { SPECIES_GREEDENT,                  { ABILITY_CHEEK_POUCH,         ABILITY_NONE,                ABILITY_GLUTTONY             } }, //  820 greedent
    { SPECIES_ROOKIDEE,                  { ABILITY_KEEN_EYE,            ABILITY_UNNERVE,             ABILITY_BIG_PECKS            } }, //  821 rookidee
    { SPECIES_CORVISQUIRE,               { ABILITY_KEEN_EYE,            ABILITY_UNNERVE,             ABILITY_BIG_PECKS            } }, //  822 corvisquire
    { SPECIES_CORVIKNIGHT,               { ABILITY_PRESSURE,            ABILITY_UNNERVE,             ABILITY_MIRROR_ARMOR         } }, //  823 corviknight
    { SPECIES_BLIPBUG,                   { ABILITY_SWARM,               ABILITY_COMPOUND_EYES,       ABILITY_TELEPATHY            } }, //  824 blipbug
    { SPECIES_DOTTLER,                   { ABILITY_SWARM,               ABILITY_COMPOUND_EYES,       ABILITY_TELEPATHY            } }, //  825 dottler
    { SPECIES_ORBEETLE,                  { ABILITY_SWARM,               ABILITY_FRISK,               ABILITY_TELEPATHY            } }, //  826 orbeetle
    { SPECIES_NICKIT,                    { ABILITY_RUN_AWAY,            ABILITY_UNBURDEN,            ABILITY_STAKEOUT             } }, //  827 nickit
    { SPECIES_THIEVUL,                   { ABILITY_RUN_AWAY,            ABILITY_UNBURDEN,            ABILITY_STAKEOUT             } }, //  828 thievul
    { SPECIES_GOSSIFLEUR,                { ABILITY_COTTON_DOWN,         ABILITY_REGENERATOR,         ABILITY_EFFECT_SPORE         } }, //  829 gossifleur
    { SPECIES_ELDEGOSS,                  { ABILITY_COTTON_DOWN,         ABILITY_REGENERATOR,         ABILITY_EFFECT_SPORE         } }, //  830 eldegoss
    { SPECIES_WOOLOO,                    { ABILITY_FLUFFY,              ABILITY_RUN_AWAY,            ABILITY_BULLETPROOF          } }, //  831 wooloo
    { SPECIES_DUBWOOL,                   { ABILITY_FLUFFY,              ABILITY_STEADFAST,           ABILITY_BULLETPROOF          } }, //  832 dubwool
    { SPECIES_CHEWTLE,                   { ABILITY_STRONG_JAW,          ABILITY_SHELL_ARMOR,         ABILITY_SWIFT_SWIM           } }, //  833 chewtle
    { SPECIES_DREDNAW,                   { ABILITY_STRONG_JAW,          ABILITY_SHELL_ARMOR,         ABILITY_SWIFT_SWIM           } }, //  834 drednaw
    { SPECIES_YAMPER,                    { ABILITY_BALL_FETCH,          ABILITY_NONE,                ABILITY_RATTLED              } }, //  835 yamper
    { SPECIES_BOLTUND,                   { ABILITY_STRONG_JAW,          ABILITY_NONE,                ABILITY_COMPETITIVE          } }, //  836 boltund
    { SPECIES_ROLYCOLY,                  { ABILITY_STEAM_ENGINE,        ABILITY_HEATPROOF,           ABILITY_FLASH_FIRE           } }, //  837 rolycoly
    { SPECIES_CARKOL,                    { ABILITY_STEAM_ENGINE,        ABILITY_FLAME_BODY,          ABILITY_FLASH_FIRE           } }, //  838 carkol
    { SPECIES_COALOSSAL,                 { ABILITY_STEAM_ENGINE,        ABILITY_FLAME_BODY,          ABILITY_FLASH_FIRE           } }, //  839 coalossal
    { SPECIES_APPLIN,                    { ABILITY_RIPEN,               ABILITY_GLUTTONY,            ABILITY_BULLETPROOF          } }, //  840 applin
    { SPECIES_FLAPPLE,                   { ABILITY_RIPEN,               ABILITY_GLUTTONY,            ABILITY_HUSTLE               } }, //  841 flapple
    { SPECIES_APPLETUN,                  { ABILITY_RIPEN,               ABILITY_GLUTTONY,            ABILITY_THICK_FAT            } }, //  842 appletun
    { SPECIES_DIPPLIN,                   { ABILITY_SUPERSWEET_SYRUP,    ABILITY_GLUTTONY,            ABILITY_STICKY_HOLD          } }, // 1011 dipplin
    { SPECIES_HYDRAPPLE,                 { ABILITY_SUPERSWEET_SYRUP,    ABILITY_REGENERATOR,         ABILITY_STICKY_HOLD          } }, // 1019 hydrapple
    { SPECIES_SILICOBRA,                 { ABILITY_SAND_SPIT,           ABILITY_SHED_SKIN,           ABILITY_SAND_VEIL            } }, //  843 silicobra
    { SPECIES_SANDACONDA,                { ABILITY_SAND_SPIT,           ABILITY_SHED_SKIN,           ABILITY_SAND_VEIL            } }, //  844 sandaconda
    { SPECIES_CRAMORANT,                 { ABILITY_GULP_MISSILE,        ABILITY_NONE,                ABILITY_NONE                 } }, //  845 cramorant
    { SPECIES_ARROKUDA,                  { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_PROPELLER_TAIL       } }, //  846 arrokuda
    { SPECIES_BARRASKEWDA,               { ABILITY_SWIFT_SWIM,          ABILITY_NONE,                ABILITY_PROPELLER_TAIL       } }, //  847 barraskewda
    { SPECIES_TOXEL,                     { ABILITY_RATTLED,             ABILITY_STATIC,              ABILITY_KLUTZ                } }, //  848 toxel
    { SPECIES_TOXTRICITY,                { ABILITY_PUNK_ROCK,           ABILITY_PLUS,                ABILITY_TECHNICIAN           } }, //  849 toxtricity
    { SPECIES_SIZZLIPEDE,                { ABILITY_FLASH_FIRE,          ABILITY_WHITE_SMOKE,         ABILITY_FLAME_BODY           } }, //  850 sizzlipede
    { SPECIES_CENTISKORCH,               { ABILITY_FLASH_FIRE,          ABILITY_WHITE_SMOKE,         ABILITY_FLAME_BODY           } }, //  851 centiskorch
    { SPECIES_CLOBBOPUS,                 { ABILITY_LIMBER,              ABILITY_NONE,                ABILITY_TECHNICIAN           } }, //  852 clobbopus
    { SPECIES_GRAPPLOCT,                 { ABILITY_LIMBER,              ABILITY_NONE,                ABILITY_TECHNICIAN           } }, //  853 grapploct
    { SPECIES_SINISTEA,                  { ABILITY_WEAK_ARMOR,          ABILITY_NONE,                ABILITY_CURSED_BODY          } }, //  854 sinistea
    { SPECIES_POLTEAGEIST,               { ABILITY_WEAK_ARMOR,          ABILITY_NONE,                ABILITY_CURSED_BODY          } }, //  855 polteageist
    { SPECIES_HATENNA,                   { ABILITY_HEALER,              ABILITY_ANTICIPATION,        ABILITY_MAGIC_BOUNCE         } }, //  856 hatenna
    { SPECIES_HATTREM,                   { ABILITY_HEALER,              ABILITY_ANTICIPATION,        ABILITY_MAGIC_BOUNCE         } }, //  857 hattrem
    { SPECIES_HATTERENE,                 { ABILITY_HEALER,              ABILITY_ANTICIPATION,        ABILITY_MAGIC_BOUNCE         } }, //  858 hatterene
    { SPECIES_IMPIDIMP,                  { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_PICKPOCKET           } }, //  859 impidimp   2.0: PRANKSTER,FRISK,PICKPOCKET
    { SPECIES_MORGREM,                   { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_PICKPOCKET           } }, //  860 morgrem   2.0: PRANKSTER,FRISK,PICKPOCKET
    { SPECIES_GRIMMSNARL,                { ABILITY_GUTS,                ABILITY_NONE,                ABILITY_PICKPOCKET           } }, //  861 grimmsnarl   2.0: PRANKSTER,FRISK,PICKPOCKET
    { SPECIES_OBSTAGOON,                 { ABILITY_RECKLESS,            ABILITY_GUTS,                ABILITY_DEFIANT              } }, //  862 obstagoon   [disabled by the regional-form gate]
    { SPECIES_PERRSERKER,                { ABILITY_BATTLE_ARMOR,        ABILITY_TOUGH_CLAWS,         ABILITY_STEELY_SPIRIT        } }, //  863 perrserker   [disabled by the regional-form gate]
    { SPECIES_CURSOLA,                   { ABILITY_WEAK_ARMOR,          ABILITY_NONE,                ABILITY_PERISH_BODY          } }, //  864 cursola   [disabled by the regional-form gate]
    { SPECIES_SIRFETCHD,                 { ABILITY_STEADFAST,           ABILITY_NONE,                ABILITY_SCRAPPY              } }, //  865 sirfetchd   [disabled by the regional-form gate]
    { SPECIES_RUNERIGUS,                 { ABILITY_WANDERING_SPIRIT,    ABILITY_NONE,                ABILITY_NONE                 } }, //  867 runerigus   [disabled by the regional-form gate]
    { SPECIES_MILCERY,                   { ABILITY_SWEET_VEIL,          ABILITY_NONE,                ABILITY_AROMA_VEIL           } }, //  868 milcery
    { SPECIES_ALCREMIE,                  { ABILITY_SWEET_VEIL,          ABILITY_NONE,                ABILITY_AROMA_VEIL           } }, //  869 alcremie
    { SPECIES_FALINKS,                   { ABILITY_BATTLE_ARMOR,        ABILITY_NONE,                ABILITY_DEFIANT              } }, //  870 falinks
    { SPECIES_PINCURCHIN,                { ABILITY_LIGHTNING_ROD,       ABILITY_NONE,                ABILITY_ELECTRIC_SURGE       } }, //  871 pincurchin
    { SPECIES_SNOM,                      { ABILITY_SHIELD_DUST,         ABILITY_NONE,                ABILITY_ICE_SCALES           } }, //  872 snom
    { SPECIES_FROSMOTH,                  { ABILITY_SHIELD_DUST,         ABILITY_NONE,                ABILITY_ICE_SCALES           } }, //  873 frosmoth
    { SPECIES_STONJOURNER,               { ABILITY_POWER_SPOT,          ABILITY_NONE,                ABILITY_NONE                 } }, //  874 stonjourner
    { SPECIES_EISCUE,                    { ABILITY_ICE_FACE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  875 eiscue
    { SPECIES_INDEEDEE,                  { ABILITY_INNER_FOCUS,         ABILITY_SYNCHRONIZE,         ABILITY_PSYCHIC_SURGE        } }, //  876 indeedee
    { SPECIES_MORPEKO,                   { ABILITY_HUNGER_SWITCH,       ABILITY_NONE,                ABILITY_NONE                 } }, //  877 morpeko
    { SPECIES_CUFANT,                    { ABILITY_SHEER_FORCE,         ABILITY_NONE,                ABILITY_HEAVY_METAL          } }, //  878 cufant
    { SPECIES_COPPERAJAH,                { ABILITY_SHEER_FORCE,         ABILITY_NONE,                ABILITY_HEAVY_METAL          } }, //  879 copperajah
    { SPECIES_DRACOZOLT,                 { ABILITY_VOLT_ABSORB,         ABILITY_HUSTLE,              ABILITY_SAND_RUSH            } }, //  880 dracozolt
    { SPECIES_ARCTOZOLT,                 { ABILITY_VOLT_ABSORB,         ABILITY_STATIC,              ABILITY_SLUSH_RUSH           } }, //  881 arctozolt
    { SPECIES_DRACOVISH,                 { ABILITY_WATER_ABSORB,        ABILITY_STRONG_JAW,          ABILITY_SAND_RUSH            } }, //  882 dracovish
    { SPECIES_ARCTOVISH,                 { ABILITY_WATER_ABSORB,        ABILITY_ICE_BODY,            ABILITY_SLUSH_RUSH           } }, //  883 arctovish
    { SPECIES_DURALUDON,                 { ABILITY_LIGHT_METAL,         ABILITY_HEAVY_METAL,         ABILITY_STALWART             } }, //  884 duraludon
    { SPECIES_ARCHALUDON,                { ABILITY_STAMINA,             ABILITY_STURDY,              ABILITY_STALWART             } }, // 1018 archaludon
    { SPECIES_DREEPY,                    { ABILITY_CLEAR_BODY,          ABILITY_INFILTRATOR,         ABILITY_CURSED_BODY          } }, //  885 dreepy
    { SPECIES_DRAKLOAK,                  { ABILITY_CLEAR_BODY,          ABILITY_INFILTRATOR,         ABILITY_CURSED_BODY          } }, //  886 drakloak
    { SPECIES_DRAGAPULT,                 { ABILITY_CLEAR_BODY,          ABILITY_INFILTRATOR,         ABILITY_CURSED_BODY          } }, //  887 dragapult
    { SPECIES_ZACIAN,                    { ABILITY_INTREPID_SWORD,      ABILITY_NONE,                ABILITY_NONE                 } }, //  888 zacian
    { SPECIES_ZAMAZENTA,                 { ABILITY_DAUNTLESS_SHIELD,    ABILITY_NONE,                ABILITY_NONE                 } }, //  889 zamazenta
    { SPECIES_ETERNATUS,                 { ABILITY_PRESSURE,            ABILITY_NONE,                ABILITY_NONE                 } }, //  890 eternatus
    { SPECIES_KUBFU,                     { ABILITY_INNER_FOCUS,         ABILITY_NONE,                ABILITY_NONE                 } }, //  891 kubfu
    { SPECIES_URSHIFU,                   { ABILITY_UNSEEN_FIST,         ABILITY_NONE,                ABILITY_NONE                 } }, //  892 urshifu
    { SPECIES_ZARUDE,                    { ABILITY_LEAF_GUARD,          ABILITY_NONE,                ABILITY_NONE                 } }, //  893 zarude
    { SPECIES_REGIELEKI,                 { ABILITY_TRANSISTOR,          ABILITY_NONE,                ABILITY_NONE                 } }, //  894 regieleki
    { SPECIES_REGIDRAGO,                 { ABILITY_DRAGONS_MAW,         ABILITY_NONE,                ABILITY_NONE                 } }, //  895 regidrago
    { SPECIES_GLASTRIER,                 { ABILITY_CHILLING_NEIGH,      ABILITY_NONE,                ABILITY_NONE                 } }, //  896 glastrier
    { SPECIES_SPECTRIER,                 { ABILITY_GRIM_NEIGH,          ABILITY_NONE,                ABILITY_NONE                 } }, //  897 spectrier
    { SPECIES_CALYREX,                   { ABILITY_UNNERVE,             ABILITY_NONE,                ABILITY_NONE                 } }, //  898 calyrex
    { SPECIES_BASCULEGION,               { ABILITY_SWIFT_SWIM,          ABILITY_ADAPTABILITY,        ABILITY_MOLD_BREAKER         } }, //  902 basculegion   [disabled by the regional-form gate]
    { SPECIES_SNEASLER,                  { ABILITY_PRESSURE,            ABILITY_UNBURDEN,            ABILITY_POISON_TOUCH         } }, //  903 sneasler   [disabled by the regional-form gate]
    { SPECIES_OVERQWIL,                  { ABILITY_POISON_POINT,        ABILITY_SWIFT_SWIM,          ABILITY_INTIMIDATE           } }, //  904 overqwil   [disabled by the regional-form gate]
    { SPECIES_ENAMORUS,                  { ABILITY_CUTE_CHARM,          ABILITY_NONE,                ABILITY_CONTRARY             } }, //  905 enamorus
    { SPECIES_SPRIGATITO,                { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_PROTEAN              } }, //  906 sprigatito
    { SPECIES_FLORAGATO,                 { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_PROTEAN              } }, //  907 floragato
    { SPECIES_MEOWSCARADA,               { ABILITY_OVERGROW,            ABILITY_NONE,                ABILITY_PROTEAN              } }, //  908 meowscarada
    { SPECIES_FUECOCO,                   { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_UNAWARE              } }, //  909 fuecoco
    { SPECIES_CROCALOR,                  { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_UNAWARE              } }, //  910 crocalor
    { SPECIES_SKELEDIRGE,                { ABILITY_BLAZE,               ABILITY_NONE,                ABILITY_UNAWARE              } }, //  911 skeledirge
    { SPECIES_QUAXLY,                    { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_MOXIE                } }, //  912 quaxly
    { SPECIES_QUAXWELL,                  { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_MOXIE                } }, //  913 quaxwell
    { SPECIES_QUAQUAVAL,                 { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_MOXIE                } }, //  914 quaquaval
    { SPECIES_LECHONK,                   { ABILITY_AROMA_VEIL,          ABILITY_GLUTTONY,            ABILITY_THICK_FAT            } }, //  915 lechonk
    { SPECIES_OINKOLOGNE,                { ABILITY_LINGERING_AROMA,     ABILITY_GLUTTONY,            ABILITY_THICK_FAT            } }, //  916 oinkologne
    { SPECIES_TAROUNTULA,                { ABILITY_INSOMNIA,            ABILITY_NONE,                ABILITY_STAKEOUT             } }, //  917 tarountula
    { SPECIES_SPIDOPS,                   { ABILITY_INSOMNIA,            ABILITY_NONE,                ABILITY_STAKEOUT             } }, //  918 spidops
    { SPECIES_NYMBLE,                    { ABILITY_SWARM,               ABILITY_NONE,                ABILITY_TINTED_LENS          } }, //  919 nymble
    { SPECIES_LOKIX,                     { ABILITY_SWARM,               ABILITY_NONE,                ABILITY_TINTED_LENS          } }, //  920 lokix
    { SPECIES_PAWMI,                     { ABILITY_STATIC,              ABILITY_NATURAL_CURE,        ABILITY_IRON_FIST            } }, //  921 pawmi
    { SPECIES_PAWMO,                     { ABILITY_VOLT_ABSORB,         ABILITY_NATURAL_CURE,        ABILITY_IRON_FIST            } }, //  922 pawmo
    { SPECIES_PAWMOT,                    { ABILITY_VOLT_ABSORB,         ABILITY_NATURAL_CURE,        ABILITY_IRON_FIST            } }, //  923 pawmot
    { SPECIES_TANDEMAUS,                 { ABILITY_RUN_AWAY,            ABILITY_PICKUP,              ABILITY_OWN_TEMPO            } }, //  924 tandemaus
    { SPECIES_MAUSHOLD,                  { ABILITY_FRIEND_GUARD,        ABILITY_CHEEK_POUCH,         ABILITY_TECHNICIAN           } }, //  925 maushold
    { SPECIES_FIDOUGH,                   { ABILITY_OWN_TEMPO,           ABILITY_NONE,                ABILITY_KLUTZ                } }, //  926 fidough
    { SPECIES_DACHSBUN,                  { ABILITY_WELL_BAKED_BODY,     ABILITY_NONE,                ABILITY_AROMA_VEIL           } }, //  927 dachsbun
    { SPECIES_SMOLIV,                    { ABILITY_EARLY_BIRD,          ABILITY_NONE,                ABILITY_HARVEST              } }, //  928 smoliv
    { SPECIES_DOLLIV,                    { ABILITY_EARLY_BIRD,          ABILITY_NONE,                ABILITY_HARVEST              } }, //  929 dolliv
    { SPECIES_ARBOLIVA,                  { ABILITY_SEED_SOWER,          ABILITY_NONE,                ABILITY_HARVEST              } }, //  930 arboliva
    { SPECIES_SQUAWKABILLY,              { ABILITY_INTIMIDATE,          ABILITY_HUSTLE,              ABILITY_GUTS                 } }, //  931 squawkabilly
    { SPECIES_NACLI,                     { ABILITY_PURIFYING_SALT,      ABILITY_STURDY,              ABILITY_CLEAR_BODY           } }, //  932 nacli
    { SPECIES_NACLSTACK,                 { ABILITY_PURIFYING_SALT,      ABILITY_STURDY,              ABILITY_CLEAR_BODY           } }, //  933 naclstack
    { SPECIES_GARGANACL,                 { ABILITY_PURIFYING_SALT,      ABILITY_STURDY,              ABILITY_CLEAR_BODY           } }, //  934 garganacl
    { SPECIES_CHARCADET,                 { ABILITY_FLASH_FIRE,          ABILITY_NONE,                ABILITY_FLAME_BODY           } }, //  935 charcadet
    { SPECIES_ARMAROUGE,                 { ABILITY_FLASH_FIRE,          ABILITY_NONE,                ABILITY_WEAK_ARMOR           } }, //  936 armarouge
    { SPECIES_CERULEDGE,                 { ABILITY_FLASH_FIRE,          ABILITY_NONE,                ABILITY_WEAK_ARMOR           } }, //  937 ceruledge
    { SPECIES_TADBULB,                   { ABILITY_OWN_TEMPO,           ABILITY_STATIC,              ABILITY_DAMP                 } }, //  938 tadbulb
    { SPECIES_BELLIBOLT,                 { ABILITY_ELECTROMORPHOSIS,    ABILITY_STATIC,              ABILITY_DAMP                 } }, //  939 bellibolt
    { SPECIES_WATTREL,                   { ABILITY_WIND_POWER,          ABILITY_VOLT_ABSORB,         ABILITY_COMPETITIVE          } }, //  940 wattrel
    { SPECIES_KILOWATTREL,               { ABILITY_WIND_POWER,          ABILITY_VOLT_ABSORB,         ABILITY_COMPETITIVE          } }, //  941 kilowattrel
    { SPECIES_MASCHIFF,                  { ABILITY_INTIMIDATE,          ABILITY_RUN_AWAY,            ABILITY_STAKEOUT             } }, //  942 maschiff
    { SPECIES_MABOSSTIFF,                { ABILITY_INTIMIDATE,          ABILITY_GUARD_DOG,           ABILITY_STAKEOUT             } }, //  943 mabosstiff
    { SPECIES_SHROODLE,                  { ABILITY_UNBURDEN,            ABILITY_PICKPOCKET,          ABILITY_PRANKSTER            } }, //  944 shroodle
    { SPECIES_GRAFAIAI,                  { ABILITY_UNBURDEN,            ABILITY_POISON_TOUCH,        ABILITY_PRANKSTER            } }, //  945 grafaiai
    { SPECIES_BRAMBLIN,                  { ABILITY_WIND_RIDER,          ABILITY_NONE,                ABILITY_INFILTRATOR          } }, //  946 bramblin
    { SPECIES_BRAMBLEGHAST,              { ABILITY_WIND_RIDER,          ABILITY_NONE,                ABILITY_INFILTRATOR          } }, //  947 brambleghast
    { SPECIES_TOEDSCOOL,                 { ABILITY_MYCELIUM_MIGHT,      ABILITY_NONE,                ABILITY_NONE                 } }, //  948 toedscool
    { SPECIES_TOEDSCRUEL,                { ABILITY_MYCELIUM_MIGHT,      ABILITY_NONE,                ABILITY_NONE                 } }, //  949 toedscruel
    { SPECIES_KLAWF,                     { ABILITY_ANGER_SHELL,         ABILITY_SHELL_ARMOR,         ABILITY_REGENERATOR          } }, //  950 klawf
    { SPECIES_CAPSAKID,                  { ABILITY_CHLOROPHYLL,         ABILITY_INSOMNIA,            ABILITY_KLUTZ                } }, //  951 capsakid
    { SPECIES_SCOVILLAIN,                { ABILITY_CHLOROPHYLL,         ABILITY_INSOMNIA,            ABILITY_MOODY                } }, //  952 scovillain
    { SPECIES_RELLOR,                    { ABILITY_COMPOUND_EYES,       ABILITY_NONE,                ABILITY_SHED_SKIN            } }, //  953 rellor
    { SPECIES_RABSCA,                    { ABILITY_SYNCHRONIZE,         ABILITY_NONE,                ABILITY_TELEPATHY            } }, //  954 rabsca
    { SPECIES_FLITTLE,                   { ABILITY_SKITTISH,            ABILITY_ANTICIPATION,        ABILITY_SPEED_BOOST          } }, //  955 flittle
    { SPECIES_ESPATHRA,                  { ABILITY_SKITTISH,            ABILITY_OPPORTUNIST,         ABILITY_SPEED_BOOST          } }, //  956 espathra
    { SPECIES_TINKATINK,                 { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_PICKPOCKET           } }, //  957 tinkatink   2.0: MOLD_BREAKER,OWN_TEMPO,PICKPOCKET
    { SPECIES_TINKATUFF,                 { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_PICKPOCKET           } }, //  958 tinkatuff   2.0: MOLD_BREAKER,OWN_TEMPO,PICKPOCKET
    { SPECIES_TINKATON,                  { ABILITY_ADAPTABILITY,        ABILITY_NONE,                ABILITY_PICKPOCKET           } }, //  959 tinkaton   2.0: MOLD_BREAKER,OWN_TEMPO,PICKPOCKET
    { SPECIES_WIGLETT,                   { ABILITY_GOOEY,               ABILITY_RATTLED,             ABILITY_SAND_VEIL            } }, //  960 wiglett
    { SPECIES_WUGTRIO,                   { ABILITY_GOOEY,               ABILITY_RATTLED,             ABILITY_SAND_VEIL            } }, //  961 wugtrio
    { SPECIES_BOMBIRDIER,                { ABILITY_ROCKY_PAYLOAD,       ABILITY_NONE,                ABILITY_ROCKY_PAYLOAD        } }, //  962 bombirdier   2.0: BIG_PECKS,KEEN_EYE,ROCKY_PAYLOAD
    { SPECIES_FINIZEN,                   { ABILITY_WATER_VEIL,          ABILITY_NONE,                ABILITY_NONE                 } }, //  963 finizen
    { SPECIES_PALAFIN,                   { ABILITY_ZERO_TO_HERO,        ABILITY_NONE,                ABILITY_NONE                 } }, //  964 palafin
    { SPECIES_VAROOM,                    { ABILITY_OVERCOAT,            ABILITY_NONE,                ABILITY_SLOW_START           } }, //  965 varoom
    { SPECIES_REVAVROOM,                 { ABILITY_OVERCOAT,            ABILITY_NONE,                ABILITY_FILTER               } }, //  966 revavroom
    { SPECIES_CYCLIZAR,                  { ABILITY_SHED_SKIN,           ABILITY_NONE,                ABILITY_REGENERATOR          } }, //  967 cyclizar
    { SPECIES_ORTHWORM,                  { ABILITY_EARTH_EATER,         ABILITY_NONE,                ABILITY_SAND_VEIL            } }, //  968 orthworm
    { SPECIES_GLIMMET,                   { ABILITY_TOXIC_DEBRIS,        ABILITY_NONE,                ABILITY_CORROSION            } }, //  969 glimmet
    { SPECIES_GLIMMORA,                  { ABILITY_TOXIC_DEBRIS,        ABILITY_NONE,                ABILITY_CORROSION            } }, //  970 glimmora
    { SPECIES_GREAVARD,                  { ABILITY_PICKUP,              ABILITY_NONE,                ABILITY_FLUFFY               } }, //  971 greavard
    { SPECIES_HOUNDSTONE,                { ABILITY_CURSED_BODY,         ABILITY_NONE,                ABILITY_FLUFFY               } }, //  972 houndstone   2.0: SAND_RUSH,NONE,FLUFFY
    { SPECIES_FLAMIGO,                   { ABILITY_SCRAPPY,             ABILITY_TANGLED_FEET,        ABILITY_COSTAR               } }, //  973 flamigo
    { SPECIES_CETODDLE,                  { ABILITY_THICK_FAT,           ABILITY_SNOW_CLOAK,          ABILITY_SHEER_FORCE          } }, //  974 cetoddle
    { SPECIES_CETITAN,                   { ABILITY_THICK_FAT,           ABILITY_SLUSH_RUSH,          ABILITY_SHEER_FORCE          } }, //  975 cetitan
    { SPECIES_VELUZA,                    { ABILITY_MOLD_BREAKER,        ABILITY_NONE,                ABILITY_SHARPNESS            } }, //  976 veluza
    { SPECIES_DONDOZO,                   { ABILITY_UNAWARE,             ABILITY_OBLIVIOUS,           ABILITY_WATER_VEIL           } }, //  977 dondozo
    { SPECIES_TATSUGIRI,                 { ABILITY_COMMANDER,           ABILITY_NONE,                ABILITY_STORM_DRAIN          } }, //  978 tatsugiri
    { SPECIES_CLODSIRE,                  { ABILITY_POISON_POINT,        ABILITY_WATER_ABSORB,        ABILITY_UNAWARE              } }, //  980 clodsire   [disabled by the regional-form gate]
    { SPECIES_DUDUNSPARCE,               { ABILITY_SERENE_GRACE,        ABILITY_RUN_AWAY,            ABILITY_RATTLED              } }, //  982 dudunsparce
    { SPECIES_GREAT_TUSK,                { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, //  984 great_tusk
    { SPECIES_SCREAM_TAIL,               { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, //  985 scream_tail
    { SPECIES_BRUTE_BONNET,              { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, //  986 brute_bonnet
    { SPECIES_FLUTTER_MANE,              { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, //  987 flutter_mane
    { SPECIES_SLITHER_WING,              { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, //  988 slither_wing
    { SPECIES_SANDY_SHOCKS,              { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, //  989 sandy_shocks
    { SPECIES_IRON_TREADS,               { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, //  990 iron_treads
    { SPECIES_IRON_BUNDLE,               { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, //  991 iron_bundle
    { SPECIES_IRON_HANDS,                { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, //  992 iron_hands
    { SPECIES_IRON_JUGULIS,              { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, //  993 iron_jugulis
    { SPECIES_IRON_MOTH,                 { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, //  994 iron_moth
    { SPECIES_IRON_THORNS,               { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, //  995 iron_thorns
    { SPECIES_FRIGIBAX,                  { ABILITY_THERMAL_EXCHANGE,    ABILITY_NONE,                ABILITY_ICE_BODY             } }, //  996 frigibax
    { SPECIES_ARCTIBAX,                  { ABILITY_THERMAL_EXCHANGE,    ABILITY_NONE,                ABILITY_ICE_BODY             } }, //  997 arctibax
    { SPECIES_BAXCALIBUR,                { ABILITY_THERMAL_EXCHANGE,    ABILITY_NONE,                ABILITY_ICE_BODY             } }, //  998 baxcalibur
    { SPECIES_GIMMIGHOUL,                { ABILITY_RATTLED,             ABILITY_NONE,                ABILITY_NONE                 } }, //  999 gimmighoul
    { SPECIES_GHOLDENGO,                 { ABILITY_GOOD_AS_GOLD,        ABILITY_NONE,                ABILITY_NONE                 } }, // 1000 gholdengo
    { SPECIES_WO_CHIEN,                  { ABILITY_TABLETS_OF_RUIN,     ABILITY_NONE,                ABILITY_NONE                 } }, // 1001 wo_chien
    { SPECIES_CHIEN_PAO,                 { ABILITY_SWORD_OF_RUIN,       ABILITY_NONE,                ABILITY_NONE                 } }, // 1002 chien_pao
    { SPECIES_TING_LU,                   { ABILITY_VESSEL_OF_RUIN,      ABILITY_NONE,                ABILITY_NONE                 } }, // 1003 ting_lu
    { SPECIES_CHI_YU,                    { ABILITY_BEADS_OF_RUIN,       ABILITY_NONE,                ABILITY_NONE                 } }, // 1004 chi_yu
    { SPECIES_ROARING_MOON,              { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, // 1005 roaring_moon
    { SPECIES_IRON_VALIANT,              { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, // 1006 iron_valiant
    { SPECIES_KORAIDON,                  { ABILITY_ORICHALCUM_PULSE,    ABILITY_NONE,                ABILITY_NONE                 } }, // 1007 koraidon
    { SPECIES_MIRAIDON,                  { ABILITY_HADRON_ENGINE,       ABILITY_NONE,                ABILITY_NONE                 } }, // 1008 miraidon
    { SPECIES_WALKING_WAKE,              { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, // 1009 walking_wake
    { SPECIES_IRON_LEAVES,               { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, // 1010 iron_leaves
    { SPECIES_POLTCHAGEIST,              { ABILITY_HOSPITALITY,         ABILITY_NONE,                ABILITY_HEATPROOF            } }, // 1012 poltchageist
    { SPECIES_SINISTCHA,                 { ABILITY_HOSPITALITY,         ABILITY_NONE,                ABILITY_HEATPROOF            } }, // 1013 sinistcha
    { SPECIES_OKIDOGI,                   { ABILITY_TOXIC_CHAIN,         ABILITY_NONE,                ABILITY_GUARD_DOG            } }, // 1014 okidogi
    { SPECIES_MUNKIDORI,                 { ABILITY_TOXIC_CHAIN,         ABILITY_NONE,                ABILITY_FRISK                } }, // 1015 munkidori
    { SPECIES_FEZANDIPITI,               { ABILITY_TOXIC_CHAIN,         ABILITY_NONE,                ABILITY_TECHNICIAN           } }, // 1016 fezandipiti
    { SPECIES_OGERPON,                   { ABILITY_DEFIANT,             ABILITY_NONE,                ABILITY_NONE                 } }, // 1017 ogerpon
    { SPECIES_GOUGING_FIRE,              { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, // 1020 gouging_fire
    { SPECIES_RAGING_BOLT,               { ABILITY_PROTOSYNTHESIS,      ABILITY_NONE,                ABILITY_NONE                 } }, // 1021 raging_bolt
    { SPECIES_IRON_BOULDER,              { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, // 1022 iron_boulder
    { SPECIES_IRON_CROWN,                { ABILITY_QUARK_DRIVE,         ABILITY_NONE,                ABILITY_NONE                 } }, // 1023 iron_crown
    { SPECIES_TERAPAGOS,                 { ABILITY_TERA_SHIFT,          ABILITY_NONE,                ABILITY_NONE                 } }, // 1024 terapagos
    { SPECIES_PECHARUNT,                 { ABILITY_POISON_PUPPETEER,    ABILITY_NONE,                ABILITY_NONE                 } }, // 1025 pecharunt

    // Kismet fakemon
    { SPECIES_RAELIC,                    { ABILITY_STURDY,              ABILITY_NONE,                ABILITY_NONE                 } }, // 1026 raelic
    { SPECIES_ROMUSHU,                   { ABILITY_STURDY,              ABILITY_NONE,                ABILITY_NONE                 } }, // 1027 romushu
    { SPECIES_FUSANG,                    { ABILITY_EFFECT_SPORE,        ABILITY_NONE,                ABILITY_NONE                 } }, // 1028 fusang
    { SPECIES_LARVICID,                  { ABILITY_BATTLE_ARMOR,        ABILITY_NONE,                ABILITY_NONE                 } }, // 1029 larvicid
    { SPECIES_PENDRAGON,                 { ABILITY_BATTLE_ARMOR,        ABILITY_NONE,                ABILITY_NONE                 } }, // 1030 pendragon
    { SPECIES_KROLUCADA,                 { ABILITY_SHIELD_DUST,         ABILITY_NONE,                ABILITY_NONE                 } }, // 1031 krolucada
    { SPECIES_KROLUCARD,                 { ABILITY_INSOMNIA,            ABILITY_NONE,                ABILITY_NONE                 } }, // 1032 krolucard
    { SPECIES_PURGISLUG,                 { ABILITY_STICKY_HOLD,         ABILITY_NONE,                ABILITY_NONE                 } }, // 1036 purgislug
    { SPECIES_GEKOPON,                   { ABILITY_DAMP,                ABILITY_NONE,                ABILITY_NONE                 } }, // 1038 gekopon
    { SPECIES_ALT_MEGANIUM,              { ABILITY_SOLID_ROCK,          ABILITY_NONE,                ABILITY_NONE                 } }, // 1041 alt_meganium
    { SPECIES_ALT_TYPHLOSION,            { ABILITY_CURSED_BODY,         ABILITY_NONE,                ABILITY_NONE                 } }, // 1042 alt_typhlosion
    { SPECIES_ALT_FERALIGATR,            { ABILITY_TORRENT,             ABILITY_NONE,                ABILITY_NONE                 } }, // 1043 alt_feraligatr
};
