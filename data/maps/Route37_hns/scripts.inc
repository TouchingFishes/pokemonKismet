Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	setflag FLAG_HIDE_ROUTE37_SHADOW
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	specialvar VAR_RESULT, ScriptGetWeekDay
	goto_if_ne VAR_RESULT, WEEKDAY_SUN, Route37_EventScript_SunnyNope
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	goto Route37_EventScript_SunnyYes
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "ANN: ANNE and I are in this\n"
	.string "together!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "ANN & ANNE: Nnn… A little too\n"
	.string "strong.$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "ANN: I can tell what my sister and\n"
	.string "my POKéMON are thinking.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "ANNE: ANN and I are in this\n"
	.string "together!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "ANN & ANNE: Nnn… A little too\n"
	.string "strong.$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "ANNE: We share the same feelings as\n"
	.string "our POKéMON.$"

Route37_Text_PsychicGreg_Seen:
	.string "POKéMON can't do a thing if they are\n"
	.string "asleep.\p"
	.string "I'll show you how scary that is!$"

Route37_Text_PsychicGreg_Beaten:
	.string "I lost. That's pretty sad…$"

Route37_Text_PsychicGreg_After:
	.string "Putting POKéMON to sleep or paralyz-\n"
	.string "ing them are good battle techniques.$"

Route37_Text_Sunny_Meet:
	.string "SUNNY: Hi!\p"
	.string "I'm SUNNY of the WEEKDAY family!\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"

Route37_Text_Sunny_GiveGift1:
	.string "I was told to give you this if I saw\n"
	.string "you!$"

Route37_Text_Sunny_GiveGift2:
	.string "I was told to give you this if I saw\n"
	.string "you!$"

Route37_Text_Sunny_GaveGift:
	.string "SUNNY: That thing…\p"
	.string "Um…\p"
	.string "… What was it now…\p"
	.string "…\p"
	.string "Oh! I remember now!\p"
	.string "A POKéMON that knows electric\n"
	.string "moves should hold it.\p"
	.string "My sis MONICA said it powers up\n"
	.string "electric moves!$"

Route37_Text_Sunny_Sunday:
	.string "SUNNY: My sisters and brothers are\n"
	.string "MONICA, TUSCANY, WESLEY, ARTHUR,\l"
	.string "FRIEDA and SANTOS.\p"
	.string "They're all older than me!$"

Route37_Text_Sunny_NotSunday:
	.string "SUNNY: Isn't today Sunday?\n"
	.string "Um… I forgot!$"

Route37_Text_Sign:
	.string "ROUTE 37\n"
	.string "ECRUTEAK CITY AHEAD$"

Route37_EventScript_BreederFAmala::
	trainerbattle_single TRAINER_AMALA_HNS, Route37_Text_BreederFAmala_Seen, Route37_Text_BreederFAmala_Beaten
	msgbox Route37_Text_BreederFAmala_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_ChannelerMercy::
	trainerbattle_single TRAINER_MERCY_HNS, Route37_Text_ChannelerMercy_Seen, Route37_Text_ChannelerMercy_Beaten
	msgbox Route37_Text_ChannelerMercy_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_BugManiacDale::
	trainerbattle_single TRAINER_DALE_HNS, Route37_Text_BugManiacDale_Seen, Route37_Text_BugManiacDale_Beaten
	msgbox Route37_Text_BugManiacDale_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_BugCatcherMicky::
	trainerbattle_single TRAINER_MICKY_HNS, Route37_Text_BugCatcherMicky_Seen, Route37_Text_BugCatcherMicky_Beaten
	msgbox Route37_Text_BugCatcherMicky_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_CamperJordan::
	trainerbattle_single TRAINER_JORDAN_HNS, Route37_Text_CamperJordan_Seen, Route37_Text_CamperJordan_Beaten
	msgbox Route37_Text_CamperJordan_After, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_Item_GrassKnot::
	finditem ITEM_TM_GRASS_KNOT
	end

Route37_Text_BreederFAmala_Seen::
	.string "Certain POKéMON can only evolve\p"
	.string "if someone truly cares for them.\n"
	.string "Care can overcome any obstacle,\n"
	.string "I'll show you.$"
	
