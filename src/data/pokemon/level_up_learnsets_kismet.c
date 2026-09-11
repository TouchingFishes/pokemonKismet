#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "level_up_learnsets/kismet.h"

// NULL for every species the fork does not override, which
// GetSpeciesLevelUpLearnset reads as "fall through to the baseline".
// NUM_SPECIES + 1: NUM_SPECIES == SPECIES_EGG and SanitizeSpeciesId
// returns it unchanged, so a bare NUM_SPECIES sizing lets an egg
// read one element past the end.
const struct LevelUpMove *const gLevelUpLearnsets_Kismet[NUM_SPECIES + 1] = {
#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR] = sBulbasaurLevelUpLearnset_Kismet,
    [SPECIES_IVYSAUR] = sIvysaurLevelUpLearnset_Kismet,
    [SPECIES_VENUSAUR] = sVenusaurLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] = sCharmanderLevelUpLearnset_Kismet,
    [SPECIES_CHARMELEON] = sCharmeleonLevelUpLearnset_Kismet,
    [SPECIES_CHARIZARD] = sCharizardLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SQUIRTLE
    [SPECIES_SQUIRTLE] = sSquirtleLevelUpLearnset_Kismet,
    [SPECIES_WARTORTLE] = sWartortleLevelUpLearnset_Kismet,
    [SPECIES_BLASTOISE] = sBlastoiseLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CATERPIE
    [SPECIES_CATERPIE] = sCaterpieLevelUpLearnset_Kismet,
    [SPECIES_METAPOD] = sMetapodLevelUpLearnset_Kismet,
    [SPECIES_BUTTERFREE] = sButterfreeLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_WEEDLE
    [SPECIES_WEEDLE] = sWeedleLevelUpLearnset_Kismet,
    [SPECIES_KAKUNA] = sKakunaLevelUpLearnset_Kismet,
    [SPECIES_BEEDRILL] = sBeedrillLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PIDGEY
    [SPECIES_PIDGEY] = sPidgeyLevelUpLearnset_Kismet,
    [SPECIES_PIDGEOTTO] = sPidgeottoLevelUpLearnset_Kismet,
    [SPECIES_PIDGEOT] = sPidgeotLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_RATTATA
    [SPECIES_RATTATA] = sRattataLevelUpLearnset_Kismet,
    [SPECIES_RATICATE] = sRaticateLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowLevelUpLearnset_Kismet,
    [SPECIES_FEAROW] = sFearowLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansLevelUpLearnset_Kismet,
    [SPECIES_ARBOK] = sArbokLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PIKACHU
    [SPECIES_PIKACHU] = sPikachuLevelUpLearnset_Kismet,
    [SPECIES_RAICHU] = sRaichuLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewLevelUpLearnset_Kismet,
    [SPECIES_SANDSLASH] = sSandslashLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_NIDORAN
    [SPECIES_NIDORAN_F] = sNidoranFLevelUpLearnset_Kismet,
    [SPECIES_NIDORINA] = sNidorinaLevelUpLearnset_Kismet,
    [SPECIES_NIDOQUEEN] = sNidoqueenLevelUpLearnset_Kismet,
    [SPECIES_NIDORAN_M] = sNidoranMLevelUpLearnset_Kismet,
    [SPECIES_NIDORINO] = sNidorinoLevelUpLearnset_Kismet,
    [SPECIES_NIDOKING] = sNidokingLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CLEFAIRY
    [SPECIES_CLEFAIRY] = sClefairyLevelUpLearnset_Kismet,
    [SPECIES_CLEFABLE] = sClefableLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_VULPIX
    [SPECIES_VULPIX] = sVulpixLevelUpLearnset_Kismet,
    [SPECIES_NINETALES] = sNinetalesLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_JIGGLYPUFF
    [SPECIES_JIGGLYPUFF] = sJigglypuffLevelUpLearnset_Kismet,
    [SPECIES_WIGGLYTUFF] = sWigglytuffLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ZUBAT
    [SPECIES_ZUBAT] = sZubatLevelUpLearnset_Kismet,
    [SPECIES_GOLBAT] = sGolbatLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ODDISH
    [SPECIES_ODDISH] = sOddishLevelUpLearnset_Kismet,
    [SPECIES_GLOOM] = sGloomLevelUpLearnset_Kismet,
    [SPECIES_VILEPLUME] = sVileplumeLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PARAS
    [SPECIES_PARAS] = sParasLevelUpLearnset_Kismet,
    [SPECIES_PARASECT] = sParasectLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_VENONAT
    [SPECIES_VENONAT] = sVenonatLevelUpLearnset_Kismet,
    [SPECIES_VENOMOTH] = sVenomothLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DIGLETT
    [SPECIES_DIGLETT] = sDiglettLevelUpLearnset_Kismet,
    [SPECIES_DUGTRIO] = sDugtrioLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthLevelUpLearnset_Kismet,
    [SPECIES_PERSIAN] = sPersianLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PSYDUCK
    [SPECIES_PSYDUCK] = sPsyduckLevelUpLearnset_Kismet,
    [SPECIES_GOLDUCK] = sGolduckLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MANKEY
    [SPECIES_MANKEY] = sMankeyLevelUpLearnset_Kismet,
    [SPECIES_PRIMEAPE] = sPrimeapeLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GROWLITHE
    [SPECIES_GROWLITHE] = sGrowlitheLevelUpLearnset_Kismet,
    [SPECIES_ARCANINE] = sArcanineLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_POLIWAG
    [SPECIES_POLIWAG] = sPoliwagLevelUpLearnset_Kismet,
    [SPECIES_POLIWHIRL] = sPoliwhirlLevelUpLearnset_Kismet,
    [SPECIES_POLIWRATH] = sPoliwrathLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ABRA
    [SPECIES_ABRA] = sAbraLevelUpLearnset_Kismet,
    [SPECIES_KADABRA] = sKadabraLevelUpLearnset_Kismet,
    [SPECIES_ALAKAZAM] = sAlakazamLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MACHOP
    [SPECIES_MACHOP] = sMachopLevelUpLearnset_Kismet,
    [SPECIES_MACHOKE] = sMachokeLevelUpLearnset_Kismet,
    [SPECIES_MACHAMP] = sMachampLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BELLSPROUT
    [SPECIES_BELLSPROUT] = sBellsproutLevelUpLearnset_Kismet,
    [SPECIES_WEEPINBELL] = sWeepinbellLevelUpLearnset_Kismet,
    [SPECIES_VICTREEBEL] = sVictreebelLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TENTACOOL
    [SPECIES_TENTACOOL] = sTentacoolLevelUpLearnset_Kismet,
    [SPECIES_TENTACRUEL] = sTentacruelLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GEODUDE
    [SPECIES_GEODUDE] = sGeodudeLevelUpLearnset_Kismet,
    [SPECIES_GRAVELER] = sGravelerLevelUpLearnset_Kismet,
    [SPECIES_GOLEM] = sGolemLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaLevelUpLearnset_Kismet,
    [SPECIES_RAPIDASH] = sRapidashLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeLevelUpLearnset_Kismet,
    [SPECIES_SLOWBRO] = sSlowbroLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MAGNEMITE
    [SPECIES_MAGNEMITE] = sMagnemiteLevelUpLearnset_Kismet,
    [SPECIES_MAGNETON] = sMagnetonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DODUO
    [SPECIES_DODUO] = sDoduoLevelUpLearnset_Kismet,
    [SPECIES_DODRIO] = sDodrioLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SEEL
    [SPECIES_SEEL] = sSeelLevelUpLearnset_Kismet,
    [SPECIES_DEWGONG] = sDewgongLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GRIMER
    [SPECIES_GRIMER] = sGrimerLevelUpLearnset_Kismet,
    [SPECIES_MUK] = sMukLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SHELLDER
    [SPECIES_SHELLDER] = sShellderLevelUpLearnset_Kismet,
    [SPECIES_CLOYSTER] = sCloysterLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GASTLY
    [SPECIES_GASTLY] = sGastlyLevelUpLearnset_Kismet,
    [SPECIES_HAUNTER] = sHaunterLevelUpLearnset_Kismet,
    [SPECIES_GENGAR] = sGengarLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ONIX
    [SPECIES_ONIX] = sOnixLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DROWZEE
    [SPECIES_DROWZEE] = sDrowzeeLevelUpLearnset_Kismet,
    [SPECIES_HYPNO] = sHypnoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] = sKrabbyLevelUpLearnset_Kismet,
    [SPECIES_KINGLER] = sKinglerLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_VOLTORB
    [SPECIES_VOLTORB] = sVoltorbLevelUpLearnset_Kismet,
    [SPECIES_ELECTRODE] = sElectrodeLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] = sExeggcuteLevelUpLearnset_Kismet,
    [SPECIES_EXEGGUTOR] = sExeggutorLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CUBONE
    [SPECIES_CUBONE] = sCuboneLevelUpLearnset_Kismet,
    [SPECIES_MAROWAK] = sMarowakLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HITMONS
    [SPECIES_HITMONLEE] = sHitmonleeLevelUpLearnset_Kismet,
    [SPECIES_HITMONCHAN] = sHitmonchanLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LICKITUNG
    [SPECIES_LICKITUNG] = sLickitungLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_KOFFING
    [SPECIES_KOFFING] = sKoffingLevelUpLearnset_Kismet,
    [SPECIES_WEEZING] = sWeezingLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_RHYHORN
    [SPECIES_RHYHORN] = sRhyhornLevelUpLearnset_Kismet,
    [SPECIES_RHYDON] = sRhydonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CHANSEY
    [SPECIES_CHANSEY] = sChanseyLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HORSEA
    [SPECIES_HORSEA] = sHorseaLevelUpLearnset_Kismet,
    [SPECIES_SEADRA] = sSeadraLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GOLDEEN
    [SPECIES_GOLDEEN] = sGoldeenLevelUpLearnset_Kismet,
    [SPECIES_SEAKING] = sSeakingLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_STARYU
    [SPECIES_STARYU] = sStaryuLevelUpLearnset_Kismet,
    [SPECIES_STARMIE] = sStarmieLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MR_MIME
    [SPECIES_MR_MIME] = sMrMimeLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SCYTHER
    [SPECIES_SCYTHER] = sScytherLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_JYNX
    [SPECIES_JYNX] = sJynxLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ELECTABUZZ
    [SPECIES_ELECTABUZZ] = sElectabuzzLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MAGMAR
    [SPECIES_MAGMAR] = sMagmarLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TAUROS
    [SPECIES_TAUROS] = sTaurosLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MAGIKARP
    [SPECIES_MAGIKARP] = sMagikarpLevelUpLearnset_Kismet,
    [SPECIES_GYARADOS] = sGyaradosLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DITTO
    [SPECIES_DITTO] = sDittoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeLevelUpLearnset_Kismet,
    [SPECIES_VAPOREON] = sVaporeonLevelUpLearnset_Kismet,
    [SPECIES_JOLTEON] = sJolteonLevelUpLearnset_Kismet,
    [SPECIES_FLAREON] = sFlareonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PORYGON
    [SPECIES_PORYGON] = sPorygonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteLevelUpLearnset_Kismet,
    [SPECIES_OMASTAR] = sOmastarLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoLevelUpLearnset_Kismet,
    [SPECIES_KABUTOPS] = sKabutopsLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SNORLAX
    [SPECIES_SNORLAX] = sSnorlaxLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ARTICUNO
    [SPECIES_ARTICUNO] = sArticunoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ZAPDOS
    [SPECIES_ZAPDOS] = sZapdosLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MOLTRES
    [SPECIES_MOLTRES] = sMoltresLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DRATINI
    [SPECIES_DRATINI] = sDratiniLevelUpLearnset_Kismet,
    [SPECIES_DRAGONAIR] = sDragonairLevelUpLearnset_Kismet,
    [SPECIES_DRAGONITE] = sDragoniteLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MEWTWO
    [SPECIES_MEWTWO] = sMewtwoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MEW
    [SPECIES_MEW] = sMewLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] = sChikoritaLevelUpLearnset_Kismet,
    [SPECIES_BAYLEEF] = sBayleefLevelUpLearnset_Kismet,
    [SPECIES_MEGANIUM] = sMeganiumLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] = sCyndaquilLevelUpLearnset_Kismet,
    [SPECIES_QUILAVA] = sQuilavaLevelUpLearnset_Kismet,
    [SPECIES_TYPHLOSION] = sTyphlosionLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] = sTotodileLevelUpLearnset_Kismet,
    [SPECIES_CROCONAW] = sCroconawLevelUpLearnset_Kismet,
    [SPECIES_FERALIGATR] = sFeraligatrLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] = sSentretLevelUpLearnset_Kismet,
    [SPECIES_FURRET] = sFurretLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] = sHoothootLevelUpLearnset_Kismet,
    [SPECIES_NOCTOWL] = sNoctowlLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] = sLedybaLevelUpLearnset_Kismet,
    [SPECIES_LEDIAN] = sLedianLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] = sSpinarakLevelUpLearnset_Kismet,
    [SPECIES_ARIADOS] = sAriadosLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ZUBAT
