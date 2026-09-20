#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "teachable_learnsets_kismet.h"

// NULL means "the fork did not retune this species", which
// GetSpeciesTeachableLearnset reads as "use the generated list".
// NUM_SPECIES + 1: NUM_SPECIES == SPECIES_EGG and SanitizeSpeciesId
// returns it unchanged, so a bare NUM_SPECIES sizing lets an egg
// read one element past the end.
const u16 *const gTeachableLearnsets_Kismet[NUM_SPECIES + 1] = {
#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR] = sBulbasaurTeachableLearnset_Kismet,
    [SPECIES_IVYSAUR] = sBulbasaurTeachableLearnset_Kismet,
    [SPECIES_VENUSAUR] = sVenusaurTeachableLearnset_Kismet,
    [SPECIES_VENUSAUR_MEGA] = sVenusaurTeachableLearnset_Kismet,
    [SPECIES_VENUSAUR_GMAX] = sVenusaurTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] = sCharmanderTeachableLearnset_Kismet,
    [SPECIES_CHARMELEON] = sCharmanderTeachableLearnset_Kismet,
    [SPECIES_CHARIZARD] = sCharizardTeachableLearnset_Kismet,
    [SPECIES_CHARIZARD_MEGA_X] = sCharizardTeachableLearnset_Kismet,
    [SPECIES_CHARIZARD_MEGA_Y] = sCharizardTeachableLearnset_Kismet,
    [SPECIES_CHARIZARD_GMAX] = sCharizardTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SQUIRTLE
    [SPECIES_SQUIRTLE] = sSquirtleTeachableLearnset_Kismet,
    [SPECIES_WARTORTLE] = sWartortleTeachableLearnset_Kismet,
    [SPECIES_BLASTOISE] = sBlastoiseTeachableLearnset_Kismet,
    [SPECIES_BLASTOISE_MEGA] = sBlastoiseTeachableLearnset_Kismet,
    [SPECIES_BLASTOISE_GMAX] = sBlastoiseTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CATERPIE
    [SPECIES_CATERPIE] = sCaterpieTeachableLearnset_Kismet,
    [SPECIES_METAPOD] = sCaterpieTeachableLearnset_Kismet,
    [SPECIES_BUTTERFREE] = sButterfreeTeachableLearnset_Kismet,
    [SPECIES_BUTTERFREE_GMAX] = sButterfreeTeachableLearnset_Kismet,
#endif
#if P_FAMILY_WEEDLE
    [SPECIES_WEEDLE] = sWeedleTeachableLearnset_Kismet,
    [SPECIES_KAKUNA] = sWeedleTeachableLearnset_Kismet,
    [SPECIES_BEEDRILL] = sBeedrillTeachableLearnset_Kismet,
    [SPECIES_BEEDRILL_MEGA] = sBeedrillTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PIDGEY
    [SPECIES_PIDGEY] = sPidgeyTeachableLearnset_Kismet,
    [SPECIES_PIDGEOTTO] = sPidgeyTeachableLearnset_Kismet,
    [SPECIES_PIDGEOT] = sPidgeotTeachableLearnset_Kismet,
    [SPECIES_PIDGEOT_MEGA] = sPidgeotTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RATTATA
    [SPECIES_RATTATA] = sRattataTeachableLearnset_Kismet,
    [SPECIES_RATICATE] = sRaticateTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowTeachableLearnset_Kismet,
    [SPECIES_FEAROW] = sFearowTeachableLearnset_Kismet,
#endif
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansTeachableLearnset_Kismet,
    [SPECIES_ARBOK] = sArbokTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PICHU] = sPichuTeachableLearnset_Kismet,
    [SPECIES_PICHU_SPIKY_EARED] = sPichuTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PIKACHU
    [SPECIES_PIKACHU] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_COSPLAY] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_ROCK_STAR] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_BELLE] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_POP_STAR] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_PHD] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_LIBRE] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_ORIGINAL] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_HOENN] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_SINNOH] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_UNOVA] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_KALOS] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_ALOLA] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_PARTNER] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_WORLD] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_GMAX] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_PIKACHU_STARTER] = sPikachuTeachableLearnset_Kismet,
    [SPECIES_RAICHU] = sRaichuTeachableLearnset_Kismet,
    [SPECIES_RAICHU_MEGA_X] = sRaichuTeachableLearnset_Kismet,
    [SPECIES_RAICHU_MEGA_Y] = sRaichuTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewTeachableLearnset_Kismet,
    [SPECIES_SANDSLASH] = sSandslashTeachableLearnset_Kismet,
#endif
#if P_FAMILY_NIDORAN
    [SPECIES_NIDORAN_F] = sNidoranFTeachableLearnset_Kismet,
    [SPECIES_NIDORINA] = sNidorinaTeachableLearnset_Kismet,
    [SPECIES_NIDOQUEEN] = sNidoqueenTeachableLearnset_Kismet,
    [SPECIES_NIDORAN_M] = sNidoranMTeachableLearnset_Kismet,
    [SPECIES_NIDORINO] = sNidorinoTeachableLearnset_Kismet,
    [SPECIES_NIDOKING] = sNidokingTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CLEFAIRY
#if P_GEN_2_CROSS_EVOS
    [SPECIES_CLEFFA] = sCleffaTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CLEFAIRY
    [SPECIES_CLEFAIRY] = sClefairyTeachableLearnset_Kismet,
    [SPECIES_CLEFABLE] = sClefableTeachableLearnset_Kismet,
    [SPECIES_CLEFABLE_MEGA] = sClefableTeachableLearnset_Kismet,
#endif
#if P_FAMILY_VULPIX
    [SPECIES_VULPIX] = sVulpixTeachableLearnset_Kismet,
    [SPECIES_NINETALES] = sNinetalesTeachableLearnset_Kismet,
#endif
#if P_FAMILY_JIGGLYPUFF
#if P_GEN_2_CROSS_EVOS
    [SPECIES_IGGLYBUFF] = sIgglybuffTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_JIGGLYPUFF
    [SPECIES_JIGGLYPUFF] = sJigglypuffTeachableLearnset_Kismet,
    [SPECIES_WIGGLYTUFF] = sWigglytuffTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ZUBAT
    [SPECIES_ZUBAT] = sZubatTeachableLearnset_Kismet,
    [SPECIES_GOLBAT] = sGolbatTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ZUBAT
#if P_GEN_2_CROSS_EVOS
    [SPECIES_CROBAT] = sCrobatTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_ODDISH
    [SPECIES_ODDISH] = sOddishTeachableLearnset_Kismet,
    [SPECIES_GLOOM] = sGloomTeachableLearnset_Kismet,
    [SPECIES_VILEPLUME] = sVileplumeTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ODDISH
#if P_GEN_2_CROSS_EVOS
    [SPECIES_BELLOSSOM] = sBellossomTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PARAS
    [SPECIES_PARAS] = sParasTeachableLearnset_Kismet,
    [SPECIES_PARASECT] = sParasectTeachableLearnset_Kismet,
#endif
#if P_FAMILY_VENONAT
    [SPECIES_VENONAT] = sVenonatTeachableLearnset_Kismet,
    [SPECIES_VENOMOTH] = sVenomothTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DIGLETT
    [SPECIES_DIGLETT] = sDiglettTeachableLearnset_Kismet,
    [SPECIES_DUGTRIO] = sDugtrioTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthTeachableLearnset_Kismet,
    [SPECIES_MEOWTH_GMAX] = sMeowthTeachableLearnset_Kismet,
    [SPECIES_PERSIAN] = sPersianTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PSYDUCK
    [SPECIES_PSYDUCK] = sPsyduckTeachableLearnset_Kismet,
    [SPECIES_GOLDUCK] = sGolduckTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MANKEY
    [SPECIES_MANKEY] = sMankeyTeachableLearnset_Kismet,
    [SPECIES_PRIMEAPE] = sPrimeapeTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MANKEY
