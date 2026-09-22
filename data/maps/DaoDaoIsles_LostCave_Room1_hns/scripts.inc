DaoDaoIsles_LostCave_Room1_hns_MapScripts::
	.byte 0

DaoDaoIsles_LostCave_Room1_EventScript_Lawson::
	trainerbattle_single TRAINER_LAWSON_HNS, DaoDaoIsles_LostCave_Room1_Text_LawsonIntro, DaoDaoIsles_LostCave_Room1_Text_LawsonDefeat
	msgbox DaoDaoIsles_LostCave_Room1_Text_LawsonPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_LostCave_Room1_Text_LawsonIntro:
	.string "Aiyeeeeeh!\p"
	.string "I came here for a ruin. This is\n"
	.string "a ruin that moves!$"

DaoDaoIsles_LostCave_Room1_Text_LawsonDefeat:
	.string "Aiyeeeeeh!\n"
	.string "Mercy!$"

DaoDaoIsles_LostCave_Room1_Text_LawsonPostBattle:
	.string "I keep walking out of here and\n"
	.string "arriving back in this same room.\p"
	.string "The only thing that changes is the\n"
	.string "boulders. I have counted them in\l"
	.string "every room I can reach.\p"
	.string "Three. Six. Nine. Twelve.\p"
	.string "Numbers like that belong on a\n"
	.string "clock face, not in a cave.$"
