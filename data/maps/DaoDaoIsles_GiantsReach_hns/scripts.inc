DaoDaoIsles_GiantsReach_hns_MapScripts::
	.byte 0

@ The PHANT cutscene, copied from UlaulaIsle because Giant's Reach cannot
@ share it.
@
@ Two reasons, both silent:
@  - Giant's Reach lost the TAPU object in chunk 1, so PHANT sits at object
@    11/12 here and 12/13 on UlaulaIsle. map_event_ids.h has no namespacing, so
@    the two maps disagreed on what `Phant_Outside` means and one of them
@    despawned the wrong NPC.
@  - Giant's Reach is 47 columns wide against UlaulaIsle's 51 and PHANT stands at
@    x=32 rather than 36, so every hardcoded player-x test was 4 columns out.
@
@ The Text_ and Movement_ labels are still UlaulaIsle's - those are shared data
@ with no coordinates or local ids in them.

DaoDaoIsles_GiantsReach_PhantOutside::
	lock
	faceplayer
	hidefollower
	msgbox DaoDaoIsles_GiantsReach_Phant_outside_Text_0, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 31
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_3
DaoDaoIsles_GiantsReach_PhantOutside_1:
	compare VAR_TEMP_0, 32
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_8
DaoDaoIsles_GiantsReach_PhantOutside_6:
	compare VAR_TEMP_0, 33
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_13
DaoDaoIsles_GiantsReach_PhantOutside_11:
	compare VAR_TEMP_0, 32
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_18
DaoDaoIsles_GiantsReach_PhantOutside_16:
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox DaoDaoIsles_GiantsReach_Phant_outside_Text_1, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 31
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_23
DaoDaoIsles_GiantsReach_PhantOutside_22:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, DaoDaoIsles_GiantsReach_Phant_outside_Movement_6
	waitmovement 0
	playmoncry SPECIES_NOIVERN, 0
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT_NOIVERN, DaoDaoIsles_GiantsReach_Phant_outside_Movement_5
	waitmovement 0
	removeobject LOCALID_DAODAO_GIANTS_REACH_PHANT_NOIVERN
	removeobject LOCALID_DAODAO_GIANTS_REACH_PHANT
	setflag FLAG_HIDE_PHANT_OUTSIDE
	clearflag FLAG_HIDE_PHANT_INSIDE
	release
	end

DaoDaoIsles_GiantsReach_PhantOutside_2:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, DaoDaoIsles_GiantsReach_Phant_outside_Movement_0
	goto DaoDaoIsles_GiantsReach_PhantOutside_1

DaoDaoIsles_GiantsReach_PhantOutside_3:
	compare VAR_TEMP_1, 46
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_2
	goto DaoDaoIsles_GiantsReach_PhantOutside_1

DaoDaoIsles_GiantsReach_PhantOutside_7:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, DaoDaoIsles_GiantsReach_Phant_outside_Movement_1
	goto DaoDaoIsles_GiantsReach_PhantOutside_6

DaoDaoIsles_GiantsReach_PhantOutside_8:
	compare VAR_TEMP_1, 47
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_7
	goto DaoDaoIsles_GiantsReach_PhantOutside_6

DaoDaoIsles_GiantsReach_PhantOutside_12:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, DaoDaoIsles_GiantsReach_Phant_outside_Movement_2
	goto DaoDaoIsles_GiantsReach_PhantOutside_11

DaoDaoIsles_GiantsReach_PhantOutside_13:
	compare VAR_TEMP_1, 46
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_12
	goto DaoDaoIsles_GiantsReach_PhantOutside_11

DaoDaoIsles_GiantsReach_PhantOutside_17:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, DaoDaoIsles_GiantsReach_Phant_outside_Movement_3
	goto DaoDaoIsles_GiantsReach_PhantOutside_16

DaoDaoIsles_GiantsReach_PhantOutside_18:
	compare VAR_TEMP_1, 45
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_17
	goto DaoDaoIsles_GiantsReach_PhantOutside_16

