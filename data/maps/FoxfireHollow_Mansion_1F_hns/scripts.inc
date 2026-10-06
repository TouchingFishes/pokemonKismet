@ The NINETALES's house in FOXFIRE HOLLOW (MIGRATION_DECISIONS.md 59). While
@ VAR_FOXFIRE_HOLLOW_STATE is 1-3 this floor is its illusion: the house swept clean and lit
@ (LAYOUT_FOXFIRE_HOLLOW_MANSION_1F_ILLUSION_HNS, painted by .claude/paint_foxfire_mansion.py),
@ with the woman and the NINETALES by the fire. From 4 it is FRLG's real 1F, the ruin.
FoxfireHollow_Mansion_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FoxfireHollow_Mansion_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FoxfireHollow_Mansion_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FoxfireHollow_Mansion_1F_OnFrame
	.byte 0

FoxfireHollow_Mansion_1F_OnLoad::
	call_if_set FLAG_FOXFIRE_MANSION_SWITCH_STATE, FoxfireHollow_Mansion_EventScript_PressSwitch_1F
	end

FoxfireHollow_Mansion_1F_OnTransition::
	call_if_eq VAR_FOXFIRE_HOLLOW_STATE, 0, FoxfireHollow_Mansion_1F_EventScript_MetAtTheDoor
	call_if_eq VAR_FOXFIRE_HOLLOW_STATE, 3, FoxfireHollow_Mansion_1F_EventScript_TruthUnfinished
	call FoxfireHollow_Mansion_EventScript_Weather
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	goto_if_ge VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_Ruined
	setmaplayoutindex LAYOUT_FOXFIRE_HOLLOW_MANSION_1F_ILLUSION_HNS
	savebgm MUS_HG_KIMONO_GIRL
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_2
	@ Nobody else is in the house the illusion shows. The trainers are hidden, and the item
	@ balls are parked far outside the map, where nothing spawns; templates reload every visit.
	setflag FLAG_TEMP_4
	setobjectxyperm LOCALID_FOXFIRE_MANSION_1F_CARBOS, 100, 100
	setobjectxyperm LOCALID_FOXFIRE_MANSION_1F_ESCAPE_ROPE, 100, 100
	setobjectxyperm LOCALID_FOXFIRE_MANSION_1F_PROTEIN, 100, 100
	call_if_eq VAR_FOXFIRE_HOLLOW_STATE, 1, FoxfireHollow_Mansion_1F_EventScript_PlaceForGreeting
	end

@ Only if the hollow's trigger row was somehow skipped.
FoxfireHollow_Mansion_1F_EventScript_MetAtTheDoor:
	setvar VAR_FOXFIRE_HOLLOW_STATE, 1
	return

@ 3 only lasts while the truth scene runs, so it can't be saved there. Anything that still
@ holds it goes back to before the diary.
FoxfireHollow_Mansion_1F_EventScript_TruthUnfinished:
	setvar VAR_FOXFIRE_HOLLOW_STATE, 2
	return

FoxfireHollow_Mansion_1F_EventScript_Ruined:
	call_if_eq VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_ShowNinetales
	end

FoxfireHollow_Mansion_1F_EventScript_ShowNinetales:
	clearflag FLAG_TEMP_3
	return

@ Every floor: fog while the NINETALES waits (4-5), clear air otherwise. The illusion is only
@ ever on this floor, and it is clear too.
FoxfireHollow_Mansion_EventScript_Weather::
	setweather WEATHER_NONE
	call_if_eq VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_EventScript_Fog
	call_if_eq VAR_FOXFIRE_HOLLOW_STATE, 5, FoxfireHollow_Mansion_EventScript_Fog
	return

FoxfireHollow_Mansion_EventScript_Fog:
	setweather WEATHER_FOG_HORIZONTAL
	return

@ The first visit: she comes down the carpet to the door, and the NINETALES runs to meet it.
FoxfireHollow_Mansion_1F_EventScript_PlaceForGreeting:
	setobjectxyperm LOCALID_FOXFIRE_MANSION_WOMAN, 7, 24
	setobjectxyperm LOCALID_FOXFIRE_MANSION_NINETALES_HEARTH, 9, 28
	return

@ Both scenes move the state on first: an ON_FRAME script re-fires until its value changes,
@ including on return from a battle.
FoxfireHollow_Mansion_1F_OnFrame:
	map_script_2 VAR_FOXFIRE_HOLLOW_STATE, 1, FoxfireHollow_Mansion_1F_EventScript_Greeting
	map_script_2 VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_Reveal
	.2byte 0

