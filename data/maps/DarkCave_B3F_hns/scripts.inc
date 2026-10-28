DarkCave_B3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_B3F_OnTransition
	.byte 0

DarkCave_B3F_OnTransition:
	setflag FLAG_TEMP_1
	goto_if_set FLAG_CAUGHT_DARKRAI, DarkCave_B3F_OnTransitionEnd
	clearflag FLAG_TEMP_1
DarkCave_B3F_OnTransitionEnd:
	end

DarkCave_B3F_EventScript_Darkrai::
	lock
	faceplayer
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	msgbox DarkCave_B3F_Text_DarkraiCry, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setwildbattle SPECIES_DARKRAI, 75
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DarkCave_B3F_EventScript_DarkraiCaught
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DarkCave_B3F_EventScript_DarkraiStays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DarkCave_B3F_EventScript_DarkraiStays
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DARK_CAVE_B3F_DARKRAI
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DarkCave_B3F_EventScript_DarkraiCaught:
	setflag FLAG_CAUGHT_DARKRAI
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DARK_CAVE_B3F_DARKRAI
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DarkCave_B3F_EventScript_DarkraiStays:
	release
	end

DarkCave_B3F_Text_DarkraiCry:
	.string "A shadow rises out of the dark!$"
