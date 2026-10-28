MtMoon_Summit_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_Summit_OnTransition
	.byte 0

MtMoon_Summit_OnTransition:
	setflag FLAG_TEMP_1
	goto_if_set FLAG_CAUGHT_CRESSELIA, MtMoon_Summit_OnTransitionEnd
	gettimeofday
	goto_if_ne VAR_0x8000, TIME_NIGHT, MtMoon_Summit_OnTransitionEnd
	clearflag FLAG_TEMP_1
MtMoon_Summit_OnTransitionEnd:
	end

MtMoon_Summit_EventScript_Cresselia::
	lock
	faceplayer
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	msgbox MtMoon_Summit_Text_CresseliaCry, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setwildbattle SPECIES_CRESSELIA, 70
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MtMoon_Summit_EventScript_CresseliaCaught
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtMoon_Summit_EventScript_CresseliaStays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtMoon_Summit_EventScript_CresseliaStays
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_MOON_SUMMIT_CRESSELIA
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtMoon_Summit_EventScript_CresseliaCaught:
	setflag FLAG_CAUGHT_CRESSELIA
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_MOON_SUMMIT_CRESSELIA
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtMoon_Summit_EventScript_CresseliaStays:
	release
	end

MtMoon_Summit_EventScript_Rock::
	msgbox MtMoon_Summit_Text_Rock, MSGBOX_SIGN
	end

MtMoon_Summit_Text_CresseliaCry:
	.string "A silver light shimmers across\n"
	.string "the peak!$"

MtMoon_Summit_Text_Rock:
	.string "The rock face is smooth, as if\n"
	.string "polished by moonlight.$"
