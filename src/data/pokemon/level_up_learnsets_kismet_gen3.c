#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "level_up_learnsets/kismet_gen3.h"

// NULL for every species the fork does not override, which
// GetSpeciesLevelUpLearnset reads as "fall through to the baseline".
// NUM_SPECIES + 1: NUM_SPECIES == SPECIES_EGG and SanitizeSpeciesId
// returns it unchanged, so a bare NUM_SPECIES sizing lets an egg
// read one element past the end.
const struct LevelUpMove *const gLevelUpLearnsets_KismetGen3[NUM_SPECIES + 1] = {
#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR] = sBulbasaurLevelUpLearnset_KismetGen3,
    [SPECIES_IVYSAUR] = sIvysaurLevelUpLearnset_KismetGen3,
    [SPECIES_VENUSAUR] = sVenusaurLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] = sCharmanderLevelUpLearnset_KismetGen3,
    [SPECIES_CHARMELEON] = sCharmeleonLevelUpLearnset_KismetGen3,
    [SPECIES_CHARIZARD] = sCharizardLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SQUIRTLE
    [SPECIES_SQUIRTLE] = sSquirtleLevelUpLearnset_KismetGen3,
    [SPECIES_WARTORTLE] = sWartortleLevelUpLearnset_KismetGen3,
    [SPECIES_BLASTOISE] = sBlastoiseLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CATERPIE
    [SPECIES_CATERPIE] = sCaterpieLevelUpLearnset_KismetGen3,
    [SPECIES_METAPOD] = sMetapodLevelUpLearnset_KismetGen3,
    [SPECIES_BUTTERFREE] = sButterfreeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_WEEDLE
    [SPECIES_WEEDLE] = sWeedleLevelUpLearnset_KismetGen3,
    [SPECIES_KAKUNA] = sKakunaLevelUpLearnset_KismetGen3,
    [SPECIES_BEEDRILL] = sBeedrillLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PIDGEY
    [SPECIES_PIDGEY] = sPidgeyLevelUpLearnset_KismetGen3,
    [SPECIES_PIDGEOTTO] = sPidgeottoLevelUpLearnset_KismetGen3,
    [SPECIES_PIDGEOT] = sPidgeotLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RATTATA
    [SPECIES_RATTATA] = sRattataLevelUpLearnset_KismetGen3,
    [SPECIES_RATICATE] = sRaticateLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowLevelUpLearnset_KismetGen3,
    [SPECIES_FEAROW] = sFearowLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansLevelUpLearnset_KismetGen3,
    [SPECIES_ARBOK] = sArbokLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PICHU] = sPichuLevelUpLearnset_KismetGen3,
    [SPECIES_PICHU_SPIKY_EARED] = sPichuLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PIKACHU
    [SPECIES_PIKACHU] = sPikachuLevelUpLearnset_KismetGen3,
    [SPECIES_RAICHU] = sRaichuLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewLevelUpLearnset_KismetGen3,
    [SPECIES_SANDSLASH] = sSandslashLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_NIDORAN
    [SPECIES_NIDORAN_F] = sNidoranFLevelUpLearnset_KismetGen3,
    [SPECIES_NIDORINA] = sNidorinaLevelUpLearnset_KismetGen3,
    [SPECIES_NIDOQUEEN] = sNidoqueenLevelUpLearnset_KismetGen3,
    [SPECIES_NIDORAN_M] = sNidoranMLevelUpLearnset_KismetGen3,
    [SPECIES_NIDORINO] = sNidorinoLevelUpLearnset_KismetGen3,
    [SPECIES_NIDOKING] = sNidokingLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CLEFAIRY
#if P_GEN_2_CROSS_EVOS
    [SPECIES_CLEFFA] = sCleffaLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_CLEFAIRY
    [SPECIES_CLEFAIRY] = sClefairyLevelUpLearnset_KismetGen3,
    [SPECIES_CLEFABLE] = sClefableLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_VULPIX
    [SPECIES_VULPIX] = sVulpixLevelUpLearnset_KismetGen3,
    [SPECIES_NINETALES] = sNinetalesLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_JIGGLYPUFF
#if P_GEN_2_CROSS_EVOS
    [SPECIES_IGGLYBUFF] = sIgglybuffLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_JIGGLYPUFF
    [SPECIES_JIGGLYPUFF] = sJigglypuffLevelUpLearnset_KismetGen3,
    [SPECIES_WIGGLYTUFF] = sWigglytuffLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ZUBAT
    [SPECIES_ZUBAT] = sZubatLevelUpLearnset_KismetGen3,
    [SPECIES_GOLBAT] = sGolbatLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ZUBAT
#if P_GEN_2_CROSS_EVOS
    [SPECIES_CROBAT] = sCrobatLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_ODDISH
    [SPECIES_ODDISH] = sOddishLevelUpLearnset_KismetGen3,
    [SPECIES_GLOOM] = sGloomLevelUpLearnset_KismetGen3,
    [SPECIES_VILEPLUME] = sVileplumeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ODDISH
