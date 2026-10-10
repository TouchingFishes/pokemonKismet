DaoDaoIsles_ScoriaCave_hns_MapScripts::
	.byte 0

DaoDaoIsles_ScoriaCave_EventScript_Salazzle::
	lock
	faceplayer
	playmoncry SPECIES_SALAZZLE, CRY_MODE_NORMAL
	msgbox DaoDaoIsles_ScoriaCave_Text_Salazzle, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	setwildbattle SPECIES_SALAZZLE, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_ScoriaCave_EventScript_SalazzleStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a win.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_ScoriaCave_EventScript_SalazzleStays
	setflag FLAG_HIDE_DAODAO_SCORIA_CAVE_SALAZZLE
	removeobject LOCALID_DAODAO_SCORIA_CAVE_SALAZZLE
DaoDaoIsles_ScoriaCave_EventScript_SalazzleStays::
	release
	end

DaoDaoIsles_ScoriaCave_Text_Salazzle:
	.string "Sssshaaa!$"

@ -----------------------------------------------------------------------------------------
@ Moved from Akala_Cave_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_ScoriaCave_BattleCamerupt::
	lock
	faceplayer
	setflag FLAG_BATTLED_CAMERUPT
	playmoncry SPECIES_CAMERUPT, 0
	msgbox DaoDaoIsles_ScoriaCave_BattleCamerupt_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_CAMERUPT, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DaoDaoIsles_ScoriaCave_BattleCamerupt_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_ScoriaCave_BattleCamerupt_3
	release
	end

	release
	end

DaoDaoIsles_ScoriaCave_BattleCamerupt_2:
	setflag FLAG_HIDE_CAMERUPT
	removeobject LOCALID_DAODAO_SCORIA_CAVE_CAMERUPT
	release
	end

DaoDaoIsles_ScoriaCave_BattleCamerupt_3:
	setflag FLAG_HIDE_CAMERUPT
	removeobject LOCALID_DAODAO_SCORIA_CAVE_CAMERUPT
	release
	end


DaoDaoIsles_ScoriaCave_FindItem1::
	finditem ITEM_CARBOS, 1
	end


DaoDaoIsles_ScoriaCave_FindItem2::
	finditem ITEM_HP_UP, 1
	end


DaoDaoIsles_ScoriaCave_TrainerBattleHiker::
	trainerbattle_single TRAINER_DAODAO_SCORIA_CAVE_HIKER_HNS, DaoDaoIsles_ScoriaCave_TrainerBattleHiker_Text_0, DaoDaoIsles_ScoriaCave_TrainerBattleHiker_Text_1
	msgbox DaoDaoIsles_ScoriaCave_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_ScoriaCave_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_DAODAO_SCORIA_CAVE_PICNICKER_HNS, DaoDaoIsles_ScoriaCave_TrainerBattlePicnicker_Text_0, DaoDaoIsles_ScoriaCave_TrainerBattlePicnicker_Text_1
	msgbox DaoDaoIsles_ScoriaCave_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_ScoriaCave_TrainerBattleCamper::
	trainerbattle_single TRAINER_DAODAO_SCORIA_CAVE_CAMPER_HNS, DaoDaoIsles_ScoriaCave_TrainerBattleCamper_Text_0, DaoDaoIsles_ScoriaCave_TrainerBattleCamper_Text_1
	msgbox DaoDaoIsles_ScoriaCave_TrainerBattleCamper_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_ScoriaCave_BattleCamerupt_Text_0:
	.string "Cha-Cha!$"

DaoDaoIsles_ScoriaCave_TrainerBattleHiker_Text_0:
	.string "You must be tough if you made it all the\nway up here!$"

DaoDaoIsles_ScoriaCave_TrainerBattleHiker_Text_1:
	.string "Tougher than me!$"

DaoDaoIsles_ScoriaCave_TrainerBattleHiker_Text_2:
	.string "I had to stop climbing because it was\n"
	.string "getting far too hot.\p"
	.string "It's like someone's got a fire going\n"
	.string "up on the peak…$"

DaoDaoIsles_ScoriaCave_TrainerBattlePicnicker_Text_0:
	.string "I'm tired from all this walking,\nlet's have a battle!$"

DaoDaoIsles_ScoriaCave_TrainerBattlePicnicker_Text_1:
	.string "Well that was refreshing!$"

DaoDaoIsles_ScoriaCave_TrainerBattlePicnicker_Text_2:
	.string "I'm usually not this tired but\n"
	.string "the heat in this cave is exhausting!$"

DaoDaoIsles_ScoriaCave_TrainerBattleCamper_Text_0:
	.string "Check me out!\nI caught some strong POKéMON!$"

DaoDaoIsles_ScoriaCave_TrainerBattleCamper_Text_1:
	.string "Not bad,\nbut not good enough!$"

DaoDaoIsles_ScoriaCave_TrainerBattleCamper_Text_2:
	.string "Is it warm in here or is it just me?$"
