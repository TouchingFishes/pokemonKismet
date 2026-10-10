DaoDaoIsles_LandfallIsle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_LandfallIsle_hns_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DaoDaoIsles_LandfallIsle_hns_OnWarpIntoMapTable
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DaoDaoIsles_LandfallIsle_hns_OnFrameTable
	.byte 0

DaoDaoIsles_LandfallIsle_hns_OnTransition:
	call_if_unset FLAG_TRIGGERED_DAODAO_LANDFALL_TOTEM, DaoDaoIsles_LandfallIsle_EventScript_HideTotem
	setrespawn HEAL_LOCATION_DAODAO_LANDFALL_ISLE_HNS
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_LandfallIsle_hns_OnTransition_Day
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_LandfallIsle_hns_OnTransition_Day
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_LandfallIsle_hns_OnTransition_Day
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( BEWEAR )
	clearflag FLAG_DAODAO_LANDFALL_TOTEM_DAY
	call DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_LandfallIsle_hns_OnTransition_Day:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_DAODAO_LANDFALL_TOTEM_DAY
	call DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_LandfallIsle_hns_OnWarpIntoMapTable:
	map_script_2 VAR_TEMP_C, 0, DaoDaoIsles_LandfallIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	map_script_2 VAR_DAODAO_TRAVEL, 1, DaoDaoIsles_LandfallIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

DaoDaoIsles_LandfallIsle_hns_OnFrameTable:
	map_script_2 VAR_DAODAO_TRAVEL, 1, DaoDaoIsles_LandfallIsle_GetOffBoat
	.2byte 0

DaoDaoIsles_LandfallIsle_EventScript_Arrival::
	lock
	playse SE_PIN
	applymovement LOCALID_DAODAO_STEVEN_LANDING, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DAODAO_STEVEN_LANDING, Common_Movement_FaceDown
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox DaoDaoIsles_LandfallIsle_Text_StevenArrival, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DAODAO_STATE, 1
	setflag FLAG_VISITED_DAODAO
	clearflag FLAG_HIDE_PHANT_OUTSIDE
	release
	end

DaoDaoIsles_LandfallIsle_EventScript_Steven::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_Text_StevenAgain, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_LandfallIsle_Text_StevenArrival:
	.string "{PLAYER}! You made the crossing.\p"
	.string "Rough out past the shelf, isn't it.\n"
	.string "I've done it twice and I still don't\l"
	.string "care for it.\p"
	.string "Word from the FUCHSIA docks is that\n"
	.string "GIDEON came out this way.\p"
	.string "He's the last thing carrying the\n"
	.string "FEDERATION. Everyone else is\l"
	.string "accounted for.\p"
	.string "West, past the water. There's more\n"
	.string "standing out there than open sea,\l"
	.string "whatever the charts say.\p"
	.string "As for the rest of it…\p"
	.string "Three isles. This one, the burnt one\n"
	.string "across the channel, and the low one\l"
	.string "to the south.\p"
	.string "People here talk about the ruins the\n"
	.string "way sailors talk about weather. I\l"
	.string "haven't been, and I'm not going to\l"
	.string "tell you to.\p"
	.string "Go and look, or don't. GIDEON is the\n"
	.string "only thing I need from these islands.\p"
	.string "The POKéMON CENTER is north, by the\n"
	.string "way. You may need it.$"

DaoDaoIsles_LandfallIsle_Text_StevenAgain:
	.string "West, past the water.\p"
	.string "Everything else out here is yours to\n"
	.string "find or leave alone.$"

@ -----------------------------------------------------------------------------------------
@ Moved from MelemeleIsle_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing:
	setvar VAR_TEMP_C, 1
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	compare VAR_TEMP_A, 34
	goto_if_ne DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing_End
	compare VAR_TEMP_B, 26
	goto_if_eq DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing_Set
	compare VAR_TEMP_B, 27
	goto_if_eq DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing_Set
	goto DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing_End

DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing_Set:
	setvar VAR_TEMP_C, 0