#if P_GEN_9_CROSS_EVOS
    [SPECIES_ANNIHILAPE] = sAnnihilapeTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_GROWLITHE
    [SPECIES_GROWLITHE] = sGrowlitheTeachableLearnset_Kismet,
    [SPECIES_ARCANINE] = sArcanineTeachableLearnset_Kismet,
#endif
#if P_FAMILY_POLIWAG
    [SPECIES_POLIWAG] = sPoliwagTeachableLearnset_Kismet,
    [SPECIES_POLIWHIRL] = sPoliwhirlTeachableLearnset_Kismet,
    [SPECIES_POLIWRATH] = sPoliwrathTeachableLearnset_Kismet,
#endif
#if P_FAMILY_POLIWAG
#if P_GEN_2_CROSS_EVOS
    [SPECIES_POLITOED] = sPolitoedTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_ABRA
    [SPECIES_ABRA] = sAbraTeachableLearnset_Kismet,
    [SPECIES_KADABRA] = sKadabraTeachableLearnset_Kismet,
    [SPECIES_ALAKAZAM] = sAlakazamTeachableLearnset_Kismet,
    [SPECIES_ALAKAZAM_MEGA] = sAlakazamTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MACHOP
    [SPECIES_MACHOP] = sMachopTeachableLearnset_Kismet,
    [SPECIES_MACHOKE] = sMachopTeachableLearnset_Kismet,
    [SPECIES_MACHAMP] = sMachampTeachableLearnset_Kismet,
    [SPECIES_MACHAMP_GMAX] = sMachampTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BELLSPROUT
    [SPECIES_BELLSPROUT] = sBellsproutTeachableLearnset_Kismet,
    [SPECIES_WEEPINBELL] = sWeepinbellTeachableLearnset_Kismet,
    [SPECIES_VICTREEBEL] = sVictreebelTeachableLearnset_Kismet,
    [SPECIES_VICTREEBEL_MEGA] = sVictreebelTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TENTACOOL
    [SPECIES_TENTACOOL] = sTentacoolTeachableLearnset_Kismet,
    [SPECIES_TENTACRUEL] = sTentacruelTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GEODUDE
    [SPECIES_GEODUDE] = sGeodudeTeachableLearnset_Kismet,
    [SPECIES_GRAVELER] = sGravelerTeachableLearnset_Kismet,
    [SPECIES_GOLEM] = sGolemTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaTeachableLearnset_Kismet,
    [SPECIES_RAPIDASH] = sRapidashTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeTeachableLearnset_Kismet,
    [SPECIES_SLOWBRO] = sSlowbroTeachableLearnset_Kismet,
    [SPECIES_SLOWBRO_MEGA] = sSlowbroTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SLOWPOKE
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SLOWKING] = sSlowkingTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MAGNEMITE
    [SPECIES_MAGNEMITE] = sMagnemiteTeachableLearnset_Kismet,
    [SPECIES_MAGNETON] = sMagnetonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MAGNEMITE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGNEZONE] = sMagnezoneTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdTeachableLearnset_Kismet,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_MLLOY] = sMlloyTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DODUO
    [SPECIES_DODUO] = sDoduoTeachableLearnset_Kismet,
    [SPECIES_DODRIO] = sDodrioTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SEEL
    [SPECIES_SEEL] = sSeelTeachableLearnset_Kismet,
    [SPECIES_DEWGONG] = sDewgongTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GRIMER
    [SPECIES_GRIMER] = sGrimerTeachableLearnset_Kismet,
    [SPECIES_MUK] = sMukTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SHELLDER
    [SPECIES_SHELLDER] = sShellderTeachableLearnset_Kismet,
    [SPECIES_CLOYSTER] = sCloysterTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GASTLY
    [SPECIES_GASTLY] = sGastlyTeachableLearnset_Kismet,
    [SPECIES_HAUNTER] = sHaunterTeachableLearnset_Kismet,
    [SPECIES_GENGAR] = sGengarTeachableLearnset_Kismet,
    [SPECIES_GENGAR_MEGA] = sGengarTeachableLearnset_Kismet,
    [SPECIES_GENGAR_GMAX] = sGengarTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ONIX
    [SPECIES_ONIX] = sOnixTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ONIX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_STEELIX] = sSteelixTeachableLearnset_Kismet,
    [SPECIES_STEELIX_MEGA] = sSteelixTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_DROWZEE
    [SPECIES_DROWZEE] = sDrowzeeTeachableLearnset_Kismet,
    [SPECIES_HYPNO] = sHypnoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] = sKrabbyTeachableLearnset_Kismet,
    [SPECIES_KINGLER] = sKinglerTeachableLearnset_Kismet,
    [SPECIES_KINGLER_GMAX] = sKinglerTeachableLearnset_Kismet,
#endif
#if P_FAMILY_VOLTORB
    [SPECIES_VOLTORB] = sVoltorbTeachableLearnset_Kismet,
    [SPECIES_ELECTRODE] = sElectrodeTeachableLearnset_Kismet,
#endif
#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] = sExeggcuteTeachableLearnset_Kismet,
    [SPECIES_EXEGGUTOR] = sExeggutorTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CUBONE
    [SPECIES_CUBONE] = sCuboneTeachableLearnset_Kismet,
    [SPECIES_MAROWAK] = sMarowakTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
    [SPECIES_TYROGUE] = sTyrogueTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_HITMONS
    [SPECIES_HITMONLEE] = sHitmonleeTeachableLearnset_Kismet,
    [SPECIES_HITMONCHAN] = sHitmonchanTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
    [SPECIES_HITMONTOP] = sHitmontopTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_LICKITUNG
    [SPECIES_LICKITUNG] = sLickitungTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LICKITUNG
#if P_GEN_4_CROSS_EVOS
    [SPECIES_LICKILICKY] = sLickilickyTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_KOFFING
    [SPECIES_KOFFING] = sKoffingTeachableLearnset_Kismet,
    [SPECIES_WEEZING] = sWeezingTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RHYHORN
    [SPECIES_RHYHORN] = sRhyhornTeachableLearnset_Kismet,
    [SPECIES_RHYDON] = sRhydonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RHYHORN
#if P_GEN_4_CROSS_EVOS
    [SPECIES_RHYPERIOR] = sRhyperiorTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CHANSEY
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HAPPINY] = sHappinyTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CHANSEY
    [SPECIES_CHANSEY] = sChanseyTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CHANSEY
#if P_GEN_2_CROSS_EVOS
    [SPECIES_BLISSEY] = sBlisseyTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TANGELA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_TANGROWTH] = sTangrowthTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanTeachableLearnset_Kismet,
    [SPECIES_KANGASKHAN_MEGA] = sKangaskhanTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HORSEA
    [SPECIES_HORSEA] = sHorseaTeachableLearnset_Kismet,
    [SPECIES_SEADRA] = sSeadraTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HORSEA
#if P_GEN_2_CROSS_EVOS
    [SPECIES_KINGDRA] = sKingdraTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_GOLDEEN
    [SPECIES_GOLDEEN] = sGoldeenTeachableLearnset_Kismet,
    [SPECIES_SEAKING] = sSeakingTeachableLearnset_Kismet,
#endif
#if P_FAMILY_STARYU
    [SPECIES_STARYU] = sStaryuTeachableLearnset_Kismet,
    [SPECIES_STARMIE] = sStarmieTeachableLearnset_Kismet,
    [SPECIES_STARMIE_MEGA] = sStarmieTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MR_MIME
    [SPECIES_MR_MIME] = sMrMimeTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SCYTHER
    [SPECIES_SCYTHER] = sScytherTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SCYTHER
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SCIZOR] = sScizorTeachableLearnset_Kismet,
    [SPECIES_SCIZOR_MEGA] = sScizorTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SCYTHER
