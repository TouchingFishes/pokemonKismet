DaoDaoIsles_GiantsBridge_hns_MapScripts::
	.byte 0

@ The BLACK BELT move tutor, moved here from GIANT'S REACH's beach (3,73), where he popped in when the
@ player crossed from LANDFALL ISLE. FLAG_DAODAO_GIANTS_REACH_MOVE_TUTOR_PAID keeps its old name.
DaoDaoIsles_GiantsBridge_EventScript_MoveTutor::
	lock
	faceplayer
	goto_if_set FLAG_DAODAO_GIANTS_REACH_MOVE_TUTOR_PAID, DaoDaoIsles_GiantsBridge_EventScript_MoveTutorMenu
	msgbox DaoDaoIsles_GiantsBridge_Text_MoveTutorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_GiantsBridge_EventScript_MoveTutorDecline
	checkitem ITEM_HEART_SCALE, 5
	goto_if_eq VAR_RESULT, FALSE, DaoDaoIsles_GiantsBridge_EventScript_MoveTutorNoScales
	removeitem ITEM_HEART_SCALE, 5
	setflag FLAG_DAODAO_GIANTS_REACH_MOVE_TUTOR_PAID
	msgbox DaoDaoIsles_GiantsBridge_Text_MoveTutorPaid, MSGBOX_DEFAULT

DaoDaoIsles_GiantsBridge_EventScript_MoveTutorMenu::
	message DaoDaoIsles_GiantsBridge_Text_MoveTutorChoose
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, DaoDaoIsles_GiantsBridge_Text_TutorMove_Acrobatics, DaoDaoIsles_GiantsBridge_Text_TutorMove_AuroraVeil, DaoDaoIsles_GiantsBridge_Text_TutorMove_BrutalSwing, DaoDaoIsles_GiantsBridge_Text_TutorMove_Confide, DaoDaoIsles_GiantsBridge_Text_TutorMove_DazzlingGleam, DaoDaoIsles_GiantsBridge_Text_TutorMove_DragonTail, DaoDaoIsles_GiantsBridge_Text_TutorMove_EchoedVoice, DaoDaoIsles_GiantsBridge_Text_TutorMove_Inferno, DaoDaoIsles_GiantsBridge_Text_TutorMove_FrostBreath, DaoDaoIsles_GiantsBridge_Text_TutorMove_Infestation, DaoDaoIsles_GiantsBridge_Text_TutorMove_LeechLife, DaoDaoIsles_GiantsBridge_Text_TutorMove_LowSweep, DaoDaoIsles_GiantsBridge_Text_TutorMove_EerieSpell, DaoDaoIsles_GiantsBridge_Text_TutorMove_Scald, DaoDaoIsles_GiantsBridge_Text_TutorMove_SludgeWave, DaoDaoIsles_GiantsBridge_Text_TutorMove_SmackDown, DaoDaoIsles_GiantsBridge_Text_TutorMove_SmartStrike, DaoDaoIsles_GiantsBridge_Text_TutorMove_Snarl, DaoDaoIsles_GiantsBridge_Text_TutorMove_KnockOff, DaoDaoIsles_GiantsBridge_Text_TutorMove_WildCharge, DaoDaoIsles_GiantsBridge_Text_TutorMove_Cancel
	switch VAR_RESULT
	case 0, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Acrobatics
	case 1, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_AuroraVeil
	case 2, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_BrutalSwing
	case 3, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Confide
	case 4, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_DazzlingGleam
	case 5, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_DragonTail
	case 6, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_EchoedVoice
	case 7, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Inferno
	case 8, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_FrostBreath
	case 9, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Infestation
	case 10, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_LeechLife
	case 11, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_LowSweep
	case 12, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_EerieSpell
	case 13, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Scald
	case 14, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_SludgeWave
	case 15, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_SmackDown
	case 16, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_SmartStrike
	case 17, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Snarl
	case 18, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_KnockOff
	case 19, DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_WildCharge
	case 20, DaoDaoIsles_GiantsBridge_EventScript_MoveTutorDecline
	case MULTI_B_PRESSED, DaoDaoIsles_GiantsBridge_EventScript_MoveTutorDecline
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Acrobatics::
	setvar VAR_0x8005, MOVE_ACROBATICS
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_AuroraVeil::
	setvar VAR_0x8005, MOVE_AURORA_VEIL
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_BrutalSwing::
	setvar VAR_0x8005, MOVE_BRUTAL_SWING
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Confide::
	setvar VAR_0x8005, MOVE_CONFIDE
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_DazzlingGleam::
	setvar VAR_0x8005, MOVE_DAZZLING_GLEAM
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_DragonTail::
	setvar VAR_0x8005, MOVE_DRAGON_TAIL
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_EchoedVoice::
	setvar VAR_0x8005, MOVE_ECHOED_VOICE
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Inferno::
	setvar VAR_0x8005, MOVE_INFERNO
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_FrostBreath::
	setvar VAR_0x8005, MOVE_FROST_BREATH
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Infestation::
	setvar VAR_0x8005, MOVE_INFESTATION
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_LeechLife::
	setvar VAR_0x8005, MOVE_LEECH_LIFE
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_LowSweep::
	setvar VAR_0x8005, MOVE_LOW_SWEEP
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_EerieSpell::
	setvar VAR_0x8005, MOVE_EERIE_SPELL
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Scald::
	setvar VAR_0x8005, MOVE_SCALD
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_SludgeWave::
	setvar VAR_0x8005, MOVE_SLUDGE_WAVE
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_SmackDown::
	setvar VAR_0x8005, MOVE_SMACK_DOWN
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_SmartStrike::
	setvar VAR_0x8005, MOVE_SMART_STRIKE
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_Snarl::
	setvar VAR_0x8005, MOVE_SNARL
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end

DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_KnockOff::
	setvar VAR_0x8005, MOVE_KNOCK_OFF
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsBridge_EventScript_TutorTeach_WildCharge::
	setvar VAR_0x8005, MOVE_WILD_CHARGE
	goto DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove
	end


DaoDaoIsles_GiantsBridge_EventScript_MoveTutorTeachMove::
	buffermovename STR_VAR_1, VAR_0x8005
	msgbox DaoDaoIsles_GiantsBridge_Text_MoveTutorConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_GiantsBridge_EventScript_MoveTutorMenu
	msgbox DaoDaoIsles_GiantsBridge_Text_MoveTutorWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, DaoDaoIsles_GiantsBridge_EventScript_MoveTutorCancelMon
	msgbox DaoDaoIsles_GiantsBridge_Text_MoveTutorDone, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsBridge_EventScript_MoveTutorCancelMon::
	msgbox DaoDaoIsles_GiantsBridge_Text_MoveTutorComeBack, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsBridge_EventScript_MoveTutorDecline::
	msgbox DaoDaoIsles_GiantsBridge_Text_MoveTutorComeBack, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsBridge_EventScript_MoveTutorNoScales::
	msgbox DaoDaoIsles_GiantsBridge_Text_MoveTutorNoScales, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsBridge_Text_MoveTutorIntro:
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

DaoDaoIsles_GiantsBridge_Text_MoveTutorPaid:
	.string "My wife loves these things.\p"
	.string "From now on, my services are\n"
	.string "granted to you.$"

DaoDaoIsles_GiantsBridge_Text_MoveTutorNoScales:
	.string "Five HEART SCALES.\n"
	.string "Not four.\p"
	.string "Try smashing rocks.\n"
	.string "With your POKéMON, or your fists!$"

DaoDaoIsles_GiantsBridge_Text_MoveTutorChoose:
	.string "Which move would you like?$"

DaoDaoIsles_GiantsBridge_Text_MoveTutorConfirm:
	.string "You'd like to learn {STR_VAR_1}?$"

DaoDaoIsles_GiantsBridge_Text_MoveTutorWhichMon:
	.string "Which POKéMON should learn it?$"

DaoDaoIsles_GiantsBridge_Text_MoveTutorDone:
	.string "EXCELLENT!\p"
	.string "Your POKéMON holds the knowledge\n"
	.string "of the ISLES.$"

DaoDaoIsles_GiantsBridge_Text_MoveTutorComeBack:
	.string "The ISLES aren't going anywhere.\n"
	.string "Come back anytime.$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_Acrobatics:
	.string "ACROBATICS$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_AuroraVeil:
	.string "AURORA VEIL$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_BrutalSwing:
	.string "BRUTAL SWING$"


DaoDaoIsles_GiantsBridge_Text_TutorMove_Confide:
	.string "CONFIDE$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_DazzlingGleam:
	.string "DAZZLING GLEAM$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_DragonTail:
	.string "DRAGON TAIL$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_EchoedVoice:
	.string "ECHOED VOICE$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_Inferno:
	.string "INFERNO$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_FrostBreath:
	.string "FROST BREATH$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_Infestation:
	.string "INFESTATION$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_LeechLife:
	.string "LEECH LIFE$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_LowSweep:
	.string "LOW SWEEP$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_EerieSpell:
	.string "EERIE SPELL$"


DaoDaoIsles_GiantsBridge_Text_TutorMove_Scald:
	.string "SCALD$"


DaoDaoIsles_GiantsBridge_Text_TutorMove_SludgeWave:
	.string "SLUDGE WAVE$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_SmackDown:
	.string "SMACK DOWN$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_SmartStrike:
	.string "SMART STRIKE$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_Snarl:
	.string "SNARL$"

DaoDaoIsles_GiantsBridge_Text_TutorMove_KnockOff:
	.string "KNOCK OFF$"


DaoDaoIsles_GiantsBridge_Text_TutorMove_WildCharge:
	.string "WILD CHARGE$"


DaoDaoIsles_GiantsBridge_Text_TutorMove_Cancel:
	.string "CANCEL$"
