NewSinjoh_KimonoHideout_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_KimonoHideout_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewSinjoh_KimonoHideout_OnFrame
	.byte 0

NewSinjoh_KimonoHideout_OnTransition:
	call_if_ge VAR_SINJOH_STORYLINE, 6, NewSinjoh_KimonoHideout_HideYouko
	end

NewSinjoh_KimonoHideout_HideYouko:
	setflag FLAG_TEMP_12
	return

NewSinjoh_KimonoHideout_OnFrame:
	map_script_2 VAR_SINJOH_STORYLINE, 4, NewSinjoh_KimonoHideout_EventScript_PlayerMeetsKimonos
	.2byte 0

@ ============INTRO CUTSCENE=====================================================================================

NewSinjoh_KimonoHideout_EventScript_PlayerMeetsKimonos::
	lock
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsKimonos, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, NewSinjoh_KimonoHideout_Movement_PlayerWalksIntoRoom
	waitmovement 0

	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_AYAME, NewSinjoh_KimonoHideout_Movement_KimonoWalksDown
	waitmovement 0
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsAyame, MSGBOX_AUTOCLOSE
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_AYAME, NewSinjoh_KimonoHideout_Movement_KimonoWalksUp
	waitmovement 0

	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_SUZU, NewSinjoh_KimonoHideout_Movement_KimonoWalksDown
	waitmovement 0
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsSuzu, MSGBOX_AUTOCLOSE
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_SUZU, NewSinjoh_KimonoHideout_Movement_KimonoWalksUp
	waitmovement 0

	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_YOUKO, NewSinjoh_KimonoHideout_Movement_KimonoWalksDown
	waitmovement 0
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsYouko, MSGBOX_AUTOCLOSE
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_NEWSINJOH_KIMONOHIDEOUT_YOUKO, NewSinjoh_KimonoHideout_Movement_KimonoWalksUp
	waitmovement 0

	setvar VAR_SINJOH_STORYLINE, 5
	release
	end

NewSinjoh_KimonoHideout_Movement_PlayerWalksIntoRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewSinjoh_KimonoHideout_Movement_KimonoWalksDown:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	walk_down
	step_end

NewSinjoh_KimonoHideout_Movement_KimonoWalksUp:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	walk_up
	face_down
	step_end

NewSinjoh_KimonoHideout_Text_PlayerMeetsKimonos:
	.string "{PLAYER}.\p"
	.string "Please, approach.$"

NewSinjoh_KimonoHideout_Text_PlayerMeetsAyame:
    .string "AYAME: Welcome to NEW SINJOH, \n"
	.string "{PLAYER}.\p"
	.string "For generations, this village has\n"
	.string "peacefully coexisted with immensely\l"
	.string "powerful POKéMON, in isolation from\l"
	.string "the prying eyes of outsiders.\p"
	.string "Recent events at our sacred temple\n"
	.string "and a subsequent influx of uninvited\l"
	.string "guests now threaten to disrupt the\l"
	.string "careful balance we have long\l"
	.string "protected.$"

NewSinjoh_KimonoHideout_Text_PlayerMeetsSuzu:
	.string "SUZU: Our cousins in ECRUTEAK\n"
	.string "CITY made us aware of your\l"
	.string "connection to the LEGENDARY POKéMON\l"
	.string "of the JOHTO REGION, and your\l"
	.string "prowess as a trainer.\p"
	.string "We believe you can help us in these\n"
	.string "trying times.$"

NewSinjoh_KimonoHideout_Text_PlayerMeetsYouko:
	.string "YOUKO: Go to the SINJOH RUINS, to\n"
	.string "the north of ROUTE 50.\p"
	.string "Meet with the scientists there, and\n"
	.string "investigate the events that invoked\l"
	.string "their presence.\p"
	.string "It is imperative that the LEGENDARY\n"
	.string "POKéMON there are not disturbed\l"
	.string "by the unworthy.$"

NewSinjoh_KimonoHideout_EventScript_Ayame::
	lock
	faceplayer
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_KimonoHideout_EventScript_AyameFinal
	goto_if_ge VAR_SINJOH_STORYLINE, 6, NewSinjoh_KimonoHideout_EventScript_AyameHunt
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsAyame, MSGBOX_DEFAULT
	release
	end

NewSinjoh_KimonoHideout_EventScript_AyameHunt:
	msgbox NewSinjoh_KimonoHideout_Text_AyameHunt, MSGBOX_DEFAULT
	release
	end

NewSinjoh_KimonoHideout_EventScript_AyameFinal:
	msgbox NewSinjoh_KimonoHideout_Text_AyameFinal, MSGBOX_DEFAULT
	release
	end

NewSinjoh_KimonoHideout_EventScript_Suzu::
	lock
	faceplayer
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_KimonoHideout_EventScript_SuzuFinal
	goto_if_ge VAR_SINJOH_STORYLINE, 6, NewSinjoh_KimonoHideout_EventScript_SuzuHunt
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsSuzu, MSGBOX_DEFAULT
	release
	end

NewSinjoh_KimonoHideout_EventScript_SuzuHunt:
	msgbox NewSinjoh_KimonoHideout_Text_SuzuHunt, MSGBOX_DEFAULT
	release
	end

NewSinjoh_KimonoHideout_EventScript_SuzuFinal:
	msgbox NewSinjoh_KimonoHideout_Text_SuzuFinal, MSGBOX_DEFAULT
	release
	end

NewSinjoh_KimonoHideout_EventScript_Youko::
	lock
	faceplayer
	msgbox NewSinjoh_KimonoHideout_Text_PlayerMeetsYouko, MSGBOX_DEFAULT
	release
	end

NewSinjoh_KimonoHideout_Text_AyameHunt:
	.string "AYAME: The EXPERTS on ROUTE 50\n"
	.string "let you through to the ruins.\p"
	.string "Before you, only CYNTHIA had\n"
	.string "earned that.$"

NewSinjoh_KimonoHideout_Text_SuzuHunt:
	.string "SUZU: YOUKO has gone to the lake\n"
	.string "past SINJOH CANYON.\p"
	.string "She dances with both sun and\n"
	.string "moon. I hope to, one day.$"

NewSinjoh_KimonoHideout_Text_AyameFinal:
	.string "AYAME: You have done our village\n"
	.string "a great service, {PLAYER}.\p"
	.string "We will not forget this.$"

NewSinjoh_KimonoHideout_Text_SuzuFinal:
	.string "SUZU: Few trainers in all\n"
	.string "of SINJOH's storied history have\l"
	.string "managed what you've just done.\p"
	.string "Quite impressive, {PLAYER}.$"

@ =================================================================================================

NewSinjoh_KimonoHideout_EventScript_OldMan::
	msgbox NewSinjoh_KimonoHideout_Text_OldMan, MSGBOX_NPC
	end

NewSinjoh_KimonoHideout_Text_OldMan:
    .string "The KIMONO GIRLS have watched\n"
	.string "over our village since its founding.\p"
	.string "They have sacrificed much.\p"
	.string "Blessed by the Gods themselves,\n"
	.string "they have powers beyond that\l"
	.string "of any normal trainer!\p"
	.string "That is to say, be prepared\n"
	.string "if you ever fight them, young one.$"

NewSinjoh_KimonoHideout_Text_OldManAfter:
    .string "You have bested the champions of\n"
	.string "our village.\p"
	.string "What does that make you, young one?$"