#if P_GEN_8_CROSS_EVOS
    [SPECIES_KLEAVOR] = sKleavorTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_JYNX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SMOOCHUM] = sSmoochumTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_JYNX
    [SPECIES_JYNX] = sJynxTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ELECTABUZZ
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ELEKID] = sElekidTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_ELECTABUZZ
    [SPECIES_ELECTABUZZ] = sElectabuzzTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ELECTABUZZ
#if P_GEN_4_CROSS_EVOS
    [SPECIES_ELECTIVIRE] = sElectivireTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_2_CROSS_EVOS
    [SPECIES_MAGBY] = sMagbyTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MAGMAR
    [SPECIES_MAGMAR] = sMagmarTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MAGMAR
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGMORTAR] = sMagmortarTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirTeachableLearnset_Kismet,
    [SPECIES_PINSIR_MEGA] = sPinsirTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TAUROS
    [SPECIES_TAUROS] = sTaurosTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MAGIKARP
    [SPECIES_MAGIKARP] = sMagikarpTeachableLearnset_Kismet,
    [SPECIES_GYARADOS] = sGyaradosTeachableLearnset_Kismet,
    [SPECIES_GYARADOS_MEGA] = sGyaradosTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasTeachableLearnset_Kismet,
    [SPECIES_LAPRAS_GMAX] = sLaprasTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DITTO
    [SPECIES_DITTO] = sDittoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeTeachableLearnset_Kismet,
    [SPECIES_EEVEE_GMAX] = sEeveeTeachableLearnset_Kismet,
    [SPECIES_EEVEE_STARTER] = sEeveeTeachableLearnset_Kismet,
    [SPECIES_VAPOREON] = sVaporeonTeachableLearnset_Kismet,
    [SPECIES_JOLTEON] = sJolteonTeachableLearnset_Kismet,
    [SPECIES_FLAREON] = sFlareonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_EEVEE
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ESPEON] = sEspeonTeachableLearnset_Kismet,
    [SPECIES_UMBREON] = sUmbreonTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_EEVEE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_LEAFEON] = sLeafeonTeachableLearnset_Kismet,
    [SPECIES_GLACEON] = sGlaceonTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_EEVEE
#if P_GEN_6_CROSS_EVOS
    [SPECIES_SYLVEON] = sSylveonTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PORYGON
    [SPECIES_PORYGON] = sPorygonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PORYGON
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PORYGON2] = sPorygon2TeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PORYGON
#if P_GEN_2_CROSS_EVOS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_PORYGON_Z] = sPorygonZTeachableLearnset_Kismet,
#endif
#endif
#endif
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteTeachableLearnset_Kismet,
    [SPECIES_OMASTAR] = sOmastarTeachableLearnset_Kismet,
#endif
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoTeachableLearnset_Kismet,
    [SPECIES_KABUTOPS] = sKabutopsTeachableLearnset_Kismet,
#endif
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylTeachableLearnset_Kismet,
    [SPECIES_AERODACTYL_MEGA] = sAerodactylTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SNORLAX
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MUNCHLAX] = sMunchlaxTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SNORLAX
    [SPECIES_SNORLAX] = sSnorlaxTeachableLearnset_Kismet,
    [SPECIES_SNORLAX_GMAX] = sSnorlaxTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ARTICUNO
    [SPECIES_ARTICUNO] = sArticunoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ZAPDOS
    [SPECIES_ZAPDOS] = sZapdosTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MOLTRES
    [SPECIES_MOLTRES] = sMoltresTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DRATINI
    [SPECIES_DRATINI] = sDratiniTeachableLearnset_Kismet,
    [SPECIES_DRAGONAIR] = sDratiniTeachableLearnset_Kismet,
    [SPECIES_DRAGONITE] = sDragoniteTeachableLearnset_Kismet,
    [SPECIES_DRAGONITE_MEGA] = sDragoniteTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MEWTWO
    [SPECIES_MEWTWO] = sMewtwoTeachableLearnset_Kismet,
    [SPECIES_MEWTWO_MEGA_X] = sMewtwoTeachableLearnset_Kismet,
    [SPECIES_MEWTWO_MEGA_Y] = sMewtwoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MEW
    [SPECIES_MEW] = sMewTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] = sChikoritaTeachableLearnset_Kismet,
    [SPECIES_BAYLEEF] = sBayleefTeachableLearnset_Kismet,
    [SPECIES_MEGANIUM] = sMeganiumTeachableLearnset_Kismet,
    [SPECIES_MEGANIUM_MEGA] = sMeganiumTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] = sCyndaquilTeachableLearnset_Kismet,
    [SPECIES_QUILAVA] = sQuilavaTeachableLearnset_Kismet,
    [SPECIES_TYPHLOSION] = sTyphlosionTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] = sTotodileTeachableLearnset_Kismet,
    [SPECIES_CROCONAW] = sCroconawTeachableLearnset_Kismet,
    [SPECIES_FERALIGATR] = sFeraligatrTeachableLearnset_Kismet,
    [SPECIES_FERALIGATR_MEGA] = sFeraligatrTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] = sSentretTeachableLearnset_Kismet,
    [SPECIES_FURRET] = sFurretTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] = sHoothootTeachableLearnset_Kismet,
    [SPECIES_NOCTOWL] = sNoctowlTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] = sLedybaTeachableLearnset_Kismet,
    [SPECIES_LEDIAN] = sLedianTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] = sSpinarakTeachableLearnset_Kismet,
    [SPECIES_ARIADOS] = sAriadosTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] = sChinchouTeachableLearnset_Kismet,
    [SPECIES_LANTURN] = sLanturnTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TOGEPI
    [SPECIES_TOGEPI] = sTogepiTeachableLearnset_Kismet,
    [SPECIES_TOGETIC] = sTogeticTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TOGEPI
#if P_GEN_4_CROSS_EVOS
    [SPECIES_TOGEKISS] = sTogekissTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_NATU
    [SPECIES_NATU] = sNatuTeachableLearnset_Kismet,
    [SPECIES_XATU] = sXatuTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] = sMareepTeachableLearnset_Kismet,
    [SPECIES_FLAAFFY] = sFlaaffyTeachableLearnset_Kismet,
    [SPECIES_AMPHAROS] = sAmpharosTeachableLearnset_Kismet,
    [SPECIES_AMPHAROS_MEGA] = sAmpharosTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MARILL
#if P_GEN_3_CROSS_EVOS
    [SPECIES_AZURILL] = sAzurillTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MARILL
    [SPECIES_MARILL] = sMarillTeachableLearnset_Kismet,
    [SPECIES_AZUMARILL] = sAzumarillTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SUDOWOODO
    [SPECIES_SUDOWOODO] = sSudowoodoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] = sHoppipTeachableLearnset_Kismet,
    [SPECIES_SKIPLOOM] = sHoppipTeachableLearnset_Kismet,
    [SPECIES_JUMPLUFF] = sJumpluffTeachableLearnset_Kismet,
#endif
#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] = sAipomTeachableLearnset_Kismet,
#endif
#if P_FAMILY_AIPOM
#if P_GEN_4_CROSS_EVOS
    [SPECIES_AMBIPOM] = sAmbipomTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] = sSunkernTeachableLearnset_Kismet,
    [SPECIES_SUNFLORA] = sSunfloraTeachableLearnset_Kismet,
#endif
#if P_FAMILY_YANMA
    [SPECIES_YANMA] = sYanmaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_YANMA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_YANMEGA] = sYanmegaTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] = sWooperTeachableLearnset_Kismet,
    [SPECIES_QUAGSIRE] = sQuagsireTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] = sMurkrowTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MURKROW
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HONCHKROW] = sHonchkrowTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_MISDREAVUS
    [SPECIES_MISDREAVUS] = sMisdreavusTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MISDREAVUS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MISMAGIUS] = sMismagiusTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_UNOWN
    [SPECIES_UNOWN] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_EXCLAMATION] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_QUESTION] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_B] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_C] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_D] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_E] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_F] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_G] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_H] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_I] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_J] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_K] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_L] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_M] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_N] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_O] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_P] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_Q] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_R] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_S] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_T] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_U] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_V] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_W] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_X] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_Y] = sUnownTeachableLearnset_Kismet,
    [SPECIES_UNOWN_Z] = sUnownTeachableLearnset_Kismet,
