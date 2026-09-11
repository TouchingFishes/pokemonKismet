#ifndef GUARD_CONSTANTS_REGIONAL_FORM_FALLBACKS_H
#define GUARD_CONSTANTS_REGIONAL_FORM_FALLBACKS_H

// Turning a P_*_FORMS gate off does not build in pokehns-expansion 2.0 either.
// src/data/pokemon/pokedex_orders.h lists every regional form's NATIONAL_DEX_*
// unconditionally, and level_up_learnsets_gen3.c guards its table rows with
// P_FAMILY_* while the learnsets themselves are guarded with P_*_FORMS. Guarding
// all ~230 sites would mean editing two upstream files and eating the merge
// conflicts forever, so the names are defined here as nulls instead.
//
// NATIONAL_DEX_NONE is safe: every consumer of those arrays filters through
// GetSetPokedexFlag, which is never set for 0, so the slot is skipped rather than
// drawn (src/pokedex.c:2251 and :4552, and the ObtainableToNationalOrder callers).
// sNoneLevelUpLearnset is the empty learnset every level_up_learnsets/gen_*.h
// already defines, and the species it gets attached to is disabled anyway.
//
// All of this is inert while the gates are TRUE.

// Alolan forms - 18 dex constants
#if !(P_SEPARATE_REGIONAL_FORMS && P_ALOLAN_FORMS)
#define NATIONAL_DEX_DIGLETT_ALOLA   NATIONAL_DEX_NONE
#define NATIONAL_DEX_DUGTRIO_ALOLA   NATIONAL_DEX_NONE
#define NATIONAL_DEX_EXEGGUTOR_ALOLA NATIONAL_DEX_NONE
#define NATIONAL_DEX_GEODUDE_ALOLA   NATIONAL_DEX_NONE
#define NATIONAL_DEX_GOLEM_ALOLA     NATIONAL_DEX_NONE
#define NATIONAL_DEX_GRAVELER_ALOLA  NATIONAL_DEX_NONE
#define NATIONAL_DEX_GRIMER_ALOLA    NATIONAL_DEX_NONE
#define NATIONAL_DEX_MAROWAK_ALOLA   NATIONAL_DEX_NONE
#define NATIONAL_DEX_MEOWTH_ALOLA    NATIONAL_DEX_NONE
#define NATIONAL_DEX_MUK_ALOLA       NATIONAL_DEX_NONE
#define NATIONAL_DEX_NINETALES_ALOLA NATIONAL_DEX_NONE
#define NATIONAL_DEX_PERSIAN_ALOLA   NATIONAL_DEX_NONE
#define NATIONAL_DEX_RAICHU_ALOLA    NATIONAL_DEX_NONE
#define NATIONAL_DEX_RATICATE_ALOLA  NATIONAL_DEX_NONE
#define NATIONAL_DEX_RATTATA_ALOLA   NATIONAL_DEX_NONE
#define NATIONAL_DEX_SANDSHREW_ALOLA NATIONAL_DEX_NONE
#define NATIONAL_DEX_SANDSLASH_ALOLA NATIONAL_DEX_NONE
#define NATIONAL_DEX_VULPIX_ALOLA    NATIONAL_DEX_NONE
#endif

