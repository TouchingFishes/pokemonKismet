PokemonLeague_ChampionsRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChampionRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_ChampionsRoom_OnTransition
	.byte 0

PokemonLeague_ChampionsRoom_OnTransition:
	setflag FLAG_TEMP_HIDE_CHALLENGER
	@ MARY and OAK only appear through addobject, which ignores this flag. Route 27 is the
	@ only other place that sets it, so a player who never walked it saw them standing here.
	setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
	end

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	special DoPokemonLeagueLightingEffect
	end

ChampionRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, ChampionRoom_CloseDoor
	.2byte 0

ChampionRoom_CloseDoor::
	lock
	setflag FLAG_TEMP_2
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, ChamionRoom_Movement_Enter
	waitmovement 0
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_IS_KANTO_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_TitleDefense
	release
	end

ChamionRoom_Movement_Enter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ChampionRoom_Trigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

PokemonLeague_WillsRoom_EventScript_Lance::
	lockall
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest
	faceplayer
	goto_if_unset FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_LanceFirstBattle
	goto_if_set FLAG_BADGE16_GET, PokemonLeague_WillsRoom_EventScript_LanceRematch

PokemonLeague_ChampionsRoom_EventScript_LanceFirstBattle::
	msgbox PokemonLeague_ChampionsRoom_Text_BattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_1_HNS, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatJohto

PokemonLeague_WillsRoom_EventScript_LanceRematch::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchBattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_2_HNS, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto

PokemonLeague_WillsRoom_EventScript_LanceOnDefeatJohto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_LANCE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_MARY
	msgbox PokemonLeague_ChampionsRoom_Text_MaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_HNS, 0
	waitstate
	releaseall
	end

PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_LANCE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_RematchOakCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_RematchMaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_MARY
	msgbox PokemonLeague_ChampionsRoom_Text_RematchMaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_HNS, 0
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest
	waitmovement 0
	return

PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast:
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth:
	walk_left
	walk_down
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest:
	walk_down
	walk_left
	face_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceMoveOver:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_2
	walk_in_place_fast_down
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryMoveOver:
	walk_left
	face_right
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryInterview:
	walk_fast_up
	walk_in_place_fast_right
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceAnxious:
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_left
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceLeave:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PokemonLeague_ChampionsRoom_Text_RematchBattleIntro:
    .string "LANCE: Welcome back!\p"
    .string "You've proven yourself in JOHTO,\p"
    .string "acquiring all 8 badges and even\n"
    .string "besting me once.\p"
    .string "But now, you're in the big\n"
    .string "leagues.\p"
    .string "The KANTO LEAGUE!\p"
    .string "A region with its own trials and\n"
    .string "champions.\p"
    .string "Here, I am the final challenge,\n"
    .string "with a team stronger than ever\l"
    .string "before.\p"
    .string "This is the true test,\p"
    .string "a battle to determine the\n"
    .string "CHAMPION of KANTO.\p"
    .string "Are you ready to rise to this new\n"
    .string "challenge?\p"
    .string "To prove yourself once more?\p"
    .string "Show me the strength that\n"
    .string "conquered JOHTO, CHAMPION.$"

PokemonLeague_ChampionsRoom_Text_BattleIntro:
    .string "LANCE: I've been waiting for you.\p"
    .string "{PLAYER}!\p"
    .string "I knew that you, with your skills,\n"
    .string "would eventually reach me here.\p"
    .string "There's no need for words now.\p"
    .string "We will battle to determine who is\n"
    .string "the stronger of the two of us.\p"
    .string "As the most powerful trainer and as\n"
    .string "the POKéMON LEAGUE CHAMPION…\p"
    .string "I, LANCE the dragon master, accept\n"
    .string "your challenge!$"

PokemonLeague_ChampionsRoom_Text_BattleWin:
    .string "…It's over.\p"
    .string "But it's an odd feeling.\p"
    .string "I'm not angry that I lost. In fact,\n"
    .string "I feel happy.\p"
    .string "Happy that I witnessed the rise\n"
    .string "of a great new CHAMPION!$"

