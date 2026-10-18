Gate_Route39_OlivineCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineGate_OnTransition
	.byte 0

@ VAR_OLIVINE_GATE_ROCKET
@   0 - the robbery is still happening
@   1 - the player broke it up, the band is not handed over yet
@   2 - the window closed unseen; she was robbed
@   3 - the player broke it up and has the band
@   4 - New Bark's test NPC: the next load replays the robbery once, whatever
@       the badges (it sets all eight, which would expire the scene)
@
@ The gate is the land route into Olivine, but a player with SURF can come in by
@ water through Olivine Bay and never pass through here. Rather than block that,
@ the scene simply expires: once Chuck is beaten the robbery is long over.
OlivineGate_OnTransition:
	goto_if_eq VAR_OLIVINE_GATE_ROCKET, 4, OlivineGate_EventScript_TestReplay
	goto_if_ne VAR_OLIVINE_GATE_ROCKET, 0, OlivineGate_OnTransition_Done
	goto_if_set FLAG_BADGE05_GET, OlivineGate_EventScript_ExpireScene
OlivineGate_OnTransition_Done:
	return

OlivineGate_EventScript_ExpireScene:
	setvar VAR_OLIVINE_GATE_ROCKET, 2
	setflag FLAG_HIDE_OLIVINE_GATE_ROCKET
	return

OlivineGate_EventScript_TestReplay:
	setvar VAR_OLIVINE_GATE_ROCKET, 0
	clearflag FLAG_HIDE_OLIVINE_GATE_ROCKET
	return

@ Two entrances, so the scene has to start from either end of the corridor: the trigger rows
@ are y 3 (from ROUTE 39, the north door) and y 7 (from OLIVINE, the south door). The player
@ first steps into the middle column (x 7). From there every move is the same from both sides,
@ mirrored: the woman spots the player, the ROCKET walks up to him, and once beaten he
@ staggers back to (7,5) and runs out of the FAR door. The woman then comes over and hands the
@ band over on the spot.
@
@ VAR_0x8009 is the side, 0 north and 1 south. It is read again from the player's row after
@ the battle rather than trusted to survive it.
OlivineGate_Trigger_FromRoute39::
	lockall
	goto OlivineGate_EventScript_Robbery
	end

OlivineGate_Trigger_FromOlivine::
	lockall
	goto OlivineGate_EventScript_Robbery
	end

OlivineGate_EventScript_Robbery::
	hidefollower
	call OlivineGate_EventScript_GetSide
	call OlivineGate_EventScript_PlayerToMiddle
	@ The player walks in on it: the ROCKET lunges at her, she flinches.
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketLunge
	applymovement LOCALID_OLIVINE_GATE_WOMAN, OlivineGate_Movement_WomanFlinch
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	waitmovement LOCALID_OLIVINE_GATE_WOMAN
	msgbox OlivineGate_Text_RocketThreat, MSGBOX_DEFAULT
	closemessage
	@ She sees the player first...
	call_if_eq VAR_0x8009, 0, OlivineGate_EventScript_WomanFacesNorth
	call_if_eq VAR_0x8009, 1, OlivineGate_EventScript_WomanFacesSouth
	playse SE_PIN
	applymovement LOCALID_OLIVINE_GATE_WOMAN, OlivineGate_Movement_DoubleExclamation
	waitmovement LOCALID_OLIVINE_GATE_WOMAN
	msgbox OlivineGate_Text_WomanPlea, MSGBOX_DEFAULT
	closemessage
	@ ...and so does he.
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	call_if_eq VAR_0x8009, 0, OlivineGate_EventScript_RocketFacesNorth
	call_if_eq VAR_0x8009, 1, OlivineGate_EventScript_RocketFacesSouth
	playse SE_PIN
	applymovement LOCALID_OLIVINE_GATE_ROCKET, Common_Movement_ExclamationMark
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	call_if_eq VAR_0x8009, 0, OlivineGate_EventScript_RocketApproachNorth
	call_if_eq VAR_0x8009, 1, OlivineGate_EventScript_RocketApproachSouth
	msgbox OlivineGate_Text_RocketNotice, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_33_HNS, OlivineGate_Text_RocketBeaten
	call OlivineGate_EventScript_GetSide
	call_if_eq VAR_0x8009, 0, OlivineGate_EventScript_RocketStaggerSouth
	call_if_eq VAR_0x8009, 1, OlivineGate_EventScript_RocketStaggerNorth
	msgbox OlivineGate_Text_RocketFlee, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8009, 0, OlivineGate_EventScript_RocketBoltsSouth
	call_if_eq VAR_0x8009, 1, OlivineGate_EventScript_RocketBoltsNorth
	playse SE_EXIT
	removeobject LOCALID_OLIVINE_GATE_ROCKET
	setflag FLAG_HIDE_OLIVINE_GATE_ROCKET
	setvar VAR_OLIVINE_GATE_ROCKET, 1
	delay 20
	call_if_eq VAR_0x8009, 0, OlivineGate_EventScript_WomanToPlayerNorth
	call_if_eq VAR_0x8009, 1, OlivineGate_EventScript_WomanToPlayerSouth
	msgbox OlivineGate_Text_WomanThanks, MSGBOX_DEFAULT
	msgbox OlivineGate_Text_WomanOffersBand, MSGBOX_DEFAULT
	giveitem ITEM_MUSCLE_BAND
	goto_if_eq VAR_RESULT, FALSE, OlivineGate_EventScript_SceneBagFull
	setvar VAR_OLIVINE_GATE_ROCKET, 3
	msgbox OlivineGate_Text_WomanGaveBand, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ No room: VAR_OLIVINE_GATE_ROCKET stays 1, so talking to her later still hands it over.
OlivineGate_EventScript_SceneBagFull:
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

