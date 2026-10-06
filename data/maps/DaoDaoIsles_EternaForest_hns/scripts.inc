@ The doll shrine where the Mansion used to stand (MIGRATION_DECISIONS.md 60). People leave old
@ dolls here. Three of them are rag PIKACHU, and one of those is a MIMIKYU: the only one that
@ ever turns its head. VAR_DOLL_SHRINE_STATE (include/constants/vars_hns.h) remembers who has it.
DaoDaoIsles_EternaForest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_EternaForest_OnTransition
	.byte 0

@ KAREN and the three rags share FLAG_TEMP_1: there until the MIMIKYU has gone with someone.
DaoDaoIsles_EternaForest_OnTransition:
	setflag FLAG_TEMP_1
	goto_if_ne VAR_DOLL_SHRINE_STATE, 0, DaoDaoIsles_EternaForest_EventScript_ShrineQuiet
	clearflag FLAG_TEMP_1
	call DaoDaoIsles_EternaForest_EventScript_DealDolls
DaoDaoIsles_EternaForest_EventScript_ShrineQuiet:
	end

@ The rags trade places on every visit and after every wrong guess. Both the templates and the
@ live objects move, so it works from ON_TRANSITION (nothing spawned yet) and mid-scene.
DaoDaoIsles_EternaForest_EventScript_DealDolls:
	random 3
	switch VAR_RESULT
	case 0, DaoDaoIsles_EternaForest_EventScript_DealLeft
	case 1, DaoDaoIsles_EternaForest_EventScript_DealMiddle
	goto DaoDaoIsles_EternaForest_EventScript_DealRight

DaoDaoIsles_EternaForest_EventScript_DealLeft:
	setvar VAR_0x8004, 18
	setvar VAR_0x8005, 11
	setvar VAR_0x8006, 21
	setvar VAR_0x8007, 12
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, 11
	goto DaoDaoIsles_EternaForest_EventScript_PlaceDolls

DaoDaoIsles_EternaForest_EventScript_DealMiddle:
	setvar VAR_0x8004, 21
	setvar VAR_0x8005, 12
	setvar VAR_0x8006, 18
	setvar VAR_0x8007, 11
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, 11
	goto DaoDaoIsles_EternaForest_EventScript_PlaceDolls

DaoDaoIsles_EternaForest_EventScript_DealRight:
	setvar VAR_0x8004, 24
	setvar VAR_0x8005, 11
	setvar VAR_0x8006, 18
	setvar VAR_0x8007, 11
	setvar VAR_0x8008, 21
	setvar VAR_0x8009, 12
DaoDaoIsles_EternaForest_EventScript_PlaceDolls:
	setobjectxyperm LOCALID_ETERNA_FOREST_MIMIKYU, VAR_0x8004, VAR_0x8005
	setobjectxy LOCALID_ETERNA_FOREST_MIMIKYU, VAR_0x8004, VAR_0x8005
	setobjectxyperm LOCALID_ETERNA_FOREST_RAG_1, VAR_0x8006, VAR_0x8007
	setobjectxy LOCALID_ETERNA_FOREST_RAG_1, VAR_0x8006, VAR_0x8007
	setobjectxyperm LOCALID_ETERNA_FOREST_RAG_2, VAR_0x8008, VAR_0x8009
	setobjectxy LOCALID_ETERNA_FOREST_RAG_2, VAR_0x8008, VAR_0x8009
	return

DaoDaoIsles_EternaForest_EventScript_Karen::
	lock
	faceplayer
	msgbox DaoDaoIsles_EternaForest_Text_KarenHint, MSGBOX_DEFAULT
	closemessage
	release
	end

DaoDaoIsles_EternaForest_EventScript_EmptyRag::
	lockall
	msgbox DaoDaoIsles_EternaForest_Text_EmptyRag, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_MIMIKYU, CRY_MODE_HIGH_PITCH
	waitmoncry
	call DaoDaoIsles_EternaForest_EventScript_Reshuffle
	releaseall
	end

DaoDaoIsles_EternaForest_EventScript_Reshuffle:
	fadescreenswapbuffers FADE_TO_BLACK
	call DaoDaoIsles_EternaForest_EventScript_DealDolls
	fadescreenswapbuffers FADE_FROM_BLACK
	return

