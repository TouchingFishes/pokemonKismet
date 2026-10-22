DaoDaoIsles_RocketLab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_RocketLab_OnTransition
	.byte 0

DaoDaoIsles_RocketLab_OnTransition:
	call DaoDaoIsles_RocketLab_SetGideon
	call DaoDaoIsles_RocketLab_SetKlinklang
	call DaoDaoIsles_RocketLab_SetGiovanni
	call DaoDaoIsles_RocketLab_SetGenesect
	call DaoDaoIsles_RocketLab_SetAssistant
	end

DaoDaoIsles_RocketLab_SetGideon:
	setflag FLAG_HIDE_DAODAO_LAB_GIDEON
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GIDEON
	return

@ KLINKLANG is the REGISTEEL boss, but it is gated on GIDEON alone - NOT on
@ FLAG_DAODAO_REGIS_ENABLED like the other four. Gating it on the braille riddle
@ would put a puzzle in a different chamber on a different island in front of
@ finishing the KANTO POKeMON FEDERATION arc.
DaoDaoIsles_RocketLab_SetKlinklang:
	setflag FLAG_HIDE_DAODAO_BOSS_REGISTEEL
	goto_if_set FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_BOSS_REGISTEEL
	return

DaoDaoIsles_RocketLab_SetGiovanni:
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	return

DaoDaoIsles_RocketLab_SetGenesect:
	setflag FLAG_HIDE_DAODAO_LAB_GENESECT
	goto_if_set FLAG_DAODAO_GENESECT_TAKEN, DaoDaoIsles_RocketLab_Ret
	goto_if_set FLAG_DAODAO_GENESECT_KNOCKED_OUT, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GENESECT
	return

@ The assistant who stayed behind, at GIDEON's desk once he is gone - the KLINK and KLANG
@ have no wild slot since the Alola tables went, so this is where the line comes from.
@ No hide flag of its own: FLAG_TEMP_11 is derived here on every load.
DaoDaoIsles_RocketLab_SetAssistant:
	setflag FLAG_TEMP_11
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_TEMP_11
	return

DaoDaoIsles_RocketLab_Ret:
	return

DaoDaoIsles_RocketLab_EventScript_Assistant::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DAODAO_LAB_KLINK, DaoDaoIsles_RocketLab_EventScript_AssistantAfter
	msgbox DaoDaoIsles_RocketLab_Text_AssistantKlink, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KLINK
	bufferspeciesname STR_VAR_1, SPECIES_KLINK
	givemon SPECIES_KLINK, 43
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, DaoDaoIsles_RocketLab_EventScript_AssistantNoRoom
	call Common_EventScript_GiftMon
	setflag FLAG_RECEIVED_DAODAO_LAB_KLINK
DaoDaoIsles_RocketLab_EventScript_AssistantAfter:
	msgbox DaoDaoIsles_RocketLab_Text_AssistantAfter, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_RocketLab_EventScript_AssistantNoRoom:
	msgbox DaoDaoIsles_RocketLab_Text_AssistantNoRoom, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_RocketLab_Text_AssistantKlink:
	.string "DR. GIDEON is gone, and the rest of\n"
	.string "the staff with him.\p"
	.string "Somebody had to stay and feed the\n"
	.string "KLINK.\p"
	.string "It came off the big one at the far\n"
	.string "end. One gear, years ago. It has\l"
	.string "been turning in a box under my\l"
	.string "desk ever since.\p"
	.string "Take it. It's the only thing in this\n"
	.string "room that never hurt anybody.$"

DaoDaoIsles_RocketLab_Text_AssistantAfter:
	.string "Gears like that don't belong in a\n"
	.string "box.$"

DaoDaoIsles_RocketLab_Text_AssistantNoRoom:
	.string "You've got no room for it. Come back\n"
	.string "when you do.$"

