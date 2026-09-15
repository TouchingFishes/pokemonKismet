#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "egg_moves_kismet_gen3.h"

// NUM_SPECIES + 1: NUM_SPECIES == SPECIES_EGG and SanitizeSpeciesId
// returns it unchanged, so a bare NUM_SPECIES sizing lets an egg
// read one element past the end.
const u16 *const gEggMoves_KismetGen3[NUM_SPECIES + 1] = {
#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR] = sBulbasaurEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] = sCharmanderEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SQUIRTLE
    [SPECIES_SQUIRTLE] = sSquirtleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PIDGEY
    [SPECIES_PIDGEY] = sPidgeyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_RATTATA
    [SPECIES_RATTATA] = sRattataEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_RATTATA
#if P_ALOLAN_FORMS
    [SPECIES_RATTATA_ALOLA] = sRattataAlolaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PICHU] = sPichuEggMoveLearnset_KismetGen3,
    [SPECIES_PICHU_SPIKY_EARED] = sPichuSpikyEaredEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SANDSHREW
#if P_ALOLAN_FORMS
    [SPECIES_SANDSHREW_ALOLA] = sSandshrewAlolaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_NIDORAN
    [SPECIES_NIDORAN_F] = sNidoranFEggMoveLearnset_KismetGen3,
    [SPECIES_NIDORAN_M] = sNidoranMEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CLEFAIRY
#if P_GEN_2_CROSS_EVOS
    [SPECIES_CLEFFA] = sCleffaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_VULPIX
    [SPECIES_VULPIX] = sVulpixEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_VULPIX
#if P_ALOLAN_FORMS
    [SPECIES_VULPIX_ALOLA] = sVulpixAlolaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_JIGGLYPUFF
#if P_GEN_2_CROSS_EVOS
    [SPECIES_IGGLYBUFF] = sIgglybuffEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_ZUBAT
    [SPECIES_ZUBAT] = sZubatEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ODDISH
    [SPECIES_ODDISH] = sOddishEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PARAS
    [SPECIES_PARAS] = sParasEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_VENONAT
    [SPECIES_VENONAT] = sVenonatEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DIGLETT
    [SPECIES_DIGLETT] = sDiglettEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DIGLETT
#if P_ALOLAN_FORMS
    [SPECIES_DIGLETT_ALOLA] = sDiglettAlolaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthEggMoveLearnset_KismetGen3,
    [SPECIES_MEOWTH_GMAX] = sMeowthGmaxEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MEOWTH
#if P_ALOLAN_FORMS
    [SPECIES_MEOWTH_ALOLA] = sMeowthAlolaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PSYDUCK
    [SPECIES_PSYDUCK] = sPsyduckEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MANKEY
    [SPECIES_MANKEY] = sMankeyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GROWLITHE
    [SPECIES_GROWLITHE] = sGrowlitheEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ABRA
    [SPECIES_ABRA] = sAbraEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MACHOP
    [SPECIES_MACHOP] = sMachopEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BELLSPROUT
    [SPECIES_BELLSPROUT] = sBellsproutEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TENTACOOL
    [SPECIES_TENTACOOL] = sTentacoolEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GEODUDE
    [SPECIES_GEODUDE] = sGeodudeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GEODUDE
#if P_ALOLAN_FORMS
    [SPECIES_GEODUDE_ALOLA] = sGeodudeAlolaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FARFETCHD
#if P_GALARIAN_FORMS
    [SPECIES_FARFETCHD_GALAR] = sFarfetchdGalarEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_DODUO
    [SPECIES_DODUO] = sDoduoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SEEL
    [SPECIES_SEEL] = sSeelEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GRIMER
    [SPECIES_GRIMER] = sGrimerEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GRIMER
