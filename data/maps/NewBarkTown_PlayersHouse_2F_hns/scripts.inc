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
@ Four jobs, all of them shortcuts past a lot of play:
@   GREEN   - sets every prerequisite her encounter needs, hands over a party
@             that can fight her (she is L75-80) and warps to OAK'S LAB.
@   FUCHSIA - hands over the same party and drops the player in the ROUTE 15
@             gate house, where a second test NPC sets the KANTO POKeMON
@             FEDERATION stages. The stage setter lives out there rather than
@             in here because the arc's flags only take effect when FUCHSIA
@             LOADS - see the long note in that gate house's scripts.inc.
@   OLIVINE GATE - replays the ROCKET robbery in the ROUTE 39 / OLIVINE gate,
@             which otherwise expires once the fifth badge is set.
@   KIMONO GIRLS - the ECRUTEAK THEATER gauntlet before LUGIA or HO-OH.
@   FOXFIRE - sets any stage of the NINETALES story and warps to where it plays.
@   DOLL SHRINE - resets the MIMIKYU hide-and-seek and warps to the shrine in
@             DAODAO's ETERNA FOREST (MIGRATION_DECISIONS.md 60).
@   ROCKET LAB - any of the DAODAO lab's four steps, the earlier ones marked done.
@   CHALLENGERS - the KANTO title, all 16 badges and every CHAMPION's ROOM challenger's
@             unlock battle, then the CHAMPION's ROOM door (MIGRATION_DECISIONS.md 81).
@
@ Talking to him at all opens the start menu's POKeDEX, and its POKeMON entry once the player
@ has a POKeMON (TestMenuFlags), so a save that used him early can look at both like any other.
@
@ Whichever test is picked, the player is asked first whether to take the test kit
@ (TestBasics): the eight JOHTO badges, the RUNNING SHOES and the eight HMs, a TOWN MAP
@ and MAX REPELs, and a full POKeDEX (every obtainable species seen and caught). NO
@ leaves the save's own progress alone, so a test can be played on from where the save
@ really is. FOXFIRE's LAKE start needs the badges for the path north of the hermit's
@ house.
@ ===========================================================================
NewBarkTown_PlayersHouse_2F_EventScript_GreenTestNpc::
	lock
	faceplayer
	call NewBarkTown_PlayersHouse_2F_EventScript_TestMenuFlags
	message NewBarkTown_PlayersHouse_2F_Text_TestAsk
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, NewBarkTown_PlayersHouse_2F_Text_TestOptGreen, NewBarkTown_PlayersHouse_2F_Text_TestOptFuchsia, NewBarkTown_PlayersHouse_2F_Text_TestOptOlivineGate, NewBarkTown_PlayersHouse_2F_Text_TestOptKimono, NewBarkTown_PlayersHouse_2F_Text_TestOptFoxfire, NewBarkTown_PlayersHouse_2F_Text_TestOptShrine, NewBarkTown_PlayersHouse_2F_Text_TestOptRocketLab, NewBarkTown_PlayersHouse_2F_Text_TestOptChallengers, NewBarkTown_PlayersHouse_2F_Text_TestOptCancel
	goto_if_ge VAR_RESULT, 8, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline
	copyvar VAR_0x8006, VAR_RESULT
	msgbox NewBarkTown_PlayersHouse_2F_Text_TestKitAsk, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, NewBarkTown_PlayersHouse_2F_EventScript_TestBasics
	goto_if_eq VAR_0x8006, 0, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestGreen
	goto_if_eq VAR_0x8006, 1, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestFuchsia
	goto_if_eq VAR_0x8006, 2, NewBarkTown_PlayersHouse_2F_EventScript_OlivineGateTest
	goto_if_eq VAR_0x8006, 3, NewBarkTown_PlayersHouse_2F_EventScript_KimonoTest
	goto_if_eq VAR_0x8006, 5, NewBarkTown_PlayersHouse_2F_EventScript_ShrineTest
	goto_if_eq VAR_0x8006, 6, NewBarkTown_PlayersHouse_2F_EventScript_RocketLabTest
	goto_if_eq VAR_0x8006, 7, NewBarkTown_PlayersHouse_2F_EventScript_ChallengersTest
	goto NewBarkTown_PlayersHouse_2F_EventScript_FoxfireTest