// Galarian forms - 19 dex constants
#if !(P_SEPARATE_REGIONAL_FORMS && P_GALARIAN_FORMS)
#define NATIONAL_DEX_ARTICUNO_GALAR   NATIONAL_DEX_NONE
#define NATIONAL_DEX_CORSOLA_GALAR    NATIONAL_DEX_NONE
#define NATIONAL_DEX_DARMANITAN_GALAR NATIONAL_DEX_NONE
#define NATIONAL_DEX_DARUMAKA_GALAR   NATIONAL_DEX_NONE
#define NATIONAL_DEX_FARFETCHD_GALAR  NATIONAL_DEX_NONE
#define NATIONAL_DEX_LINOONE_GALAR    NATIONAL_DEX_NONE
#define NATIONAL_DEX_MEOWTH_GALAR     NATIONAL_DEX_NONE
#define NATIONAL_DEX_MOLTRES_GALAR    NATIONAL_DEX_NONE
#define NATIONAL_DEX_MR_MIME_GALAR    NATIONAL_DEX_NONE
#define NATIONAL_DEX_PONYTA_GALAR     NATIONAL_DEX_NONE
#define NATIONAL_DEX_RAPIDASH_GALAR   NATIONAL_DEX_NONE
#define NATIONAL_DEX_SLOWBRO_GALAR    NATIONAL_DEX_NONE
#define NATIONAL_DEX_SLOWKING_GALAR   NATIONAL_DEX_NONE
#define NATIONAL_DEX_SLOWPOKE_GALAR   NATIONAL_DEX_NONE
#define NATIONAL_DEX_STUNFISK_GALAR   NATIONAL_DEX_NONE
#define NATIONAL_DEX_WEEZING_GALAR    NATIONAL_DEX_NONE
#define NATIONAL_DEX_YAMASK_GALAR     NATIONAL_DEX_NONE
#define NATIONAL_DEX_ZAPDOS_GALAR     NATIONAL_DEX_NONE
#define NATIONAL_DEX_ZIGZAGOON_GALAR  NATIONAL_DEX_NONE
#endif

// Hisuian forms - 16 dex constants
#if !(P_SEPARATE_REGIONAL_FORMS && P_HISUIAN_FORMS)
#define NATIONAL_DEX_ARCANINE_HISUI   NATIONAL_DEX_NONE
#define NATIONAL_DEX_AVALUGG_HISUI    NATIONAL_DEX_NONE
#define NATIONAL_DEX_BRAVIARY_HISUI   NATIONAL_DEX_NONE
#define NATIONAL_DEX_DECIDUEYE_HISUI  NATIONAL_DEX_NONE
#define NATIONAL_DEX_ELECTRODE_HISUI  NATIONAL_DEX_NONE
#define NATIONAL_DEX_GOODRA_HISUI     NATIONAL_DEX_NONE
#define NATIONAL_DEX_GROWLITHE_HISUI  NATIONAL_DEX_NONE
#define NATIONAL_DEX_LILLIGANT_HISUI  NATIONAL_DEX_NONE
#define NATIONAL_DEX_QWILFISH_HISUI   NATIONAL_DEX_NONE
#define NATIONAL_DEX_SAMUROTT_HISUI   NATIONAL_DEX_NONE
#define NATIONAL_DEX_SLIGGOO_HISUI    NATIONAL_DEX_NONE
#define NATIONAL_DEX_SNEASEL_HISUI    NATIONAL_DEX_NONE
#define NATIONAL_DEX_TYPHLOSION_HISUI NATIONAL_DEX_NONE
#define NATIONAL_DEX_VOLTORB_HISUI    NATIONAL_DEX_NONE
#define NATIONAL_DEX_ZOROARK_HISUI    NATIONAL_DEX_NONE
#define NATIONAL_DEX_ZORUA_HISUI      NATIONAL_DEX_NONE
#endif

// Paldean forms - 2 dex constants
#if !(P_SEPARATE_REGIONAL_FORMS && P_PALDEAN_FORMS)
#define NATIONAL_DEX_TAUROS_PALDEA NATIONAL_DEX_NONE
#define NATIONAL_DEX_WOOPER_PALDEA NATIONAL_DEX_NONE
#endif

