DaoDaoIsles_RocketLab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_RocketLab_OnTransition
	.byte 0

DaoDaoIsles_RocketLab_OnTransition:
	call DaoDaoIsles_RocketLab_SetGideon
	call DaoDaoIsles_RocketLab_SetAssistant
	end

DaoDaoIsles_RocketLab_SetGideon:
	setflag FLAG_HIDE_DAODAO_LAB_GIDEON
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_Ret
	clearflag FLAG_HIDE_DAODAO_LAB_GIDEON
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
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

@ The stairs down to the generator hall (B1F, MIGRATION_DECISIONS.md 92), a trigger on (10,2): the
@ stair art there is plain floor to the engine, so the warp event only marks where B1F returns
@ the player. Shut while GIDEON still runs the lab.
DaoDaoIsles_RocketLab_EventScript_StairsDown::
	lockall
	goto_if_set FLAG_DEFEATED_DAODAO_LAB_GIDEON, DaoDaoIsles_RocketLab_EventScript_GoDownstairs
	msgbox DaoDaoIsles_RocketLab_Text_StairsNotYet, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, DaoDaoIsles_RocketLab_EventScript_StairsStepDown
	call_if_eq VAR_RESULT, DIR_EAST, DaoDaoIsles_RocketLab_EventScript_StairsStepLeft
	releaseall
	end

DaoDaoIsles_RocketLab_EventScript_GoDownstairs:
	warp MAP_DAO_DAO_ISLES_ROCKET_LAB_B1F_HNS, 0
	waitstate
	releaseall
	end

DaoDaoIsles_RocketLab_EventScript_StairsStepDown:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	return

DaoDaoIsles_RocketLab_EventScript_StairsStepLeft:
	applymovement OBJ_EVENT_ID_PLAYER, DaoDaoIsles_RocketLab_Movement_StepLeft
	waitmovement 0
	return

DaoDaoIsles_RocketLab_Movement_StepLeft:
	walk_left
	step_end

DaoDaoIsles_RocketLab_Text_StairsNotYet:
	.string "Something down there is grinding\n"
	.string "and turning…\p"
	.string "It would be unwise to go down\n"
	.string "while GIDEON is still around.$"

DaoDaoIsles_RocketLab_Notes::
	lock
	msgbox DaoDaoIsles_RocketLab_Text_Notes
	release
	end

DaoDaoIsles_RocketLab_Notes2::
	lock
	msgbox DaoDaoIsles_RocketLab_Text_Notes2
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
	.string "You dismantled my FEDERATION in\n"
	.string "FUCHSIA, and now you've come to\l"
	.string "tear my lab apart?!\p"
	.string "PAXTON was the muscle. He should\n"
	.string "have gotten me more specimens.\p"
	.string "Let's see if you understand\n"
	.string "what you're currently destroying.$"

DaoDaoIsles_RocketLab_Text_GideonDefeat:
	.string "Crude. Effective, but crude.$"

DaoDaoIsles_RocketLab_Text_GideonPostBattle:
	.string "Twenty years.\n"
	.string "That's how long I spent trying\l"
	.string "to build something of my own.\p"
	.string "I wanted one thing in twenty\n"
	.string "years that even GIOVANNI could\l"
	.string "never have.\p"	
	.string "I built the FEDERATION, hoping\n"
	.string "it could achieve what he never\l"
	.string "could.\p"
	.string "……………\n"
	.string "My finest work. The one thing\l"
	.string "I was truly proud of.\p"
	.string "He took it from me last year.\n"
	.string "Didn't even have the decency\l"
	.string "to pretend it was his to take.\p"
	.string "……………\n"
	.string "The machines haven't shut down\l"
	.string "once. Not in twenty years.\p"
	.string "And lately… there's something\n"
	.string "wrong with them.\p"
	.string "……………\n"
	.string "They almost seem alive. Not\l"
	.string "intelligent. Just… aware.\p"
	.string "As if something ancient has\n"
	.string "taken root in the machinery.\l"
	.string "Something that was here long\l"
	.string "before I ever built this place.\p"
	.string "I don't know what it wants.\n"
	.string "I only know it knows we're here.\p"
	.string "Don't go near it.$"

DaoDaoIsles_RocketLab_Text_Notes:
	.string "RESEARCH LOG - SPECIMEN G-0\p"
	.string "The fossil reconstruction is\n"
	.string "complete. The organism's original\l"
	.string "anatomy was insufficient for our\l"
	.string "intended applications.\p"
	.string "Armor plating has been integrated\n"
	.string "along the dorsal ridge. The cannon\l"
	.string "assembly is functional, though the\l"
	.string "specimen's response to commands\l"
	.string "remains inconsistent.\p"
	.string "GIDEON insists we stop calling it\n"
	.string "a reconstruction. In his words,\l"
	.string "we haven't restored the creature.\l"
	.string "We've made it something new.\p"
	.string "I have concerns about the energy\n"
	.string "source. The readings don't match\l"
	.string "any known power system. They rise\l"
	.string "whenever the gears begin turning.\p"
	.string "Speaking of which, the KLINKLANG\n"
	.string "has moved again. No one saw it\l"
	.string "enter the lab. No one can explain\l"
	.string "how it keeps running without fuel.\p"
	.string "Its gear markings match symbols\n"
	.string "found in the island ruins. The\l"
	.string "same symbols appear in the energy\l"
	.string "readings from Specimen G-0.\p"
	.string "GIDEON has ordered the KLINKLANG\n"
	.string "left undisturbed. He says it may\l"
	.string "be the key to understanding the\l"
	.string "technology beneath the ruins.\p"
	.string "I don't think it came here to be\n"
	.string "studied. Yesterday, I found it\l"
	.string "facing the sealed elevator.\p"
	.string "The elevator has no power.\n"
	.string "Something below it does.$"

DaoDaoIsles_RocketLab_Text_Notes2:
	.string "RESEARCH LOG - FOLLOW-UP\p"
	.string "Specimen G-0 reacted to the gear\n"
	.string "assembly again last night.\p"
	.string "The moment KLINKLANG began turning,\n"
	.string "every monitor in the chamber lit\l"
	.string "up. The specimen raised its head\l"
	.string "and tracked the sound.\p"
	.string "For three seconds, its readings\n"
	.string "matched the signal beneath the\l"
	.string "island. Not approximately. Exactly.\p"
	.string "We repeated the test with KLINKLANG\n"
	.string "removed from the room. Nothing.\l"
	.string "We tried a recording of its gears.\l"
	.string "Nothing.\p"
	.string "It has to be present. The real\n"
	.string "thing. As though the specimen is\l"
	.string "waiting for a signal it remembers.\p"
	.string "GIDEON ordered the experiment sealed\n"
	.string "and all copies of the readings\l"
	.string "transferred to his private archive.\p"
	.string "I asked whether the ruins might\n"
	.string "have contained something like G-0.\l"
	.string "He told me the ruins predate every\l"
	.string "known record of civilization here.\p"
	.string "Then he asked me a question I\n"
	.string "haven't been able to forget:\l"
	.string "“What if we didn't invent the weapon?\l"
	.string "What if we only reminded it?”\p"
	.string "KLINKLANG is outside the chamber\n"
	.string "again. Its gears have stopped.\p"
	.string "Something beneath the floor has\n"
	.string "started turning.$"
