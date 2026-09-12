Route25_BillsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_BillsHouse_hns_OnTransition
	.byte 0

Route25_BillsHouse_hns_OnTransition::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	end

Route25_BillsHouse_hns_EventScript_TeleporterTest::
	lockall
	goto_if_unset FLAG_TELEPORTER_UNLOCKED, Route25_BillsHouse_hns_Locked
	helpwindow HELP_TELEPORTER_WINDOW
	msgbox Route25_BillsHouse_Text_Teleporter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_hns_EndChoice
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_hns_EndChoice
	special CheckPartyMonForHiddenAbility
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_hns_NoHiddenAbility
	closemessage
	goto Route25_BillsHouse_hns_CutsceneSetup
	end

Route25_BillsHouse_hns_Locked::
	msgbox Route25_BillsHouse_hns_Text_Locked, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route25_BillsHouse_hns_NoHiddenAbility::
	msgbox Route25_BillsHouse_hns_Text_NoHiddenAbility, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route25_BillsHouse_hns_Text_Locked:
	.string "The machine is dark and silent.\p"
	.string "BILL'S GRANDPA must know how to\n"
	.string "switch it on.$"

Route25_BillsHouse_hns_Text_NoHiddenAbility:
	.string "The machine hums, then falls quiet.\p"
	.string "That POKéMON has no sleeping\n"
	.string "talent left to wake.$"

Route25_BillsHouse_Text_Teleporter:
	.string "THIS MACHINE WILL WAKE THE HIDDEN\n"
	.string "TALENT SLEEPING IN A POKéMON.\l"
	.string "THIS PROCESS IS PERMANENT.\l"
	.string "WOULD YOU LIKE TO PROCEED?$"

Route25_BillsHouse_hns_EndChoice::
	closemessage
	releaseall
	end

Route25_BillsHouse_SetPlayerMale::
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_GOLD_NORMAL_HNS
	return

Route25_BillsHouse_SetPlayerFemale::
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_KRIS_NORMAL_HNS
	return

Route25_BillsHouse_hns_CutsceneSetup::
	fadescreen FADE_TO_BLACK
	clearflag FLAG_TEMP_1
	copyvar VAR_OBJ_GFX_ID_0, VAR_TEMP_0
	addvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MON_BASE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route25_BillsHouse_SetPlayerMale
	call_if_eq VAR_RESULT, FEMALE, Route25_BillsHouse_SetPlayerFemale
	addobject LOCALID_BILLS_GRANDPA_PLAYER
	addobject LOCALID_BILLS_GRANDPA_OLD_MON
	applymovement OBJ_EVENT_ID_PLAYER, Route25_BillsHouse_Movement_HidePlayer
	hidefollower
	turnobject LOCALID_BILLS_GRANDPA, DIR_NORTH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Route25_BillsHouse_Movement_CameraPanUp
	waitmovement 0
	delay 60
	fadescreen FADE_FROM_BLACK

Route25_BillsHouse_hns_CutsceneBeforeTeleport::
	delay 60
	opendoor 10, 3
	waitdooranim
	playmoncry VAR_TEMP_0, CRY_MODE_NORMAL
	waitmoncry 
	applymovement LOCALID_BILLS_GRANDPA_OLD_MON, Common_Movement_WalkUp1
	waitmovement 0
	turnobject LOCALID_BILLS_GRANDPA_OLD_MON, DIR_SOUTH
	applymovement LOCALID_BILLS_GRANDPA_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject LOCALID_BILLS_GRANDPA_PLAYER, DIR_NORTH
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 10, 3
	delay 10
	removeobject LOCALID_BILLS_GRANDPA_OLD_MON
	waitdooranim

Route25_BillsHouse_hns_CutsceneTeleport::
	delay 35
	playse SE_PIN
	waitse
	setvar VAR_0x8004, 0
	special AnimateTeleporterHousing
	delay 10
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	setvar VAR_0x8004, 1
	special AnimateTeleporterHousing
	playse SE_WARP_IN
	special AnimateTeleporterCable
	delay 30
	applymovement LOCALID_BILLS_GRANDPA_PLAYER, Route25_BillsHouse_Movement_PlayerMoveLeft
	waitse
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	@ The same POKéMON walks back out - only its ability changed - so the "after"
	@ sprite is the same species as the "before" one.
	copyvar VAR_TEMP_1, VAR_TEMP_0
	clearflag FLAG_TEMP_2
	copyvar VAR_OBJ_GFX_ID_1, VAR_TEMP_1
	addvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MON_BASE
	
