CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	goto_if_set FLAG_IS_KANTO_CHAMPION, CherrygroveCity_House2_EventScript_GuideGentGrandkids
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House2_EventScript_GuideGentGrandkids::
	msgbox CherrygroveCity_GuideHouse_Text_GuideGentGrandkids, MSGBOX_DEFAULT
	closemessage
	release
	end

@ CLAYDOL keeps the old man company. No script beyond a cry and a look - it is
@ flavour, so it is left out of the dex entirely rather than registered.
CherrygroveCity_House2_EventScript_Claydol::
	lock
	faceplayer
	playmoncry SPECIES_CLAYDOL, CRY_MODE_NORMAL
	msgbox CherrygroveCity_GuideHouse_Text_Claydol, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

@ MORI and SARI are behind FLAG_HIDE_CHERRYGROVE_GRANDKIDS, which the day-of-week
@ table recomputes on every map load: weekends only, and only once
@ FLAG_IS_KANTO_CHAMPION is set. Their beaten flags are cleared on every League
@ clear after the first, so each trip through the ELITE FOUR makes them
@ challengeable again.
CherrygroveCity_House2_EventScript_Mori::
	trainerbattle_single TRAINER_MORI_HNS, CherrygroveCity_GuideHouse_Text_MoriIntro, CherrygroveCity_GuideHouse_Text_MoriDefeat
	msgbox CherrygroveCity_GuideHouse_Text_MoriAfter, MSGBOX_AUTOCLOSE
	end

CherrygroveCity_House2_EventScript_Sari::
	trainerbattle_single TRAINER_SARI_HNS, CherrygroveCity_GuideHouse_Text_SariIntro, CherrygroveCity_GuideHouse_Text_SariDefeat
	msgbox CherrygroveCity_GuideHouse_Text_SariAfter, MSGBOX_AUTOCLOSE
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "When I was a wee lad, I was a\n"
	.string "hotshot trainer!\p"
	.string "Here's a word of advice:\n"
	.string "Catch lots of POKéMON!\p"
	.string "Treat them all with kindness!$"

CherrygroveCity_GuideHouse_Text_GuideGentGrandkids:
	.string "My grandchildren come over on the\n"
	.string "weekend. Every weekend, without\l"
	.string "fail, since they were small.\p"
	.string "They do their homework at that\n"
	.string "table and they feed CLAYDOL.\p"
	.string "They will ask you for a battle.\n"
	.string "They always ask.\p"
	.string "Do not be gentle with them. They\n"
	.string "will not be gentle with you.$"

CherrygroveCity_GuideHouse_Text_Claydol:
	.string "CLAYDOL hangs in the corner,\n"
	.string "turning very slowly.\p"
	.string "It has been in this family longer\n"
	.string "than the old man has.\p"
	.string "CLAYDOL: Wooooon…$"

CherrygroveCity_GuideHouse_Text_MoriIntro:
	.string "Oh! Grandpa said someone strong\n"
	.string "might visit.\p"
	.string "I have got homework, but it can\n"
	.string "wait. It is only maths.\p"
	.string "Six on six, please!$"

CherrygroveCity_GuideHouse_Text_MoriDefeat:
	.string "Whoa! You are actually good!$"

CherrygroveCity_GuideHouse_Text_MoriAfter:
	.string "That was the best one all year.\p"
	.string "Sari says I overtrain. I say she\n"
	.string "does not train enough.\p"
	.string "Come back after you beat the\n"
	.string "ELITE FOUR again. I will have\l"
	.string "thought of something by then.$"

CherrygroveCity_GuideHouse_Text_SariIntro:
	.string "Hello! Are you here for grandpa\n"
	.string "or for us?\p"
	.string "Mori always goes first. He thinks\n"
	.string "he is the strong one.\p"
	.string "Let us find out.$"

CherrygroveCity_GuideHouse_Text_SariDefeat:
	.string "Ah. I knew that would happen.$"

CherrygroveCity_GuideHouse_Text_SariAfter:
	.string "You are better than my brother.\n"
	.string "Do not tell him I said that.\p"
	.string "We are here every weekend.\p"
	.string "Beat the ELITE FOUR again and we\n"
	.string "will both be ready for you.$"