// Alolan forms - 18 level-up learnsets
#if !P_ALOLAN_FORMS
#define sDiglettAlolaLevelUpLearnset   sNoneLevelUpLearnset
#define sDugtrioAlolaLevelUpLearnset   sNoneLevelUpLearnset
#define sExeggutorAlolaLevelUpLearnset sNoneLevelUpLearnset
#define sGeodudeAlolaLevelUpLearnset   sNoneLevelUpLearnset
#define sGolemAlolaLevelUpLearnset     sNoneLevelUpLearnset
#define sGravelerAlolaLevelUpLearnset  sNoneLevelUpLearnset
#define sGrimerAlolaLevelUpLearnset    sNoneLevelUpLearnset
#define sMarowakAlolaLevelUpLearnset   sNoneLevelUpLearnset
#define sMeowthAlolaLevelUpLearnset    sNoneLevelUpLearnset
#define sMukAlolaLevelUpLearnset       sNoneLevelUpLearnset
#define sNinetalesAlolaLevelUpLearnset sNoneLevelUpLearnset
#define sPersianAlolaLevelUpLearnset   sNoneLevelUpLearnset
#define sRaichuAlolaLevelUpLearnset    sNoneLevelUpLearnset
#define sRaticateAlolaLevelUpLearnset  sNoneLevelUpLearnset
#define sRattataAlolaLevelUpLearnset   sNoneLevelUpLearnset
#define sSandshrewAlolaLevelUpLearnset sNoneLevelUpLearnset
#define sSandslashAlolaLevelUpLearnset sNoneLevelUpLearnset
#define sVulpixAlolaLevelUpLearnset    sNoneLevelUpLearnset
#endif

// Galarian forms - 25 level-up learnsets
#if !P_GALARIAN_FORMS
#define sArticunoGalarLevelUpLearnset   sNoneLevelUpLearnset
#define sCorsolaGalarLevelUpLearnset    sNoneLevelUpLearnset
#define sCursolaLevelUpLearnset         sNoneLevelUpLearnset
#define sDarmanitanGalarLevelUpLearnset sNoneLevelUpLearnset
#define sDarumakaGalarLevelUpLearnset   sNoneLevelUpLearnset
#define sFarfetchdGalarLevelUpLearnset  sNoneLevelUpLearnset
#define sLinooneGalarLevelUpLearnset    sNoneLevelUpLearnset
#define sMeowthGalarLevelUpLearnset     sNoneLevelUpLearnset
#define sMoltresGalarLevelUpLearnset    sNoneLevelUpLearnset
#define sMrMimeGalarLevelUpLearnset     sNoneLevelUpLearnset
#define sMrRimeLevelUpLearnset          sNoneLevelUpLearnset
#define sObstagoonLevelUpLearnset       sNoneLevelUpLearnset
#define sPerrserkerLevelUpLearnset      sNoneLevelUpLearnset
#define sPonytaGalarLevelUpLearnset     sNoneLevelUpLearnset
#define sRapidashGalarLevelUpLearnset   sNoneLevelUpLearnset
#define sRunerigusLevelUpLearnset       sNoneLevelUpLearnset
#define sSirfetchdLevelUpLearnset       sNoneLevelUpLearnset
#define sSlowbroGalarLevelUpLearnset    sNoneLevelUpLearnset
#define sSlowkingGalarLevelUpLearnset   sNoneLevelUpLearnset
#define sSlowpokeGalarLevelUpLearnset   sNoneLevelUpLearnset
#define sStunfiskGalarLevelUpLearnset   sNoneLevelUpLearnset
#define sWeezingGalarLevelUpLearnset    sNoneLevelUpLearnset
#define sYamaskGalarLevelUpLearnset     sNoneLevelUpLearnset
#define sZapdosGalarLevelUpLearnset     sNoneLevelUpLearnset
#define sZigzagoonGalarLevelUpLearnset  sNoneLevelUpLearnset
#endif

