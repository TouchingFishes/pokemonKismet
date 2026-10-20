DaoDaoIsles_RocketLab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_RocketLab_OnTransition
	.byte 0

DaoDaoIsles_RocketLab_OnTransition:
	call DaoDaoIsles_RocketLab_SetGideon
	call DaoDaoIsles_RocketLab_SetKlinklang
	call DaoDaoIsles_RocketLab_SetGiovanni
	call DaoDaoIsles_RocketLab_SetGenesect
	call DaoDaoIsles_RocketLab_SetAssistant
	end

DaoDaoIsles_RocketLab_SetGideon:
	setflag FLAG_HIDE_DAODAO_LAB_GIDEON
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GIDEON
	return

@ KLINKLANG is the REGISTEEL boss, but it is gated on GIDEON alone - NOT on
@ FLAG_DAODAO_REGIS_ENABLED like the other four. Gating it on the braille riddle
@ would put a puzzle in a different chamber on a different island in front of
@ finishing the KANTO POKeMON FEDERATION arc.
DaoDaoIsles_RocketLab_SetKlinklang:
	setflag FLAG_HIDE_DAODAO_BOSS_REGISTEEL
	goto_if_set FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_BOSS_REGISTEEL
	return

DaoDaoIsles_RocketLab_SetGiovanni:
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	return

DaoDaoIsles_RocketLab_SetGenesect:
	setflag FLAG_HIDE_DAODAO_LAB_GENESECT
	goto_if_set FLAG_DAODAO_GENESECT_TAKEN, DaoDaoIsles_RocketLab_Ret
	goto_if_set FLAG_DAODAO_GENESECT_KNOCKED_OUT, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GENESECT
	return

@ The assistant who stayed behind, at GIDEON's desk once he is gone - the KLINK and KLANG
@ have no wild slot since the Alola tables went, so this is where the line comes from.
@ No hide flag of its own: FLAG_TEMP_11 is derived here on every load.
DaoDaoIsles_RocketLab_SetAssistant:
	setflag FLAG_TEMP_11
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_TEMP_11
	return

DaoDaoIsles_RocketLab_Ret:
	return

DaoDaoIsles_RocketLab_EventScript_Assistant::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DAODAO_LAB_KLINK, DaoDaoIsles_RocketLab_EventScript_AssistantAfter
	msgbox DaoDaoIsles_RocketLab_Text_AssistantKlink, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KLINK
	bufferspeciesname STR_VAR_1, SPECIES_KLINK
	givemon SPECIES_KLINK, 43
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, DaoDaoIsles_RocketLab_EventScript_AssistantNoRoom
	call Common_EventScript_GiftMon
	setflag FLAG_RECEIVED_DAODAO_LAB_KLINK
DaoDaoIsles_RocketLab_EventScript_AssistantAfter:
	msgbox DaoDaoIsles_RocketLab_Text_AssistantAfter, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_RocketLab_EventScript_AssistantNoRoom:
	msgbox DaoDaoIsles_RocketLab_Text_AssistantNoRoom, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_RocketLab_Text_AssistantKlink:
	.string "DR. GIDEON is gone, and the rest of\n"
	.string "the staff with him.\p"
	.string "Somebody had to stay and feed the\n"
	.string "KLINK.\p"
	.string "It came off the big one at the far\n"
	.string "end. One gear, years ago. It has\l"
	.string "been turning in a box under my\l"
	.string "desk ever since.\p"
	.string "Take it. It's the only thing in this\n"
	.string "room that never hurt anybody.$"

DaoDaoIsles_RocketLab_Text_AssistantAfter:
	.string "Gears like that don't belong in a\n"
	.string "box.$"

DaoDaoIsles_RocketLab_Text_AssistantNoRoom:
	.string "You've got no room for it. Come back\n"
	.string "when you do.$"

DaoDaoIsles_RocketLab_EventScript_Cueball1::
	trainerbattle_single TRAINER_DAODAO_LAB_CUEBALL_1_HNS, DaoDaoIsles_RocketLab_Text_Cueball1Intro, DaoDaoIsles_RocketLab_Text_Cueball1Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Cueball1Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Scientist1::
	trainerbattle_single TRAINER_DAODAO_LAB_SCIENTIST_1_HNS, DaoDaoIsles_RocketLab_Text_Scientist1Intro, DaoDaoIsles_RocketLab_Text_Scientist1Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Scientist1Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Cueball2::
	trainerbattle_single TRAINER_DAODAO_LAB_CUEBALL_2_HNS, DaoDaoIsles_RocketLab_Text_Cueball2Intro, DaoDaoIsles_RocketLab_Text_Cueball2Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Cueball2Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Scientist2::
	trainerbattle_single TRAINER_DAODAO_LAB_SCIENTIST_2_HNS, DaoDaoIsles_RocketLab_Text_Scientist2Intro, DaoDaoIsles_RocketLab_Text_Scientist2Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Scientist2Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Gideon::
	trainerbattle_single TRAINER_GIDEON_HNS, DaoDaoIsles_RocketLab_Text_GideonIntro, DaoDaoIsles_RocketLab_Text_GideonDefeat, DaoDaoIsles_RocketLab_EventScript_GideonDefeated
	end