OlivineGate_EventScript_GetSide:
	getplayerxy VAR_0x8004, VAR_0x8005
	setvar VAR_0x8009, 0
	goto_if_le VAR_0x8005, 4, OlivineGate_EventScript_Ret
	setvar VAR_0x8009, 1
OlivineGate_EventScript_Ret:
	return

@ From the north the player can only reach row 3 at x 6-8 (row 2 is three tiles wide); from
@ the south any of x 5-9. VAR_0x8004 still holds the x GetSide read.
OlivineGate_EventScript_PlayerToMiddle:
	call_if_eq VAR_0x8004, 5, OlivineGate_EventScript_PlayerRight2
	call_if_eq VAR_0x8004, 6, OlivineGate_EventScript_PlayerRight1
	call_if_eq VAR_0x8004, 8, OlivineGate_EventScript_PlayerLeft1
	call_if_eq VAR_0x8004, 9, OlivineGate_EventScript_PlayerLeft2
	call_if_eq VAR_0x8009, 0, OlivineGate_EventScript_PlayerFacesSouth
	call_if_eq VAR_0x8009, 1, OlivineGate_EventScript_PlayerFacesNorth
	return

OlivineGate_EventScript_PlayerRight2:
	applymovement OBJ_EVENT_ID_PLAYER, OlivineGate_Movement_Right2
	waitmovement 0
	return

OlivineGate_EventScript_PlayerRight1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	return

OlivineGate_EventScript_PlayerLeft1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	return

OlivineGate_EventScript_PlayerLeft2:
	applymovement OBJ_EVENT_ID_PLAYER, OlivineGate_Movement_Left2
	waitmovement 0
	return

OlivineGate_EventScript_PlayerFacesSouth:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return

OlivineGate_EventScript_PlayerFacesNorth:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

OlivineGate_EventScript_WomanFacesNorth:
	turnobject LOCALID_OLIVINE_GATE_WOMAN, DIR_NORTH
	return

OlivineGate_EventScript_WomanFacesSouth:
	turnobject LOCALID_OLIVINE_GATE_WOMAN, DIR_SOUTH
	return

OlivineGate_EventScript_RocketFacesNorth:
	turnobject LOCALID_OLIVINE_GATE_ROCKET, DIR_NORTH
	return

OlivineGate_EventScript_RocketFacesSouth:
	turnobject LOCALID_OLIVINE_GATE_ROCKET, DIR_SOUTH
	return

@ From (6,5) to the tile in front of the player: (7,4) below him, or (7,6) above him.
OlivineGate_EventScript_RocketApproachNorth:
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketApproachNorth
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	return

OlivineGate_EventScript_RocketApproachSouth:
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketApproachSouth
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	return

@ Beaten, he backs off to (7,5) still facing the player...
OlivineGate_EventScript_RocketStaggerSouth:
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketStaggerSouth
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	return

OlivineGate_EventScript_RocketStaggerNorth:
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketStaggerNorth
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	return

@ ...and runs the four tiles to the door the player did not come in by.
OlivineGate_EventScript_RocketBoltsSouth:
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketBoltsSouth
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	return

OlivineGate_EventScript_RocketBoltsNorth:
	applymovement LOCALID_OLIVINE_GATE_ROCKET, OlivineGate_Movement_RocketBoltsNorth
	waitmovement LOCALID_OLIVINE_GATE_ROCKET
	return

@ She comes from (5,5) round to the tile in front of the player.
OlivineGate_EventScript_WomanToPlayerNorth:
	applymovement LOCALID_OLIVINE_GATE_WOMAN, OlivineGate_Movement_WomanToPlayerNorth
	waitmovement LOCALID_OLIVINE_GATE_WOMAN
	return

OlivineGate_EventScript_WomanToPlayerSouth:
	applymovement LOCALID_OLIVINE_GATE_WOMAN, OlivineGate_Movement_WomanToPlayerSouth
	waitmovement LOCALID_OLIVINE_GATE_WOMAN
	return

OlivineGate_Movement_Right2:
	walk_right
	walk_right
	step_end

OlivineGate_Movement_Left2:
	walk_left
	walk_left
	step_end

OlivineGate_Movement_RocketLunge:
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

OlivineGate_Movement_WomanFlinch:
	delay_8
	jump_in_place_right
	step_end

OlivineGate_Movement_DoubleExclamation:
	emote_double_exclamation_mark
	step_end

OlivineGate_Movement_RocketApproachNorth:
	walk_right
	walk_up
	step_end

OlivineGate_Movement_RocketApproachSouth:
	walk_right
	walk_down
	step_end

OlivineGate_Movement_RocketStaggerSouth:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	jump_in_place_up
	step_end

OlivineGate_Movement_RocketStaggerNorth:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	jump_in_place_down
	step_end

OlivineGate_Movement_RocketBoltsSouth:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

OlivineGate_Movement_RocketBoltsNorth:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

OlivineGate_Movement_WomanToPlayerNorth:
	walk_right
	walk_up
	walk_right
	face_up
	step_end

OlivineGate_Movement_WomanToPlayerSouth:
	walk_right
	walk_down
	walk_right
	face_down
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

@ A fallback only: both trigger rows span the whole corridor, so the player cannot reach
@ him without crossing one. The player could be on any side of him here, so he leaves under
@ a fade rather than along a fixed path.
OlivineGate_EventScript_Rocket::
	lock
	faceplayer
	msgbox OlivineGate_Text_RocketNotice, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_33_HNS, OlivineGate_Text_RocketBeaten
	msgbox OlivineGate_Text_RocketFlee, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	removeobject LOCALID_OLIVINE_GATE_ROCKET
	fadescreen FADE_FROM_BLACK
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
	.string "Here, I want you to have\n"
	.string "something.$"

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