// Hisuian forms - 20 level-up learnsets
#if !P_HISUIAN_FORMS
#define sArcanineHisuiLevelUpLearnset        sNoneLevelUpLearnset
#define sAvaluggHisuiLevelUpLearnset         sNoneLevelUpLearnset
#define sBasculegionLevelUpLearnset          sNoneLevelUpLearnset
#define sBasculinWhiteStripedLevelUpLearnset sNoneLevelUpLearnset
#define sBraviaryHisuiLevelUpLearnset        sNoneLevelUpLearnset
#define sDecidueyeHisuiLevelUpLearnset       sNoneLevelUpLearnset
#define sElectrodeHisuiLevelUpLearnset       sNoneLevelUpLearnset
#define sGoodraHisuiLevelUpLearnset          sNoneLevelUpLearnset
#define sGrowlitheHisuiLevelUpLearnset       sNoneLevelUpLearnset
#define sLilligantHisuiLevelUpLearnset       sNoneLevelUpLearnset
#define sOverqwilLevelUpLearnset             sNoneLevelUpLearnset
#define sQwilfishHisuiLevelUpLearnset        sNoneLevelUpLearnset
#define sSamurottHisuiLevelUpLearnset        sNoneLevelUpLearnset
#define sSliggooHisuiLevelUpLearnset         sNoneLevelUpLearnset
#define sSneaselHisuiLevelUpLearnset         sNoneLevelUpLearnset
#define sSneaslerLevelUpLearnset             sNoneLevelUpLearnset
#define sTyphlosionHisuiLevelUpLearnset      sNoneLevelUpLearnset
#define sVoltorbHisuiLevelUpLearnset         sNoneLevelUpLearnset
#define sZoroarkHisuiLevelUpLearnset         sNoneLevelUpLearnset
#define sZoruaHisuiLevelUpLearnset           sNoneLevelUpLearnset
#endif

// Paldean forms - 5 level-up learnsets
#if !P_PALDEAN_FORMS
#define sClodsireLevelUpLearnset           sNoneLevelUpLearnset
#define sTaurosPaldeaAquaLevelUpLearnset   sNoneLevelUpLearnset
#define sTaurosPaldeaBlazeLevelUpLearnset  sNoneLevelUpLearnset
#define sTaurosPaldeaCombatLevelUpLearnset sNoneLevelUpLearnset
#define sWooperPaldeaLevelUpLearnset       sNoneLevelUpLearnset
#endif

// Alolan forms - 18 teachable learnsets
#if !P_ALOLAN_FORMS
#define sDiglettAlolaTeachableLearnset   sNoneTeachableLearnset
#define sDugtrioAlolaTeachableLearnset   sNoneTeachableLearnset
#define sExeggutorAlolaTeachableLearnset sNoneTeachableLearnset
#define sGeodudeAlolaTeachableLearnset   sNoneTeachableLearnset
#define sGolemAlolaTeachableLearnset     sNoneTeachableLearnset
#define sGravelerAlolaTeachableLearnset  sNoneTeachableLearnset
#define sGrimerAlolaTeachableLearnset    sNoneTeachableLearnset
#define sMarowakAlolaTeachableLearnset   sNoneTeachableLearnset
#define sMeowthAlolaTeachableLearnset    sNoneTeachableLearnset
#define sMukAlolaTeachableLearnset       sNoneTeachableLearnset
#define sNinetalesAlolaTeachableLearnset sNoneTeachableLearnset
#define sPersianAlolaTeachableLearnset   sNoneTeachableLearnset
#define sRaichuAlolaTeachableLearnset    sNoneTeachableLearnset
#define sRaticateAlolaTeachableLearnset  sNoneTeachableLearnset
#define sRattataAlolaTeachableLearnset   sNoneTeachableLearnset
#define sSandshrewAlolaTeachableLearnset sNoneTeachableLearnset
#define sSandslashAlolaTeachableLearnset sNoneTeachableLearnset
#define sVulpixAlolaTeachableLearnset    sNoneTeachableLearnset
#endif