Route37_Text_BreederFAmala_Beaten::
	.string "What a caring display.$"

Route37_Text_BreederFAmala_After::
	.string "Raising POKéMON isn't just about\n"
	.string "making them stronger.\p"
	.string "The trust you build together is\n"
	.string "what wins the toughest battles.$"

Route37_Text_ChannelerMercy_Seen::
	.string "Can you feel it?\p"
	.string "The forest whispers to believers.\n"
	.string "Even SHUPPET is listening.\p"
	.string "Come. Let the spirits judge\n"
	.string "our battle.$"

Route37_Text_ChannelerMercy_Beaten::
	.string "The forest has spoken...\n"
	.string "Today, it favored you.$"

Route37_Text_ChannelerMercy_After::
	.string "When the wind stirs the leaves,\n"
	.string "SHUPPET always looks up.\p"
	.string "Perhaps it hears voices that\n"
	.string "we've long forgotten.$"

Route37_Text_BugManiacDale_Seen::
	.string "Shh! Keep your voice down!\p"
	.string "I'm waiting for a rare BUG\n"
	.string "POKéMON to fall out of a tree.\p"
	.string "Since you're here anyway,\n"
	.string "let's battle while we wait!$"

Route37_Text_BugManiacDale_Beaten::
	.string "Aw, now I've scared them all\n"
	.string "away...$"

Route37_Text_BugManiacDale_After::
	.string "Headbutting trees is an art.\p"
	.string "You never know whether a common\n"
	.string "BUG or something truly rare will\l"
	.string "come tumbling down.$"

Route37_Text_BugCatcherMicky_Seen::
	.string "BUG POKéMON are the best!\p"
	.string "They're always hiding somewhere,\n"
	.string "just waiting to surprise you!\p"
	.string "Let's see if mine surprise you!$"

Route37_Text_BugCatcherMicky_Beaten::
	.string "Aw... I guess my bugs weren't\n"
	.string "sneaky enough.$"

Route37_Text_BugCatcherMicky_After::
	.string "People walk right past BUG\n"
	.string "POKéMON all the time.\p"
	.string "If you slow down and really look,\n"
	.string "they're everywhere!$"

Route37_Text_CamperJordan_Seen::
	.string "Isn't this forest awesome?\p"
	.string "I could spend all day looking\n"
	.string "at these colorful trees!\p"
	.string "A battle's even more fun with\n"
	.string "a view like this!$"

Route37_Text_CamperJordan_Beaten::
	.string "Whoa! That was as bright as\n"
	.string "the leaves overhead!$"

Route37_Text_CamperJordan_After::
	.string "Every season gives these trees\n"
	.string "new colors.\p"
	.string "No wonder so many POKéMON\n"
	.string "choose to live here.$"

Route37_EventScript_Item_HoneClaws::
	finditem ITEM_TM_HONE_CLAWS
	end

Route37_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE37_SHADOW
	addobject LOCALID_ROUTE37_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_ROUTE37_SHADOW, Route37_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE37_SHADOW
	removeobject LOCALID_ROUTE37_SHADOW
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 60
	@ BAOBA waits at (16,50), out of sight of the triggers at x=24, so he walks in beside
	@ the player first and only then reacts. VAR_TEMP_1 keeps the row for his exit.
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 48, Route37_EventScript_BaobaApproach48
	call_if_eq VAR_TEMP_1, 49, Route37_EventScript_BaobaApproach49
	call_if_eq VAR_TEMP_1, 50, Route37_EventScript_BaobaApproach50
	call_if_eq VAR_TEMP_1, 51, Route37_EventScript_BaobaApproach51
	playse SE_PIN
	applymovement LOCALID_ROUTE37_BAOBA, Common_Movement_QuestionMark
	waitmovement 0
	turnobject LOCALID_ROUTE37_BAOBA, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
Route37_EventScript_ChooseLegend::
	msgbox Route37_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_LegendaryTriggerGold
	case 1, Route37_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route37_EventScript_ChooseLegend
	release
	end

