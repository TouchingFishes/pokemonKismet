@ The study at the bottom of the NINETALES's house. From state 5 it waits here, curled under the
@ master's desk beside the old POKe BALL, until it is caught or set free (state 6). After the
@ Hall of Fame, with the NINETALES gone, a MARSHADOW sits in the master's chair.
FoxfireHollow_Mansion_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FoxfireHollow_Mansion_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FoxfireHollow_Mansion_B1F_OnTransition
	.byte 0

FoxfireHollow_Mansion_B1F_OnTransition:
	call FoxfireHollow_Mansion_EventScript_Weather
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	call_if_eq VAR_FOXFIRE_HOLLOW_STATE, 5, FoxfireHollow_Mansion_B1F_EventScript_ShowNinetales
	call_if_lt VAR_FOXFIRE_HOLLOW_STATE, 6, FoxfireHollow_Mansion_B1F_EventScript_ShowOldBall
	call_if_eq VAR_FOXFIRE_HOLLOW_STATE, 6, FoxfireHollow_Mansion_B1F_EventScript_TryShowMarshadow
	end

FoxfireHollow_Mansion_B1F_EventScript_TryShowMarshadow:
	goto_if_set FLAG_CAUGHT_FOXFIRE_MANSION_MARSHADOW, FoxfireHollow_Mansion_B1F_EventScript_NoMarshadow
	goto_if_unset FLAG_SYS_GAME_CLEAR, FoxfireHollow_Mansion_B1F_EventScript_NoMarshadow
	clearflag FLAG_TEMP_3
FoxfireHollow_Mansion_B1F_EventScript_NoMarshadow:
	return

FoxfireHollow_Mansion_B1F_EventScript_ShowNinetales:
	clearflag FLAG_TEMP_1
	return

FoxfireHollow_Mansion_B1F_EventScript_ShowOldBall:
	clearflag FLAG_TEMP_2
	return

FoxfireHollow_Mansion_B1F_OnLoad::
	call_if_set FLAG_FOXFIRE_MANSION_SWITCH_STATE, FoxfireHollow_Mansion_EventScript_PressSwitch_B1F
	end

FoxfireHollow_Mansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call FoxfireHollow_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

FoxfireHollow_Mansion_B1F_EventScript_Ledger::
	msgbox FoxfireHollow_Mansion_B1F_Text_Ledger, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_B1F_EventScript_Loretta::
	trainerbattle_single TRAINER_MANSION_LORETTA_HNS, FoxfireHollow_Mansion_B1F_Text_LorettaIntro, FoxfireHollow_Mansion_B1F_Text_LorettaDefeat
	msgbox FoxfireHollow_Mansion_B1F_Text_LorettaPostBattle, MSGBOX_AUTOCLOSE
	end

FoxfireHollow_Mansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_MANSION_IVAN_HNS, FoxfireHollow_Mansion_B1F_Text_IvanIntro, FoxfireHollow_Mansion_B1F_Text_IvanDefeat
	msgbox FoxfireHollow_Mansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

FoxfireHollow_Mansion_B1F_Text_LorettaIntro::
	.string "Something down here is waiting\n"
	.string "for someone.\p"
	.string "It isn't waiting for you.$"

FoxfireHollow_Mansion_B1F_Text_LorettaDefeat::
	.string "Ohh… The spirits are cross\n"
	.string "with me now.$"

FoxfireHollow_Mansion_B1F_Text_LorettaPostBattle::
	.string "Whatever it is, it's been waiting\n"
	.string "a very long time.$"

FoxfireHollow_Mansion_B1F_Text_IvanIntro::
	.string "This place is ideal for a lab.\n"
	.string "Look at all this space.$"

FoxfireHollow_Mansion_B1F_Text_IvanDefeat::
	.string "What was that for?$"

FoxfireHollow_Mansion_B1F_Text_IvanPostBattle::
	.string "I like it here.\n"
	.string "It's conducive to my studies.$"

FoxfireHollow_Mansion_B1F_Text_Ledger::
	.string "An open ledger. Every line is in\n"
	.string "the same careful hand:\p"
	.string "“First snow. Fire lit.\n"
	.string "Not home yet.”\p"
	.string "The line repeats down every page,\n"
	.string "two hundred times over.$"