DaoDaoIsles_LandfallIsle_hns_SetTotemSignWarpFacing_End:
	return

DaoDaoIsles_LandfallIsle_hns_EventScript_FacePlayerUpAfterTotemWarp::
	setvar VAR_TEMP_C, 1
	applymovement LOCALID_PLAYER, DaoDaoIsles_LandfallIsle_hns_Movement_FacePlayerUpAfterTotemWarp
	return

DaoDaoIsles_LandfallIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	applymovement LOCALID_DAODAO_LANDFALL_CAPTAIN, DaoDaoIsles_LandfallIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	applymovement LOCALID_PLAYER, DaoDaoIsles_LandfallIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return

DaoDaoIsles_LandfallIsle_GetOffBoat::
	lock
	delay 30
	applymovement LOCALID_DAODAO_LANDFALL_CAPTAIN, DaoDaoIsles_LandfallIsle_GetOffBoat_Movement_0
	applymovement LOCALID_PLAYER, DaoDaoIsles_LandfallIsle_GetOffBoat_Movement_1
	waitmovement 0
	msgbox DaoDaoIsles_LandfallIsle_GetOffBoat_Text_0, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DAODAO_TRAVEL, 2
	applymovement LOCALID_PLAYER, DaoDaoIsles_LandfallIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	waitmovement 0
	release
	end


DaoDaoIsles_LandfallIsle_TravelToKanto::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_TravelToKanto_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DaoDaoIsles_LandfallIsle_TravelToKanto_1
	msgbox DaoDaoIsles_LandfallIsle_TravelToKanto_Text_2, MSGBOX_AUTOCLOSE
	release
	end

DaoDaoIsles_LandfallIsle_TravelToKanto_1:
	msgbox DaoDaoIsles_LandfallIsle_TravelToKanto_Text_1, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 32
	goto_if_eq DaoDaoIsles_LandfallIsle_TravelToKanto_5
	compare VAR_TEMP_0, 23
	goto_if_eq DaoDaoIsles_LandfallIsle_TravelToKanto_8
DaoDaoIsles_LandfallIsle_TravelToKanto_7:
DaoDaoIsles_LandfallIsle_TravelToKanto_4:
	applymovement LOCALID_DAODAO_LANDFALL_CAPTAIN, DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_2
	applymovement LOCALID_PLAYER, DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_2
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	hidefollower
	playse SE_EXIT
	special SpawnCameraObject
	hideobjectat LOCALID_PLAYER, MAP_DAO_DAO_ISLES_LANDFALL_ISLE_HNS
	hideobjectat LOCALID_DAODAO_LANDFALL_CAPTAIN, MAP_DAO_DAO_ISLES_LANDFALL_ISLE_HNS
	applymovement OBJ_EVENT_ID_CAMERA, DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_3
	waitmovement 0
	waitse
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_RG_SS_ANNE_HORN
	waitse
	playse SE_M_SURF
	applymovement LOCALID_DAODAO_LANDFALL_SHIP, DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_4
	delay 90
	fadescreenswapbuffers FADE_TO_BLACK
	special RemoveCameraObject
	warp MAP_ROUTE13_HNS, 77, 26
	waitstate
	end

DaoDaoIsles_LandfallIsle_TravelToKanto_5:
	applymovement LOCALID_PLAYER, DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_0
	waitmovement 0
	goto DaoDaoIsles_LandfallIsle_TravelToKanto_4

DaoDaoIsles_LandfallIsle_TravelToKanto_6:
	applymovement LOCALID_PLAYER, DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_1
	waitmovement 0
	goto DaoDaoIsles_LandfallIsle_TravelToKanto_4

DaoDaoIsles_LandfallIsle_TravelToKanto_8:
	compare VAR_TEMP_1, 33
	goto_if_eq DaoDaoIsles_LandfallIsle_TravelToKanto_6
	goto DaoDaoIsles_LandfallIsle_TravelToKanto_7


DaoDaoIsles_LandfallIsle_Mailbox::
	lock
	msgbox DaoDaoIsles_LandfallIsle_Mailbox_Text_0
	release
	end