Route25_BillsHouse_hns_CutsceneAfterTeleport::
	opendoor 3, 3
	delay 10
	addobject LOCALID_BILLS_GRANDPA_NEW_MON
	waitdooranim
	applymovement LOCALID_BILLS_GRANDPA_PLAYER, Route25_BillsHouse_Movement_PlayerSlideDown
	playse SE_LEDGE
	applymovement LOCALID_BILLS_GRANDPA_NEW_MON, Common_Movement_WalkDown1
	waitmovement 0
	waitmovement 0
	@playse SE_PIN
	@applymovement LOCALID_BILLS_GRANDPA_PLAYER, Common_Movement_ExclamationMark
	@delay 60
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 3, 3
	delay 10
	applymovement LOCALID_BILLS_GRANDPA_NEW_MON, Route25_BillsHouse_Movement_MonCelebration
	waitmovement 0
	playmoncry VAR_TEMP_0, CRY_MODE_NORMAL
	waitmoncry
	delay 60

Route25_BillsHouse_hns_CutsceneCleanup::
	fadescreen FADE_TO_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, Route25_BillsHouse_Movement_CameraPanDown
	waitmovement 0
	removeobject LOCALID_BILLS_GRANDPA_NEW_MON
	removeobject LOCALID_BILLS_GRANDPA_OLD_MON
	removeobject LOCALID_BILLS_GRANDPA_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Route25_BillsHouse_Movement_ShowPlayer
	waitmovement 0
	turnobject LOCALID_BILLS_GRANDPA, DIR_SOUTH
	special RemoveCameraObject
	special WakeHiddenAbility
	delay 60
	callnative UpdateFollowingPokemon
	fadescreen FADE_FROM_BLACK
	releaseall
	end

Route25_BillsHouse_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route25_BillsHouse_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Route25_BillsHouse_Movement_PlayerMoveLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

Route25_BillsHouse_Movement_PlayerSlideDown:
	lock_facing_direction
	jump_down
	unlock_facing_direction
	step_end

Route25_BillsHouse_hns_BeepSE::
	playse SE_BALL
	waitse
	delay 20
	return

Route25_BillsHouse_Movement_HidePlayer:
	set_invisible
	step_end

Route25_BillsHouse_Movement_ShowPlayer:
	set_visible
	step_end

@VAR_BILLS_GRANDPA

Route25_BillsHouse_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_BILLS_GRANDPA, 1, Route25_BillsHouse_EventScript_Gramps_Sentret
	goto_if_eq VAR_BILLS_GRANDPA, 2, Route25_BillsHouse_EventScript_Gramps_Hoothoot
	goto_if_eq VAR_BILLS_GRANDPA, 3, Route25_BillsHouse_EventScript_Gramps_Wooper
	goto_if_eq VAR_BILLS_GRANDPA, 4, Route25_BillsHouse_EventScript_Gramps_Heracross
	goto_if_eq VAR_BILLS_GRANDPA, 5, Route25_BillsHouse_EventScript_Gramps_Slowpoke
	goto_if_eq VAR_BILLS_GRANDPA, 6, Route25_BillsHouse_EventScript_Gramps_ShownAll
	msgbox Route25_BillsHouse_Text_GrandpaIntro, MSGBOX_DEFAULT
	setvar VAR_BILLS_GRANDPA, 1
	goto Route25_BillsHouse_EventScript_Gramps_Sentret

Route25_BillsHouse_EventScript_Gramps_Declined::
	msgbox Route25_BillsHouse_Text_YouDontHaveIt, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_WrongMon::
	msgbox Route25_BillsHouse_Text_WrongPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Sentret::
	msgbox Route25_BillsHouse_Text_GrampsSentret, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	@ The evolved form carries the same hidden ability, so the clue is equally
	@ true of it - a player who evolved theirs must not be locked out.
	goto_if_eq VAR_RESULT, SPECIES_SENTRET, Route25_BillsHouse_EventScript_Gramps_SentretRightMon
	goto_if_eq VAR_RESULT, SPECIES_FURRET, Route25_BillsHouse_EventScript_Gramps_SentretRightMon
	goto Route25_BillsHouse_EventScript_Gramps_WrongMon