#if P_GEN_2_CROSS_EVOS
    [SPECIES_BELLOSSOM] = sBellossomLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PARAS
    [SPECIES_PARAS] = sParasLevelUpLearnset_KismetGen3,
    [SPECIES_PARASECT] = sParasectLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_VENONAT
    [SPECIES_VENONAT] = sVenonatLevelUpLearnset_KismetGen3,
    [SPECIES_VENOMOTH] = sVenomothLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DIGLETT
    [SPECIES_DIGLETT] = sDiglettLevelUpLearnset_KismetGen3,
    [SPECIES_DUGTRIO] = sDugtrioLevelUpLearnset_KismetGen3,
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
    [SPECIES_MANKEY] = sMankeyLevelUpLearnset_KismetGen3,
    [SPECIES_PRIMEAPE] = sPrimeapeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MANKEY
#if P_GEN_9_CROSS_EVOS
    [SPECIES_ANNIHILAPE] = sAnnihilapeLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_GROWLITHE
    [SPECIES_GROWLITHE] = sGrowlitheLevelUpLearnset_KismetGen3,
    [SPECIES_ARCANINE] = sArcanineLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_POLIWAG
    [SPECIES_POLIWAG] = sPoliwagLevelUpLearnset_KismetGen3,
    [SPECIES_POLIWHIRL] = sPoliwhirlLevelUpLearnset_KismetGen3,
    [SPECIES_POLIWRATH] = sPoliwrathLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_POLIWAG
#if P_GEN_2_CROSS_EVOS
    [SPECIES_POLITOED] = sPolitoedLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_ABRA
    [SPECIES_ABRA] = sAbraLevelUpLearnset_KismetGen3,
    [SPECIES_KADABRA] = sKadabraLevelUpLearnset_KismetGen3,
    [SPECIES_ALAKAZAM] = sAlakazamLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MACHOP
    [SPECIES_MACHOP] = sMachopLevelUpLearnset_KismetGen3,
    [SPECIES_MACHOKE] = sMachokeLevelUpLearnset_KismetGen3,
    [SPECIES_MACHAMP] = sMachampLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BELLSPROUT
    [SPECIES_BELLSPROUT] = sBellsproutLevelUpLearnset_KismetGen3,
    [SPECIES_WEEPINBELL] = sWeepinbellLevelUpLearnset_KismetGen3,
    [SPECIES_VICTREEBEL] = sVictreebelLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TENTACOOL
    [SPECIES_TENTACOOL] = sTentacoolLevelUpLearnset_KismetGen3,
    [SPECIES_TENTACRUEL] = sTentacruelLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GEODUDE
    [SPECIES_GEODUDE] = sGeodudeLevelUpLearnset_KismetGen3,
    [SPECIES_GRAVELER] = sGravelerLevelUpLearnset_KismetGen3,
    [SPECIES_GOLEM] = sGolemLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaLevelUpLearnset_KismetGen3,
    [SPECIES_RAPIDASH] = sRapidashLevelUpLearnset_KismetGen3,
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
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DODUO
    [SPECIES_DODUO] = sDoduoLevelUpLearnset_KismetGen3,
    [SPECIES_DODRIO] = sDodrioLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SEEL
    [SPECIES_SEEL] = sSeelLevelUpLearnset_KismetGen3,
    [SPECIES_DEWGONG] = sDewgongLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GRIMER
    [SPECIES_GRIMER] = sGrimerLevelUpLearnset_KismetGen3,
    [SPECIES_MUK] = sMukLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SHELLDER
    [SPECIES_SHELLDER] = sShellderLevelUpLearnset_KismetGen3,
    [SPECIES_CLOYSTER] = sCloysterLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GASTLY
    [SPECIES_GASTLY] = sGastlyLevelUpLearnset_KismetGen3,
    [SPECIES_HAUNTER] = sHaunterLevelUpLearnset_KismetGen3,
    [SPECIES_GENGAR] = sGengarLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ONIX
    [SPECIES_ONIX] = sOnixLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ONIX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_STEELIX] = sSteelixLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_DROWZEE
    [SPECIES_DROWZEE] = sDrowzeeLevelUpLearnset_KismetGen3,
    [SPECIES_HYPNO] = sHypnoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] = sKrabbyLevelUpLearnset_KismetGen3,
    [SPECIES_KINGLER] = sKinglerLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_VOLTORB
    [SPECIES_VOLTORB] = sVoltorbLevelUpLearnset_KismetGen3,
    [SPECIES_ELECTRODE] = sElectrodeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] = sExeggcuteLevelUpLearnset_KismetGen3,
    [SPECIES_EXEGGUTOR] = sExeggutorLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CUBONE
    [SPECIES_CUBONE] = sCuboneLevelUpLearnset_KismetGen3,
    [SPECIES_MAROWAK] = sMarowakLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
    [SPECIES_TYROGUE] = sTyrogueLevelUpLearnset_KismetGen3,
