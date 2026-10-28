MtMoon_UpperCave_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_UpperCave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMoon_UpperCave_OnTransition:
	callnative SetTimeBasedEncounters
	end

MtMoon_UpperCave_EventScript_Item_TMBodyPress::
	finditem ITEM_TM_BODY_PRESS
	end
