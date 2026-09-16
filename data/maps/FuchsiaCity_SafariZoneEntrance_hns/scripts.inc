FuchsiaCity_SafariZoneEntrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZoneEntrance_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_SafariZoneEntrance_OnTransition
	.byte 0

FuchsiaCity_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari
	.2byte 0

FuchsiaCity_SafariZoneEntrance_OnTransition::
	call_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_FirstTime
	end

FuchsiaCity_SafariZoneEntrance_FirstTime::
	setobjectxyperm LOCALID_SAFARIZONEFUCHSIA_STEVEN, 4, 10
	setobjectmovementtype LOCALID_SAFARIZONEFUCHSIA_STEVEN, MOVEMENT_TYPE_FACE_LEFT
	end

FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	release
	end
 
FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 0
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN

	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase

	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 1
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	return

FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase:
	.string "Oh and you might need this.$"

FuchsiaCity_SafariZoneEntrance_Steven::
	lock
	faceplayer
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_SafariZoneEntrance_EventScript_StevenAfterFederation
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, FuchsiaCity_SafariZoneEntrance_EventScript_StevenUnderSiege
	goto FuchsiaCity_SafariZoneEntrance_EventScript_StevenNormal

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNormal::
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade
	goto_if_set FLAG_IS_KANTO_CHAMPION, FuchsiaCity_SafariZoneEntrance_StevenChamp
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Steven, MSGBOX_NPC
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenUnderSiege::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenUnderSiege, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenAfterFederation::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 7, FuchsiaCity_SafariZoneEntrance_EventScript_StevenCharterDone
	goto_if_unset FLAG_DEFEATED_VERMILION_GYM, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady
	goto_if_unset FLAG_DEFEATED_CELADON_GYM, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady
	goto_if_unset FLAG_DEFEATED_SAFFRON_GYM, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady
	goto_if_unset FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineBattle
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenAccept, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN_KANTO_HNS, FuchsiaCity_SafariZoneEntrance_Text_StevenBattleBeaten
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenBattleAfter, MSGBOX_DEFAULT
	setvar VAR_FUCHSIA_FEDERATION_STATE, 7
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineBattle::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenDecline, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenCharterDone::
	goto_if_set FLAG_VISITED_ALOLA, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNormal
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenCharterReminder, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_StevenChamp::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenChamp, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenChamp:
	.string "Oh, hey {PLAYER}.\n"
	.string "Or should I say KANTO champion?\p"
	.string "You know, for some time, I was the\n"
	.string "champion of the HOENN region.\p"
	.string "So welcome to the club, {PLAYER}.\p"
	.string "In fact, here.\n"
	.string "Consider this a welcome gift.$"

FuchsiaCity_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	@ No tickets while the FEDERATION holds the building - the attendant is
	@ hidden by FLAG_HIDE_SAFARI_STAFF, so without this the counter would take
	@ the player's money on behalf of nobody.
	goto_if_lt VAR_FUCHSIA_FEDERATION_STATE, 2, FuchsiaCity_SafariZoneEntrance_EventScript_CounterOpen
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_SafariZoneEntrance_EventScript_CounterOpen
	msgbox FuchsiaCity_SafariZoneEntrance_Text_CounterShut, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter

FuchsiaCity_SafariZoneEntrance_EventScript_CounterOpen::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase
	call FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 4, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft
	call_if_eq VAR_TEMP_0, 6, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	setflag FLAG_IN_KANTO_SAFARI_ZONE
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 1
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome:
	.string "Hello again, {PLAYER}!\p"
	.string "Welcome to the DEVON SAFARI ZONE!\p"
	.string "This specially designed safari\n"
	.string "has 4 different habitats that\l"
	.string "attract and house different invasive\l"
	.string "species from the HOENN region.\p"
	.string "We encourage trainers to capture\n"
	.string "as many as they can to safely\l"
	.string "remove them from the environment.\p"
	.string "You'll find very rare POKéMON\n"
	.string "here. Especially if you increase\l"
	.string "your SAFARI LEVEL.\p"
	.string "Just speak to the attendant here\n"
	.string "any time to increase your SAFARI\l"
	.string "LEVEL.$"

FuchsiaCity_SafariZoneEntrance_UpgradeGuy::
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 1, FuchsiaCity_SafariZoneEntrance_UpgradeGuy1
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 2, FuchsiaCity_SafariZoneEntrance_UpgradeGuy2
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 3, FuchsiaCity_SafariZoneEntrance_UpgradeGuy3
	msgbox FuchsiaCity_SafariZoneEntrance_Text_MaxLevel, MSGBOX_NPC
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy1::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 200000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 200000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 2
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy2::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 300000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 300000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 3
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy3::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 400000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 400000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 4
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_Text_Steven:
	.string "Oh, hey, {PLAYER}.\p"
	.string "I hope you're enjoying the SAFARI.\p"
	.string "Have you seen any rare stones\n"
	.string "lately?$"

FuchsiaCity_SafariZoneEntrance_Text_Level1:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 2? It will cost you ¥200,000.$"