Route25_BillsHouse_EventScript_Gramps_SentretRightMon::
	bufferspeciesname STR_VAR_1, SPECIES_SENTRET
	setvar VAR_TEMP_0, ITEM_EXP_CANDY_L
	setvar VAR_TEMP_1, 1
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Hoothoot::
	msgbox Route25_BillsHouse_Text_GrampsHoothoot, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_eq VAR_RESULT, SPECIES_HOOTHOOT, Route25_BillsHouse_EventScript_Gramps_HoothootRightMon
	goto_if_eq VAR_RESULT, SPECIES_NOCTOWL, Route25_BillsHouse_EventScript_Gramps_HoothootRightMon
	goto Route25_BillsHouse_EventScript_Gramps_WrongMon
Route25_BillsHouse_EventScript_Gramps_HoothootRightMon::
	bufferspeciesname STR_VAR_1, SPECIES_HOOTHOOT
	setvar VAR_TEMP_0, ITEM_EXP_CANDY_L
	setvar VAR_TEMP_1, 3
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Wooper::
	msgbox Route25_BillsHouse_Text_GrampsWooper, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_eq VAR_RESULT, SPECIES_WOOPER, Route25_BillsHouse_EventScript_Gramps_WooperRightMon
	goto_if_eq VAR_RESULT, SPECIES_QUAGSIRE, Route25_BillsHouse_EventScript_Gramps_WooperRightMon
	goto Route25_BillsHouse_EventScript_Gramps_WrongMon
Route25_BillsHouse_EventScript_Gramps_WooperRightMon::
	bufferspeciesname STR_VAR_1, SPECIES_WOOPER
	setvar VAR_TEMP_0, ITEM_EXP_CANDY_L
	setvar VAR_TEMP_1, 5
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Heracross::
	msgbox Route25_BillsHouse_Text_GrampsHeracross, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_HERACROSS, Route25_BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_HERACROSS
	setvar VAR_TEMP_0, ITEM_EXP_CANDY_L
	setvar VAR_TEMP_1, 7
	goto Route25_BillsHouse_EventScript_Gramps_Correctmon

Route25_BillsHouse_EventScript_Gramps_Slowpoke::
	msgbox Route25_BillsHouse_Text_GrampsSlowpoke, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_EventScript_Gramps_Declined
	msgbox Route25_BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25_BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_eq VAR_RESULT, SPECIES_SLOWPOKE, Route25_BillsHouse_EventScript_Gramps_SlowpokeRightMon
	goto_if_eq VAR_RESULT, SPECIES_SLOWBRO, Route25_BillsHouse_EventScript_Gramps_SlowpokeRightMon
	goto_if_eq VAR_RESULT, SPECIES_SLOWKING, Route25_BillsHouse_EventScript_Gramps_SlowpokeRightMon
	goto Route25_BillsHouse_EventScript_Gramps_WrongMon
Route25_BillsHouse_EventScript_Gramps_SlowpokeRightMon::
	bufferspeciesname STR_VAR_1, SPECIES_SLOWPOKE
	goto Route25_BillsHouse_EventScript_Gramps_SlowpokeReward

Route25_BillsHouse_EventScript_Gramps_SlowpokeReward::
	msgbox Route25_BillsHouse_Text_ShownPokemon, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_Appreciation, MSGBOX_DEFAULT
	@ The Galarica Cuff and Wreath used to be handed over here. They are the
	@ Galarian Slowpoke evolution items, so P_REGIONAL_FORMS = FALSE left them
	@ with nothing to evolve - dead loot. The teleporter itself is the reward now.
	msgbox Route25_BillsHouse_Text_TeleporterUnlocked, MSGBOX_DEFAULT
	setflag FLAG_TELEPORTER_UNLOCKED
	addvar VAR_BILLS_GRANDPA, 1
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_ShownAll::
	msgbox Route25_BillsHouse_Text_ShownAll, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25_BillsHouse_EventScript_Gramps_Correctmon::
	msgbox Route25_BillsHouse_Text_ShownPokemon, MSGBOX_DEFAULT
	msgbox Route25_BillsHouse_Text_Appreciation, MSGBOX_DEFAULT
	@ This used to loop `giveitem VAR_TEMP_0` VAR_TEMP_1 times with VAR_0x8006 as
	@ the counter - but Std_ObtainItem does `copyvar VAR_0x8006, ITEMID`, so after
	@ the first item the counter held the item id, not the count, and the loop
	@ always exited after one. giveitem's amount goes through setorcopyvar just
	@ like the item does, so one call does the whole job - and prints a single
	@ "obtained 7 EXP CANDY L" instead of seven separate messages.
	giveitem VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route25_BillsHouse_Text_ComeAgain, MSGBOX_DEFAULT
	addvar VAR_BILLS_GRANDPA, 1
	closemessage
	release
	end

