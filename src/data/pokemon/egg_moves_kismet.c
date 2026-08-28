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
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PICHU] = sPichuEggMoveLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewEggMoveLearnset_Kismet,
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
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthEggMoveLearnset_Kismet,
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
#if P_FAMILY_POLIWAG
    [SPECIES_POLIWAG] = sPoliwagEggMoveLearnset_Kismet,
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
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdEggMoveLearnset_Kismet,
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
#if P_FAMILY_SHELLDER
    [SPECIES_SHELLDER] = sShellderEggMoveLearnset_Kismet,
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
    [SPECIES_CHANSEY] = sChanseyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HORSEA
    [SPECIES_HORSEA] = sHorseaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GOLDEEN
    [SPECIES_GOLDEEN] = sGoldeenEggMoveLearnset_Kismet,
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
#endif
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNORLAX
    [SPECIES_SNORLAX] = sSnorlaxEggMoveLearnset_Kismet,
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
#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] = sLedybaEggMoveLearnset_Kismet,
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
    [SPECIES_MARILL] = sMarillEggMoveLearnset_Kismet,
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
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselEggMoveLearnset_Kismet,
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
#if P_FAMILY_LOTAD
    [SPECIES_LOTAD] = sLotadEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotEggMoveLearnset_Kismet,
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
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyEggMoveLearnset_Kismet,
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
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaEggMoveLearnset_Kismet,
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
#if P_FAMILY_BARBOACH
    [SPECIES_BARBOACH] = sBarboachEggMoveLearnset_Kismet,
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
#endif
#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] = sShuppetEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_DUSKULL
    [SPECIES_DUSKULL] = sDuskullEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CHIMECHO
    [SPECIES_CHIMECHO] = sChimechoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] = sClamperlEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] = sLuvdiscEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BRONZOR
    [SPECIES_BRONZOR] = sBronzorEggMoveLearnset_Kismet,
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
#if P_FAMILY_SKORUPI
    [SPECIES_SKORUPI] = sSkorupiEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] = sTynamoEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_AXEW
    [SPECIES_AXEW] = sAxewEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] = sRuffletEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] = sVullabyEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] = sLarvestaEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] = sFletchlingEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_MIMIKYU
    [SPECIES_MIMIKYU_DISGUISED] = sMimikyuDisguisedEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] = sImpidimpEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_WATTREL
    [SPECIES_WATTREL] = sWattrelEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] = sTinkatinkEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] = sBombirdierEggMoveLearnset_Kismet,
#endif
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardEggMoveLearnset_Kismet,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_KROLUCADA] = sKrolucadaEggMoveLearnset_Kismet,
    [SPECIES_LARVICID] = sLarvicidEggMoveLearnset_Kismet,
    [SPECIES_PURGISLUG] = sPurgislugEggMoveLearnset_Kismet,
    [SPECIES_RAELIC] = sRaelicEggMoveLearnset_Kismet,
#endif
};
