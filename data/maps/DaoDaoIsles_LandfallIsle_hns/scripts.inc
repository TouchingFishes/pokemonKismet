DaoDaoIsles_LandfallIsle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_LandfallIsle_hns_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DaoDaoIsles_LandfallIsle_hns_OnWarpIntoMapTable
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DaoDaoIsles_LandfallIsle_hns_OnFrameTable
	.byte 0

DaoDaoIsles_LandfallIsle_hns_OnTransition:
	setrespawn HEAL_LOCATION_MELEMELE_ISLE_HNS
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_LandfallIsle_hns_OnTransition_Day
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_LandfallIsle_hns_OnTransition_Day
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_LandfallIsle_hns_OnTransition_Day
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( BEWEAR )
	clearflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_LandfallIsle_hns_OnTransition_Day:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_LandfallIsle_hns_OnWarpIntoMapTable:
	map_script_2 VAR_TEMP_C, 0, MelemeleIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	map_script_2 VAR_ALOLA_TRAVEL, 1, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

DaoDaoIsles_LandfallIsle_hns_OnFrameTable:
	map_script_2 VAR_ALOLA_TRAVEL, 1, Alola_Melemele_GetOffBoat
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
	setvar VAR_ALOLA_STATE, 1
	setflag FLAG_VISITED_ALOLA
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
	.string "JANINE had word from the docks.\n"
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
	.string "The POKéCENTRE is north, by the way.\n"
	.string "You'll may need it.$"

DaoDaoIsles_LandfallIsle_Text_StevenAgain:
	.string "West, past the water.\p"
	.string "Everything else out here is yours to\n"
	.string "find or leave alone.$"
