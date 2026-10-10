DaoDaoIsles_LandfallIsle_House5_hns_MapScripts::
	.byte 0

@ -----------------------------------------------------------------------------------------
@ Moved from Melemele_House_5_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_LandfallIsle_House5_Mom::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_House5_Mom_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_LandfallIsle_House5_Son::
	lock
	faceplayer
	msgbox DaoDaoIsles_LandfallIsle_House5_Son_Text_0
	applymovement LOCALID_DAODAO_LANDFALL_ELIO DaoDaoIsles_LandfallIsle_House5_Son_Movement
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement
	msgbox DaoDaoIsles_LandfallIsle_House5_Son_Text_1, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_MEOWTH, 0
	waitmoncry
	release
	end


DaoDaoIsles_LandfallIsle_House5_Cat::
	lock
	faceplayer
	playmoncry SPECIES_MEOWTH, 0
	msgbox DaoDaoIsles_LandfallIsle_House5_Cat_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end

DaoDaoIsles_LandfallIsle_House5_Son_Movement:
	jump_in_place_down
	jump_in_place_down
	step_end

DaoDaoIsles_LandfallIsle_House5_Mom_Text_0:
	.string "I'm thinking of moving to the DAODAO\n"
	.string "region with my son, ELIO.\p"
	.string "We're just getting a little taste here\n"
	.string "on the ISLES!$"

DaoDaoIsles_LandfallIsle_House5_Son_Text_0:
	.string "Hehe... tag is so fun!$"

DaoDaoIsles_LandfallIsle_House5_Son_Text_1:
	.string "Try to catch me MEOWTH!$"

DaoDaoIsles_LandfallIsle_House5_Cat_Text_0:
	.string "Mwaaawwwrrrrrrrr!!!$"