#endif
#if P_FAMILY_WOBBUFFET
#if P_GEN_3_CROSS_EVOS
    [SPECIES_WYNAUT] = sWynautTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_WOBBUFFET
    [SPECIES_WOBBUFFET] = sWobbuffetTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] = sGirafarigTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GIRAFARIG
#if P_GEN_9_CROSS_EVOS
    [SPECIES_FARIGIRAF] = sFarigirafTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_PINECO
    [SPECIES_PINECO] = sPinecoTeachableLearnset_Kismet,
    [SPECIES_FORRETRESS] = sForretressTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] = sDunsparceTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DUNSPARCE
#if P_GEN_9_CROSS_EVOS
    [SPECIES_DUDUNSPARCE_THREE_SEGMENT] = sDudunsparceThreeSegmentTeachableLearnset_Kismet,
    [SPECIES_DUDUNSPARCE_TWO_SEGMENT] = sDudunsparceThreeSegmentTeachableLearnset_Kismet,
    [SPECIES_DUDUNSPARCE] = sDudunsparceThreeSegmentTeachableLearnset_Kismet,
#endif
#endif
#if P_KISMET_FAKEMON
    [SPECIES_DUNDRAG] = sDundragTeachableLearnset_Kismet,
    [SPECIES_DUNLONG] = sDundragTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] = sGligarTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GLIGAR
#if P_GEN_4_CROSS_EVOS
    [SPECIES_GLISCOR] = sGliscorTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] = sSnubbullTeachableLearnset_Kismet,
    [SPECIES_GRANBULL] = sGranbullTeachableLearnset_Kismet,
#endif
#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] = sQwilfishTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossTeachableLearnset_Kismet,
    [SPECIES_HERACROSS_MEGA] = sHeracrossTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SNEASEL
#if P_GEN_4_CROSS_EVOS
    [SPECIES_WEAVILE] = sWeavileTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] = sTeddiursaTeachableLearnset_Kismet,
    [SPECIES_URSARING] = sUrsaringTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TEDDIURSA
#if P_GEN_8_CROSS_EVOS
    [SPECIES_URSALUNA] = sUrsalunaTeachableLearnset_Kismet,
    [SPECIES_URSALUNA_BLOODMOON] = sUrsalunaBloodmoonTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] = sSlugmaTeachableLearnset_Kismet,
    [SPECIES_MAGCARGO] = sMagcargoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] = sSwinubTeachableLearnset_Kismet,
    [SPECIES_PILOSWINE] = sPiloswineTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SWINUB
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAMOSWINE] = sMamoswineTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CORSOLA
    [SPECIES_CORSOLA] = sCorsolaTeachableLearnset_Kismet,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_CORSOREEF] = sCorsoreefTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MANTINE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MANTYKE] = sMantykeTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] = sRemoraidTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MANTINE
    [SPECIES_MANTINE] = sMantineTeachableLearnset_Kismet,
#endif
#if P_FAMILY_REMORAID
    [SPECIES_OCTILLERY] = sOctilleryTeachableLearnset_Kismet,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_KUJINOUGHT] = sKujinoughtTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] = sDelibirdTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] = sSkarmoryTeachableLearnset_Kismet,
    [SPECIES_SKARMORY_MEGA] = sSkarmoryTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] = sHoundourTeachableLearnset_Kismet,
    [SPECIES_HOUNDOOM] = sHoundoomTeachableLearnset_Kismet,
    [SPECIES_HOUNDOOM_MEGA] = sHoundoomTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] = sPhanpyTeachableLearnset_Kismet,
    [SPECIES_DONPHAN] = sDonphanTeachableLearnset_Kismet,
#endif
#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] = sStantlerTeachableLearnset_Kismet,
#endif
#if P_FAMILY_STANTLER
#if P_GEN_8_CROSS_EVOS
    [SPECIES_WYRDEER] = sWyrdeerTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SMEARGLE
    [SPECIES_SMEARGLE] = sSmeargleTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] = sMiltankTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RAIKOU
    [SPECIES_RAIKOU] = sRaikouTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ENTEI
    [SPECIES_ENTEI] = sEnteiTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SUICUNE
    [SPECIES_SUICUNE] = sSuicuneTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] = sLarvitarTeachableLearnset_Kismet,
    [SPECIES_PUPITAR] = sLarvitarTeachableLearnset_Kismet,
    [SPECIES_TYRANITAR] = sTyranitarTeachableLearnset_Kismet,
    [SPECIES_TYRANITAR_MEGA] = sTyranitarTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LUGIA
    [SPECIES_LUGIA] = sLugiaTeachableLearnset_Kismet,
    [SPECIES_LUGIA_SHADOW] = sLugiaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HO_OH
    [SPECIES_HO_OH] = sHoOhTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CELEBI
    [SPECIES_CELEBI] = sCelebiTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TREECKO
    [SPECIES_TREECKO] = sTreeckoTeachableLearnset_Kismet,
    [SPECIES_GROVYLE] = sGrovyleTeachableLearnset_Kismet,
    [SPECIES_SCEPTILE] = sSceptileTeachableLearnset_Kismet,
    [SPECIES_SCEPTILE_MEGA] = sSceptileTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC] = sTorchicTeachableLearnset_Kismet,
    [SPECIES_COMBUSKEN] = sCombuskenTeachableLearnset_Kismet,
    [SPECIES_BLAZIKEN] = sBlazikenTeachableLearnset_Kismet,
    [SPECIES_BLAZIKEN_MEGA] = sBlazikenTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MUDKIP
    [SPECIES_MUDKIP] = sMudkipTeachableLearnset_Kismet,
    [SPECIES_MARSHTOMP] = sMarshtompTeachableLearnset_Kismet,
    [SPECIES_SWAMPERT] = sSwampertTeachableLearnset_Kismet,
    [SPECIES_SWAMPERT_MEGA] = sSwampertTeachableLearnset_Kismet,
#endif
#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA] = sPoochyenaTeachableLearnset_Kismet,
    [SPECIES_MIGHTYENA] = sMightyenaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ZIGZAGOON
    [SPECIES_ZIGZAGOON] = sZigzagoonTeachableLearnset_Kismet,
    [SPECIES_LINOONE] = sLinooneTeachableLearnset_Kismet,
#endif
#if P_FAMILY_WURMPLE
    [SPECIES_WURMPLE] = sWurmpleTeachableLearnset_Kismet,
    [SPECIES_SILCOON] = sWurmpleTeachableLearnset_Kismet,
    [SPECIES_CASCOON] = sWurmpleTeachableLearnset_Kismet,
    [SPECIES_BEAUTIFLY] = sBeautiflyTeachableLearnset_Kismet,
    [SPECIES_DUSTOX] = sDustoxTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LOTAD
    [SPECIES_LOTAD] = sLotadTeachableLearnset_Kismet,
    [SPECIES_LOMBRE] = sLombreTeachableLearnset_Kismet,
    [SPECIES_LUDICOLO] = sLudicoloTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotTeachableLearnset_Kismet,
    [SPECIES_NUZLEAF] = sNuzleafTeachableLearnset_Kismet,
    [SPECIES_SHIFTRY] = sShiftryTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TAILLOW
    [SPECIES_TAILLOW] = sTaillowTeachableLearnset_Kismet,
    [SPECIES_SWELLOW] = sSwellowTeachableLearnset_Kismet,