#if P_GEN_2_CROSS_EVOS
    [SPECIES_CROBAT] = sCrobatLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] = sChinchouLevelUpLearnset_Kismet,
    [SPECIES_LANTURN] = sLanturnLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PICHU] = sPichuLevelUpLearnset_Kismet,
    [SPECIES_PICHU_SPIKY_EARED] = sPichuLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CLEFAIRY
#if P_GEN_2_CROSS_EVOS
    [SPECIES_CLEFFA] = sCleffaLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_JIGGLYPUFF
#if P_GEN_2_CROSS_EVOS
    [SPECIES_IGGLYBUFF] = sIgglybuffLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_TOGEPI
    [SPECIES_TOGEPI] = sTogepiLevelUpLearnset_Kismet,
    [SPECIES_TOGETIC] = sTogeticLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_NATU
    [SPECIES_NATU] = sNatuLevelUpLearnset_Kismet,
    [SPECIES_XATU] = sXatuLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] = sMareepLevelUpLearnset_Kismet,
    [SPECIES_FLAAFFY] = sFlaaffyLevelUpLearnset_Kismet,
    [SPECIES_AMPHAROS] = sAmpharosLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ODDISH
#if P_GEN_2_CROSS_EVOS
    [SPECIES_BELLOSSOM] = sBellossomLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MARILL
    [SPECIES_MARILL] = sMarillLevelUpLearnset_Kismet,
    [SPECIES_AZUMARILL] = sAzumarillLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SUDOWOODO
    [SPECIES_SUDOWOODO] = sSudowoodoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_POLIWAG