DaoDaoIsles_GiantsReach_PhantOutside_21:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, DaoDaoIsles_GiantsReach_Phant_outside_Movement_4
	waitmovement 0
	playmoncry SPECIES_NOIVERN, 0
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT_NOIVERN, DaoDaoIsles_GiantsReach_Phant_outside_Movement_5
	waitmovement 0
	removeobject LOCALID_DAODAO_GIANTS_REACH_PHANT_NOIVERN
	removeobject LOCALID_DAODAO_GIANTS_REACH_PHANT
	setflag FLAG_HIDE_PHANT_OUTSIDE
	clearflag FLAG_HIDE_PHANT_INSIDE
	release
	end

DaoDaoIsles_GiantsReach_PhantOutside_23:
	compare VAR_TEMP_1, 46
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_21
	goto DaoDaoIsles_GiantsReach_PhantOutside_22

@ -----------------------------------------------------------------------------------------
@ Moved from UlaulaIsle_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_GiantsReach_FindItem2::
	finditem ITEM_PROTEIN, 1
	end


DaoDaoIsles_GiantsReach_MtLanikalaSign::
	lock
	msgbox DaoDaoIsles_GiantsReach_MtLanikalaSign_Text_0
	release
	end


DaoDaoIsles_GiantsReach_UlaulaSign::
	lock
	msgbox DaoDaoIsles_GiantsReach_UlaulaSign_Text_0
	release
	end


DaoDaoIsles_GiantsReach_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_DAODAO_GIANTS_REACH_PICNICKER_HNS, DaoDaoIsles_GiantsReach_TrainerBattlePicnicker_Text_0, DaoDaoIsles_GiantsReach_TrainerBattlePicnicker_Text_1
	msgbox DaoDaoIsles_GiantsReach_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_GiantsReach_TrainerBattleYoungster::
	trainerbattle_single TRAINER_DAODAO_GIANTS_REACH_YOUNGSTER_HNS, DaoDaoIsles_GiantsReach_TrainerBattleYoungster_Text_0, DaoDaoIsles_GiantsReach_TrainerBattleYoungster_Text_1
	msgbox DaoDaoIsles_GiantsReach_TrainerBattleYoungster_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_GiantsReach_TrainerBattleHiker::
	trainerbattle_single TRAINER_DAODAO_GIANTS_REACH_HIKER_HNS, DaoDaoIsles_GiantsReach_TrainerBattleHiker_Text_0, DaoDaoIsles_GiantsReach_TrainerBattleHiker_Text_1
	msgbox DaoDaoIsles_GiantsReach_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_GiantsReach_TrainerBattleCooltrainer::
	trainerbattle_single TRAINER_DAODAO_GIANTS_REACH_COOLTRAINER_HNS, DaoDaoIsles_GiantsReach_TrainerBattleCooltrainer_Text_0, DaoDaoIsles_GiantsReach_TrainerBattleCooltrainer_Text_1
	msgbox DaoDaoIsles_GiantsReach_TrainerBattleCooltrainer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_GiantsReach_LassNPC::
	lock
	faceplayer
	msgbox DaoDaoIsles_GiantsReach_LassNPC_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_GiantsReach_Bench_Heal_Right::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq DaoDaoIsles_GiantsReach_Bench_Heal_Skip
	goto DaoDaoIsles_GiantsReach_Bench_Heal

DaoDaoIsles_GiantsReach_Bench_Heal_Left::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq DaoDaoIsles_GiantsReach_Bench_Heal_Skip
	goto DaoDaoIsles_GiantsReach_Bench_Heal

DaoDaoIsles_GiantsReach_Bench_Heal_Skip:
	end

DaoDaoIsles_GiantsReach_Bench_Heal:
	lock
	faceplayer
	msgbox DaoDaoIsles_GiantsReach_Bench_Heal_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DaoDaoIsles_GiantsReach_Bench_Heal_2
