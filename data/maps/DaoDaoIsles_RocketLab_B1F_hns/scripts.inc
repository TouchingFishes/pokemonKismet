DaoDaoIsles_RocketLab_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_RocketLab_B1F_OnTransition
	.byte 0

DaoDaoIsles_RocketLab_B1F_OnTransition:
	call DaoDaoIsles_RocketLab_B1F_SetKlinklang
	call DaoDaoIsles_RocketLab_B1F_SetGiovanni
	call DaoDaoIsles_RocketLab_B1F_SetGenesect
	end

@ KLINKLANG is the REGISTEEL boss, but it is gated on GIDEON alone - NOT on
@ FLAG_DAODAO_REGIS_ENABLED like the other four. Gating it on the braille riddle
@ would put a puzzle in a different chamber on a different island in front of
@ finishing the KANTO POKeMON FEDERATION arc.
DaoDaoIsles_RocketLab_B1F_SetKlinklang:
	setflag FLAG_HIDE_DAODAO_LAB_KLINKLANG
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_KLINKLANG, DaoDaoIsles_RocketLab_B1F_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_B1F_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_KLINKLANG
	return

DaoDaoIsles_RocketLab_B1F_SetGiovanni:
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_B1F_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_B1F_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_KLINKLANG, DaoDaoIsles_RocketLab_B1F_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	return

DaoDaoIsles_RocketLab_B1F_SetGenesect:
	setflag FLAG_HIDE_DAODAO_LAB_GENESECT
	goto_if_set FLAG_DAODAO_GENESECT_TAKEN, DaoDaoIsles_RocketLab_B1F_Ret
	goto_if_set FLAG_DAODAO_GENESECT_KNOCKED_OUT, DaoDaoIsles_RocketLab_B1F_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_B1F_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GENESECT
	return

DaoDaoIsles_RocketLab_B1F_Ret:
	return

DaoDaoIsles_RocketLab_B1F_EventScript_BossKlinklang::
	lock
	faceplayer
	playmoncry SPECIES_KLINKLANG, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_RocketLab_B1F_Text_KlinklangIntro, MSGBOX_DEFAULT
	closemessage
	setwildbossbattle species=SPECIES_KLINKLANG, level=70, item=ITEM_METAL_COAT, move1_1=MOVE_GEAR_GRIND, move1_2=MOVE_WILD_CHARGE, move1_3=MOVE_FLASH_CANNON, move1_4=MOVE_SHIFT_GEAR
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 1, 1, 0, 0, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_RocketLab_B1F_EventScript_BossStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a win.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_RocketLab_B1F_EventScript_BossStays
	setflag FLAG_DEFEATED_DAODAO_LAB_KLINKLANG
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_KLINKLANG
	setflag FLAG_HIDE_DAODAO_LAB_KLINKLANG
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox DaoDaoIsles_RocketLab_B1F_Text_KlinklangBeaten, MSGBOX_DEFAULT
	closemessage
	goto DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniArrives

DaoDaoIsles_RocketLab_B1F_EventScript_BossStays::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

