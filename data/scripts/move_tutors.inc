@ ============================================================
@ TUTOR PLACEMENTS - matched against the fork, 2026-08-28.
@
@ Every tutor here now stands where pokemonHnS puts it. Compare by the
@ map.json reference, NOT by the script label: the labels are Hoenn-derived
@ legacy names carried over from the shared script, so a label reading
@ "MossdeepCity_..." says nothing about where the NPC actually stands. An
@ earlier audit compared labels and wrongly concluded most placements differed.
@
@   MOVE          OUR HnS-SIDE MAP                     FORK
@   Swagger       Route4_PokemonCenter_hns             same
@   Rollout       PewterCity_hns                       same
@   Fury Cutter   IlexForest_hns                       same
@   Tri Attack    SaffronCity_PokemonCenter_hns        same
@   Metronome     OlivineCity_hns                      same
@   Substitute    Gate_Route40_TrainerHill_Courtyard   same
@   Double-Edge   ViridianCity_House2 + _Mart          same (both)
@   Explosion     CinnabarIsland_PokemonCenter_hns     same
@   Headbutt      IlexForest_hns                       same
@   Mega Punch    Route4_hns  x=47                     same
@   Mega Kick     Route4_hns  x=50                     same slot, see below
@   Acrobatics    FortreeCity_House2 (Hoenn only)      same
@   Focus Punch   - none yet -                         KameHouse, not ported
@   Focus Blast   ViridianCity_hns                     - none, ours only -
@
@ Two entries do not come from the fork cleanly, and both are deliberate:
@
@   - FOCUS PUNCH has no HnS-side home. The fork teaches it at Kame House, a
@     map absent from this tree entirely. Rather than relocate the tutor to a
@     map that holds a different one in the source, the HnS half is left
@     unplaced until Kame House is ported (D35). Mossdeep, the Hoenn half,
@     matches the fork and still works. Focus Punch is a TM here, so the move
@     is not lost meanwhile.
@
@   - FOCUS BLAST is ours alone. The fork's tutor is at Cerulean Cape, a map
@     in neither tree, and no map.json references its script - dead code in the
@     source. Viridian City is our placement, kept because Focus Blast is on no
@     TM list and this is its only teach source.
@
@ DIALOGUE: ported from the fork wherever it has authored text, which is all
@ tutors here except Headbutt. Prices match the fork's exactly and are named in
@ the text, as the fork does. The once-only flag gate is gone (D13); tutors are
@ repeatable and charge every time.
@
@ Where a script is shared by a Hoenn map and one of ours, one body of text
@ cannot suit both. Because the placements match the fork, the fork's own text
@ carries the same compromise, so it is ported as written rather than rewritten.
@
@ ============================================================

SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	move_tutor MOVE_SWAGGER, MoveTutor_Text_SwaggerTeach, MoveTutor_Text_SwaggerWhichMon, MoveTutor_EventScript_SwaggerDeclined, MoveTutor_EventScript_SwaggerTaught, 2500
	release
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerTaught::
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	move_tutor MOVE_ROLLOUT, MoveTutor_Text_RolloutTeach, MoveTutor_Text_RolloutWhichMon, MoveTutor_EventScript_RolloutDeclined, MoveTutor_EventScript_RolloutTaught, 2500
	release
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	move_tutor MOVE_FURY_CUTTER, MoveTutor_Text_FuryCutterTeach, MoveTutor_Text_FuryCutterWhichMon, MoveTutor_EventScript_FuryCutterDeclined, MoveTutor_EventScript_FuryCutterTaught, 3500
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_House_EventScript_TriAttackTutor::
	lock
	faceplayer
	move_tutor MOVE_TRI_ATTACK, MoveTutor_TriAttackTeach, MoveTutor_Text_TriAttackWhichMon, MoveTutor_EventScript_TriAttackDeclined, MoveTutor_EventScript_TriAttackTaught, 3333
	end

MoveTutor_EventScript_TriAttackDeclined::
	msgbox MoveTutor_TriAttackDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_TriAttackTaught::
	msgbox MoveTutor_Text_TriAttackTaught, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor::
	lock
	faceplayer
	move_tutor MOVE_METRONOME, MoveTutor_Text_MetronomeTeach, MoveTutor_Text_MetronomeWhichMon, MoveTutor_EventScript_MetronomeDeclined, MoveTutor_EventScript_MetronomeTaught, 2500
	end

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MetronomeTaught::
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

