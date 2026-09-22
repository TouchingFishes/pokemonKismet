DaoDaoIsles_GiantsStair_House_hns_MapScripts::
	.byte 0

DaoDaoIsles_GiantsStair_House_EventScript_Drake::
	trainerbattle_single TRAINER_ELITE_DRAKE_HNS, DaoDaoIsles_GiantsStair_House_Text_DrakeIntro, DaoDaoIsles_GiantsStair_House_Text_DrakeDefeat
	msgbox DaoDaoIsles_GiantsStair_House_Text_DrakeAfter, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_GiantsStair_House_Text_DrakeIntro:
	.string "Close the door, it drags the heat\n"
	.string "out.\p"
	.string "You climbed all that for a house.\n"
	.string "Most turn back at the second bend.\p"
	.string "I built here on purpose. Forty years\n"
	.string "at sea and I wanted somewhere the\l"
	.string "water couldn't reach.\p"
	.string "It's quieter than I bargained for.\n"
	.string "The thing sleeping at the top of\l"
	.string "this stair does not snore, but you\l"
	.string "know it's there.\p"
	.string "Sit down. No - on second thought,\n"
	.string "don't. Let's see what you've got.$"

DaoDaoIsles_GiantsStair_House_Text_DrakeDefeat:
	.string "Hm! Steady hands.$"

DaoDaoIsles_GiantsStair_House_Text_DrakeAfter:
	.string "Keep going up, if you're going.\p"
	.string "Whatever's up there was old when\n"
	.string "this rock was young. Be civil to it.$"

DaoDaoIsles_GiantsStair_House_EventScript_ShelfBagon::
	msgbox DaoDaoIsles_GiantsStair_House_Text_ShelfBagon, MSGBOX_SIGN
	end

DaoDaoIsles_GiantsStair_House_EventScript_ShelfSalamence::
	msgbox DaoDaoIsles_GiantsStair_House_Text_ShelfSalamence, MSGBOX_SIGN
	end

DaoDaoIsles_GiantsStair_House_Text_ShelfBagon:
	.string "ON THE HEAD OF BAGON, vol. I.\p"
	.string "“The skull is not armour. It is a\n"
	.string "tool, and BAGON uses it the way a\l"
	.string "frustrated man uses a wall.\p"
	.string "“It cannot fly. It is built entirely\n"
	.string "wrong for it, and it knows, and it\l"
	.string "throws itself off the cliff anyway.\p"
	.string "“Every specimen I have examined has\n"
	.string "healed fractures. Every one.”$"

DaoDaoIsles_GiantsStair_House_Text_ShelfSalamence:
	.string "ON THE HEAD OF BAGON, vol. II.\p"
	.string "“SHELGON seals itself and stops\n"
	.string "eating. From outside, nothing.\l"
	.string "Inside, the whole animal is being\l"
	.string "taken apart and put back.\p"
	.string "“What comes out has wings.\p"
	.string "“The cells did not grow them. They\n"
	.string "REMEMBERED them - the wanting was\l"
	.string "in the blood the entire time.\p"
	.string "“A SALAMENCE that has just flown for\n"
	.string "the first time is not safe to stand\l"
	.string "near. It is not anger. It is joy,\l"
	.string "and it burns the same.”\p"
	.string "The margin is annotated in a\n"
	.string "sailor's hand: “Forty years. Same\l"
	.string "with men.”$"
