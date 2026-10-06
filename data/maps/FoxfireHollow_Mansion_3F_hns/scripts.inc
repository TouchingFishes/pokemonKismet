FoxfireHollow_Mansion_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FoxfireHollow_Mansion_3F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FoxfireHollow_Mansion_3F_OnTransition
	.byte 0

FoxfireHollow_Mansion_3F_OnTransition:
	call FoxfireHollow_Mansion_EventScript_Weather
	end

FoxfireHollow_Mansion_3F_OnLoad::
	call_if_set FLAG_FOXFIRE_MANSION_SWITCH_STATE, FoxfireHollow_Mansion_EventScript_PressSwitch_3F
	end

FoxfireHollow_Mansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call FoxfireHollow_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

FoxfireHollow_Mansion_3F_EventScript_DiaryOneSeason::
	msgbox FoxfireHollow_Mansion_3F_Text_DiaryOneSeason, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_MANSION_SIMON_HNS, FoxfireHollow_Mansion_1F_Text_SimonIntro, FoxfireHollow_Mansion_1F_Text_SimonDefeat
	msgbox FoxfireHollow_Mansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

FoxfireHollow_Mansion_3F_EventScript_Opal::
	trainerbattle_single TRAINER_MANSION_OPAL_HNS, FoxfireHollow_Mansion_3F_Text_OpalIntro, FoxfireHollow_Mansion_3F_Text_OpalDefeat
	msgbox FoxfireHollow_Mansion_3F_Text_OpalPostBattle, MSGBOX_AUTOCLOSE
	end

FoxfireHollow_Mansion_1F_Text_SimonIntro::
	.string "This place is, like, huge!$"

FoxfireHollow_Mansion_1F_Text_SimonDefeat::
	.string "Ayah!$"

FoxfireHollow_Mansion_1F_Text_SimonPostBattle::
	.string "I wonder where my partner went.$"

FoxfireHollow_Mansion_3F_Text_OpalIntro::
	.string "The spirits sent me up here.\n"
	.string "They wanted me out of the way.$"

FoxfireHollow_Mansion_3F_Text_OpalDefeat::
	.string "Whew!\n"
	.string "Overwhelming!$"

FoxfireHollow_Mansion_3F_Text_OpalPostBattle::
	.string "So, you're stuck?\n"
	.string "Try jumping off over there!$"

FoxfireHollow_Mansion_3F_Text_DiaryOneSeason::
	.string "A page from a diary:\p"
	.string "“There's work for me beyond the\n"
	.string "mountains. One season, no more.\p"
	.string "NINETALES can't come. Somebody\n"
	.string "has to keep the fire lit.”$"

FoxfireHollow_Mansion_3F_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION
	end
FoxfireHollow_Mansion_3F_EventScript_ItemIron::
	finditem ITEM_IRON
	end