DaoDaoIsles_RocketLab_EventScript_Cueball1::
	trainerbattle_single TRAINER_DAODAO_LAB_CUEBALL_1_HNS, DaoDaoIsles_RocketLab_Text_Cueball1Intro, DaoDaoIsles_RocketLab_Text_Cueball1Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Cueball1Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Scientist1::
	trainerbattle_single TRAINER_DAODAO_LAB_SCIENTIST_1_HNS, DaoDaoIsles_RocketLab_Text_Scientist1Intro, DaoDaoIsles_RocketLab_Text_Scientist1Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Scientist1Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Cueball2::
	trainerbattle_single TRAINER_DAODAO_LAB_CUEBALL_2_HNS, DaoDaoIsles_RocketLab_Text_Cueball2Intro, DaoDaoIsles_RocketLab_Text_Cueball2Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Cueball2Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Scientist2::
	trainerbattle_single TRAINER_DAODAO_LAB_SCIENTIST_2_HNS, DaoDaoIsles_RocketLab_Text_Scientist2Intro, DaoDaoIsles_RocketLab_Text_Scientist2Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Scientist2Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Gideon::
	trainerbattle_single TRAINER_GIDEON_HNS, DaoDaoIsles_RocketLab_Text_GideonIntro, DaoDaoIsles_RocketLab_Text_GideonDefeat, DaoDaoIsles_RocketLab_EventScript_GideonDefeated
	end

DaoDaoIsles_RocketLab_EventScript_GideonDefeated::
	setvar VAR_FUCHSIA_FEDERATION_STATE, 6
	call Common_EventScript_ClearKantoCordon
	setflag FLAG_DEFEATED_DAODAO_LAB_GIDEON
	msgbox DaoDaoIsles_RocketLab_Text_GideonPostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GIDEON
	setflag FLAG_HIDE_DAODAO_LAB_GIDEON
	clearflag FLAG_HIDE_DAODAO_BOSS_REGISTEEL
	addobject LOCALID_DAODAO_BOSS_REGISTEEL
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_EventScript_BossKlinklang::
	lock
	faceplayer
	playmoncry SPECIES_KLINKLANG, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_RocketLab_Text_KlinklangIntro, MSGBOX_DEFAULT
	closemessage
	setwildbossbattle species=SPECIES_KLINKLANG, level=70, item=ITEM_METAL_COAT, move1_1=MOVE_GEAR_GRIND, move1_2=MOVE_WILD_CHARGE, move1_3=MOVE_FLASH_CANNON, move1_4=MOVE_SHIFT_GEAR
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 1, 1, 0, 0, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_RocketLab_EventScript_BossStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a win.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_RocketLab_EventScript_BossStays
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_BOSS_REGISTEEL
	setflag FLAG_HIDE_DAODAO_BOSS_REGISTEEL
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox DaoDaoIsles_RocketLab_Text_KlinklangBeaten, MSGBOX_DEFAULT
	closemessage
	goto DaoDaoIsles_RocketLab_EventScript_GiovanniArrives

DaoDaoIsles_RocketLab_EventScript_BossStays::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_RocketLab_EventScript_GiovanniArrives:
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8005, 13, DaoDaoIsles_RocketLab_EventScript_PlayerFromNorth
	call_if_eq VAR_0x8004, 10, DaoDaoIsles_RocketLab_EventScript_PlayerFromWest
	call_if_eq VAR_0x8004, 12, DaoDaoIsles_RocketLab_EventScript_PlayerFromEast
	call DaoDaoIsles_RocketLab_EventScript_LightsFlicker
	clearflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	addobject LOCALID_DAODAO_LAB_GIOVANNI
	addobject LOCALID_DAODAO_LAB_PERSIAN
	call DaoDaoIsles_RocketLab_EventScript_LightsFlicker
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, DaoDaoIsles_RocketLab_Movement_CameraToGiovanni
	waitmovement 0
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	playse SE_PIN
	applymovement LOCALID_DAODAO_LAB_GIOVANNI, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_PERSIAN, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement OBJ_EVENT_ID_CAMERA, DaoDaoIsles_RocketLab_Movement_CameraBack
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_Movement_GiovanniWalksUp
	applymovement LOCALID_DAODAO_LAB_PERSIAN, DaoDaoIsles_RocketLab_Movement_PersianWalksUp
	waitmovement LOCALID_DAODAO_LAB_GIOVANNI
	waitmovement LOCALID_DAODAO_LAB_PERSIAN
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniIntro, MSGBOX_DEFAULT
	goto DaoDaoIsles_RocketLab_EventScript_GiovanniAskReady