FoxfireHollow_Mansion_1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 0
	call FoxfireHollow_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

FoxfireHollow_Mansion_1F_EventScript_Ted::
	trainerbattle_single TRAINER_MANSION_TED_HNS, FoxfireHollow_Mansion_1F_Text_TedIntro, FoxfireHollow_Mansion_1F_Text_TedDefeat
	msgbox FoxfireHollow_Mansion_1F_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

FoxfireHollow_Mansion_1F_EventScript_Mavis::
	trainerbattle_single TRAINER_MANSION_MAVIS_HNS, FoxfireHollow_Mansion_1F_Text_MavisIntro, FoxfireHollow_Mansion_1F_Text_MavisDefeat
	msgbox FoxfireHollow_Mansion_1F_Text_MavisPostBattle, MSGBOX_AUTOCLOSE
	end

FoxfireHollow_Mansion_1F_Text_TedIntro::
	.string "Who are you?\n"
	.string "There shouldn't be anyone here.$"

FoxfireHollow_Mansion_1F_Text_TedDefeat::
	.string "Ouch!$"

FoxfireHollow_Mansion_1F_Text_TedPostBattle::
	.string "My instruments can't explain this\n"
	.string "fog. It isn't weather.$"

FoxfireHollow_Mansion_1F_Text_MavisIntro::
	.string "Shh… Can you hear it?\n"
	.string "The house is breathing.$"

FoxfireHollow_Mansion_1F_Text_MavisDefeat::
	.string "My hex… fizzled out.$"

FoxfireHollow_Mansion_1F_Text_MavisPostBattle::
	.string "Something lived here long after\n"
	.string "the people left.\p"
	.string "It still does.$"

FoxfireHollow_Mansion_1F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end
FoxfireHollow_Mansion_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end
FoxfireHollow_Mansion_1F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

FoxfireHollow_Mansion_EventScript_SecretSwitch::
	msgbox FoxfireHollow_Mansion_Text_PressSecretSwitch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FoxfireHollow_Mansion_EventScript_DontPressSwitch
	msgbox FoxfireHollow_Mansion_Text_WhoWouldnt
	goto_if_set FLAG_FOXFIRE_MANSION_SWITCH_STATE, FoxfireHollow_Mansion_EventScript_ResetSwitch
	setflag FLAG_FOXFIRE_MANSION_SWITCH_STATE
	switch VAR_0x8004
	case 0, FoxfireHollow_Mansion_EventScript_PressSwitch_1F
	case 1, FoxfireHollow_Mansion_EventScript_PressSwitch_2F
	case 2, FoxfireHollow_Mansion_EventScript_PressSwitch_3F
	case 3, FoxfireHollow_Mansion_EventScript_PressSwitch_B1F
	end

FoxfireHollow_Mansion_EventScript_ResetSwitch::
	clearflag FLAG_FOXFIRE_MANSION_SWITCH_STATE
	switch VAR_0x8004
	case 0, FoxfireHollow_Mansion_EventScript_ResetSwitch_1F
	case 1, FoxfireHollow_Mansion_EventScript_ResetSwitch_2F
	case 2, FoxfireHollow_Mansion_EventScript_ResetSwitch_3F
	case 3, FoxfireHollow_Mansion_EventScript_ResetSwitch_B1F
	end

FoxfireHollow_Mansion_EventScript_DontPressSwitch::
	msgbox FoxfireHollow_Mansion_Text_NotQuiteYet
	releaseall
	end

FoxfireHollow_Mansion_EventScript_PressSwitch_1F::
	setmetatile 22, 10, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 23, 10, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 10, METATILE_PokemonMansion_Floor, 0
	setmetatile 22, 11, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 23, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 27, 25, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 28, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 29, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 27, 26, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 28, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 29, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 32, 25, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 33, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 34, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 32, 26, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 33, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 34, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 31, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 32, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 33, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 31, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 32, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 33, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile  5,  4, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

FoxfireHollow_Mansion_EventScript_ResetSwitch_1F::
	setmetatile 22, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 23, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 24, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 22, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 23, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 24, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 27, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 28, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 29, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 27, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 28, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 29, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 32, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 33, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 34, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 32, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 33, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 34, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 31, 18, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 32, 18, METATILE_PokemonMansion_Floor, 0
	setmetatile 33, 18, METATILE_PokemonMansion_Floor, 0
	setmetatile 31, 19, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 32, 19, METATILE_PokemonMansion_Floor, 0
	setmetatile 33, 19, METATILE_PokemonMansion_Floor, 0
	setmetatile  5,  4, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