#if P_ALOLAN_FORMS
    [SPECIES_GRIMER_ALOLA] = sGrimerAlolaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_GASTLY
    [SPECIES_GASTLY] = sGastlyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ONIX
    [SPECIES_ONIX] = sOnixEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DROWZEE
    [SPECIES_DROWZEE] = sDrowzeeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] = sKrabbyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] = sExeggcuteEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CUBONE
    [SPECIES_CUBONE] = sCuboneEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
    [SPECIES_TYROGUE] = sTyrogueEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_LICKITUNG
    [SPECIES_LICKITUNG] = sLickitungEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_KOFFING
    [SPECIES_KOFFING] = sKoffingEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_RHYHORN
    [SPECIES_RHYHORN] = sRhyhornEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHANSEY
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HAPPINY] = sHappinyEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_CHANSEY
    [SPECIES_CHANSEY] = sChanseyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanEggMoveLearnset_KismetGen3,
    [SPECIES_KANGASKHAN_MEGA] = sKangaskhanMegaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MR_MIME
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MIME_JR] = sMimeJrEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MR_MIME
    [SPECIES_MR_MIME] = sMrMimeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SCYTHER
    [SPECIES_SCYTHER] = sScytherEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_JYNX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SMOOCHUM] = sSmoochumEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_2_CROSS_EVOS
    [SPECIES_MAGBY] = sMagbyEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirEggMoveLearnset_KismetGen3,
    [SPECIES_PINSIR_MEGA] = sPinsirMegaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeEggMoveLearnset_KismetGen3,
    [SPECIES_EEVEE_GMAX] = sEeveeGmaxEggMoveLearnset_KismetGen3,
    [SPECIES_EEVEE_STARTER] = sEeveeStarterEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylEggMoveLearnset_KismetGen3,
    [SPECIES_AERODACTYL_MEGA] = sAerodactylMegaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNORLAX
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MUNCHLAX] = sMunchlaxEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SNORLAX
    [SPECIES_SNORLAX] = sSnorlaxEggMoveLearnset_KismetGen3,
    [SPECIES_SNORLAX_GMAX] = sSnorlaxGmaxEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DRATINI
    [SPECIES_DRATINI] = sDratiniEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] = sChikoritaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] = sCyndaquilEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] = sTotodileEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] = sSentretEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] = sHoothootEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] = sSpinarakEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] = sChinchouEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TOGEPI
    [SPECIES_TOGEPI] = sTogepiEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_NATU
    [SPECIES_NATU] = sNatuEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] = sMareepEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MARILL
#if P_GEN_3_CROSS_EVOS
    [SPECIES_AZURILL] = sAzurillEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MARILL
    [SPECIES_MARILL] = sMarillEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SUDOWOODO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BONSLY] = sBonslyEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SUDOWOODO
    [SPECIES_SUDOWOODO] = sSudowoodoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] = sHoppipEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] = sAipomEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] = sWooperEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WOOPER
#if P_PALDEAN_FORMS
    [SPECIES_WOOPER_PALDEA] = sWooperPaldeaEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] = sMurkrowEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MISDREAVUS
    [SPECIES_MISDREAVUS] = sMisdreavusEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] = sGirafarigEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PINECO
    [SPECIES_PINECO] = sPinecoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] = sDunsparceEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] = sGligarEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] = sSnubbullEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] = sQwilfishEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_QWILFISH
#if P_HISUIAN_FORMS
    [SPECIES_QWILFISH_HISUI] = sQwilfishHisuiEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNEASEL
#if P_HISUIAN_FORMS
    [SPECIES_SNEASEL_HISUI] = sSneaselHisuiEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] = sTeddiursaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] = sSlugmaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] = sSwinubEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CORSOLA
    [SPECIES_CORSOLA] = sCorsolaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] = sRemoraidEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] = sDelibirdEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MANTINE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MANTYKE] = sMantykeEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MANTINE
    [SPECIES_MANTINE] = sMantineEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] = sSkarmoryEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] = sHoundourEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] = sPhanpyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] = sStantlerEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] = sMiltankEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] = sLarvitarEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TREECKO
    [SPECIES_TREECKO] = sTreeckoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC] = sTorchicEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MUDKIP
    [SPECIES_MUDKIP] = sMudkipEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA] = sPoochyenaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ZIGZAGOON
    [SPECIES_ZIGZAGOON] = sZigzagoonEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ZIGZAGOON