DaoDaoIsles_GiantsReach_Bench_Heal_1:
	callnative UpdateFollowingPokemon
	release
	end

DaoDaoIsles_GiantsReach_Bench_Heal_2:
	fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	applymovement LOCALID_PLAYER, DaoDaoIsles_GiantsReach_Bench_Heal_Movement_0
	waitmovement 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto DaoDaoIsles_GiantsReach_Bench_Heal_1


DaoDaoIsles_GiantsReach_Phant_outside_Movement_0:
	jump_in_place_left
	jump_in_place_left
	step_end

DaoDaoIsles_GiantsReach_Phant_outside_Movement_1:
	jump_in_place_down
	jump_in_place_down
	step_end

DaoDaoIsles_GiantsReach_Phant_outside_Movement_2:
	jump_in_place_right
	jump_in_place_right
	step_end

DaoDaoIsles_GiantsReach_Phant_outside_Movement_3:
	jump_in_place_up
	jump_in_place_up
	step_end

DaoDaoIsles_GiantsReach_Phant_outside_Movement_4:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

DaoDaoIsles_GiantsReach_Phant_outside_Movement_5:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DaoDaoIsles_GiantsReach_Phant_outside_Movement_6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

DaoDaoIsles_GiantsReach_Bench_Heal_Movement_0:
	face_down
	step_end

DaoDaoIsles_GiantsReach_MtLanikalaSign_Text_0:
	.string "This mountain is affectionately\n"
	.string "referred to as MT. LANIKALA by the\l"
	.string "locals, as it is the tallest mountain\l"
	.string "on the DAODAO ISLES.\p"
	.string "The real name of this mountain has been\n"
	.string "lost to time.$"

DaoDaoIsles_GiantsReach_UlaulaSign_Text_0:
	.string "GIANT'S REACH$"

DaoDaoIsles_GiantsReach_Phant_outside_Text_0:
	.string "Hello there, {PLAYER}!\p"
	.string "I'm the developer who built this\n"
	.string "section of the game!\p"
	.string "I hope you enjoyed this taste of DAODAO.\p"
	.string "I'm working on a full demake of the\n"
	.string "region called ULTRA ECLIPSE.$"

DaoDaoIsles_GiantsReach_Phant_outside_Text_1:
	.string "Please come visit me at my house at\n"
	.string "the top of this isle.\l"
	.string "I'll make it worth your while!$"

DaoDaoIsles_GiantsReach_TrainerBattlePicnicker_Text_0:
	.string "Surprise!\nI was in the trees!$"

DaoDaoIsles_GiantsReach_TrainerBattlePicnicker_Text_1:
	.string "Back into hiding I go…$"

DaoDaoIsles_GiantsReach_TrainerBattlePicnicker_Text_2:
	.string "I thought I saw something red flying\n"
	.string "through the sky.\p"
	.string "Could it have been a POKéMON?$"

DaoDaoIsles_GiantsReach_TrainerBattleYoungster_Text_0:
	.string "Hey, I'm going to be the first to climb\nMT. LANIKALA!$"

DaoDaoIsles_GiantsReach_TrainerBattleYoungster_Text_1:
	.string "It's not even the real MT. LANIKALA…$"

DaoDaoIsles_GiantsReach_TrainerBattleYoungster_Text_2:
	.string "My dad never told me the real name of\n"
	.string "this mountain.\p"
	.string "We've always just called it MT. LANIKALA.$"

DaoDaoIsles_GiantsReach_TrainerBattleHiker_Text_0:
	.string "You must be tough to handle this\nrough terrain!$"

DaoDaoIsles_GiantsReach_TrainerBattleHiker_Text_1:
	.string "Oof,\nI should've trained harder…$"

DaoDaoIsles_GiantsReach_TrainerBattleHiker_Text_2:
	.string "GIANT'S REACH has the best hiking!\p"
	.string "The locals refer to this mountain as\n"
	.string "MT. LANIKALA, as it is the tallest on\l"
	.string "the DAODAO ISLES!$"

