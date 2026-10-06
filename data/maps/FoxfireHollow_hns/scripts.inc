@ FOXFIRE HOLLOW - north of the Lake of Rage, through the trees beside the hermit's house.
@ The Ninetales story after anime EP232, "Just Waiting On a Friend". Progress is
@ VAR_FOXFIRE_HOLLOW_STATE (include/constants/vars_hns.h); the lodge holds the rest of it.
@ The way in is gated on Johto badges 1-7 by LakeOfRage_OnLoad.
FoxfireHollow_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FoxfireHollow_OnTransition
	.byte 0

@ The woman only exists inside the meeting below, so she is hidden on every load. The fog is
@ the Ninetales's own, and lifts for good once it has been caught or set free.
FoxfireHollow_OnTransition:
	setflag FLAG_TEMP_1
	call_if_ge VAR_FOXFIRE_HOLLOW_STATE, 6, FoxfireHollow_EventScript_FogLifted
	end

FoxfireHollow_EventScript_FogLifted:
	setweather WEATHER_NONE
	return

@ Both trigger tiles run this. Everything is placed from the player's own column.
FoxfireHollow_EventScript_WomanInTheFog::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	fadeoutbgm 0
	delay 30
	getplayerxy VAR_0x8004, VAR_0x8005
	subvar VAR_0x8005, 2
	call FoxfireHollow_EventScript_Foxfire
	subvar VAR_0x8005, 1
	call FoxfireHollow_EventScript_Foxfire
	subvar VAR_0x8005, 1
	call FoxfireHollow_EventScript_Foxfire
	delay 30
	@ She forms three tiles up, where the lights gathered. Hidden in the same frame she is
	@ added, so she never pops in before the flicker.
	addvar VAR_0x8005, 1
	setobjectxyperm LOCALID_FOXFIRE_HOLLOW_WOMAN, VAR_0x8004, VAR_0x8005
	clearflag FLAG_TEMP_1
	addobject LOCALID_FOXFIRE_HOLLOW_WOMAN
	hideobjectat LOCALID_FOXFIRE_HOLLOW_WOMAN, MAP_FOXFIRE_HOLLOW_HNS
	playse SE_M_MIST
	applymovement LOCALID_FOXFIRE_HOLLOW_WOMAN, FoxfireHollow_Movement_Materialise
	waitmovement 0
	playbgm MUS_HG_ENCOUNTER_KIMONO_GIRL, FALSE
	applymovement LOCALID_FOXFIRE_HOLLOW_WOMAN, FoxfireHollow_Movement_Approach
	waitmovement 0
	msgbox FoxfireHollow_Text_WomanInTheFog, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOXFIRE_HOLLOW_WOMAN, FoxfireHollow_Movement_Leave
	waitmovement 0
	playse SE_M_MIST
	applymovement LOCALID_FOXFIRE_HOLLOW_WOMAN, FoxfireHollow_Movement_Dissolve
	waitmovement 0
	removeobject LOCALID_FOXFIRE_HOLLOW_WOMAN
	delay 20
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	setvar VAR_FOXFIRE_HOLLOW_STATE, 1
	fadedefaultbgm
	releaseall
	end

FoxfireHollow_EventScript_Foxfire:
	playse SE_M_DETECT
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, 0
	delay 24
	return

@ Kecleon's flicker (data/scripts/kecleon.inc), weighted so she is mostly not there at first
@ and mostly there at the end. The Mansion's reveal dissolves the NINETALES with the second.
FoxfireHollow_Movement_Materialise:
	set_visible
	delay_2
	set_invisible
	delay_16
	set_visible
	delay_4
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_4
	set_visible
	delay_16
	set_invisible
	delay_2
	set_visible
	step_end

FoxfireHollow_Movement_Dissolve::
	set_invisible
	delay_2
	set_visible
	delay_16
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_4
	set_invisible
	delay_16
	set_visible
	delay_2
	set_invisible
	step_end

FoxfireHollow_Movement_Approach:
	walk_down
	walk_down
	step_end

@ Back up into the fog, and one look back at the player before she goes.
FoxfireHollow_Movement_Leave:
	walk_slow_up
	walk_slow_up
	face_down
	delay_16
	delay_16
	step_end

FoxfireHollow_Text_WomanInTheFog:
	.string "Oh! Someone's out in this?\p"
	.string "You'll walk straight into the lake\n"
	.string "in fog like this.\p"
	.string "There's a house just up the path.\n"
	.string "Come in and get warm.\p"
	.string "I'll go on ahead and see to the\n"
	.string "fire.$"