#endif
#if P_FAMILY_WINGULL
    [SPECIES_WINGULL] = sWingullTeachableLearnset_Kismet,
    [SPECIES_PELIPPER] = sPelipperTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RALTS
    [SPECIES_RALTS] = sRaltsTeachableLearnset_Kismet,
    [SPECIES_KIRLIA] = sKirliaTeachableLearnset_Kismet,
    [SPECIES_GARDEVOIR] = sGardevoirTeachableLearnset_Kismet,
    [SPECIES_GARDEVOIR_MEGA] = sGardevoirTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RALTS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_GALLADE] = sGalladeTeachableLearnset_Kismet,
    [SPECIES_GALLADE_MEGA] = sGalladeTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SURSKIT
    [SPECIES_SURSKIT] = sSurskitTeachableLearnset_Kismet,
    [SPECIES_MASQUERAIN] = sMasquerainTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SHROOMISH
    [SPECIES_SHROOMISH] = sShroomishTeachableLearnset_Kismet,
    [SPECIES_BRELOOM] = sBreloomTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] = sSlakothTeachableLearnset_Kismet,
    [SPECIES_VIGOROTH] = sVigorothTeachableLearnset_Kismet,
    [SPECIES_SLAKING] = sSlakingTeachableLearnset_Kismet,
#endif
#if P_FAMILY_NINCADA
    [SPECIES_NINCADA] = sNincadaTeachableLearnset_Kismet,
    [SPECIES_NINJASK] = sNinjaskTeachableLearnset_Kismet,
    [SPECIES_SHEDINJA] = sShedinjaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_WHISMUR
    [SPECIES_WHISMUR] = sWhismurTeachableLearnset_Kismet,
    [SPECIES_LOUDRED] = sLoudredTeachableLearnset_Kismet,
    [SPECIES_EXPLOUD] = sExploudTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaTeachableLearnset_Kismet,
    [SPECIES_HARIYAMA] = sHariyamaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassTeachableLearnset_Kismet,
#endif
#if P_FAMILY_NOSEPASS
#if P_GEN_4_CROSS_EVOS
    [SPECIES_PROBOPASS] = sProbopassTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyTeachableLearnset_Kismet,
    [SPECIES_DELCATTY] = sDelcattyTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] = sSableyeTeachableLearnset_Kismet,
    [SPECIES_SABLEYE_MEGA] = sSableyeTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MAWILE
    [SPECIES_MAWILE] = sMawileTeachableLearnset_Kismet,
    [SPECIES_MAWILE_MEGA] = sMawileTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ARON
    [SPECIES_ARON] = sAronTeachableLearnset_Kismet,
    [SPECIES_LAIRON] = sAronTeachableLearnset_Kismet,
    [SPECIES_AGGRON] = sAggronTeachableLearnset_Kismet,
    [SPECIES_AGGRON_MEGA] = sAggronTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] = sMedititeTeachableLearnset_Kismet,
    [SPECIES_MEDICHAM] = sMedichamTeachableLearnset_Kismet,
    [SPECIES_MEDICHAM_MEGA] = sMedichamTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ELECTRIKE
    [SPECIES_ELECTRIKE] = sElectrikeTeachableLearnset_Kismet,
    [SPECIES_MANECTRIC] = sManectricTeachableLearnset_Kismet,
    [SPECIES_MANECTRIC_MEGA] = sManectricTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PLUSLE
    [SPECIES_PLUSLE] = sPlusleTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MINUN
    [SPECIES_MINUN] = sMinunTeachableLearnset_Kismet,
#endif
#if P_FAMILY_VOLBEAT_ILLUMISE
    [SPECIES_VOLBEAT] = sVolbeatTeachableLearnset_Kismet,
    [SPECIES_ILLUMISE] = sIllumiseTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ROSELIA
    [SPECIES_ROSELIA] = sRoseliaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ROSELIA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_ROSERADE] = sRoseradeTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_GULPIN
    [SPECIES_GULPIN] = sGulpinTeachableLearnset_Kismet,
    [SPECIES_SWALOT] = sSwalotTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaTeachableLearnset_Kismet,
    [SPECIES_SHARPEDO] = sSharpedoTeachableLearnset_Kismet,
    [SPECIES_SHARPEDO_MEGA] = sSharpedoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] = sWailmerTeachableLearnset_Kismet,
    [SPECIES_WAILORD] = sWailordTeachableLearnset_Kismet,
#endif
#if P_FAMILY_NUMEL
    [SPECIES_NUMEL] = sNumelTeachableLearnset_Kismet,
    [SPECIES_CAMERUPT] = sCameruptTeachableLearnset_Kismet,
    [SPECIES_CAMERUPT_MEGA] = sCameruptTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] = sTorkoalTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] = sSpoinkTeachableLearnset_Kismet,
    [SPECIES_GRUMPIG] = sGrumpigTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TRAPINCH
    [SPECIES_TRAPINCH] = sTrapinchTeachableLearnset_Kismet,
    [SPECIES_VIBRAVA] = sVibravaTeachableLearnset_Kismet,
    [SPECIES_FLYGON] = sFlygonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CACNEA
    [SPECIES_CACNEA] = sCacneaTeachableLearnset_Kismet,
    [SPECIES_CACTURNE] = sCacturneTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SWABLU
    [SPECIES_SWABLU] = sSwabluTeachableLearnset_Kismet,
    [SPECIES_ALTARIA] = sAltariaTeachableLearnset_Kismet,
    [SPECIES_ALTARIA_MEGA] = sAltariaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ZANGOOSE
    [SPECIES_ZANGOOSE] = sZangooseTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SEVIPER
    [SPECIES_SEVIPER] = sSeviperTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LUNATONE
    [SPECIES_LUNATONE] = sLunatoneTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SOLROCK
    [SPECIES_SOLROCK] = sSolrockTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BARBOACH
    [SPECIES_BARBOACH] = sBarboachTeachableLearnset_Kismet,
    [SPECIES_WHISCASH] = sWhiscashTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] = sCorphishTeachableLearnset_Kismet,
    [SPECIES_CRAWDAUNT] = sCrawdauntTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BALTOY
    [SPECIES_BALTOY] = sBaltoyTeachableLearnset_Kismet,
    [SPECIES_CLAYDOL] = sClaydolTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] = sLileepTeachableLearnset_Kismet,
    [SPECIES_CRADILY] = sCradilyTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ANORITH
    [SPECIES_ANORITH] = sAnorithTeachableLearnset_Kismet,
    [SPECIES_ARMALDO] = sArmaldoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_FEEBAS
    [SPECIES_FEEBAS] = sFeebasTeachableLearnset_Kismet,
    [SPECIES_MILOTIC] = sMiloticTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CASTFORM
    [SPECIES_CASTFORM_NORMAL] = sCastformNormalTeachableLearnset_Kismet,
    [SPECIES_CASTFORM_SUNNY] = sCastformNormalTeachableLearnset_Kismet,
    [SPECIES_CASTFORM_RAINY] = sCastformNormalTeachableLearnset_Kismet,
    [SPECIES_CASTFORM_SNOWY] = sCastformNormalTeachableLearnset_Kismet,
    [SPECIES_CASTFORM] = sCastformNormalTeachableLearnset_Kismet,
#endif
#if P_FAMILY_KECLEON
    [SPECIES_KECLEON] = sKecleonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] = sShuppetTeachableLearnset_Kismet,
    [SPECIES_BANETTE] = sBanetteTeachableLearnset_Kismet,
    [SPECIES_BANETTE_MEGA] = sBanetteTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DUSKULL
    [SPECIES_DUSKULL] = sDuskullTeachableLearnset_Kismet,
    [SPECIES_DUSCLOPS] = sDusclopsTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DUSKULL
