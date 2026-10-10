DaoDaoIsles_LandfallIsle_PokeMart_hns_MapScripts::
	.byte 0

@ -----------------------------------------------------------------------------------------
@ Moved from Melemele_House_2_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_LandfallIsle_PokeMart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart DaoDaoIsles_LandfallIsle_PokeMart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end


	.align 2
DaoDaoIsles_LandfallIsle_PokeMart_Pokemart:
	.2byte ITEM_BIG_MALASADA
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_WAVE_INCENSE
	.2byte ITEM_LEMONADE
	.2byte ITEM_NONE

DaoDaoIsles_LandfallIsle_PokeMart_Cook::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_PokeMart_Cook_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_PokeMart_BaldMan::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_PokeMart_BaldMan_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_PokeMart_Cook_Text_0:
	.string "The MALASADAS here are delicious.\n"
	.string "Just like the real ones in DAODAO!$"

DaoDaoIsles_LandfallIsle_PokeMart_BaldMan_Text_0:
	.string "I'm looking for some sunscreen!\p"
	.string "It's sunnier here on the ISLES!$"
