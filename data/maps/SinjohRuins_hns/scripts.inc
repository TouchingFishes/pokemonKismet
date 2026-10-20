SinjohRuins_hns_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_OnFrame
    map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_hns_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SinjohRuins_hns_OnLoad
	.byte 0

SinjohRuins_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 8, SinjohRuins_StairsScene
	.2byte 0

SinjohRuins_hns_OnTransition::
    call_if_eq VAR_SINJOH_STORYLINE, 9, SinjohRuins_CynthiaLanding
    call_if_eq VAR_SINJOH_STORYLINE, 10, SinjohRuins_CynthiaLanding
    call_if_eq VAR_SINJOH_STORYLINE, 11, SinjohRuins_CynthiaLanding
    call_if_eq VAR_SINJOH_STORYLINE, 12, SinjohRuins_CynthiaLanding
    callnative SetTimeBasedEncounters
	end

SinjohRuins_CynthiaLanding::
    setobjectxyperm LOCALID_SINJOHRUINS_CYNTHIA, 24, 31
    setobjectmovementtype LOCALID_SINJOHRUINS_CYNTHIA, MOVEMENT_TYPE_FACE_UP
    return

SinjohRuins_hns_OnLoad::
    call_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_OpenArceus
    end

SinjohRuins_OpenArceus::
    @left stairs
    setmetatile 17, 32, 0x089, FALSE
    setmetatile 17, 33, 0x089, FALSE
    setmetatile 17, 34, 0x089, FALSE
    setmetatile 17, 35, 0x089, FALSE
    setmetatile 17, 36, 0x089, FALSE
    setmetatile 18, 32, 0x091, FALSE
    setmetatile 18, 33, 0x091, FALSE
    setmetatile 18, 34, 0x091, FALSE
    setmetatile 18, 35, 0x091, FALSE
    setmetatile 18, 36, 0x091, FALSE
    setmetatile 19, 32, 0x091, FALSE
    setmetatile 19, 33, 0x091, FALSE
    setmetatile 19, 34, 0x091, FALSE
    setmetatile 19, 35, 0x091, FALSE
    setmetatile 19, 36, 0x091, FALSE
    @right stairs
    setmetatile 29, 32, 0x089, FALSE
    setmetatile 29, 33, 0x089, FALSE
    setmetatile 29, 34, 0x089, FALSE
    setmetatile 29, 35, 0x089, FALSE
    setmetatile 29, 36, 0x089, FALSE
    setmetatile 30, 32, 0x091, FALSE
    setmetatile 30, 33, 0x091, FALSE
    setmetatile 30, 34, 0x091, FALSE
    setmetatile 30, 35, 0x091, FALSE
    setmetatile 30, 36, 0x091, FALSE
    setmetatile 31, 32, 0x091, FALSE
    setmetatile 31, 33, 0x091, FALSE
    setmetatile 31, 34, 0x091, FALSE
    setmetatile 31, 35, 0x091, FALSE
    setmetatile 31, 36, 0x091, FALSE
    return