FoxfireHollow_Mansion_EventScript_PressSwitch_2F::
	setmetatile 24, 14, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 25, 14, METATILE_PokemonMansion_Floor, 0
	setmetatile 26, 14, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 15, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 25, 15, METATILE_PokemonMansion_Floor, 0
	setmetatile 26, 15, METATILE_PokemonMansion_Floor, 0
	setmetatile 10, 28, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 10, 29, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 10, 30, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 10, 31, METATILE_PokemonMansion_Floor, 0
	setmetatile 10, 32, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile 12,  4, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 12,  5, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 12,  6, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 12,  7, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 12,  8, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile  2, 15, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

FoxfireHollow_Mansion_EventScript_ResetSwitch_2F::
	setmetatile 24, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 25, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 26, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 24, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 25, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 26, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 10, 28, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 10, 29, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 10, 30, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 10, 31, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 10, 32, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile 12,  4, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 12,  5, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 12,  6, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 12,  7, METATILE_PokemonMansion_Floor, 0
	setmetatile 12,  8, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile  2, 15, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

FoxfireHollow_Mansion_EventScript_PressSwitch_3F::
	setmetatile 17, 11, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 18, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 19, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 17, 12, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 18, 12, METATILE_PokemonMansion_Floor, 0
	setmetatile 19, 12, METATILE_PokemonMansion_Floor, 0
	setmetatile 21,  4, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 21,  5, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 21,  6, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 21,  7, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 21,  8, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile 12,  4, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

FoxfireHollow_Mansion_EventScript_ResetSwitch_3F::
	setmetatile 17, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 18, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 19, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 17, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 18, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 19, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 21,  4, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 21,  5, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 21,  6, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 21,  7, METATILE_PokemonMansion_Floor, 0
	setmetatile 21,  8, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile 12,  4, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

FoxfireHollow_Mansion_EventScript_PressSwitch_B1F::
	setmetatile 33, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 34, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 35, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 33, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft_Basement, 1
	setmetatile 34, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid_Basement, 1
	setmetatile 35, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight_Basement, 1
	setmetatile 16, 26, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 16, 27, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 16, 28, METATILE_PokemonMansion_Barrier_Vertical_MidShadow_Basement, 1
	setmetatile 16, 29, METATILE_PokemonMansion_Barrier_Vertical_Mid_Basement, 1
	setmetatile 16, 30, METATILE_PokemonMansion_Barrier_Vertical_Bottom_Basement, 1
	setmetatile 12,  8, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 12,  9, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 12, 10, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 12, 11, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 12, 12, METATILE_PokemonMansion_Wall_EndCap_Basement, 0
	setmetatile 20, 22, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 21, 22, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 22, 22, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 20, 23, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 21, 23, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 22, 23, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 24, 28, METATILE_PokemonMansion_Statue_RedEyes_Basement, 0
	setmetatile 27,  4, METATILE_PokemonMansion_Statue_RedEyes_Basement, 0
	return

FoxfireHollow_Mansion_EventScript_ResetSwitch_B1F::
	setmetatile 33, 20, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 34, 20, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 35, 20, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 33, 21, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 34, 21, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 35, 21, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 16, 26, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 16, 27, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 16, 28, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 16, 29, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 16, 30, METATILE_PokemonMansion_Wall_EndCap_Basement, 0
	setmetatile 12,  8, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 12,  9, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 12, 10, METATILE_PokemonMansion_Barrier_Vertical_MidShadow_Basement, 1
	setmetatile 12, 11, METATILE_PokemonMansion_Barrier_Vertical_Mid_Basement, 1
	setmetatile 12, 12, METATILE_PokemonMansion_Barrier_Vertical_Bottom_Basement, 1
	setmetatile 20, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 21, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 22, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 20, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft_Basement, 1
	setmetatile 21, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid_Basement, 1
	setmetatile 22, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight_Basement, 1
	setmetatile 24, 28, METATILE_PokemonMansion_Statue_BlackEyes_Basement, 0
	setmetatile 27,  4, METATILE_PokemonMansion_Statue_BlackEyes_Basement, 0
	return

