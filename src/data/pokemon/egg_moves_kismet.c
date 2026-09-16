#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "egg_moves_kismet.h"

// NUM_SPECIES + 1: NUM_SPECIES == SPECIES_EGG and SanitizeSpeciesId
// returns it unchanged, so a bare NUM_SPECIES sizing lets an egg
// read one element past the end.
const u16 *const gEggMoves_Kismet[NUM_SPECIES + 1] = {
#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR] = sBulbasaurEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] = sCharmanderEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SQUIRTLE
    [SPECIES_SQUIRTLE] = sSquirtleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PIDGEY
    [SPECIES_PIDGEY] = sPidgeyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_RATTATA
    [SPECIES_RATTATA] = sRattataEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_RATTATA
#if P_ALOLAN_FORMS
    [SPECIES_RATTATA_ALOLA] = sRattataAlolaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PICHU] = sPichuEggMoveLearnset_Kismet,
    [SPECIES_PICHU_SPIKY_EARED] = sPichuSpikyEaredEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SANDSHREW
#if P_ALOLAN_FORMS
    [SPECIES_SANDSHREW_ALOLA] = sSandshrewAlolaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_NIDORAN
    [SPECIES_NIDORAN_F] = sNidoranFEggMoveLearnset_Kismet,
    [SPECIES_NIDORAN_M] = sNidoranMEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CLEFAIRY
#if P_GEN_2_CROSS_EVOS
    [SPECIES_CLEFFA] = sCleffaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_VULPIX
    [SPECIES_VULPIX] = sVulpixEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_VULPIX
#if P_ALOLAN_FORMS
    [SPECIES_VULPIX_ALOLA] = sVulpixAlolaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_JIGGLYPUFF
#if P_GEN_2_CROSS_EVOS
    [SPECIES_IGGLYBUFF] = sIgglybuffEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_ZUBAT
    [SPECIES_ZUBAT] = sZubatEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ODDISH
    [SPECIES_ODDISH] = sOddishEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PARAS
    [SPECIES_PARAS] = sParasEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_VENONAT
    [SPECIES_VENONAT] = sVenonatEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DIGLETT
    [SPECIES_DIGLETT] = sDiglettEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DIGLETT
#if P_ALOLAN_FORMS
    [SPECIES_DIGLETT_ALOLA] = sDiglettAlolaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthEggMoveLearnset_Kismet,
    [SPECIES_MEOWTH_GMAX] = sMeowthGmaxEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MEOWTH
#if P_ALOLAN_FORMS
    [SPECIES_MEOWTH_ALOLA] = sMeowthAlolaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PSYDUCK
    [SPECIES_PSYDUCK] = sPsyduckEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MANKEY
    [SPECIES_MANKEY] = sMankeyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GROWLITHE
    [SPECIES_GROWLITHE] = sGrowlitheEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ABRA
    [SPECIES_ABRA] = sAbraEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MACHOP
    [SPECIES_MACHOP] = sMachopEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BELLSPROUT
    [SPECIES_BELLSPROUT] = sBellsproutEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TENTACOOL
    [SPECIES_TENTACOOL] = sTentacoolEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GEODUDE
    [SPECIES_GEODUDE] = sGeodudeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GEODUDE
#if P_ALOLAN_FORMS
    [SPECIES_GEODUDE_ALOLA] = sGeodudeAlolaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FARFETCHD
#if P_GALARIAN_FORMS
    [SPECIES_FARFETCHD_GALAR] = sFarfetchdGalarEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_DODUO
    [SPECIES_DODUO] = sDoduoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SEEL
    [SPECIES_SEEL] = sSeelEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GRIMER
    [SPECIES_GRIMER] = sGrimerEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GRIMER