SinjohRuins_StairsScene::
    lock
    setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
    applymovement LOCALID_PLAYER, SinjohRuins_Movement_PlayerWalkRight
    opendoor 14, 52
	waitdooranim
    addobject LOCALID_SINJOHRUINS_CYNTHIA
    clearflag FLAG_HIDE_SINJOHRUINS_CYNTHIA
    applymovement LOCALID_SINJOHRUINS_CYNTHIA, Common_Movement_WalkDown1
    waitmovement LOCALID_SINJOHRUINS_CYNTHIA
    applymovement LOCALID_SINJOHRUINS_CYNTHIA, SinjohRuins_Movement_CynthiaWalkRight
    waitmovement 0
    closedoor 14, 52
	waitdooranim
    setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
    waitmovement LOCALID_SINJOHRUINS_CYNTHIA
    waitmovement 0
    setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
    special SpawnCameraObject
    applymovement OBJ_EVENT_ID_CAMERA, SinjohRuins_Movement_CameraPanUp
    waitmovement 0
    setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
    setobjectxyperm LOCALID_SINJOHRUINS_CYNTHIA, 19, 52
    setobjectmovementtype LOCALID_SINJOHRUINS_CYNTHIA, MOVEMENT_TYPE_FACE_UP
    call SinjohRuins_OpenArceus
    special DrawWholeMapView
    delay 60
    applymovement OBJ_EVENT_ID_CAMERA, SinjohRuins_Movement_CameraPanDown
    waitmovement 0
    special RemoveCameraObject
    msgbox SinjohRuins_Text_CynthiaGotoStairs1, MSGBOX_AUTOCLOSE
    turnobject LOCALID_SINJOHRUINS_CYNTHIA, DIR_EAST
    delay 10
    turnobject LOCALID_PLAYER, DIR_WEST
    msgbox SinjohRuins_Text_CynthiaGotoStairs2, MSGBOX_AUTOCLOSE
    setvar VAR_SINJOH_STORYLINE, 9
    setvar VAR_PLATECOUNTER, 17
    applymovement LOCALID_SINJOHRUINS_CYNTHIA, SinjohRuins_Movement_CynthiaGoesToStairs
    waitmovement 0
    removeobject LOCALID_SINJOHRUINS_CYNTHIA
    setobjectxyperm LOCALID_SINJOHRUINS_CYNTHIA, 24, 31
    setobjectmovementtype LOCALID_SINJOHRUINS_CYNTHIA, MOVEMENT_TYPE_FACE_UP
    addobject LOCALID_SINJOHRUINS_CYNTHIA
    clearflag FLAG_HIDE_SINJOHRUINS_CYNTHIA
    setflag FLAG_HIDE_SINJOHRUINS_LAB_CYNTHIA
    setvar VAR_SINJOH_STORYLINE, 9
    release
    end

SinjohRuins_Text_CynthiaGotoStairs1:
    .string "CYNTHIA: This could only mean\n"
    .string "one thing.$"

SinjohRuins_Text_CynthiaGotoStairs2:
    .string "{PLAYER}. We were able to decipher\n"
    .string "the rest of the glyphs...\p"
    .string "If the translation is right, \n"
    .string "the POKéMON at the top of that\l"
    .string "staircase is the most powerful\l"
    .string "being in the universe.\p"
    .string "And it is my duty as\n"
    .string "CHAMPION of the SINNOH LEAGUE\l"
    .string "to make sure you are strong\l"
    .string "enough to face it.\p"
    .string "Meet me at that landing\n"
    .string "when you are ready.$"

SinjohRuins_Movement_CynthiaGoesToStairs:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_right
    walk_diag_southeast
    walk_diag_southeast
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

SinjohRuins_Movement_CameraPanDown:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_diag_southwest
    walk_diag_southwest
    walk_diag_southwest
    walk_diag_southwest
    step_end

SinjohRuins_Movement_CameraPanUp:
    walk_diag_northeast
    walk_diag_northeast
    walk_diag_northeast
    walk_diag_northeast
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

SinjohRuins_Movement_CynthiaWalkRight:
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_up
    step_end

SinjohRuins_Movement_PlayerWalkRight:
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_up
    step_end
SinjohRuins_EventScript_TriggerCynthiaBattleRight::
    lock
    turnobject LOCALID_SINJOHRUINS_CYNTHIA, DIR_EAST
    msgbox SinjohRuins_Text_CynthiaReadytoBattle, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_EventScript_TriggerPlayerLeaveRight
    call SinjohRuins_EventScript_CynthiaBattle
    setvar VAR_SINJOH_STORYLINE, 10
    release
    end
SinjohRuins_EventScript_TriggerPlayerLeaveRight::
    closemessage
    applymovement LOCALID_PLAYER, Common_Movement_WalkRight1
    waitmovement 0
    release
    end
SinjohRuins_EventScript_TriggerCynthiaBattleLeft::
    lock
    turnobject LOCALID_SINJOHRUINS_CYNTHIA, DIR_WEST
    msgbox SinjohRuins_Text_CynthiaReadytoBattle, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, SinjohRuins_EventScript_TriggerPlayerLeaveLeft
    call SinjohRuins_EventScript_CynthiaBattle
    setvar VAR_SINJOH_STORYLINE, 10
    release
    end
