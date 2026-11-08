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

DarkCave_B1F_EventScript_Item_DuskBall::
	finditem ITEM_DUSK_BALL, 3
	end

DarkCave_B1F_EventScript_Item_Everstone::
	finditem ITEM_EVERSTONE
	end

DarkCave_B1F_EventScript_Hiker::
	msgbox DarkCave_B1F_Text_Hiker, MSGBOX_NPC
	end

DarkCave_B1F_Text_Hiker:
	.string "I've been mapping this cave for\n"
	.string "weeks now.\p"
	.string "One of the ladders here goes down\n"
	.string "even deeper.\p"
	.string "There's an old sage down there,\n"
	.string "guarding some passage.\p"
	.string "Every time I camp near him, I get\n"
	.string "the worst nightmares...$"