PokemonLeague_ChampionsRoom_Text_BattleAfter:
    .string "…Whew.\p"
    .string "You have become truly powerful,\n"
    .string "{PLAYER}.\p"
    .string "Your POKéMON have responded to your\n"
    .string "strong and upstanding nature.\p"
    .string "As a trainer, you will continue to\n"
    .string "grow strong with your POKéMON.$"

PokemonLeague_ChampionsRoom_Text_MaryOhNoOak:
    .string "MARY: Oh, no! It's all over!\p"
    .string "PROF.OAK, if you weren't so slow…$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations:
    .string "PROF.OAK: Ah, {PLAYER}!\p"
    .string "It's been a long while.\p"
    .string "You certainly look more impressive.\p"
    .string "Your conquest of the JOHTO LEAGUE\n"
    .string "is just fantastic!\p"
    .string "Your dedication, trust and love for\n"
    .string "your POKéMON made this happen.\p"
    .string "Your POKéMON were outstanding too.\p"
    .string "Because they believed in you as a\n"
    .string "trainer, they persevered.\p"
    .string "Congratulations, {PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_RematchOakCongratulations:
    .string "PROF.OAK: Ah, {PLAYER}!\p"
    .string "I've been following your progress\n"
    .string "since PROF.ELM sent you on your\l"
    .string "way.\p"
    .string "You've certainly become more\n"
    .string "impressive.\p"
    .string "Conquering both the JOHTO and now\n"
    .string "the KANTO LEAGUE is no small feat.\p"
    .string "You've truly outdone yourself!\p"
    .string "It's clear that your POKéMON trust\n"
    .string "you immensely,\p"
    .string "and that trust has been the\n"
    .string "foundation of your success.\p"
    .string "But remember, a trainer's journey\n"
    .string "is never truly over.\p"
    .string "Congratulations on your victory,\n"
    .string "{PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_MaryInterview:
    .string "MARY: Let's interview the brand new\n"
    .string "JOHTO CHAMPION!$"

PokemonLeague_ChampionsRoom_Text_RematchMaryInterview:
    .string "MARY: Let's interview the brand new\n"
    .string "KANTO CHAMPION!$"

PokemonLeague_ChampionsRoom_Text_Noisy:
    .string "LANCE: This is getting to be a bit\n"
    .string "too noisy…\p"
    .string "{PLAYER}, could you come with me?$"

PokemonLeague_ChampionsRoom_Text_MaryNoInterview:
    .string "MARY: Oh, wait! We haven't done\n"
    .string "the interview!$"

PokemonLeague_ChampionsRoom_Text_RematchMaryNoInterview:
    .string "MARY: Come on! You can't blow off\n"
    .string "the interview AGAIN!$"

@ ===========================================================================
@ TITLE DEFENSE (MIGRATION_DECISIONS.md 81), finished from the fork's half-built challenger
@ system. Once the KANTO title is won, LANCE no longer waits here (his object hides on
@ FLAG_IS_KANTO_CHAMPION): the player takes his place and a challenger comes up the stairs -
@ one at random from everyone whose LAST battle elsewhere the player has won. A locked slot
@ simply re-rolls; LANCE is always open, so the pick always lands. Like LANCE's own victory,
@ it ends in the HALL OF FAME (VAR_LEAGUE_STATE 6), which records the defense and runs the
@ usual post-game respawns.
@
@ Gates are each challenger's last battle, never their challenger team's own flag. A trainer
@ the HALL OF FAME refreshes (cleartrainerflag) must never be a gate - LORELEI, AGATHA, MORI,
@ SARI and the HOENN ELITE FOUR are - or the challenger would lock again after every run.
@ VAR_TEMP_1 marks a two-object challenge (TATE & LIZA).
@ ===========================================================================
PokemonLeague_ChampionsRoom_EventScript_TitleDefense::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerToChampionSpot
	waitmovement 0
	delay 30
	msgbox PokemonLeague_ChampionsRoom_Text_ChallengerApproaches, MSGBOX_DEFAULT
	closemessage
