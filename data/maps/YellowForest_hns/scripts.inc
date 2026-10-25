YellowForest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, YellowForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

YellowForest_OnTransition:
	callnative SetTimeBasedEncounters
	call_if_unset FLAG_HIDE_YELLOW_FOREST_PIKACHU, YellowForest_EventScript_HideLightBall
	call_if_unset FLAG_DEFEATED_RED, YellowForest_EventScript_HidePikachu
	call_if_set FLAG_HIDE_YELLOW_FOREST_PIKACHU, YellowForest_EventScript_HidePikachu
	end

@ The Pikachu sleeps here only once RED is beaten. FLAG_TEMP_12 is its object flag, worked out on
@ every load; FLAG_HIDE_YELLOW_FOREST_PIKACHU stays the permanent record of its battle.
YellowForest_EventScript_HidePikachu:
	setflag FLAG_TEMP_12
	return

@ The LIGHT BALL ball only shows once the Pikachu has run off without being caught.
YellowForest_EventScript_HideLightBall:
	setflag FLAG_ITEM_YELLOW_FOREST_LIGHT_BALL
	return

YellowForest_EventScript_Sarah::
	trainerbattle_single TRAINER_YELLOW_FOREST_SARAH_HNS, YellowForest_Text_SarahSeen, YellowForest_Text_SarahBeaten
	msgbox YellowForest_Text_SarahAfter, MSGBOX_AUTOCLOSE
	end

YellowForest_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_HNS, YellowForest_Text_IsabelSeen, YellowForest_Text_IsabelBeaten
	msgbox YellowForest_Text_IsabelAfter, MSGBOX_AUTOCLOSE
	end

YellowForest_EventScript_Kathryn::
	trainerbattle_single TRAINER_KATHRYN_HNS, YellowForest_Text_KathrynSeen, YellowForest_Text_KathrynBeaten
	msgbox YellowForest_Text_KathrynAfter, MSGBOX_AUTOCLOSE
	end

YellowForest_EventScript_Sophie::
	trainerbattle_single TRAINER_SOPHIE_HNS, YellowForest_Text_SophieSeen, YellowForest_Text_SophieBeaten
	msgbox YellowForest_Text_SophieAfter, MSGBOX_AUTOCLOSE
	end

YellowForest_Text_SarahSeen:
	.string "Whoa, a TRAINER!\n"
	.string "Let's have a battle!$"

YellowForest_Text_SarahBeaten:
	.string "Aww…\n"
	.string "I can't believe I lost!$"

YellowForest_Text_SarahAfter:
	.string "If we were back at school,\n"
	.string "I'd totally beat you!$"

YellowForest_Text_IsabelSeen:
	.string "Do you have any cute POKéMON\n"
	.string "like the ones around here?$"

YellowForest_Text_IsabelBeaten:
	.string "Wow! Your POKéMON are\n"
	.string "super strong!$"

YellowForest_Text_IsabelAfter:
	.string "We're learning how POKéMON\n"
	.string "live and grow together\l"
	.string "out here in the wild.$"

YellowForest_Text_KathrynSeen:
	.string "Hey, you!\n"
	.string "You're a TRAINER?\p"
	.string "Just don't go making\n"
	.string "my students cry!$"

YellowForest_Text_KathrynBeaten:
	.string "I'm not going to cry…\n"
	.string "Not over a little loss…$"

YellowForest_Text_KathrynAfter:
	.string "Looking after everyone\n"
	.string "on a field trip is\l"
	.string "no easy task.$"

YellowForest_Text_SophieSeen:
	.string "Did you know PIKACHU\n"
	.string "is an evolved POKéMON?$"

YellowForest_Text_SophieBeaten:
	.string "I knew it!$"

YellowForest_Text_SophieAfter:
	.string "Sometimes PIKACHU use their\n"
	.string "electric shocks to wake up\l"
	.string "POKéMON that have fainted.\p"
	.string "Isn't that just adorable?$"