DaoDaoIsles_EternaForest_EventScript_Mimikyu::
	lockall
	playse SE_PIN
	applymovement LOCALID_ETERNA_FOREST_MIMIKYU, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_MIMIKYU, CRY_MODE_NORMAL
	waitmoncry
	msgbox DaoDaoIsles_EternaForest_Text_ItMoved, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ETERNA_FOREST_KAREN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox DaoDaoIsles_EternaForest_Text_KarenFound, MSGBOX_DEFAULT
	msgbox DaoDaoIsles_EternaForest_Text_LetItGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_EternaForest_EventScript_KeepIt
	msgbox DaoDaoIsles_EternaForest_Text_KarenThanks, MSGBOX_DEFAULT
	giveitem ITEM_REAPER_CLOTH
	msgbox DaoDaoIsles_EternaForest_Text_KarenComeAlong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ETERNA_FOREST_MIMIKYU, DaoDaoIsles_EternaForest_Movement_Heart
	waitmovement 0
	goto DaoDaoIsles_EternaForest_EventScript_GoesWithKaren

@ NO: the player battles it. Caught, it is theirs; knocked out, KAREN takes it after all; if
@ the player runs, it hides among the dolls again.
DaoDaoIsles_EternaForest_EventScript_KeepIt:
	msgbox DaoDaoIsles_EternaForest_Text_KarenNo, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_MIMIKYU, 45
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DaoDaoIsles_EternaForest_EventScript_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DaoDaoIsles_EternaForest_EventScript_KnockedOut
	msgbox DaoDaoIsles_EternaForest_Text_SlippedBack, MSGBOX_DEFAULT
	closemessage
	call DaoDaoIsles_EternaForest_EventScript_Reshuffle
	releaseall
	end

DaoDaoIsles_EternaForest_EventScript_Caught:
	setvar VAR_DOLL_SHRINE_STATE, 2
	removeobject LOCALID_ETERNA_FOREST_MIMIKYU
	applymovement LOCALID_ETERNA_FOREST_KAREN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox DaoDaoIsles_EternaForest_Text_KarenCaught, MSGBOX_DEFAULT
	closemessage
	goto DaoDaoIsles_EternaForest_EventScript_KarenLeaves

DaoDaoIsles_EternaForest_EventScript_KnockedOut:
	applymovement LOCALID_ETERNA_FOREST_KAREN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox DaoDaoIsles_EternaForest_Text_KarenKnockedOut, MSGBOX_DEFAULT
	closemessage
DaoDaoIsles_EternaForest_EventScript_GoesWithKaren:
	setvar VAR_DOLL_SHRINE_STATE, 1
DaoDaoIsles_EternaForest_EventScript_KarenLeaves:
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ETERNA_FOREST_KAREN
	removeobject LOCALID_ETERNA_FOREST_MIMIKYU
	removeobject LOCALID_ETERNA_FOREST_RAG_1
	removeobject LOCALID_ETERNA_FOREST_RAG_2
	fadescreen FADE_FROM_BLACK
	releaseall
	end

DaoDaoIsles_EternaForest_Movement_Heart:
	emote_heart
	step_end

DaoDaoIsles_EternaForest_Text_KarenHint:
	.string "KAREN: People leave their old dolls\n"
	.string "here once they've stopped loving\l"
	.string "them.\p"
	.string "One of those rag dolls isn't a doll.\n"
	.string "It hides whenever I look for it.\p"
	.string "See if it will come out for you.$"

DaoDaoIsles_EternaForest_Text_EmptyRag:
	.string "A rag doll, stitched to look like a\n"
	.string "PIKACHU. It's empty.\p"
	.string "Something has been sleeping in it.$"

DaoDaoIsles_EternaForest_Text_ItMoved:
	.string "The rag doll's head flops over.\n"
	.string "It's a MIMIKYU!$"

DaoDaoIsles_EternaForest_Text_KarenFound:
	.string "KAREN: So that's where you were.\p"
	.string "Strong POKéMON. Weak POKéMON.\n"
	.string "That is only the selfish\l"
	.string "perception of people.\p"
	.string "It wears that rag so that someone\n"
	.string "will love it.\p"
	.string "Let me take it with me. I'll love\n"
	.string "it best of all.$"

DaoDaoIsles_EternaForest_Text_LetItGo:
	.string "Let the MIMIKYU go with KAREN?$"

DaoDaoIsles_EternaForest_Text_KarenThanks:
	.string "KAREN: Thank you.\p"
	.string "Here. Something for a kind trainer.$"

DaoDaoIsles_EternaForest_Text_KarenComeAlong:
	.string "KAREN: Come along, little one.$"

DaoDaoIsles_EternaForest_Text_KarenNo:
	.string "KAREN: Then show it you mean it.$"

DaoDaoIsles_EternaForest_Text_KarenCaught:
	.string "KAREN: It chose well.\p"
	.string "Look after it.$"

DaoDaoIsles_EternaForest_Text_KarenKnockedOut:
	.string "KAREN: Too rough.\p"
	.string "I'll take it from here. It will be\n"
	.string "well by the time we reach home.$"

DaoDaoIsles_EternaForest_Text_SlippedBack:
	.string "The MIMIKYU slipped back in among\n"
	.string "the dolls.$"