DaoDaoIsles_LandfallIsle_Melemele_Sign::
	lock
	msgbox DaoDaoIsles_LandfallIsle_Melemele_Sign_Text_0
	release
	end


DaoDaoIsles_LandfallIsle_Pokecenter_Sign::
	lock
	msgbox DaoDaoIsles_LandfallIsle_Pokecenter_Sign_Text_0
	release
	end


DaoDaoIsles_LandfallIsle_MelemeleMart_Sign::
	lock
	msgbox DaoDaoIsles_LandfallIsle_MelemeleMart_Sign_Text_0
	release
	end


DaoDaoIsles_LandfallIsle_TotemBattle_Trigger::
	goto_if_unset FLAG_TRIGGERED_DAODAO_LANDFALL_TOTEM, DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_1
	end

DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_1:
	goto DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_4

DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_4:
	lock
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	fadescreenswapbuffers FADE_TO_BLACK
	delay 30
	clearflag FLAG_HIDE_DAODAO_LANDFALL_TOTEM
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_14
	playmoncry SPECIES_BEWEAR, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( BEWEAR )
	clearflag FLAG_DAODAO_LANDFALL_TOTEM_DAY
	addobject LOCALID_DAODAO_LANDFALL_TOTEM
	waitmoncry
DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_13:
	special DrawWholeMapView
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 30
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_20
	playmoncry SPECIES_BEWEAR, 0
	applymovement LOCALID_DAODAO_LANDFALL_TOTEM, DaoDaoIsles_LandfallIsle_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	waitmoncry
DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_19:
	setflag FLAG_TRIGGERED_DAODAO_LANDFALL_TOTEM
	release
	end

DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_14:
	playmoncry SPECIES_LEAFEON, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_DAODAO_LANDFALL_TOTEM_DAY
	addobject LOCALID_DAODAO_LANDFALL_TOTEM
	waitmoncry
	goto DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_13

DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_20:
	playmoncry SPECIES_LEAFEON, 0
	applymovement LOCALID_DAODAO_LANDFALL_TOTEM, DaoDaoIsles_LandfallIsle_SamsonOak_Trigger_Beginning_Movement_2
	waitmovement 0
	waitmoncry
	goto DaoDaoIsles_LandfallIsle_TotemBattle_Trigger_19


DaoDaoIsles_LandfallIsle_TotemBattle::
	lock
	faceplayer
	goto_if_set FLAG_DAODAO_LANDFALL_TOTEM_DAY, DaoDaoIsles_LandfallIsle_TotemBattle_1
	playmoncry SPECIES_BEWEAR, 0
	msgbox DaoDaoIsles_LandfallIsle_TotemBattle_Text_2, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_STUFFUL, 60, ITEM_NONE, SPECIES_BEWEAR, 60, ITEM_PECHA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 0, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_7
	@ Any other ending (your Dragon Tail or Circle Throw, say) still undoes the battle flags.
	goto DaoDaoIsles_LandfallIsle_TotemBattle_9

DaoDaoIsles_LandfallIsle_TotemBattle_1:
	playmoncry SPECIES_LEAFEON, 0
	msgbox DaoDaoIsles_LandfallIsle_TotemBattle_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_EEVEE, 60, ITEM_NONE, SPECIES_LEAFEON, 60, ITEM_PECHA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_5
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq DaoDaoIsles_LandfallIsle_TotemBattle_9
	@ Any other ending (your Dragon Tail or Circle Throw, say) still undoes the battle flags.
	goto DaoDaoIsles_LandfallIsle_TotemBattle_9

DaoDaoIsles_LandfallIsle_TotemBattle_5:
	setflag FLAG_HIDE_DAODAO_LANDFALL_TOTEM
	setflag FLAG_DEFEATED_DAODAO_LANDFALL_TOTEM
	removeobject LOCALID_DAODAO_LANDFALL_TOTEM
	msgbox DaoDaoIsles_LandfallIsle_TotemBattle_Text_1, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_LandfallIsle_TotemBattle_7:
	setflag FLAG_HIDE_DAODAO_LANDFALL_TOTEM
	setflag FLAG_DEFEATED_DAODAO_LANDFALL_TOTEM
	removeobject LOCALID_DAODAO_LANDFALL_TOTEM
	msgbox DaoDaoIsles_LandfallIsle_TotemBattle_Text_3, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_LandfallIsle_TotemBattle_9:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end