#if P_GALARIAN_FORMS
    [SPECIES_ZIGZAGOON_GALAR] = sZigzagoonGalarEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TAILLOW
    [SPECIES_TAILLOW] = sTaillowEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WINGULL
    [SPECIES_WINGULL] = sWingullEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_RALTS
    [SPECIES_RALTS] = sRaltsEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SURSKIT
    [SPECIES_SURSKIT] = sSurskitEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SHROOMISH
    [SPECIES_SHROOMISH] = sShroomishEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] = sSlakothEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_NINCADA
    [SPECIES_NINCADA] = sNincadaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WHISMUR
    [SPECIES_WHISMUR] = sWhismurEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] = sSableyeEggMoveLearnset_KismetGen3,
    [SPECIES_SABLEYE_MEGA] = sSableyeMegaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MAWILE
    [SPECIES_MAWILE] = sMawileEggMoveLearnset_KismetGen3,
    [SPECIES_MAWILE_MEGA] = sMawileMegaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ARON
    [SPECIES_ARON] = sAronEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] = sMedititeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ELECTRIKE
    [SPECIES_ELECTRIKE] = sElectrikeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PLUSLE
    [SPECIES_PLUSLE] = sPlusleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MINUN
    [SPECIES_MINUN] = sMinunEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_VOLBEAT_ILLUMISE
    [SPECIES_ILLUMISE] = sIllumiseEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GULPIN
    [SPECIES_GULPIN] = sGulpinEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] = sWailmerEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] = sTorkoalEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] = sSpoinkEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CACNEA
    [SPECIES_CACNEA] = sCacneaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SWABLU
    [SPECIES_SWABLU] = sSwabluEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ZANGOOSE
    [SPECIES_ZANGOOSE] = sZangooseEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SEVIPER
    [SPECIES_SEVIPER] = sSeviperEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] = sCorphishEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] = sLileepEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ANORITH
    [SPECIES_ANORITH] = sAnorithEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FEEBAS
    [SPECIES_FEEBAS] = sFeebasEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CASTFORM
    [SPECIES_CASTFORM_NORMAL] = sCastformNormalEggMoveLearnset_KismetGen3,
    [SPECIES_CASTFORM_RAINY] = sCastformRainyEggMoveLearnset_KismetGen3,
    [SPECIES_CASTFORM_SNOWY] = sCastformSnowyEggMoveLearnset_KismetGen3,
    [SPECIES_CASTFORM_SUNNY] = sCastformSunnyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_KECLEON
    [SPECIES_KECLEON] = sKecleonEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHIMECHO
    [SPECIES_CHIMECHO] = sChimechoEggMoveLearnset_KismetGen3,
    [SPECIES_CHIMECHO_MEGA] = sChimechoMegaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolEggMoveLearnset_KismetGen3,
    [SPECIES_ABSOL_MEGA] = sAbsolMegaEggMoveLearnset_KismetGen3,
    [SPECIES_ABSOL_MEGA_Z] = sAbsolMegaZEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] = sLuvdiscEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TURTWIG
    [SPECIES_TURTWIG] = sTurtwigEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHIMCHAR
    [SPECIES_CHIMCHAR] = sChimcharEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PIPLUP
    [SPECIES_PIPLUP] = sPiplupEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BIDOOF
    [SPECIES_BIDOOF] = sBidoofEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SHIELDON
    [SPECIES_SHIELDON] = sShieldonEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PACHIRISU
    [SPECIES_PACHIRISU] = sPachirisuEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BUIZEL
    [SPECIES_BUIZEL] = sBuizelEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHERUBI
    [SPECIES_CHERUBI] = sCherubiEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SHELLOS
    [SPECIES_SHELLOS_EAST] = sShellosEastEggMoveLearnset_KismetGen3,
    [SPECIES_SHELLOS_WEST] = sShellosWestEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DRIFLOON
    [SPECIES_DRIFLOON] = sDrifloonEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BUNEARY
    [SPECIES_BUNEARY] = sBunearyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GLAMEOW
    [SPECIES_GLAMEOW] = sGlameowEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_STUNKY
    [SPECIES_STUNKY] = sStunkyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHATOT
    [SPECIES_CHATOT] = sChatotEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SPIRITOMB
    [SPECIES_SPIRITOMB] = sSpiritombEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GIBLE
    [SPECIES_GIBLE] = sGibleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_RIOLU
    [SPECIES_RIOLU] = sRioluEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CROAGUNK
    [SPECIES_CROAGUNK] = sCroagunkEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CARNIVINE
    [SPECIES_CARNIVINE] = sCarnivineEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNIVY
    [SPECIES_SNIVY] = sSnivyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TEPIG
    [SPECIES_TEPIG] = sTepigEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_OSHAWOTT
    [SPECIES_OSHAWOTT] = sOshawottEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PATRAT
    [SPECIES_PATRAT] = sPatratEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LILLIPUP
    [SPECIES_LILLIPUP] = sLillipupEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MUNNA
    [SPECIES_MUNNA] = sMunnaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PIDOVE
    [SPECIES_PIDOVE] = sPidoveEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BLITZLE
    [SPECIES_BLITZLE] = sBlitzleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] = sRoggenrolaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WOOBAT
    [SPECIES_WOOBAT] = sWoobatEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DRILBUR
    [SPECIES_DRILBUR] = sDrilburEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_AUDINO
    [SPECIES_AUDINO] = sAudinoEggMoveLearnset_KismetGen3,
    [SPECIES_AUDINO_MEGA] = sAudinoMegaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TIMBURR
    [SPECIES_TIMBURR] = sTimburrEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TYMPOLE
    [SPECIES_TYMPOLE] = sTympoleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SEWADDLE
    [SPECIES_SEWADDLE] = sSewaddleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_VENIPEDE
    [SPECIES_VENIPEDE] = sVenipedeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_COTTONEE
    [SPECIES_COTTONEE] = sCottoneeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PETILIL
    [SPECIES_PETILIL] = sPetililEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] = sSandileEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DARUMAKA
