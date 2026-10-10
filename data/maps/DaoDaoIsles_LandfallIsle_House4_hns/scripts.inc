DaoDaoIsles_LandfallIsle_House4_hns_MapScripts::
	.byte 0

@ -----------------------------------------------------------------------------------------
@ Moved from Melemele_House_4_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_LandfallIsle_House4_Man::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_House4_Woman::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_House4_Man_Text_0:
	.string "We're vacationing on the DAODAO ISLES!\p"
	.string "It's just like the DAODAO region,\n"
	.string "but closer to KANTO!\p"
	.string "I saved so much on travel expenses!$"

DaoDaoIsles_LandfallIsle_House4_Woman_Text_0:
	.string "My boyfriend told me we were going to\n"
	.string "DAODAO…\p"
	.string "I had assumed it would be the DAODAO\n"
	.string "region, not the small isles off the\l"
	.string "coast of KANTO.$"
