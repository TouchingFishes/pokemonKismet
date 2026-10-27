CeladonCity_House1_hns_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MILCERY, CeladonCity_House1_EventScript_ChefAfter
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_DEFAULT
	msgbox CeladonCity_House1_Text_ChefMilcery, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_House1_EventScript_ChefDeclined
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MILCERY
	bufferspeciesname STR_VAR_1, SPECIES_MILCERY
	givemon SPECIES_MILCERY, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon
	call Common_EventScript_GiftMon
	setflag FLAG_RECEIVED_MILCERY
CeladonCity_House1_EventScript_ChefAfter:
	msgbox CeladonCity_House1_Text_ChefAfter, MSGBOX_DEFAULT
	release
	end

CeladonCity_House1_EventScript_ChefDeclined:
	msgbox CeladonCity_House1_Text_ChefDeclined, MSGBOX_DEFAULT
	release
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "Hi!\p"
	.string "We're holding an eatathon contest.\p"
	.string "We can't serve you right now.\n"
	.string "Sorry.$"

CeladonCity_House1_Text_ChefMilcery:
	.string "…Oh, and this little one keeps\n"
	.string "sneaking into the kitchen for\l"
	.string "the whipped cream.\p"
	.string "A trainer like you could give it\n"
	.string "a better home than my pantry.\p"
	.string "Would you take MILCERY with you?$"

CeladonCity_House1_Text_ChefAfter:
	.string "How is MILCERY doing?\p"
	.string "They say it turns into ALCREMIE\n"
	.string "when it touches an evolution\l"
	.string "stone.\p"
	.string "Every stone makes a different\n"
	.string "flavor. Isn't that sweet?$"

CeladonCity_House1_Text_ChefDeclined:
	.string "Oh… Then it stays with the\n"
	.string "cream for now.$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "…Snarfle, chew…$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "Don't talk to me!\p"
	.string "You'll break my concentration!$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "…Gulp… Chew…$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "I take quantity over quality!\p"
	.string "I'm happy when I'm full!$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "Munch, munch…$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "The food is good here, but\n"
	.string "GOLDENROD has the best food\l"
	.string "anywhere.$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "Crunch… Crunch…$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "Nobody here will give you a COIN\n"
	.string "CASE. You should look in JOHTO.$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "Crunch… Crunch…\p"
	.string "I can keep eating!\p"
	.string "More, CHEF!$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "Eatathon Contest! No time limit!\p"
	.string "A battle without end! The biggest\n"
	.string "muncher gets it all for free!$"