#if P_ALOLAN_FORMS
    [SPECIES_GRIMER_ALOLA] = sGrimerAlolaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_GASTLY
    [SPECIES_GASTLY] = sGastlyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ONIX
    [SPECIES_ONIX] = sOnixEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DROWZEE
    [SPECIES_DROWZEE] = sDrowzeeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] = sKrabbyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] = sExeggcuteEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CUBONE
    [SPECIES_CUBONE] = sCuboneEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
    [SPECIES_TYROGUE] = sTyrogueEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_LICKITUNG
    [SPECIES_LICKITUNG] = sLickitungEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_KOFFING
    [SPECIES_KOFFING] = sKoffingEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_RHYHORN
    [SPECIES_RHYHORN] = sRhyhornEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHANSEY
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HAPPINY] = sHappinyEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CHANSEY
    [SPECIES_CHANSEY] = sChanseyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanEggMoveLearnset_Kismet,
    [SPECIES_KANGASKHAN_MEGA] = sKangaskhanMegaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MR_MIME
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MIME_JR] = sMimeJrEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MR_MIME
    [SPECIES_MR_MIME] = sMrMimeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SCYTHER
    [SPECIES_SCYTHER] = sScytherEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_JYNX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SMOOCHUM] = sSmoochumEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_ELECTABUZZ
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ELEKID] = sElekidEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_2_CROSS_EVOS
    [SPECIES_MAGBY] = sMagbyEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirEggMoveLearnset_Kismet,
    [SPECIES_PINSIR_MEGA] = sPinsirMegaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeEggMoveLearnset_Kismet,
    [SPECIES_EEVEE_GMAX] = sEeveeGmaxEggMoveLearnset_Kismet,
    [SPECIES_EEVEE_STARTER] = sEeveeStarterEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylEggMoveLearnset_Kismet,
    [SPECIES_AERODACTYL_MEGA] = sAerodactylMegaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNORLAX
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MUNCHLAX] = sMunchlaxEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SNORLAX
    [SPECIES_SNORLAX] = sSnorlaxEggMoveLearnset_Kismet,
    [SPECIES_SNORLAX_GMAX] = sSnorlaxGmaxEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DRATINI
    [SPECIES_DRATINI] = sDratiniEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] = sChikoritaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] = sCyndaquilEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] = sTotodileEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] = sSentretEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] = sHoothootEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] = sSpinarakEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] = sChinchouEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TOGEPI
    [SPECIES_TOGEPI] = sTogepiEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_NATU
    [SPECIES_NATU] = sNatuEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] = sMareepEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MARILL
#if P_GEN_3_CROSS_EVOS
    [SPECIES_AZURILL] = sAzurillEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MARILL
    [SPECIES_MARILL] = sMarillEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SUDOWOODO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BONSLY] = sBonslyEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SUDOWOODO
    [SPECIES_SUDOWOODO] = sSudowoodoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] = sHoppipEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] = sAipomEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] = sSunkernEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_YANMA
    [SPECIES_YANMA] = sYanmaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] = sWooperEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WOOPER
#if P_PALDEAN_FORMS
    [SPECIES_WOOPER_PALDEA] = sWooperPaldeaEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] = sMurkrowEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MISDREAVUS
    [SPECIES_MISDREAVUS] = sMisdreavusEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] = sGirafarigEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PINECO
    [SPECIES_PINECO] = sPinecoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] = sDunsparceEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] = sGligarEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] = sSnubbullEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] = sQwilfishEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_QWILFISH
#if P_HISUIAN_FORMS
    [SPECIES_QWILFISH_HISUI] = sQwilfishHisuiEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNEASEL
#if P_HISUIAN_FORMS
    [SPECIES_SNEASEL_HISUI] = sSneaselHisuiEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] = sTeddiursaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] = sSlugmaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] = sSwinubEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CORSOLA
    [SPECIES_CORSOLA] = sCorsolaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] = sRemoraidEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] = sDelibirdEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MANTINE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MANTYKE] = sMantykeEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MANTINE
    [SPECIES_MANTINE] = sMantineEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] = sSkarmoryEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] = sHoundourEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] = sPhanpyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] = sStantlerEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] = sMiltankEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] = sLarvitarEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TREECKO
    [SPECIES_TREECKO] = sTreeckoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC] = sTorchicEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MUDKIP
    [SPECIES_MUDKIP] = sMudkipEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA] = sPoochyenaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ZIGZAGOON
    [SPECIES_ZIGZAGOON] = sZigzagoonEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ZIGZAGOON