DaoDaoIsles_RocketLab_EventScript_PlayerFromNorth:
	applymovement OBJ_EVENT_ID_PLAYER, DaoDaoIsles_RocketLab_Movement_PlayerFromNorth
	waitmovement 0
	return

DaoDaoIsles_RocketLab_EventScript_PlayerFromWest:
	applymovement OBJ_EVENT_ID_PLAYER, DaoDaoIsles_RocketLab_Movement_PlayerFromWest
	waitmovement 0
	return

DaoDaoIsles_RocketLab_EventScript_PlayerFromEast:
	applymovement OBJ_EVENT_ID_PLAYER, DaoDaoIsles_RocketLab_Movement_PlayerFromEast
	waitmovement 0
	return

DaoDaoIsles_RocketLab_EventScript_LightsFlicker:
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

DaoDaoIsles_RocketLab_EventScript_Giovanni::
	lock
	faceplayer
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	goto_if_eq VAR_TEMP_2, 1, DaoDaoIsles_RocketLab_EventScript_GiovanniAskReady
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniIntro, MSGBOX_DEFAULT
DaoDaoIsles_RocketLab_EventScript_GiovanniAskReady:
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_RocketLab_EventScript_GiovanniWaits
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniShowMe, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GIOVANNI_LAB_HNS, DaoDaoIsles_RocketLab_Text_GiovanniDefeat
	goto DaoDaoIsles_RocketLab_EventScript_GiovanniDefeated

DaoDaoIsles_RocketLab_EventScript_GiovanniWaits:
	setvar VAR_TEMP_2, 1
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniWaits, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

DaoDaoIsles_RocketLab_EventScript_Persian::
	lock
	faceplayer
	playmoncry SPECIES_PERSIAN, CRY_MODE_ENCOUNTER
	msgbox DaoDaoIsles_RocketLab_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DaoDaoIsles_RocketLab_EventScript_GiovanniDefeated::
	setflag FLAG_DEFEATED_DAODAO_LAB_GIOVANNI
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniPostBattle, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_DAODAO_LAB_GIOVANNI, DIR_NORTH
	delay 20
	getobjectxy LOCALID_DAODAO_LAB_GIOVANNI, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
	subvar VAR_0x8005, 2
	setobjectxyperm LOCALID_DAODAO_LAB_GENESECT, VAR_0x8004, VAR_0x8005
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
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniFreesGenesect, MSGBOX_DEFAULT
	closemessage
	playse SE_M_HYPER_BEAM
	applymovement LOCALID_DAODAO_LAB_GENESECT, DaoDaoIsles_RocketLab_Movement_GenesectStreaksOff
	waitmovement 0
	removeobject LOCALID_DAODAO_LAB_GENESECT
	setobjectxyperm LOCALID_DAODAO_LAB_GENESECT, 4, 5
	addobject LOCALID_DAODAO_LAB_GENESECT
	clearflag FLAG_HIDE_DAODAO_LAB_GENESECT
	msgbox DaoDaoIsles_RocketLab_Text_GenesectStreaksOff, MSGBOX_DEFAULT
	closemessage
	getobjectxy LOCALID_DAODAO_LAB_GIOVANNI, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 11, DaoDaoIsles_RocketLab_EventScript_GiovanniWalksOff
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GIOVANNI
	removeobject LOCALID_DAODAO_LAB_PERSIAN
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_EventScript_GiovanniWalksOff:
	applymovement LOCALID_DAODAO_LAB_PERSIAN, DaoDaoIsles_RocketLab_Movement_PersianWalksOff
	applymovement LOCALID_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_Movement_GiovanniWalksOff
	waitmovement LOCALID_DAODAO_LAB_PERSIAN
	waitmovement LOCALID_DAODAO_LAB_GIOVANNI
	removeobject LOCALID_DAODAO_LAB_GIOVANNI
	removeobject LOCALID_DAODAO_LAB_PERSIAN
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	release
	end