@ The player is on the front door mat at (7,33).
FoxfireHollow_Mansion_1F_EventScript_Greeting::
	lockall
	setvar VAR_FOXFIRE_HOLLOW_STATE, 2
	delay 20
	playmoncry SPECIES_NINETALES, CRY_MODE_HIGH_PITCH
	applymovement LOCALID_FOXFIRE_MANSION_NINETALES_HEARTH, FoxfireHollow_Mansion_1F_Movement_MasterIsHome
	waitmovement 0
	waitmoncry
	delay 40
	applymovement LOCALID_FOXFIRE_MANSION_NINETALES_HEARTH, FoxfireHollow_Mansion_1F_Movement_NotTheMaster
	waitmovement 0
	applymovement LOCALID_FOXFIRE_MANSION_WOMAN, FoxfireHollow_Mansion_1F_Movement_DownTheCarpet
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FOXFIRE_MANSION_WOMAN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox FoxfireHollow_Mansion_1F_Text_Oh, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOXFIRE_MANSION_WOMAN, Common_Movement_WalkDown
	waitmovement 0
	msgbox FoxfireHollow_Mansion_1F_Text_ForAMoment, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOXFIRE_MANSION_WOMAN, FoxfireHollow_Mansion_1F_Movement_LooksAway
	waitmovement 0
	msgbox FoxfireHollow_Mansion_1F_Text_ComeIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOXFIRE_MANSION_WOMAN, Common_Movement_WalkDown
	waitmovement 0
	msgbox FoxfireHollow_Mansion_1F_Text_Cloak, MSGBOX_DEFAULT
	msgbox FoxfireHollow_Mansion_1F_Text_TheMastersCloak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOXFIRE_MANSION_WOMAN, FoxfireHollow_Mansion_1F_Movement_BackUpTheCarpet
	waitmovement 0
	call FoxfireHollow_Mansion_1F_EventScript_PlaceByTheFire
	releaseall
	end

@ Back where they wait, by the fire in the parlour. The templates move too, so neither jumps
@ back to the hall when the view scrolls.
FoxfireHollow_Mansion_1F_EventScript_PlaceByTheFire:
	setobjectxyperm LOCALID_FOXFIRE_MANSION_WOMAN, 5, 3
	setobjectxy LOCALID_FOXFIRE_MANSION_WOMAN, 5, 3
	turnobject LOCALID_FOXFIRE_MANSION_WOMAN, DIR_EAST
	setobjectxyperm LOCALID_FOXFIRE_MANSION_NINETALES_HEARTH, 7, 3
	setobjectxy LOCALID_FOXFIRE_MANSION_NINETALES_HEARTH, 7, 3
	turnobject LOCALID_FOXFIRE_MANSION_NINETALES_HEARTH, DIR_SOUTH
	return

FoxfireHollow_Mansion_1F_Movement_MasterIsHome:
	face_down
	jump_in_place_down
	walk_fast_down
	walk_fast_down
	step_end

FoxfireHollow_Mansion_1F_Movement_NotTheMaster:
	face_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

FoxfireHollow_Mansion_1F_Movement_DownTheCarpet:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FoxfireHollow_Mansion_1F_Movement_LooksAway:
	face_left
	delay_16
	delay_16
	face_down
	step_end

FoxfireHollow_Mansion_1F_Movement_BackUpTheCarpet:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FoxfireHollow_Mansion_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox FoxfireHollow_Mansion_1F_Text_WomanIdle, MSGBOX_DEFAULT
	closemessage
	release
	end

FoxfireHollow_Mansion_1F_EventScript_HearthNinetales::
	lock
	playmoncry SPECIES_NINETALES, CRY_MODE_NORMAL
	msgbox FoxfireHollow_Mansion_1F_Text_WatchingTheDoor, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

@ The diary is on the east dining table, by the tea tray, and can only be read from (33,9),
@ facing south across it.
FoxfireHollow_Mansion_1F_EventScript_Diary::
	goto_if_ge VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_DiaryDamp
	goto_if_ne VAR_FOXFIRE_HOLLOW_STATE, 2, FoxfireHollow_Mansion_1F_EventScript_DiaryOnly
	lockall
	@ The follower walks one tile behind, on the tile she is about to stand on.
	hidefollower
	msgbox FoxfireHollow_Mansion_1F_Text_Diary, MSGBOX_DEFAULT
	closemessage
	goto FoxfireHollow_Mansion_1F_EventScript_TheTruth

FoxfireHollow_Mansion_1F_EventScript_DiaryOnly:
	msgbox FoxfireHollow_Mansion_1F_Text_Diary, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_1F_EventScript_DiaryDamp:
	msgbox FoxfireHollow_Mansion_1F_Text_DiaryDamp, MSGBOX_SIGN
	end

