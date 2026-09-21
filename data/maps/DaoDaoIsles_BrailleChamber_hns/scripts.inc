@ The braille wall at the back tells the player what is wanted: tablets run
@ along y = 4 from x = 5 to x = 13, all sharing one script. Using WATERFALL from
@ the party menu while standing in front of ANY of them wakes the five golems.
DaoDaoIsles_BrailleChamber_hns_MapScripts::
	.byte 0

DaoDaoIsles_BrailleChamber_EventScript_Tablet::
	lockall
	braillemsgbox DaoDaoIsles_BrailleChamber_Braille_Riddle
	goto_if_set FLAG_DAODAO_REGIS_ENABLED, DaoDaoIsles_BrailleChamber_EventScript_AlreadyWoken
	msgbox DaoDaoIsles_BrailleChamber_Text_Dry, MSGBOX_DEFAULT
	releaseall
	end

DaoDaoIsles_BrailleChamber_EventScript_AlreadyWoken::
	msgbox DaoDaoIsles_BrailleChamber_Text_Woken, MSGBOX_DEFAULT
	releaseall
	end

DaoDaoIsles_BrailleChamber_Braille_Riddle:
	brailleformat 4, 6, 26, 13, 7, 9
	.braille "USE WATERFALL.$"

DaoDaoIsles_BrailleChamber_Text_Dry:
	.string "The floor of the chamber is dry\n"
	.string "and cut with old channels.\p"
	.string "They all run upward.$"

DaoDaoIsles_BrailleChamber_Text_Woken:
	.string "Water still runs up the channels\n"
	.string "and out through the walls.\p"
	.string "Somewhere out there, five things\n"
	.string "are awake.$"
