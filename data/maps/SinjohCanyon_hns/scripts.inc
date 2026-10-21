SinjohCanyon_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SinjohCanyon_OnTransition
	.byte 0

SinjohCanyon_OnTransition:
	setvar VAR_TEMP_1, 1
	goto_if_unset FLAG_SINJOH_FAWN_FOUND, SinjohCanyon_OnTransition_HideFawn
	goto_if_set FLAG_SINJOH_FAWN_RETURNED, SinjohCanyon_OnTransition_End
	setvar VAR_TEMP_1, 0
	end
SinjohCanyon_OnTransition_HideFawn:
	setflag FLAG_TEMP_12
SinjohCanyon_OnTransition_End:
	end

SinjohCanyon_EventScript_ActivateGigalith::
	lock
	setobjectxyperm LOCALID_SINJOHCANYON_NOBLE_GIGALITH, 5, 30
	playse SE_M_DETECT
	getplayerxy VAR_0x8004, VAR_0x8005
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, 0
	waitfieldeffect FLDEFF_SPARKLE
	playse SE_PIN
	applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	msgbox SinjohRuins_Lab_Text_PlayFlute, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, FALSE, SinjohRuins_Lab_EventScript_NoOp
	playbgm MUS_DP_AZURE_FLUTE, FALSE
	delay 200
	fadedefaultbgm
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 12  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_SINJOHCANYON_NOBLE_GIGALITH
	clearflag FLAG_HIDE_SINJOHCANYON_NOBLE_GIGALITH
	playse SE_M_ROCK_THROW
	applymovement2 LOCALID_SINJOHCANYON_NOBLE_GIGALITH, SinjohCanyon_Movement_GigalithRises
	waitmovement LOCALID_SINJOHCANYON_NOBLE_GIGALITH
	playmoncry SPECIES_GIGALITH, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_GIGALITH, CRY_MODE_NORMAL
	waitmoncry
	applymovement2 LOCALID_SINJOHCANYON_NOBLE_GIGALITH, SinjohCanyon_Movement_GigalithStomps
	waitmovement LOCALID_SINJOHCANYON_NOBLE_GIGALITH
	playse SE_LEDGE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	waitstate
	applymovement2 LOCALID_SINJOHCANYON_NOBLE_GIGALITH, SinjohCanyon_Movement_GigalithToPatrol
	waitmovement LOCALID_SINJOHCANYON_NOBLE_GIGALITH
	removeobject LOCALID_SINJOHCANYON_NOBLE_GIGALITH
	setobjectxyperm LOCALID_SINJOHCANYON_NOBLE_GIGALITH, 2, 38
	addobject LOCALID_SINJOHCANYON_NOBLE_GIGALITH
	clearflag FLAG_HIDE_SINJOHCANYON_NOBLE_GIGALITH
	setvar VAR_NOBLE_GIGALITH, 2
	release
	end

SinjohCanyon_Movement_GigalithRises:
	walk_in_place_slow_up
	walk_in_place_slow_up
	jump_up
	step_end

SinjohCanyon_Movement_GigalithStomps:
	walk_in_place_slow_right
	jump_in_place_right
	face_right
	step_end

SinjohCanyon_Movement_GigalithToPatrol:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SinjohCanyon_EventScript_Gigalith::
	lock
	faceplayer
	playmoncry SPECIES_GIGALITH, CRY_MODE_ENCOUNTER
	msgbox SinjohCanyon_Text_GigalithCry, MSGBOX_AUTOCLOSE
	waitmoncry
	msgbox SinjohCanyon_Text_GigalithPlate, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, SinjohCanyon_EventScript_GigalithRan
	setwildbossbattle species=SPECIES_GIGALITH, level=80, item=ITEM_HARD_STONE, move1_1=MOVE_STONE_EDGE, move1_2=MOVE_EARTHQUAKE, move1_3=MOVE_HEAVY_SLAM, move1_4=MOVE_IRON_DEFENSE
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 0, 0, 2, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SinjohCanyon_EventScript_GigalithRan
    bufferspeciesname STR_VAR_1, SPECIES_GIGALITH
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_STONE_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SINJOHCANYON_NOBLE_GIGALITH
	setflag FLAG_HIDE_SINJOHCANYON_NOBLE_GIGALITH
	fadescreenswapbuffers FADE_FROM_BLACK
    call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
    call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
    call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
    call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
    call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
    call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

SinjohCanyon_EventScript_GigalithRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

SinjohCanyon_Text_GigalithCry:
	.string "Gigaaa!!$"

SinjohCanyon_Text_GigalithPlate:
	.string "The NOBLE GIGALITH's crystals\n"
	.string "hum with stored light.\p"
	.string "A PLATE is lodged among them.\p"
	.string "Battle it?$"