#if P_GEN_2_CROSS_EVOS
    [SPECIES_POLITOED] = sPolitoedLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] = sHoppipLevelUpLearnset_Kismet,
    [SPECIES_SKIPLOOM] = sSkiploomLevelUpLearnset_Kismet,
    [SPECIES_JUMPLUFF] = sJumpluffLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] = sAipomLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] = sSunkernLevelUpLearnset_Kismet,
    [SPECIES_SUNFLORA] = sSunfloraLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_YANMA
    [SPECIES_YANMA] = sYanmaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] = sWooperLevelUpLearnset_Kismet,
    [SPECIES_QUAGSIRE] = sQuagsireLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_EEVEE
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ESPEON] = sEspeonLevelUpLearnset_Kismet,
    [SPECIES_UMBREON] = sUmbreonLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] = sMurkrowLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SLOWPOKE
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SLOWKING] = sSlowkingLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MISDREAVUS
    [SPECIES_MISDREAVUS] = sMisdreavusLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_UNOWN
    [SPECIES_UNOWN] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_B] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_C] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_D] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_E] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_F] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_G] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_H] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_I] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_J] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_K] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_L] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_M] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_N] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_O] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_P] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_Q] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_R] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_S] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_T] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_U] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_V] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_W] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_X] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_Y] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_Z] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_EXCLAMATION] = sUnownLevelUpLearnset_Kismet,
    [SPECIES_UNOWN_QUESTION] = sUnownLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_WOBBUFFET
    [SPECIES_WOBBUFFET] = sWobbuffetLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] = sGirafarigLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PINECO
    [SPECIES_PINECO] = sPinecoLevelUpLearnset_Kismet,
    [SPECIES_FORRETRESS] = sForretressLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] = sDunsparceLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] = sGligarLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ONIX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_STEELIX] = sSteelixLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] = sSnubbullLevelUpLearnset_Kismet,
    [SPECIES_GRANBULL] = sGranbullLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] = sQwilfishLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SCYTHER
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SCIZOR] = sScizorLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] = sTeddiursaLevelUpLearnset_Kismet,
    [SPECIES_URSARING] = sUrsaringLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] = sSlugmaLevelUpLearnset_Kismet,
    [SPECIES_MAGCARGO] = sMagcargoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] = sSwinubLevelUpLearnset_Kismet,
    [SPECIES_PILOSWINE] = sPiloswineLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CORSOLA
    [SPECIES_CORSOLA] = sCorsolaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] = sRemoraidLevelUpLearnset_Kismet,
    [SPECIES_OCTILLERY] = sOctilleryLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] = sDelibirdLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MANTINE
    [SPECIES_MANTINE] = sMantineLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] = sSkarmoryLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] = sHoundourLevelUpLearnset_Kismet,
    [SPECIES_HOUNDOOM] = sHoundoomLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HORSEA