@ The player takes KLINKLANG's place at (10,4), facing the doorway, and GIOVANNI and PERSIAN come in
@ through it from the hall below (Moritz's layout of 2026-10-27). Their map positions, (10,5) and
@ (11,5), are where they stand to talk, so a player who turns him down and leaves finds them there.
DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniArrives:
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8005, 3, DaoDaoIsles_RocketLab_B1F_EventScript_PlayerFromNorth
	call_if_eq VAR_0x8005, 5, DaoDaoIsles_RocketLab_B1F_EventScript_PlayerFromSouth
	call_if_eq VAR_0x8004, 9, DaoDaoIsles_RocketLab_B1F_EventScript_PlayerFromWest
	call_if_eq VAR_0x8004, 11, DaoDaoIsles_RocketLab_B1F_EventScript_PlayerFromEast
	call DaoDaoIsles_RocketLab_B1F_EventScript_LightsFlicker
	setobjectxyperm LOCALID_DAODAO_LAB_GIOVANNI, 10, 10
	setobjectxyperm LOCALID_DAODAO_LAB_PERSIAN, 11, 10
	clearflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	addobject LOCALID_DAODAO_LAB_GIOVANNI
	addobject LOCALID_DAODAO_LAB_PERSIAN
	call DaoDaoIsles_RocketLab_B1F_EventScript_LightsFlicker
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, DaoDaoIsles_RocketLab_B1F_Movement_CameraToGiovanni
	waitmovement 0
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	playse SE_PIN
	applymovement LOCALID_DAODAO_LAB_GIOVANNI, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_PERSIAN, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement OBJ_EVENT_ID_CAMERA, DaoDaoIsles_RocketLab_B1F_Movement_CameraBack
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_B1F_Movement_GiovanniWalksUp
	applymovement LOCALID_DAODAO_LAB_PERSIAN, DaoDaoIsles_RocketLab_B1F_Movement_PersianWalksUp
	waitmovement LOCALID_DAODAO_LAB_GIOVANNI
	waitmovement LOCALID_DAODAO_LAB_PERSIAN
	setobjectxyperm LOCALID_DAODAO_LAB_GIOVANNI, 10, 5
	setobjectxyperm LOCALID_DAODAO_LAB_PERSIAN, 11, 5
	msgbox DaoDaoIsles_RocketLab_B1F_Text_GiovanniIntro, MSGBOX_DEFAULT
	goto DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniAskReady

DaoDaoIsles_RocketLab_B1F_EventScript_PlayerFromNorth:
	applymovement OBJ_EVENT_ID_PLAYER, DaoDaoIsles_RocketLab_B1F_Movement_PlayerFromNorth
	waitmovement 0
	return

DaoDaoIsles_RocketLab_B1F_EventScript_PlayerFromSouth:
	applymovement OBJ_EVENT_ID_PLAYER, DaoDaoIsles_RocketLab_B1F_Movement_PlayerFromSouth
	waitmovement 0
	return

DaoDaoIsles_RocketLab_B1F_EventScript_PlayerFromWest:
	applymovement OBJ_EVENT_ID_PLAYER, DaoDaoIsles_RocketLab_B1F_Movement_PlayerFromWest
	waitmovement 0
	return

DaoDaoIsles_RocketLab_B1F_EventScript_PlayerFromEast:
	applymovement OBJ_EVENT_ID_PLAYER, DaoDaoIsles_RocketLab_B1F_Movement_PlayerFromEast
	waitmovement 0
	return

DaoDaoIsles_RocketLab_B1F_EventScript_LightsFlicker:
	playse SE_SWITCH
	fadescreenspeed FADE_TO_BLACK, 1
	delay 8
	fadescreenspeed FADE_FROM_BLACK, 1
	delay 4
	playse SE_SWITCH
	fadescreenspeed FADE_TO_BLACK, 1
	delay 16
	fadescreenspeed FADE_FROM_BLACK, 2
	return

DaoDaoIsles_RocketLab_B1F_EventScript_Giovanni::
	lock
	faceplayer
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	goto_if_eq VAR_TEMP_2, 1, DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniAskReady
	msgbox DaoDaoIsles_RocketLab_B1F_Text_GiovanniIntro, MSGBOX_DEFAULT
DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniAskReady:
	msgbox DaoDaoIsles_RocketLab_B1F_Text_GiovanniReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniWaits
	msgbox DaoDaoIsles_RocketLab_B1F_Text_GiovanniShowMe, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GIOVANNI_LAB_HNS, DaoDaoIsles_RocketLab_B1F_Text_GiovanniDefeat
	goto DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniDefeated

DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniWaits:
	setvar VAR_TEMP_2, 1
	msgbox DaoDaoIsles_RocketLab_B1F_Text_GiovanniWaits, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

DaoDaoIsles_RocketLab_B1F_EventScript_Persian::
	lock
	faceplayer
	playmoncry SPECIES_PERSIAN, CRY_MODE_ENCOUNTER
	msgbox DaoDaoIsles_RocketLab_B1F_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniDefeated::
	setflag FLAG_DEFEATED_DAODAO_LAB_GIOVANNI
	msgbox DaoDaoIsles_RocketLab_B1F_Text_GiovanniPostBattle, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_DAODAO_LAB_GIOVANNI, DIR_NORTH
	delay 20
	@ Released at (12,4), on the player's right.
	setobjectxyperm LOCALID_DAODAO_LAB_GENESECT, 12, 4
	playse SE_BALL_THROW
	waitse
	playse SE_M_CHARGE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 10  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE, 1
	fadescreenspeed FADE_FROM_WHITE, 1
	playse SE_M_CHARGE
	fadescreenspeed FADE_TO_WHITE, 1
	clearflag FLAG_HIDE_DAODAO_LAB_GENESECT
	addobject LOCALID_DAODAO_LAB_GENESECT
	playse SE_BALL_OPEN
	fadescreenspeed FADE_FROM_WHITE, 2
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	delay 20
	msgbox DaoDaoIsles_RocketLab_B1F_Text_GiovanniFreesGenesect, MSGBOX_DEFAULT
	closemessage
	playse SE_M_HYPER_BEAM
	applymovement LOCALID_DAODAO_LAB_GENESECT, DaoDaoIsles_RocketLab_B1F_Movement_GenesectStreaksOff
	waitmovement 0
	removeobject LOCALID_DAODAO_LAB_GENESECT
	setobjectxyperm LOCALID_DAODAO_LAB_GENESECT, 3, 11
	addobject LOCALID_DAODAO_LAB_GENESECT
	clearflag FLAG_HIDE_DAODAO_LAB_GENESECT
	msgbox DaoDaoIsles_RocketLab_B1F_Text_GenesectStreaksOff, MSGBOX_DEFAULT
	closemessage
	@ Back out through the doorway, unless the player stands in its columns below them.
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_lt VAR_0x8005, 6, DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniWalksOff
	goto_if_lt VAR_0x8004, 10, DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniWalksOff
	goto_if_gt VAR_0x8004, 11, DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniWalksOff
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GIOVANNI
	removeobject LOCALID_DAODAO_LAB_PERSIAN
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_B1F_EventScript_GiovanniWalksOff:
	applymovement LOCALID_DAODAO_LAB_PERSIAN, DaoDaoIsles_RocketLab_B1F_Movement_PersianWalksOff
	applymovement LOCALID_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_B1F_Movement_GiovanniWalksOff
	waitmovement LOCALID_DAODAO_LAB_PERSIAN
	waitmovement LOCALID_DAODAO_LAB_GIOVANNI
	removeobject LOCALID_DAODAO_LAB_GIOVANNI
	removeobject LOCALID_DAODAO_LAB_PERSIAN
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	release
	end

DaoDaoIsles_RocketLab_B1F_Movement_PlayerFromNorth:
	walk_down
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_PlayerFromSouth:
	walk_up
	face_down
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_PlayerFromWest:
	walk_right
	face_down
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_PlayerFromEast:
	walk_left
	face_down
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_CameraToGiovanni:
	walk_fast_down
	walk_fast_down
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_CameraBack:
	walk_fast_up
	walk_fast_up
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_GiovanniWalksUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_PersianWalksUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_GenesectStreaksOff:
	fly_up
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_PersianWalksOff:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

DaoDaoIsles_RocketLab_B1F_Movement_GiovanniWalksOff:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

DaoDaoIsles_RocketLab_B1F_EventScript_Genesect::
	lock
	faceplayer
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_RocketLab_B1F_Text_Genesect, MSGBOX_DEFAULT
	closemessage
	@ The level of the GENESECT in GIOVANNI's party (TRAINER_GIOVANNI_LAB_HNS).
	seteventmon SPECIES_GENESECT, 84
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_RocketLab_B1F_EventScript_GenesectStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a knockout.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_RocketLab_B1F_EventScript_GenesectStays
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DaoDaoIsles_RocketLab_B1F_EventScript_Genesect_Caught
	@ Knocked out: back after the next Hall of Fame (SpawnDaoDaoLegendaries).
	setflag FLAG_DAODAO_GENESECT_KNOCKED_OUT
	goto DaoDaoIsles_RocketLab_B1F_EventScript_Genesect_Gone

DaoDaoIsles_RocketLab_B1F_EventScript_Genesect_Caught:
	setflag FLAG_DAODAO_GENESECT_TAKEN
DaoDaoIsles_RocketLab_B1F_EventScript_Genesect_Gone:
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GENESECT
	setflag FLAG_HIDE_DAODAO_LAB_GENESECT
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_B1F_EventScript_GenesectStays::
	release
	end

DaoDaoIsles_RocketLab_B1F_Text_KlinklangIntro:
	.string "It has turned in the same spot\n"
	.string "for twenty years.\p"
	.string "No fuel. No maintenance.\n"
	.string "No discernible power source.\p"
	.string "I've examined every gear.\n"
	.string "Those markings aren't decorative.\l"
	.string "They're identical to the ones\n"
	.string "carved into the ruin walls.\p"
	.string "I used to think the ruins were\n"
	.string "built around some great machine.\p"
	.string "Now I'm not so sure.\n"
	.string "Perhaps the machine came first.$"

DaoDaoIsles_RocketLab_B1F_Text_KlinklangBeaten:
	.string "The gears stop.\p"
	.string "For the first time in twenty years,\n"
	.string "the warehouse falls silent.\p"
	.string "Somewhere beneath our feet,\n"
	.string "something answers.\p"
	.string "A deep, metallic groan rolls up\n"
	.string "through the foundations.\p"
	.string "The markings on the gears begin\n"
	.string "to glow. One by one.\p"
	.string "And at the far end of the room…\n"
	.string "something moves.$"

DaoDaoIsles_RocketLab_B1F_Text_GiovanniIntro:
	.string "So the warehouse still had one\n"
	.string "more visitor in it.\p"
	.string "I sank this place because it was\n"
	.string "the only thing I ever regretted\l"
	.string "building.\p"
	.string "Turn around, or I will sink it\n"
	.string "again with you inside.$"

DaoDaoIsles_RocketLab_B1F_Text_GiovanniReady:
	.string "GIOVANNI: Your POKéMON have just\n"
	.string "fought that machine to a standstill.\p"
	.string "I will not insult either of us by\n"
	.string "fighting them like that.\p"
	.string "Well? Are you ready?$"

DaoDaoIsles_RocketLab_B1F_Text_GiovanniShowMe:
	.string "GIOVANNI: Then show me.$"

DaoDaoIsles_RocketLab_B1F_Text_GiovanniWaits:
	.string "GIOVANNI: Tend to them, then.\p"
	.string "I have waited twenty years. I can\n"
	.string "wait a little longer.$"

DaoDaoIsles_RocketLab_B1F_Text_Persian:
	.string "PERSIAN: Mrrrowr…!$"

DaoDaoIsles_RocketLab_B1F_Text_GenesectStreaksOff:
	.string "GENESECT streaked off into the\n"
	.string "dark!$"

DaoDaoIsles_RocketLab_B1F_Text_GiovanniDefeat:
	.string "Enough.$"

DaoDaoIsles_RocketLab_B1F_Text_GiovanniPostBattle:
	.string "Gideon drew it. I paid for it.\p"
	.string "Neither of us could ever switch\n"
	.string "it off.\p"
	.string "Twenty years I have kept it on a\n"
	.string "belt, because I did not trust\l"
	.string "anyone else to.$"

DaoDaoIsles_RocketLab_B1F_Text_GiovanniFreesGenesect:
	.string "GIOVANNI released GENESECT.\p"
	.string "I am done carrying it.\p"
	.string "It was never mine. It was only\n"
	.string "ever pointed somewhere.\p"
	.string "If it follows you, that is your\n"
	.string "burden now.$"

DaoDaoIsles_RocketLab_B1F_Text_Genesect:
	.string "The cannon on its back swivels\n"
	.string "and locks on.$"