#if P_GALARIAN_FORMS
    [SPECIES_DARUMAKA_GALAR] = sDarumakaGalarEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MARACTUS
    [SPECIES_MARACTUS] = sMaractusEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DWEBBLE
    [SPECIES_DWEBBLE] = sDwebbleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SCRAGGY
    [SPECIES_SCRAGGY] = sScraggyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SIGILYPH
    [SPECIES_SIGILYPH] = sSigilyphEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_YAMASK
    [SPECIES_YAMASK] = sYamaskEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TIRTOUGA
    [SPECIES_TIRTOUGA] = sTirtougaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ARCHEN
    [SPECIES_ARCHEN] = sArchenEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TRUBBISH
    [SPECIES_TRUBBISH] = sTrubbishEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ZORUA
    [SPECIES_ZORUA] = sZoruaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ZORUA
#if P_HISUIAN_FORMS
    [SPECIES_ZORUA_HISUI] = sZoruaHisuiEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_GOTHITA
    [SPECIES_GOTHITA] = sGothitaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DUCKLETT
    [SPECIES_DUCKLETT] = sDucklettEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DEERLING
    [SPECIES_DEERLING_AUTUMN] = sDeerlingAutumnEggMoveLearnset_KismetGen3,
    [SPECIES_DEERLING_SPRING] = sDeerlingSpringEggMoveLearnset_KismetGen3,
    [SPECIES_DEERLING_SUMMER] = sDeerlingSummerEggMoveLearnset_KismetGen3,
    [SPECIES_DEERLING_WINTER] = sDeerlingWinterEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] = sEmolgaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FOONGUS
    [SPECIES_FOONGUS] = sFoongusEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_JOLTIK
    [SPECIES_JOLTIK] = sJoltikEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FERROSEED
    [SPECIES_FERROSEED] = sFerroseedEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ELGYEM
    [SPECIES_ELGYEM] = sElgyemEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] = sLitwickEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] = sCubchooEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_STUNFISK
    [SPECIES_STUNFISK] = sStunfiskEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_STUNFISK