@ The start menu shows POKeDEX on FLAG_SYS_POKEDEX_GET and POKeMON on FLAG_SYS_POKEMON_GET
@ (src/start_menu.c). POKeMON waits until there is a POKeMON to show; GiveTestParty calls this
@ again once it has handed the party over.
NewBarkTown_PlayersHouse_2F_EventScript_TestMenuFlags::
	setflag FLAG_SYS_POKEDEX_GET
	getpartysize
	goto_if_eq VAR_RESULT, 0, NewBarkTown_PlayersHouse_2F_EventScript_TestMenuFlagsDone
	setflag FLAG_SYS_POKEMON_GET
NewBarkTown_PlayersHouse_2F_EventScript_TestMenuFlagsDone:
	return

@ The DAODAO ROCKET LAB at any of its four steps - GIDEON, the KLINKLANG boss, GIOVANNI and
@ the GENESECT he lets go - with every step before it done. The KANTO POKeMON FEDERATION arc
@ is put where the lab sits in it (5 before GIDEON, 6 after), FUCHSIA gets the aftermath
@ flags from the gate house's own stage setter (FedFlagsAftermath), and the KANTO cordon is
@ up before GIDEON and down after, exactly as his defeat leaves it. The save can be played on
@ from there. GIDEON starts at the lab door so the grunts are there to fight; the other steps
@ land beside their boss.
NewBarkTown_PlayersHouse_2F_EventScript_RocketLabTest::
	message NewBarkTown_PlayersHouse_2F_Text_LabStage
	waitmessage
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, NewBarkTown_PlayersHouse_2F_Text_LabGideon, NewBarkTown_PlayersHouse_2F_Text_LabKlinklang, NewBarkTown_PlayersHouse_2F_Text_LabGiovanni, NewBarkTown_PlayersHouse_2F_Text_LabGenesect
	goto_if_ge VAR_RESULT, 4, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline
	copyvar VAR_0x8005, VAR_RESULT
	msgbox NewBarkTown_PlayersHouse_2F_Text_TestPartyAsk, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty
	special HealPlayerParty
	call NewBarkTown_PlayersHouse_2F_EventScript_LabBeforeGideon
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsAftermath
	setvar VAR_FUCHSIA_SCENE, 4
	msgbox NewBarkTown_PlayersHouse_2F_Text_FoxfireGo, MSGBOX_DEFAULT
	closemessage
	switch VAR_0x8005
	case 0, NewBarkTown_PlayersHouse_2F_EventScript_LabGideon
	case 1, NewBarkTown_PlayersHouse_2F_EventScript_LabKlinklang
	case 2, NewBarkTown_PlayersHouse_2F_EventScript_LabGiovanni
	goto NewBarkTown_PlayersHouse_2F_EventScript_LabGenesect