DaoDaoIsles_LandfallIsle_Totem_sign::
	lock
	goto_if_unset FLAG_DEFEATED_DAODAO_LANDFALL_TOTEM, DaoDaoIsles_LandfallIsle_Totem_sign_Locked
	goto_if_unset FLAG_DEFEATED_DAODAO_KILN_TOTEM, DaoDaoIsles_LandfallIsle_Totem_sign_Locked
	goto_if_unset FLAG_DEFEATED_DAODAO_WAKE_TOTEM, DaoDaoIsles_LandfallIsle_Totem_sign_Locked
	msgbox DaoDaoIsles_LandfallIsle_Totem_sign_Text_0
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, DaoDaoIsles_LandfallIsle_Totem_sign_Text_1, DaoDaoIsles_LandfallIsle_Totem_sign_Text_2, DaoDaoIsles_LandfallIsle_Totem_sign_Text_4, DaoDaoIsles_LandfallIsle_Totem_sign_Text_5
	goto_if_eq VAR_RESULT, 0, DaoDaoIsles_LandfallIsle_Totem_sign_Landfall
	goto_if_eq VAR_RESULT, 1, DaoDaoIsles_LandfallIsle_Totem_sign_Kiln
	goto_if_eq VAR_RESULT, 2, DaoDaoIsles_LandfallIsle_Totem_sign_Wake
	release
	end

DaoDaoIsles_LandfallIsle_Totem_sign_Locked:
	msgbox DaoDaoIsles_LandfallIsle_Totem_sign_Text_6, MSGBOX_AUTOCLOSE
	release
	end

DaoDaoIsles_LandfallIsle_Totem_sign_Landfall:
	warp MAP_DAO_DAO_ISLES_LANDFALL_ISLE_HNS, 34, 26
	waitstate
	end

DaoDaoIsles_LandfallIsle_Totem_sign_Kiln:
	warp MAP_DAO_DAO_ISLES_KILN_ISLE_HNS, 9, 11
	waitstate
	end

DaoDaoIsles_LandfallIsle_Totem_sign_Wake:
	warp MAP_DAO_DAO_ISLES_WAKE_ISLE_HNS, 13, 8
	waitstate
	end


DaoDaoIsles_LandfallIsle_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_DAODAO_LANDFALL_SWIMMER_1_HNS, DaoDaoIsles_LandfallIsle_TrainerBattleSwimmer_Text_0, DaoDaoIsles_LandfallIsle_TrainerBattleSwimmer_Text_1
	msgbox DaoDaoIsles_LandfallIsle_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_Bugcatcher::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_Bugcatcher_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_camper::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_camper_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_Picnicker::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_Picnicker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
	face_up
	step_end

DaoDaoIsles_LandfallIsle_GetOffBoat_Movement_0:
	face_right
	step_end

DaoDaoIsles_LandfallIsle_GetOffBoat_Movement_1:
	face_left
	step_end

DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_0:
	walk_right
	walk_down
	step_end

DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_1:
	walk_up
	walk_right
	walk_right
	walk_down
	step_end

DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_2:
	face_down
	step_end

DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_3:
	walk_down
	step_end

DaoDaoIsles_LandfallIsle_TravelToKanto_Movement_4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

DaoDaoIsles_LandfallIsle_SamsonOak_Trigger_Beginning_Movement_2:
	walk_in_place_down
	walk_in_place_down
	step_end

DaoDaoIsles_LandfallIsle_GetOffBoat_Text_0:
	.string "Welcome back to the ISLES!\p"
	.string "Come back if you'd like to take a trip\n"
	.string "to mainland KANTO!$"

