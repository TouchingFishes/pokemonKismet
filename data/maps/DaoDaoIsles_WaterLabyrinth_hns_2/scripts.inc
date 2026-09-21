DaoDaoIsles_WaterLabyrinth_hns_2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DaoDaoIsles_WaterLabyrinth_OnLoad
	.byte 0

DaoDaoIsles_WaterLabyrinth_OnLoad::
	goto_if_set FLAG_DAODAO_ROCKET_LAB_FOUND, DaoDaoIsles_WaterLabyrinth_LeaveDoorOpen
	goto_if_unset FLAG_IS_KANTO_CHAMPION, DaoDaoIsles_WaterLabyrinth_SealDoor
	goto_if_ne VAR_TOHJO_FALLS_GIOVANNI_STATE, 2, DaoDaoIsles_WaterLabyrinth_SealDoor
	end

DaoDaoIsles_WaterLabyrinth_LeaveDoorOpen::
	end

DaoDaoIsles_WaterLabyrinth_SealDoor::
	setmetatile 11, 16, 751, TRUE
	end
