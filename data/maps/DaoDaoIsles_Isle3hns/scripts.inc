@ Isle3 is the Melemele clone and the DaoDao hub: the Route 13 boat lands here.
@ Its object events already point at the shared Alola_Melemele_* scripts, so this
@ file only supplies the map-script block those objects rely on. The bodies are
@ reused from MelemeleIsle_hns rather than copied, because duplicating them would
@ collide on the global labels the objects already reference.

DaoDaoIsles_Isle3hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_Isle3hns_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DaoDaoIsles_Isle3hns_OnWarpIntoMapTable
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DaoDaoIsles_Isle3hns_OnFrameTable
	.byte 0

@ Melemele_Totem is an OBJ_EVENT_GFX_VAR_1 object, so VAR_OBJ_GFX_ID_1 has to be
@ set before it spawns or it renders as whatever the var last held.
DaoDaoIsles_Isle3hns_OnTransition:
	setrespawn HEAL_LOCATION_MELEMELE_ISLE_HNS
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_Isle3hns_OnTransition_Day
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_Isle3hns_OnTransition_Day
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_Isle3hns_OnTransition_Day
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( BEWEAR )
	clearflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_Isle3hns_OnTransition_Day:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LEAFEON )
	setflag FLAG_MELEMELE_TOTEM_DAY
	call MelemeleIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_Isle3hns_OnWarpIntoMapTable:
	map_script_2 VAR_TEMP_C, 0, MelemeleIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	map_script_2 VAR_ALOLA_TRAVEL, 1, MelemeleIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

@ VAR_ALOLA_TRAVEL is set to 1 by the Route 13 boat; GetOffBoat plays the arrival
@ scene with Alola_Melemele_Captain (local id 8 on this map too) and clears it to 2.
DaoDaoIsles_Isle3hns_OnFrameTable:
	map_script_2 VAR_ALOLA_TRAVEL, 1, Alola_Melemele_GetOffBoat
	.2byte 0
