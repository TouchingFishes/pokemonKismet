DaoDaoIsles_RegiceChamber_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_RegiceChamber_OnTransition
	.byte 0

DaoDaoIsles_RegiceChamber_OnTransition:
	setflag FLAG_HIDE_DAODAO_REGICE
	goto_if_set FLAG_DAODAO_REGICE_TAKEN, DaoDaoIsles_RegiceChamber_Ret
	goto_if_set FLAG_DAODAO_REGICE_KNOCKED_OUT, DaoDaoIsles_RegiceChamber_Ret
	goto_if_unset FLAG_DAODAO_REGIS_ENABLED, DaoDaoIsles_RegiceChamber_Ret
	goto_if_unset FLAG_DEFEATED_DAODAO_BOSS_REGICE, DaoDaoIsles_RegiceChamber_Ret
	clearflag FLAG_HIDE_DAODAO_REGICE
DaoDaoIsles_RegiceChamber_Ret:
	end

DaoDaoIsles_RegiceChamber_EventScript_Regice::
	lock
	faceplayer
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_REGICE, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_RegiceChamber_EventScript_Stays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a knockout.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_RegiceChamber_EventScript_Stays
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DaoDaoIsles_RegiceChamber_EventScript_Regi_Caught
	@ Knocked out: back after the next Hall of Fame (SpawnDaoDaoLegendaries).
	setflag FLAG_DAODAO_REGICE_KNOCKED_OUT
	goto DaoDaoIsles_RegiceChamber_EventScript_Regi_Gone

DaoDaoIsles_RegiceChamber_EventScript_Regi_Caught:
	setflag FLAG_DAODAO_REGICE_TAKEN
DaoDaoIsles_RegiceChamber_EventScript_Regi_Gone:
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_REGICE
	setflag FLAG_HIDE_DAODAO_REGICE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_RegiceChamber_EventScript_Stays::
	release
	end
