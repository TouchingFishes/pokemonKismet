SinjohLake_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SinjohLake_OnTransition
	.byte 0

SinjohLake_OnTransition:
	setvar VAR_TEMP_1, 1
	call_if_lt VAR_SINJOH_STORYLINE, 6, SinjohLake_HideYouko
	goto_if_lt VAR_SINJOH_STORYLINE, 6, SinjohLake_OnTransition_End
	goto_if_defeated TRAINER_KIMONO_YOUKO_HNS, SinjohLake_OnTransition_End
	setvar VAR_TEMP_1, 0
SinjohLake_OnTransition_End:
	end

SinjohLake_HideYouko:
	setflag FLAG_TEMP_12
	return

SinjohLake_EventScript_Youko::
	lock
	faceplayer
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohLake_EventScript_YoukoFinal
	goto_if_defeated TRAINER_KIMONO_YOUKO_HNS, SinjohLake_EventScript_YoukoAfter
	msgbox SinjohLake_Text_YoukoIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_KIMONO_YOUKO_HNS, SinjohLake_Text_YoukoDefeat
	giveitem ITEM_PIXIE_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox SinjohLake_Text_YoukoReward, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end

SinjohLake_EventScript_YoukoAfter:
	msgbox SinjohLake_Text_YoukoAfter, MSGBOX_DEFAULT
	release
	end

SinjohLake_EventScript_YoukoFinal:
	msgbox SinjohLake_Text_YoukoFinal, MSGBOX_DEFAULT
	release
	end

SinjohLake_Text_YoukoIntro:
	.string "YOUKO: You found me.\p"
	.string "The sun dances on this lake by\n"
	.string "day, and the moon by night.\p"
	.string "They say my dance rivals both.\p"
	.string "The PIXIE PLATE is yours, if you\n"
	.string "manage to meet my pace.$"

SinjohLake_Text_YoukoDefeat:
	.string "YOUKO: …Your grace is stunning.$"

SinjohLake_Text_YoukoReward:
	.string "YOUKO: Take the PIXIE PLATE.\p"
	.string "Sun and moon both bow to you\n"
	.string "today.$"

SinjohLake_Text_YoukoAfter:
	.string "YOUKO: The lake is quiet again.\p"
	.string "I will dance here until the sun\n"
	.string "and moon tell me otherwise.$"

SinjohLake_Text_YoukoFinal:
	.string "YOUKO: I had my doubts, at first.\p"
	.string "But after what you've done, it\n"
	.string "cannot be denied.$"

SinjohLake_EventScript_YoukoSceneA::
	setvar VAR_0x8008, 1
	goto SinjohLake_EventScript_YoukoScene

SinjohLake_EventScript_YoukoSceneB::
	setvar VAR_0x8008, 2
	goto SinjohLake_EventScript_YoukoScene

SinjohLake_EventScript_YoukoSceneC::
	setvar VAR_0x8008, 3
	goto SinjohLake_EventScript_YoukoScene

SinjohLake_EventScript_YoukoSceneD::
	setvar VAR_0x8008, 4
	goto SinjohLake_EventScript_YoukoScene

SinjohLake_EventScript_YoukoSceneE::
	setvar VAR_0x8008, 5
	goto SinjohLake_EventScript_YoukoScene

