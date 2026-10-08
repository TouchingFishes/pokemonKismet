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

DaoDaoIsles_Mansion_2F_EventScript_DiaryHouse::
	msgbox DaoDaoIsles_Mansion_2F_Text_DiaryHouse, MSGBOX_SIGN
	end

DaoDaoIsles_Mansion_2F_EventScript_DiaryHumming::
	msgbox DaoDaoIsles_Mansion_2F_Text_DiaryHumming, MSGBOX_SIGN
	end

DaoDaoIsles_Mansion_2F_EventScript_Griffin::
	trainerbattle_single TRAINER_DAODAO_MANSION_GRIFFIN_HNS, DaoDaoIsles_Mansion_2F_Text_GriffinIntro, DaoDaoIsles_Mansion_2F_Text_GriffinDefeat
	msgbox DaoDaoIsles_Mansion_2F_Text_GriffinPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_2F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM
	end
DaoDaoIsles_Mansion_2F_EventScript_ItemZinc::
	finditem ITEM_ZINC
	end
DaoDaoIsles_Mansion_2F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP
	end

DaoDaoIsles_Mansion_Text_PressSecretSwitch::
	.string "A secret switch!\p"
	.string "Press it?$"

DaoDaoIsles_Mansion_Text_WhoWouldnt::
	.string "Who wouldn't?$"

DaoDaoIsles_Mansion_Text_NotQuiteYet::
	.string "Not quite yet!$"

DaoDaoIsles_Mansion_2F_Text_GriffinIntro::
	.string "I can't get out!\n"
	.string "This old place is one big puzzle.$"

DaoDaoIsles_Mansion_2F_Text_GriffinDefeat::
	.string "Oh, no!\n"
	.string "My bag of loot!$"

DaoDaoIsles_Mansion_2F_Text_GriffinPostBattle::
	.string "The switches here open and close\n"
	.string "alternating sets of doors.$"

DaoDaoIsles_Mansion_2F_Text_DiaryHouse::
	.string "A housekeeper's diary:\n"
	.string "The Boss bought the house for\l"
	.string "the quiet, he says.\p"
	.string "DR. GIDEON took the basement before\n"
	.string "the movers had even left.$"

DaoDaoIsles_Mansion_2F_Text_DiaryHumming::
	.string "A housekeeper's diary:\n"
	.string "The humming from the basement went\l"
	.string "on all night again.\p"
	.string "I wonder what they are doing down\n"
	.string "there.$"