@ She was by the fire, at the other end of the house. In the time it takes to close a diary she
@ is behind the player. That far from the parlour her object is not loaded, so her template moves
@ and addobject spawns her; setobjectxy only matters if she was loaded after all.
FoxfireHollow_Mansion_1F_EventScript_TheTruth:
	setvar VAR_FOXFIRE_HOLLOW_STATE, 3
	fadeoutbgm 0
	setobjectxyperm LOCALID_FOXFIRE_MANSION_WOMAN, 33, 8
	addobject LOCALID_FOXFIRE_MANSION_WOMAN
	setobjectxy LOCALID_FOXFIRE_MANSION_WOMAN, 33, 8
	turnobject LOCALID_FOXFIRE_MANSION_WOMAN, DIR_SOUTH
	delay 40
	msgbox FoxfireHollow_Mansion_1F_Text_YouFoundIt, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox FoxfireHollow_Mansion_1F_Text_TwoHundredWinters, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_FOXFIRE_MANSION_WOMAN, DIR_WEST
	delay 30
	msgbox FoxfireHollow_Mansion_1F_Text_TheOthersLeft, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_FOXFIRE_MANSION_WOMAN, DIR_SOUTH
	delay 20
	msgbox FoxfireHollow_Mansion_1F_Text_Stay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FoxfireHollow_Mansion_1F_EventScript_StayYes
	msgbox FoxfireHollow_Mansion_1F_Text_StayNo, MSGBOX_DEFAULT
	goto FoxfireHollow_Mansion_1F_EventScript_IllusionBreaks

FoxfireHollow_Mansion_1F_EventScript_StayYes:
	msgbox FoxfireHollow_Mansion_1F_Text_StayYes, MSGBOX_DEFAULT
FoxfireHollow_Mansion_1F_EventScript_IllusionBreaks:
	closemessage
	applymovement LOCALID_FOXFIRE_MANSION_WOMAN, FoxfireHollow_Mansion_1F_Movement_Reach
	waitmovement 0
	msgbox FoxfireHollow_Mansion_1F_Text_SheReaches, MSGBOX_DEFAULT
	closemessage
	playse SE_M_FAINT_ATTACK
	applymovement LOCALID_FOXFIRE_MANSION_WOMAN, FoxfireHollow_Mansion_1F_Movement_Waver
	waitmovement 0
	msgbox FoxfireHollow_Mansion_1F_Text_LikeMist, MSGBOX_DEFAULT
	closemessage
	delay 30
	@ Under the flash she and the NINETALES by the fire are gone, and the NINETALES she
	@ really was stands where she stood.
	playse SE_ICE_BREAK
	dofieldeffect FLDEFF_PHOTO_FLASH
	removeobject LOCALID_FOXFIRE_MANSION_WOMAN
	removeobject LOCALID_FOXFIRE_MANSION_NINETALES_HEARTH
	clearflag FLAG_TEMP_3
	addobject LOCALID_FOXFIRE_MANSION_NINETALES
	turnobject LOCALID_FOXFIRE_MANSION_NINETALES, DIR_SOUTH
	waitfieldeffect FLDEFF_PHOTO_FLASH
	playmoncry SPECIES_NINETALES, CRY_MODE_ECHO_START
	waitmoncry
	delay 30
	@ Out of sight in the parlour, the fire dies. The ruin's fireplace is already cold.
	playse SE_M_HAZE
	delay 30
	msgbox FoxfireHollow_Mansion_1F_Text_TheFireGoesOut, MSGBOX_DEFAULT
	closemessage
	@ The house rots in front of the player. The crumble only re-enables the script once its
	@ debris has landed (about 75 frames), so the waves between it and the waitstate must
	@ take less than that.
	special DoMirageTowerCeilingCrumble
	call FoxfireHollow_Mansion_1F_EventScript_DecayWave1
	delay 16
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	call FoxfireHollow_Mansion_1F_EventScript_DecayWave2
	waitstate
	delay 40
	fadescreenspeed FADE_TO_BLACK, 6
	setvar VAR_FOXFIRE_HOLLOW_STATE, 4
	warpsilent MAP_FOXFIRE_HOLLOW_MANSION_1F_HNS, 33, 9
	waitstate
	releaseall
	end

FoxfireHollow_Mansion_1F_Movement_Reach:
	walk_in_place_slow_down
	step_end

FoxfireHollow_Mansion_1F_Movement_Waver:
	set_invisible
	delay_2
	set_visible
	delay_4
	set_invisible
	delay_2
	set_visible
	delay_8
	set_invisible
	delay_2
	set_visible
	step_end