FuchsiaCity_SafariZoneEntrance_Text_Level2:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 3? It will cost you ¥300,000.$"

FuchsiaCity_SafariZoneEntrance_Text_Level3:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 4? It will cost you ¥400,000.$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined:
	.string "Oh, that's too bad, then...$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted:
	.string "Enjoy the premium SAFARI ZONE\n"
	.string "experience!$"

FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade::
	goto_if_set FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED, FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted
	ingame_trade INGAME_TRADE_BELDUM, FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon, FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare
	setflag FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade:
	.string "Say, {PLAYER}…\n"
	.string "I've been raising this BELDUM\l"
	.string "for a while now.\p"
	.string "But I think it would do better\n"
	.string "with a trainer like you.\p"
	.string "Would you trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare:
	.string "Excellent!\n"
	.string "Please take good care of IRON.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade:
	.string "That's all right.\n"
	.string "The offer stands if you change\l"
	.string "your mind.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon:
	.string "Hmm, that's not a {STR_VAR_1}.\n"
	.string "That's not quite what I had\l"
	.string "in mind.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted:
	.string "How is IRON doing?\n"
	.string "BELDUM are fascinating POKéMON.\p"
	.string "They communicate with each other\n"
	.string "using magnetic pulses.$"

FuchsiaCity_SafariZoneEntrance_Text_MaxLevel:
	.string "Hello {PLAYER}, thank you for\n"
	.string "continuing to be a premium member\l"
	.string "at the FUCHSIA SAFARI ZONE.$"

@ ===[ THE SHOWDOWN - STATES 3 TO 6 ]=========================================
@ GIL and BRIX can be taken in either order; PAXTON will not fight until both
@ are down, which forces the whole gauntlet without dictating a sequence.
@
@ The PAXTON battle is where the tie lands, and it lands in the AUDIO: his party
@ entry carries `Music: Rocket`, so the TEAM ROCKET battle theme plays before any
@ character has said the words. His team does the rest - CROBAT and WEEZING are
@ biker mon, but RHYDON and NIDOKING are GIOVANNI's. Nobody ever says
@ "TEAM ROCKET" out loud in this whole arc.
@
@ ⚠️ The party itself is Moritz's and is hand-maintained in trainers_hns.party -
@ do not edit it from here. If the team changes, this comment is what goes stale:
@ it already had to drop PERSIAN once when the ace became ANNIHILAPE.

FuchsiaCity_SafariZoneEntrance_EventScript_Gil::
	trainerbattle_single TRAINER_GIL_HNS, FuchsiaCity_SafariZoneEntrance_Text_GilSeen, FuchsiaCity_SafariZoneEntrance_Text_GilBeaten
	msgbox FuchsiaCity_SafariZoneEntrance_Text_GilAfter, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_SafariZoneEntrance_EventScript_Brix::
	trainerbattle_single TRAINER_BRIX_HNS, FuchsiaCity_SafariZoneEntrance_Text_BrixSeen, FuchsiaCity_SafariZoneEntrance_Text_BrixBeaten
	msgbox FuchsiaCity_SafariZoneEntrance_Text_BrixAfter, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_SafariZoneEntrance_EventScript_Paxton::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_GIL_HNS, FuchsiaCity_SafariZoneEntrance_EventScript_PaxtonWait
	goto_if_not_defeated TRAINER_BRIX_HNS, FuchsiaCity_SafariZoneEntrance_EventScript_PaxtonWait
	msgbox FuchsiaCity_SafariZoneEntrance_Text_PaxtonSeen, MSGBOX_DEFAULT
	@ Bookmark, so a save made mid-scene resumes with the tie already surfaced.
	setvar VAR_FUCHSIA_FEDERATION_STATE, 4
	trainerbattle_no_intro TRAINER_PAXTON_HNS, FuchsiaCity_SafariZoneEntrance_Text_PaxtonBeaten
	msgbox FuchsiaCity_SafariZoneEntrance_Text_PaxtonAfter, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setvar VAR_FUCHSIA_FEDERATION_STATE, 5
	setflag FLAG_HIDE_SAFARI_FEDERATION
	clearflag FLAG_HIDE_SAFARI_STAFF
	removeobject LOCALID_SAFARI_PAXTON
	removeobject LOCALID_SAFARI_GIL
	removeobject LOCALID_SAFARI_BRIX
	playse SE_EXIT
	fadescreenswapbuffers FADE_FROM_BLACK
	goto FuchsiaCity_SafariZoneEntrance_EventScript_FederationAftermath

FuchsiaCity_SafariZoneEntrance_EventScript_PaxtonWait::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_PaxtonWait, MSGBOX_DEFAULT
	closemessage
	release
	end