PokemonLeague_ChampionsRoom_EventScript_PickChallenger:
	random 18
	switch VAR_RESULT
	case 0, PokemonLeague_ChampionsRoom_EventScript_TryLance
	case 1, PokemonLeague_ChampionsRoom_EventScript_TryCynthia
	case 2, PokemonLeague_ChampionsRoom_EventScript_TryEusine
	case 3, PokemonLeague_ChampionsRoom_EventScript_TryGiovanni
	case 4, PokemonLeague_ChampionsRoom_EventScript_TryGreen
	case 5, PokemonLeague_ChampionsRoom_EventScript_TryBlue
	case 6, PokemonLeague_ChampionsRoom_EventScript_TryClair
	case 7, PokemonLeague_ChampionsRoom_EventScript_TryIris
	case 8, PokemonLeague_ChampionsRoom_EventScript_TryAlder
	case 9, PokemonLeague_ChampionsRoom_EventScript_TrySteven
	case 10, PokemonLeague_ChampionsRoom_EventScript_TryRoxanne
	case 11, PokemonLeague_ChampionsRoom_EventScript_TryBrawly
	case 12, PokemonLeague_ChampionsRoom_EventScript_TryWattson
	case 13, PokemonLeague_ChampionsRoom_EventScript_TryFlannery
	case 14, PokemonLeague_ChampionsRoom_EventScript_TryNorman
	case 15, PokemonLeague_ChampionsRoom_EventScript_TryWinona
	case 16, PokemonLeague_ChampionsRoom_EventScript_TryTateAndLiza
	case 17, PokemonLeague_ChampionsRoom_EventScript_TryWallace
	goto PokemonLeague_ChampionsRoom_EventScript_PickChallenger

PokemonLeague_ChampionsRoom_EventScript_TryLance:
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLance

PokemonLeague_ChampionsRoom_EventScript_TryCynthia:
	goto_if_not_defeated TRAINER_CYNTHIA_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerCynthia

PokemonLeague_ChampionsRoom_EventScript_TryEusine:
	goto_if_not_defeated TRAINER_EUSINE_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerEusine

PokemonLeague_ChampionsRoom_EventScript_TryGiovanni:
	goto_if_not_defeated TRAINER_GIOVANNI_LAB_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerGiovanni

PokemonLeague_ChampionsRoom_EventScript_TryGreen:
	goto_if_not_defeated TRAINER_GREEN_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerGreen

PokemonLeague_ChampionsRoom_EventScript_TryBlue:
	goto_if_not_defeated TRAINER_BLUE_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerBlue

PokemonLeague_ChampionsRoom_EventScript_TryClair:
	goto_if_not_defeated TRAINER_CLAIR_2_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerClair

PokemonLeague_ChampionsRoom_EventScript_TryIris:
	goto_if_not_defeated TRAINER_IRIS_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerIris

PokemonLeague_ChampionsRoom_EventScript_TryAlder:
	goto_if_not_defeated TRAINER_ALDER_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerAlder

PokemonLeague_ChampionsRoom_EventScript_TrySteven:
	goto_if_unset FLAG_DEFEATED_DAODAO_STEVEN, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerSteven

PokemonLeague_ChampionsRoom_EventScript_TryRoxanne:
	goto_if_not_defeated TRAINER_LEADER_ROXANNE_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerRoxanne

PokemonLeague_ChampionsRoom_EventScript_TryBrawly:
	goto_if_not_defeated TRAINER_LEADER_BRAWLY_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerBrawly

PokemonLeague_ChampionsRoom_EventScript_TryWattson:
	goto_if_not_defeated TRAINER_LEADER_WATTSON_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerWattson

PokemonLeague_ChampionsRoom_EventScript_TryFlannery:
	goto_if_not_defeated TRAINER_LEADER_FLANNERY_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerFlannery

PokemonLeague_ChampionsRoom_EventScript_TryNorman:
	goto_if_not_defeated TRAINER_LEADER_NORMAN_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerNorman

PokemonLeague_ChampionsRoom_EventScript_TryWinona:
	goto_if_not_defeated TRAINER_LEADER_WINONA_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerWinona

