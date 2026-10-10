DaoDaoIsles_LandfallIsle_House3_hns_MapScripts::
	.byte 0

@ -----------------------------------------------------------------------------------------
@ Moved from Melemele_House_3_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_LandfallIsle_House3_Woman::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_House3_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_House3_Man::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_House3_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_House3_Woman_Text_0:
	.string "Island life here is so peaceful!\p"
	.string "And it's nice that my grandkids are just\n"
	.string "a quick boat ride away in KANTO!$"

DaoDaoIsles_LandfallIsle_House3_Man_Text_0:
	.string "Dang tourists!\p"
	.string "My realtor said this place would be\n"
	.string "quiet… but I guess its cheaper to \l"
	.string "travel here than all the way to DAODAO.$"
