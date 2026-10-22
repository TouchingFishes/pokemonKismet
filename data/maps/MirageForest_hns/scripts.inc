MirageForest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MirageForest_OnTransition
	.byte 0

@ The ZOROARK at the heart of the wood holds the DREAD PLATE (MIGRATION_DECISIONS.md 87). During
@ the plate hunt (VAR_SINJOH_STORYLINE 6 on) one of the STANTLER wandering round its cove at (29,4)
@ is the ZOROARK's illusion, among five real ones (MIGRATION_DECISIONS.md 88). It appears where the
@ illusion stood. Talking to it breaks the illusion, and the ZOROARK fights Noble-style:
@ no catching or running, boosted, L80 (ZORUA is still wild here, so ZOROARK stays obtainable).
@ Both objects hide on temp flags worked out here on every load, so a whiteout or a run brings
@ the illusion back; FLAG_HIDE_MIRAGE_ZOROARK ends it for good once the plate is won.
MirageForest_OnTransition:
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	goto_if_set FLAG_HIDE_MIRAGE_ZOROARK, MirageForest_OnTransition_End
	goto_if_lt VAR_SINJOH_STORYLINE, 6, MirageForest_OnTransition_End
	clearflag FLAG_TEMP_12
MirageForest_OnTransition_End:
	end

MirageForest_EventScript_ZoroarkIllusion::
	lock
	faceplayer
	msgbox MirageForest_Text_ZoroarkIntro, MSGBOX_DEFAULT
	closemessage
	getobjectxy LOCALID_MIRAGE_ZOROARK_ILLUSION, CURRENT_POSITION, VAR_0x8004, VAR_0x8005
	playse SE_M_DETECT
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, 0
	waitfieldeffect FLDEFF_SPARKLE
	removeobject LOCALID_MIRAGE_ZOROARK_ILLUSION
	setflag FLAG_TEMP_12
	clearflag FLAG_TEMP_13
	setobjectxyperm LOCALID_MIRAGE_ZOROARK, VAR_0x8004, VAR_0x8005
	addobject LOCALID_MIRAGE_ZOROARK
	playmoncry SPECIES_ZOROARK, CRY_MODE_ENCOUNTER
	msgbox MirageForest_Text_IllusionBreaks, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto MirageForest_EventScript_ZoroarkFight

MirageForest_EventScript_Zoroark::
	lock
	faceplayer
	playmoncry SPECIES_ZOROARK, CRY_MODE_ENCOUNTER
	waitmoncry
MirageForest_EventScript_ZoroarkFight:
	setflag FLAG_BATTLED_MIRAGE_ZOROARK
	setwildbossbattle species=SPECIES_ZOROARK, level=80, item=ITEM_BLACK_GLASSES, move1_1=MOVE_NIGHT_DAZE, move1_2=MOVE_NASTY_PLOT, move1_3=MOVE_EXTRASENSORY, move1_4=MOVE_FLAMETHROWER
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 1, 1, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MirageForest_EventScript_ZoroarkStays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MirageForest_EventScript_ZoroarkStays
	bufferspeciesname STR_VAR_1, SPECIES_ZOROARK
	msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
	giveitem ITEM_DREAD_PLATE
	addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MIRAGE_ZOROARK
	setflag FLAG_HIDE_MIRAGE_ZOROARK
	fadescreenswapbuffers FADE_FROM_BLACK
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end

MirageForest_EventScript_ZoroarkStays::
	release
	end

MirageForest_EventScript_ItemNeverMeltIce::
	finditem ITEM_NEVER_MELT_ICE
	end

MirageForest_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

MirageForest_EventScript_Rosalind::
	trainerbattle_single TRAINER_ROSALIND_HNS, MirageForest_Text_RosalindIntro, MirageForest_Text_RosalindDefeat, MirageForest_EventScript_RosalindHerd
	lock
	faceplayer
MirageForest_EventScript_RosalindHerd::
	goto_if_set FLAG_HIDE_MIRAGE_ZOROARK, MirageForest_EventScript_RosalindHerdCalm
	goto_if_ge VAR_SINJOH_STORYLINE, 6, MirageForest_EventScript_RosalindHerdOdd
	msgbox MirageForest_Text_RosalindHerdRestless, MSGBOX_DEFAULT
	release
	end

MirageForest_EventScript_RosalindHerdOdd:
	msgbox MirageForest_Text_RosalindHerdOdd, MSGBOX_DEFAULT
	release
	end

MirageForest_EventScript_RosalindHerdCalm:
	msgbox MirageForest_Text_RosalindHerdCalm, MSGBOX_DEFAULT
	release
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

MirageForest_Text_IllusionBreaks:
	.string "The STANTLER's outline flickers…\p"
	.string "It was a ZOROARK all along!$"

MirageForest_Text_RosalindIntro:
	.string "Shh! Keep your voice down, or\n"
	.string "you'll spook the herd.\p"
	.string "...You climbed all the way up\n"
	.string "here? Then let's see if your\l"
	.string "POKéMON are as steady as you!$"

MirageForest_Text_RosalindDefeat:
	.string "Steady hands. You'll do.$"

MirageForest_Text_RosalindHerdRestless:
	.string "I'm a POKéMON RANGER. I've kept\n"
	.string "watch over this STANTLER herd\l"
	.string "for weeks now.\p"
	.string "Lately they won't settle. They\n"
	.string "keep staring into the trees, as\l"
	.string "if something is watching them.$"

MirageForest_Text_RosalindHerdOdd:
	.string "Can I tell you something strange?\p"
	.string "I count this herd every morning.\n"
	.string "Five STANTLER. Always five.\p"
	.string "Today there are six.\p"
	.string "And one of them doesn't leave a\n"
	.string "single track in the snow.\p"
	.string "If you go near them... be careful.$"

MirageForest_Text_RosalindHerdCalm:
	.string "The herd has finally calmed down.\p"
	.string "Whatever was walking among them\n"
	.string "is gone. I counted five again\l"
	.string "this morning.$"

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