DaoDaoIsles_LandfallIsle_TravelToKanto_Text_0:
	.string "Ahoy!\p"
	.string "Would you like to travel to mainland\n"
	.string "KANTO?$"

DaoDaoIsles_LandfallIsle_TravelToKanto_Text_1:
	.string "Ahoy! Let's get you on board!$"

DaoDaoIsles_LandfallIsle_TravelToKanto_Text_2:
	.string "Ahoy!\n"
	.string "Come back when you'd like to set sail.$"

DaoDaoIsles_LandfallIsle_Mailbox_Text_0:
	.string "SAMSON OAK's VILLA$"

DaoDaoIsles_LandfallIsle_Melemele_Sign_Text_0:
	.string "Welcome to LANDFALL ISLE!$"

DaoDaoIsles_LandfallIsle_Pokecenter_Sign_Text_0:
	.string "Welcome to the LANDFALL ISLE\n"
	.string "POKéMON CENTER!\p"
	.string "This is the only POKéMON CENTER on the\n"
	.string "DAODAO ISLES but you can rest on\l"
	.string "benches around the ISLES.$"

DaoDaoIsles_LandfallIsle_MelemeleMart_Sign_Text_0:
	.string "LANDFALL ISLE MART$"

DaoDaoIsles_LandfallIsle_TotemBattle_Text_0:
	.string "Leee!$"

DaoDaoIsles_LandfallIsle_TotemBattle_Text_1:
	.string "Totem LEAFEON was defeated!\n"
	.string "It scampered off somewhere…$"

DaoDaoIsles_LandfallIsle_TotemBattle_Text_2:
	.string "Thhhh!$"

DaoDaoIsles_LandfallIsle_TotemBattle_Text_3:
	.string "Totem BEWEAR was defeated!\n"
	.string "It scampered off somewhere…$"

DaoDaoIsles_LandfallIsle_hns_Movement_FacePlayerUpAfterTotemWarp:
	face_up
	step_end


DaoDaoIsles_LandfallIsle_Totem_sign_Text_0:
	.string "The totem is emanating a strong\n"
	.string "energy…\p"
	.string "Touch the totem to teleport to another\n"
	.string "Isle?$"

DaoDaoIsles_LandfallIsle_Totem_sign_Text_1:
	.string "LANDFALL ISLE$"

DaoDaoIsles_LandfallIsle_Totem_sign_Text_2:
	.string "KILN ISLE$"

DaoDaoIsles_LandfallIsle_Totem_sign_Text_4:
	.string "WAKE ISLE$"

DaoDaoIsles_LandfallIsle_Totem_sign_Text_5:
	.string "Cancel$"

DaoDaoIsles_LandfallIsle_Totem_sign_Text_6:
	.string "A strange totem stands here,\n"
	.string "power is emanating from it…$"

DaoDaoIsles_LandfallIsle_TrainerBattleSwimmer_Text_0:
	.string "The waters are warm here by the ISLES!$"

DaoDaoIsles_LandfallIsle_TrainerBattleSwimmer_Text_1:
	.string "Maybe I should dry off on land for\na bit…$"

DaoDaoIsles_LandfallIsle_TrainerBattleSwimmer_Text_2:
	.string "There are plenty of neat POKéMON in\n"
	.string "the water, try all your fishing rods!$"

DaoDaoIsles_LandfallIsle_Bugcatcher_Text_0:
	.string "The bug POKéMON on the DAODAO ISLES\n"
	.string "are much bigger than those in KANTO!$"

DaoDaoIsles_LandfallIsle_camper_Text_0:
	.string "I traveled all the way from KANTO to see\n"
	.string "a variant of my favorite cat POKéMON,\l"
	.string "MEOWTH!$"

DaoDaoIsles_LandfallIsle_Picnicker_Text_0:
	.string "These ISLES are chock full of unique\n"
	.string "POKéMON!\p"
	.string "I need to stock up on POKé BALLS so I\n"
	.string "can catch them all!$"

DaoDaoIsles_LandfallIsle_EventScript_HideTotem:
	setflag FLAG_HIDE_DAODAO_LANDFALL_TOTEM
	return