SinjohLake_EventScript_YoukoScene:
	lockall
	playbgm MUS_HG_KIMONO_GIRL_DANCE, FALSE
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_SINJOHLAKE_YOUKO, SinjohLake_Movement_Pirouette
	applymovement LOCALID_SINJOHLAKE_ESPEON, SinjohLake_Movement_Pirouette
	applymovement LOCALID_SINJOHLAKE_UMBREON, SinjohLake_Movement_Pirouette
	waitmovement LOCALID_SINJOHLAKE_YOUKO
	waitmovement LOCALID_SINJOHLAKE_ESPEON
	waitmovement LOCALID_SINJOHLAKE_UMBREON
	call SinjohLake_EventScript_DancersStop
	playse SE_M_MORNING_SUN
	dofieldeffectsparkle 7, 21, 0
	waitfieldeffect FLDEFF_SPARKLE
	playse SE_M_MOONLIGHT
	dofieldeffectsparkle 9, 21, 0
	waitfieldeffect FLDEFF_SPARKLE
	dofieldeffectsparkle 8, 21, 0
	waitfieldeffect FLDEFF_SPARKLE
	fadescreen FADE_TO_WHITE
	fadeoutbgm 0
	fadescreen FADE_FROM_WHITE
	playse SE_PIN
	applymovement LOCALID_SINJOHLAKE_YOUKO, Common_Movement_ExclamationMark
	waitmovement LOCALID_SINJOHLAKE_YOUKO
	gettimeofday
	goto_if_ge VAR_0x8000, TIME_EVENING, SinjohLake_EventScript_YoukoStopNight
	msgbox SinjohLake_Text_YoukoStopDay, MSGBOX_DEFAULT
	goto SinjohLake_EventScript_YoukoComeDown
SinjohLake_EventScript_YoukoStopNight:
	msgbox SinjohLake_Text_YoukoStopNight, MSGBOX_DEFAULT
SinjohLake_EventScript_YoukoComeDown:
	closemessage
	call_if_eq VAR_0x8008, 1, SinjohLake_EventScript_WalkDownA
	call_if_eq VAR_0x8008, 2, SinjohLake_EventScript_WalkDownB
	call_if_eq VAR_0x8008, 3, SinjohLake_EventScript_WalkDownC
	call_if_eq VAR_0x8008, 4, SinjohLake_EventScript_WalkDownD
	call_if_eq VAR_0x8008, 5, SinjohLake_EventScript_WalkDownE
	msgbox SinjohLake_Text_YoukoIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_KIMONO_YOUKO_HNS, SinjohLake_Text_YoukoDefeat
	giveitem ITEM_PIXIE_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox SinjohLake_Text_YoukoReward, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	call SinjohLake_EventScript_DancersResume
	setvar VAR_TEMP_1, 1
	releaseall
	end

SinjohLake_EventScript_WalkDownA:
	applymovement OBJ_EVENT_ID_PLAYER, SinjohLake_Movement_WalkDownA
	waitmovement 0
	return

SinjohLake_EventScript_WalkDownB:
	applymovement OBJ_EVENT_ID_PLAYER, SinjohLake_Movement_WalkDownB
	waitmovement 0
	return

SinjohLake_EventScript_WalkDownC:
	applymovement OBJ_EVENT_ID_PLAYER, SinjohLake_Movement_WalkDownC
	waitmovement 0
	return

SinjohLake_EventScript_WalkDownD:
	applymovement OBJ_EVENT_ID_PLAYER, SinjohLake_Movement_WalkDownD
	waitmovement 0
	return

SinjohLake_EventScript_WalkDownE:
	applymovement OBJ_EVENT_ID_PLAYER, SinjohLake_Movement_WalkDownE
	waitmovement 0
	return

SinjohLake_EventScript_DancersStop:
	setobjectmovementtype LOCALID_SINJOHLAKE_YOUKO, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SINJOHLAKE_ESPEON, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SINJOHLAKE_UMBREON, MOVEMENT_TYPE_FACE_UP
	removeobject LOCALID_SINJOHLAKE_YOUKO
	removeobject LOCALID_SINJOHLAKE_ESPEON
	removeobject LOCALID_SINJOHLAKE_UMBREON
	addobject LOCALID_SINJOHLAKE_YOUKO
	addobject LOCALID_SINJOHLAKE_ESPEON
	addobject LOCALID_SINJOHLAKE_UMBREON
	clearflag FLAG_TEMP_12
	return

SinjohLake_EventScript_DancersResume:
	setobjectmovementtype LOCALID_SINJOHLAKE_YOUKO, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_SINJOHLAKE_ESPEON, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_SINJOHLAKE_UMBREON, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	removeobject LOCALID_SINJOHLAKE_YOUKO
	removeobject LOCALID_SINJOHLAKE_ESPEON
	removeobject LOCALID_SINJOHLAKE_UMBREON
	addobject LOCALID_SINJOHLAKE_YOUKO
	addobject LOCALID_SINJOHLAKE_ESPEON
	addobject LOCALID_SINJOHLAKE_UMBREON
	clearflag FLAG_TEMP_12
	return