#if P_GEN_2_CROSS_EVOS
    [SPECIES_KINGDRA] = sKingdraLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] = sPhanpyLevelUpLearnset_Kismet,
    [SPECIES_DONPHAN] = sDonphanLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PORYGON
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PORYGON2] = sPorygon2LevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] = sStantlerLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SMEARGLE
    [SPECIES_SMEARGLE] = sSmeargleLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
    [SPECIES_TYROGUE] = sTyrogueLevelUpLearnset_Kismet,
    [SPECIES_HITMONTOP] = sHitmontopLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_JYNX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SMOOCHUM] = sSmoochumLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_ELECTABUZZ
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ELEKID] = sElekidLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_2_CROSS_EVOS
    [SPECIES_MAGBY] = sMagbyLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] = sMiltankLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CHANSEY
#if P_GEN_2_CROSS_EVOS
    [SPECIES_BLISSEY] = sBlisseyLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_RAIKOU
    [SPECIES_RAIKOU] = sRaikouLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ENTEI
    [SPECIES_ENTEI] = sEnteiLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SUICUNE
    [SPECIES_SUICUNE] = sSuicuneLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] = sLarvitarLevelUpLearnset_Kismet,
    [SPECIES_PUPITAR] = sPupitarLevelUpLearnset_Kismet,
    [SPECIES_TYRANITAR] = sTyranitarLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LUGIA
    [SPECIES_LUGIA] = sLugiaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HO_OH
    [SPECIES_HO_OH] = sHoOhLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CELEBI
    [SPECIES_CELEBI] = sCelebiLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TREECKO
    [SPECIES_TREECKO] = sTreeckoLevelUpLearnset_Kismet,
    [SPECIES_GROVYLE] = sGrovyleLevelUpLearnset_Kismet,
    [SPECIES_SCEPTILE] = sSceptileLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC] = sTorchicLevelUpLearnset_Kismet,
    [SPECIES_COMBUSKEN] = sCombuskenLevelUpLearnset_Kismet,
    [SPECIES_BLAZIKEN] = sBlazikenLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MUDKIP
    [SPECIES_MUDKIP] = sMudkipLevelUpLearnset_Kismet,
    [SPECIES_MARSHTOMP] = sMarshtompLevelUpLearnset_Kismet,
    [SPECIES_SWAMPERT] = sSwampertLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA] = sPoochyenaLevelUpLearnset_Kismet,
    [SPECIES_MIGHTYENA] = sMightyenaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ZIGZAGOON
    [SPECIES_ZIGZAGOON] = sZigzagoonLevelUpLearnset_Kismet,
    [SPECIES_LINOONE] = sLinooneLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_WURMPLE
    [SPECIES_WURMPLE] = sWurmpleLevelUpLearnset_Kismet,
    [SPECIES_SILCOON] = sSilcoonLevelUpLearnset_Kismet,
    [SPECIES_BEAUTIFLY] = sBeautiflyLevelUpLearnset_Kismet,
    [SPECIES_CASCOON] = sCascoonLevelUpLearnset_Kismet,
    [SPECIES_DUSTOX] = sDustoxLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LOTAD
    [SPECIES_LOTAD] = sLotadLevelUpLearnset_Kismet,
    [SPECIES_LOMBRE] = sLombreLevelUpLearnset_Kismet,
    [SPECIES_LUDICOLO] = sLudicoloLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotLevelUpLearnset_Kismet,
    [SPECIES_NUZLEAF] = sNuzleafLevelUpLearnset_Kismet,
    [SPECIES_SHIFTRY] = sShiftryLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TAILLOW
    [SPECIES_TAILLOW] = sTaillowLevelUpLearnset_Kismet,
    [SPECIES_SWELLOW] = sSwellowLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_WINGULL
    [SPECIES_WINGULL] = sWingullLevelUpLearnset_Kismet,
    [SPECIES_PELIPPER] = sPelipperLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_RALTS
    [SPECIES_RALTS] = sRaltsLevelUpLearnset_Kismet,
    [SPECIES_KIRLIA] = sKirliaLevelUpLearnset_Kismet,
    [SPECIES_GARDEVOIR] = sGardevoirLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SURSKIT
    [SPECIES_SURSKIT] = sSurskitLevelUpLearnset_Kismet,
    [SPECIES_MASQUERAIN] = sMasquerainLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SHROOMISH
    [SPECIES_SHROOMISH] = sShroomishLevelUpLearnset_Kismet,
    [SPECIES_BRELOOM] = sBreloomLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] = sSlakothLevelUpLearnset_Kismet,
    [SPECIES_VIGOROTH] = sVigorothLevelUpLearnset_Kismet,
    [SPECIES_SLAKING] = sSlakingLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_NINCADA
    [SPECIES_NINCADA] = sNincadaLevelUpLearnset_Kismet,
    [SPECIES_NINJASK] = sNinjaskLevelUpLearnset_Kismet,
    [SPECIES_SHEDINJA] = sShedinjaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_WHISMUR
    [SPECIES_WHISMUR] = sWhismurLevelUpLearnset_Kismet,
    [SPECIES_LOUDRED] = sLoudredLevelUpLearnset_Kismet,
    [SPECIES_EXPLOUD] = sExploudLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaLevelUpLearnset_Kismet,
    [SPECIES_HARIYAMA] = sHariyamaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MARILL