// Galarian forms - 25 teachable learnsets
#if !P_GALARIAN_FORMS
#define sArticunoGalarTeachableLearnset   sNoneTeachableLearnset
#define sCorsolaGalarTeachableLearnset    sNoneTeachableLearnset
#define sCursolaTeachableLearnset         sNoneTeachableLearnset
#define sDarmanitanGalarTeachableLearnset sNoneTeachableLearnset
#define sDarumakaGalarTeachableLearnset   sNoneTeachableLearnset
#define sFarfetchdGalarTeachableLearnset  sNoneTeachableLearnset
#define sLinooneGalarTeachableLearnset    sNoneTeachableLearnset
#define sMeowthGalarTeachableLearnset     sNoneTeachableLearnset
#define sMoltresGalarTeachableLearnset    sNoneTeachableLearnset
#define sMrMimeGalarTeachableLearnset     sNoneTeachableLearnset
#define sMrRimeTeachableLearnset          sNoneTeachableLearnset
#define sObstagoonTeachableLearnset       sNoneTeachableLearnset
#define sPerrserkerTeachableLearnset      sNoneTeachableLearnset
#define sPonytaGalarTeachableLearnset     sNoneTeachableLearnset
#define sRapidashGalarTeachableLearnset   sNoneTeachableLearnset
#define sRunerigusTeachableLearnset       sNoneTeachableLearnset
#define sSirfetchdTeachableLearnset       sNoneTeachableLearnset
#define sSlowbroGalarTeachableLearnset    sNoneTeachableLearnset
#define sSlowkingGalarTeachableLearnset   sNoneTeachableLearnset
#define sSlowpokeGalarTeachableLearnset   sNoneTeachableLearnset
#define sStunfiskGalarTeachableLearnset   sNoneTeachableLearnset
#define sWeezingGalarTeachableLearnset    sNoneTeachableLearnset
#define sYamaskGalarTeachableLearnset     sNoneTeachableLearnset
#define sZapdosGalarTeachableLearnset     sNoneTeachableLearnset
#define sZigzagoonGalarTeachableLearnset  sNoneTeachableLearnset
#endif

// Hisuian forms - 20 teachable learnsets
#if !P_HISUIAN_FORMS
#define sArcanineHisuiTeachableLearnset        sNoneTeachableLearnset
#define sAvaluggHisuiTeachableLearnset         sNoneTeachableLearnset
#define sBasculegionTeachableLearnset          sNoneTeachableLearnset
#define sBasculinWhiteStripedTeachableLearnset sNoneTeachableLearnset
#define sBraviaryHisuiTeachableLearnset        sNoneTeachableLearnset
#define sDecidueyeHisuiTeachableLearnset       sNoneTeachableLearnset
#define sElectrodeHisuiTeachableLearnset       sNoneTeachableLearnset
#define sGoodraHisuiTeachableLearnset          sNoneTeachableLearnset
#define sGrowlitheHisuiTeachableLearnset       sNoneTeachableLearnset
#define sLilligantHisuiTeachableLearnset       sNoneTeachableLearnset
#define sOverqwilTeachableLearnset             sNoneTeachableLearnset
#define sQwilfishHisuiTeachableLearnset        sNoneTeachableLearnset
#define sSamurottHisuiTeachableLearnset        sNoneTeachableLearnset
#define sSliggooHisuiTeachableLearnset         sNoneTeachableLearnset
#define sSneaselHisuiTeachableLearnset         sNoneTeachableLearnset
#define sSneaslerTeachableLearnset             sNoneTeachableLearnset
#define sTyphlosionHisuiTeachableLearnset      sNoneTeachableLearnset
#define sVoltorbHisuiTeachableLearnset         sNoneTeachableLearnset
#define sZoroarkHisuiTeachableLearnset         sNoneTeachableLearnset
#define sZoruaHisuiTeachableLearnset           sNoneTeachableLearnset
#endif

// Paldean forms - 5 teachable learnsets
#if !P_PALDEAN_FORMS
#define sClodsireTeachableLearnset           sNoneTeachableLearnset
#define sTaurosPaldeaAquaTeachableLearnset   sNoneTeachableLearnset
#define sTaurosPaldeaBlazeTeachableLearnset  sNoneTeachableLearnset
#define sTaurosPaldeaCombatTeachableLearnset sNoneTeachableLearnset
#define sWooperPaldeaTeachableLearnset       sNoneTeachableLearnset
#endif

#endif // GUARD_CONSTANTS_REGIONAL_FORM_FALLBACKS_H