#if P_GEN_4_CROSS_EVOS
    [SPECIES_DUSKNOIR] = sDusknoirTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CHIMECHO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_CHINGLING] = sChinglingTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_CHIMECHO
    [SPECIES_CHIMECHO] = sChimechoTeachableLearnset_Kismet,
    [SPECIES_CHIMECHO_MEGA] = sChimechoTeachableLearnset_Kismet,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_DECIBELLE] = sDecibelleTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolTeachableLearnset_Kismet,
    [SPECIES_ABSOL_MEGA] = sAbsolTeachableLearnset_Kismet,
    [SPECIES_ABSOL_MEGA_Z] = sAbsolTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntTeachableLearnset_Kismet,
    [SPECIES_GLALIE] = sGlalieTeachableLearnset_Kismet,
    [SPECIES_GLALIE_MEGA] = sGlalieTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SNORUNT
#if P_GEN_4_CROSS_EVOS
    [SPECIES_FROSLASS] = sFroslassTeachableLearnset_Kismet,
    [SPECIES_FROSLASS_MEGA] = sFroslassTeachableLearnset_Kismet,
#endif
#endif
#if P_FAMILY_SPHEAL
    [SPECIES_SPHEAL] = sSphealTeachableLearnset_Kismet,
    [SPECIES_SEALEO] = sSealeoTeachableLearnset_Kismet,
    [SPECIES_WALREIN] = sWalreinTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] = sClamperlTeachableLearnset_Kismet,
    [SPECIES_HUNTAIL] = sHuntailTeachableLearnset_Kismet,
    [SPECIES_GOREBYSS] = sGorebyssTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] = sLuvdiscTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BAGON
    [SPECIES_BAGON] = sBagonTeachableLearnset_Kismet,
    [SPECIES_SHELGON] = sShelgonTeachableLearnset_Kismet,
    [SPECIES_SALAMENCE] = sSalamenceTeachableLearnset_Kismet,
    [SPECIES_SALAMENCE_MEGA] = sSalamenceTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BELDUM
    [SPECIES_BELDUM] = sBeldumTeachableLearnset_Kismet,
    [SPECIES_METANG] = sMetangTeachableLearnset_Kismet,
    [SPECIES_METAGROSS] = sMetagrossTeachableLearnset_Kismet,
    [SPECIES_METAGROSS_MEGA] = sMetagrossTeachableLearnset_Kismet,
#endif
#if P_FAMILY_REGIROCK
    [SPECIES_REGIROCK] = sRegirockTeachableLearnset_Kismet,
#endif
#if P_FAMILY_REGICE
    [SPECIES_REGICE] = sRegiceTeachableLearnset_Kismet,
#endif
#if P_FAMILY_REGISTEEL
    [SPECIES_REGISTEEL] = sRegisteelTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LATIAS
    [SPECIES_LATIAS] = sLatiasTeachableLearnset_Kismet,
    [SPECIES_LATIAS_MEGA] = sLatiasTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LATIOS
    [SPECIES_LATIOS] = sLatiosTeachableLearnset_Kismet,
    [SPECIES_LATIOS_MEGA] = sLatiosTeachableLearnset_Kismet,
#endif
#if P_FAMILY_KYOGRE
    [SPECIES_KYOGRE] = sKyogreTeachableLearnset_Kismet,
    [SPECIES_KYOGRE_PRIMAL] = sKyogreTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GROUDON
    [SPECIES_GROUDON] = sGroudonTeachableLearnset_Kismet,
    [SPECIES_GROUDON_PRIMAL] = sGroudonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RAYQUAZA
    [SPECIES_RAYQUAZA] = sRayquazaTeachableLearnset_Kismet,
    [SPECIES_RAYQUAZA_MEGA] = sRayquazaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_JIRACHI
    [SPECIES_JIRACHI] = sJirachiTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DEOXYS
    [SPECIES_DEOXYS_ATTACK] = sDeoxysAttackTeachableLearnset_Kismet,
    [SPECIES_DEOXYS_DEFENSE] = sDeoxysAttackTeachableLearnset_Kismet,
    [SPECIES_DEOXYS_NORMAL] = sDeoxysNormalTeachableLearnset_Kismet,
    [SPECIES_DEOXYS] = sDeoxysNormalTeachableLearnset_Kismet,
    [SPECIES_DEOXYS_SPEED] = sDeoxysAttackTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TURTWIG
    [SPECIES_TURTWIG] = sTurtwigTeachableLearnset_Kismet,
    [SPECIES_GROTLE] = sTurtwigTeachableLearnset_Kismet,
    [SPECIES_TORTERRA] = sTorterraTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CHIMCHAR
    [SPECIES_CHIMCHAR] = sChimcharTeachableLearnset_Kismet,
    [SPECIES_MONFERNO] = sMonfernoTeachableLearnset_Kismet,
    [SPECIES_INFERNAPE] = sInfernapeTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PIPLUP
    [SPECIES_PIPLUP] = sPiplupTeachableLearnset_Kismet,
    [SPECIES_PRINPLUP] = sPrinplupTeachableLearnset_Kismet,
    [SPECIES_EMPOLEON] = sEmpoleonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_STARLY
    [SPECIES_STARAVIA] = sStaraviaTeachableLearnset_Kismet,
    [SPECIES_STARAPTOR] = sStaraptorTeachableLearnset_Kismet,
    [SPECIES_STARAPTOR_MEGA] = sStaraptorTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SHINX
    [SPECIES_SHINX] = sShinxTeachableLearnset_Kismet,
    [SPECIES_LUXIO] = sShinxTeachableLearnset_Kismet,
    [SPECIES_LUXRAY] = sLuxrayTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BURMY
    [SPECIES_BURMY] = sBurmyTeachableLearnset_Kismet,
    [SPECIES_BURMY_PLANT] = sBurmyTeachableLearnset_Kismet,
    [SPECIES_BURMY_SANDY] = sBurmyTeachableLearnset_Kismet,
    [SPECIES_BURMY_TRASH] = sBurmyTeachableLearnset_Kismet,
    [SPECIES_WORMADAM] = sWormadamTeachableLearnset_Kismet,
    [SPECIES_WORMADAM_PLANT] = sWormadamTeachableLearnset_Kismet,
    [SPECIES_WORMADAM_SANDY] = sWormadamSandyTeachableLearnset_Kismet,
    [SPECIES_WORMADAM_TRASH] = sWormadamTrashTeachableLearnset_Kismet,
#endif
#if P_FAMILY_COMBEE
    [SPECIES_COMBEE] = sCombeeTeachableLearnset_Kismet,
    [SPECIES_VESPIQUEN] = sVespiquenTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BUIZEL
    [SPECIES_BUIZEL] = sBuizelTeachableLearnset_Kismet,
    [SPECIES_FLOATZEL] = sFloatzelTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DRIFLOON
    [SPECIES_DRIFLOON] = sDrifloonTeachableLearnset_Kismet,
    [SPECIES_DRIFBLIM] = sDrifblimTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BUNEARY
    [SPECIES_BUNEARY] = sBunearyTeachableLearnset_Kismet,
    [SPECIES_LOPUNNY] = sLopunnyTeachableLearnset_Kismet,
    [SPECIES_LOPUNNY_MEGA] = sLopunnyTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GLAMEOW
    [SPECIES_GLAMEOW] = sGlameowTeachableLearnset_Kismet,
    [SPECIES_PURUGLY] = sPuruglyTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BRONZOR
    [SPECIES_BRONZOR] = sBronzorTeachableLearnset_Kismet,
    [SPECIES_BRONZONG] = sBronzongTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SPIRITOMB
    [SPECIES_SPIRITOMB] = sSpiritombTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GIBLE
    [SPECIES_GIBLE] = sGibleTeachableLearnset_Kismet,
    [SPECIES_GABITE] = sGabiteTeachableLearnset_Kismet,
    [SPECIES_GARCHOMP] = sGarchompTeachableLearnset_Kismet,
    [SPECIES_GARCHOMP_MEGA] = sGarchompTeachableLearnset_Kismet,
    [SPECIES_GARCHOMP_MEGA_Z] = sGarchompTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RIOLU
    [SPECIES_RIOLU] = sRioluTeachableLearnset_Kismet,
    [SPECIES_LUCARIO] = sLucarioTeachableLearnset_Kismet,
    [SPECIES_LUCARIO_MEGA] = sLucarioTeachableLearnset_Kismet,
    [SPECIES_LUCARIO_MEGA_Z] = sLucarioTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SKORUPI
    [SPECIES_SKORUPI] = sSkorupiTeachableLearnset_Kismet,
    [SPECIES_DRAPION] = sDrapionTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CROAGUNK
    [SPECIES_CROAGUNK] = sCroagunkTeachableLearnset_Kismet,
    [SPECIES_TOXICROAK] = sToxicroakTeachableLearnset_Kismet,