#if P_GEN_3_CROSS_EVOS
    [SPECIES_AZURILL] = sAzurillLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyLevelUpLearnset_Kismet,
    [SPECIES_DELCATTY] = sDelcattyLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] = sSableyeLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MAWILE
    [SPECIES_MAWILE] = sMawileLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ARON
    [SPECIES_ARON] = sAronLevelUpLearnset_Kismet,
    [SPECIES_LAIRON] = sLaironLevelUpLearnset_Kismet,
    [SPECIES_AGGRON] = sAggronLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] = sMedititeLevelUpLearnset_Kismet,
    [SPECIES_MEDICHAM] = sMedichamLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ELECTRIKE
    [SPECIES_ELECTRIKE] = sElectrikeLevelUpLearnset_Kismet,
    [SPECIES_MANECTRIC] = sManectricLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PLUSLE
    [SPECIES_PLUSLE] = sPlusleLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MINUN
    [SPECIES_MINUN] = sMinunLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_VOLBEAT_ILLUMISE
    [SPECIES_VOLBEAT] = sVolbeatLevelUpLearnset_Kismet,
    [SPECIES_ILLUMISE] = sIllumiseLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ROSELIA
    [SPECIES_ROSELIA] = sRoseliaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GULPIN
    [SPECIES_GULPIN] = sGulpinLevelUpLearnset_Kismet,
    [SPECIES_SWALOT] = sSwalotLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaLevelUpLearnset_Kismet,
    [SPECIES_SHARPEDO] = sSharpedoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] = sWailmerLevelUpLearnset_Kismet,
    [SPECIES_WAILORD] = sWailordLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_NUMEL
    [SPECIES_NUMEL] = sNumelLevelUpLearnset_Kismet,
    [SPECIES_CAMERUPT] = sCameruptLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] = sTorkoalLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] = sSpoinkLevelUpLearnset_Kismet,
    [SPECIES_GRUMPIG] = sGrumpigLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TRAPINCH
    [SPECIES_TRAPINCH] = sTrapinchLevelUpLearnset_Kismet,
    [SPECIES_VIBRAVA] = sVibravaLevelUpLearnset_Kismet,
    [SPECIES_FLYGON] = sFlygonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CACNEA
    [SPECIES_CACNEA] = sCacneaLevelUpLearnset_Kismet,
    [SPECIES_CACTURNE] = sCacturneLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SWABLU
    [SPECIES_SWABLU] = sSwabluLevelUpLearnset_Kismet,
    [SPECIES_ALTARIA] = sAltariaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ZANGOOSE
    [SPECIES_ZANGOOSE] = sZangooseLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SEVIPER
    [SPECIES_SEVIPER] = sSeviperLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LUNATONE
    [SPECIES_LUNATONE] = sLunatoneLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SOLROCK
    [SPECIES_SOLROCK] = sSolrockLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BARBOACH
    [SPECIES_BARBOACH] = sBarboachLevelUpLearnset_Kismet,
    [SPECIES_WHISCASH] = sWhiscashLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] = sCorphishLevelUpLearnset_Kismet,
    [SPECIES_CRAWDAUNT] = sCrawdauntLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BALTOY
    [SPECIES_BALTOY] = sBaltoyLevelUpLearnset_Kismet,
    [SPECIES_CLAYDOL] = sClaydolLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] = sLileepLevelUpLearnset_Kismet,
    [SPECIES_CRADILY] = sCradilyLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ANORITH
    [SPECIES_ANORITH] = sAnorithLevelUpLearnset_Kismet,
    [SPECIES_ARMALDO] = sArmaldoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_FEEBAS
    [SPECIES_FEEBAS] = sFeebasLevelUpLearnset_Kismet,
    [SPECIES_MILOTIC] = sMiloticLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CASTFORM
    [SPECIES_CASTFORM] = sCastformLevelUpLearnset_Kismet,
    [SPECIES_CASTFORM_NORMAL] = sCastformLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_KECLEON
    [SPECIES_KECLEON] = sKecleonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] = sShuppetLevelUpLearnset_Kismet,
    [SPECIES_BANETTE] = sBanetteLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DUSKULL
    [SPECIES_DUSKULL] = sDuskullLevelUpLearnset_Kismet,
    [SPECIES_DUSCLOPS] = sDusclopsLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CHIMECHO
    [SPECIES_CHIMECHO] = sChimechoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_WOBBUFFET
