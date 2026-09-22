DaoDaoIsles_GiantsRest_hns_MapScripts::
	.byte 0

DaoDaoIsles_GiantsRest_EventScript_Regigigas::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0
	getcaughtmon SPECIES_REGIROCK
	call_if_eq VAR_RESULT, TRUE, DaoDaoIsles_GiantsRest_EventScript_CountOne
	getcaughtmon SPECIES_REGICE
	call_if_eq VAR_RESULT, TRUE, DaoDaoIsles_GiantsRest_EventScript_CountOne
	getcaughtmon SPECIES_REGISTEEL
	call_if_eq VAR_RESULT, TRUE, DaoDaoIsles_GiantsRest_EventScript_CountOne
	getcaughtmon SPECIES_REGIELEKI
	call_if_eq VAR_RESULT, TRUE, DaoDaoIsles_GiantsRest_EventScript_CountOne
	getcaughtmon SPECIES_REGIDRAGO
	call_if_eq VAR_RESULT, TRUE, DaoDaoIsles_GiantsRest_EventScript_CountOne
	goto_if_eq VAR_TEMP_1, 5, DaoDaoIsles_GiantsRest_EventScript_RegigigasWakes
	goto_if_eq VAR_TEMP_1, 4, DaoDaoIsles_GiantsRest_EventScript_RegigigasTier4
	goto_if_eq VAR_TEMP_1, 3, DaoDaoIsles_GiantsRest_EventScript_RegigigasTier3
	goto_if_eq VAR_TEMP_1, 2, DaoDaoIsles_GiantsRest_EventScript_RegigigasTier2
	goto_if_eq VAR_TEMP_1, 1, DaoDaoIsles_GiantsRest_EventScript_RegigigasTier1
	msgbox DaoDaoIsles_GiantsRest_Text_RegigigasTier0, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsRest_EventScript_CountOne:
	addvar VAR_TEMP_1, 1
	return

DaoDaoIsles_GiantsRest_EventScript_RegigigasTier1::
	msgbox DaoDaoIsles_GiantsRest_Text_RegigigasTier1, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsRest_EventScript_RegigigasTier2::
	msgbox DaoDaoIsles_GiantsRest_Text_RegigigasTier2, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsRest_EventScript_RegigigasTier3::
	msgbox DaoDaoIsles_GiantsRest_Text_RegigigasTier3, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsRest_EventScript_RegigigasTier4::
	msgbox DaoDaoIsles_GiantsRest_Text_RegigigasTier4, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_GiantsRest_EventScript_RegigigasWakes::
	msgbox DaoDaoIsles_GiantsRest_Text_RegigigasWakes, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 2   @ vertical pan
	setvar VAR_0x8005, 2   @ horizontal pan
	setvar VAR_0x8006, 24  @ num shakes
	setvar VAR_0x8007, 4   @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_REGIGIGAS, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_GiantsRest_EventScript_RegigigasStays
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_REGIGIGAS
	setflag FLAG_HIDE_DAODAO_REGIGIGAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_GiantsRest_EventScript_RegigigasStays::
	release
	end

DaoDaoIsles_GiantsRest_Text_RegigigasTier0:
	.string "Moss over stone, and stone all the\n"
	.string "way down.\p"
	.string "Nothing about it suggests it was\n"
	.string "ever anything else.$"

DaoDaoIsles_GiantsRest_Text_RegigigasTier1:
	.string "Moss over stone.\p"
	.string "There is a hairline crack running\n"
	.string "under it that was probably always\l"
	.string "there. Weather, most likely.$"

DaoDaoIsles_GiantsRest_Text_RegigigasTier2:
	.string "The moss has thinned across one\n"
	.string "side of the stone.\p"
	.string "Where it has, the stone is faintly\n"
	.string "warm.$"

DaoDaoIsles_GiantsRest_Text_RegigigasTier3:
	.string "Something is humming, just below\n"
	.string "hearing.\p"
	.string "It stops the moment {PLAYER} listens\n"
	.string "for it.$"

DaoDaoIsles_GiantsRest_Text_RegigigasTier4:
	.string "The moss has fallen away from one\n"
	.string "shoulder.\p"
	.string "Underneath, something is keeping\n"
	.string "time. It has been keeping time for\l"
	.string "a very long while.$"

DaoDaoIsles_GiantsRest_Text_RegigigasWakes:
	.string "Seven lights come up under the\n"
	.string "moss, one after another.\p"
	.string "The last of the stone falls away,\n"
	.string "and it steps down off the plinth.$"
