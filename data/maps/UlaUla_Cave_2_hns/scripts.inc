UlaUla_Cave_2_hns_MapScripts::
	.byte 0


Alola_Ulaula_BattleDrapion::
	lock
	faceplayer
	setflag FLAG_BATTLED_DRAPION
	playmoncry SPECIES_DRAPION, 0
	msgbox Alola_Ulaula_BattleDrapion_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_DRAPION, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Ulaula_BattleDrapion_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Ulaula_BattleDrapion_3
	release
	end

	release
	end

Alola_Ulaula_BattleDrapion_2:
	setflag FLAG_HIDE_DRAPION
	removeobject Alola_Ulaula_Drapion
	release
	end

Alola_Ulaula_BattleDrapion_3:
	setflag FLAG_HIDE_DRAPION
	removeobject Alola_Ulaula_Drapion
	release
	end


Alola_Ulaula_BattleDrapion_Text_0:
	.string "Gaaah!$"
