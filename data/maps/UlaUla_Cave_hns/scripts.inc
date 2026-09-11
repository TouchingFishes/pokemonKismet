UlaUla_Cave_hns_MapScripts::
	.byte 0


Alola_Ulaula_BattleKlawf::
	lock
	faceplayer
	setflag FLAG_BATTLED_KLAWF
	playmoncry SPECIES_KLAWF, 0
	msgbox Alola_Ulaula_BattleKlawf_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_KLAWF, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Ulaula_BattleKlawf_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Ulaula_BattleKlawf_3
	release
	end

	release
	end

Alola_Ulaula_BattleKlawf_2:
	setflag FLAG_HIDE_KLAWF
	removeobject Alola_Ulaula_Klawf
	release
	end

Alola_Ulaula_BattleKlawf_3:
	setflag FLAG_HIDE_KLAWF
	removeobject Alola_Ulaula_Klawf
	release
	end


Alola_Ulaula_BattleMimikyu::
	lock
	faceplayer
	setflag FLAG_BATTLED_MIMIKYU
	playmoncry SPECIES_MIMIKYU, 0
	msgbox Alola_Ulaula_BattleKlawf_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_MIMIKYU, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Ulaula_BattleMimikyu_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Ulaula_BattleMimikyu_3
	release
	end

	release
	end

Alola_Ulaula_BattleMimikyu_2:
	setflag FLAG_HIDE_MIMIKYU
	removeobject Alola_Ulaula_Mimikyu
	release
	end

Alola_Ulaula_BattleMimikyu_3:
	setflag FLAG_HIDE_MIMIKYU
	removeobject Alola_Ulaula_Mimikyu
	release
	end


Alola_Ulaula_Cave_FindItem1::
	finditem ITEM_ICE_STONE, 1
	end


Alola_Ulaula_Cave_FindItem2::
	finditem ITEM_ADRENALINE_ORB, 1
	end


Alola_Ulaula_BattleKlawf_Text_0:
	.string "Graah!$"
