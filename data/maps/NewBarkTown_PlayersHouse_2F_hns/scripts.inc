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
@ Three jobs, all of them shortcuts past a lot of play:
@   GREEN   - sets every prerequisite her encounter needs, hands over a party
@             that can fight her (she is L75-80) and warps to OAK'S LAB.
@   FUCHSIA - hands over the same party and drops the player in the ROUTE 15
@             gate house, where a second test NPC sets the KANTO POKeMON
@             FEDERATION stages. The stage setter lives out there rather than
@             in here because the arc's flags only take effect when FUCHSIA
@             LOADS - see the long note in that gate house's scripts.inc.
@   SILVER 7 - fights SILVER's last encounter (INDIGO PLATEAU, L68-70) for any
@             starter region and any of his three starters, right here.
@ ===========================================================================
NewBarkTown_PlayersHouse_2F_EventScript_GreenTestNpc::
	lock
	faceplayer
	message NewBarkTown_PlayersHouse_2F_Text_TestAsk
	waitmessage
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, NewBarkTown_PlayersHouse_2F_Text_TestOptGreen, NewBarkTown_PlayersHouse_2F_Text_TestOptFuchsia, NewBarkTown_PlayersHouse_2F_Text_TestOptSilver7, NewBarkTown_PlayersHouse_2F_Text_TestOptCancel
	goto_if_eq VAR_RESULT, 0, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestGreen
	goto_if_eq VAR_RESULT, 1, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestFuchsia
	goto_if_eq VAR_RESULT, 2, NewBarkTown_PlayersHouse_2F_EventScript_Silver7Test
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

@ SILVER's encounter 7. It fights the same JOHTO trainer ID the real encounter
@ uses (IndigoPlateau_PokemonCenter_hns), so GetRivalTrainerIdForStarterChoice
@ and GetRivalAceOverride resolve it exactly as they would for a player of the
@ chosen region: the shared party, the ace swap, the AI and the items are all
@ the real ones. 6 regions x 3 starters = all 18 of his final teams.
@
@ ⚠️ It SETS VAR_STARTER_REGION and leaves it set - that is what makes the
@ redirect pick the region's party, and a loss whites out before any script
@ could put it back. The player's own starter is already caught and does not
@ change; the dex's starter window and every later SILVER fight follow the new
@ region. Fine on a test save, which is what this NPC is for.
@
@ The region menu is ordered by the STARTER_REGION_* constants (JOHTO 0 ...
@ KALOS 5), which is why the choice can be copied straight into the var.
NewBarkTown_PlayersHouse_2F_EventScript_Silver7Test::
	message NewBarkTown_PlayersHouse_2F_Text_Silver7Region
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, NewBarkTown_PlayersHouse_2F_Text_RegionJohto, NewBarkTown_PlayersHouse_2F_Text_RegionKanto, NewBarkTown_PlayersHouse_2F_Text_RegionHoenn, NewBarkTown_PlayersHouse_2F_Text_RegionSinnoh, NewBarkTown_PlayersHouse_2F_Text_RegionUnova, NewBarkTown_PlayersHouse_2F_Text_RegionKalos
	goto_if_ge VAR_RESULT, STARTER_REGION_COUNT, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline
	copyvar VAR_0x8005, VAR_RESULT
	message NewBarkTown_PlayersHouse_2F_Text_Silver7Slot
	waitmessage
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, NewBarkTown_PlayersHouse_2F_Text_SlotGrass, NewBarkTown_PlayersHouse_2F_Text_SlotFire, NewBarkTown_PlayersHouse_2F_Text_SlotWater
	@ 0 / 1 / 2 are STARTER_SLOT_GRASS / _FIRE / _WATER. Those live in
	@ include/starter_generation.h, which event scripts cannot see.
	goto_if_eq VAR_RESULT, 0, NewBarkTown_PlayersHouse_2F_EventScript_Silver7Grass
	goto_if_eq VAR_RESULT, 1, NewBarkTown_PlayersHouse_2F_EventScript_Silver7Fire
	goto_if_eq VAR_RESULT, 2, NewBarkTown_PlayersHouse_2F_EventScript_Silver7Water
	goto NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline

@ The trainer flag the win sets is cleared again: the real encounter repeats
@ daily on FLAG_DAILY_BEAT_SILVER and never reads it, but a test should leave
@ no trace it does not have to.
NewBarkTown_PlayersHouse_2F_EventScript_Silver7Grass::
	call NewBarkTown_PlayersHouse_2F_EventScript_Silver7Setup
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_7_HNS, NewBarkTown_PlayersHouse_2F_Text_Silver7Beaten
	cleartrainerflag TRAINER_RIVAL_CHIKORITA_7_HNS
	goto NewBarkTown_PlayersHouse_2F_EventScript_Silver7Done

NewBarkTown_PlayersHouse_2F_EventScript_Silver7Fire::
	call NewBarkTown_PlayersHouse_2F_EventScript_Silver7Setup
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_7_HNS, NewBarkTown_PlayersHouse_2F_Text_Silver7Beaten
	cleartrainerflag TRAINER_RIVAL_CYNDAQUIL_7_HNS
	goto NewBarkTown_PlayersHouse_2F_EventScript_Silver7Done

NewBarkTown_PlayersHouse_2F_EventScript_Silver7Water::
	call NewBarkTown_PlayersHouse_2F_EventScript_Silver7Setup
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_7_HNS, NewBarkTown_PlayersHouse_2F_Text_Silver7Beaten
	cleartrainerflag TRAINER_RIVAL_TOTODILE_7_HNS
	goto NewBarkTown_PlayersHouse_2F_EventScript_Silver7Done

NewBarkTown_PlayersHouse_2F_EventScript_Silver7Setup::
	copyvar VAR_STARTER_REGION, VAR_0x8005
	msgbox NewBarkTown_PlayersHouse_2F_Text_Silver7Party, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty
	special HealPlayerParty
	msgbox NewBarkTown_PlayersHouse_2F_Text_Silver7Go, MSGBOX_DEFAULT
	closemessage
	return

NewBarkTown_PlayersHouse_2F_EventScript_Silver7Done::
	special HealPlayerParty
	msgbox NewBarkTown_PlayersHouse_2F_Text_Silver7Done, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_PlayersHouse_2F_Text_TestAsk:
	.string "TEST: What do you want to try?\p"
	.string "GREEN and FUCHSIA hand you a\n"
	.string "level 95 party first.$"

NewBarkTown_PlayersHouse_2F_Text_TestOptGreen:
	.string "GREEN at OAK'S LAB$"

NewBarkTown_PlayersHouse_2F_Text_TestOptFuchsia:
	.string "FUCHSIA FEDERATION$"

NewBarkTown_PlayersHouse_2F_Text_TestOptSilver7:
	.string "SILVER battle 7$"

NewBarkTown_PlayersHouse_2F_Text_Silver7Region:
	.string "TEST: Which starter region?\p"
	.string "It stays set afterwards.$"

NewBarkTown_PlayersHouse_2F_Text_RegionJohto:
	.string "JOHTO$"

NewBarkTown_PlayersHouse_2F_Text_RegionKanto:
	.string "KANTO$"

NewBarkTown_PlayersHouse_2F_Text_RegionHoenn:
	.string "HOENN$"

NewBarkTown_PlayersHouse_2F_Text_RegionSinnoh:
	.string "SINNOH$"

NewBarkTown_PlayersHouse_2F_Text_RegionUnova:
	.string "UNOVA$"

NewBarkTown_PlayersHouse_2F_Text_RegionKalos:
	.string "KALOS$"

NewBarkTown_PlayersHouse_2F_Text_Silver7Slot:
	.string "TEST: Which starter does SILVER\n"
	.string "have?$"

NewBarkTown_PlayersHouse_2F_Text_SlotGrass:
	.string "GRASS starter$"

NewBarkTown_PlayersHouse_2F_Text_SlotFire:
	.string "FIRE starter$"

NewBarkTown_PlayersHouse_2F_Text_SlotWater:
	.string "WATER starter$"

NewBarkTown_PlayersHouse_2F_Text_Silver7Party:
	.string "TEST: Take the level 95 party\n"
	.string "too?$"

NewBarkTown_PlayersHouse_2F_Text_Silver7Go:
	.string "TEST: Your party is healed.\n"
	.string "Here he comes!$"

NewBarkTown_PlayersHouse_2F_Text_Silver7Beaten:
	.string "…\p"
	.string "OK--I lost…$"

NewBarkTown_PlayersHouse_2F_Text_Silver7Done:
	.string "TEST: Done. Your party is healed\n"
	.string "again. Talk to me for another go.$"

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
	.string "head west into the city.$"

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
