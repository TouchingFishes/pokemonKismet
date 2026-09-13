MirageForest_hns_MapScripts::
	.byte 0

MirageForest_EventScript_Zoroark::
	lock
	faceplayer
	setflag FLAG_BATTLED_MIRAGE_ZOROARK
	msgbox MirageForest_Text_ZoroarkIntro, MSGBOX_DEFAULT
	playmoncry SPECIES_ZOROARK, 0
	waitmoncry
	setwildbossbattle species=SPECIES_ZOROARK, level=55, move1_1=MOVE_NIGHT_DAZE, move1_2=MOVE_NASTY_PLOT, move1_3=MOVE_EXTRASENSORY, move1_4=MOVE_FLAMETHROWER
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MirageForest_EventScript_ZoroarkGone
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MirageForest_EventScript_ZoroarkGone
	release
	end

MirageForest_EventScript_ZoroarkGone::
	setflag FLAG_HIDE_MIRAGE_ZOROARK
	removeobject LOCALID_MIRAGE_ZOROARK
	release
	end

MirageForest_EventScript_ItemNeverMeltIce::
	finditem ITEM_NEVER_MELT_ICE
	end

MirageForest_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end


MirageForest_Text_ZoroarkIntro:
	.string "The trees here do not stay where\n"
	.string "you left them.\p"
	.string "Something at the heart of the\n"
	.string "wood is watching, and it is\l"
	.string "tired of being looked for.$"