SinjohRuins_EventScript_TriggerPlayerLeaveLeft::
    closemessage
    applymovement LOCALID_PLAYER, Common_Movement_WalkLeft1
    waitmovement 0
    release
    end 

SinjohRuins_Movement_CynthiaLeaveRight:
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

SinjohRuins_Movement_CynthiaLeaveLeft:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

SinjohRuins_EventScript_CynthiaBattle::
    msgbox SinjohRuins_Text_ChallengeCynthia, MSGBOX_AUTOCLOSE
    trainerbattle_no_intro TRAINER_CYNTHIA_HNS, SinjohRuins_Text_CynthiaDefeat
    msgbox SinjohRuins_Text_CynthiaAfterBattle, MSGBOX_AUTOCLOSE
    giveitem ITEM_STONE_PLATE
    msgbox SinjohRuins_Text_HealParty, MSGBOX_AUTOCLOSE
    fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox SinjohRuins_Text_CynthiaAfterPlate, MSGBOX_AUTOCLOSE
    return

SinjohRuins_Text_HealParty::
    .string "CYNTHIA: Let me heal your POKéMON\n"
    .string "before you go.$"

SinjohRuins_Text_CynthiaAfterPlate:
    .string "CYNTHIA: Good luck, {PLAYER}\p"
    .string "Go on, I'm right behind you.$"

SinjohRuins_Text_CynthiaAfterBattle:
	.string "CYNTHIA: To think, another trainer \n"
	.string "would defeat me like this.\p"
    .string "Incredible.\p"
	.string "Take this, it's the final plate.$"

SinjohRuins_Text_CynthiaReadytoBattle:
    .string "CYNTHIA: {PLAYER}.\p"
    .string "Ever since I first saw the\n"
    .string "determination in your eyes,\l"
    .string "I felt it would lead to this.\p"
    .string "I will test the bond between you\n"
    .string "and your POKéMON.\p"
    .string "Are you ready?$"

SinjohRuins_Text_ChallengeCynthia:
	.string "Then I, CYNTHIA, accept your\n"
	.string "challenge. I won't hold back!$"

SinjohRuins_Text_CynthiaDefeat:
	.string "You...\n"
	.string "You are ready.$"

SinjohRuins_EventScript_Cynthia::
    msgbox SinjohRuins_Text_CynthiaAfterPlate, MSGBOX_NPC
    end

@ BAXCALIBUR guards the temple door like the AZURE FLUTE's NOBLES: it cannot be caught or
@ fled, and once beaten it is gone and the dungeon is open (MIGRATION_DECISIONS.md 82).
@ A whiteout clears the engine flags (B_RESET_FLAGS_VARS_AFTER_WHITEOUT) and leaves it here.
SinjohRuins_EventScript_Baxcalibur::
	lock
	faceplayer
	playmoncry SPECIES_BAXCALIBUR, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_BAXCALIBUR, level=80, item=ITEM_DRAGON_FANG, move1_1=MOVE_GLAIVE_RUSH, move1_2=MOVE_ICICLE_CRASH, move1_3=MOVE_EARTHQUAKE, move1_4=MOVE_SWORDS_DANCE
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 1, 0, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SinjohRuins_EventScript_BaxcaliburRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SINJOHRUINS_BAXCALIBUR
	setflag FLAG_HIDE_SINJOHRUINS_BAXCALIBUR
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox SinjohRuins_Text_BaxcaliburRetreated, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

SinjohRuins_EventScript_BaxcaliburRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

SinjohRuins_Text_BaxcaliburRetreated:
	.string "BAXCALIBUR retreated.\n"
	.string "The way into the ruins is open.$"

SinjohRuins_EventScript_Sign::
    msgbox SinjohRuins_Text_Sign, MSGBOX_SIGN
    end

SinjohRuins_Text_Sign:
    .string "SINJOH RUINS$"