@ It turns in the chair to look at the player. Run from, it stays where it is; knocked out, it
@ sinks out of sight until the next visit; caught, it is gone for good.
FoxfireHollow_Mansion_B1F_EventScript_Marshadow::
	lock
	msgbox FoxfireHollow_Mansion_B1F_Text_AShadow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOXFIRE_MANSION_B1F_MARSHADOW, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FOXFIRE_MANSION_B1F_MARSHADOW, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_MARSHADOW, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbossbattle species=SPECIES_MARSHADOW, level=75, item=ITEM_SPELL_TAG, move1_1=MOVE_SPECTRAL_THIEF, move1_2=MOVE_CLOSE_COMBAT, move1_3=MOVE_SHADOW_SNEAK, move1_4=MOVE_DRAIN_PUNCH
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, FoxfireHollow_Mansion_B1F_EventScript_MarshadowCaught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FoxfireHollow_Mansion_B1F_EventScript_MarshadowSinks
	release
	end

FoxfireHollow_Mansion_B1F_EventScript_MarshadowCaught:
	setflag FLAG_CAUGHT_FOXFIRE_MANSION_MARSHADOW
	removeobject LOCALID_FOXFIRE_MANSION_B1F_MARSHADOW
	release
	end

FoxfireHollow_Mansion_B1F_EventScript_MarshadowSinks:
	removeobject LOCALID_FOXFIRE_MANSION_B1F_MARSHADOW
	msgbox FoxfireHollow_Mansion_B1F_Text_IntoTheDark, MSGBOX_DEFAULT
	closemessage
	release
	end

FoxfireHollow_Mansion_B1F_Text_AShadow:
	.string "A shadow is sitting in the master's\n"
	.string "chair.\p"
	.string "There's nobody here to cast it.$"

FoxfireHollow_Mansion_B1F_Text_IntoTheDark:
	.string "The shadow sinks into the dark\n"
	.string "under the desk.$"

FoxfireHollow_Mansion_B1F_EventScript_ItemTM14::
	finditem ITEM_TM14
	end
FoxfireHollow_Mansion_B1F_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE
	end
FoxfireHollow_Mansion_B1F_EventScript_ItemTM22::
	finditem ITEM_TM22
	end
FoxfireHollow_Mansion_B1F_EventScript_ItemFireStone::
	finditem ITEM_FIRE_STONE
	end

@ The NINETALES is below the desk at (21,30). The player talks to it from (20,30), (22,30) or
@ (21,29), so when it leaves it always has a free side to run to.
FoxfireHollow_Mansion_B1F_EventScript_Ninetales::
	lock
	faceplayer
	msgbox FoxfireHollow_Mansion_B1F_Text_BesideTheBall, MSGBOX_DEFAULT
	closemessage
	@ Its foxfire flares. No text and no waitstate until FadeOutOrbEffect: the orb re-enables
	@ the script every frame (src/field_screen_effect.c, Task_OrbEffect). Any VAR_RESULT past
	@ 3 is the blue orb, centred; 2 would be red.
	playse SE_M_CONFUSE_RAY
	setvar VAR_RESULT, 4
	special DoOrbEffect
	delay 60
	playmoncry SPECIES_NINETALES, CRY_MODE_ENCOUNTER
	delay 60
	special FadeOutOrbEffect
	waitstate
	waitmoncry
	setwildbossbattle species=SPECIES_NINETALES, level=42, move1_1=MOVE_FLAMETHROWER, move1_2=MOVE_EXTRASENSORY, move1_3=MOVE_CONFUSE_RAY, move1_4=MOVE_WILL_O_WISP
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 1, 1
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, FoxfireHollow_Mansion_B1F_EventScript_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FoxfireHollow_Mansion_B1F_EventScript_Freed
	release
	end

FoxfireHollow_Mansion_B1F_EventScript_Caught:
	setvar VAR_FOXFIRE_HOLLOW_STATE, 6
	removeobject LOCALID_FOXFIRE_MANSION_B1F_NINETALES
	call FoxfireHollow_Mansion_B1F_EventScript_BallSplits
	setweather WEATHER_NONE
	doweather
	msgbox FoxfireHollow_Mansion_B1F_Text_FogLifting, MSGBOX_DEFAULT
	closemessage
	release
	end