@ From .claude/paint_foxfire_mansion.py --setmetatile.
FoxfireHollow_Mansion_1F_EventScript_DecayWave1:
	setmetatile 35, 5, 0x2B8, FALSE
	setmetatile 36, 5, 0x2B9, FALSE
	setmetatile 35, 6, 0x2C0, FALSE
	setmetatile 36, 6, 0x2CC, TRUE
	setmetatile 35, 7, 0x2C0, FALSE
	setmetatile 36, 7, 0x2CB, TRUE
	setmetatile 35, 8, 0x2C8, FALSE
	setmetatile 36, 8, 0x2BC, FALSE
	setmetatile 36, 9, 0x2C8, FALSE
	special DrawWholeMapView
	return

FoxfireHollow_Mansion_1F_EventScript_DecayWave2:
	setmetatile 29, 11, 0x33D, FALSE
	setmetatile 30, 11, 0x2BA, FALSE
	setmetatile 26, 12, 0x2CB, TRUE
	setmetatile 27, 12, 0x2CC, TRUE
	setmetatile 28, 12, 0x2CC, TRUE
	setmetatile 29, 12, 0x2CB, TRUE
	setmetatile 30, 12, 0x2C2, FALSE
	setmetatile 26, 13, 0x2BC, FALSE
	setmetatile 27, 13, 0x2CB, TRUE
	setmetatile 28, 13, 0x2CC, TRUE
	setmetatile 29, 13, 0x2CC, TRUE
	setmetatile 30, 13, 0x2C2, FALSE
	setmetatile 26, 14, 0x2C8, FALSE
	setmetatile 27, 14, 0x2BC, FALSE
	setmetatile 28, 14, 0x2CC, TRUE
	setmetatile 29, 14, 0x2CB, TRUE
	setmetatile 30, 14, 0x2C2, FALSE
	special DrawWholeMapView
	return

@ The player arrives at (33,9) facing the table, with the NINETALES at (33,8) behind them.
FoxfireHollow_Mansion_1F_EventScript_Reveal::
	lockall
	setvar VAR_FOXFIRE_HOLLOW_STATE, 5
	hidefollower
	delay 40
	@ West, back across the house toward the parlour the player came from.
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, FoxfireHollow_Mansion_1F_Movement_PanWest
	waitmovement 0
	delay 40
	msgbox FoxfireHollow_Mansion_1F_Text_ARuin, MSGBOX_DEFAULT
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, FoxfireHollow_Mansion_1F_Movement_PanBack
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 20
	msgbox FoxfireHollow_Mansion_1F_Text_CloakGone, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox FoxfireHollow_Mansion_1F_Text_Watching, MSGBOX_DEFAULT
	closemessage
	@ It does not fight here. It turns away, goes into the fog, and the foxfire shows which way.
	applymovement LOCALID_FOXFIRE_MANSION_NINETALES, FoxfireHollow_Mansion_1F_Movement_LeadsTheWay
	waitmovement 0
	playse SE_M_MIST
	applymovement LOCALID_FOXFIRE_MANSION_NINETALES, FoxfireHollow_Movement_Dissolve
	waitmovement 0
	removeobject LOCALID_FOXFIRE_MANSION_NINETALES
	call FoxfireHollow_Mansion_1F_EventScript_Foxfire
	releaseall
	end

@ North out of the dining room and west along the gallery toward the hall stairs: the only way
@ down is up first, then through 3F's broken floor. The view rises four rows to show the gallery.
FoxfireHollow_Mansion_1F_EventScript_Foxfire:
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, FoxfireHollow_Mansion_1F_Movement_LookUp
	waitmovement 0
	playse SE_M_DETECT
	dofieldeffectsparkle 33, 4, 0
	delay 24
	playse SE_M_DETECT
	dofieldeffectsparkle 31, 3, 0
	delay 24
	playse SE_M_DETECT
	dofieldeffectsparkle 28, 3, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 20
	applymovement2 OBJ_EVENT_ID_CAMERA, FoxfireHollow_Mansion_1F_Movement_LookDown
	waitmovement 0
	special RemoveCameraObject
	return

FoxfireHollow_Mansion_1F_Movement_PanWest:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

FoxfireHollow_Mansion_1F_Movement_PanBack:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FoxfireHollow_Mansion_1F_Movement_LookUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FoxfireHollow_Mansion_1F_Movement_LookDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FoxfireHollow_Mansion_1F_Movement_LeadsTheWay:
	face_up
	delay_16
	walk_slow_up
	walk_slow_up
	step_end