DaoDaoIsles_RocketLab_Movement_PlayerFromNorth:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	face_up
	step_end

DaoDaoIsles_RocketLab_Movement_PlayerFromWest:
	walk_right
	face_up
	step_end

DaoDaoIsles_RocketLab_Movement_PlayerFromEast:
	walk_left
	face_up
	step_end

DaoDaoIsles_RocketLab_Movement_CameraToGiovanni:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

DaoDaoIsles_RocketLab_Movement_CameraBack:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

DaoDaoIsles_RocketLab_Movement_GiovanniWalksUp:
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
	walk_right
	walk_down
	step_end

DaoDaoIsles_RocketLab_Movement_PersianWalksUp:
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
	walk_down
	step_end

DaoDaoIsles_RocketLab_Movement_GenesectStreaksOff:
	fly_up
	step_end

DaoDaoIsles_RocketLab_Movement_PersianWalksOff:
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

DaoDaoIsles_RocketLab_Movement_GiovanniWalksOff:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DaoDaoIsles_RocketLab_EventScript_Genesect::
	lock
	faceplayer
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_RocketLab_Text_Genesect, MSGBOX_DEFAULT
	closemessage
	seteventmon SPECIES_GENESECT, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_RocketLab_EventScript_GenesectStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a knockout.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_RocketLab_EventScript_GenesectStays
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DaoDaoIsles_RocketLab_EventScript_Genesect_Caught
	@ Knocked out: back after the next Hall of Fame (SpawnDaoDaoLegendaries).
	setflag FLAG_DAODAO_GENESECT_KNOCKED_OUT
	goto DaoDaoIsles_RocketLab_EventScript_Genesect_Gone

DaoDaoIsles_RocketLab_EventScript_Genesect_Caught:
	setflag FLAG_DAODAO_GENESECT_TAKEN
DaoDaoIsles_RocketLab_EventScript_Genesect_Gone:
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GENESECT
	setflag FLAG_HIDE_DAODAO_LAB_GENESECT
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_EventScript_GenesectStays::
	release
	end

DaoDaoIsles_RocketLab_Text_Cueball1Intro:
	.string "The boss said no visitors.\p"
	.string "The boss is very clear about\n"
	.string "things like that.$"

DaoDaoIsles_RocketLab_Text_Cueball1Defeat:
	.string "Didn't see that coming.$"

DaoDaoIsles_RocketLab_Text_Cueball1Post:
	.string "He's still here, you know.\p"
	.string "Never goes up. Never goes home.$"

DaoDaoIsles_RocketLab_Text_Scientist1Intro:
	.string "You are contaminating a sealed\n"
	.string "site.\p"
	.string "I will have to log this.$"

DaoDaoIsles_RocketLab_Text_Scientist1Defeat:
	.string "My figures were correct!$"

DaoDaoIsles_RocketLab_Text_Scientist1Post:
	.string "We were told it was defensive.\p"
	.string "Nothing with a cannon bolted to\n"
	.string "its spine is defensive.$"

DaoDaoIsles_RocketLab_Text_Cueball2Intro:
	.string "Turn around, kid.\p"
	.string "There's nothing back there worth\n"
	.string "the walk.$"

DaoDaoIsles_RocketLab_Text_Cueball2Defeat:
	.string "All right, all right!$"

DaoDaoIsles_RocketLab_Text_Cueball2Post:
	.string "Don't look it in the eye.\p"
	.string "It remembers faces.$"

DaoDaoIsles_RocketLab_Text_Scientist2Intro:
	.string "Fascinating. An uninvited\n"
	.string "variable.\p"
	.string "Let us see how you perform.$"

