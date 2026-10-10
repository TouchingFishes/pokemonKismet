DaoDaoIsles_EternaForest_hns_MapScripts::
	.byte 0

DaoDaoIsles_EternaForest_EventScript_Youngster::
	lock
	faceplayer
	goto_if_eq VAR_DOLL_SHRINE_STATE, 3, DaoDaoIsles_EternaForest_EventScript_YoungsterYouWentIn
	goto_if_ne VAR_DOLL_SHRINE_STATE, 0, DaoDaoIsles_EternaForest_EventScript_YoungsterQuiet
	msgbox DaoDaoIsles_EternaForest_Text_YoungsterDare, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_EternaForest_EventScript_YoungsterYouWentIn::
	msgbox DaoDaoIsles_EternaForest_Text_YoungsterYouWentIn, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_EternaForest_EventScript_YoungsterQuiet::
	msgbox DaoDaoIsles_EternaForest_Text_YoungsterQuiet, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_EternaForest_Text_YoungsterDare:
	.string "Everyone in my class has done it.\p"
	.string "You go into the old MANSION alone\n"
	.string "and leave a doll somewhere inside.\p"
	.string "I brought mine and everything…\p"
	.string "I've just been standing here\n"
	.string "since lunch.$"

DaoDaoIsles_EternaForest_Text_YoungsterYouWentIn:
	.string "You went in there?\n"
	.string "And you came back out?\p"
	.string "…Did any of the dolls move?\p"
	.string "No! Don't tell me!$"

DaoDaoIsles_EternaForest_Text_YoungsterQuiet:
	.string "The big kids say it's gone quiet\n"
	.string "in there.\p"
	.string "So I'm going in for sure.\p"
	.string "Tomorrow.$"

@ -----------------------------------------------------------------------------------------
@ Moved from Akala_Forest_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_EternaForest_FindItem2::
	finditem ITEM_PP_UP, 1
	end


DaoDaoIsles_EternaForest_TrainerBattleBugCatcher1::
	trainerbattle_single TRAINER_DAODAO_ETERNA_FOREST_BUGCATCHER_1_HNS, DaoDaoIsles_EternaForest_TrainerBattleBugCatcher1_Text_0, DaoDaoIsles_EternaForest_TrainerBattleBugCatcher1_Text_1
	msgbox DaoDaoIsles_EternaForest_TrainerBattleBugCatcher1_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_EternaForest_TrainerBattleBugCatcher2::
	trainerbattle_single TRAINER_DAODAO_ETERNA_FOREST_BUGCATCHER_2_HNS, DaoDaoIsles_EternaForest_TrainerBattleBugCatcher2_Text_0, DaoDaoIsles_EternaForest_TrainerBattleBugCatcher2_Text_1
	msgbox DaoDaoIsles_EternaForest_TrainerBattleBugCatcher2_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_EternaForest_BattleToxicroak::
	lock
	faceplayer
	setflag FLAG_BATTLED_TOXICROAK
	playmoncry SPECIES_TOXICROAK, 0
	msgbox DaoDaoIsles_EternaForest_BattleToxicroak_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_TOXICROAK, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DaoDaoIsles_EternaForest_BattleToxicroak_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_EternaForest_BattleToxicroak_3
	release
	end

	release
	end

DaoDaoIsles_EternaForest_BattleToxicroak_2:
	setflag FLAG_HIDE_TOXICROAK
	removeobject LOCALID_DAODAO_ETERNA_FOREST_TOXICROAK
	release
	end

DaoDaoIsles_EternaForest_BattleToxicroak_3:
	setflag FLAG_HIDE_TOXICROAK
	removeobject LOCALID_DAODAO_ETERNA_FOREST_TOXICROAK
	release
	end


DaoDaoIsles_EternaForest_TrainerBattleBugCatcher1_Text_0:
	.string "Look at all the cool bugs here on the \nISLES!$"

DaoDaoIsles_EternaForest_TrainerBattleBugCatcher1_Text_1:
	.string "Ouch, that stung!$"

DaoDaoIsles_EternaForest_TrainerBattleBugCatcher1_Text_2:
	.string "The ISLES are far away from other land,\n"
	.string "so Bug-type POKéMON here must have\l"
	.string "adapted to the environment.$"

DaoDaoIsles_EternaForest_TrainerBattleBugCatcher2_Text_0:
	.string "Look at what I caught!$"

DaoDaoIsles_EternaForest_TrainerBattleBugCatcher2_Text_1:
	.string "Awh, that bites!$"

DaoDaoIsles_EternaForest_TrainerBattleBugCatcher2_Text_2:
	.string "The climate is a bit different on the\n"
	.string "DAODAO ISLES…\p"
	.string "I'm sure that's why there are some\n"
	.string "unique Bug-type POKéMON here.$"


DaoDaoIsles_EternaForest_BattleToxicroak_Text_0:
	.string "Gaaah!$"