#endif
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
#if P_FAMILY_LICKITUNG
#if P_GEN_4_CROSS_EVOS
    [SPECIES_LICKILICKY] = sLickilickyLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_KOFFING
    [SPECIES_KOFFING] = sKoffingLevelUpLearnset_KismetGen3,
    [SPECIES_WEEZING] = sWeezingLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RHYHORN
    [SPECIES_RHYHORN] = sRhyhornLevelUpLearnset_KismetGen3,
    [SPECIES_RHYDON] = sRhydonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RHYHORN
#if P_GEN_4_CROSS_EVOS
    [SPECIES_RHYPERIOR] = sRhyperiorLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_CHANSEY
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HAPPINY] = sHappinyLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_CHANSEY
    [SPECIES_CHANSEY] = sChanseyLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CHANSEY
#if P_GEN_2_CROSS_EVOS
    [SPECIES_BLISSEY] = sBlisseyLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TANGELA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_TANGROWTH] = sTangrowthLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HORSEA
    [SPECIES_HORSEA] = sHorseaLevelUpLearnset_KismetGen3,
    [SPECIES_SEADRA] = sSeadraLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HORSEA
#if P_GEN_2_CROSS_EVOS
    [SPECIES_KINGDRA] = sKingdraLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_GOLDEEN
    [SPECIES_GOLDEEN] = sGoldeenLevelUpLearnset_KismetGen3,
    [SPECIES_SEAKING] = sSeakingLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_STARYU
    [SPECIES_STARYU] = sStaryuLevelUpLearnset_KismetGen3,
    [SPECIES_STARMIE] = sStarmieLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MR_MIME
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MIME_JR] = sMimeJrLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MR_MIME
    [SPECIES_MR_MIME] = sMrMimeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SCYTHER
    [SPECIES_SCYTHER] = sScytherLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SCYTHER
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SCIZOR] = sScizorLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SCYTHER
#if P_GEN_8_CROSS_EVOS
    [SPECIES_KLEAVOR] = sKleavorLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_JYNX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SMOOCHUM] = sSmoochumLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_JYNX
    [SPECIES_JYNX] = sJynxLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ELECTABUZZ
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ELEKID] = sElekidLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_ELECTABUZZ
    [SPECIES_ELECTABUZZ] = sElectabuzzLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ELECTABUZZ
#if P_GEN_4_CROSS_EVOS
    [SPECIES_ELECTIVIRE] = sElectivireLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_2_CROSS_EVOS
    [SPECIES_MAGBY] = sMagbyLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MAGMAR
    [SPECIES_MAGMAR] = sMagmarLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGMORTAR] = sMagmortarLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TAUROS
    [SPECIES_TAUROS] = sTaurosLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MAGIKARP
    [SPECIES_MAGIKARP] = sMagikarpLevelUpLearnset_KismetGen3,
    [SPECIES_GYARADOS] = sGyaradosLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DITTO
    [SPECIES_DITTO] = sDittoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeLevelUpLearnset_KismetGen3,
    [SPECIES_VAPOREON] = sVaporeonLevelUpLearnset_KismetGen3,
    [SPECIES_JOLTEON] = sJolteonLevelUpLearnset_KismetGen3,
    [SPECIES_FLAREON] = sFlareonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_EEVEE
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ESPEON] = sEspeonLevelUpLearnset_KismetGen3,
    [SPECIES_UMBREON] = sUmbreonLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_EEVEE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_LEAFEON] = sLeafeonLevelUpLearnset_KismetGen3,
    [SPECIES_GLACEON] = sGlaceonLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_EEVEE
#if P_GEN_6_CROSS_EVOS
    [SPECIES_SYLVEON] = sSylveonLevelUpLearnset_KismetGen3,
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
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteLevelUpLearnset_KismetGen3,
    [SPECIES_OMASTAR] = sOmastarLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoLevelUpLearnset_KismetGen3,
    [SPECIES_KABUTOPS] = sKabutopsLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SNORLAX
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MUNCHLAX] = sMunchlaxLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SNORLAX
    [SPECIES_SNORLAX] = sSnorlaxLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ARTICUNO
    [SPECIES_ARTICUNO] = sArticunoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ZAPDOS
    [SPECIES_ZAPDOS] = sZapdosLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MOLTRES
    [SPECIES_MOLTRES] = sMoltresLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DRATINI
    [SPECIES_DRATINI] = sDratiniLevelUpLearnset_KismetGen3,
    [SPECIES_DRAGONAIR] = sDragonairLevelUpLearnset_KismetGen3,
    [SPECIES_DRAGONITE] = sDragoniteLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MEWTWO
    [SPECIES_MEWTWO] = sMewtwoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MEW
    [SPECIES_MEW] = sMewLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] = sChikoritaLevelUpLearnset_KismetGen3,
    [SPECIES_BAYLEEF] = sBayleefLevelUpLearnset_KismetGen3,
    [SPECIES_MEGANIUM] = sMeganiumLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] = sCyndaquilLevelUpLearnset_KismetGen3,
    [SPECIES_QUILAVA] = sQuilavaLevelUpLearnset_KismetGen3,
    [SPECIES_TYPHLOSION] = sTyphlosionLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] = sTotodileLevelUpLearnset_KismetGen3,
    [SPECIES_CROCONAW] = sCroconawLevelUpLearnset_KismetGen3,
    [SPECIES_FERALIGATR] = sFeraligatrLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] = sSentretLevelUpLearnset_KismetGen3,
    [SPECIES_FURRET] = sFurretLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] = sHoothootLevelUpLearnset_KismetGen3,
    [SPECIES_NOCTOWL] = sNoctowlLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] = sLedybaLevelUpLearnset_KismetGen3,
    [SPECIES_LEDIAN] = sLedianLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] = sSpinarakLevelUpLearnset_KismetGen3,
    [SPECIES_ARIADOS] = sAriadosLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] = sChinchouLevelUpLearnset_KismetGen3,
    [SPECIES_LANTURN] = sLanturnLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TOGEPI
    [SPECIES_TOGEPI] = sTogepiLevelUpLearnset_KismetGen3,
    [SPECIES_TOGETIC] = sTogeticLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TOGEPI