#if P_GALARIAN_FORMS
    [SPECIES_STUNFISK_GALAR] = sStunfiskGalarEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DRUDDIGON
    [SPECIES_DRUDDIGON] = sDruddigonEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PAWNIARD
    [SPECIES_PAWNIARD] = sPawniardEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BOUFFALANT
    [SPECIES_BOUFFALANT] = sBouffalantEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HEATMOR
    [SPECIES_HEATMOR] = sHeatmorEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DURANT
    [SPECIES_DURANT] = sDurantEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DEINO
    [SPECIES_DEINO] = sDeinoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHESPIN
    [SPECIES_CHESPIN] = sChespinEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FROAKIE
    [SPECIES_FROAKIE] = sFroakieEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] = sFletchlingEggMoveLearnset_KismetGen3,
    [SPECIES_TALONFLAME] = sTalonflameEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LITLEO
    [SPECIES_LITLEO] = sLitleoEggMoveLearnset_KismetGen3,
    [SPECIES_PYROAR_MEGA] = sPyroarMegaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] = sPanchamEggMoveLearnset_KismetGen3,
    [SPECIES_PANGORO] = sPangoroEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HONEDGE
    [SPECIES_HONEDGE] = sHonedgeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SPRITZEE
    [SPECIES_SPRITZEE] = sSpritzeeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SWIRLIX
    [SPECIES_SWIRLIX] = sSwirlixEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_INKAY
    [SPECIES_INKAY] = sInkayEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BINACLE
    [SPECIES_BINACLE] = sBinacleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SKRELP
    [SPECIES_SKRELP] = sSkrelpEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CLAUNCHER
    [SPECIES_CLAUNCHER] = sClauncherEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HAWLUCHA
    [SPECIES_HAWLUCHA] = sHawluchaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DEDENNE
    [SPECIES_DEDENNE] = sDedenneEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_KLEFKI
    [SPECIES_KLEFKI] = sKlefkiEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PHANTUMP
    [SPECIES_PHANTUMP] = sPhantumpEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PUMPKABOO
    [SPECIES_PUMPKABOO_AVERAGE] = sPumpkabooAverageEggMoveLearnset_KismetGen3,
    [SPECIES_PUMPKABOO_LARGE] = sPumpkabooLargeEggMoveLearnset_KismetGen3,
    [SPECIES_PUMPKABOO_SMALL] = sPumpkabooSmallEggMoveLearnset_KismetGen3,
    [SPECIES_PUMPKABOO_SUPER] = sPumpkabooSuperEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_NOIBAT
    [SPECIES_NOIBAT] = sNoibatEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ROWLET
    [SPECIES_ROWLET] = sRowletEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LITTEN
    [SPECIES_LITTEN] = sLittenEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_POPPLIO
    [SPECIES_POPPLIO] = sPopplioEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_YUNGOOS
    [SPECIES_YUNGOOS] = sYungoosEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GRUBBIN
    [SPECIES_GRUBBIN] = sGrubbinEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CRABRAWLER
    [SPECIES_CRABRAWLER] = sCrabrawlerEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ORICORIO
    [SPECIES_ORICORIO_BAILE] = sOricorioBaileEggMoveLearnset_KismetGen3,
    [SPECIES_ORICORIO_PAU] = sOricorioPauEggMoveLearnset_KismetGen3,
    [SPECIES_ORICORIO_POM_POM] = sOricorioPomPomEggMoveLearnset_KismetGen3,
    [SPECIES_ORICORIO_SENSU] = sOricorioSensuEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CUTIEFLY
    [SPECIES_CUTIEFLY] = sCutieflyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ROCKRUFF
    [SPECIES_ROCKRUFF] = sRockruffEggMoveLearnset_KismetGen3,
    [SPECIES_ROCKRUFF_OWN_TEMPO] = sRockruffOwnTempoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DEWPIDER
    [SPECIES_DEWPIDER] = sDewpiderEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_STUFFUL
    [SPECIES_STUFFUL] = sStuffulEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_COMFEY
    [SPECIES_COMFEY] = sComfeyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PASSIMIAN
    [SPECIES_PASSIMIAN] = sPassimianEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WIMPOD
    [SPECIES_WIMPOD] = sWimpodEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PYUKUMUKU
    [SPECIES_PYUKUMUKU] = sPyukumukuEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TURTONATOR
    [SPECIES_TURTONATOR] = sTurtonatorEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GROOKEY
    [SPECIES_GROOKEY] = sGrookeyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SCORBUNNY
    [SPECIES_SCORBUNNY] = sScorbunnyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SOBBLE
    [SPECIES_SOBBLE] = sSobbleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SKWOVET
    [SPECIES_SKWOVET] = sSkwovetEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ROOKIDEE
    [SPECIES_ROOKIDEE] = sRookideeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BLIPBUG
    [SPECIES_BLIPBUG] = sBlipbugEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_NICKIT
    [SPECIES_NICKIT] = sNickitEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GOSSIFLEUR
    [SPECIES_GOSSIFLEUR] = sGossifleurEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHEWTLE
    [SPECIES_CHEWTLE] = sChewtleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_APPLIN
    [SPECIES_APPLIN] = sApplinEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SILICOBRA
    [SPECIES_SILICOBRA] = sSilicobraEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CRAMORANT
    [SPECIES_CRAMORANT] = sCramorantEggMoveLearnset_KismetGen3,
    [SPECIES_CRAMORANT_GORGING] = sCramorantGorgingEggMoveLearnset_KismetGen3,
    [SPECIES_CRAMORANT_GULPING] = sCramorantGulpingEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TOXEL
    [SPECIES_TOXEL] = sToxelEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CLOBBOPUS
    [SPECIES_CLOBBOPUS] = sClobbopusEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HATENNA
    [SPECIES_HATENNA] = sHatennaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MILCERY
    [SPECIES_MILCERY] = sMilceryEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PINCURCHIN
    [SPECIES_PINCURCHIN] = sPincurchinEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_EISCUE
    [SPECIES_EISCUE_ICE] = sEiscueIceEggMoveLearnset_KismetGen3,
    [SPECIES_EISCUE_NOICE] = sEiscueNoiceEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_INDEEDEE
    [SPECIES_INDEEDEE_F] = sIndeedeeFEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MORPEKO
    [SPECIES_MORPEKO_FULL_BELLY] = sMorpekoFullBellyEggMoveLearnset_KismetGen3,
    [SPECIES_MORPEKO_HANGRY] = sMorpekoHangryEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DREEPY
    [SPECIES_DREEPY] = sDreepyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SPRIGATITO
    [SPECIES_SPRIGATITO] = sSprigatitoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_QUAXLY
    [SPECIES_QUAXLY] = sQuaxlyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LECHONK
    [SPECIES_LECHONK] = sLechonkEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TAROUNTULA
    [SPECIES_TAROUNTULA] = sTarountulaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_NYMBLE
    [SPECIES_NYMBLE] = sNymbleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TANDEMAUS
    [SPECIES_TANDEMAUS] = sTandemausEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SQUAWKABILLY
    [SPECIES_SQUAWKABILLY_BLUE] = sSquawkabillyBlueEggMoveLearnset_KismetGen3,
    [SPECIES_SQUAWKABILLY_GREEN] = sSquawkabillyGreenEggMoveLearnset_KismetGen3,
    [SPECIES_SQUAWKABILLY_WHITE] = sSquawkabillyWhiteEggMoveLearnset_KismetGen3,
    [SPECIES_SQUAWKABILLY_YELLOW] = sSquawkabillyYellowEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TADBULB
    [SPECIES_TADBULB] = sTadbulbEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MASCHIFF
    [SPECIES_MASCHIFF] = sMaschiffEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SHROODLE
    [SPECIES_SHROODLE] = sShroodleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TOEDSCOOL
    [SPECIES_TOEDSCOOL] = sToedscoolEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CAPSAKID
    [SPECIES_CAPSAKID] = sCapsakidEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FLITTLE
    [SPECIES_FLITTLE] = sFlittleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] = sTinkatinkEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WIGLETT
    [SPECIES_WIGLETT] = sWiglettEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] = sBombirdierEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_VAROOM
    [SPECIES_VAROOM] = sVaroomEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FLAMIGO
    [SPECIES_FLAMIGO] = sFlamigoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CETODDLE
    [SPECIES_CETODDLE] = sCetoddleEggMoveLearnset_KismetGen3,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_KROLUCADA] = sKrolucadaEggMoveLearnset_KismetGen3,
    [SPECIES_LARVICID] = sLarvicidEggMoveLearnset_KismetGen3,
    [SPECIES_PURGISLUG] = sPurgislugEggMoveLearnset_KismetGen3,
    [SPECIES_RAELIC] = sRaelicEggMoveLearnset_KismetGen3,
#endif
};