@ OURS ONLY - no counterpart in the fork. The fork's Focus Blast tutor is
@ CeruleanCape_EventScript_FocusBlastTutor, and CeruleanCape is a map that
@ exists in neither tree: no map.json references that script, so it is dead
@ code in the source. Viridian City is our own placement, kept deliberately
@ because Focus Blast is on no TM list and this is its only teach source.
ViridianCity_EventScript_FocusBlastTutor::
	lock
	faceplayer
	move_tutor MOVE_FOCUS_BLAST, MoveTutor_Text_FocusBlastTeach, MoveTutor_Text_FocusBlastWhichMon, MoveTutor_EventScript_FocusBlastDeclined, MoveTutor_EventScript_FocusBlastTaught, 20000
	end

MoveTutor_EventScript_FocusBlastDeclined::
	msgbox MoveTutor_Text_FocusBlastDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FocusBlastTaught::
	msgbox MoveTutor_Text_FocusBlastTaught, MSGBOX_DEFAULT
	release
	end

@ Fortree City House 2, matching the fork exactly - same map, same expert NPC.
@ Hoenn-only in the fork and here: no HnS-side map references it, so this tutor
@ is reachable in the Emerald build only.
FortreeCity_House2_EventScript_AcrobaticsTutor::
	lock
	faceplayer
	move_tutor MOVE_ACROBATICS, MoveTutor_Text_AcrobaticsTeach, MoveTutor_Text_AcrobaticsWhichMon, MoveTutor_EventScript_AcrobaticsDeclined, MoveTutor_EventScript_AcrobaticsTaught, 5000
	end

MoveTutor_EventScript_AcrobaticsDeclined::
	msgbox MoveTutor_Text_AcrobaticsDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_AcrobaticsTaught::
	msgbox MoveTutor_Text_AcrobaticsTaught, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
	lock
	faceplayer
	move_tutor MOVE_SUBSTITUTE, MoveTutor_Text_SubstituteTeach, MoveTutor_Text_SubstituteWhichMon, MoveTutor_EventScript_SubstituteDeclined, MoveTutor_EventScript_SubstituteTaught, 12500
	end

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

@ HOENN ONLY for now. The fork places this tutor on TWO maps - MossdeepCity
@ (Hoenn) and KameHouse (HnS side) - and we match the Hoenn half exactly.
@ KameHouse does not exist in this tree at all, so the HnS half has no home
@ yet and Focus Punch is currently TM-only in the HnS build. See D35: the
@ Kame House map is to be ported, and this script gains its second reference
@ then. Do not relocate the tutor to substitute for that port.
MossdeepCity_EventScript_FocusPunchTutor::
	lock
	faceplayer
	move_tutor MOVE_FOCUS_PUNCH, MoveTutor_Text_FocusPunchTeach, MoveTutor_Text_FocusPunchWhichMon, MoveTutor_EventScript_FocusPunchDeclined, MoveTutor_EventScript_FocusPunchTaught, 5000
	end

MoveTutor_EventScript_FocusPunchDeclined::
	msgbox MoveTutor_Text_FocusPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FocusPunchTaught::
	msgbox MoveTutor_Text_FocusPunchTaught, MSGBOX_DEFAULT
	release
	end

@ Route 4, matching the fork: two rival black belts facing each other, one
@ teaching punching and one kicking - their Taught texts insult each other,
@ so they are a deliberate pair, not a duplicate.
@
@ The fork wires BOTH of its Route 4 belts to MegaPunchTutor and leaves
@ Route4_EventScript_MegaKickTutor referenced by nothing; that is a bug in the
@ source, not a design choice, so we give the second belt the kicking tutor.
@
@ The _hns suffix is required: plain Route4_EventScript_MegaPunchTutor and
@ ...MegaKickTutor already exist in data/scripts/move_tutors_frlg.inc for the
@ FireRed Route 4 pair, which are once-only and flag-gated rather than paid.
Route4_EventScript_MegaPunchTutor_hns::
	lock
	faceplayer
	move_tutor MOVE_MEGA_PUNCH, MoveTutor_Text_MegaPunchTeach, MoveTutor_Text_MegaPunchWhichMon, MoveTutor_EventScript_MegaPunchDeclined, MoveTutor_EventScript_MegaPunchTaught, 5000
	end

MoveTutor_EventScript_MegaPunchDeclined::
	msgbox MoveTutor_Text_MegaPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MegaPunchTaught::
	msgbox MoveTutor_Text_MegaPunchTaught, MSGBOX_DEFAULT
	release
	end

Route4_EventScript_MegaKickTutor_hns::
	lock
	faceplayer
	move_tutor MOVE_MEGA_KICK, MoveTutor_Text_MegaKickTeach, MoveTutor_Text_MegaKickWhichMon, MoveTutor_EventScript_MegaKickDeclined, MoveTutor_EventScript_MegaKickTaught, 5000
	end