PokemonLeague_ChampionsRoom_EventScript_TryTateAndLiza:
	goto_if_not_defeated TRAINER_LEADER_TATE_AND_LIZA_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_lt VAR_RESULT, 2, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerTateAndLiza

PokemonLeague_ChampionsRoom_EventScript_TryWallace:
	goto_if_not_defeated TRAINER_LEADER_WALLACE_HNS, PokemonLeague_ChampionsRoom_EventScript_PickChallenger
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerWallace

PokemonLeague_ChampionsRoom_EventScript_ChallengerLance:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LANCE_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_LanceChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_LANCE_HNS, PokemonLeague_ChampionsRoom_Text_LanceChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_LanceChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerCynthia:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CYNTHIA_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_CynthiaChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_CYNTHIA_HNS, PokemonLeague_ChampionsRoom_Text_CynthiaChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_CynthiaChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerEusine:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_EUSINE_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_EusineChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_EUSINE_HNS, PokemonLeague_ChampionsRoom_Text_EusineChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_EusineChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerGiovanni:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GIOVANNI_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_GiovanniChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_GIOVANNI_HNS, PokemonLeague_ChampionsRoom_Text_GiovanniChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_GiovanniChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerGreen:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GREEN_NPC_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_GreenChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_GREEN_HNS, PokemonLeague_ChampionsRoom_Text_GreenChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_GreenChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerBlue:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BLUE_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_BlueChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_BLUE_HNS, PokemonLeague_ChampionsRoom_Text_BlueChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_BlueChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerClair:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CLAIR_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_ClairChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_CLAIR_HNS, PokemonLeague_ChampionsRoom_Text_ClairChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_ClairChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerIris:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_IRIS_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_IrisChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_IRIS_HNS, PokemonLeague_ChampionsRoom_Text_IrisChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_IrisChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerAlder:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ALDER_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_AlderChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_ALDER_HNS, PokemonLeague_ChampionsRoom_Text_AlderChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_AlderChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerSteven:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_STEVEN_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_StevenChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_STEVEN_HNS, PokemonLeague_ChampionsRoom_Text_StevenChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_StevenChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerRoxanne:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ROXANNE_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_RoxanneChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_LEADER_ROXANNE_HNS, PokemonLeague_ChampionsRoom_Text_RoxanneChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_RoxanneChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerBrawly:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRAWLY_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_BrawlyChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_LEADER_BRAWLY_HNS, PokemonLeague_ChampionsRoom_Text_BrawlyChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_BrawlyChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerWattson:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WATTSON_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_WattsonChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_LEADER_WATTSON_HNS, PokemonLeague_ChampionsRoom_Text_WattsonChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_WattsonChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerFlannery:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_FLANNERY_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_FlanneryChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_LEADER_FLANNERY_HNS, PokemonLeague_ChampionsRoom_Text_FlanneryChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_FlanneryChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerNorman:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_NORMAN_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_NormanChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_NORMAN_HNS, PokemonLeague_ChampionsRoom_Text_NormanChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_NormanChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerWinona:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WINONA_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_WinonaChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_CHALLENGER_WINONA_HNS, PokemonLeague_ChampionsRoom_Text_WinonaChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_WinonaChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerTateAndLiza:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_TATE_HNS
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LIZA_HNS
	setvar VAR_TEMP_1, 1
	call PokemonLeague_ChampionsRoom_EventScript_ChallengersEnter
	msgbox PokemonLeague_ChampionsRoom_Text_TateAndLizaChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_LEADER_TATE_AND_LIZA_HNS, PokemonLeague_ChampionsRoom_Text_TateAndLizaChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_TateAndLizaChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerWallace:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WALLACE_HNS
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter
	msgbox PokemonLeague_ChampionsRoom_Text_WallaceChallengerIntro, MSGBOX_DEFAULT
	call PokemonLeague_ChampionsRoom_EventScript_ChallengerLights
	trainerbattle_no_intro TRAINER_LEADER_WALLACE_HNS, PokemonLeague_ChampionsRoom_Text_WallaceChallengerDefeat
	msgbox PokemonLeague_ChampionsRoom_Text_WallaceChallengerOutro, MSGBOX_DEFAULT
	goto PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave

PokemonLeague_ChampionsRoom_EventScript_ChallengerEnter:
	addobject LOCALID_LEAGUE_CHALLENGER
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement LOCALID_LEAGUE_CHALLENGER
	return

PokemonLeague_ChampionsRoom_EventScript_ChallengersEnter:
	addobject LOCALID_LEAGUE_CHALLENGER
	addobject LOCALID_LEAGUE_CHALLENGER_2
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	applymovement LOCALID_LEAGUE_CHALLENGER_2, PokemonLeague_ChampionsRoom_Movement_ChallengerApproach
	waitmovement LOCALID_LEAGUE_CHALLENGER
	waitmovement LOCALID_LEAGUE_CHALLENGER_2
	return

@ As before LANCE's battle: FLAG_TEMP_3 cancels the lighting effect when the map resumes and
@ FLAG_TEMP_5 pauses it meanwhile (DoPokemonLeagueLightingEffect, src/field_specials.c).
PokemonLeague_ChampionsRoom_EventScript_ChallengerLights:
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	return

PokemonLeague_ChampionsRoom_EventScript_ChallengerLeave:
	closemessage
	clearflag FLAG_TEMP_5
	applymovement LOCALID_LEAGUE_CHALLENGER, PokemonLeague_ChampionsRoom_Movement_ChallengerLeave
	call_if_eq VAR_TEMP_1, 1, PokemonLeague_ChampionsRoom_EventScript_SecondChallengerLeave
	waitmovement LOCALID_LEAGUE_CHALLENGER
	removeobject LOCALID_LEAGUE_CHALLENGER
	call_if_eq VAR_TEMP_1, 1, PokemonLeague_ChampionsRoom_EventScript_SecondChallengerRemove
	playse SE_EXIT
	delay 20
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement 0
	playse SE_EXIT
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_HNS, 0
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_SecondChallengerLeave:
	applymovement LOCALID_LEAGUE_CHALLENGER_2, PokemonLeague_ChampionsRoom_Movement_ChallengerLeave
	return

PokemonLeague_ChampionsRoom_EventScript_SecondChallengerRemove:
	waitmovement LOCALID_LEAGUE_CHALLENGER_2
	removeobject LOCALID_LEAGUE_CHALLENGER_2
	return

@ From the door's landing (6,13) to LANCE's spot (6,8), turning to face the stairs.
PokemonLeague_ChampionsRoom_Movement_PlayerToChampionSpot:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

@ Up the corridor from (x,17) to (x,9), one step below the player.
PokemonLeague_ChampionsRoom_Movement_ChallengerApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_ChallengerLeave:
	face_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonLeague_ChampionsRoom_Text_ChallengerApproaches:
	.string "Footsteps echo up the stairs…\p"
	.string "A challenger has come for the\n"
	.string "CHAMPION's title!$"

PokemonLeague_ChampionsRoom_Text_LanceChallengerIntro:
	.string "LANCE: So, we meet again.\p"
	.string "You have already proven yourself\n"
	.string "worthy of the title CHAMPION.\p"
	.string "But a title is merely a title.\p"
	.string "Let us see whether your strength\n"
	.string "can withstand the power of DRAGON\l"
	.string "POKéMON once more!$"

PokemonLeague_ChampionsRoom_Text_LanceChallengerDefeat:
	.string "LANCE: Incredible!\p"
	.string "Your strength has grown beyond\n"
	.string "what I imagined.$"

PokemonLeague_ChampionsRoom_Text_LanceChallengerOutro:
	.string "LANCE: I have no doubt now.\p"
	.string "You truly belong among the world's\n"
	.string "greatest trainers.$"

PokemonLeague_ChampionsRoom_Text_CynthiaChallengerIntro:
	.string "CYNTHIA: Oh, how wonderful!\p"
	.string "I've been hoping we'd meet again.\p"
	.string "There are few things I enjoy more\n"
	.string "than discovering what makes a\l"
	.string "great trainer truly great.\p"
	.string "Shall we discover it together?$"

