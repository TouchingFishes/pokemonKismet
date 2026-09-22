DaoDaoIsles_Mansion_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DaoDaoIsles_Mansion_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_Mansion_1F_OnTransition
	.byte 0

DaoDaoIsles_Mansion_1F_OnLoad::
	call_if_set FLAG_DAODAO_MANSION_SWITCH_STATE, DaoDaoIsles_Mansion_EventScript_PressSwitch_1F
	end

DaoDaoIsles_Mansion_1F_OnTransition::
	end

DaoDaoIsles_Mansion_1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 0
	call DaoDaoIsles_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

DaoDaoIsles_Mansion_1F_EventScript_Ted::
	trainerbattle_single TRAINER_MANSION_TED_HNS, DaoDaoIsles_Mansion_1F_Text_TedIntro, DaoDaoIsles_Mansion_1F_Text_TedDefeat
	msgbox DaoDaoIsles_Mansion_1F_Text_TedPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_1F_EventScript_Johnson::
	trainerbattle_single TRAINER_MANSION_JOHNSON_HNS, DaoDaoIsles_Mansion_1F_Text_JohnsonIntro, DaoDaoIsles_Mansion_1F_Text_JohnsonDefeat
	msgbox DaoDaoIsles_Mansion_1F_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_1F_Text_TedIntro::
	.string "Who are you?\n"
	.string "There shouldn't be anyone here.$"

DaoDaoIsles_Mansion_1F_Text_TedDefeat::
	.string "Ouch!$"

DaoDaoIsles_Mansion_1F_Text_TedPostBattle::
	.string "A key? I don't know what you're\n"
	.string "talking about.$"

DaoDaoIsles_Mansion_1F_Text_JohnsonIntro::
	.string "W-w-waah! You startled me!\n"
	.string "I thought you were a ghost.$"

DaoDaoIsles_Mansion_1F_Text_JohnsonDefeat::
	.string "Tch!\n"
	.string "I can't get any wins.$"

DaoDaoIsles_Mansion_1F_Text_JohnsonPostBattle::
	.string "I was exploring here by myself,\n"
	.string "but I feel spooked.\p"
	.string "I ought to go soon.$"

DaoDaoIsles_Mansion_1F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end
DaoDaoIsles_Mansion_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end
DaoDaoIsles_Mansion_1F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end

DaoDaoIsles_Mansion_EventScript_SecretSwitch::
	msgbox DaoDaoIsles_Mansion_Text_PressSecretSwitch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_Mansion_EventScript_DontPressSwitch
	msgbox DaoDaoIsles_Mansion_Text_WhoWouldnt
	goto_if_set FLAG_DAODAO_MANSION_SWITCH_STATE, DaoDaoIsles_Mansion_EventScript_ResetSwitch
	setflag FLAG_DAODAO_MANSION_SWITCH_STATE
	switch VAR_0x8004
	case 0, DaoDaoIsles_Mansion_EventScript_PressSwitch_1F
	case 1, DaoDaoIsles_Mansion_EventScript_PressSwitch_2F
	case 2, DaoDaoIsles_Mansion_EventScript_PressSwitch_3F
	case 3, DaoDaoIsles_Mansion_EventScript_PressSwitch_B1F
	end

DaoDaoIsles_Mansion_EventScript_ResetSwitch::
	clearflag FLAG_DAODAO_MANSION_SWITCH_STATE
	switch VAR_0x8004
	case 0, DaoDaoIsles_Mansion_EventScript_ResetSwitch_1F
	case 1, DaoDaoIsles_Mansion_EventScript_ResetSwitch_2F
	case 2, DaoDaoIsles_Mansion_EventScript_ResetSwitch_3F
	case 3, DaoDaoIsles_Mansion_EventScript_ResetSwitch_B1F
	end

DaoDaoIsles_Mansion_EventScript_DontPressSwitch::
	msgbox DaoDaoIsles_Mansion_Text_NotQuiteYet
	releaseall
	end

DaoDaoIsles_Mansion_EventScript_PressSwitch_1F::
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

DaoDaoIsles_Mansion_EventScript_ResetSwitch_1F::
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

DaoDaoIsles_Mansion_EventScript_PressSwitch_2F::
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

DaoDaoIsles_Mansion_EventScript_ResetSwitch_2F::
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

DaoDaoIsles_Mansion_EventScript_PressSwitch_3F::
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

DaoDaoIsles_Mansion_EventScript_ResetSwitch_3F::
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

DaoDaoIsles_Mansion_EventScript_PressSwitch_B1F::
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

DaoDaoIsles_Mansion_EventScript_ResetSwitch_B1F::
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