#if P_GEN_3_CROSS_EVOS
    [SPECIES_WYNAUT] = sWynautLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntLevelUpLearnset_Kismet,
    [SPECIES_GLALIE] = sGlalieLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SPHEAL
    [SPECIES_SPHEAL] = sSphealLevelUpLearnset_Kismet,
    [SPECIES_SEALEO] = sSealeoLevelUpLearnset_Kismet,
    [SPECIES_WALREIN] = sWalreinLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] = sClamperlLevelUpLearnset_Kismet,
    [SPECIES_HUNTAIL] = sHuntailLevelUpLearnset_Kismet,
    [SPECIES_GOREBYSS] = sGorebyssLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] = sLuvdiscLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BAGON
    [SPECIES_BAGON] = sBagonLevelUpLearnset_Kismet,
    [SPECIES_SHELGON] = sShelgonLevelUpLearnset_Kismet,
    [SPECIES_SALAMENCE] = sSalamenceLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BELDUM
    [SPECIES_BELDUM] = sBeldumLevelUpLearnset_Kismet,
    [SPECIES_METANG] = sMetangLevelUpLearnset_Kismet,
    [SPECIES_METAGROSS] = sMetagrossLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_REGIROCK
    [SPECIES_REGIROCK] = sRegirockLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_REGICE
    [SPECIES_REGICE] = sRegiceLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_REGISTEEL
    [SPECIES_REGISTEEL] = sRegisteelLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LATIAS
    [SPECIES_LATIAS] = sLatiasLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LATIOS
    [SPECIES_LATIOS] = sLatiosLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_KYOGRE
    [SPECIES_KYOGRE] = sKyogreLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GROUDON
    [SPECIES_GROUDON] = sGroudonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_RAYQUAZA
    [SPECIES_RAYQUAZA] = sRayquazaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_JIRACHI
    [SPECIES_JIRACHI] = sJirachiLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DEOXYS
    [SPECIES_DEOXYS_NORMAL] = sDeoxysNormalLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TURTWIG
    [SPECIES_TURTWIG] = sTurtwigLevelUpLearnset_Kismet,
    [SPECIES_GROTLE] = sGrotleLevelUpLearnset_Kismet,
    [SPECIES_TORTERRA] = sTorterraLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CHIMCHAR
    [SPECIES_CHIMCHAR] = sChimcharLevelUpLearnset_Kismet,
    [SPECIES_MONFERNO] = sMonfernoLevelUpLearnset_Kismet,
    [SPECIES_INFERNAPE] = sInfernapeLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PIPLUP
    [SPECIES_PIPLUP] = sPiplupLevelUpLearnset_Kismet,
    [SPECIES_PRINPLUP] = sPrinplupLevelUpLearnset_Kismet,
    [SPECIES_EMPOLEON] = sEmpoleonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_STARLY
    [SPECIES_STARLY] = sStarlyLevelUpLearnset_Kismet,
    [SPECIES_STARAVIA] = sStaraviaLevelUpLearnset_Kismet,
    [SPECIES_STARAPTOR] = sStaraptorLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SHINX
    [SPECIES_SHINX] = sShinxLevelUpLearnset_Kismet,
    [SPECIES_LUXIO] = sLuxioLevelUpLearnset_Kismet,
    [SPECIES_LUXRAY] = sLuxrayLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ROSELIA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BUDEW] = sBudewLevelUpLearnset_Kismet,
    [SPECIES_ROSERADE] = sRoseradeLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CRANIDOS
    [SPECIES_CRANIDOS] = sCranidosLevelUpLearnset_Kismet,
    [SPECIES_RAMPARDOS] = sRampardosLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SHIELDON
    [SPECIES_SHIELDON] = sShieldonLevelUpLearnset_Kismet,
    [SPECIES_BASTIODON] = sBastiodonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BURMY
    [SPECIES_BURMY] = sBurmyLevelUpLearnset_Kismet,
    [SPECIES_WORMADAM_PLANT] = sWormadamPlantLevelUpLearnset_Kismet,
    [SPECIES_MOTHIM] = sMothimLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_COMBEE
    [SPECIES_COMBEE] = sCombeeLevelUpLearnset_Kismet,
    [SPECIES_VESPIQUEN] = sVespiquenLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BUIZEL
    [SPECIES_BUIZEL] = sBuizelLevelUpLearnset_Kismet,
    [SPECIES_FLOATZEL] = sFloatzelLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_AIPOM
#if P_GEN_4_CROSS_EVOS
    [SPECIES_AMBIPOM] = sAmbipomLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_DRIFLOON
    [SPECIES_DRIFLOON] = sDrifloonLevelUpLearnset_Kismet,
    [SPECIES_DRIFBLIM] = sDrifblimLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BUNEARY
    [SPECIES_BUNEARY] = sBunearyLevelUpLearnset_Kismet,
    [SPECIES_LOPUNNY] = sLopunnyLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MISDREAVUS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MISMAGIUS] = sMismagiusLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MURKROW
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HONCHKROW] = sHonchkrowLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_GLAMEOW
    [SPECIES_GLAMEOW] = sGlameowLevelUpLearnset_Kismet,
    [SPECIES_PURUGLY] = sPuruglyLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CHIMECHO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_CHINGLING] = sChinglingLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_BRONZOR
    [SPECIES_BRONZOR] = sBronzorLevelUpLearnset_Kismet,
    [SPECIES_BRONZONG] = sBronzongLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SUDOWOODO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BONSLY] = sBonslyLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MR_MIME
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MIME_JR] = sMimeJrLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CHANSEY
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HAPPINY] = sHappinyLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SPIRITOMB
    [SPECIES_SPIRITOMB] = sSpiritombLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GIBLE
    [SPECIES_GIBLE] = sGibleLevelUpLearnset_Kismet,
    [SPECIES_GABITE] = sGabiteLevelUpLearnset_Kismet,
    [SPECIES_GARCHOMP] = sGarchompLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SNORLAX
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MUNCHLAX] = sMunchlaxLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_RIOLU
    [SPECIES_RIOLU] = sRioluLevelUpLearnset_Kismet,
    [SPECIES_LUCARIO] = sLucarioLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SKORUPI
    [SPECIES_SKORUPI] = sSkorupiLevelUpLearnset_Kismet,
    [SPECIES_DRAPION] = sDrapionLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CROAGUNK
    [SPECIES_CROAGUNK] = sCroagunkLevelUpLearnset_Kismet,
    [SPECIES_TOXICROAK] = sToxicroakLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_FINNEON
    [SPECIES_FINNEON] = sFinneonLevelUpLearnset_Kismet,
    [SPECIES_LUMINEON] = sLumineonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MANTINE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MANTYKE] = sMantykeLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SNOVER
    [SPECIES_SNOVER] = sSnoverLevelUpLearnset_Kismet,
    [SPECIES_ABOMASNOW] = sAbomasnowLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SNEASEL
#if P_GEN_4_CROSS_EVOS
    [SPECIES_WEAVILE] = sWeavileLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MAGNEMITE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGNEZONE] = sMagnezoneLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_LICKITUNG
#if P_GEN_4_CROSS_EVOS
    [SPECIES_LICKILICKY] = sLickilickyLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_RHYHORN
#if P_GEN_4_CROSS_EVOS
    [SPECIES_RHYPERIOR] = sRhyperiorLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_TANGELA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_TANGROWTH] = sTangrowthLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_ELECTABUZZ
#if P_GEN_4_CROSS_EVOS
    [SPECIES_ELECTIVIRE] = sElectivireLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGMORTAR] = sMagmortarLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_TOGEPI
#if P_GEN_4_CROSS_EVOS
    [SPECIES_TOGEKISS] = sTogekissLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_YANMA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_YANMEGA] = sYanmegaLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_EEVEE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_LEAFEON] = sLeafeonLevelUpLearnset_Kismet,
    [SPECIES_GLACEON] = sGlaceonLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_GLIGAR