@ STEVEN's charter has run (state 5), nothing in the lab has, and the cordon is up. Every flag
@ is written outright rather than as a delta, so a save that played further gets reset too.
NewBarkTown_PlayersHouse_2F_EventScript_LabBeforeGideon::
	setvar VAR_FUCHSIA_FEDERATION_STATE, 5
	clearflag FLAG_DEFEATED_DAODAO_LAB_GIDEON
	clearflag FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL
	clearflag FLAG_DEFEATED_DAODAO_LAB_GIOVANNI
	clearflag FLAG_DAODAO_GENESECT_TAKEN
	clearflag FLAG_DAODAO_GENESECT_KNOCKED_OUT
	clearflag FLAG_RECEIVED_DAODAO_LAB_KLINK
	cleartrainerflag TRAINER_GIDEON_HNS
	cleartrainerflag TRAINER_GIOVANNI_LAB_HNS
	cleartrainerflag TRAINER_DAODAO_LAB_CUEBALL_1_HNS
	cleartrainerflag TRAINER_DAODAO_LAB_CUEBALL_2_HNS
	cleartrainerflag TRAINER_DAODAO_LAB_SCIENTIST_1_HNS
	cleartrainerflag TRAINER_DAODAO_LAB_SCIENTIST_2_HNS
	cleartrainerflag TRAINER_DAODAO_LAB_BIKER_2_HNS
	@ Common_EventScript_ClearKantoCordon, undone. Nothing else sets these four, and the
	@ guard's flag is only ever cleared elsewhere (ROUTE 27).
	clearflag FLAG_DAODAO_CLEARED
	clearflag FLAG_HIDE_MTMOON_BLOCKER
	clearflag FLAG_HIDE_DIGLETTS_CAVE_BLOCKER
	clearflag FLAG_HIDE_TANGLEBRUSH_BLOCKER
	clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD
	return

@ GIDEON beaten, as his defeat script leaves things.
NewBarkTown_PlayersHouse_2F_EventScript_LabAfterGideon::
	setvar VAR_FUCHSIA_FEDERATION_STATE, 6
	setflag FLAG_DEFEATED_DAODAO_LAB_GIDEON
	settrainerflag TRAINER_GIDEON_HNS
	call Common_EventScript_ClearKantoCordon
	return

NewBarkTown_PlayersHouse_2F_EventScript_LabGideon::
	warp MAP_DAO_DAO_ISLES_ROCKET_LAB_HNS, 0
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_LabKlinklang::
	call NewBarkTown_PlayersHouse_2F_EventScript_LabAfterGideon
	warp MAP_DAO_DAO_ISLES_ROCKET_LAB_HNS, 12, 14
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_LabGiovanni::
	call NewBarkTown_PlayersHouse_2F_EventScript_LabAfterGideon
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL
	warp MAP_DAO_DAO_ISLES_ROCKET_LAB_HNS, 7, 6
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_LabGenesect::
	call NewBarkTown_PlayersHouse_2F_EventScript_LabAfterGideon
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL
	setflag FLAG_DEFEATED_DAODAO_LAB_GIOVANNI
	settrainerflag TRAINER_GIOVANNI_LAB_HNS
	warp MAP_DAO_DAO_ISLES_ROCKET_LAB_HNS, 5, 5
	waitstate
	end

