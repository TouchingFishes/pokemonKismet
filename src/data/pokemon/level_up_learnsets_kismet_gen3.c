#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "level_up_learnsets/kismet_gen3.h"

// NULL for every species the fork does not override, which
// GetSpeciesLevelUpLearnset reads as "fall through to the baseline".
const struct LevelUpMove *const gLevelUpLearnsets_KismetGen3[NUM_SPECIES] = {
#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] = sCharmanderLevelUpLearnset_KismetGen3,
    [SPECIES_CHARMELEON] = sCharmeleonLevelUpLearnset_KismetGen3,
    [SPECIES_CHARIZARD] = sCharizardLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PIKACHU
    [SPECIES_RAICHU] = sRaichuLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ODDISH
    [SPECIES_VILEPLUME] = sVileplumeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthLevelUpLearnset_KismetGen3,
    [SPECIES_PERSIAN] = sPersianLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PSYDUCK
    [SPECIES_PSYDUCK] = sPsyduckLevelUpLearnset_KismetGen3,
    [SPECIES_GOLDUCK] = sGolduckLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MANKEY
    [SPECIES_PRIMEAPE] = sPrimeapeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BELLSPROUT
    [SPECIES_VICTREEBEL] = sVictreebelLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeLevelUpLearnset_KismetGen3,
    [SPECIES_SLOWBRO] = sSlowbroLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SLOWPOKE
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SLOWKING] = sSlowkingLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MAGNEMITE
    [SPECIES_MAGNEMITE] = sMagnemiteLevelUpLearnset_KismetGen3,
    [SPECIES_MAGNETON] = sMagnetonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MAGNEMITE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGNEZONE] = sMagnezoneLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] = sKrabbyLevelUpLearnset_KismetGen3,
    [SPECIES_KINGLER] = sKinglerLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] = sExeggcuteLevelUpLearnset_KismetGen3,
    [SPECIES_EXEGGUTOR] = sExeggutorLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HITMONS
    [SPECIES_HITMONLEE] = sHitmonleeLevelUpLearnset_KismetGen3,
    [SPECIES_HITMONCHAN] = sHitmonchanLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
    [SPECIES_HITMONTOP] = sHitmontopLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_LICKITUNG
    [SPECIES_LICKITUNG] = sLickitungLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TANGELA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_TANGROWTH] = sTangrowthLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_ELECTABUZZ
#if P_GEN_4_CROSS_EVOS
    [SPECIES_ELECTIVIRE] = sElectivireLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGMORTAR] = sMagmortarLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_EEVEE
#if P_GEN_2_CROSS_EVOS
    [SPECIES_UMBREON] = sUmbreonLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_EEVEE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_LEAFEON] = sLeafeonLevelUpLearnset_KismetGen3,
    [SPECIES_GLACEON] = sGlaceonLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PORYGON
    [SPECIES_PORYGON] = sPorygonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PORYGON
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PORYGON2] = sPorygon2LevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PORYGON
#if P_GEN_2_CROSS_EVOS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_PORYGON_Z] = sPorygonZLevelUpLearnset_KismetGen3,
#endif
#endif
#endif
#if P_FAMILY_SUDOWOODO
    [SPECIES_SUDOWOODO] = sSudowoodoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] = sAipomLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_YANMA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_YANMEGA] = sYanmegaLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] = sMurkrowLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MURKROW
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HONCHKROW] = sHonchkrowLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MISDREAVUS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MISMAGIUS] = sMismagiusLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_UNOWN
    [SPECIES_UNOWN_B] = sSpecies252LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_C] = sSpecies253LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_D] = sSpecies254LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_E] = sSpecies255LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_F] = sSpecies256LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_G] = sSpecies257LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_H] = sSpecies258LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_I] = sSpecies259LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_J] = sSpecies260LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_K] = sSpecies261LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_L] = sSpecies262LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_M] = sSpecies263LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_N] = sSpecies264LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_O] = sSpecies265LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_P] = sSpecies266LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_Q] = sSpecies267LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_R] = sSpecies268LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_S] = sSpecies269LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_T] = sSpecies270LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_U] = sSpecies271LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_V] = sSpecies272LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_W] = sSpecies273LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_X] = sSpecies274LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_Y] = sSpecies275LevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_Z] = sSpecies276LevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] = sGirafarigLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] = sDunsparceLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] = sGligarLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GLIGAR