PokemonLeague_ChampionsRoom_Text_CynthiaChallengerDefeat:
	.string "CYNTHIA: Ah… extraordinary.\p"
	.string "You've grown even stronger since\n"
	.string "our last battle.$"

PokemonLeague_ChampionsRoom_Text_CynthiaChallengerOutro:
	.string "CYNTHIA: What a fascinating battle.\p"
	.string "I wonder how much farther you can go.\n"
	.string "I certainly hope we meet again.$"

PokemonLeague_ChampionsRoom_Text_EusineChallengerIntro:
	.string "EUSINE: {PLAYER}! It's me, EUSINE!\p"
	.string "While I chased SUICUNE across\n"
	.string "JOHTO and KANTO, you became\l"
	.string "CHAMPION!\p"
	.string "Show me the strength that\n"
	.string "impressed even SUICUNE!$"

PokemonLeague_ChampionsRoom_Text_EusineChallengerDefeat:
	.string "EUSINE: I see now why SUICUNE\n"
	.string "chose you.$"

PokemonLeague_ChampionsRoom_Text_EusineChallengerOutro:
	.string "EUSINE: I'll keep chasing the\n"
	.string "legends.\p"
	.string "And you'll keep chasing the top!$"

PokemonLeague_ChampionsRoom_Text_GiovanniChallengerIntro:
	.string "GIOVANNI: So… the CHAMPION has come\n"
	.string "to test themselves against me.\p"
	.string "How predictable.\p"
	.string "Power is not inherited.\n"
	.string "It is seized by those capable\l"
	.string "of wielding it.\p"
	.string "Come, then.\n"
	.string "Let us see who truly possesses it.$"

PokemonLeague_ChampionsRoom_Text_GiovanniChallengerDefeat:
	.string "GIOVANNI: Hmph…\p"
	.string "It seems your reputation was not\n"
	.string "entirely undeserved.$"

PokemonLeague_ChampionsRoom_Text_GiovanniChallengerOutro:
	.string "GIOVANNI: Enjoy your victory.\p"
	.string "There will always be someone\n"
	.string "stronger waiting beyond it.$"

PokemonLeague_ChampionsRoom_Text_GreenChallengerIntro:
	.string "GREEN: So you're sitting in LANCE's\n"
	.string "old spot now?\p"
	.string "Don't get too comfortable.\n"
	.string "I came here to take it from you!$"

PokemonLeague_ChampionsRoom_Text_GreenChallengerDefeat:
	.string "GREEN: Ugh… Fine!\n"
	.string "You earned that seat.$"

PokemonLeague_ChampionsRoom_Text_GreenChallengerOutro:
	.string "GREEN: Next time, I'm taking that\n"
	.string "title.\p"
	.string "Don't you dare lose to anyone\n"
	.string "else before then!$"

PokemonLeague_ChampionsRoom_Text_BlueChallengerIntro:
	.string "BLUE: Smell ya later? Not today!\p"
	.string "I was the CHAMPION once too, you\n"
	.string "know.\p"
	.string "Let's see if you can hold on to\n"
	.string "the title better than I did!$"

PokemonLeague_ChampionsRoom_Text_BlueChallengerDefeat:
	.string "BLUE: Tch…\n"
	.string "You're the real deal.$"

PokemonLeague_ChampionsRoom_Text_BlueChallengerOutro:
	.string "BLUE: Don't let it go to your head.\p"
	.string "I'll be back, and next time the\n"
	.string "title's mine!$"

PokemonLeague_ChampionsRoom_Text_ClairChallengerIntro:
	.string "CLAIR: Hmph. So you're the CHAMPION\n"
	.string "everyone keeps talking about.\p"
	.string "Don't expect me to be impressed\n"
	.string "just because you defeated me before.\p"
	.string "This time, I'll show you what a true\n"
	.string "DRAGON MASTER can do!$"

PokemonLeague_ChampionsRoom_Text_ClairChallengerDefeat:
	.string "CLAIR: What?! Again?!\p"
	.string "I refuse to believe you're\n"
	.string "this strong!$"