Route37_EventScript_BaobaApproach48:
	applymovement LOCALID_ROUTE37_BAOBA, Route37_Movement_BaobaApproach48
	waitmovement 0
	return

Route37_EventScript_BaobaApproach49:
	applymovement LOCALID_ROUTE37_BAOBA, Route37_Movement_BaobaApproach49
	waitmovement 0
	return

Route37_EventScript_BaobaApproach50:
	applymovement LOCALID_ROUTE37_BAOBA, Route37_Movement_BaobaApproach50
	waitmovement 0
	return

Route37_EventScript_BaobaApproach51:
	applymovement LOCALID_ROUTE37_BAOBA, Route37_Movement_BaobaApproach51
	waitmovement 0
	return

Route37_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route37_EventScript_BaobaIntro

Route37_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route37_EventScript_BaobaIntro

Route37_EventScript_BaobaIntro::
	msgbox Route37_Text_BaobaIntro, MSGBOX_DEFAULT
	playse MUS_HG_POKEGEAR_REGISTERED
	msgbox Route37_Text_Registered, MSGBOX_DEFAULT
	waitse
	msgbox Route37_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	@ Back up to row 48, then west along it and north out of view.
	call_if_eq VAR_TEMP_1, 49, Route37_EventScript_BaobaUp1
	call_if_eq VAR_TEMP_1, 50, Route37_EventScript_BaobaUp2
	call_if_eq VAR_TEMP_1, 51, Route37_EventScript_BaobaUp3
	applymovement LOCALID_ROUTE37_BAOBA, Route37_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_ROUTE37_BAOBA
	release
	end

Route37_EventScript_BaobaUp1:
	applymovement LOCALID_ROUTE37_BAOBA, Route37_Movement_BaobaUp1
	waitmovement 0
	return

Route37_EventScript_BaobaUp2:
	applymovement LOCALID_ROUTE37_BAOBA, Route37_Movement_BaobaUp2
	waitmovement 0
	return

Route37_EventScript_BaobaUp3:
	applymovement LOCALID_ROUTE37_BAOBA, Route37_Movement_BaobaUp3
	waitmovement 0
	return

Route37_Movement_BaobaApproach48:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route37_Movement_BaobaApproach49:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route37_Movement_BaobaApproach50:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route37_Movement_BaobaApproach51:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route37_Movement_BaobaUp1:
	walk_up
	step_end

Route37_Movement_BaobaUp2:
	walk_up
	walk_up
	step_end

Route37_Movement_BaobaUp3:
	walk_up
	walk_up
	walk_up
	step_end

Route37_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route37_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route37_Text_ChooseLegend::
	.string "BAOBA: GOOD HEAVENS! Did that\n"
	.string "shadow belong to a POKéMON?\p"
	.string "Did you get a good look at it?\n"
	.string "I can't tell what color it was...$"

Route37_Text_BaobaIntro::
	.string "How strange...\p"
	.string "...Ohh!\n"
	.string "What you are holding is...\l"
	.string "what they call... a POKéDEX!\p"
	.string "Haven't seen one of those in ages.\p"
	.string "My name is BAOBA!\n"
	.string "I used to run a SAFARI ZONE in\l"
	.string "FUCHSIA CITY, but it was becoming\l"
	.string "out of date with new entertainment\l"
	.string "options coming out.\p"
	.string "I decided to go overseas to learn\n"
	.string "the newest technology and open a\l"
	.string "state-of-the-art SAFARI ZONE\l"
	.string "in CIANWOOD.\p"
	.string "It may be more than a coincidence\n"
	.string "that we are chatting.\p"
	.string "Why don't we register each other's\n"
	.string "numbers in the POKéGEAR?\p"
	.string "I can give you a call once the\n"
	.string "SAFARI ZONE is open before I call\l"
	.string "anyone else!$"

Route37_Text_Registered:
	.string "{PLAYER} registered BAOBA\n"
	.string "in the POKéGEAR!$"

Route37_Text_WillCall:
	.string "BAOBA: I'll let you know\n"
	.string "on the POKéGEAR soon!$"
