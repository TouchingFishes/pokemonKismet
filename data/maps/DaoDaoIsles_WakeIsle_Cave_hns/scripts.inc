DaoDaoIsles_WakeIsle_Cave_hns_MapScripts::
	.byte 0

@ -----------------------------------------------------------------------------------------
@ Moved from Poni_Cave_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_WakeIsle_Cave_BattleProbopass::
	lock
	faceplayer
	setflag FLAG_BATTLED_PROBOPASS
	playmoncry SPECIES_PROBOPASS, 0
	msgbox DaoDaoIsles_WakeIsle_Cave_BattleProbopass_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbossbattle species=SPECIES_PROBOPASS, level=60, move1_1=MOVE_DISCHARGE, move1_2=MOVE_ROCK_BLAST, move1_3=MOVE_THUNDER_PUNCH, move1_4=MOVE_STEALTH_ROCK
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DaoDaoIsles_WakeIsle_Cave_BattleProbopass_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_WakeIsle_Cave_BattleProbopass_3
	release
	end

	release
	end

DaoDaoIsles_WakeIsle_Cave_BattleProbopass_2:
	setflag FLAG_HIDE_PROBOPASS
	removeobject LOCALID_DAODAO_WAKE_CAVE_PROBOPASS
	release
	end

DaoDaoIsles_WakeIsle_Cave_BattleProbopass_3:
	setflag FLAG_HIDE_PROBOPASS
	removeobject LOCALID_DAODAO_WAKE_CAVE_PROBOPASS
	release
	end


DaoDaoIsles_WakeIsle_Cave_FindItem1::
	finditem ITEM_LEAF_STONE, 1
	end


DaoDaoIsles_WakeIsle_Cave_FindItem2::
	finditem ITEM_THUNDER_STONE, 1
	end


DaoDaoIsles_WakeIsle_Cave_BattleProbopass_Text_0:
	.string "Gaaah!$"