FoxfireHollow_Mansion_1F_EventScript_Hearth::
	lockall
	goto_if_ge VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_HearthCold
	msgbox FoxfireHollow_Mansion_1F_Text_RestByTheFire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FoxfireHollow_Mansion_1F_EventScript_HearthDone
	closemessage
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	fadescreen FADE_FROM_BLACK
	msgbox FoxfireHollow_Mansion_1F_Text_Rested, MSGBOX_DEFAULT
FoxfireHollow_Mansion_1F_EventScript_HearthDone:
	closemessage
	releaseall
	end

FoxfireHollow_Mansion_1F_EventScript_HearthCold:
	msgbox FoxfireHollow_Mansion_1F_Text_ColdAsh, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ The mirror where the hall carpet ends (.claude/draft_mansion_fireplace.py). She is in it,
@ though she is by the fire at the other end of the house.
FoxfireHollow_Mansion_1F_EventScript_Mirror::
	goto_if_ge VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_MirrorCracked
	lockall
	msgbox FoxfireHollow_Mansion_1F_Text_Mirror, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox FoxfireHollow_Mansion_1F_Text_NoOneThere, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FoxfireHollow_Mansion_1F_EventScript_MirrorCracked:
	msgbox FoxfireHollow_Mansion_1F_Text_MirrorCracked, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_1F_EventScript_TravellerStatue::
	goto_if_ge VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_TravellerStatueWorn
	lockall
	msgbox FoxfireHollow_Mansion_1F_Text_TravellerStatue, MSGBOX_DEFAULT
	closemessage
	@ Somewhere in the house, the NINETALES answers.
	playmoncry SPECIES_NINETALES, CRY_MODE_WEAK
	waitmoncry
	releaseall
	end

FoxfireHollow_Mansion_1F_EventScript_TravellerStatueWorn:
	msgbox FoxfireHollow_Mansion_1F_Text_TravellerStatueWorn, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_1F_EventScript_TeaTray::
	goto_if_ge VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_TeaTrayLeaves
	msgbox FoxfireHollow_Mansion_1F_Text_TeaTray, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_1F_EventScript_TeaTrayLeaves:
	msgbox FoxfireHollow_Mansion_1F_Text_TeaTrayLeaves, MSGBOX_SIGN
	end

@ The illusion keeps the player on this floor; in the ruin the stairs are open.
FoxfireHollow_Mansion_1F_EventScript_RopedOff::
	goto_if_ge VAR_FOXFIRE_HOLLOW_STATE, 4, FoxfireHollow_Mansion_1F_EventScript_RopedOffNothing
	msgbox FoxfireHollow_Mansion_1F_Text_RopedOff, MSGBOX_SIGN
FoxfireHollow_Mansion_1F_EventScript_RopedOffNothing:
	end

@ Text_Greeting, split at its page breaks.
FoxfireHollow_Mansion_1F_Text_Oh:
	.string "…Oh.$"

FoxfireHollow_Mansion_1F_Text_ForAMoment:
	.string "For a moment I thought…$"

FoxfireHollow_Mansion_1F_Text_ComeIn:
	.string "No. Forgive me. Come in, come in.\n"
	.string "You're soaked through.$"

FoxfireHollow_Mansion_1F_Text_Cloak:
	.string "She puts an old travelling cloak\n"
	.string "around {PLAYER}'s shoulders.\p"
	.string "It smells of woodsmoke.$"

FoxfireHollow_Mansion_1F_Text_TheMastersCloak:
	.string "It's the master's. They won't mind.\p"
	.string "They're away on a journey, but\n"
	.string "they'll be home before the first\l"
	.string "snow.\p"
	.string "Rest by the fire as long as you\n"
	.string "like.$"

FoxfireHollow_Mansion_1F_Text_WomanIdle:
	.string "Stay as long as you like.\p"
	.string "The fog never lifts up here,\n"
	.string "anyway.$"

FoxfireHollow_Mansion_1F_Text_WatchingTheDoor:
	.string "NINETALES is curled by the hearth,\n"
	.string "watching the door.$"

FoxfireHollow_Mansion_1F_Text_Diary:
	.string "It's a diary. The last page reads:\p"
	.string "“Off at first light. I'm leaving\n"
	.string "its BALL on the stand, so it knows\l"
	.string "I'm coming back.\p"
	.string "I told it to wait for me, and it\n"
	.string "will. It always does.\p"
	.string "Home before the first snow.”\p"
	.string "The date is two hundred years ago.$"