PokemonLeague_ChampionsRoom_Text_ClairChallengerOutro:
	.string "CLAIR: …Fine.\p"
	.string "I'll admit it.\n"
	.string "You've earned your place here.$"

PokemonLeague_ChampionsRoom_Text_IrisChallengerIntro:
	.string "IRIS: Hiya! It's me, IRIS!\p"
	.string "I came all the way from UNOVA to\n"
	.string "battle the CHAMPION!\p"
	.string "My dragons and I are super ready!$"

PokemonLeague_ChampionsRoom_Text_IrisChallengerDefeat:
	.string "IRIS: Waaah!\n"
	.string "You're amazing!$"

PokemonLeague_ChampionsRoom_Text_IrisChallengerOutro:
	.string "IRIS: That was so much fun!\p"
	.string "I'm gonna train even harder with\n"
	.string "my dragons, just you wait!$"

PokemonLeague_ChampionsRoom_Text_AlderChallengerIntro:
	.string "ALDER: Hahaha! So you're the\n"
	.string "CHAMPION now!\p"
	.string "Let an old wanderer see how\n"
	.string "brightly your bonds burn!$"

PokemonLeague_ChampionsRoom_Text_AlderChallengerDefeat:
	.string "ALDER: Splendid!\n"
	.string "Your bonds burn bright!$"

PokemonLeague_ChampionsRoom_Text_AlderChallengerOutro:
	.string "ALDER: A CHAMPION isn't the one\n"
	.string "who wins every battle…\p"
	.string "but the one who never stops\n"
	.string "caring for their POKéMON.\p"
	.string "You understand that already.$"

PokemonLeague_ChampionsRoom_Text_StevenChallengerIntro:
	.string "STEVEN: I was curious when I heard\n"
	.string "that you had become CHAMPION.\p"
	.string "A CHAMPION should never stop seeking\n"
	.string "new challenges.\p"
	.string "Let us test the strength you've\n"
	.string "gathered on your journey.$"

PokemonLeague_ChampionsRoom_Text_StevenChallengerDefeat:
	.string "STEVEN: Fascinating…\p"
	.string "Your strength continues to develop\n"
	.string "like a precious stone under pressure.$"

PokemonLeague_ChampionsRoom_Text_StevenChallengerOutro:
	.string "STEVEN: Wonderful.\p"
	.string "A battle like this reminds me why\n"
	.string "I became a trainer in the first place.$"

PokemonLeague_ChampionsRoom_Text_RoxanneChallengerIntro:
	.string "ROXANNE: I've reviewed every battle\n"
	.string "you fought on your way here.\p"
	.string "A CHAMPION should pass any test.\n"
	.string "This is your final exam!$"

PokemonLeague_ChampionsRoom_Text_RoxanneChallengerDefeat:
	.string "ROXANNE: Full marks…\n"
	.string "I have nothing left to teach you.$"

PokemonLeague_ChampionsRoom_Text_RoxanneChallengerOutro:
	.string "ROXANNE: I'll tell my students all\n"
	.string "about this battle.\p"
	.string "The CHAMPION who passed every\n"
	.string "test I could set!$"

PokemonLeague_ChampionsRoom_Text_BrawlyChallengerIntro:
	.string "BRAWLY: Yo, CHAMPION!\p"
	.string "I rode the biggest wave of my life\n"
	.string "all the way up here.\p"
	.string "Let's see if you can wipe me out\n"
	.string "again!$"

PokemonLeague_ChampionsRoom_Text_BrawlyChallengerDefeat:
	.string "BRAWLY: Wipeout!\n"
	.string "What a ride, though!$"

PokemonLeague_ChampionsRoom_Text_BrawlyChallengerOutro:
	.string "BRAWLY: Man, you're like a tidal\n"
	.string "wave.\p"
	.string "I'm heading back to the sea to\n"
	.string "train harder!$"

PokemonLeague_ChampionsRoom_Text_WattsonChallengerIntro:
	.string "WATTSON: Wahahahah!\p"
	.string "The CHAMPION's room! My old heart\n"
	.string "is positively crackling!\p"
	.string "Let's see if you can still handle\n"
	.string "the shock!$"

