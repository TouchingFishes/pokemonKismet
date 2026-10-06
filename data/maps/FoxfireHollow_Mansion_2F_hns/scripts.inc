FoxfireHollow_Mansion_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FoxfireHollow_Mansion_2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FoxfireHollow_Mansion_2F_OnTransition
	.byte 0

FoxfireHollow_Mansion_2F_OnTransition:
	call FoxfireHollow_Mansion_EventScript_Weather
	end

FoxfireHollow_Mansion_2F_OnLoad::
	call_if_set FLAG_FOXFIRE_MANSION_SWITCH_STATE, FoxfireHollow_Mansion_EventScript_PressSwitch_2F
	end

FoxfireHollow_Mansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call FoxfireHollow_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

FoxfireHollow_Mansion_2F_EventScript_DiaryNinetails::
	msgbox FoxfireHollow_Mansion_2F_Text_DiaryNinetails, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_2F_EventScript_DiaryTheCook::
	msgbox FoxfireHollow_Mansion_2F_Text_DiaryTheCook, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_MANSION_ARNIE_HNS, FoxfireHollow_Mansion_1F_Text_ArnieIntro, FoxfireHollow_Mansion_1F_Text_ArnieDefeat
	msgbox FoxfireHollow_Mansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

FoxfireHollow_Mansion_Text_PressSecretSwitch::
	.string "A secret switch!\p"
	.string "Press it?$"

FoxfireHollow_Mansion_Text_WhoWouldnt::
	.string "Who wouldn't?$"

FoxfireHollow_Mansion_Text_NotQuiteYet::
	.string "Not quite yet!$"

FoxfireHollow_Mansion_1F_Text_ArnieIntro::
	.string "I can't get out!\n"
	.string "This old place is one big puzzle.$"

FoxfireHollow_Mansion_1F_Text_ArnieDefeat::
	.string "Oh, no!\n"
	.string "My bag of loot!$"

FoxfireHollow_Mansion_1F_Text_ArniePostBattle::
	.string "The switches here open and close\n"
	.string "alternating sets of doors.$"

FoxfireHollow_Mansion_2F_Text_DiaryNinetails::
	.string "A page from a diary:\p"
	.string "“The VULPIX became a NINETALES\n"
	.string "today. It still sleeps at my feet\l"
	.string "by the fire, every night.”$"

FoxfireHollow_Mansion_2F_Text_DiaryTheCook::
	.string "A page from a diary:\p"
	.string "“The cook has gone down to the\n"
	.string "village for good. Only the two\l"
	.string "of us now, and the fire.”$"

FoxfireHollow_Mansion_2F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM
	end
FoxfireHollow_Mansion_2F_EventScript_ItemZinc::
	finditem ITEM_ZINC
	end
FoxfireHollow_Mansion_2F_EventScript_ItemHPUp::
	finditem ITEM_HP_UP
	end
