Route15_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE_HNS, Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY_HNS, Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten, Route15_EventScript_RegisterHillary
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchHillary
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterHillary::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_HillaryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HILLARY_HNS
	release
	end

Route15_EventScript_RematchHillary::
	trainerbattle_rematch TRAINER_HILLARY_HNS, Route15_Text_HillaryRematchIntro, Route15_Text_HillaryRematchDefeat
	msgbox Route15_Text_HillaryPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_HILLARY_2_HNS, Route15_EventScript_RematchHillaryTryGiveItem
	end

Route15_EventScript_RematchHillaryTryGiveItem::
	checkitem ITEM_TM_ENERGY_BALL
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_ENERGY_BALL
	closemessage
	end

Route15_EventScript_Kippi::
	trainerbattle_single TRAINER_KIPPI_HNS, Route15_Text_SchoolgirlKippiSeen, Route15_Text_SchoolgirlKippiBeaten
	msgbox Route15_Text_SchoolgirlKippiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Thea::
	trainerbattle_single TRAINER_THEA_HNS, Route15_Text_SchoolgirlTheaSeen, Route15_Text_SchoolgirlTheaBeaten
	msgbox Route15_Text_SchoolgirlTheaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Joanna::
	trainerbattle_single TRAINER_JOANNA_HNS, Route15_Text_SchoolgirlJoannaSeen, Route15_Text_SchoolgirlJoannaBeaten
	msgbox Route15_Text_SchoolgirlJoannaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billie::
	trainerbattle_single TRAINER_BILLIE_HNS, Route15_Text_SchoolgirlBillieSeen, Route15_Text_SchoolgirlBillieBeaten, Route15_EventScript_RegisterBillie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchBillie
	msgbox Route15_Text_SchoolgirlBillieAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterBillie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BillieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLIE_HNS
	release
	end

Route15_EventScript_RematchBillie::
	trainerbattle_rematch TRAINER_BILLIE_HNS, Route15_Text_BillieRematchIntro, Route15_Text_BillieRematchDefeat
	msgbox Route15_Text_BilliePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_BILLIE_2_HNS, Route15_EventScript_RematchBillieTryGiveItem
	end

Route15_EventScript_RematchBillieTryGiveItem::
	checkitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_FACADE
	closemessage
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "Have you forgotten anything?$"

Route15_Text_TeacherColetteBeaten:
	.string "Kyaaah!$"

Route15_Text_TeacherColetteAfterBattle:
	.string "Before I became a teacher, I used\n"
	.string "to forget a lot of things.$"

Route15_Text_TeacherHillarySeen:
	.string "On sunny days, I think that the\n"
	.string "kids would rather be playing in the\l"
	.string "schoolyard than studying in class.$"

Route15_Text_TeacherHillaryBeaten:
	.string "I didn't want to lose…$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "Studying is important, but\n"
	.string "exercise is just as vital.$"

Route15_Text_HillaryRegister:
	.string "You've taught me a lesson!\n"
	.string "May I have your number?$"

Route15_Text_HillaryRematchIntro:
	.string "I'll school you this time!$"

Route15_Text_HillaryRematchDefeat:
	.string "Back to the drawing board…$"

Route15_Text_HillaryPostRematch:
	.string "Teaching POKéMON is just like\n"
	.string "teaching children. Patience!$"

Route15_Text_SchoolgirlKippiSeen:
	.string "Hang on. I have to phone my mom.$"

Route15_Text_SchoolgirlKippiBeaten:
	.string "Sorry, Mom! I was beaten!$"

Route15_Text_SchoolgirlKippiAfterBattle:
	.string "My mom worries so much about me, I\n"
	.string "have to phone her all the time.$"

Route15_Text_SchoolgirlTheaSeen:
	.string "Let's battle. I won't lose!$"

Route15_Text_SchoolgirlTheaBeaten:
	.string "I forgot to do my homework!$"

Route15_Text_SchoolgirlTheaAfterBattle:
	.string "Sayonara! I just learned that in\n"
	.string "my Japanese class.$"

Route15_Text_SchoolgirlJoannaSeen:
	.string "We're on a field trip to LAVENDER\n"
	.string "RADIO TOWER for social studies.$"

Route15_Text_SchoolgirlJoannaBeaten:
	.string "You're wickedly tough!$"

Route15_Text_SchoolgirlJoannaAfterBattle:
	.string "I'm tired of walking. I need to\n"
	.string "take a break.$"

Route15_Text_SchoolgirlBillieSeen:
	.string "My favorite class is Gym!$"

Route15_Text_SchoolgirlBillieBeaten:
	.string "Oh, no! How could I lose?$"

Route15_Text_SchoolgirlBillieAfterBattle:
	.string "If POKéMON were a subject at\n"
	.string "school, I'd be the best!$"

Route15_Text_BillieRegister:
	.string "I should've paid more attention in class.\n"
	.string "Can I have your number?$"

Route15_Text_BillieRematchIntro:
	.string "I've been studying hard!\n"
	.string "Let me show you what I learned!$"

Route15_Text_BillieRematchDefeat:
	.string "I need to study more…$"

Route15_Text_BilliePostRematch:
	.string "Book smarts aren't everything.\n"
	.string "I need battle experience too!$"

Route15_Text_Sign:
	.string "ROUTE 15\p"
	.string "FUCHSIA CITY - LAVENDER TOWN$"