#if P_GALARIAN_FORMS
    [SPECIES_ZIGZAGOON_GALAR] = sZigzagoonGalarEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TAILLOW
    [SPECIES_TAILLOW] = sTaillowEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WINGULL
    [SPECIES_WINGULL] = sWingullEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_RALTS
    [SPECIES_RALTS] = sRaltsEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SURSKIT
    [SPECIES_SURSKIT] = sSurskitEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SHROOMISH
    [SPECIES_SHROOMISH] = sShroomishEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] = sSlakothEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_NINCADA
    [SPECIES_NINCADA] = sNincadaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WHISMUR
    [SPECIES_WHISMUR] = sWhismurEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] = sSableyeEggMoveLearnset_Kismet,
    [SPECIES_SABLEYE_MEGA] = sSableyeMegaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MAWILE
    [SPECIES_MAWILE] = sMawileEggMoveLearnset_Kismet,
    [SPECIES_MAWILE_MEGA] = sMawileMegaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ARON
    [SPECIES_ARON] = sAronEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] = sMedititeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ELECTRIKE
    [SPECIES_ELECTRIKE] = sElectrikeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PLUSLE
    [SPECIES_PLUSLE] = sPlusleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MINUN
    [SPECIES_MINUN] = sMinunEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_VOLBEAT_ILLUMISE
    [SPECIES_ILLUMISE] = sIllumiseEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ROSELIA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BUDEW] = sBudewEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_ROSELIA
    [SPECIES_ROSELIA] = sRoseliaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GULPIN
    [SPECIES_GULPIN] = sGulpinEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] = sWailmerEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_NUMEL
    [SPECIES_NUMEL] = sNumelEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] = sTorkoalEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] = sSpoinkEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CACNEA
    [SPECIES_CACNEA] = sCacneaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SWABLU
    [SPECIES_SWABLU] = sSwabluEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ZANGOOSE
    [SPECIES_ZANGOOSE] = sZangooseEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SEVIPER
    [SPECIES_SEVIPER] = sSeviperEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] = sCorphishEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] = sLileepEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ANORITH
    [SPECIES_ANORITH] = sAnorithEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FEEBAS
    [SPECIES_FEEBAS] = sFeebasEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CASTFORM
    [SPECIES_CASTFORM_NORMAL] = sCastformNormalEggMoveLearnset_Kismet,
    [SPECIES_CASTFORM_RAINY] = sCastformRainyEggMoveLearnset_Kismet,
    [SPECIES_CASTFORM_SNOWY] = sCastformSnowyEggMoveLearnset_Kismet,
    [SPECIES_CASTFORM_SUNNY] = sCastformSunnyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_KECLEON
    [SPECIES_KECLEON] = sKecleonEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHIMECHO
    [SPECIES_CHIMECHO] = sChimechoEggMoveLearnset_Kismet,
    [SPECIES_CHIMECHO_MEGA] = sChimechoMegaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolEggMoveLearnset_Kismet,
    [SPECIES_ABSOL_MEGA] = sAbsolMegaEggMoveLearnset_Kismet,
    [SPECIES_ABSOL_MEGA_Z] = sAbsolMegaZEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] = sLuvdiscEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TURTWIG
    [SPECIES_TURTWIG] = sTurtwigEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHIMCHAR
    [SPECIES_CHIMCHAR] = sChimcharEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PIPLUP
    [SPECIES_PIPLUP] = sPiplupEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BIDOOF
    [SPECIES_BIDOOF] = sBidoofEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SHIELDON
    [SPECIES_SHIELDON] = sShieldonEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PACHIRISU
    [SPECIES_PACHIRISU] = sPachirisuEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BUIZEL
    [SPECIES_BUIZEL] = sBuizelEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHERUBI
    [SPECIES_CHERUBI] = sCherubiEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SHELLOS
    [SPECIES_SHELLOS_EAST] = sShellosEastEggMoveLearnset_Kismet,
    [SPECIES_SHELLOS_WEST] = sShellosWestEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DRIFLOON
    [SPECIES_DRIFLOON] = sDrifloonEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BUNEARY
    [SPECIES_BUNEARY] = sBunearyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GLAMEOW
    [SPECIES_GLAMEOW] = sGlameowEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_STUNKY
    [SPECIES_STUNKY] = sStunkyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHATOT
    [SPECIES_CHATOT] = sChatotEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SPIRITOMB
    [SPECIES_SPIRITOMB] = sSpiritombEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GIBLE
    [SPECIES_GIBLE] = sGibleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_RIOLU
    [SPECIES_RIOLU] = sRioluEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CROAGUNK
    [SPECIES_CROAGUNK] = sCroagunkEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CARNIVINE
    [SPECIES_CARNIVINE] = sCarnivineEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNOVER
    [SPECIES_SNOVER] = sSnoverEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNIVY
    [SPECIES_SNIVY] = sSnivyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TEPIG
    [SPECIES_TEPIG] = sTepigEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_OSHAWOTT
    [SPECIES_OSHAWOTT] = sOshawottEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PATRAT
    [SPECIES_PATRAT] = sPatratEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LILLIPUP
    [SPECIES_LILLIPUP] = sLillipupEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MUNNA
    [SPECIES_MUNNA] = sMunnaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PIDOVE
    [SPECIES_PIDOVE] = sPidoveEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BLITZLE
    [SPECIES_BLITZLE] = sBlitzleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] = sRoggenrolaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WOOBAT
    [SPECIES_WOOBAT] = sWoobatEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DRILBUR
    [SPECIES_DRILBUR] = sDrilburEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_AUDINO
    [SPECIES_AUDINO] = sAudinoEggMoveLearnset_Kismet,
    [SPECIES_AUDINO_MEGA] = sAudinoMegaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TIMBURR
    [SPECIES_TIMBURR] = sTimburrEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TYMPOLE
    [SPECIES_TYMPOLE] = sTympoleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SEWADDLE
    [SPECIES_SEWADDLE] = sSewaddleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_VENIPEDE
    [SPECIES_VENIPEDE] = sVenipedeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_COTTONEE
    [SPECIES_COTTONEE] = sCottoneeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PETILIL
    [SPECIES_PETILIL] = sPetililEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] = sSandileEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DARUMAKA