#if P_GEN_4_CROSS_EVOS
    [SPECIES_GLISCOR] = sGliscorLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SWINUB
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAMOSWINE] = sMamoswineLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PORYGON
#if P_GEN_2_CROSS_EVOS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_PORYGON_Z] = sPorygonZLevelUpLearnset_Kismet,
#endif
#endif
#endif
#if P_FAMILY_RALTS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_GALLADE] = sGalladeLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_NOSEPASS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_PROBOPASS] = sProbopassLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_DUSKULL
#if P_GEN_4_CROSS_EVOS
    [SPECIES_DUSKNOIR] = sDusknoirLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SNORUNT
#if P_GEN_4_CROSS_EVOS
    [SPECIES_FROSLASS] = sFroslassLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_REGIGIGAS
    [SPECIES_REGIGIGAS] = sRegigigasLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ARCEUS
    [SPECIES_ARCEUS] = sArceusLevelUpLearnset_Kismet,
    [SPECIES_ARCEUS_NORMAL] = sArceusLevelUpLearnset_Kismet,
    [SPECIES_ARCEUS_STEEL] = sArceusLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] = sRoggenrolaLevelUpLearnset_Kismet,
    [SPECIES_BOLDORE] = sBoldoreLevelUpLearnset_Kismet,
    [SPECIES_GIGALITH] = sGigalithLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] = sSandileLevelUpLearnset_Kismet,
    [SPECIES_KROKOROK] = sKrokorokLevelUpLearnset_Kismet,
    [SPECIES_KROOKODILE] = sKrookodileLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DARUMAKA
    [SPECIES_DARUMAKA] = sDarumakaLevelUpLearnset_Kismet,
    [SPECIES_DARMANITAN] = sDarmanitanLevelUpLearnset_Kismet,
    [SPECIES_DARMANITAN_STANDARD] = sDarmanitanLevelUpLearnset_Kismet,
    [SPECIES_DARMANITAN_ZEN] = sDarmanitanLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ZORUA
    [SPECIES_ZORUA] = sZoruaLevelUpLearnset_Kismet,
    [SPECIES_ZOROARK] = sZoroarkLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteLevelUpLearnset_Kismet,
    [SPECIES_VANILLISH] = sVanillishLevelUpLearnset_Kismet,
    [SPECIES_VANILLUXE] = sVanilluxeLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] = sEmolgaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_KLINK
    [SPECIES_KLINK] = sKlinkLevelUpLearnset_Kismet,
    [SPECIES_KLANG] = sKlangLevelUpLearnset_Kismet,
    [SPECIES_KLINKLANG] = sKlinklangLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] = sTynamoLevelUpLearnset_Kismet,
    [SPECIES_EELEKTRIK] = sEelektrikLevelUpLearnset_Kismet,
    [SPECIES_EELEKTROSS] = sEelektrossLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] = sLitwickLevelUpLearnset_Kismet,
    [SPECIES_LAMPENT] = sLampentLevelUpLearnset_Kismet,
    [SPECIES_CHANDELURE] = sChandelureLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_AXEW
    [SPECIES_AXEW] = sAxewLevelUpLearnset_Kismet,
    [SPECIES_FRAXURE] = sFraxureLevelUpLearnset_Kismet,
    [SPECIES_HAXORUS] = sHaxorusLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] = sCubchooLevelUpLearnset_Kismet,
    [SPECIES_BEARTIC] = sBearticLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CRYOGONAL
    [SPECIES_CRYOGONAL] = sCryogonalLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooLevelUpLearnset_Kismet,
    [SPECIES_MIENSHAO] = sMienshaoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GOLETT
    [SPECIES_GOLETT] = sGolettLevelUpLearnset_Kismet,
    [SPECIES_GOLURK] = sGolurkLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] = sRuffletLevelUpLearnset_Kismet,
    [SPECIES_BRAVIARY] = sBraviaryLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] = sVullabyLevelUpLearnset_Kismet,
    [SPECIES_MANDIBUZZ] = sMandibuzzLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DEINO
    [SPECIES_DEINO] = sDeinoLevelUpLearnset_Kismet,
    [SPECIES_ZWEILOUS] = sZweilousLevelUpLearnset_Kismet,
    [SPECIES_HYDREIGON] = sHydreigonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] = sLarvestaLevelUpLearnset_Kismet,
    [SPECIES_VOLCARONA] = sVolcaronaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] = sFletchlingLevelUpLearnset_Kismet,
    [SPECIES_FLETCHINDER] = sFletchinderLevelUpLearnset_Kismet,
    [SPECIES_TALONFLAME] = sTalonflameLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_FLABEBE
    [SPECIES_FLABEBE] = sFlabebeLevelUpLearnset_Kismet,
    [SPECIES_FLOETTE] = sFloetteLevelUpLearnset_Kismet,
    [SPECIES_FLORGES] = sFlorgesLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] = sPanchamLevelUpLearnset_Kismet,
    [SPECIES_PANGORO] = sPangoroLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_HONEDGE
    [SPECIES_HONEDGE] = sHonedgeLevelUpLearnset_Kismet,
    [SPECIES_DOUBLADE] = sDoubladeLevelUpLearnset_Kismet,
    [SPECIES_AEGISLASH] = sAegislashLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_EEVEE
