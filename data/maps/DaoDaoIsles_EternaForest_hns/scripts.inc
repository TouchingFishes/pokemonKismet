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
