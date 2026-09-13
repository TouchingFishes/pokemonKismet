Gate_Route39_OlivineCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineGate_OnTransition
	.byte 0

@ VAR_OLIVINE_GATE_ROCKET
@   0 - the robbery is still happening
@   1 - the player broke it up, the band is not handed over yet
@   2 - the window closed unseen; she was robbed
@   3 - the player broke it up and has the band
@
@ The gate is the land route into Olivine, but a player with SURF can come in by
@ water through Olivine Bay and never pass through here. Rather than block that,
@ the scene simply expires: once Chuck is beaten the robbery is long over.
OlivineGate_OnTransition:
	goto_if_ne VAR_OLIVINE_GATE_ROCKET, 0, OlivineGate_OnTransition_Done
	goto_if_set FLAG_BADGE05_GET, OlivineGate_EventScript_ExpireScene
OlivineGate_OnTransition_Done:
	return

OlivineGate_EventScript_ExpireScene:
	setvar VAR_OLIVINE_GATE_ROCKET, 2
	setflag FLAG_HIDE_OLIVINE_GATE_ROCKET
	return

@ Two entrances, so the scene has to start from either end of the corridor.
@ Both face the player at the pair before handing off to the shared body.
OlivineGate_Trigger_FromRoute39::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto OlivineGate_EventScript_Robbery
	end

OlivineGate_Trigger_FromOlivine::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto OlivineGate_EventScript_Robbery
	end

OlivineGate_EventScript_Robbery::
	playse SE_PIN
	applymovement LOCALID_OLIVINE_GATE_ROCKET, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	msgbox OlivineGate_Text_RocketThreat, MSGBOX_DEFAULT
	closemessage
	msgbox OlivineGate_Text_WomanPlea, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_OLIVINE_GATE_ROCKET, DIR_EAST
	delay 16
	msgbox OlivineGate_Text_RocketNotice, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_33_HNS, OlivineGate_Text_RocketBeaten
	msgbox OlivineGate_Text_RocketFlee, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketFlee
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_OLIVINE_GATE_ROCKET
	setflag FLAG_HIDE_OLIVINE_GATE_ROCKET
	setvar VAR_OLIVINE_GATE_ROCKET, 1
	delay 20
	turnobject LOCALID_OLIVINE_GATE_WOMAN, DIR_EAST
	msgbox OlivineGate_Text_WomanThanks, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

OlivineGate_Movement_RocketFlee:
	walk_in_place_right
	step_end

OlivineGate_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_GATE_ROCKET, 1, OlivineGate_EventScript_GiveBand
	goto_if_eq VAR_OLIVINE_GATE_ROCKET, 2, OlivineGate_EventScript_WomanRobbed
	goto_if_eq VAR_OLIVINE_GATE_ROCKET, 3, OlivineGate_EventScript_WomanAfter
	msgbox OlivineGate_Text_WomanPlea, MSGBOX_DEFAULT
	release
	end

OlivineGate_EventScript_GiveBand::
	msgbox OlivineGate_Text_WomanOffersBand, MSGBOX_DEFAULT
	giveitem ITEM_MUSCLE_BAND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_OLIVINE_GATE_ROCKET, 3
	msgbox OlivineGate_Text_WomanGaveBand, MSGBOX_DEFAULT
	release
	end

OlivineGate_EventScript_WomanAfter::
	msgbox OlivineGate_Text_WomanAfter, MSGBOX_DEFAULT
	release
	end

OlivineGate_EventScript_WomanRobbed::
	msgbox OlivineGate_Text_WomanRobbed, MSGBOX_DEFAULT
	release
	end

@ Reachable only if the player walks up and talks to him before the trigger
@ tiles fire, which the coord_event placement makes unlikely but not impossible.
OlivineGate_EventScript_Rocket::
	lock
	faceplayer
	msgbox OlivineGate_Text_RocketNotice, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_33_HNS, OlivineGate_Text_RocketBeaten
	msgbox OlivineGate_Text_RocketFlee, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketFlee
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_OLIVINE_GATE_ROCKET
	setflag FLAG_HIDE_OLIVINE_GATE_ROCKET
	setvar VAR_OLIVINE_GATE_ROCKET, 1
	release
	end


OlivineGate_Text_RocketThreat:
	.string "Hand it over, granny.\p"
	.string "That's a nice band your POKéMON\n"
	.string "is wearing. Too nice for you.$"

OlivineGate_Text_WomanPlea:
	.string "Oh, please, somebody!\p"
	.string "My husband gave me that!$"

OlivineGate_Text_RocketNotice:
	.string "What are you looking at?\p"
	.string "Walk on by, kid. This is TEAM\n"
	.string "ROCKET business.$"

OlivineGate_Text_RocketBeaten:
	.string "Where did you come from?!$"

OlivineGate_Text_RocketFlee:
	.string "Keep the junk! It wasn't worth\n"
	.string "the trouble!$"

OlivineGate_Text_WomanThanks:
	.string "Oh, thank you, dear. Thank you.\p"
	.string "I thought nobody used this gate\n"
	.string "any more.\p"
	.string "Come here a moment. I want\n"
	.string "you to have something.$"

OlivineGate_Text_WomanOffersBand:
	.string "My husband trained here, years\n"
	.string "ago. He gave me this.\p"
	.string "It should be on a POKéMON that\n"
	.string "still has fights ahead of it.$"

OlivineGate_Text_WomanGaveBand:
	.string "Look after it, and after that\n"
	.string "POKéMON of yours.$"

OlivineGate_Text_WomanAfter:
	.string "Off you go, dear. OLIVINE is just\n"
	.string "down the road.\p"
	.string "Mind the sea wind.$"

OlivineGate_Text_WomanRobbed:
	.string "A TEAM ROCKET man cornered me in\n"
	.string "here, a while back.\p"
	.string "He took the band my husband gave\n"
	.string "me and ran off toward the water.\p"
	.string "Nobody came. That's all right.\n"
	.string "Nobody uses this gate any more.$"