#if P_GEN_4_CROSS_EVOS
    [SPECIES_TOGEKISS] = sTogekissLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_NATU
    [SPECIES_NATU] = sNatuLevelUpLearnset_KismetGen3,
    [SPECIES_XATU] = sXatuLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] = sMareepLevelUpLearnset_KismetGen3,
    [SPECIES_FLAAFFY] = sFlaaffyLevelUpLearnset_KismetGen3,
    [SPECIES_AMPHAROS] = sAmpharosLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MARILL
#if P_GEN_3_CROSS_EVOS
    [SPECIES_AZURILL] = sAzurillLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_MARILL
    [SPECIES_MARILL] = sMarillLevelUpLearnset_KismetGen3,
    [SPECIES_AZUMARILL] = sAzumarillLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SUDOWOODO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BONSLY] = sBonslyLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SUDOWOODO
    [SPECIES_SUDOWOODO] = sSudowoodoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] = sHoppipLevelUpLearnset_KismetGen3,
    [SPECIES_SKIPLOOM] = sSkiploomLevelUpLearnset_KismetGen3,
    [SPECIES_JUMPLUFF] = sJumpluffLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] = sAipomLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_AIPOM
#if P_GEN_4_CROSS_EVOS
    [SPECIES_AMBIPOM] = sAmbipomLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] = sSunkernLevelUpLearnset_KismetGen3,
    [SPECIES_SUNFLORA] = sSunfloraLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_YANMA
    [SPECIES_YANMA] = sYanmaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_YANMA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_YANMEGA] = sYanmegaLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] = sWooperLevelUpLearnset_KismetGen3,
    [SPECIES_QUAGSIRE] = sQuagsireLevelUpLearnset_KismetGen3,
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
    [SPECIES_MISDREAVUS] = sMisdreavusLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MISDREAVUS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MISMAGIUS] = sMismagiusLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_UNOWN
    [SPECIES_UNOWN] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_B] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_C] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_D] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_E] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_EXCLAMATION] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_F] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_H] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_I] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_L] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_M] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_N] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_O] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_P] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_Q] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_QUESTION] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_R] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_S] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_T] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_U] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_V] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_W] = sUnownLevelUpLearnset_KismetGen3,
    [SPECIES_UNOWN_X] = sUnownLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_WOBBUFFET
#if P_GEN_3_CROSS_EVOS
    [SPECIES_WYNAUT] = sWynautLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_WOBBUFFET
    [SPECIES_WOBBUFFET] = sWobbuffetLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] = sGirafarigLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GIRAFARIG
#if P_GEN_9_CROSS_EVOS
    [SPECIES_FARIGIRAF] = sFarigirafLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_PINECO
    [SPECIES_PINECO] = sPinecoLevelUpLearnset_KismetGen3,
    [SPECIES_FORRETRESS] = sForretressLevelUpLearnset_KismetGen3,
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
#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] = sSnubbullLevelUpLearnset_KismetGen3,
    [SPECIES_GRANBULL] = sGranbullLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] = sQwilfishLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossLevelUpLearnset_KismetGen3,
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
    [SPECIES_URSALUNA_BLOODMOON] = sUrsalunaBloodmoonLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] = sSlugmaLevelUpLearnset_KismetGen3,
    [SPECIES_MAGCARGO] = sMagcargoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] = sSwinubLevelUpLearnset_KismetGen3,
    [SPECIES_PILOSWINE] = sPiloswineLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SWINUB
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAMOSWINE] = sMamoswineLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_CORSOLA
    [SPECIES_CORSOLA] = sCorsolaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MANTINE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MANTYKE] = sMantykeLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] = sRemoraidLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MANTINE
    [SPECIES_MANTINE] = sMantineLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REMORAID
    [SPECIES_OCTILLERY] = sOctilleryLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] = sDelibirdLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] = sSkarmoryLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] = sHoundourLevelUpLearnset_KismetGen3,
    [SPECIES_HOUNDOOM] = sHoundoomLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] = sPhanpyLevelUpLearnset_KismetGen3,
    [SPECIES_DONPHAN] = sDonphanLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] = sStantlerLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_STANTLER