PokemonLeague_ChampionsRoom_Text_WattsonChallengerDefeat:
	.string "WATTSON: Wahahahah!\n"
	.string "I've been short-circuited!$"

PokemonLeague_ChampionsRoom_Text_WattsonChallengerOutro:
	.string "WATTSON: You keep a current running\n"
	.string "through everything you do.\p"
	.string "Wahahahah! Fine work, CHAMPION!$"

PokemonLeague_ChampionsRoom_Text_FlanneryChallengerIntro:
	.string "FLANNERY: I came all this way with\n"
	.string "my fire burning hotter than ever!\p"
	.string "Don't you dare cool off now,\n"
	.string "CHAMPION!$"

PokemonLeague_ChampionsRoom_Text_FlanneryChallengerDefeat:
	.string "FLANNERY: Whew!\n"
	.string "On the verge of eruption!$"

PokemonLeague_ChampionsRoom_Text_FlanneryChallengerOutro:
	.string "FLANNERY: I lost, but I'm still\n"
	.string "all fired up!\p"
	.string "I'll be back with an even hotter\n"
	.string "team!$"

PokemonLeague_ChampionsRoom_Text_NormanChallengerIntro:
	.string "NORMAN: A CHAMPION should never\n"
	.string "become complacent.\p"
	.string "Strength must be tested constantly,\n"
	.string "or it will begin to fade.\p"
	.string "Come.\n"
	.string "Let us see how strong you've become.$"

PokemonLeague_ChampionsRoom_Text_NormanChallengerDefeat:
	.string "NORMAN: I see…\p"
	.string "Your training has brought you\n"
	.string "considerably farther than before.$"

PokemonLeague_ChampionsRoom_Text_NormanChallengerOutro:
	.string "NORMAN: Excellent.\p"
	.string "Continue challenging yourself.\n"
	.string "That is how true strength is built.$"

PokemonLeague_ChampionsRoom_Text_WinonaChallengerIntro:
	.string "WINONA: The winds carried word of\n"
	.string "your victory to me.\p"
	.string "Yet even the strongest winds can\n"
	.string "change direction without warning.\p"
	.string "Let us take to the skies once more.\p"
	.string "Show me how high a CHAMPION can fly!$"

PokemonLeague_ChampionsRoom_Text_WinonaChallengerDefeat:
	.string "WINONA: The wind has shifted…\p"
	.string "And once again, you stand above me.$"

PokemonLeague_ChampionsRoom_Text_WinonaChallengerOutro:
	.string "WINONA: Magnificent.\p"
	.string "Your spirit soars higher than ever.$"

PokemonLeague_ChampionsRoom_Text_TateAndLizaChallengerIntro:
	.string "TATE: Hehehe…\n"
	.string "We were waiting for you, CHAMPION.\p"
	.string "LIZA: Fufufu…\n"
	.string "We saw this battle coming.\p"
	.string "TATE: Our combination…\p"
	.string "LIZA: …is perfect!$"

PokemonLeague_ChampionsRoom_Text_TateAndLizaChallengerDefeat:
	.string "TATE: We couldn't…\n"
	.string "LIZA: …see that coming!$"

PokemonLeague_ChampionsRoom_Text_TateAndLizaChallengerOutro:
	.string "LIZA: You read our moves as if you\n"
	.string "were one of us.\p"
	.string "TATE: We'll train our minds and\n"
	.string "come back stronger!$"

PokemonLeague_ChampionsRoom_Text_WallaceChallengerIntro:
	.string "WALLACE: Ah, the CHAMPION.\p"
	.string "I have dreamed of a battle on this\n"
	.string "stage, against a trainer like you.\p"
	.string "Let us make it a performance\n"
	.string "worthy of the audience!$"

PokemonLeague_ChampionsRoom_Text_WallaceChallengerDefeat:
	.string "WALLACE: Bravo!\n"
	.string "A truly elegant victory.$"

PokemonLeague_ChampionsRoom_Text_WallaceChallengerOutro:
	.string "WALLACE: You and your POKéMON move\n"
	.string "as one. That is true beauty.\p"
	.string "I shall remember this battle\n"
	.string "for a long time.$"
