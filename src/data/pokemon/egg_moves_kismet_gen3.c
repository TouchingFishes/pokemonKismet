#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "egg_moves_kismet_gen3.h"

const u16 *const gEggMoves_KismetGen3[NUM_SPECIES] = {
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
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PICHU] = sPichuEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_POLIWAG
    [SPECIES_POLIWAG] = sPoliwagEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_SHELLDER
    [SPECIES_SHELLDER] = sShellderEggMoveLearnset_KismetGen3,
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
    [SPECIES_CHANSEY] = sChanseyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HORSEA
    [SPECIES_HORSEA] = sHorseaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GOLDEEN
    [SPECIES_GOLDEEN] = sGoldeenEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_ELECTABUZZ
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ELEKID] = sElekidEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_2_CROSS_EVOS
    [SPECIES_MAGBY] = sMagbyEggMoveLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNORLAX
    [SPECIES_SNORLAX] = sSnorlaxEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] = sLedybaEggMoveLearnset_KismetGen3,
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
    [SPECIES_MARILL] = sMarillEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] = sSunkernEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_YANMA
    [SPECIES_YANMA] = sYanmaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] = sWooperEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_LOTAD
    [SPECIES_LOTAD] = sLotadEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] = sWailmerEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_NUMEL
    [SPECIES_NUMEL] = sNumelEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] = sTorkoalEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_BARBOACH
    [SPECIES_BARBOACH] = sBarboachEggMoveLearnset_KismetGen3,
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
#endif
#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] = sShuppetEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DUSKULL
    [SPECIES_DUSKULL] = sDuskullEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CHIMECHO
    [SPECIES_CHIMECHO] = sChimechoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] = sClamperlEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_BRONZOR
    [SPECIES_BRONZOR] = sBronzorEggMoveLearnset_KismetGen3,
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
#if P_FAMILY_SKORUPI
    [SPECIES_SKORUPI] = sSkorupiEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] = sTynamoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_AXEW
    [SPECIES_AXEW] = sAxewEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] = sRuffletEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] = sVullabyEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_DEINO
    [SPECIES_DEINO] = sDeinoEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] = sLarvestaEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] = sFletchlingEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_MIMIKYU
    [SPECIES_MIMIKYU_DISGUISED] = sMimikyuDisguisedEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] = sImpidimpEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_WATTREL
    [SPECIES_WATTREL] = sWattrelEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] = sTinkatinkEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] = sBombirdierEggMoveLearnset_KismetGen3,
#endif
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardEggMoveLearnset_KismetGen3,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_KROLUCADA] = sKrolucadaEggMoveLearnset_KismetGen3,
    [SPECIES_LARVICID] = sLarvicidEggMoveLearnset_KismetGen3,
    [SPECIES_PURGISLUG] = sPurgislugEggMoveLearnset_KismetGen3,
    [SPECIES_RAELIC] = sRaelicEggMoveLearnset_KismetGen3,
#endif
};
