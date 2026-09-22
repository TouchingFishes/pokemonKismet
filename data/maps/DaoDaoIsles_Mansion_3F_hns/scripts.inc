DaoDaoIsles_Mansion_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DaoDaoIsles_Mansion_3F_OnLoad
	.byte 0

DaoDaoIsles_Mansion_3F_OnLoad::
	call_if_set FLAG_DAODAO_MANSION_SWITCH_STATE, DaoDaoIsles_Mansion_EventScript_PressSwitch_3F
	end

DaoDaoIsles_Mansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call DaoDaoIsles_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

DaoDaoIsles_Mansion_3F_EventScript_DiaryFeb6th::
	msgbox DaoDaoIsles_Mansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

DaoDaoIsles_Mansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_MANSION_SIMON_HNS, DaoDaoIsles_Mansion_1F_Text_SimonIntro, DaoDaoIsles_Mansion_1F_Text_SimonDefeat
	msgbox DaoDaoIsles_Mansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_MANSION_BRAYDON_HNS, DaoDaoIsles_Mansion_1F_Text_BraydonIntro, DaoDaoIsles_Mansion_1F_Text_BraydonDefeat
	msgbox DaoDaoIsles_Mansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_1F_Text_SimonIntro::
	.string "This place is, like, huge!$"

DaoDaoIsles_Mansion_1F_Text_SimonDefeat::
	.string "Ayah!$"

DaoDaoIsles_Mansion_1F_Text_SimonPostBattle::
	.string "I wonder where my partner went.$"

DaoDaoIsles_Mansion_1F_Text_BraydonIntro::
	.string "My mentor once lived here.$"

DaoDaoIsles_Mansion_1F_Text_BraydonDefeat::
	.string "Whew!\n"
	.string "Overwhelming!$"

DaoDaoIsles_Mansion_1F_Text_BraydonPostBattle::
	.string "So, you're stuck?\n"
	.string "Try jumping off over there!$"

DaoDaoIsles_Mansion_1F_Text_MewGaveBirthToMewtwo::
	.string "Diary: Feb. 6\n"
	.string "MEW gave birth.\p"
	.string "We named the newborn MEWTWO.$"

DaoDaoIsles_Mansion_3F_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end
DaoDaoIsles_Mansion_3F_EventScript_ItemIron::
	finditem ITEM_IRON
	end