#if P_GEN_4_CROSS_EVOS
    [SPECIES_GLISCOR] = sGliscorLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] = sQwilfishLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SNEASEL
#if P_GEN_4_CROSS_EVOS
    [SPECIES_WEAVILE] = sWeavileLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] = sTeddiursaLevelUpLearnset_KismetGen3,
    [SPECIES_URSARING] = sUrsaringLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TEDDIURSA
#if P_GEN_8_CROSS_EVOS
    [SPECIES_URSALUNA] = sUrsalunaLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] = sSlugmaLevelUpLearnset_KismetGen3,
    [SPECIES_MAGCARGO] = sMagcargoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SWINUB
    [SPECIES_PILOSWINE] = sPiloswineLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] = sHoundourLevelUpLearnset_KismetGen3,
    [SPECIES_HOUNDOOM] = sHoundoomLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] = sStantlerLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_STANTLER
#if P_GEN_8_CROSS_EVOS
    [SPECIES_WYRDEER] = sWyrdeerLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SEEDOT
    [SPECIES_NUZLEAF] = sNuzleafLevelUpLearnset_KismetGen3,
    [SPECIES_SHIFTRY] = sShiftryLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RALTS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_GALLADE] = sGalladeLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] = sSlakothLevelUpLearnset_KismetGen3,
    [SPECIES_SLAKING] = sSlakingLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] = sSableyeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MAWILE
    [SPECIES_MAWILE] = sMawileLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] = sMedititeLevelUpLearnset_KismetGen3,
    [SPECIES_MEDICHAM] = sMedichamLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ROSELIA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_ROSERADE] = sRoseradeLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaLevelUpLearnset_KismetGen3,
    [SPECIES_SHARPEDO] = sSharpedoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] = sSpoinkLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TRAPINCH
    [SPECIES_TRAPINCH] = sTrapinchLevelUpLearnset_KismetGen3,
    [SPECIES_VIBRAVA] = sVibravaLevelUpLearnset_KismetGen3,
    [SPECIES_FLYGON] = sFlygonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CACNEA
    [SPECIES_CACNEA] = sCacneaLevelUpLearnset_KismetGen3,
    [SPECIES_CACTURNE] = sCacturneLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] = sCorphishLevelUpLearnset_KismetGen3,
    [SPECIES_CRAWDAUNT] = sCrawdauntLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] = sLileepLevelUpLearnset_KismetGen3,
    [SPECIES_CRADILY] = sCradilyLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] = sShuppetLevelUpLearnset_KismetGen3,
    [SPECIES_BANETTE] = sBanetteLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SNORUNT