DaoDaoIsles_RocketLab_EventScript_GideonDefeated::
	setvar VAR_FUCHSIA_FEDERATION_STATE, 6
	call Common_EventScript_ClearKantoCordon
	setflag FLAG_DEFEATED_DAODAO_LAB_GIDEON
	msgbox DaoDaoIsles_RocketLab_Text_GideonPostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GIDEON
	setflag FLAG_HIDE_DAODAO_LAB_GIDEON
	clearflag FLAG_HIDE_DAODAO_BOSS_REGISTEEL
	addobject LOCALID_DAODAO_BOSS_REGISTEEL
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_EventScript_BossKlinklang::
	lock
	faceplayer
	playmoncry SPECIES_KLINKLANG, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_RocketLab_Text_KlinklangIntro, MSGBOX_DEFAULT
	closemessage
	setwildbossbattle species=SPECIES_KLINKLANG, level=70, item=ITEM_METAL_COAT, move1_1=MOVE_GEAR_GRIND, move1_2=MOVE_WILD_CHARGE, move1_3=MOVE_FLASH_CANNON, move1_4=MOVE_SHIFT_GEAR
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 1, 1, 0, 0, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_RocketLab_EventScript_BossStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a win.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_RocketLab_EventScript_BossStays
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGISTEEL
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_BOSS_REGISTEEL
	setflag FLAG_HIDE_DAODAO_BOSS_REGISTEEL
	clearflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	addobject LOCALID_DAODAO_LAB_GIOVANNI
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox DaoDaoIsles_RocketLab_Text_KlinklangBeaten, MSGBOX_DEFAULT
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_RocketLab_EventScript_BossStays::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_RocketLab_EventScript_Giovanni::
	trainerbattle_single TRAINER_GIOVANNI_LAB_HNS, DaoDaoIsles_RocketLab_Text_GiovanniIntro, DaoDaoIsles_RocketLab_Text_GiovanniDefeat, DaoDaoIsles_RocketLab_EventScript_GiovanniDefeated
	end

DaoDaoIsles_RocketLab_EventScript_GiovanniDefeated::
	setflag FLAG_DEFEATED_DAODAO_LAB_GIOVANNI
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DAODAO_LAB_GIOVANNI, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	playse SE_BALL_THROW
	waitse
	clearflag FLAG_HIDE_DAODAO_LAB_GENESECT
	addobject LOCALID_DAODAO_LAB_GENESECT
	playse SE_BALL_OPEN
	waitse
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	msgbox DaoDaoIsles_RocketLab_Text_GiovanniFreesGenesect, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GIOVANNI
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_EventScript_Genesect::
	lock
	faceplayer
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_RocketLab_Text_Genesect, MSGBOX_DEFAULT
	closemessage
	seteventmon SPECIES_GENESECT, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_RocketLab_EventScript_GenesectStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a knockout.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_RocketLab_EventScript_GenesectStays
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DaoDaoIsles_RocketLab_EventScript_Genesect_Caught
	@ Knocked out: back after the next Hall of Fame (SpawnDaoDaoLegendaries).
	setflag FLAG_DAODAO_GENESECT_KNOCKED_OUT
	goto DaoDaoIsles_RocketLab_EventScript_Genesect_Gone

DaoDaoIsles_RocketLab_EventScript_Genesect_Caught:
	setflag FLAG_DAODAO_GENESECT_TAKEN
DaoDaoIsles_RocketLab_EventScript_Genesect_Gone:
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GENESECT
	setflag FLAG_HIDE_DAODAO_LAB_GENESECT
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_EventScript_GenesectStays::
	release
	end

DaoDaoIsles_RocketLab_Text_Cueball1Intro:
	.string "The boss said no visitors.\p"
	.string "The boss is very clear about\n"
	.string "things like that.$"