YellowForest_EventScript_Norman::
	lock
	faceplayer
	goto_if_defeated TRAINER_LEADER_NORMAN_HNS, YellowForest_EventScript_NormanAfter
	msgbox YellowForest_Text_NormanIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_NORMAN_HNS, YellowForest_Text_NormanDefeat
	msgbox YellowForest_Text_NormanPostBattle, MSGBOX_DEFAULT
	release
	end

YellowForest_EventScript_NormanAfter:
	msgbox YellowForest_Text_NormanAfter, MSGBOX_DEFAULT
	release
	end

YellowForest_EventScript_Item_LightBall::
	finditem ITEM_LIGHT_BALL
	end

YellowForest_EventScript_Item_BigRoot::
	finditem ITEM_BIG_ROOT
	end

YellowForest_Text_NormanIntro:
	.string "I'm NORMAN, the GYM LEADER of\n"
	.string "PETALBURG CITY in HOENN.\p"
	.string "I came to JOHTO to train where\n"
	.string "my POKéMON can't get lazy.\p"
	.string "You look like a TRAINER who\n"
	.string "has earned a few BADGES.\p"
	.string "Show me what JOHTO has\n"
	.string "taught you!$"

YellowForest_Text_NormanDefeat:
	.string "I see…\n"
	.string "You've earned that win.$"

YellowForest_Text_NormanPostBattle:
	.string "Strength isn't only power.\p"
	.string "It's how far you and your\n"
	.string "POKéMON are willing to grow\l"
	.string "together.$"

YellowForest_Text_NormanAfter:
	.string "Even my SLAKING trains hard\n"
	.string "in a forest like this one.\p"
	.string "Well, when it's awake.$"

YellowForest_EventScript_Pikachu::
	lock
	msgbox YellowForest_Text_PikachuAsleep, MSGBOX_DEFAULT
	playmoncry SPECIES_PIKACHU, 0
	msgbox YellowForest_Text_PikachuWoke, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setwildbattle SPECIES_PIKACHU, 45, ITEM_LIGHT_BALL
	createmon 1, 0, SPECIES_PIKACHU, 45, item=ITEM_LIGHT_BALL, move1=MOVE_VOLT_TACKLE, move2=MOVE_THUNDERBOLT, move3=MOVE_IRON_TAIL, move4=MOVE_QUICK_ATTACK
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, YellowForest_EventScript_PikachuCaught
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, YellowForest_EventScript_PikachuStays
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, YellowForest_EventScript_PikachuStays
	@ fainted or ran: it dashes off and leaves the LIGHT BALL where it slept
	getobjectxy LOCALID_YELLOW_FOREST_PIKACHU, TEMPLATE_POSITION, VAR_0x8004, VAR_0x8005
	setflag FLAG_HIDE_YELLOW_FOREST_PIKACHU
	removeobject LOCALID_YELLOW_FOREST_PIKACHU
	setobjectxyperm LOCALID_YELLOW_FOREST_LIGHT_BALL, VAR_0x8004, VAR_0x8005
	clearflag FLAG_ITEM_YELLOW_FOREST_LIGHT_BALL
	addobject LOCALID_YELLOW_FOREST_LIGHT_BALL
	msgbox YellowForest_Text_PikachuDashedOff, MSGBOX_DEFAULT
	release
	end

YellowForest_EventScript_PikachuCaught:
	setflag FLAG_HIDE_YELLOW_FOREST_PIKACHU
	removeobject LOCALID_YELLOW_FOREST_PIKACHU
	release
	end

YellowForest_EventScript_PikachuStays:
	release
	end

YellowForest_Text_PikachuAsleep:
	.string "A PIKACHU is curled up, fast asleep.\p"
	.string "Something round and glowing is\n"
	.string "tucked under its tail…$"

YellowForest_Text_PikachuWoke:
	.string "Pika?!$"

YellowForest_Text_PikachuDashedOff:
	.string "The PIKACHU dashed off into the\n"
	.string "trees…\p"
	.string "It left something shiny behind!$"
