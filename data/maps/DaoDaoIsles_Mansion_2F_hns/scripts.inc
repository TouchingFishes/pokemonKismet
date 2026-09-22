DaoDaoIsles_Mansion_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DaoDaoIsles_Mansion_2F_OnLoad
	.byte 0

DaoDaoIsles_Mansion_2F_OnLoad::
	call_if_set FLAG_DAODAO_MANSION_SWITCH_STATE, DaoDaoIsles_Mansion_EventScript_PressSwitch_2F
	end

DaoDaoIsles_Mansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call DaoDaoIsles_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

DaoDaoIsles_Mansion_2F_EventScript_DiaryJuly5th::
	msgbox DaoDaoIsles_Mansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

DaoDaoIsles_Mansion_2F_EventScript_DiaryJuly10th::
	msgbox DaoDaoIsles_Mansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

DaoDaoIsles_Mansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_MANSION_ARNIE_HNS, DaoDaoIsles_Mansion_1F_Text_ArnieIntro, DaoDaoIsles_Mansion_1F_Text_ArnieDefeat
	msgbox DaoDaoIsles_Mansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_Text_PressSecretSwitch::
	.string "A secret switch!\p"
	.string "Press it?$"

DaoDaoIsles_Mansion_Text_WhoWouldnt::
	.string "Who wouldn't?$"

DaoDaoIsles_Mansion_Text_NotQuiteYet::
	.string "Not quite yet!$"

DaoDaoIsles_Mansion_1F_Text_ArnieIntro::
	.string "I can't get out!\n"
	.string "This old place is one big puzzle.$"

DaoDaoIsles_Mansion_1F_Text_ArnieDefeat::
	.string "Oh, no!\n"
	.string "My bag of loot!$"

DaoDaoIsles_Mansion_1F_Text_ArniePostBattle::
	.string "The switches here open and close\n"
	.string "alternating sets of doors.$"

DaoDaoIsles_Mansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
	.string "Diary: July 5\n"
	.string "Guyana, South America\p"
	.string "A new POKéMON was discovered deep\n"
	.string "in the jungle.$"

DaoDaoIsles_Mansion_1F_Text_ChristenedDiscoveredMonMew::
	.string "Diary: July 10\n"
	.string "We christened the newly discovered\l"
	.string "POKéMON, MEW.$"

DaoDaoIsles_Mansion_2F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM
	end
DaoDaoIsles_Mansion_2F_EventScript_ItemZinc::
	finditem ITEM_ZINC
	end
DaoDaoIsles_Mansion_2F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP
	end
