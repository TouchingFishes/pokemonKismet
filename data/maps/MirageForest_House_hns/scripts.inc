MirageForest_House_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MirageForest_House_hns_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MirageForest_House_hns_OnFrame
	.byte 0

MirageForest_House_hns_OnTransition:
	goto_if_set FLAG_BATTLED_MIRAGE_POLTEAGEIST, MirageForestHouse_EmptyForever
	goto_if_set FLAG_NIGHT_POKEMON, MirageForestHouse_Daytime
	setflag FLAG_HIDE_MIRAGE_HOUSE_GRANDMAS
	clearflag FLAG_HIDE_MIRAGE_POLTEAGEIST
	setvar VAR_TEMP_1, 1
	end

MirageForestHouse_Daytime:
	clearflag FLAG_HIDE_MIRAGE_HOUSE_GRANDMAS
	setflag FLAG_HIDE_MIRAGE_POLTEAGEIST
	end

MirageForestHouse_EmptyForever:
	setflag FLAG_HIDE_MIRAGE_HOUSE_GRANDMAS
	setflag FLAG_HIDE_MIRAGE_POLTEAGEIST
	end

MirageForest_House_hns_OnFrame:
	map_script_2 VAR_TEMP_1, 1, MirageForestHouse_EventScript_TeaParty
	.2byte 0

MirageForestHouse_EventScript_GrandmaA::
	lock
	faceplayer
	msgbox MirageForestHouse_Text_GrandmaA, MSGBOX_DEFAULT
	release
	end

MirageForestHouse_EventScript_GrandmaB::
	lock
	faceplayer
	msgbox MirageForestHouse_Text_GrandmaB, MSGBOX_DEFAULT
	release
	end

MirageForestHouse_EventScript_TeaParty::
	lockall
	setvar VAR_TEMP_1, 0
	delay 20
	playse SE_DOOR
	msgbox MirageForestHouse_Text_DoorShuts, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MirageForestHouse_Movement_PlayerToTable
	waitmovement 0
	msgbox MirageForestHouse_Text_HouseIsEmpty, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_CLICK
	delay 16
	playse SE_CLICK
	msgbox MirageForestHouse_Text_CupsClink, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox MirageForestHouse_Text_VoiceA, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox MirageForestHouse_Text_VoiceB, MSGBOX_DEFAULT
	closemessage
	call MirageForestHouse_EventScript_LightsFlicker
	delay 20
	call MirageForestHouse_EventScript_LightsFlicker
	playse SE_M_TEETER_DANCE
	applymovement LOCALID_MIRAGE_POLTEAGEIST, MirageForestHouse_Movement_TeapotRises
	waitmovement 0
	msgbox MirageForestHouse_Text_TeapotRises, MSGBOX_DEFAULT
	closemessage
	playse SE_M_NIGHTMARE
	applymovement LOCALID_MIRAGE_POLTEAGEIST, MirageForestHouse_Movement_TeapotHopsOntoTable
	waitmovement 0
	goto MirageForestHouse_EventScript_PolteageistBattle

MirageForestHouse_EventScript_Polteageist::
	lock
	faceplayer
	msgbox MirageForestHouse_Text_HouseIsEmpty, MSGBOX_DEFAULT
	closemessage
MirageForestHouse_EventScript_PolteageistBattle:
	playmoncry SPECIES_POLTEAGEIST, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_POLTEAGEIST, level=70, move1_1=MOVE_SHADOW_BALL, move1_2=MOVE_NASTY_PLOT, move1_3=MOVE_GIGA_DRAIN, move1_4=MOVE_WILL_O_WISP
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MirageForestHouse_EventScript_PolteageistGone
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MirageForestHouse_EventScript_PolteageistGone
	releaseall
	end

MirageForestHouse_EventScript_PolteageistGone::
	setflag FLAG_BATTLED_MIRAGE_POLTEAGEIST
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MIRAGE_POLTEAGEIST
	setflag FLAG_HIDE_MIRAGE_POLTEAGEIST
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox MirageForestHouse_Text_CupsAreCold, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

MirageForestHouse_EventScript_LightsFlicker:
	playse SE_M_CONFUSE_RAY
	fadescreenspeed FADE_TO_BLACK, 1
	fadescreenspeed FADE_FROM_BLACK, 1
	delay 6
	fadescreenspeed FADE_TO_BLACK, 1
	fadescreenspeed FADE_FROM_BLACK, 2
	return

MirageForestHouse_Movement_PlayerToTable:
	walk_slow_up
	walk_slow_right
	walk_slow_right
	walk_slow_up
	face_up
	step_end

MirageForestHouse_Movement_TeapotRises:
	jump_in_place_down
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	jump_in_place_down
	step_end

MirageForestHouse_Movement_TeapotHopsOntoTable:
	jump_2_down
	step_end

MirageForestHouse_Text_GrandmaA:
	.string "Oh! A visitor, all the way out\n"
	.string "here.\p"
	.string "We so rarely get visitors.\n"
	.string "Do come back after dark, dear.\p"
	.string "We always take our tea at night.$"

MirageForestHouse_Text_GrandmaB:
	.string "My sister has already asked\n"
	.string "you, hasn't she?\p"
	.string "Come back when it's dark and\n"
	.string "we'll put the pot on.\p"
	.string "We've been waiting such a\n"
	.string "very long time.$"

MirageForestHouse_Text_DoorShuts:
	.string "Creeeak…\p"
	.string "The door swings shut behind you.$"

MirageForestHouse_Text_HouseIsEmpty:
	.string "The house is dark and empty.\p"
	.string "The two chairs at the table are\n"
	.string "cold, but the teapot is still warm.\p"
	.string "It has already poured two cups.$"

MirageForestHouse_Text_CupsClink:
	.string "Clink… clink…\p"
	.string "The teacups rattle on their\n"
	.string "saucers.$"

MirageForestHouse_Text_VoiceA:
	.string "“There you are, dear.\n"
	.string "Sit down, sit down.”$"

MirageForestHouse_Text_VoiceB:
	.string "“The tea is ready. It has been\n"
	.string "ready for such a very long time.”$"

MirageForestHouse_Text_TeapotRises:
	.string "The teapot rose into the air!$"

MirageForestHouse_Text_CupsAreCold:
	.string "The house is silent.\p"
	.string "The two teacups are cold and thick\n"
	.string "with dust.\p"
	.string "No one has poured tea here in a\n"
	.string "very long time.$"