DaoDaoIsles_GiantsReach_TrainerBattleCooltrainer_Text_0:
	.string "This cave smells terrible!\nLet's battle to get my mind off of it!$"

DaoDaoIsles_GiantsReach_TrainerBattleCooltrainer_Text_1:
	.string "Should've brought some air freshener…$"

DaoDaoIsles_GiantsReach_TrainerBattleCooltrainer_Text_2:
	.string "You should plug your nose if you plan\n"
	.string "on going in that cave.$"

DaoDaoIsles_GiantsReach_LassNPC_Text_0:
	.string "The sea by the ISLES is truly\n"
	.string "breathtaking.\p"
	.string "I could sit here all day and just\n"
	.string "watch the waves.$"

DaoDaoIsles_GiantsReach_Bench_Heal_Text_0:
	.string "Would you like to take a rest on this\n"
	.string "bench?$"

DaoDaoIsles_GiantsReach_EventScript_MoveTutor::
	lock
	faceplayer
	goto_if_set FLAG_DAODAO_GIANTS_REACH_MOVE_TUTOR_PAID, DaoDaoIsles_GiantsReach_EventScript_MoveTutorMenu
	msgbox DaoDaoIsles_GiantsReach_Text_MoveTutorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_GiantsReach_EventScript_MoveTutorDecline
	checkitem ITEM_HEART_SCALE, 5
	goto_if_eq VAR_RESULT, FALSE, DaoDaoIsles_GiantsReach_EventScript_MoveTutorNoScales
	removeitem ITEM_HEART_SCALE, 5
	setflag FLAG_DAODAO_GIANTS_REACH_MOVE_TUTOR_PAID
	msgbox DaoDaoIsles_GiantsReach_Text_MoveTutorPaid, MSGBOX_DEFAULT