SinjohCanyon_EventScript_FawnTrigger::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement LOCALID_SINJOHCANYON_FAWN, SinjohCanyon_Movement_FawnGreets
	waitmovement LOCALID_SINJOHCANYON_FAWN
	playmoncry SPECIES_STANTLER, CRY_MODE_NORMAL
	msgbox SinjohCanyon_Text_FawnHome, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_SINJOHCANYON_FAWN, SinjohCanyon_Movement_FawnStepsAside
	waitmovement LOCALID_SINJOHCANYON_FAWN
	applymovement LOCALID_SINJOHCANYON_WYRDEER, SinjohCanyon_Movement_WyrdeerComes
	waitmovement LOCALID_SINJOHCANYON_WYRDEER
	playmoncry SPECIES_WYRDEER, CRY_MODE_NORMAL
	waitmoncry
	call SinjohCanyon_EventScript_FawnReward
	closemessage
	applymovement LOCALID_SINJOHCANYON_WYRDEER, SinjohCanyon_Movement_WyrdeerReturns
	waitmovement LOCALID_SINJOHCANYON_WYRDEER
	applymovement LOCALID_SINJOHCANYON_FAWN, SinjohCanyon_Movement_FawnBack
	waitmovement LOCALID_SINJOHCANYON_FAWN
	setvar VAR_TEMP_1, 1
	releaseall
	end

SinjohCanyon_EventScript_FawnReward:
	msgbox SinjohCanyon_Text_WyrdeerGift, MSGBOX_DEFAULT
	giveitem ITEM_PEAT_BLOCK
	goto_if_eq VAR_RESULT, FALSE, SinjohCanyon_EventScript_FawnRewardEnd
	setflag FLAG_SINJOH_FAWN_RETURNED
SinjohCanyon_EventScript_FawnRewardEnd:
	return

SinjohCanyon_EventScript_Wyrdeer::
	lock
	faceplayer
	playmoncry SPECIES_WYRDEER, CRY_MODE_NORMAL
	waitmoncry
	goto_if_set FLAG_SINJOH_FAWN_RETURNED, SinjohCanyon_EventScript_WyrdeerContent
	goto_if_set FLAG_SINJOH_FAWN_FOUND, SinjohCanyon_EventScript_WyrdeerThanks
	msgbox SinjohCanyon_Text_WyrdeerWaiting, MSGBOX_DEFAULT
	release
	end

SinjohCanyon_EventScript_WyrdeerThanks:
	call SinjohCanyon_EventScript_FawnReward
	setvar VAR_TEMP_1, 1
	release
	end

SinjohCanyon_EventScript_WyrdeerContent:
	msgbox SinjohCanyon_Text_WyrdeerContent, MSGBOX_DEFAULT
	release
	end

SinjohCanyon_EventScript_FawnHome::
	lock
	faceplayer
	playmoncry SPECIES_STANTLER, CRY_MODE_NORMAL
	msgbox SinjohCanyon_Text_FawnContent, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SinjohCanyon_Movement_FawnGreets:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	jump_in_place_right
	jump_in_place_right
	step_end

SinjohCanyon_Movement_FawnStepsAside:
	walk_left
	walk_left
	walk_down
	face_up
	step_end

SinjohCanyon_Movement_FawnBack:
	walk_up
	walk_left
	walk_left
	face_down
	step_end

SinjohCanyon_Movement_WyrdeerComes:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_right
	step_end

SinjohCanyon_Movement_WyrdeerReturns:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

SinjohCanyon_Text_FawnHome:
	.string "The young STANTLER from the lake\n"
	.string "found its way home!$"

SinjohCanyon_Text_WyrdeerGift:
	.string "The WYRDEER lowers its antlers…\p"
	.string "It nudges something out of the\n"
	.string "snow toward you.$"

SinjohCanyon_Text_WyrdeerWaiting:
	.string "The WYRDEER keeps glancing toward\n"
	.string "the lake.\p"
	.string "One of its herd seems to be\n"
	.string "missing.$"

SinjohCanyon_Text_WyrdeerContent:
	.string "The WYRDEER keeps a calm watch\n"
	.string "over its herd.$"

SinjohCanyon_Text_FawnContent:
	.string "The young STANTLER looks happy to\n"
	.string "be home.$"

SinjohCanyon_EventScript_Dawson::
	trainerbattle_single TRAINER_DAWSON_HNS, SinjohCanyon_Text_DawsonSeen, SinjohCanyon_Text_DawsonBeaten
	msgbox SinjohCanyon_Text_DawsonAfter, MSGBOX_AUTOCLOSE
	end

SinjohCanyon_Text_DawsonSeen:
	.string "Nothing beats a\n"
	.string "good battle\l"
	.string "out here!$"

SinjohCanyon_Text_DawsonBeaten:
	.string "Whoa! You hit\n"
	.string "harder than a\l"
	.string "ROCK SLIDE!$"

SinjohCanyon_Text_DawsonAfter:
	.string "I hike here all\n"
	.string "the time. My\l"
	.string "POKéMON keep me\l"
	.string "company!$"

SinjohCanyon_EventScript_Dai::
	trainerbattle_single TRAINER_DAI_HNS, SinjohCanyon_Text_DaiSeen, SinjohCanyon_Text_DaiBeaten
	msgbox SinjohCanyon_Text_DaiAfter, MSGBOX_AUTOCLOSE
	end

SinjohCanyon_Text_DaiSeen:
	.string "My fighting spirit\n"
	.string "burns bright!\l"
	.string "Face me!$"

SinjohCanyon_Text_DaiBeaten:
	.string "My spirit…\n"
	.string "shaken!$"

SinjohCanyon_Text_DaiAfter:
	.string "A true fighter\n"
	.string "grows from defeat.\l"
	.string "I'll train harder!$"

SinjohCanyon_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

SinjohCanyon_EventScript_ItemBlackAugurite::
	finditem ITEM_BLACK_AUGURITE
	end

SinjohCanyon_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end