#if P_GALARIAN_FORMS
    [SPECIES_DARUMAKA_GALAR] = sDarumakaGalarEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MARACTUS
    [SPECIES_MARACTUS] = sMaractusEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DWEBBLE
    [SPECIES_DWEBBLE] = sDwebbleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SCRAGGY
    [SPECIES_SCRAGGY] = sScraggyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SIGILYPH
    [SPECIES_SIGILYPH] = sSigilyphEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_YAMASK
    [SPECIES_YAMASK] = sYamaskEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TIRTOUGA
    [SPECIES_TIRTOUGA] = sTirtougaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ARCHEN
    [SPECIES_ARCHEN] = sArchenEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TRUBBISH
    [SPECIES_TRUBBISH] = sTrubbishEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ZORUA
    [SPECIES_ZORUA] = sZoruaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ZORUA
#if P_HISUIAN_FORMS
    [SPECIES_ZORUA_HISUI] = sZoruaHisuiEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_GOTHITA
    [SPECIES_GOTHITA] = sGothitaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DUCKLETT
    [SPECIES_DUCKLETT] = sDucklettEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DEERLING
    [SPECIES_DEERLING_AUTUMN] = sDeerlingAutumnEggMoveLearnset_Kismet,
    [SPECIES_DEERLING_SPRING] = sDeerlingSpringEggMoveLearnset_Kismet,
    [SPECIES_DEERLING_SUMMER] = sDeerlingSummerEggMoveLearnset_Kismet,
    [SPECIES_DEERLING_WINTER] = sDeerlingWinterEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] = sEmolgaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FOONGUS
    [SPECIES_FOONGUS] = sFoongusEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_JOLTIK
    [SPECIES_JOLTIK] = sJoltikEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FERROSEED
    [SPECIES_FERROSEED] = sFerroseedEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ELGYEM
    [SPECIES_ELGYEM] = sElgyemEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] = sLitwickEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] = sCubchooEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SHELMET
    [SPECIES_SHELMET] = sShelmetEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_STUNFISK
    [SPECIES_STUNFISK] = sStunfiskEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_STUNFISK
