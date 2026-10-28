DarkCave_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DarkCave_B1F_OnTransition:
	callnative SetTimeBasedEncounters
	end

DarkCave_B1F_EventScript_Item_TMDoubleTeam::
	finditem ITEM_TM_DOUBLE_TEAM
	end