DaoDaoIsles_RocketLab_Text_Cueball1Defeat:
	.string "Didn't see that coming.$"

DaoDaoIsles_RocketLab_Text_Cueball1Post:
	.string "He's still here, you know.\p"
	.string "Never goes up. Never goes home.$"

DaoDaoIsles_RocketLab_Text_Scientist1Intro:
	.string "You are contaminating a sealed\n"
	.string "site.\p"
	.string "I will have to log this.$"

DaoDaoIsles_RocketLab_Text_Scientist1Defeat:
	.string "My figures were correct!$"

DaoDaoIsles_RocketLab_Text_Scientist1Post:
	.string "We were told it was defensive.\p"
	.string "Nothing with a cannon bolted to\n"
	.string "its spine is defensive.$"

DaoDaoIsles_RocketLab_Text_Cueball2Intro:
	.string "Turn around, kid.\p"
	.string "There's nothing back there worth\n"
	.string "the walk.$"

DaoDaoIsles_RocketLab_Text_Cueball2Defeat:
	.string "All right, all right!$"

DaoDaoIsles_RocketLab_Text_Cueball2Post:
	.string "Don't look it in the eye.\p"
	.string "It remembers faces.$"

DaoDaoIsles_RocketLab_Text_Scientist2Intro:
	.string "Fascinating. An uninvited\n"
	.string "variable.\p"
	.string "Let us see how you perform.$"

DaoDaoIsles_RocketLab_Text_Scientist2Defeat:
	.string "An unhelpful result.$"

DaoDaoIsles_RocketLab_Text_Scientist2Post:
	.string "We kept it fed and we kept it\n"
	.string "still.\p"
	.string "That was the whole of the work.$"

DaoDaoIsles_RocketLab_Text_GideonIntro:
	.string "Don't touch that. Or that.\p"
	.string "You took my FEDERATION apart in\n"
	.string "FUCHSIA, and now you've come to\l"
	.string "take apart my lab.\p"
	.string "PAXTON was the muscle. I was\n"
	.string "the reason he had any.\p"
	.string "Let's see if you understand\n"
	.string "what you're breaking.$"

DaoDaoIsles_RocketLab_Text_GideonDefeat:
	.string "Crude. Effective, but crude.$"

DaoDaoIsles_RocketLab_Text_GideonPostBattle:
	.string "I wanted one thing in twenty\n"
	.string "years that GIOVANNI's money\l"
	.string "never touched.\p"
	.string "The FEDERATION lasted a month\n"
	.string "before it was his again in all\l"
	.string "but the name.\p"
	.string "He's here. The far end of the\n"
	.string "floor. He never left.\p"
	.string "The thing between you was in\n"
	.string "the ruins before any of us.\l"
	.string "It has never powered down.\l"
	.string "Mind it.$"

DaoDaoIsles_RocketLab_Text_KlinklangIntro:
	.string "It has been turning on the same\n"
	.string "spot for twenty years.\p"
	.string "The gears are cut with the same\n"
	.string "marks as the ruin walls.$"

DaoDaoIsles_RocketLab_Text_KlinklangBeaten:
	.string "The gears stop.\p"
	.string "For the first time in twenty years\n"
	.string "the warehouse is quiet, and the\l"
	.string "far end of it is not empty.$"

DaoDaoIsles_RocketLab_Text_GiovanniIntro:
	.string "So the warehouse still had one\n"
	.string "more visitor in it.\p"
	.string "I sank this place because it was\n"
	.string "the only thing I ever regretted\l"
	.string "building.\p"
	.string "Turn around, or I will sink it\n"
	.string "again with you inside.$"

DaoDaoIsles_RocketLab_Text_GiovanniDefeat:
	.string "Enough.$"

DaoDaoIsles_RocketLab_Text_GiovanniPostBattle:
	.string "Gideon drew it. I paid for it.\p"
	.string "Neither of us could ever switch\n"
	.string "it off.\p"
	.string "Twenty years I have kept it on a\n"
	.string "belt, because I did not trust\l"
	.string "anyone else to.$"

DaoDaoIsles_RocketLab_Text_GiovanniFreesGenesect:
	.string "GIOVANNI released GENESECT.\p"
	.string "I am done carrying it.\p"
	.string "It was never mine. It was only\n"
	.string "ever pointed somewhere.\p"
	.string "If it follows you, that is your\n"
	.string "burden now.$"

DaoDaoIsles_RocketLab_Text_Genesect:
	.string "The cannon on its back swivels\n"
	.string "and locks on.$"
