DaoDaoIsles_Mansion_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DaoDaoIsles_Mansion_B1F_OnLoad
	.byte 0

DaoDaoIsles_Mansion_B1F_OnLoad::
	call_if_set FLAG_DAODAO_MANSION_SWITCH_STATE, DaoDaoIsles_Mansion_EventScript_PressSwitch_B1F
	end

DaoDaoIsles_Mansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call DaoDaoIsles_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

DaoDaoIsles_Mansion_B1F_EventScript_DiarySep1st::
	msgbox DaoDaoIsles_Mansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end

DaoDaoIsles_Mansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_MANSION_LEWIS_HNS, DaoDaoIsles_Mansion_B1F_Text_LewisIntro, DaoDaoIsles_Mansion_B1F_Text_LewisDefeat
	msgbox DaoDaoIsles_Mansion_B1F_Text_LewisPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_MANSION_IVAN_HNS, DaoDaoIsles_Mansion_B1F_Text_IvanIntro, DaoDaoIsles_Mansion_B1F_Text_IvanDefeat
	msgbox DaoDaoIsles_Mansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_B1F_Text_LewisIntro::
	.string "Uh-oh…\n"
	.string "Where am I now?$"

DaoDaoIsles_Mansion_B1F_Text_LewisDefeat::
	.string "Awooh!$"

DaoDaoIsles_Mansion_B1F_Text_LewisPostBattle::
	.string "You can find stuff lying around.\n"
	.string "The residents must've left them.$"

DaoDaoIsles_Mansion_B1F_Text_IvanIntro::
	.string "This place is ideal for a lab.\n"
	.string "Look at all this space.$"

DaoDaoIsles_Mansion_B1F_Text_IvanDefeat::
	.string "What was that for?$"

DaoDaoIsles_Mansion_B1F_Text_IvanPostBattle::
	.string "I like it here.\n"
	.string "It's conducive to my studies.$"

DaoDaoIsles_Mansion_B1F_Text_MewtwoIsFarTooPowerful::
	.string "Diary: Sept. 1\n"
	.string "MEWTWO is far too powerful.\p"
	.string "We have failed to curb its vicious\n"
	.string "tendencies…$"

DaoDaoIsles_Mansion_B1F_EventScript_ItemTM14::
	finditem ITEM_TM14
	end
DaoDaoIsles_Mansion_B1F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end
DaoDaoIsles_Mansion_B1F_EventScript_ItemTM22::
	finditem ITEM_TM22
	end
DaoDaoIsles_Mansion_B1F_EventScript_ItemSecretKey::
	finditem ITEM_SECRET_KEY
	end