FoxfireHollow_Mansion_B1F_EventScript_Freed:
	setvar VAR_FOXFIRE_HOLLOW_STATE, 6
	call FoxfireHollow_Mansion_B1F_EventScript_BallSplits
	getplayerxy VAR_0x8004, VAR_0x8005
	msgbox FoxfireHollow_Mansion_B1F_Text_ToItsFeet, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOXFIRE_MANSION_B1F_NINETALES, FoxfireHollow_Mansion_B1F_Movement_GetsUp
	waitmovement 0
	msgbox FoxfireHollow_Mansion_B1F_Text_TheDoorway, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_FOXFIRE_MANSION_B1F_NINETALES, DIR_WEST
	delay 60
	playmoncry SPECIES_NINETALES, CRY_MODE_WEAK
	waitmoncry
	msgbox FoxfireHollow_Mansion_B1F_Text_RunsOut, MSGBOX_DEFAULT
	closemessage
	setweather WEATHER_NONE
	doweather
	call_if_eq VAR_0x8004, 20, FoxfireHollow_Mansion_B1F_EventScript_RunsEast
	call_if_ne VAR_0x8004, 20, FoxfireHollow_Mansion_B1F_EventScript_RunsWest
	playse SE_M_MIST
	applymovement LOCALID_FOXFIRE_MANSION_B1F_NINETALES, FoxfireHollow_Movement_Dissolve
	waitmovement 0
	removeobject LOCALID_FOXFIRE_MANSION_B1F_NINETALES
	release
	end

@ Away from wherever the player stands, then gone into the fog.
FoxfireHollow_Mansion_B1F_EventScript_RunsEast:
	applymovement LOCALID_FOXFIRE_MANSION_B1F_NINETALES, FoxfireHollow_Mansion_B1F_Movement_RunsEast
	waitmovement 0
	return

FoxfireHollow_Mansion_B1F_EventScript_RunsWest:
	applymovement LOCALID_FOXFIRE_MANSION_B1F_NINETALES, FoxfireHollow_Mansion_B1F_Movement_RunsWest
	waitmovement 0
	return

FoxfireHollow_Mansion_B1F_Movement_GetsUp:
	jump_in_place_up
	face_player
	step_end

FoxfireHollow_Mansion_B1F_Movement_RunsEast:
	walk_fast_right
	walk_fast_right
	step_end

FoxfireHollow_Mansion_B1F_Movement_RunsWest:
	walk_fast_left
	walk_fast_left
	step_end

FoxfireHollow_Mansion_B1F_EventScript_BallSplits:
	delay 20
	playse SE_BALL_OPEN
	dofieldeffectsparkle 20, 27, 0
	removeobject LOCALID_FOXFIRE_MANSION_B1F_OLD_BALL
	waitfieldeffect FLDEFF_SPARKLE
	msgbox FoxfireHollow_Mansion_B1F_Text_BallSplits, MSGBOX_DEFAULT
	closemessage
	return

FoxfireHollow_Mansion_B1F_EventScript_OldBall::
	msgbox FoxfireHollow_Mansion_B1F_Text_OldBallInRuin, MSGBOX_SIGN
	end

@ Only reachable once the ball object has gone.
FoxfireHollow_Mansion_B1F_EventScript_OldBallSplit::
	msgbox FoxfireHollow_Mansion_B1F_Text_OldBallSplit, MSGBOX_SIGN
	end

FoxfireHollow_Mansion_B1F_Text_BesideTheBall:
	.string "NINETALES is curled up beside the\n"
	.string "old POKé BALL, watching the door.$"

FoxfireHollow_Mansion_B1F_Text_OldBallInRuin:
	.string "The old POKé BALL is still on the\n"
	.string "desk.\p"
	.string "It is the only thing in the room\n"
	.string "anyone has kept clean.$"

FoxfireHollow_Mansion_B1F_Text_BallSplits:
	.string "On the desk, the old POKé BALL\n"
	.string "splits cleanly in two.$"

FoxfireHollow_Mansion_B1F_Text_OldBallSplit:
	.string "Two halves of an old POKé BALL.$"

FoxfireHollow_Mansion_B1F_Text_FogLifting:
	.string "Outside, the fog is starting to\n"
	.string "lift.$"

@ Text_RunsFree, split at its page breaks.
FoxfireHollow_Mansion_B1F_Text_ToItsFeet:
	.string "NINETALES gets slowly to its feet.$"

FoxfireHollow_Mansion_B1F_Text_TheDoorway:
	.string "It looks at the empty doorway for\n"
	.string "a long moment.$"

FoxfireHollow_Mansion_B1F_Text_RunsOut:
	.string "Then it runs out into the thinning\n"
	.string "fog, and doesn't look back.$"