#if P_GEN_4_CROSS_EVOS
    [SPECIES_FROSLASS] = sFroslassLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] = sClamperlLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGISTEEL
    [SPECIES_REGISTEEL] = sRegisteelLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_JIRACHI
    [SPECIES_JIRACHI] = sJirachiLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DEOXYS
    [SPECIES_DEOXYS_NORMAL] = sDeoxysLevelUpLearnset_KismetGen3,
    [SPECIES_DEOXYS_DEFENSE] = sDeoxysDLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TURTWIG
    [SPECIES_TURTWIG] = sTurtwigLevelUpLearnset_KismetGen3,
    [SPECIES_GROTLE] = sGrotleLevelUpLearnset_KismetGen3,
    [SPECIES_TORTERRA] = sTorterraLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CHIMCHAR
    [SPECIES_CHIMCHAR] = sChimcharLevelUpLearnset_KismetGen3,
    [SPECIES_MONFERNO] = sMonfernoLevelUpLearnset_KismetGen3,
    [SPECIES_INFERNAPE] = sInfernapeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PIPLUP
    [SPECIES_PIPLUP] = sPiplupLevelUpLearnset_KismetGen3,
    [SPECIES_PRINPLUP] = sPrinplupLevelUpLearnset_KismetGen3,
    [SPECIES_EMPOLEON] = sEmpoleonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BRONZOR
    [SPECIES_BRONZOR] = sBronzorLevelUpLearnset_KismetGen3,
    [SPECIES_BRONZONG] = sBronzongLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SPIRITOMB
    [SPECIES_SPIRITOMB] = sSpiritombLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GIBLE
    [SPECIES_GIBLE] = sGibleLevelUpLearnset_KismetGen3,
    [SPECIES_GABITE] = sGabiteLevelUpLearnset_KismetGen3,
    [SPECIES_GARCHOMP] = sGarchompLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RIOLU
    [SPECIES_RIOLU] = sRioluLevelUpLearnset_KismetGen3,
    [SPECIES_LUCARIO] = sLucarioLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SKORUPI
    [SPECIES_SKORUPI] = sSkorupiLevelUpLearnset_KismetGen3,
    [SPECIES_DRAPION] = sDrapionLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_FINNEON
    [SPECIES_FINNEON] = sFinneonLevelUpLearnset_KismetGen3,
    [SPECIES_LUMINEON] = sLumineonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SNOVER
    [SPECIES_SNOVER] = sSnoverLevelUpLearnset_KismetGen3,
    [SPECIES_ABOMASNOW] = sAbomasnowLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGIGIGAS
    [SPECIES_REGIGIGAS] = sRegigigasLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ARCEUS
    [SPECIES_ARCEUS_NORMAL] = sArceusLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] = sRoggenrolaLevelUpLearnset_KismetGen3,
    [SPECIES_BOLDORE] = sBoldoreLevelUpLearnset_KismetGen3,
    [SPECIES_GIGALITH] = sGigalithLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] = sSandileLevelUpLearnset_KismetGen3,
    [SPECIES_KROKOROK] = sKrokorokLevelUpLearnset_KismetGen3,
    [SPECIES_KROOKODILE] = sKrookodileLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DARUMAKA
    [SPECIES_DARUMAKA] = sDarumakaLevelUpLearnset_KismetGen3,
    [SPECIES_DARMANITAN_STANDARD] = sDarmanitanLevelUpLearnset_KismetGen3,
    [SPECIES_DARMANITAN_ZEN] = sDarmanitanTranceLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteLevelUpLearnset_KismetGen3,
    [SPECIES_VANILLISH] = sVanillishLevelUpLearnset_KismetGen3,
    [SPECIES_VANILLUXE] = sVanilluxeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] = sEmolgaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_KLINK
    [SPECIES_KLINK] = sKlinkLevelUpLearnset_KismetGen3,
    [SPECIES_KLANG] = sKlangLevelUpLearnset_KismetGen3,
    [SPECIES_KLINKLANG] = sKlinklangLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] = sTynamoLevelUpLearnset_KismetGen3,
    [SPECIES_EELEKTRIK] = sEelektrikLevelUpLearnset_KismetGen3,
    [SPECIES_EELEKTROSS] = sEelektrossLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] = sLitwickLevelUpLearnset_KismetGen3,
    [SPECIES_LAMPENT] = sLampentLevelUpLearnset_KismetGen3,
    [SPECIES_CHANDELURE] = sChandelureLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_AXEW
    [SPECIES_AXEW] = sAxewLevelUpLearnset_KismetGen3,
    [SPECIES_FRAXURE] = sFraxureLevelUpLearnset_KismetGen3,
    [SPECIES_HAXORUS] = sHaxorusLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] = sCubchooLevelUpLearnset_KismetGen3,
    [SPECIES_BEARTIC] = sBearticLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooLevelUpLearnset_KismetGen3,
    [SPECIES_MIENSHAO] = sMienshaoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] = sRuffletLevelUpLearnset_KismetGen3,
    [SPECIES_BRAVIARY] = sBraviaryLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] = sVullabyLevelUpLearnset_KismetGen3,
    [SPECIES_MANDIBUZZ] = sMandibuzzLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DEINO
    [SPECIES_DEINO] = sDeinoLevelUpLearnset_KismetGen3,
    [SPECIES_ZWEILOUS] = sZweilousLevelUpLearnset_KismetGen3,
    [SPECIES_HYDREIGON] = sHydreigonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] = sLarvestaLevelUpLearnset_KismetGen3,
    [SPECIES_VOLCARONA] = sVolcaronaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] = sFletchlingLevelUpLearnset_KismetGen3,
    [SPECIES_FLETCHINDER] = sFletchadinLevelUpLearnset_KismetGen3,
    [SPECIES_TALONFLAME] = sTalonflameLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] = sPanchamLevelUpLearnset_KismetGen3,
    [SPECIES_PANGORO] = sPangoroLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisLevelUpLearnset_KismetGen3,
    [SPECIES_LURANTIS] = sLurantisLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MIMIKYU
    [SPECIES_MIMIKYU_DISGUISED] = sMimikyuLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] = sImpidimpLevelUpLearnset_KismetGen3,
    [SPECIES_MORGREM] = sMorgremLevelUpLearnset_KismetGen3,
    [SPECIES_GRIMMSNARL] = sGrimmsnarlLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGIELEKI
    [SPECIES_REGIELEKI] = sRegielekiLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGIDRAGO
    [SPECIES_REGIDRAGO] = sRegidragoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_WATTREL
    [SPECIES_WATTREL] = sVoltrelLevelUpLearnset_KismetGen3,
    [SPECIES_KILOWATTREL] = sVoltreanLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_FLITTLE
    [SPECIES_FLITTLE] = sFlittleLevelUpLearnset_KismetGen3,
    [SPECIES_ESPATHRA] = sEspathraLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] = sTinkatinkLevelUpLearnset_KismetGen3,
    [SPECIES_TINKATUFF] = sTinkatuffLevelUpLearnset_KismetGen3,
    [SPECIES_TINKATON] = sTinkatonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] = sBombirdierLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardLevelUpLearnset_KismetGen3,
    [SPECIES_HOUNDSTONE] = sHoundstoneLevelUpLearnset_KismetGen3,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_ALT_FERALIGATR] = sFeraligatrAltLevelUpLearnset_KismetGen3,
    [SPECIES_ALT_MEGANIUM] = sMeganiumAltLevelUpLearnset_KismetGen3,
    [SPECIES_ALT_TYPHLOSION] = sTyphlosionAltLevelUpLearnset_KismetGen3,
    [SPECIES_CORSOREEF] = sCorsoreefLevelUpLearnset_KismetGen3,
    [SPECIES_DECIBELLE] = sDecibelleLevelUpLearnset_KismetGen3,
    [SPECIES_DUNDRAG] = sDundragLevelUpLearnset_KismetGen3,
    [SPECIES_DUNLONG] = sDunlongLevelUpLearnset_KismetGen3,
    [SPECIES_FUSANG] = sFusangLevelUpLearnset_KismetGen3,
    [SPECIES_GEKOPON] = sGekoponLevelUpLearnset_KismetGen3,
    [SPECIES_GEOWATT] = sGeowattLevelUpLearnset_KismetGen3,
    [SPECIES_KROLUCADA] = sKrolucadaLevelUpLearnset_KismetGen3,
    [SPECIES_KROLUCARD] = sKrolucardLevelUpLearnset_KismetGen3,
    [SPECIES_KUJINOUGHT] = sKujinoughtLevelUpLearnset_KismetGen3,
    [SPECIES_LARVICID] = sLarvicidLevelUpLearnset_KismetGen3,
    [SPECIES_MLLOY] = sMlloyLevelUpLearnset_KismetGen3,
    [SPECIES_PENDRAGON] = sPendragonLevelUpLearnset_KismetGen3,
    [SPECIES_PSYCHU] = sPsychuLevelUpLearnset_KismetGen3,
    [SPECIES_PURGISLUG] = sPurgislugLevelUpLearnset_KismetGen3,
    [SPECIES_RAELIC] = sRaelicLevelUpLearnset_KismetGen3,
    [SPECIES_ROMUSHU] = sRomushuLevelUpLearnset_KismetGen3,
#endif
};