@ State 5 -> 6. Restores FUCHSIA itself: the townsfolk come back, JANINE returns
@ to her GYM, and the takeover BGM stops being selected the next time the city
@ map loads. Done here rather than on the city map so the player never sees a
@ half-restored FUCHSIA.
FuchsiaCity_SafariZoneEntrance_EventScript_FederationAftermath::
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_WalkLeft1
	waitmovement 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenAftermath, MSGBOX_DEFAULT
	setvar VAR_FUCHSIA_FEDERATION_STATE, 6
	clearflag FLAG_HIDE_FUCHSIA_NPCS
	setflag FLAG_HIDE_FUCHSIA_FEDERATION
	@ The two street holdouts clear out with him. No removeobject needed: the
	@ player is standing in the SAFARI ZONE ENTRANCE right now, so FUCHSIA is
	@ reloaded from scratch with this flag already set the moment they walk out.
	setflag FLAG_HIDE_FUCHSIA_HOLDOUTS
	clearflag FLAG_HIDE_FUCHSIA_JANINE
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_CounterShut:
	.string "The SAFARI ZONE is closed.\p"
	.string "Nobody is taking tickets while\n"
	.string "those people are inside.$"

FuchsiaCity_SafariZoneEntrance_Text_GilSeen:
	.string "DEVON walks in, buys the SAFARI\n"
	.string "ZONE, and we're supposed to smile?$"

FuchsiaCity_SafariZoneEntrance_Text_GilBeaten:
	.string "Agh! Fine, fine!$"

FuchsiaCity_SafariZoneEntrance_Text_GilAfter:
	.string "This was our ground before it had\n"
	.string "a gate and a ticket price.$"

FuchsiaCity_SafariZoneEntrance_Text_BrixSeen:
	.string "PAXTON said to flatten anyone who\n"
	.string "came through that door.$"

FuchsiaCity_SafariZoneEntrance_Text_BrixBeaten:
	.string "…Not paid enough for this.$"

FuchsiaCity_SafariZoneEntrance_Text_BrixAfter:
	.string "We're not thieves. We're owed.\p"
	.string "That's what the man in the suit\n"
	.string "told us, anyway.$"

FuchsiaCity_SafariZoneEntrance_Text_PaxtonWait:
	.string "Stay back, kid.\p"
	.string "My people are still counting what's\n"
	.string "in this building.$"

FuchsiaCity_SafariZoneEntrance_Text_PaxtonSeen:
	.string "So you're the one knocking my\n"
	.string "people down.\p"
	.string "Look around. DEVON fenced off the\n"
	.string "marsh, sells tickets to what used\l"
	.string "to be ours, and calls it charity.\p"
	.string "I got run off an island once by\n"
	.string "people who talked like that.\p"
	.string "Not again.\p"
	.string "Someone finally offered to help us\n"
	.string "take it back.\p"
	.string "I didn't ask his name.\n"
	.string "I didn't need to.$"

FuchsiaCity_SafariZoneEntrance_Text_PaxtonBeaten:
	.string "…Should've asked his name.$"

FuchsiaCity_SafariZoneEntrance_Text_PaxtonAfter:
	.string "He told us there'd be a kid.\p"
	.string "Said if a kid from JOHTO turned up,\n"
	.string "we were to leave and say nothing.\p"
	.string "…He knew you'd come.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenUnderSiege:
	.string "{PLAYER}! You shouldn't be in here.\p"
	.string "They have my attendants in the back\n"
	.string "room. The one standing over me is\l"
	.string "the one giving the orders.\p"
	.string "I can't fight him and keep everyone\n"
	.string "in there safe.\p"
	.string "But you can fight.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenAftermath:
	.string "It's over…\p"
	.string "My attendants are shaken, but they\n"
	.string "are safe. Thank you, {PLAYER}.\p"
	.string "Did you hear him? He kept saying\n"
	.string "'he'. Never a name.\p"
	.string "Someone paid for all this. Someone\n"
	.string "who knew you were coming before\l"
	.string "I did.\p"
	.string "Come and find me once FUCHSIA is\n"
	.string "back on its feet. I have a favor\l"
	.string "to ask you.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenNotReady:
	.string "There's something I want to ask\n"
	.string "of you, {PLAYER}.\p"
	.string "But finish what you came here for\n"
	.string "first. JANINE is back at her GYM.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenChallenge:
	.string "SURGE, ERIKA, SABRINA, JANINE.\p"
	.string "All four, and the FEDERATION too.\p"
	.string "The men who took my SAFARI ZONE\n"
	.string "were paid by someone I cannot\l"
	.string "reach from KANTO.\p"
	.string "DEVON has a ship. I want you on it.\p"
	.string "But not before I've seen for myself\n"
	.string "that you're ready.\p"
	.string "Show me. Here and now?$"

FuchsiaCity_SafariZoneEntrance_Text_StevenAccept:
	.string "Good.\p"
	.string "I won't go easy on you. It would\n"
	.string "be no kindness if I did.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenDecline:
	.string "Then come back when you are.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenBattleBeaten:
	.string "…Yes.\n"
	.string "You're ready.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenBattleAfter:
	.string "That was a fine battle.\p"
	.string "The ship is at the dock on\n"
	.string "ROUTE 13. The captain has his\l"
	.string "orders.\p"
	.string "Find out who paid them, {PLAYER}.\p"
	.string "And be careful out there.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenCharterReminder:
	.string "The DEVON ship is waiting at the\n"
	.string "ROUTE 13 dock whenever you are.$"
