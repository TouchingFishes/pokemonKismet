DaoDaoIsles_RocketLab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_RocketLab_OnTransition
	.byte 0

DaoDaoIsles_RocketLab_OnTransition:
	setflag FLAG_DAODAO_ROCKET_LAB_FOUND
	call DaoDaoIsles_RocketLab_SetGideon
	call DaoDaoIsles_RocketLab_SetGiovanni
	call DaoDaoIsles_RocketLab_SetGenesect
	end

DaoDaoIsles_RocketLab_SetGideon:
	setflag FLAG_HIDE_DAODAO_LAB_GIDEON
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GIDEON
	return

DaoDaoIsles_RocketLab_SetGiovanni:
	setflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	return

DaoDaoIsles_RocketLab_SetGenesect:
	setflag FLAG_HIDE_DAODAO_LAB_GENESECT
	goto_if_unset FLAG_DEFEATED_DAODAO_LAB_GIOVANNI, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GENESECT
	return

DaoDaoIsles_RocketLab_Ret:
	return

DaoDaoIsles_RocketLab_EventScript_Biker1::
	trainerbattle_single TRAINER_DAODAO_LAB_BIKER_1_HNS, DaoDaoIsles_RocketLab_Text_Biker1Intro, DaoDaoIsles_RocketLab_Text_Biker1Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Biker1Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Cueball1::
	trainerbattle_single TRAINER_DAODAO_LAB_CUEBALL_1_HNS, DaoDaoIsles_RocketLab_Text_Cueball1Intro, DaoDaoIsles_RocketLab_Text_Cueball1Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Cueball1Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Scientist1::
	trainerbattle_single TRAINER_DAODAO_LAB_SCIENTIST_1_HNS, DaoDaoIsles_RocketLab_Text_Scientist1Intro, DaoDaoIsles_RocketLab_Text_Scientist1Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Scientist1Post, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_RocketLab_EventScript_Biker2::
	trainerbattle_single TRAINER_DAODAO_LAB_BIKER_2_HNS, DaoDaoIsles_RocketLab_Text_Biker2Intro, DaoDaoIsles_RocketLab_Text_Biker2Defeat
	msgbox DaoDaoIsles_RocketLab_Text_Biker2Post, MSGBOX_AUTOCLOSE
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
	setvar VAR_FUCHSIA_FEDERATION_STATE, 8
	setflag FLAG_DEFEATED_DAODAO_LAB_GIDEON
	msgbox DaoDaoIsles_RocketLab_Text_GideonPostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GIDEON
	setflag FLAG_HIDE_DAODAO_LAB_GIDEON
	clearflag FLAG_HIDE_DAODAO_LAB_GIOVANNI
	addobject LOCALID_DAODAO_LAB_GIOVANNI
	fadescreenswapbuffers FADE_FROM_BLACK
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
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_GENESECT
	setflag FLAG_HIDE_DAODAO_LAB_GENESECT
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RocketLab_EventScript_GenesectStays::
	release
	end

DaoDaoIsles_RocketLab_Text_Biker1Intro:
	.string "Nobody's come down that stair in\n"
	.string "twenty years.\p"
	.string "Should've stayed that way!$"

DaoDaoIsles_RocketLab_Text_Biker1Defeat:
	.string "Ugh... my exhaust...$"

DaoDaoIsles_RocketLab_Text_Biker1Post:
	.string "We don't guard the crates.\p"
	.string "We guard the thing at the back.$"

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

DaoDaoIsles_RocketLab_Text_Biker2Intro:
	.string "Hey. HEY.\p"
	.string "You don't get to just walk in\n"
	.string "here and look around!$"

DaoDaoIsles_RocketLab_Text_Biker2Defeat:
	.string "Fine. Look. Whatever.$"

DaoDaoIsles_RocketLab_Text_Biker2Post:
	.string "Half of us only stayed because\n"
	.string "GIDEON did.$"

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
	.string "You.\p"
	.string "You pulled the FEDERATION apart in\n"
	.string "FUCHSIA and you still came out\l"
	.string "here after me.\p"
	.string "PAXTON shouted. I packed.\p"
	.string "Do you have any idea what we built\n"
	.string "in this room?$"

DaoDaoIsles_RocketLab_Text_GideonDefeat:
	.string "My work was sound!$"

DaoDaoIsles_RocketLab_Text_GideonPostBattle:
	.string "The FEDERATION was going to be my\n"
	.string "second chance. Clean work.\p"
	.string "It took about a month to turn into\n"
	.string "the same thing again.\p"
	.string "Tell JANINE it's finished. She has\n"
	.string "earned hearing it.\p"
	.string "The boss never left either.\n"
	.string "Go on. He's waiting.$"

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