#if P_GEN_8_CROSS_EVOS
    [SPECIES_WYRDEER] = sWyrdeerLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SMEARGLE
    [SPECIES_SMEARGLE] = sSmeargleLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] = sMiltankLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RAIKOU
    [SPECIES_RAIKOU] = sRaikouLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ENTEI
    [SPECIES_ENTEI] = sEnteiLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SUICUNE
    [SPECIES_SUICUNE] = sSuicuneLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] = sLarvitarLevelUpLearnset_KismetGen3,
    [SPECIES_PUPITAR] = sPupitarLevelUpLearnset_KismetGen3,
    [SPECIES_TYRANITAR] = sTyranitarLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LUGIA
    [SPECIES_LUGIA] = sLugiaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HO_OH
    [SPECIES_HO_OH] = sHoOhLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CELEBI
    [SPECIES_CELEBI] = sCelebiLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TREECKO
    [SPECIES_TREECKO] = sTreeckoLevelUpLearnset_KismetGen3,
    [SPECIES_GROVYLE] = sGrovyleLevelUpLearnset_KismetGen3,
    [SPECIES_SCEPTILE] = sSceptileLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC] = sTorchicLevelUpLearnset_KismetGen3,
    [SPECIES_COMBUSKEN] = sCombuskenLevelUpLearnset_KismetGen3,
    [SPECIES_BLAZIKEN] = sBlazikenLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MUDKIP
    [SPECIES_MUDKIP] = sMudkipLevelUpLearnset_KismetGen3,
    [SPECIES_MARSHTOMP] = sMarshtompLevelUpLearnset_KismetGen3,
    [SPECIES_SWAMPERT] = sSwampertLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA] = sPoochyenaLevelUpLearnset_KismetGen3,
    [SPECIES_MIGHTYENA] = sMightyenaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ZIGZAGOON
    [SPECIES_ZIGZAGOON] = sZigzagoonLevelUpLearnset_KismetGen3,
    [SPECIES_LINOONE] = sLinooneLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_WURMPLE
    [SPECIES_WURMPLE] = sWurmpleLevelUpLearnset_KismetGen3,
    [SPECIES_SILCOON] = sSilcoonLevelUpLearnset_KismetGen3,
    [SPECIES_CASCOON] = sCascoonLevelUpLearnset_KismetGen3,
    [SPECIES_BEAUTIFLY] = sBeautiflyLevelUpLearnset_KismetGen3,
    [SPECIES_DUSTOX] = sDustoxLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LOTAD
    [SPECIES_LOTAD] = sLotadLevelUpLearnset_KismetGen3,
    [SPECIES_LOMBRE] = sLombreLevelUpLearnset_KismetGen3,
    [SPECIES_LUDICOLO] = sLudicoloLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotLevelUpLearnset_KismetGen3,
    [SPECIES_NUZLEAF] = sNuzleafLevelUpLearnset_KismetGen3,
    [SPECIES_SHIFTRY] = sShiftryLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TAILLOW
    [SPECIES_TAILLOW] = sTaillowLevelUpLearnset_KismetGen3,
    [SPECIES_SWELLOW] = sSwellowLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_WINGULL
    [SPECIES_WINGULL] = sWingullLevelUpLearnset_KismetGen3,
    [SPECIES_PELIPPER] = sPelipperLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RALTS
    [SPECIES_RALTS] = sRaltsLevelUpLearnset_KismetGen3,
    [SPECIES_KIRLIA] = sKirliaLevelUpLearnset_KismetGen3,
    [SPECIES_GARDEVOIR] = sGardevoirLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RALTS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_GALLADE] = sGalladeLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SURSKIT
    [SPECIES_SURSKIT] = sSurskitLevelUpLearnset_KismetGen3,
    [SPECIES_MASQUERAIN] = sMasquerainLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SHROOMISH
    [SPECIES_SHROOMISH] = sShroomishLevelUpLearnset_KismetGen3,
    [SPECIES_BRELOOM] = sBreloomLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] = sSlakothLevelUpLearnset_KismetGen3,
    [SPECIES_VIGOROTH] = sVigorothLevelUpLearnset_KismetGen3,
    [SPECIES_SLAKING] = sSlakingLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_NINCADA
    [SPECIES_NINCADA] = sNincadaLevelUpLearnset_KismetGen3,
    [SPECIES_NINJASK] = sNinjaskLevelUpLearnset_KismetGen3,
    [SPECIES_SHEDINJA] = sShedinjaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_WHISMUR
    [SPECIES_WHISMUR] = sWhismurLevelUpLearnset_KismetGen3,
    [SPECIES_LOUDRED] = sLoudredLevelUpLearnset_KismetGen3,
    [SPECIES_EXPLOUD] = sExploudLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaLevelUpLearnset_KismetGen3,
    [SPECIES_HARIYAMA] = sHariyamaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_NOSEPASS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_PROBOPASS] = sProbopassLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyLevelUpLearnset_KismetGen3,
    [SPECIES_DELCATTY] = sDelcattyLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] = sSableyeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MAWILE
    [SPECIES_MAWILE] = sMawileLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ARON
    [SPECIES_ARON] = sAronLevelUpLearnset_KismetGen3,
    [SPECIES_LAIRON] = sLaironLevelUpLearnset_KismetGen3,
    [SPECIES_AGGRON] = sAggronLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] = sMedititeLevelUpLearnset_KismetGen3,
    [SPECIES_MEDICHAM] = sMedichamLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ELECTRIKE
    [SPECIES_ELECTRIKE] = sElectrikeLevelUpLearnset_KismetGen3,
    [SPECIES_MANECTRIC] = sManectricLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PLUSLE
    [SPECIES_PLUSLE] = sPlusleLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MINUN
    [SPECIES_MINUN] = sMinunLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_VOLBEAT_ILLUMISE
    [SPECIES_VOLBEAT] = sVolbeatLevelUpLearnset_KismetGen3,
    [SPECIES_ILLUMISE] = sIllumiseLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ROSELIA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BUDEW] = sBudewLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_ROSELIA
    [SPECIES_ROSELIA] = sRoseliaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ROSELIA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_ROSERADE] = sRoseradeLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_GULPIN
    [SPECIES_GULPIN] = sGulpinLevelUpLearnset_KismetGen3,
    [SPECIES_SWALOT] = sSwalotLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaLevelUpLearnset_KismetGen3,
    [SPECIES_SHARPEDO] = sSharpedoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] = sWailmerLevelUpLearnset_KismetGen3,
    [SPECIES_WAILORD] = sWailordLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_NUMEL
    [SPECIES_NUMEL] = sNumelLevelUpLearnset_KismetGen3,
    [SPECIES_CAMERUPT] = sCameruptLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] = sTorkoalLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] = sSpoinkLevelUpLearnset_KismetGen3,
    [SPECIES_GRUMPIG] = sGrumpigLevelUpLearnset_KismetGen3,
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
#if P_FAMILY_SWABLU
    [SPECIES_SWABLU] = sSwabluLevelUpLearnset_KismetGen3,
    [SPECIES_ALTARIA] = sAltariaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ZANGOOSE
    [SPECIES_ZANGOOSE] = sZangooseLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SEVIPER
    [SPECIES_SEVIPER] = sSeviperLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LUNATONE
    [SPECIES_LUNATONE] = sLunatoneLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SOLROCK
    [SPECIES_SOLROCK] = sSolrockLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BARBOACH
    [SPECIES_BARBOACH] = sBarboachLevelUpLearnset_KismetGen3,
    [SPECIES_WHISCASH] = sWhiscashLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] = sCorphishLevelUpLearnset_KismetGen3,
    [SPECIES_CRAWDAUNT] = sCrawdauntLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BALTOY
    [SPECIES_BALTOY] = sBaltoyLevelUpLearnset_KismetGen3,
    [SPECIES_CLAYDOL] = sClaydolLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] = sLileepLevelUpLearnset_KismetGen3,
    [SPECIES_CRADILY] = sCradilyLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ANORITH
    [SPECIES_ANORITH] = sAnorithLevelUpLearnset_KismetGen3,
    [SPECIES_ARMALDO] = sArmaldoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_FEEBAS
    [SPECIES_FEEBAS] = sFeebasLevelUpLearnset_KismetGen3,
    [SPECIES_MILOTIC] = sMiloticLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CASTFORM
    [SPECIES_CASTFORM] = sCastformLevelUpLearnset_KismetGen3,
    [SPECIES_CASTFORM_NORMAL] = sCastformLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_KECLEON
    [SPECIES_KECLEON] = sKecleonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] = sShuppetLevelUpLearnset_KismetGen3,
    [SPECIES_BANETTE] = sBanetteLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DUSKULL
    [SPECIES_DUSKULL] = sDuskullLevelUpLearnset_KismetGen3,
    [SPECIES_DUSCLOPS] = sDusclopsLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DUSKULL
