MirageForest_House_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MirageForest_House_hns_OnTransition
	.byte 0

MirageForest_House_hns_OnTransition:
	goto_if_set FLAG_BATTLED_MIRAGE_POLTEAGEIST, MirageForestHouse_EmptyForever
	goto_if_set FLAG_NIGHT_POKEMON, MirageForestHouse_Daytime
	setflag FLAG_HIDE_MIRAGE_HOUSE_GRANDMAS
	clearflag FLAG_HIDE_MIRAGE_POLTEAGEIST
	return

MirageForestHouse_Daytime:
	clearflag FLAG_HIDE_MIRAGE_HOUSE_GRANDMAS
	setflag FLAG_HIDE_MIRAGE_POLTEAGEIST
	return

@ Once the teapot is gone the house stays empty at every hour. The women were
@ never really there.
MirageForestHouse_EmptyForever:
	setflag FLAG_HIDE_MIRAGE_HOUSE_GRANDMAS
	setflag FLAG_HIDE_MIRAGE_POLTEAGEIST
	return


MirageForestHouse_EventScript_GrandmaA::
	lock
	faceplayer
	msgbox MirageForestHouse_Text_GrandmaA, MSGBOX_DEFAULT
	release
	end

MirageForestHouse_EventScript_GrandmaB::
	lock
	faceplayer
	msgbox MirageForestHouse_Text_GrandmaB, MSGBOX_DEFAULT
	release
	end

MirageForestHouse_EventScript_Polteageist::
	lock
	faceplayer
	setflag FLAG_BATTLED_MIRAGE_POLTEAGEIST
	msgbox MirageForestHouse_Text_PolteageistIntro, MSGBOX_DEFAULT
	playmoncry SPECIES_POLTEAGEIST, 0
	waitmoncry
	setwildbossbattle species=SPECIES_POLTEAGEIST, level=70, move1_1=MOVE_SHADOW_BALL, move1_2=MOVE_NASTY_PLOT, move1_3=MOVE_GIGA_DRAIN, move1_4=MOVE_WILL_O_WISP
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MirageForestHouse_EventScript_PolteageistGone
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MirageForestHouse_EventScript_PolteageistGone
	release
	end

MirageForestHouse_EventScript_PolteageistGone::
	setflag FLAG_HIDE_MIRAGE_POLTEAGEIST
	removeobject LOCALID_MIRAGE_POLTEAGEIST
	release
	end


MirageForestHouse_Text_GrandmaA:
	.string "Oh! A visitor, all the way out\n"
	.string "here.\p"
	.string "We so rarely get visitors.\n"
	.string "Do come back after dark, dear.\p"
	.string "We always take our tea at night.$"

MirageForestHouse_Text_GrandmaB:
	.string "My sister has already asked\n"
	.string "you, hasn't she?\p"
	.string "Come back when it's dark and\n"
	.string "we'll put the pot on.\p"
	.string "We've been waiting such a\n"
	.string "very long time.$"

MirageForestHouse_Text_PolteageistIntro:
	.string "The house is empty. The chairs\n"
	.string "are cold.\p"
	.string "Only the teapot is here, and it\n"
	.string "is still warm.\p"
	.string "It has already poured two cups.$"
