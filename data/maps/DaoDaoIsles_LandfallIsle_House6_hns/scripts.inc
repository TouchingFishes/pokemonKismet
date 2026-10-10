DaoDaoIsles_LandfallIsle_House6_hns_MapScripts::
	.byte 0

@ -----------------------------------------------------------------------------------------
@ Moved from Melemele_House_6_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_LandfallIsle_House6_Hiker::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_House6_Hiker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_House6_GameboyKid::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_House6_GameboyKid_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_House6_Hiker_Text_0:
	.string "I bought this place so that my son\n"
	.string "and I could explore the outdoors…\p"
	.string "All he wants to do is play on that\n"
	.string "Game Boy Advance.$"

DaoDaoIsles_LandfallIsle_House6_GameboyKid_Text_0:
	.string "I have a game on my Game Boy Advance\n"
	.string "that lets me explore the DAODAO Region!\p"
	.string "It's just like the real thing.\p"
	.string "It's called ULTRA ECLIPSE,\n"
	.string "by PHANTONOMY!\p"
	.string "Haha, look!\n"
	.string "I'm riding an icy NOIVERN!$"