#endif
#if P_FAMILY_FINNEON
    [SPECIES_FINNEON] = sFinneonTeachableLearnset_Kismet,
    [SPECIES_LUMINEON] = sLumineonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SNOVER
    [SPECIES_SNOVER] = sSnoverTeachableLearnset_Kismet,
    [SPECIES_ABOMASNOW] = sAbomasnowTeachableLearnset_Kismet,
    [SPECIES_ABOMASNOW_MEGA] = sAbomasnowTeachableLearnset_Kismet,
#endif
#if P_FAMILY_REGIGIGAS
    [SPECIES_REGIGIGAS] = sRegigigasTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ARCEUS
    [SPECIES_ARCEUS_NORMAL] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_FIGHTING] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_FLYING] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_POISON] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_GROUND] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_ROCK] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_BUG] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_GHOST] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_STEEL] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_FIRE] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_WATER] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_GRASS] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_ELECTRIC] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_PSYCHIC] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_ICE] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_DRAGON] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_DARK] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS_FAIRY] = sArceusNormalTeachableLearnset_Kismet,
    [SPECIES_ARCEUS] = sArceusNormalTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] = sRoggenrolaTeachableLearnset_Kismet,
    [SPECIES_BOLDORE] = sBoldoreTeachableLearnset_Kismet,
    [SPECIES_GIGALITH] = sGigalithTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] = sSandileTeachableLearnset_Kismet,
    [SPECIES_KROKOROK] = sKrokorokTeachableLearnset_Kismet,
    [SPECIES_KROOKODILE] = sKrookodileTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DARUMAKA
    [SPECIES_DARUMAKA] = sDarumakaTeachableLearnset_Kismet,
    [SPECIES_DARMANITAN_STANDARD] = sDarmanitanStandardTeachableLearnset_Kismet,
    [SPECIES_DARMANITAN] = sDarmanitanStandardTeachableLearnset_Kismet,
    [SPECIES_DARMANITAN_ZEN] = sDarmanitanZenTeachableLearnset_Kismet,
#endif
#if P_FAMILY_ZORUA
    [SPECIES_ZORUA] = sZoruaTeachableLearnset_Kismet,
    [SPECIES_ZOROARK] = sZoroarkTeachableLearnset_Kismet,
#endif
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteTeachableLearnset_Kismet,
    [SPECIES_VANILLISH] = sVanilliteTeachableLearnset_Kismet,
    [SPECIES_VANILLUXE] = sVanilluxeTeachableLearnset_Kismet,
#endif
#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] = sEmolgaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_JOLTIK
    [SPECIES_JOLTIK] = sJoltikTeachableLearnset_Kismet,
    [SPECIES_GALVANTULA] = sGalvantulaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_KLINK
    [SPECIES_KLINK] = sKlinkTeachableLearnset_Kismet,
    [SPECIES_KLANG] = sKlinkTeachableLearnset_Kismet,
    [SPECIES_KLINKLANG] = sKlinklangTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] = sTynamoTeachableLearnset_Kismet,
    [SPECIES_EELEKTRIK] = sEelektrikTeachableLearnset_Kismet,
    [SPECIES_EELEKTROSS] = sEelektrossTeachableLearnset_Kismet,
    [SPECIES_EELEKTROSS_MEGA] = sEelektrossTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] = sLitwickTeachableLearnset_Kismet,
    [SPECIES_LAMPENT] = sLitwickTeachableLearnset_Kismet,
    [SPECIES_CHANDELURE] = sChandelureTeachableLearnset_Kismet,
    [SPECIES_CHANDELURE_MEGA] = sChandelureTeachableLearnset_Kismet,
#endif
#if P_FAMILY_AXEW
    [SPECIES_AXEW] = sAxewTeachableLearnset_Kismet,
    [SPECIES_FRAXURE] = sFraxureTeachableLearnset_Kismet,
    [SPECIES_HAXORUS] = sHaxorusTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] = sCubchooTeachableLearnset_Kismet,
    [SPECIES_BEARTIC] = sBearticTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CRYOGONAL
    [SPECIES_CRYOGONAL] = sCryogonalTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooTeachableLearnset_Kismet,
    [SPECIES_MIENSHAO] = sMienshaoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GOLETT
    [SPECIES_GOLETT] = sGolettTeachableLearnset_Kismet,
    [SPECIES_GOLURK] = sGolurkTeachableLearnset_Kismet,
    [SPECIES_GOLURK_MEGA] = sGolurkTeachableLearnset_Kismet,
#endif
#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] = sRuffletTeachableLearnset_Kismet,
    [SPECIES_BRAVIARY] = sBraviaryTeachableLearnset_Kismet,
#endif
#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] = sVullabyTeachableLearnset_Kismet,
    [SPECIES_MANDIBUZZ] = sMandibuzzTeachableLearnset_Kismet,
#endif
#if P_FAMILY_DEINO
    [SPECIES_DEINO] = sDeinoTeachableLearnset_Kismet,
    [SPECIES_ZWEILOUS] = sDeinoTeachableLearnset_Kismet,
    [SPECIES_HYDREIGON] = sHydreigonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] = sLarvestaTeachableLearnset_Kismet,
    [SPECIES_VOLCARONA] = sVolcaronaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] = sFletchlingTeachableLearnset_Kismet,
    [SPECIES_FLETCHINDER] = sFletchinderTeachableLearnset_Kismet,
    [SPECIES_TALONFLAME] = sTalonflameTeachableLearnset_Kismet,
#endif
#if P_FAMILY_FLABEBE
    [SPECIES_FLABEBE] = sFlabebeTeachableLearnset_Kismet,
    [SPECIES_FLABEBE_RED] = sFlabebeTeachableLearnset_Kismet,
    [SPECIES_FLABEBE_YELLOW] = sFlabebeTeachableLearnset_Kismet,
    [SPECIES_FLABEBE_ORANGE] = sFlabebeTeachableLearnset_Kismet,
    [SPECIES_FLABEBE_BLUE] = sFlabebeTeachableLearnset_Kismet,
    [SPECIES_FLOETTE] = sFloetteTeachableLearnset_Kismet,
    [SPECIES_FLABEBE_WHITE] = sFloetteTeachableLearnset_Kismet,
    [SPECIES_FLOETTE_RED] = sFloetteTeachableLearnset_Kismet,
    [SPECIES_FLOETTE_YELLOW] = sFloetteTeachableLearnset_Kismet,
    [SPECIES_FLOETTE_ORANGE] = sFloetteTeachableLearnset_Kismet,
    [SPECIES_FLOETTE_BLUE] = sFloetteTeachableLearnset_Kismet,
    [SPECIES_FLOETTE_WHITE] = sFloetteTeachableLearnset_Kismet,
    [SPECIES_FLORGES] = sFlorgesTeachableLearnset_Kismet,
    [SPECIES_FLORGES_RED] = sFlorgesTeachableLearnset_Kismet,
    [SPECIES_FLORGES_YELLOW] = sFlorgesTeachableLearnset_Kismet,
    [SPECIES_FLORGES_ORANGE] = sFlorgesTeachableLearnset_Kismet,
    [SPECIES_FLORGES_BLUE] = sFlorgesTeachableLearnset_Kismet,
    [SPECIES_FLORGES_WHITE] = sFlorgesTeachableLearnset_Kismet,