@ The CHAMPION's ROOM title defense. Sets the KANTO title, all 16 badges and every challenger's
@ unlock battle, so the whole pool of 18 is open, then lands at the CHAMPION's ROOM door: the
@ room walks the player in and picks a challenger at random, a fresh pick per visit. Side
@ effects, as with every stage: those trainers count as beaten on this save, and DAODAO's
@ GIANT'S REST STEVEN (FLAG_DEFEATED_DAODAO_STEVEN) goes home.
NewBarkTown_PlayersHouse_2F_EventScript_ChallengersTest::
	msgbox NewBarkTown_PlayersHouse_2F_Text_TestPartyAsk, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty
	special HealPlayerParty
	setflag FLAG_IS_CHAMPION
	setflag FLAG_IS_KANTO_CHAMPION
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_BADGE09_GET
	setflag FLAG_BADGE10_GET
	setflag FLAG_BADGE11_GET
	setflag FLAG_BADGE12_GET
	setflag FLAG_BADGE13_GET
	setflag FLAG_BADGE14_GET
	setflag FLAG_BADGE15_GET
	setflag FLAG_BADGE16_GET
	setvar VAR_NUM_BADGES, 16
	settrainerflag TRAINER_CYNTHIA_HNS
	settrainerflag TRAINER_EUSINE_HNS
	settrainerflag TRAINER_GIOVANNI_LAB_HNS
	settrainerflag TRAINER_GREEN_HNS
	settrainerflag TRAINER_BLUE_HNS
	settrainerflag TRAINER_CLAIR_2_HNS
	settrainerflag TRAINER_IRIS_HNS
	settrainerflag TRAINER_ALDER_HNS
	setflag FLAG_DEFEATED_DAODAO_STEVEN
	settrainerflag TRAINER_LEADER_ROXANNE_HNS
	settrainerflag TRAINER_LEADER_BRAWLY_HNS
	settrainerflag TRAINER_LEADER_WATTSON_HNS
	settrainerflag TRAINER_LEADER_FLANNERY_HNS
	settrainerflag TRAINER_LEADER_NORMAN_HNS
	settrainerflag TRAINER_LEADER_WINONA_HNS
	settrainerflag TRAINER_LEADER_TATE_AND_LIZA_HNS
	settrainerflag TRAINER_LEADER_WALLACE_HNS
	msgbox NewBarkTown_PlayersHouse_2F_Text_FoxfireGo, MSGBOX_DEFAULT
	closemessage
	warp MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM_HNS, 0
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_ShrineTest::
	setvar VAR_DOLL_SHRINE_STATE, 0
	special HealPlayerParty
	msgbox NewBarkTown_PlayersHouse_2F_Text_FoxfireGo, MSGBOX_DEFAULT
	closemessage
	warp MAP_DAO_DAO_ISLES_MANSION_1F_HNS, 15, 4
	waitstate
	end

@ The TOWN MAP, the HMs and the MAX REPELs go in silently and only while the player
@ has none - a second visit would otherwise stack copies. The map gets its own check so that saves which already
@ have the HMs still receive it. VAR_NUM_BADGES is only ever raised, never
@ lowered, so GREEN's 16 survives a later visit.
NewBarkTown_PlayersHouse_2F_EventScript_TestBasics::
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	call_if_lt VAR_NUM_BADGES, 8, NewBarkTown_PlayersHouse_2F_EventScript_TestEightBadges
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	callnative FillObtainablePokedex
	checkitem ITEM_MAX_REPEL
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_PlayersHouse_2F_EventScript_TestBasicsMap
	additem ITEM_MAX_REPEL, 50
NewBarkTown_PlayersHouse_2F_EventScript_TestBasicsMap:
	checkitem ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_PlayersHouse_2F_EventScript_TestBasicsHMs
	additem ITEM_TOWN_MAP
NewBarkTown_PlayersHouse_2F_EventScript_TestBasicsHMs:
	checkitem ITEM_HM_CUT
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_PlayersHouse_2F_EventScript_TestBasicsDone
	additem ITEM_HM_CUT
	additem ITEM_HM_FLY
	additem ITEM_HM_SURF
	additem ITEM_HM_STRENGTH
	additem ITEM_HM_FLASH
	additem ITEM_HM_ROCK_SMASH
	additem ITEM_HM_WATERFALL
	additem ITEM_HM_WHIRLPOOL
NewBarkTown_PlayersHouse_2F_EventScript_TestBasicsDone:
	return

NewBarkTown_PlayersHouse_2F_EventScript_TestEightBadges::
	setvar VAR_NUM_BADGES, 8
	return

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

@ AERODACTYL goes first so it lands in the party rather than the PC when the
@ player already carries a POKeMON, and it knows FLY: test the TOWN MAP and the
@ fly map from anywhere outdoors. Its other three moves are its level-up ones.
NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty::
	givemon SPECIES_AERODACTYL, 95, move1=MOVE_FLY
	givemon SPECIES_TYPHLOSION, 95
	givemon SPECIES_LUCARIO, 95
	givemon SPECIES_MILOTIC, 95
	givemon SPECIES_ALAKAZAM, 95
	givemon SPECIES_HYDREIGON, 95
	special HealPlayerParty
	call NewBarkTown_PlayersHouse_2F_EventScript_TestMenuFlags
	return

NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline::
	msgbox NewBarkTown_PlayersHouse_2F_Text_GreenTestNoThanks, MSGBOX_DEFAULT
	closemessage
	release
	end

@ The ROCKET robbery in the ROUTE 39 / OLIVINE gate. The gate expires the scene once
@ FLAG_BADGE05_GET is set, which TestBasics always sets, so this hands it
@ VAR_OLIVINE_GATE_ROCKET 4: the gate's on-transition turns that into one fresh robbery.
@ The player lands on the ROUTE 39 side and trips it walking south.
NewBarkTown_PlayersHouse_2F_EventScript_OlivineGateTest::
	msgbox NewBarkTown_PlayersHouse_2F_Text_TestPartyAsk, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty
	special HealPlayerParty
	setvar VAR_OLIVINE_GATE_ROCKET, 4
	cleartrainerflag TRAINER_GRUNT_33_HNS
	msgbox NewBarkTown_PlayersHouse_2F_Text_OlivineGateGo, MSGBOX_DEFAULT
	closemessage
	warp MAP_GATE_ROUTE39_OLIVINE_CITY_HNS, 1
	waitstate
	end

@ The KIMONO GIRLS' gauntlet in the ECRUTEAK THEATER (VAR_ECRUTEAK_CITY_THEATER 5, as
@ after SILVER's ECRUTEAK scene): KIMONOs shown and the audience hidden, as ELM's call
@ leaves it. The menu picks VAR_LUGIA_OR_HOOH (1 LUGIA, 2 HO-OH), which decides the
@ bell and the legendary afterwards. The player lands on the door and trips the
@ cutscene by stepping in.
NewBarkTown_PlayersHouse_2F_EventScript_KimonoTest::
	message NewBarkTown_PlayersHouse_2F_Text_KimonoWhich
	waitmessage
	dynmultichoice 0, 0, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, NewBarkTown_PlayersHouse_2F_Text_KimonoLugia, NewBarkTown_PlayersHouse_2F_Text_KimonoHooh
	goto_if_ge VAR_RESULT, 2, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline
	addvar VAR_RESULT, 1
	copyvar VAR_LUGIA_OR_HOOH, VAR_RESULT
	msgbox NewBarkTown_PlayersHouse_2F_Text_TestPartyAsk, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty
	special HealPlayerParty
	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	cleartrainerflag TRAINER_ZUKI_HNS
	cleartrainerflag TRAINER_NAOKO_HNS
	cleartrainerflag TRAINER_MIKI_HNS
	cleartrainerflag TRAINER_SAYO_HNS
	cleartrainerflag TRAINER_KUNI_HNS
	msgbox NewBarkTown_PlayersHouse_2F_Text_KimonoGo, MSGBOX_DEFAULT
	closemessage
	warp MAP_ECRUTEAK_CITY_THEATER_HNS, 0
	waitstate
	end

