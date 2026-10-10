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

DaoDaoIsles_Mansion_3F_EventScript_DiaryArgument::
	msgbox DaoDaoIsles_Mansion_3F_Text_DiaryArgument, MSGBOX_SIGN
	end

DaoDaoIsles_Mansion_3F_EventScript_Bram::
	trainerbattle_single TRAINER_DAODAO_MANSION_BRAM_HNS, DaoDaoIsles_Mansion_3F_Text_BramIntro, DaoDaoIsles_Mansion_3F_Text_BramDefeat
	msgbox DaoDaoIsles_Mansion_3F_Text_BramPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_3F_EventScript_Rhoda::
	trainerbattle_single TRAINER_DAODAO_MANSION_RHODA_HNS, DaoDaoIsles_Mansion_3F_Text_RhodaIntro, DaoDaoIsles_Mansion_3F_Text_RhodaDefeat
	msgbox DaoDaoIsles_Mansion_3F_Text_RhodaPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_3F_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end
DaoDaoIsles_Mansion_3F_EventScript_ItemIron::
	finditem ITEM_IRON
	end
@ One of GIDEON's four Drives (see 2F's Douse Drive).
DaoDaoIsles_Mansion_3F_EventScript_ItemShockDrive::
	finditem ITEM_SHOCK_DRIVE
	end

DaoDaoIsles_Mansion_3F_Text_BramIntro::
	.string "This place is, like, huge!$"

DaoDaoIsles_Mansion_3F_Text_BramDefeat::
	.string "Ayah!$"

DaoDaoIsles_Mansion_3F_Text_BramPostBattle::
	.string "I wonder where my partner went.$"

DaoDaoIsles_Mansion_3F_Text_RhodaIntro::
	.string "My mentor once lived here.$"

DaoDaoIsles_Mansion_3F_Text_RhodaDefeat::
	.string "Whew!\n"
	.string "Overwhelming!$"

DaoDaoIsles_Mansion_3F_Text_RhodaPostBattle::
	.string "So, you're stuck?\n"
	.string "Try jumping off over there!$"

DaoDaoIsles_Mansion_3F_Text_DiaryArgument::
	.string "A housekeeper's diary:\n"
	.string "They argued over dinner again.\p"
	.string "The Boss wants it finished.\n"
	.string "DR. GIDEON wants it right.$"
