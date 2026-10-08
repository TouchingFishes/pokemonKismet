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

DaoDaoIsles_Mansion_B1F_EventScript_GideonNotes::
	msgbox DaoDaoIsles_Mansion_B1F_Text_GideonNotes, MSGBOX_SIGN
	end

DaoDaoIsles_Mansion_B1F_EventScript_Wren::
	trainerbattle_single TRAINER_DAODAO_MANSION_WREN_HNS, DaoDaoIsles_Mansion_B1F_Text_WrenIntro, DaoDaoIsles_Mansion_B1F_Text_WrenDefeat
	msgbox DaoDaoIsles_Mansion_B1F_Text_WrenPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_B1F_EventScript_Marcus::
	trainerbattle_single TRAINER_DAODAO_MANSION_MARCUS_HNS, DaoDaoIsles_Mansion_B1F_Text_MarcusIntro, DaoDaoIsles_Mansion_B1F_Text_MarcusDefeat
	msgbox DaoDaoIsles_Mansion_B1F_Text_MarcusPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_B1F_EventScript_ItemTM14::
	finditem ITEM_TM14
	end
DaoDaoIsles_Mansion_B1F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end
DaoDaoIsles_Mansion_B1F_EventScript_ItemTM22::
	finditem ITEM_TM22
	end

DaoDaoIsles_Mansion_B1F_EventScript_ItemBurnDrive::
	finditem ITEM_BURN_DRIVE
	end

DaoDaoIsles_Mansion_B1F_Text_WrenIntro::
	.string "Uh-oh…\n"
	.string "Where am I now?$"

DaoDaoIsles_Mansion_B1F_Text_WrenDefeat::
	.string "Awooh!$"

DaoDaoIsles_Mansion_B1F_Text_WrenPostBattle::
	.string "You can find stuff lying around.\n"
	.string "The residents must've left them.$"

DaoDaoIsles_Mansion_B1F_Text_MarcusIntro::
	.string "This place is ideal for a lab.\n"
	.string "Look at all this space.$"

DaoDaoIsles_Mansion_B1F_Text_MarcusDefeat::
	.string "What was that for?$"

DaoDaoIsles_Mansion_B1F_Text_MarcusPostBattle::
	.string "I like it here.\n"
	.string "It's conducive to my studies.$"

DaoDaoIsles_Mansion_B1F_Text_GideonNotes::
	.string "Notes, in a cramped hand:\p"
	.string "The fossil's carapace will take a\n"
	.string "cannon mount.\p"
	.string "The gears from the ruin turn it.\n"
	.string "I cannot yet say why.\p"
	.string "A design is not a weapon until\n"
	.string "somebody pays for it. - G.$"