DaoDaoIsles_RocketLab_Text_Scientist2Defeat:
	.string "An unhelpful result.$"

DaoDaoIsles_RocketLab_Text_Scientist2Post:
	.string "We kept it fed and we kept it\n"
	.string "still.\p"
	.string "That was the whole of the work.$"

DaoDaoIsles_RocketLab_Text_GideonIntro:
	.string "Don't touch that. Or that.\p"
	.string "You took my FEDERATION apart in\n"
	.string "FUCHSIA, and now you've come to\l"
	.string "take apart my lab.\p"
	.string "PAXTON was the muscle. I was\n"
	.string "the reason he had any.\p"
	.string "Let's see if you understand\n"
	.string "what you're breaking.$"

DaoDaoIsles_RocketLab_Text_GideonDefeat:
	.string "Crude. Effective, but crude.$"

DaoDaoIsles_RocketLab_Text_GideonPostBattle:
	.string "I wanted one thing in twenty\n"
	.string "years that GIOVANNI's money\l"
	.string "never touched.\p"
	.string "The FEDERATION lasted a month\n"
	.string "before it was his again in all\l"
	.string "but the name.\p"
	.string "He's here. The far end of the\n"
	.string "floor. He never left.\p"
	.string "The thing between you was in\n"
	.string "the ruins before any of us.\l"
	.string "It has never powered down.\l"
	.string "Mind it.$"

DaoDaoIsles_RocketLab_Text_KlinklangIntro:
	.string "It has been turning on the same\n"
	.string "spot for twenty years.\p"
	.string "The gears are cut with the same\n"
	.string "marks as the ruin walls.$"

DaoDaoIsles_RocketLab_Text_KlinklangBeaten:
	.string "The gears stop.\p"
	.string "For the first time in twenty years\n"
	.string "the warehouse is quiet, and the\l"
	.string "far end of it is not empty.$"

DaoDaoIsles_RocketLab_Text_GiovanniIntro:
	.string "So the warehouse still had one\n"
	.string "more visitor in it.\p"
	.string "I sank this place because it was\n"
	.string "the only thing I ever regretted\l"
	.string "building.\p"
	.string "Turn around, or I will sink it\n"
	.string "again with you inside.$"

DaoDaoIsles_RocketLab_Text_GiovanniReady:
	.string "GIOVANNI: Your POKéMON have just\n"
	.string "fought that machine to a standstill.\p"
	.string "I will not insult either of us by\n"
	.string "fighting them like that.\p"
	.string "Well? Are you ready?$"

DaoDaoIsles_RocketLab_Text_GiovanniShowMe:
	.string "GIOVANNI: Then show me.$"

DaoDaoIsles_RocketLab_Text_GiovanniWaits:
	.string "GIOVANNI: Tend to them, then.\p"
	.string "I have waited twenty years. I can\n"
	.string "wait a little longer.$"

DaoDaoIsles_RocketLab_Text_Persian:
	.string "PERSIAN: Mrrrowr…!$"

DaoDaoIsles_RocketLab_Text_GenesectStreaksOff:
	.string "GENESECT streaked off into the\n"
	.string "dark!$"

DaoDaoIsles_RocketLab_Text_GiovanniDefeat:
	.string "Enough.$"

DaoDaoIsles_RocketLab_Text_GiovanniPostBattle:
	.string "Gideon drew it. I paid for it.\p"
	.string "Neither of us could ever switch\n"
	.string "it off.\p"
	.string "Twenty years I have kept it on a\n"
	.string "belt, because I did not trust\l"
	.string "anyone else to.$"

DaoDaoIsles_RocketLab_Text_GiovanniFreesGenesect:
	.string "GIOVANNI released GENESECT.\p"
	.string "I am done carrying it.\p"
	.string "It was never mine. It was only\n"
	.string "ever pointed somewhere.\p"
	.string "If it follows you, that is your\n"
	.string "burden now.$"

DaoDaoIsles_RocketLab_Text_Genesect:
	.string "The cannon on its back swivels\n"
	.string "and locks on.$"
