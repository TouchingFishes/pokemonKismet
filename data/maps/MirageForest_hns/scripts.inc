MirageForest_hns_MapScripts::
	.byte 0

MirageForest_EventScript_Zoroark::
	lock
	faceplayer
	setflag FLAG_BATTLED_MIRAGE_ZOROARK
	msgbox MirageForest_Text_ZoroarkIntro, MSGBOX_DEFAULT
	playmoncry SPECIES_ZOROARK, 0
	waitmoncry
	setwildbossbattle species=SPECIES_ZOROARK, level=72, move1_1=MOVE_NIGHT_DAZE, move1_2=MOVE_NASTY_PLOT, move1_3=MOVE_EXTRASENSORY, move1_4=MOVE_FLAMETHROWER
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

MirageForest_EventScript_Rosalind::
	trainerbattle_single TRAINER_ROSALIND_HNS, MirageForest_Text_RosalindIntro, MirageForest_Text_RosalindDefeat
	msgbox MirageForest_Text_RosalindAfter, MSGBOX_AUTOCLOSE
	end

MirageForest_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_HNS, MirageForest_Text_TabithaIntro, MirageForest_Text_TabithaDefeat
	msgbox MirageForest_Text_TabithaAfter, MSGBOX_AUTOCLOSE
	end

MirageForest_EventScript_Isolde::
	trainerbattle_single TRAINER_ISOLDE_HNS, MirageForest_Text_IsoldeIntro, MirageForest_Text_IsoldeDefeat
	msgbox MirageForest_Text_IsoldeAfter, MSGBOX_AUTOCLOSE
	end

MirageForest_EventScript_Merrick::
	trainerbattle_single TRAINER_MERRICK_HNS, MirageForest_Text_MerrickIntro, MirageForest_Text_MerrickDefeat
	msgbox MirageForest_Text_MerrickAfter, MSGBOX_AUTOCLOSE
	end


MirageForest_Text_ZoroarkIntro:
	.string "The trees here do not stay where\n"
	.string "you left them.\p"
	.string "Something at the heart of the\n"
	.string "wood is watching, and it is\l"
	.string "tired of being looked for.$"

MirageForest_Text_RosalindIntro:
	.string "You found your way in.\p"
	.string "Most people only think they\n"
	.string "have.$"

MirageForest_Text_RosalindDefeat:
	.string "You saw through it.$"

MirageForest_Text_RosalindAfter:
	.string "The forest shows you what you\n"
	.string "expect to see.\p"
	.string "Stop expecting, and you will\n"
	.string "find your way out.$"

MirageForest_Text_TabithaIntro:
	.string "Shh. Do not startle them.\p"
	.string "They are only curious about\n"
	.string "you.$"

MirageForest_Text_TabithaDefeat:
	.string "Oh! How rude of them.$"

MirageForest_Text_TabithaAfter:
	.string "There is a house deeper in.\p"
	.string "Do not accept anything they\n"
	.string "offer you to drink.$"

MirageForest_Text_IsoldeIntro:
	.string "Another living one.\n"
	.string "It has been a while.$"

MirageForest_Text_IsoldeDefeat:
	.string "Warm hands. How strange.$"

MirageForest_Text_IsoldeAfter:
	.string "My sister says two old women\n"
	.string "keep the house.\p"
	.string "I have never seen them by\n"
	.string "daylight. Nor has she.$"

MirageForest_Text_MerrickIntro:
	.string "I have walked this wood for\n"
	.string "forty years.\p"
	.string "It is not the same wood twice.$"

MirageForest_Text_MerrickDefeat:
	.string "Ah. You are real, then.$"

MirageForest_Text_MerrickAfter:
	.string "Something at the heart of it\n"
	.string "does the dreaming.\p"
	.string "I have never been able to reach\n"
	.string "it. Perhaps you will.$"
