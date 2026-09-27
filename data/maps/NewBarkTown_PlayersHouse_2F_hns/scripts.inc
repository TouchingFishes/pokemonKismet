NewBarkTown_PlayersHouse_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NewBarkTown_PlayersHouse_2F_OnWarp
	.byte 0

NewBarkTown_PlayersHouse_2F_OnTransition::
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

NewBarkTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, NewBarkTown_PlayersHouse_2F_OnWarp_SetDecoration
	.2byte 0

NewBarkTown_PlayersHouse_2F_OnWarp_SetDecoration::
	call SecretBase_EventScript_InitDecorations
	end

NewBarkTown_PlayersHouse_2F_Script_ClockSetupTrigger1::
    lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
    applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_2F_Movement_PlayerWalkToClock1
	waitmovement 0
    msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	call PlayerHouse_2F_EventScript_AskWeekDay
	setvar VAR_NEWBARK_TOWN_STATE, 1
	setflag FLAG_SET_WALL_CLOCK
	helpwindow HELP_GAMESTART_WINDOW
	releaseall
	end

NewBarkTown_PlayersHouse_2F_Script_ClockSetupTrigger2::
    lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
    applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_PlayersHouse_2F_Movement_PlayerWalkToClock2
    msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	call PlayerHouse_2F_EventScript_AskWeekDay
	setvar VAR_NEWBARK_TOWN_STATE, 1
	setflag FLAG_SET_WALL_CLOCK
	helpwindow HELP_GAMESTART_WINDOW
	releaseall
	end

NewBarkTown_PlayersHouse_2F_Movement_PlayerWalkToClock1:
	walk_right
	walk_up
	delay_8
	step_end

NewBarkTown_PlayersHouse_2F_Movement_PlayerWalkToClock2:	
	walk_up
	delay_8
	step_end

@ ===========================================================================
@ TEMPORARY TEST NPC - REMOVE BEFORE RELEASE.
@ Also delete his object_event from map.json (5,5) and every Test text below.
@
@ Two jobs, both of them shortcuts past a lot of play:
@   GREEN   - sets every prerequisite her encounter needs, hands over a party
@             that can fight her (she is L75-80) and warps to OAK'S LAB.
@   FUCHSIA - hands over the same party and drops the player in the ROUTE 15
@             gate house, where a second test NPC sets the KANTO POKeMON
@             FEDERATION stages. The stage setter lives out there rather than
@             in here because the arc's flags only take effect when FUCHSIA
@             LOADS - see the long note in that gate house's scripts.inc.
@ ===========================================================================
NewBarkTown_PlayersHouse_2F_EventScript_GreenTestNpc::
	lock
	faceplayer
	message NewBarkTown_PlayersHouse_2F_Text_TestAsk
	waitmessage
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, NewBarkTown_PlayersHouse_2F_Text_TestOptGreen, NewBarkTown_PlayersHouse_2F_Text_TestOptFuchsia, NewBarkTown_PlayersHouse_2F_Text_TestOptCancel
	goto_if_eq VAR_RESULT, 0, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestGreen
	goto_if_eq VAR_RESULT, 1, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestFuchsia
	goto NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline

NewBarkTown_PlayersHouse_2F_EventScript_GreenTestGreen::
	@ GREEN spawns on FLAG_IS_KANTO_CHAMPION and despawns for good on
	@ FLAG_DEFEATED_PALLET_LAB_GREEN, so clear that one to allow re-testing.
	setflag FLAG_IS_CHAMPION
	setflag FLAG_IS_KANTO_CHAMPION
	clearflag FLAG_DEFEATED_PALLET_LAB_GREEN
	clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	@ VAR_PALLETTOWN_LABSTATE 1 is "already met OAK", so talking to him routes
	@ to the badge check rather than the first-visit greeting.
	setvar VAR_PALLETTOWN_LABSTATE, 1
	setvar VAR_NUM_BADGES, 16
	setflag FLAG_BADGE16_GET
	call NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty
	msgbox NewBarkTown_PlayersHouse_2F_Text_GreenTestGo, MSGBOX_DEFAULT
	closemessage
	warp MAP_PALLET_TOWN_LAB_HNS, 13, 20
	waitstate
	end

@ ⚠️ Deliberately sets NO federation flags or vars. The gate house NPC owns
@ all of that, and setting a stage in here would be wasted anyway: the player
@ still has to walk into FUCHSIA for it to show, which is the whole reason the
@ stage setter sits out at the gate.
NewBarkTown_PlayersHouse_2F_EventScript_GreenTestFuchsia::
	call NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty
	msgbox NewBarkTown_PlayersHouse_2F_Text_FuchsiaTestGo, MSGBOX_DEFAULT
	closemessage
	warp MAP_FUCHSIA_CITY_ROUTE15_GATE_HNS, 6, 5
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty::
	givemon SPECIES_TYPHLOSION, 95
	givemon SPECIES_LUCARIO, 95
	givemon SPECIES_MILOTIC, 95
	givemon SPECIES_ALAKAZAM, 95
	givemon SPECIES_HYDREIGON, 95
	givemon SPECIES_AERODACTYL, 95
	special HealPlayerParty
	return

NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline::
	msgbox NewBarkTown_PlayersHouse_2F_Text_GreenTestNoThanks, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_PlayersHouse_2F_Text_TestAsk:
	.string "TEST: What do you want to try?\p"
	.string "Either one hands you a level 95\n"
	.string "party first.$"

NewBarkTown_PlayersHouse_2F_Text_TestOptGreen:
	.string "GREEN at OAK'S LAB$"

NewBarkTown_PlayersHouse_2F_Text_TestOptFuchsia:
	.string "FUCHSIA FEDERATION$"

NewBarkTown_PlayersHouse_2F_Text_TestOptCancel:
	.string "Nothing$"

NewBarkTown_PlayersHouse_2F_Text_GreenTestGo:
	.string "TEST: You'll arrive at the LAB\n"
	.string "door.\p"
	.string "Walk north through the gap in the\n"
	.string "middle wall to trip the cutscene.$"

NewBarkTown_PlayersHouse_2F_Text_FuchsiaTestGo:
	.string "TEST: You'll arrive in the ROUTE 15\n"
	.string "gate house, east of FUCHSIA.\p"
	.string "The man in there sets any stage of\n"
	.string "the FEDERATION arc. Pick one, then\l"
	.string "head west into the city.\p"
	.string "Stages 2 and up want STEVEN to have\n"
	.string "greeted you at the SAFARI ZONE\l"
	.string "first. He'll tell you.$"

NewBarkTown_PlayersHouse_2F_Text_GreenTestNoThanks:
	.string "TEST: Talk to me again when\n"
	.string "you're ready.$"

NewBarkTown_PlayersHouse_2F_EventScript_NES::
	msgbox NewBarkTown_PlayersHouse_2F_Text_NES, MSGBOX_SIGN
	end

NewBarkTown_PlayersHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_PLAYER_HOUSE_HNS
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

NewBarkTown_PlayersHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYER_HOUSE_HNS
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

NewBarkTown_PlayersHouse_2F_Text_NES:
    .string "{PLAYER} played with the NES.\p"
    .string "…Okay!\n"
    .string "It's time to go!$"

PlayersHouse_2F_Text_OversleptWhatDay:
	.string "Huh…? I totally overslept!\p"
	.string "Wait…\n"
	.string "what day is it again?$"
