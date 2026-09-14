LavenderTown_SoulHouse_hns_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "MR.FUJI: Welcome.\p"
	.string "Hmm… You appear to be raising\n"
	.string "your POKéMON in a kind and\l"
	.string "loving manner.\p"
	.string "POKéMON lovers come here to pay\n"
	.string "their respects to departed\l"
	.string "POKéMON.\p"
	.string "Please offer condolences for the\n"
	.string "souls of the departed POKéMON.\p"
	.string "I'm sure that will make them\n"
	.string "happy.$"

SoulHouse_Text_Teacher:
	.string "There are other graves of POKéMON\n"
	.string "here, I think.\p"
	.string "There are many chambers that only\n"
	.string "MR.FUJI may enter.$"

SoulHouse_Text_Lass:
	.string "I came with my mom to visit\n"
	.string "POKéMON graves…$"

SoulHouse_Text_Granny:
	.string "The POKéMON that lived with me…\p"
	.string "I loved them like my\n"
	.string "grandchildren…$"

LavenderTownSoulHouse_EventScript_Agatha::
	trainerbattle_single TRAINER_AGATHA_HNS, LavenderTownSoulHouse_Text_AgathaSeen, LavenderTownSoulHouse_Text_AgathaBeaten
	msgbox LavenderTownSoulHouse_Text_AgathaAfter, MSGBOX_AUTOCLOSE
	end

LavenderTownSoulHouse_Text_AgathaSeen:
	.string "AGATHA: Hello, child.\p"
	.string "My name is AGATHA.\p"
	.string "I fought for years as a member of the\nELITE FOUR.\p"
	.string "…………\p"
	.string "Have you come to mourn a POKéMON?\p"
	.string "It might not be here any longer.\p"
	.string "MR.FUJI kept many of the graves\nelsewhere after the radio company\ltook over.\p"
	.string "…………\p"
	.string "He could have fought to preserve the\ntower! But he wouldn't get involved.\lToo scared of abusing his influence.\p"
	.string "That old fool…\p"
	.string "Power is meant to be used!\p"
	.string "You clearly understand me.\p"
	.string "I'll show you what a powerful trainer\ncan do!$"

LavenderTownSoulHouse_Text_AgathaBeaten:
	.string "Oh, my!$"

LavenderTownSoulHouse_Text_AgathaAfter:
	.string "I expect great things from you, if\nyou will them.$"