DaoDaoIsles_GiantsReach_EventScript_MoveTutorMenu::
	message DaoDaoIsles_GiantsReach_Text_MoveTutorChoose
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, DaoDaoIsles_GiantsReach_Text_TutorMove_Acrobatics, DaoDaoIsles_GiantsReach_Text_TutorMove_AuroraVeil, DaoDaoIsles_GiantsReach_Text_TutorMove_BrutalSwing, DaoDaoIsles_GiantsReach_Text_TutorMove_Confide, DaoDaoIsles_GiantsReach_Text_TutorMove_DazzlingGleam, DaoDaoIsles_GiantsReach_Text_TutorMove_DragonTail, DaoDaoIsles_GiantsReach_Text_TutorMove_EchoedVoice, DaoDaoIsles_GiantsReach_Text_TutorMove_Inferno, DaoDaoIsles_GiantsReach_Text_TutorMove_FrostBreath, DaoDaoIsles_GiantsReach_Text_TutorMove_Infestation, DaoDaoIsles_GiantsReach_Text_TutorMove_LeechLife, DaoDaoIsles_GiantsReach_Text_TutorMove_LowSweep, DaoDaoIsles_GiantsReach_Text_TutorMove_EerieSpell, DaoDaoIsles_GiantsReach_Text_TutorMove_Scald, DaoDaoIsles_GiantsReach_Text_TutorMove_SludgeWave, DaoDaoIsles_GiantsReach_Text_TutorMove_SmackDown, DaoDaoIsles_GiantsReach_Text_TutorMove_SmartStrike, DaoDaoIsles_GiantsReach_Text_TutorMove_Snarl, DaoDaoIsles_GiantsReach_Text_TutorMove_Belch, DaoDaoIsles_GiantsReach_Text_TutorMove_WildCharge, DaoDaoIsles_GiantsReach_Text_TutorMove_Cancel
	switch VAR_RESULT
	case 0, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Acrobatics
	case 1, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_AuroraVeil
	case 2, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_BrutalSwing
	case 3, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Confide
	case 4, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_DazzlingGleam
	case 5, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_DragonTail
	case 6, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_EchoedVoice
	case 7, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Inferno
	case 8, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_FrostBreath
	case 9, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Infestation
	case 10, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_LeechLife
	case 11, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_LowSweep
	case 12, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_EerieSpell
	case 13, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Scald
	case 14, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_SludgeWave
	case 15, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_SmackDown
	case 16, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_SmartStrike
	case 17, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Snarl
	case 18, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Belch
	case 19, DaoDaoIsles_GiantsReach_EventScript_TutorTeach_WildCharge
	case 20, DaoDaoIsles_GiantsReach_EventScript_MoveTutorDecline
	case MULTI_B_PRESSED, DaoDaoIsles_GiantsReach_EventScript_MoveTutorDecline
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Acrobatics::
	setvar VAR_0x8005, MOVE_ACROBATICS
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_AuroraVeil::
	setvar VAR_0x8005, MOVE_AURORA_VEIL
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_BrutalSwing::
	setvar VAR_0x8005, MOVE_BRUTAL_SWING
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Confide::
	setvar VAR_0x8005, MOVE_CONFIDE
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_DazzlingGleam::
	setvar VAR_0x8005, MOVE_DAZZLING_GLEAM
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_DragonTail::
	setvar VAR_0x8005, MOVE_DRAGON_TAIL
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_EchoedVoice::
	setvar VAR_0x8005, MOVE_ECHOED_VOICE
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Inferno::
	setvar VAR_0x8005, MOVE_INFERNO
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_FrostBreath::
	setvar VAR_0x8005, MOVE_FROST_BREATH
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Infestation::
	setvar VAR_0x8005, MOVE_INFESTATION
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_LeechLife::
	setvar VAR_0x8005, MOVE_LEECH_LIFE
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_LowSweep::
	setvar VAR_0x8005, MOVE_LOW_SWEEP
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_EerieSpell::
	setvar VAR_0x8005, MOVE_EERIE_SPELL
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Scald::
	setvar VAR_0x8005, MOVE_SCALD
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsReach_EventScript_TutorTeach_SludgeWave::
	setvar VAR_0x8005, MOVE_SLUDGE_WAVE
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_SmackDown::
	setvar VAR_0x8005, MOVE_SMACK_DOWN
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_SmartStrike::
	setvar VAR_0x8005, MOVE_SMART_STRIKE
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Snarl::
	setvar VAR_0x8005, MOVE_SNARL
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsReach_EventScript_TutorTeach_Belch::
	setvar VAR_0x8005, MOVE_BELCH
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsReach_EventScript_TutorTeach_WildCharge::
	setvar VAR_0x8005, MOVE_WILD_CHARGE
	goto DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsReach_EventScript_MoveTutorTeachMove::
	buffermovename STR_VAR_1, VAR_0x8005
	msgbox DaoDaoIsles_GiantsReach_Text_MoveTutorConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_GiantsReach_EventScript_MoveTutorMenu
	msgbox DaoDaoIsles_GiantsReach_Text_MoveTutorWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, DaoDaoIsles_GiantsReach_EventScript_MoveTutorCancelMon
	msgbox DaoDaoIsles_GiantsReach_Text_MoveTutorDone, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsReach_EventScript_MoveTutorCancelMon::
	msgbox DaoDaoIsles_GiantsReach_Text_MoveTutorComeBack, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsReach_EventScript_MoveTutorDecline::
	msgbox DaoDaoIsles_GiantsReach_Text_MoveTutorComeBack, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsReach_EventScript_MoveTutorNoScales::
	msgbox DaoDaoIsles_GiantsReach_Text_MoveTutorNoScales, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsReach_Text_MoveTutorIntro:
	.string "URGH!\n"
	.string "AGH!\p"
	.string "YOU!\p"
	.string "Did the others send you here?\n"
	.string "Did they tell you that I am the\l"
	.string "master of POKéMON moves?\p"
	.string "........................\p"
	.string "I can train your POKéMON in the\n"
	.string "ways of the ISLES, but first, a\l"
	.string "small fee.\p"
	.string "The price is 5 HEART SCALES.\p"
	.string "Do you have them?$"