MoveTutor_EventScript_MegaKickDeclined::
	msgbox MoveTutor_Text_MegaKickDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MegaKickTaught::
	msgbox MoveTutor_Text_MegaKickTaught, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	move_tutor MOVE_DOUBLE_EDGE, MoveTutor_Text_DoubleEdgeTeach, MoveTutor_Text_DoubleEdgeWhichMon, MoveTutor_EventScript_DoubleEdgeDeclined, MoveTutor_EventScript_DoubleEdgeTaught, 15000
	end

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleEdgeTaught::
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	move_tutor MOVE_EXPLOSION, MoveTutor_Text_ExplosionTeach, MoveTutor_Text_ExplosionWhichMon, MoveTutor_EventScript_ExplosionDeclined, MoveTutor_EventScript_ExplosionTaught, 15000
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

@ Ilex Forest, matching HGSS, where our Fury Cutter tutor also stands. Ours
@ only - the fork has no Headbutt tutor, so the price (1000) and the text are
@ both written here rather than ported.
IlexForest_EventScript_HeadbuttMoveTutor::
	lock
	faceplayer
	move_tutor MOVE_HEADBUTT, MoveTutor_Text_HeadbuttTeach, MoveTutor_Text_HeadbuttWhichMon, MoveTutor_EventScript_HeadbuttDeclined, MoveTutor_EventScript_HeadbuttTaught, 1000
	end

MoveTutor_EventScript_HeadbuttDeclined::
	msgbox MoveTutor_Text_HeadbuttDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_HeadbuttTaught::
	setflag FLAG_GET_HEADBUTT
	msgbox MoveTutor_Text_HeadbuttTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_OpenBox::
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_NotEnoughMoney::
	msgbox MoveTutor_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

MoveTutor_AfterChooseBoxMon::
	waitstate
	special CanTeachMoveBoxMon
	waitstate
	return

MoveTutor_EventScript_ThunderWaveTutor_hns::
	lock
	faceplayer
	move_tutor MOVE_THUNDER_WAVE, MoveTutor_Text_ThunderWaveTeach, MoveTutor_Text_ThunderWaveWhichMon, MoveTutor_EventScript_ThunderWaveDeclined_hns, MoveTutor_EventScript_ThunderWaveTaught_hns, 7500
	release
	end

MoveTutor_EventScript_ThunderWaveDeclined_hns::
	msgbox MoveTutor_Text_ThunderWaveDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ThunderWaveTaught_hns::
	msgbox MoveTutor_Text_ThunderWaveTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SoftboiledTutor_hns::
	lock
	faceplayer
	move_tutor MOVE_SOFT_BOILED, MoveTutor_Text_SoftboiledTeach, MoveTutor_Text_SoftboiledWhichMon, MoveTutor_EventScript_SoftboiledDeclined_hns, MoveTutor_EventScript_SoftboiledTaught_hns, 1000
	release
	end

MoveTutor_EventScript_SoftboiledDeclined_hns::
	msgbox MoveTutor_Text_SoftboiledDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SoftboiledTaught_hns::
	msgbox MoveTutor_Text_SoftboiledTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_HeatWaveTutor_hns::
	lock
	faceplayer
	move_tutor MOVE_HEAT_WAVE, MoveTutor_Text_HeatWaveTeach, MoveTutor_Text_HeatWaveWhichMon, MoveTutor_EventScript_HeatWaveDeclined_hns, MoveTutor_EventScript_HeatWaveTaught_hns, 10000
	release
	end

MoveTutor_EventScript_HeatWaveDeclined_hns::
	msgbox MoveTutor_Text_HeatWaveDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_HeatWaveTaught_hns::
	msgbox MoveTutor_Text_HeatWaveTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_BideTutor_hns::
	lock
	faceplayer
	move_tutor MOVE_BIDE, MoveTutor_Text_BideTeach, MoveTutor_Text_BideWhichMon, MoveTutor_EventScript_BideDeclined_hns, MoveTutor_EventScript_BideTaught_hns, 2500
	release
	end

MoveTutor_EventScript_BideDeclined_hns::
	msgbox MoveTutor_Text_BideDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_BideTaught_hns::
	msgbox MoveTutor_Text_BideTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_AncientPowerTutor_hns::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_PEWTER_GYM, MoveTutor_EventScript_AncientPowerNotReady_hns
	move_tutor MOVE_ANCIENT_POWER, MoveTutor_Text_AncientPowerTeach, MoveTutor_Text_AncientPowerWhichMon, MoveTutor_EventScript_AncientPowerDeclined_hns, MoveTutor_EventScript_AncientPowerTaught_hns, 0
	release
	end

MoveTutor_EventScript_AncientPowerDeclined_hns::
	msgbox MoveTutor_Text_AncientPowerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_AncientPowerTaught_hns::
	msgbox MoveTutor_Text_AncientPowerTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_AncientPowerNotReady_hns::
	msgbox MoveTutor_Text_AncientPowerNotReady_hns, MSGBOX_DEFAULT
	release
	end