@ FOXFIRE HOLLOW. Every stage is VAR_FOXFIRE_HOLLOW_STATE and nothing else - the
@ fog, the woman, the lodge's ruined layout and both NINETALES are worked out from
@ it each time a map loads - so any stage can be set, and set again, from here.
@ The LAKE start relies on TestBasics' badges, which open the path north of the
@ hermit's house. It lands on the nook itself, so the tide does not matter.
NewBarkTown_PlayersHouse_2F_EventScript_FoxfireTest::
	message NewBarkTown_PlayersHouse_2F_Text_FoxfireStage
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, NewBarkTown_PlayersHouse_2F_Text_FoxfireLake, NewBarkTown_PlayersHouse_2F_Text_FoxfireFresh, NewBarkTown_PlayersHouse_2F_Text_FoxfireGreeted, NewBarkTown_PlayersHouse_2F_Text_FoxfireDesk, NewBarkTown_PlayersHouse_2F_Text_FoxfireRuins, NewBarkTown_PlayersHouse_2F_Text_FoxfireOver, NewBarkTown_PlayersHouse_2F_Text_FoxfireShadow
	goto_if_ge VAR_RESULT, 7, NewBarkTown_PlayersHouse_2F_EventScript_GreenTestDecline
	copyvar VAR_0x8005, VAR_RESULT
	msgbox NewBarkTown_PlayersHouse_2F_Text_FoxfireKit, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, NewBarkTown_PlayersHouse_2F_EventScript_FoxfireKit
	special HealPlayerParty
	msgbox NewBarkTown_PlayersHouse_2F_Text_FoxfireGo, MSGBOX_DEFAULT
	closemessage
	switch VAR_0x8005
	case 0, NewBarkTown_PlayersHouse_2F_EventScript_FoxfireLake
	case 1, NewBarkTown_PlayersHouse_2F_EventScript_FoxfireFresh
	case 2, NewBarkTown_PlayersHouse_2F_EventScript_FoxfireGreeted
	case 3, NewBarkTown_PlayersHouse_2F_EventScript_FoxfireDesk
	case 4, NewBarkTown_PlayersHouse_2F_EventScript_FoxfireRuins
	case 5, NewBarkTown_PlayersHouse_2F_EventScript_FoxfireOver
	goto NewBarkTown_PlayersHouse_2F_EventScript_FoxfireShadow

NewBarkTown_PlayersHouse_2F_EventScript_FoxfireKit::
	call NewBarkTown_PlayersHouse_2F_EventScript_GiveTestParty
	giveitem ITEM_MASTER_BALL, 5
	return

NewBarkTown_PlayersHouse_2F_EventScript_FoxfireLake::
	setvar VAR_FOXFIRE_HOLLOW_STATE, 0
	warp MAP_LAKE_OF_RAGE_HNS, 20, 3
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_FoxfireFresh::
	setvar VAR_FOXFIRE_HOLLOW_STATE, 0
	warp MAP_FOXFIRE_HOLLOW_HNS, 14, 30
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_FoxfireGreeted::
	setvar VAR_FOXFIRE_HOLLOW_STATE, 2
	warp MAP_FOXFIRE_HOLLOW_MANSION_1F_HNS, 0
	waitstate
	end

@ Greeted, and standing at the east dining table facing the diary: read it to start the truth
@ scene.
NewBarkTown_PlayersHouse_2F_EventScript_FoxfireDesk::
	setvar VAR_FOXFIRE_HOLLOW_STATE, 2
	warp MAP_FOXFIRE_HOLLOW_MANSION_1F_HNS, 33, 9
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_FoxfireRuins::
	setvar VAR_FOXFIRE_HOLLOW_STATE, 5
	warp MAP_FOXFIRE_HOLLOW_MANSION_B1F_HNS, 22, 30
	waitstate
	end

NewBarkTown_PlayersHouse_2F_EventScript_FoxfireOver::
	setvar VAR_FOXFIRE_HOLLOW_STATE, 6
	warp MAP_FOXFIRE_HOLLOW_HNS, 14, 30
	waitstate
	end

@ The post-game MARSHADOW in the study chair. This sets FLAG_SYS_GAME_CLEAR, which opens
@ every other post-game door on this save too.
NewBarkTown_PlayersHouse_2F_EventScript_FoxfireShadow::
	setvar VAR_FOXFIRE_HOLLOW_STATE, 6
	setflag FLAG_SYS_GAME_CLEAR
	clearflag FLAG_CAUGHT_FOXFIRE_MANSION_MARSHADOW
	warp MAP_FOXFIRE_HOLLOW_MANSION_B1F_HNS, 18, 28
	waitstate
	end

NewBarkTown_PlayersHouse_2F_Text_TestAsk:
	.string "TEST: What do you want to try?\p"
	.string "Each one offers the test kit\n"
	.string "first: badges, HMs, a full\l"
	.string "POKéDEX and travel items.\p"
	.string "GREEN and FUCHSIA hand you a\n"
	.string "level 95 party first.$"