#if P_GEN_6_CROSS_EVOS
    [SPECIES_SYLVEON] = sSylveonLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CARBINK
    [SPECIES_CARBINK] = sCarbinkLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_NOIBAT
    [SPECIES_NOIBAT] = sNoibatLevelUpLearnset_Kismet,
    [SPECIES_NOIVERN] = sNoivernLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_ROCKRUFF
    [SPECIES_ROCKRUFF] = sRockruffLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisLevelUpLearnset_Kismet,
    [SPECIES_LURANTIS] = sLurantisLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_STUFFUL
    [SPECIES_STUFFUL] = sStuffulLevelUpLearnset_Kismet,
    [SPECIES_BEWEAR] = sBewearLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BOUNSWEET
    [SPECIES_BOUNSWEET] = sBounsweetLevelUpLearnset_Kismet,
    [SPECIES_STEENEE] = sSteeneeLevelUpLearnset_Kismet,
    [SPECIES_TSAREENA] = sTsareenaLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MIMIKYU
    [SPECIES_MIMIKYU] = sMimikyuLevelUpLearnset_Kismet,
    [SPECIES_MIMIKYU_DISGUISED] = sMimikyuLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TAPU_KOKO
    [SPECIES_TAPU_KOKO] = sTapuKokoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TAPU_LELE
    [SPECIES_TAPU_LELE] = sTapuLeleLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TAPU_BULU
    [SPECIES_TAPU_BULU] = sTapuBuluLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TAPU_FINI
    [SPECIES_TAPU_FINI] = sTapuFiniLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SINISTEA
    [SPECIES_SINISTEA] = sSinisteaLevelUpLearnset_Kismet,
    [SPECIES_POLTEAGEIST] = sPolteageistLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] = sImpidimpLevelUpLearnset_Kismet,
    [SPECIES_MORGREM] = sMorgremLevelUpLearnset_Kismet,
    [SPECIES_GRIMMSNARL] = sGrimmsnarlLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MILCERY
    [SPECIES_MILCERY] = sMilceryLevelUpLearnset_Kismet,
    [SPECIES_ALCREMIE] = sAlcremieLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_SNOM
    [SPECIES_SNOM] = sSnomLevelUpLearnset_Kismet,
    [SPECIES_FROSMOTH] = sFrosmothLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_REGIELEKI
    [SPECIES_REGIELEKI] = sRegielekiLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_REGIDRAGO
    [SPECIES_REGIDRAGO] = sRegidragoLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_STANTLER
#if P_GEN_8_CROSS_EVOS
    [SPECIES_WYRDEER] = sWyrdeerLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SCYTHER
#if P_GEN_8_CROSS_EVOS
    [SPECIES_KLEAVOR] = sKleavorLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_TEDDIURSA
#if P_GEN_8_CROSS_EVOS
    [SPECIES_URSALUNA] = sUrsalunaLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_WATTREL
    [SPECIES_WATTREL] = sWattrelLevelUpLearnset_Kismet,
    [SPECIES_KILOWATTREL] = sKilowattrelLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_KLAWF
    [SPECIES_KLAWF] = sKlawfLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CAPSAKID
    [SPECIES_CAPSAKID] = sCapsakidLevelUpLearnset_Kismet,
    [SPECIES_SCOVILLAIN] = sScovillainLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_FLITTLE
    [SPECIES_FLITTLE] = sFlittleLevelUpLearnset_Kismet,
    [SPECIES_ESPATHRA] = sEspathraLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] = sTinkatinkLevelUpLearnset_Kismet,
    [SPECIES_TINKATUFF] = sTinkatuffLevelUpLearnset_Kismet,
    [SPECIES_TINKATON] = sTinkatonLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] = sBombirdierLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GLIMMET
    [SPECIES_GLIMMET] = sGlimmetLevelUpLearnset_Kismet,
    [SPECIES_GLIMMORA] = sGlimmoraLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardLevelUpLearnset_Kismet,
    [SPECIES_HOUNDSTONE] = sHoundstoneLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_MANKEY
#if P_GEN_9_CROSS_EVOS
    [SPECIES_ANNIHILAPE] = sAnnihilapeLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_GIRAFARIG
#if P_GEN_9_CROSS_EVOS
    [SPECIES_FARIGIRAF] = sFarigirafLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_DUNSPARCE
#if P_GEN_9_CROSS_EVOS
    [SPECIES_DUDUNSPARCE] = sDudunsparceLevelUpLearnset_Kismet,
    [SPECIES_DUDUNSPARCE_THREE_SEGMENT] = sDudunsparceLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PIKACHU
#if P_ALOLAN_FORMS
    [SPECIES_RAICHU_ALOLA] = sRaichuAlolaLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_EXEGGCUTE
#if P_ALOLAN_FORMS
    [SPECIES_EXEGGUTOR_ALOLA] = sExeggutorAlolaLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CUBONE
#if P_ALOLAN_FORMS
    [SPECIES_MAROWAK_ALOLA] = sMarowakAlolaLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_KOFFING
#if P_GALARIAN_FORMS
    [SPECIES_WEEZING_GALAR] = sWeezingGalarLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CYNDAQUIL
#if P_HISUIAN_FORMS
    [SPECIES_TYPHLOSION_HISUI] = sTyphlosionHisuiLevelUpLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CHIKORITA
    [SPECIES_ALT_MEGANIUM] = sMeganiumLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_CYNDAQUIL
    [SPECIES_ALT_TYPHLOSION] = sTyphlosionLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TOTODILE
    [SPECIES_ALT_FERALIGATR] = sFeraligatrLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_DEOXYS
    [SPECIES_DEOXYS_ATTACK] = sDeoxysAttackLevelUpLearnset_Kismet,
    [SPECIES_DEOXYS_DEFENSE] = sDeoxysDefenseLevelUpLearnset_Kismet,
    [SPECIES_DEOXYS_SPEED] = sDeoxysSpeedLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_BURMY
    [SPECIES_WORMADAM_SANDY] = sWormadamSandyLevelUpLearnset_Kismet,
    [SPECIES_WORMADAM_TRASH] = sWormadamTrashLevelUpLearnset_Kismet,
#endif
#if P_FAMILY_TEDDIURSA
#if P_GEN_8_CROSS_EVOS
    [SPECIES_URSALUNA_BLOODMOON] = sUrsalunaBloodmoonLevelUpLearnset_Kismet,
#endif
#endif
};