#if P_GALARIAN_FORMS
    [SPECIES_STUNFISK_GALAR] = sStunfiskGalarEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DRUDDIGON
    [SPECIES_DRUDDIGON] = sDruddigonEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PAWNIARD
    [SPECIES_PAWNIARD] = sPawniardEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BOUFFALANT
    [SPECIES_BOUFFALANT] = sBouffalantEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HEATMOR
    [SPECIES_HEATMOR] = sHeatmorEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DURANT
    [SPECIES_DURANT] = sDurantEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DEINO
    [SPECIES_DEINO] = sDeinoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHESPIN
    [SPECIES_CHESPIN] = sChespinEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FROAKIE
    [SPECIES_FROAKIE] = sFroakieEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] = sFletchlingEggMoveLearnset_Kismet,
    [SPECIES_TALONFLAME] = sTalonflameEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LITLEO
    [SPECIES_LITLEO] = sLitleoEggMoveLearnset_Kismet,
    [SPECIES_PYROAR_MEGA] = sPyroarMegaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] = sPanchamEggMoveLearnset_Kismet,
    [SPECIES_PANGORO] = sPangoroEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HONEDGE
    [SPECIES_HONEDGE] = sHonedgeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SPRITZEE
    [SPECIES_SPRITZEE] = sSpritzeeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SWIRLIX
    [SPECIES_SWIRLIX] = sSwirlixEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_INKAY
    [SPECIES_INKAY] = sInkayEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BINACLE
    [SPECIES_BINACLE] = sBinacleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SKRELP
    [SPECIES_SKRELP] = sSkrelpEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CLAUNCHER
    [SPECIES_CLAUNCHER] = sClauncherEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HAWLUCHA
    [SPECIES_HAWLUCHA] = sHawluchaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DEDENNE
    [SPECIES_DEDENNE] = sDedenneEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_KLEFKI
    [SPECIES_KLEFKI] = sKlefkiEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PHANTUMP
    [SPECIES_PHANTUMP] = sPhantumpEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PUMPKABOO
    [SPECIES_PUMPKABOO_AVERAGE] = sPumpkabooAverageEggMoveLearnset_Kismet,
    [SPECIES_PUMPKABOO_LARGE] = sPumpkabooLargeEggMoveLearnset_Kismet,
    [SPECIES_PUMPKABOO_SMALL] = sPumpkabooSmallEggMoveLearnset_Kismet,
    [SPECIES_PUMPKABOO_SUPER] = sPumpkabooSuperEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_NOIBAT
    [SPECIES_NOIBAT] = sNoibatEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ROWLET
    [SPECIES_ROWLET] = sRowletEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LITTEN
    [SPECIES_LITTEN] = sLittenEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_POPPLIO
    [SPECIES_POPPLIO] = sPopplioEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_YUNGOOS
    [SPECIES_YUNGOOS] = sYungoosEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GRUBBIN
    [SPECIES_GRUBBIN] = sGrubbinEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CRABRAWLER
    [SPECIES_CRABRAWLER] = sCrabrawlerEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ORICORIO
    [SPECIES_ORICORIO_BAILE] = sOricorioBaileEggMoveLearnset_Kismet,
    [SPECIES_ORICORIO_PAU] = sOricorioPauEggMoveLearnset_Kismet,
    [SPECIES_ORICORIO_POM_POM] = sOricorioPomPomEggMoveLearnset_Kismet,
    [SPECIES_ORICORIO_SENSU] = sOricorioSensuEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CUTIEFLY
    [SPECIES_CUTIEFLY] = sCutieflyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ROCKRUFF
    [SPECIES_ROCKRUFF] = sRockruffEggMoveLearnset_Kismet,
    [SPECIES_ROCKRUFF_OWN_TEMPO] = sRockruffOwnTempoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MUDBRAY
    [SPECIES_MUDBRAY] = sMudbrayEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DEWPIDER
    [SPECIES_DEWPIDER] = sDewpiderEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_STUFFUL
    [SPECIES_STUFFUL] = sStuffulEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BOUNSWEET
    [SPECIES_BOUNSWEET] = sBounsweetEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_COMFEY
    [SPECIES_COMFEY] = sComfeyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PASSIMIAN
    [SPECIES_PASSIMIAN] = sPassimianEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WIMPOD
    [SPECIES_WIMPOD] = sWimpodEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PYUKUMUKU
    [SPECIES_PYUKUMUKU] = sPyukumukuEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TURTONATOR
    [SPECIES_TURTONATOR] = sTurtonatorEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GROOKEY
    [SPECIES_GROOKEY] = sGrookeyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SCORBUNNY
    [SPECIES_SCORBUNNY] = sScorbunnyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SOBBLE
    [SPECIES_SOBBLE] = sSobbleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SKWOVET
    [SPECIES_SKWOVET] = sSkwovetEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ROOKIDEE
    [SPECIES_ROOKIDEE] = sRookideeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BLIPBUG
    [SPECIES_BLIPBUG] = sBlipbugEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_NICKIT
    [SPECIES_NICKIT] = sNickitEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GOSSIFLEUR
    [SPECIES_GOSSIFLEUR] = sGossifleurEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHEWTLE
    [SPECIES_CHEWTLE] = sChewtleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_APPLIN
    [SPECIES_APPLIN] = sApplinEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SILICOBRA
    [SPECIES_SILICOBRA] = sSilicobraEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CRAMORANT
    [SPECIES_CRAMORANT] = sCramorantEggMoveLearnset_Kismet,
    [SPECIES_CRAMORANT_GORGING] = sCramorantGorgingEggMoveLearnset_Kismet,
    [SPECIES_CRAMORANT_GULPING] = sCramorantGulpingEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ARROKUDA
    [SPECIES_ARROKUDA] = sArrokudaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TOXEL
    [SPECIES_TOXEL] = sToxelEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CLOBBOPUS
    [SPECIES_CLOBBOPUS] = sClobbopusEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HATENNA
    [SPECIES_HATENNA] = sHatennaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MILCERY
    [SPECIES_MILCERY] = sMilceryEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PINCURCHIN
    [SPECIES_PINCURCHIN] = sPincurchinEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_EISCUE
    [SPECIES_EISCUE_ICE] = sEiscueIceEggMoveLearnset_Kismet,
    [SPECIES_EISCUE_NOICE] = sEiscueNoiceEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_INDEEDEE
    [SPECIES_INDEEDEE_F] = sIndeedeeFEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MORPEKO
    [SPECIES_MORPEKO_FULL_BELLY] = sMorpekoFullBellyEggMoveLearnset_Kismet,
    [SPECIES_MORPEKO_HANGRY] = sMorpekoHangryEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DREEPY
    [SPECIES_DREEPY] = sDreepyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SPRIGATITO
    [SPECIES_SPRIGATITO] = sSprigatitoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_QUAXLY
    [SPECIES_QUAXLY] = sQuaxlyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LECHONK
    [SPECIES_LECHONK] = sLechonkEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TAROUNTULA
    [SPECIES_TAROUNTULA] = sTarountulaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_NYMBLE
    [SPECIES_NYMBLE] = sNymbleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TANDEMAUS
    [SPECIES_TANDEMAUS] = sTandemausEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SQUAWKABILLY
    [SPECIES_SQUAWKABILLY_BLUE] = sSquawkabillyBlueEggMoveLearnset_Kismet,
    [SPECIES_SQUAWKABILLY_GREEN] = sSquawkabillyGreenEggMoveLearnset_Kismet,
    [SPECIES_SQUAWKABILLY_WHITE] = sSquawkabillyWhiteEggMoveLearnset_Kismet,
    [SPECIES_SQUAWKABILLY_YELLOW] = sSquawkabillyYellowEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TADBULB
    [SPECIES_TADBULB] = sTadbulbEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MASCHIFF
    [SPECIES_MASCHIFF] = sMaschiffEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SHROODLE
    [SPECIES_SHROODLE] = sShroodleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TOEDSCOOL
    [SPECIES_TOEDSCOOL] = sToedscoolEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CAPSAKID
    [SPECIES_CAPSAKID] = sCapsakidEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FLITTLE
    [SPECIES_FLITTLE] = sFlittleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] = sTinkatinkEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WIGLETT
    [SPECIES_WIGLETT] = sWiglettEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] = sBombirdierEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_VAROOM
    [SPECIES_VAROOM] = sVaroomEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FLAMIGO
    [SPECIES_FLAMIGO] = sFlamigoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CETODDLE
    [SPECIES_CETODDLE] = sCetoddleEggMoveLearnset_Kismet,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_KROLUCADA] = sKrolucadaEggMoveLearnset_Kismet,
    [SPECIES_LARVICID] = sLarvicidEggMoveLearnset_Kismet,
    [SPECIES_PURGISLUG] = sPurgislugEggMoveLearnset_Kismet,
    [SPECIES_RAELIC] = sRaelicEggMoveLearnset_Kismet,
#endif
};
