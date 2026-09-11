Akala_Cave_hns_MapScripts::
	.byte 0


Alola_Akala_BattleKrookodile::
	lock
	faceplayer
	setflag FLAG_BATTLED_KROOKODILE
	playmoncry SPECIES_KROOKODILE, 0
	msgbox Alola_Akala_BattleKrookodile_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_KROOKODILE, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Akala_BattleKrookodile_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Akala_BattleKrookodile_3
	release
	end

	release
	end

Alola_Akala_BattleKrookodile_2:
	setflag FLAG_HIDE_KROOKODILE
	removeobject Alola_Akala_Krookodile
	release
	end

Alola_Akala_BattleKrookodile_3:
	setflag FLAG_HIDE_KROOKODILE
	removeobject Alola_Akala_Krookodile
	release
	end


Alola_Akala_BattleCamerupt::
	lock
	faceplayer
	setflag FLAG_BATTLED_CAMERUPT
	playmoncry SPECIES_CAMERUPT, 0
	msgbox Alola_Akala_BattleCamerupt_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_CAMERUPT, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Akala_BattleCamerupt_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Akala_BattleCamerupt_3
	release
	end

	release
	end

Alola_Akala_BattleCamerupt_2:
	setflag FLAG_HIDE_CAMERUPT
	removeobject Alola_Akala_Camerupt
	release
	end

Alola_Akala_BattleCamerupt_3:
	setflag FLAG_HIDE_CAMERUPT
	removeobject Alola_Akala_Camerupt
	release
	end


Alola_Akala_Cave_FindItem1::
	finditem ITEM_CARBOS, 1
	end


Alola_Akala_Cave_FindItem2::
	finditem ITEM_HP_UP, 1
	end


Alola_AkalaCave_TrainerBattleHiker::
	trainerbattle_single TRAINER_AKALA_CAVE_HIKER_HNS, Alola_AkalaCave_TrainerBattleHiker_Text_0, Alola_AkalaCave_TrainerBattleHiker_Text_1
	msgbox Alola_AkalaCave_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_AkalaCave_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_AKALA_CAVE_PICNICKER_HNS, Alola_AkalaCave_TrainerBattlePicnicker_Text_0, Alola_AkalaCave_TrainerBattlePicnicker_Text_1
	msgbox Alola_AkalaCave_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_AkalaCave_TrainerBattleCamper::
	trainerbattle_single TRAINER_AKALA_CAVE_CAMPER_HNS, Alola_AkalaCave_TrainerBattleCamper_Text_0, Alola_AkalaCave_TrainerBattleCamper_Text_1
	msgbox Alola_AkalaCave_TrainerBattleCamper_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_Akala_BattleKrookodile_Text_0:
	.string "Raah!$"

Alola_Akala_BattleCamerupt_Text_0:
	.string "Cha-Cha!$"

Alola_AkalaCave_TrainerBattleHiker_Text_0:
	.string "You must be tough if you made it all the\nway up here!$"

Alola_AkalaCave_TrainerBattleHiker_Text_1:
	.string "Tougher than me!$"

Alola_AkalaCave_TrainerBattleHiker_Text_2:
	.string "I had to stop climbing because it was\n"
	.string "getting far too hot.\p"
	.string "It's like someone's got a fire going\n"
	.string "up on the peak…$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_0:
	.string "I'm tired from all this walking,\nlet's have a battle!$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_1:
	.string "Well that was refreshing!$"

Alola_AkalaCave_TrainerBattlePicnicker_Text_2:
	.string "I'm usually not this tired but\n"
	.string "the heat in this cave is exhausting!$"

Alola_AkalaCave_TrainerBattleCamper_Text_0:
	.string "Check me out!\nI caught some strong POKéMON!$"

Alola_AkalaCave_TrainerBattleCamper_Text_1:
	.string "Not bad,\nbut not good enough!$"

Alola_AkalaCave_TrainerBattleCamper_Text_2:
	.string "Is it warm in here or is it just me?$"