#if P_GEN_4_CROSS_EVOS
    [SPECIES_DUSKNOIR] = sDusknoirLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CHIMECHO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_CHINGLING] = sChinglingLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_CHIMECHO
    [SPECIES_CHIMECHO] = sChimechoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntLevelUpLearnset_KismetGen3,
    [SPECIES_GLALIE] = sGlalieLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SNORUNT
#if P_GEN_4_CROSS_EVOS
    [SPECIES_FROSLASS] = sFroslassLevelUpLearnset_KismetGen3,
#endif
#endif
#if P_FAMILY_SPHEAL
    [SPECIES_SPHEAL] = sSphealLevelUpLearnset_KismetGen3,
    [SPECIES_SEALEO] = sSealeoLevelUpLearnset_KismetGen3,
    [SPECIES_WALREIN] = sWalreinLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] = sClamperlLevelUpLearnset_KismetGen3,
    [SPECIES_HUNTAIL] = sHuntailLevelUpLearnset_KismetGen3,
    [SPECIES_GOREBYSS] = sGorebyssLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] = sLuvdiscLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BAGON
    [SPECIES_BAGON] = sBagonLevelUpLearnset_KismetGen3,
    [SPECIES_SHELGON] = sShelgonLevelUpLearnset_KismetGen3,
    [SPECIES_SALAMENCE] = sSalamenceLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BELDUM
    [SPECIES_BELDUM] = sBeldumLevelUpLearnset_KismetGen3,
    [SPECIES_METANG] = sMetangLevelUpLearnset_KismetGen3,
    [SPECIES_METAGROSS] = sMetagrossLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGIROCK
    [SPECIES_REGIROCK] = sRegirockLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGICE
    [SPECIES_REGICE] = sRegiceLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGISTEEL
    [SPECIES_REGISTEEL] = sRegisteelLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LATIAS
    [SPECIES_LATIAS] = sLatiasLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_LATIOS
    [SPECIES_LATIOS] = sLatiosLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_KYOGRE
    [SPECIES_KYOGRE] = sKyogreLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GROUDON
    [SPECIES_GROUDON] = sGroudonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_RAYQUAZA
    [SPECIES_RAYQUAZA] = sRayquazaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_JIRACHI
    [SPECIES_JIRACHI] = sJirachiLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DEOXYS
    [SPECIES_DEOXYS_NORMAL] = sDeoxysNormalLevelUpLearnset_KismetGen3,
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
#if P_FAMILY_STARLY
    [SPECIES_STARLY] = sStarlyLevelUpLearnset_KismetGen3,
    [SPECIES_STARAVIA] = sStaraviaLevelUpLearnset_KismetGen3,
    [SPECIES_STARAPTOR] = sStaraptorLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SHINX
    [SPECIES_SHINX] = sShinxLevelUpLearnset_KismetGen3,
    [SPECIES_LUXIO] = sLuxioLevelUpLearnset_KismetGen3,
    [SPECIES_LUXRAY] = sLuxrayLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CRANIDOS
    [SPECIES_CRANIDOS] = sCranidosLevelUpLearnset_KismetGen3,
    [SPECIES_RAMPARDOS] = sRampardosLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SHIELDON
    [SPECIES_SHIELDON] = sShieldonLevelUpLearnset_KismetGen3,
    [SPECIES_BASTIODON] = sBastiodonLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BURMY
    [SPECIES_BURMY] = sBurmyLevelUpLearnset_KismetGen3,
    [SPECIES_WORMADAM_PLANT] = sWormadamPlantLevelUpLearnset_KismetGen3,
    [SPECIES_WORMADAM_SANDY] = sWormadamSandyLevelUpLearnset_KismetGen3,
    [SPECIES_WORMADAM_TRASH] = sWormadamTrashLevelUpLearnset_KismetGen3,
    [SPECIES_MOTHIM] = sMothimLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_COMBEE
    [SPECIES_COMBEE] = sCombeeLevelUpLearnset_KismetGen3,
    [SPECIES_VESPIQUEN] = sVespiquenLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BUIZEL
    [SPECIES_BUIZEL] = sBuizelLevelUpLearnset_KismetGen3,
    [SPECIES_FLOATZEL] = sFloatzelLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DRIFLOON
    [SPECIES_DRIFLOON] = sDrifloonLevelUpLearnset_KismetGen3,
    [SPECIES_DRIFBLIM] = sDrifblimLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BUNEARY
    [SPECIES_BUNEARY] = sBunearyLevelUpLearnset_KismetGen3,
    [SPECIES_LOPUNNY] = sLopunnyLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GLAMEOW
    [SPECIES_GLAMEOW] = sGlameowLevelUpLearnset_KismetGen3,
    [SPECIES_PURUGLY] = sPuruglyLevelUpLearnset_KismetGen3,
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
#if P_FAMILY_CROAGUNK
    [SPECIES_CROAGUNK] = sCroagunkLevelUpLearnset_KismetGen3,
    [SPECIES_TOXICROAK] = sToxicroakLevelUpLearnset_KismetGen3,
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
    [SPECIES_ARCEUS] = sArceusLevelUpLearnset_KismetGen3,
    [SPECIES_ARCEUS_STEEL] = sArceusLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] = sRoggenrolaLevelUpLearnset_KismetGen3,
    [SPECIES_BOLDORE] = sBoldoreLevelUpLearnset_KismetGen3,
    [SPECIES_GIGALITH] = sGigalithLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SANDILE
    [SPECIES_KROOKODILE] = sKrookodileLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DARUMAKA
    [SPECIES_DARUMAKA] = sDarumakaLevelUpLearnset_KismetGen3,
    [SPECIES_DARMANITAN] = sDarmanitanLevelUpLearnset_KismetGen3,
    [SPECIES_DARMANITAN_STANDARD] = sDarmanitanLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ZORUA
    [SPECIES_ZORUA] = sZoruaLevelUpLearnset_KismetGen3,
    [SPECIES_ZOROARK] = sZoroarkLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteLevelUpLearnset_KismetGen3,
    [SPECIES_VANILLISH] = sVanillishLevelUpLearnset_KismetGen3,
    [SPECIES_VANILLUXE] = sVanilluxeLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] = sEmolgaLevelUpLearnset_KismetGen3,
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
#if P_FAMILY_CRYOGONAL
    [SPECIES_CRYOGONAL] = sCryogonalLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooLevelUpLearnset_KismetGen3,
    [SPECIES_MIENSHAO] = sMienshaoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GOLETT
    [SPECIES_GOLETT] = sGolettLevelUpLearnset_KismetGen3,
    [SPECIES_GOLURK] = sGolurkLevelUpLearnset_KismetGen3,
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
    [SPECIES_FLETCHINDER] = sFletchinderLevelUpLearnset_KismetGen3,
    [SPECIES_TALONFLAME] = sTalonflameLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_FLABEBE
    [SPECIES_FLABEBE] = sFlabebeLevelUpLearnset_KismetGen3,
    [SPECIES_FLOETTE] = sFloetteLevelUpLearnset_KismetGen3,
    [SPECIES_FLORGES] = sFlorgesLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] = sPanchamLevelUpLearnset_KismetGen3,
    [SPECIES_PANGORO] = sPangoroLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_HONEDGE
    [SPECIES_HONEDGE] = sHonedgeLevelUpLearnset_KismetGen3,
    [SPECIES_DOUBLADE] = sDoubladeLevelUpLearnset_KismetGen3,
    [SPECIES_AEGISLASH] = sAegislashLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CARBINK
    [SPECIES_CARBINK] = sCarbinkLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_NOIBAT
    [SPECIES_NOIBAT] = sNoibatLevelUpLearnset_KismetGen3,
    [SPECIES_NOIVERN] = sNoivernLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_ROCKRUFF
    [SPECIES_ROCKRUFF] = sRockruffLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisLevelUpLearnset_KismetGen3,
    [SPECIES_LURANTIS] = sLurantisLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_STUFFUL
    [SPECIES_STUFFUL] = sStuffulLevelUpLearnset_KismetGen3,
    [SPECIES_BEWEAR] = sBewearLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_BOUNSWEET
    [SPECIES_BOUNSWEET] = sBounsweetLevelUpLearnset_KismetGen3,
    [SPECIES_STEENEE] = sSteeneeLevelUpLearnset_KismetGen3,
    [SPECIES_TSAREENA] = sTsareenaLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MIMIKYU
    [SPECIES_MIMIKYU] = sMimikyuLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TAPU_KOKO
    [SPECIES_TAPU_KOKO] = sTapuKokoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TAPU_LELE
    [SPECIES_TAPU_LELE] = sTapuLeleLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TAPU_BULU
    [SPECIES_TAPU_BULU] = sTapuBuluLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_TAPU_FINI
    [SPECIES_TAPU_FINI] = sTapuFiniLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SINISTEA
    [SPECIES_SINISTEA] = sSinisteaLevelUpLearnset_KismetGen3,
    [SPECIES_POLTEAGEIST] = sPolteageistLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] = sImpidimpLevelUpLearnset_KismetGen3,
    [SPECIES_MORGREM] = sMorgremLevelUpLearnset_KismetGen3,
    [SPECIES_GRIMMSNARL] = sGrimmsnarlLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_MILCERY
    [SPECIES_MILCERY] = sMilceryLevelUpLearnset_KismetGen3,
    [SPECIES_ALCREMIE] = sAlcremieLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_SNOM
    [SPECIES_SNOM] = sSnomLevelUpLearnset_KismetGen3,
    [SPECIES_FROSMOTH] = sFrosmothLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGIELEKI
    [SPECIES_REGIELEKI] = sRegielekiLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_REGIDRAGO
    [SPECIES_REGIDRAGO] = sRegidragoLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_WATTREL
    [SPECIES_WATTREL] = sWattrelLevelUpLearnset_KismetGen3,
    [SPECIES_KILOWATTREL] = sKilowattrelLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_KLAWF
    [SPECIES_KLAWF] = sKlawfLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_CAPSAKID
    [SPECIES_CAPSAKID] = sCapsakidLevelUpLearnset_KismetGen3,
    [SPECIES_SCOVILLAIN] = sScovillainLevelUpLearnset_KismetGen3,
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
#if P_FAMILY_GLIMMET
    [SPECIES_GLIMMET] = sGlimmetLevelUpLearnset_KismetGen3,
    [SPECIES_GLIMMORA] = sGlimmoraLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardLevelUpLearnset_KismetGen3,
    [SPECIES_HOUNDSTONE] = sHoundstoneLevelUpLearnset_KismetGen3,
#endif
#if P_FAMILY_DUNSPARCE
#if P_GEN_9_CROSS_EVOS
    [SPECIES_DUDUNSPARCE] = sDudunsparceLevelUpLearnset_KismetGen3,
    [SPECIES_DUDUNSPARCE_THREE_SEGMENT] = sDudunsparceLevelUpLearnset_KismetGen3,
#endif
#endif
};