Route25_BillsHouse_Movement_MonCelebration:
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_down
	step_end

Route25_BillsHouse_Text_GrandpaIntro:
	.string "Hm? You know BILL? He's my\n"
	.string "grandson.\p"
	.string "He's in JOHTO. He does\n"
	.string "something with PCs, so I'm\l"
	.string "housesitting.$"

@ Each clue describes the species AND hints at its hidden ability, so the quest
@ teaches what the teleporter does before it hands the machine over.
@   Sentret Frisk · Hoothoot Tinted Lens · Wooper/Quagsire Unaware
@   Heracross Moxie · Slowpoke Regenerator
Route25_BillsHouse_Text_GrampsSentret:
	.string "BILL says every POKéMON hides\n"
	.string "a second talent it never uses.\p"
	.string "There's a little lookout that\n"
	.string "stands on its tail to watch.\p"
	.string "The sharp ones can tell what a\n"
	.string "stranger is carrying.$"

Route25_BillsHouse_Text_GrampsHoothoot:
	.string "There's an owl that turns its\n"
	.string "head right round at night.\p"
	.string "They say the keenest of them\n"
	.string "see straight through a\l"
	.string "POKéMON's defences.$"

Route25_BillsHouse_Text_GrampsWooper:
	.string "Do you know the carefree one\n"
	.string "that naps in the shallows?\p"
	.string "It pays so little attention\n"
	.string "that a foe puffing itself up\l"
	.string "is quite wasted on it.$"

Route25_BillsHouse_Text_GrampsHeracross:
	.string "BILL told me of a horned\n"
	.string "fighter that hurls anything\l"
	.string "it can lift.\p"
	.string "Each victory only makes it\n"
	.string "hungrier for the next.$"

Route25_BillsHouse_Text_GrampsSlowpoke:
	.string "Do you know the POKéMON that\n"
	.string "is always staring blankly?\p"
	.string "It is slow to notice a wound,\n"
	.string "and slower still to keep one.$"

Route25_BillsHouse_Text_TeleporterUnlocked:
	.string "Oh, one more thing!\p"
	.string "BILL's TELEPORTER.\n"
	.string "That's the big machine over there.\p"
	.string "He never got it working the\n"
	.string "way he meant to.\p"
	.string "But it wakes that sleeping\n"
	.string "talent we've been discussing.\p"
	.string "You're welcome to try it, if\n"
	.string "you'd like!\p"
	.string "Just use that computer over there.$"

Route25_BillsHouse_Text_AskToSeeMon:
	.string "If you have that POKéMON, may I\n"
	.string "see it, please?$"

Route25_BillsHouse_Text_ExcitedToSee:
	.string "You will show me? How good of\n"
	.string "you!$"

Route25_BillsHouse_Text_YouDontHaveIt:
	.string "You don't have it?\n"
	.string "That's too bad…$"

Route25_BillsHouse_Text_ShownPokemon:
	.string "Ah, so that is {STR_VAR_1}?\p"
	.string "Isn't it cute! That's so kind\n"
	.string "of you.$"

Route25_BillsHouse_Text_Appreciation:
	.string "Thanks!\p"
	.string "This is a token of my\n"
	.string "appreciation.$"

Route25_BillsHouse_Text_ComeAgain:
	.string "Come visit again sometime.$"

Route25_BillsHouse_Text_ShownAll:
	.string "Thanks for showing me so many\n"
	.string "cute POKéMON.\p"
	.string "I really enjoyed myself. I'm\n"
	.string "glad I've lived such a long life.\p"
	.string "Feel free to use BILL's\n"
	.string "TELEPORTER whenever you like.$"

Route25_BillsHouse_Text_WrongPokemon:
	.string "Hm?\p"
	.string "That's not the POKéMON that I\n"
	.string "was told about.$"