NewBarkTown_PlayersHouse_2F_Text_TestOptGreen:
	.string "GREEN at OAK'S LAB$"

NewBarkTown_PlayersHouse_2F_Text_TestOptFuchsia:
	.string "FUCHSIA FEDERATION$"

NewBarkTown_PlayersHouse_2F_Text_TestOptOlivineGate:
	.string "ROCKETS at OLIVINE GATE$"

NewBarkTown_PlayersHouse_2F_Text_TestOptKimono:
	.string "KIMONO GIRLS gauntlet$"

NewBarkTown_PlayersHouse_2F_Text_TestOptFoxfire:
	.string "FOXFIRE HOLLOW$"

NewBarkTown_PlayersHouse_2F_Text_TestOptShrine:
	.string "DOLL SHRINE$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireStage:
	.string "TEST: Which FOXFIRE HOLLOW stage?$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireLake:
	.string "LAKE: path north$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireFresh:
	.string "HOLLOW: fresh start$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireGreeted:
	.string "MANSION: just greeted$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireDesk:
	.string "MANSION: at the diary$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireRuins:
	.string "B1F: NINETALES waits$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireOver:
	.string "OVER: fog lifted$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireShadow:
	.string "B1F: MARSHADOW (post-game)$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireKit:
	.string "TEST: Take the level 95 party and\n"
	.string "five MASTER BALLs too?$"

NewBarkTown_PlayersHouse_2F_Text_FoxfireGo:
	.string "TEST: Your party is healed.\n"
	.string "Off you go!$"

NewBarkTown_PlayersHouse_2F_Text_TestPartyAsk:
	.string "TEST: Take the level 95 party\n"
	.string "too?$"

NewBarkTown_PlayersHouse_2F_Text_TestOptRocketLab:
	.string "ROCKET LAB$"

NewBarkTown_PlayersHouse_2F_Text_TestOptChallengers:
	.string "CHAMPION's ROOM challengers$"

NewBarkTown_PlayersHouse_2F_Text_TestOptCancel:
	.string "Nothing$"

NewBarkTown_PlayersHouse_2F_Text_TestKitAsk:
	.string "TEST: Take the test kit too?\p"
	.string "The eight JOHTO badges, RUNNING\n"
	.string "SHOES and HMs, a full POKéDEX,\l"
	.string "a TOWN MAP and MAX REPELs.\p"
	.string "NO leaves your save as it is.$"

NewBarkTown_PlayersHouse_2F_Text_LabStage:
	.string "TEST: Which part of the ROCKET\n"
	.string "LAB?$"

NewBarkTown_PlayersHouse_2F_Text_LabGideon:
	.string "GIDEON, from the door$"

NewBarkTown_PlayersHouse_2F_Text_LabKlinklang:
	.string "KLINKLANG$"

NewBarkTown_PlayersHouse_2F_Text_LabGiovanni:
	.string "GIOVANNI$"

NewBarkTown_PlayersHouse_2F_Text_LabGenesect:
	.string "GENESECT$"

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

NewBarkTown_PlayersHouse_2F_Text_OlivineGateGo:
	.string "TEST: You'll arrive at the ROUTE 39\n"
	.string "end of the OLIVINE gate.\p"
	.string "Walk south to trip the robbery.$"

NewBarkTown_PlayersHouse_2F_Text_KimonoWhich:
	.string "TEST: Which legendary do they\n"
	.string "call for?$"

NewBarkTown_PlayersHouse_2F_Text_KimonoLugia:
	.string "LUGIA$"

NewBarkTown_PlayersHouse_2F_Text_KimonoHooh:
	.string "HO-OH$"

NewBarkTown_PlayersHouse_2F_Text_KimonoGo:
	.string "TEST: You'll arrive at the THEATER\n"
	.string "door. Step in to start it.$"