FoxfireHollow_Mansion_1F_Text_DiaryDamp:
	.string "The diary is still here, swollen\n"
	.string "with damp. The last page still\l"
	.string "reads:\p"
	.string "“Home before the first snow.”$"

@ Text_YouReadIt, split at its page breaks.
FoxfireHollow_Mansion_1F_Text_YouFoundIt:
	.string "You found the diary.$"

FoxfireHollow_Mansion_1F_Text_TwoHundredWinters:
	.string "…\p"
	.string "Two hundred winters. I have kept\n"
	.string "the fire lit through every one.$"

FoxfireHollow_Mansion_1F_Text_TheOthersLeft:
	.string "The others left, one by one.\n"
	.string "Somebody had to be here when the\l"
	.string "master came home.$"

FoxfireHollow_Mansion_1F_Text_Stay:
	.string "You could stay.\p"
	.string "You look so like them.\n"
	.string "Stay, and it can be the way it was.$"

FoxfireHollow_Mansion_1F_Text_StayYes:
	.string "…You would, wouldn't you.\p"
	.string "And one morning you'd set out at\n"
	.string "first light, just like they did.$"

FoxfireHollow_Mansion_1F_Text_StayNo:
	.string "No.\p"
	.string "No, of course not. Nobody stays.$"

@ Text_HandThroughMist, split at its page breaks.
FoxfireHollow_Mansion_1F_Text_SheReaches:
	.string "She reaches for {PLAYER}'s hand.$"

FoxfireHollow_Mansion_1F_Text_LikeMist:
	.string "Hers passes straight through it,\n"
	.string "like mist.$"

FoxfireHollow_Mansion_1F_Text_TheFireGoesOut:
	.string "Down the hall, the fire goes out.$"

@ Text_Ruin, split at its page breaks; "lodge" became "mansion".
FoxfireHollow_Mansion_1F_Text_ARuin:
	.string "The mansion is a ruin.\p"
	.string "The roof is open to the sky, and\n"
	.string "the fog is pouring in.$"

FoxfireHollow_Mansion_1F_Text_CloakGone:
	.string "The cloak is gone from {PLAYER}'s\n"
	.string "shoulders.$"

FoxfireHollow_Mansion_1F_Text_Watching:
	.string "Where the woman stood, a NINETALES\n"
	.string "is watching {PLAYER}.\p"
	.string "It has been waiting a very long\n"
	.string "time.$"

FoxfireHollow_Mansion_1F_Text_RestByTheFire:
	.string "The fire is warm.\n"
	.string "Rest a while?$"

FoxfireHollow_Mansion_1F_Text_Rested:
	.string "{PLAYER} and the POKéMON rested by\n"
	.string "the fire.$"

FoxfireHollow_Mansion_1F_Text_ColdAsh:
	.string "Cold ash, long since blown into the\n"
	.string "corners.$"

@ The lodge's mirror, moved to the hall: she is no longer by the player, so the clue turned
@ round. She is in the glass and not in the hall.
FoxfireHollow_Mansion_1F_Text_Mirror:
	.string "{PLAYER} is in the mirror, and so is\n"
	.string "the hall behind.\p"
	.string "The woman is in it too, a few steps\n"
	.string "behind {PLAYER}.$"

FoxfireHollow_Mansion_1F_Text_NoOneThere:
	.string "There's no one there.$"

FoxfireHollow_Mansion_1F_Text_MirrorCracked:
	.string "The glass is cracked and grey with\n"
	.string "dust.$"

@ Was the portrait; a statue in the hall instead.
FoxfireHollow_Mansion_1F_Text_TravellerStatue:
	.string "A statue of a traveller, with a\n"
	.string "NINETALES curled at their feet.\p"
	.string "The stone has cracked with age.\p"
	.string "The traveller has {PLAYER}'s face.$"

FoxfireHollow_Mansion_1F_Text_TravellerStatueWorn:
	.string "The statue has worn almost\n"
	.string "smooth.\p"
	.string "A traveller, and a NINETALES at\n"
	.string "their feet.$"

FoxfireHollow_Mansion_1F_Text_TeaTray:
	.string "Tea, still steaming, and rice cakes\n"
	.string "on a lacquer tray.$"

FoxfireHollow_Mansion_1F_Text_TeaTrayLeaves:
	.string "A cracked lacquer tray, heaped with\n"
	.string "dry leaves.$"

FoxfireHollow_Mansion_1F_Text_RopedOff:
	.string "The stairs are roped off.$"
