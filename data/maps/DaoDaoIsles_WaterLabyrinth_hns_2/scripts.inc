@ Water Labyrinth. The building at the far west end of the maze is the hidden
@ Rocket lab; its door at (11,16) is the map's only warp.
@
@ The door is sealed until BOTH:
@   VAR_TOHJO_FALLS_GIOVANNI_STATE == 2  - Giovanni beaten in the Celebi
@                                          time-travel encounter at Tohjo Falls
@   FLAG_IS_KANTO_CHAMPION               - Champion for the second time
@
@ Recomputed in ON_TRANSITION rather than stored, because FLAG_IS_KANTO_CHAMPION
@ is cleared again by SSAqua_1F when the player first sails to Kanto; deriving
@ the door state every entry means it can never be left open by that reset.

DaoDaoIsles_WaterLabyrinth_hns_2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DaoDaoIsles_WaterLabyrinth_OnLoad
	.byte 0

DaoDaoIsles_WaterLabyrinth_OnLoad::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, DaoDaoIsles_WaterLabyrinth_SealDoor
	goto_if_ne VAR_TOHJO_FALLS_GIOVANNI_STATE, 2, DaoDaoIsles_WaterLabyrinth_SealDoor
	setflag FLAG_DAODAO_ROCKET_LAB_FOUND
	end

DaoDaoIsles_WaterLabyrinth_SealDoor::
	setmetatile 11, 16, 751, TRUE
	end