#endif
#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] = sPanchamTeachableLearnset_Kismet,
    [SPECIES_PANGORO] = sPangoroTeachableLearnset_Kismet,
#endif
#if P_FAMILY_HONEDGE
    [SPECIES_AEGISLASH] = sAegislashTeachableLearnset_Kismet,
    [SPECIES_AEGISLASH_SHIELD] = sAegislashTeachableLearnset_Kismet,
    [SPECIES_AEGISLASH_BLADE] = sAegislashTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BINACLE
    [SPECIES_BINACLE] = sBinacleTeachableLearnset_Kismet,
    [SPECIES_BARBARACLE] = sBarbaracleTeachableLearnset_Kismet,
    [SPECIES_BARBARACLE_MEGA] = sBarbaracleTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CARBINK
    [SPECIES_CARBINK] = sCarbinkTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GOOMY
    [SPECIES_GOOMY] = sGoomyTeachableLearnset_Kismet,
    [SPECIES_SLIGGOO] = sSliggooTeachableLearnset_Kismet,
    [SPECIES_GOODRA] = sGoodraTeachableLearnset_Kismet,
#endif
#if P_FAMILY_NOIBAT
    [SPECIES_NOIBAT] = sNoibatTeachableLearnset_Kismet,
    [SPECIES_NOIVERN] = sNoivernTeachableLearnset_Kismet,
#endif
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisTeachableLearnset_Kismet,
    [SPECIES_LURANTIS] = sLurantisTeachableLearnset_Kismet,
    [SPECIES_LURANTIS_TOTEM] = sLurantisTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SALANDIT
    [SPECIES_SALANDIT] = sSalanditTeachableLearnset_Kismet,
    [SPECIES_SALAZZLE] = sSalazzleTeachableLearnset_Kismet,
    [SPECIES_SALAZZLE_TOTEM] = sSalazzleTeachableLearnset_Kismet,
#endif
#if P_FAMILY_STUFFUL
    [SPECIES_STUFFUL] = sStuffulTeachableLearnset_Kismet,
    [SPECIES_BEWEAR] = sBewearTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BOUNSWEET
    [SPECIES_BOUNSWEET] = sBounsweetTeachableLearnset_Kismet,
    [SPECIES_STEENEE] = sSteeneeTeachableLearnset_Kismet,
    [SPECIES_TSAREENA] = sTsareenaTeachableLearnset_Kismet,
#endif
#if P_FAMILY_MIMIKYU
    [SPECIES_MIMIKYU_DISGUISED] = sMimikyuDisguisedTeachableLearnset_Kismet,
    [SPECIES_MIMIKYU_BUSTED] = sMimikyuDisguisedTeachableLearnset_Kismet,
    [SPECIES_MIMIKYU_TOTEM_DISGUISED] = sMimikyuDisguisedTeachableLearnset_Kismet,
    [SPECIES_MIMIKYU_BUSTED_TOTEM] = sMimikyuDisguisedTeachableLearnset_Kismet,
    [SPECIES_MIMIKYU] = sMimikyuDisguisedTeachableLearnset_Kismet,
    [SPECIES_MIMIKYU_TOTEM] = sMimikyuDisguisedTeachableLearnset_Kismet,
    [SPECIES_MIMIKYU_TOTEM_BUSTED] = sMimikyuDisguisedTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BRUXISH
    [SPECIES_BRUXISH] = sBruxishTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TAPU_KOKO
    [SPECIES_TAPU_KOKO] = sTapuKokoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TAPU_LELE
    [SPECIES_TAPU_LELE] = sTapuLeleTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TAPU_BULU
    [SPECIES_TAPU_BULU] = sTapuBuluTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TAPU_FINI
    [SPECIES_TAPU_FINI] = sTapuFiniTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SINISTEA
    [SPECIES_POLTEAGEIST] = sPolteageistTeachableLearnset_Kismet,
    [SPECIES_POLTEAGEIST_PHONY] = sPolteageistTeachableLearnset_Kismet,
    [SPECIES_POLTEAGEIST_ANTIQUE] = sPolteageistTeachableLearnset_Kismet,
#endif
#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] = sImpidimpTeachableLearnset_Kismet,
    [SPECIES_MORGREM] = sMorgremTeachableLearnset_Kismet,
    [SPECIES_GRIMMSNARL] = sGrimmsnarlTeachableLearnset_Kismet,
    [SPECIES_GRIMMSNARL_GMAX] = sGrimmsnarlTeachableLearnset_Kismet,
#endif
#if P_FAMILY_SNOM
    [SPECIES_SNOM] = sSnomTeachableLearnset_Kismet,
    [SPECIES_FROSMOTH] = sFrosmothTeachableLearnset_Kismet,
#endif
#if P_FAMILY_REGIELEKI
    [SPECIES_REGIELEKI] = sRegielekiTeachableLearnset_Kismet,
#endif
#if P_FAMILY_REGIDRAGO
    [SPECIES_REGIDRAGO] = sRegidragoTeachableLearnset_Kismet,
#endif
#if P_FAMILY_WATTREL
    [SPECIES_WATTREL] = sWattrelTeachableLearnset_Kismet,
    [SPECIES_KILOWATTREL] = sKilowattrelTeachableLearnset_Kismet,
#endif
#if P_FAMILY_KLAWF
    [SPECIES_KLAWF] = sKlawfTeachableLearnset_Kismet,
#endif
#if P_FAMILY_CAPSAKID
    [SPECIES_CAPSAKID] = sCapsakidTeachableLearnset_Kismet,
    [SPECIES_SCOVILLAIN] = sScovillainTeachableLearnset_Kismet,
    [SPECIES_SCOVILLAIN_MEGA] = sScovillainTeachableLearnset_Kismet,
#endif
#if P_FAMILY_FLITTLE
    [SPECIES_FLITTLE] = sFlittleTeachableLearnset_Kismet,
    [SPECIES_ESPATHRA] = sEspathraTeachableLearnset_Kismet,
#endif
#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] = sTinkatinkTeachableLearnset_Kismet,
    [SPECIES_TINKATUFF] = sTinkatuffTeachableLearnset_Kismet,
    [SPECIES_TINKATON] = sTinkatonTeachableLearnset_Kismet,
#endif
#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] = sBombirdierTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GLIMMET
    [SPECIES_GLIMMET] = sGlimmetTeachableLearnset_Kismet,
    [SPECIES_GLIMMORA] = sGlimmoraTeachableLearnset_Kismet,
    [SPECIES_GLIMMORA_MEGA] = sGlimmoraTeachableLearnset_Kismet,
#endif
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardTeachableLearnset_Kismet,
    [SPECIES_HOUNDSTONE] = sHoundstoneTeachableLearnset_Kismet,
#endif
#if P_KISMET_FAKEMON
    [SPECIES_RAELIC] = sRaelicTeachableLearnset_Kismet,
    [SPECIES_ROMUSHU] = sRomushuTeachableLearnset_Kismet,
    [SPECIES_FUSANG] = sFusangTeachableLearnset_Kismet,
    [SPECIES_LARVICID] = sLarvicidTeachableLearnset_Kismet,
    [SPECIES_PENDRAGON] = sPendragonTeachableLearnset_Kismet,
    [SPECIES_KROLUCADA] = sKrolucadaTeachableLearnset_Kismet,
    [SPECIES_KROLUCARD] = sKrolucardTeachableLearnset_Kismet,
    [SPECIES_PURGISLUG] = sPurgislugTeachableLearnset_Kismet,
    [SPECIES_GEKOPON] = sGekoponTeachableLearnset_Kismet,
    [SPECIES_ALT_MEGANIUM] = sAltMeganiumTeachableLearnset_Kismet,
    [SPECIES_ALT_TYPHLOSION] = sAltTyphlosionTeachableLearnset_Kismet,
    [SPECIES_ALT_FERALIGATR] = sAltFeraligatrTeachableLearnset_Kismet,
#endif
};