SinjohLake_Movement_Pirouette:
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	face_up
	step_end

SinjohLake_Movement_WalkDownA:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SinjohLake_Movement_WalkDownB:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

SinjohLake_Movement_WalkDownC:
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SinjohLake_Movement_WalkDownD:
	walk_right
	walk_down
	walk_down
	step_end

SinjohLake_Movement_WalkDownE:
	walk_down
	walk_down
	step_end

SinjohLake_EventScript_Espeon::
	lock
	faceplayer
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
	msgbox SinjohLake_Text_Espeon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SinjohLake_EventScript_Umbreon::
	lock
	faceplayer
	playmoncry SPECIES_UMBREON, CRY_MODE_NORMAL
	msgbox SinjohLake_Text_Umbreon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SinjohLake_Text_YoukoStopDay:
	.string "YOUKO: Ah… The sun stopped to\n"
	.string "watch, and so did you.\p"
	.string "Come down to me.$"

SinjohLake_Text_YoukoStopNight:
	.string "YOUKO: Ah… The moon stopped to\n"
	.string "watch, and so did you.\p"
	.string "Come down to me.$"

SinjohLake_Text_Espeon:
	.string "ESPEON: Fiiii!$"

SinjohLake_Text_Umbreon:
	.string "UMBREON: Breee…$"

SinjohLake_EventScript_Fawn::
	lock
	faceplayer
	playmoncry SPECIES_STANTLER, CRY_MODE_NORMAL
	msgbox SinjohLake_Text_Fawn, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_SINJOHLAKE_FAWN, SinjohLake_Movement_FawnLeaps
	waitmovement LOCALID_SINJOHLAKE_FAWN
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SINJOHLAKE_FAWN
	setflag FLAG_SINJOH_FAWN_FOUND
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

SinjohLake_Movement_FawnLeaps:
	jump_in_place_up
	jump_in_place_up
	step_end

SinjohLake_Text_Fawn:
	.string "A young STANTLER, shivering by\n"
	.string "the water.\p"
	.string "It must have strayed from its\n"
	.string "herd…\p"
	.string "It looks toward SINJOH CANYON,\n"
	.string "and bounds away!$"

SinjohLake_EventScript_Alexa::
	trainerbattle_single TRAINER_ALEXA_HNS, SinjohLake_Text_AlexaSeen, SinjohLake_Text_AlexaBeaten
	msgbox SinjohLake_Text_AlexaAfter, MSGBOX_AUTOCLOSE
	end

SinjohLake_Text_AlexaSeen:
	.string "I study every battle I fight.\p"
	.string "Let us learn from each other!$"

SinjohLake_Text_AlexaBeaten:
	.string "My notes didn't prepare me!$"

SinjohLake_Text_AlexaAfter:
	.string "Your strategy was unexpected… I\n"
	.string "need new data.$"

SinjohLake_EventScript_Damian::
	trainerbattle_single TRAINER_DAMIAN_HNS, SinjohLake_Text_DamianSeen, SinjohLake_Text_DamianBeaten
	msgbox SinjohLake_Text_DamianAfter, MSGBOX_AUTOCLOSE
	end

SinjohLake_Text_DamianSeen:
	.string "They told me not to come here.\p"
	.string "Said this place was… unlucky.\p"
	.string "But some of us are born to win,\n"
	.string "no matter what.$"

SinjohLake_Text_DamianBeaten:
	.string "…Impossible.$"

SinjohLake_Text_DamianAfter:
	.string "Hmph.\p"
	.string "Even fate doesn't always go as\n"
	.string "planned.$"

SinjohLake_EventScript_ItemSunStone::
	finditem ITEM_SUN_STONE
	end

SinjohLake_EventScript_ItemMoonStone::
	finditem ITEM_MOON_STONE
	end