DaoDaoIsles_GiantsReach_Text_MoveTutorPaid:
	.string "My wife loves these things.\p"
	.string "From now on, my services are\n"
	.string "granted to you.$"

DaoDaoIsles_GiantsReach_Text_MoveTutorNoScales:
	.string "Five HEART SCALES.\n"
	.string "Not four.\p"
	.string "Try smashing rocks.\n"
	.string "With your POKéMON, or your fists!$"

DaoDaoIsles_GiantsReach_Text_MoveTutorChoose:
	.string "Which move would you like?$"

DaoDaoIsles_GiantsReach_Text_MoveTutorConfirm:
	.string "You'd like to learn {STR_VAR_1}?$"

DaoDaoIsles_GiantsReach_Text_MoveTutorWhichMon:
	.string "Which POKéMON should learn it?$"

DaoDaoIsles_GiantsReach_Text_MoveTutorDone:
	.string "EXCELLENT!\p"
	.string "Your POKéMON holds the knowledge\n"
	.string "of the ISLES.$"

DaoDaoIsles_GiantsReach_Text_MoveTutorComeBack:
	.string "The ISLES aren't going anywhere.\n"
	.string "Come back anytime.$"

DaoDaoIsles_GiantsReach_Text_TutorMove_Acrobatics:
	.string "ACROBATICS$"

DaoDaoIsles_GiantsReach_Text_TutorMove_AuroraVeil:
	.string "AURORA VEIL$"

DaoDaoIsles_GiantsReach_Text_TutorMove_BrutalSwing:
	.string "BRUTAL SWING$"


DaoDaoIsles_GiantsReach_Text_TutorMove_Confide:
	.string "CONFIDE$"

DaoDaoIsles_GiantsReach_Text_TutorMove_DazzlingGleam:
	.string "DAZZLING GLEAM$"

DaoDaoIsles_GiantsReach_Text_TutorMove_DragonTail:
	.string "DRAGON TAIL$"

DaoDaoIsles_GiantsReach_Text_TutorMove_EchoedVoice:
	.string "ECHOED VOICE$"

DaoDaoIsles_GiantsReach_Text_TutorMove_Inferno:
	.string "INFERNO$"

DaoDaoIsles_GiantsReach_Text_TutorMove_FrostBreath:
	.string "FROST BREATH$"

DaoDaoIsles_GiantsReach_Text_TutorMove_Infestation:
	.string "INFESTATION$"

DaoDaoIsles_GiantsReach_Text_TutorMove_LeechLife:
	.string "LEECH LIFE$"

DaoDaoIsles_GiantsReach_Text_TutorMove_LowSweep:
	.string "LOW SWEEP$"

DaoDaoIsles_GiantsReach_Text_TutorMove_EerieSpell:
	.string "EERIE SPELL$"


DaoDaoIsles_GiantsReach_Text_TutorMove_Scald:
	.string "SCALD$"


DaoDaoIsles_GiantsReach_Text_TutorMove_SludgeWave:
	.string "SLUDGE WAVE$"

DaoDaoIsles_GiantsReach_Text_TutorMove_SmackDown:
	.string "SMACK DOWN$"

DaoDaoIsles_GiantsReach_Text_TutorMove_SmartStrike:
	.string "SMART STRIKE$"

DaoDaoIsles_GiantsReach_Text_TutorMove_Snarl:
	.string "SNARL$"

DaoDaoIsles_GiantsReach_Text_TutorMove_Belch:
	.string "BELCH$"


DaoDaoIsles_GiantsReach_Text_TutorMove_WildCharge:
	.string "WILD CHARGE$"


DaoDaoIsles_GiantsReach_Text_TutorMove_Cancel:
	.string "CANCEL$"
