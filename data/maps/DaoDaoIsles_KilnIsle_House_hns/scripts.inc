DaoDaoIsles_KilnIsle_House_hns_MapScripts::
	.byte 0

@ -----------------------------------------------------------------------------------------
@ Moved from Akala_House_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_KilnIsle_House_OldWoman::
	lock
	faceplayer
	msgbox DaoDaoIsles_KilnIsle_House_OldWoman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_KilnIsle_House_OldWoman_Text_0:
	.string "I tell my husband everyday not to feed\n"
	.string "the NATU, but he never listens!\p"
	.string "One day he'll bring one of those darn\n"
	.string "things home, I just know it!$"
