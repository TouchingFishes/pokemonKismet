DaoDaoIsles_LostCave_Room10_hns_MapScripts::
	.byte 0

DaoDaoIsles_LostCave_Room10_EventScript_Barbaracle::
	lock
	faceplayer
	playmoncry SPECIES_BARBARACLE, CRY_MODE_NORMAL
	msgbox DaoDaoIsles_LostCave_Room10_Text_Barbaracle, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	setwildbattle SPECIES_BARBARACLE, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_LostCave_Room10_EventScript_BarbaracleStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a win.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_LostCave_Room10_EventScript_BarbaracleStays
	setflag FLAG_HIDE_DAODAO_BARB_HOLLOW_BARBARACLE
	removeobject LOCALID_DAODAO_LOST_CAVE_BARBARACLE
DaoDaoIsles_LostCave_Room10_EventScript_BarbaracleStays::
	release
	end

DaoDaoIsles_LostCave_Room10_Text_Barbaracle:
	.string "Shaaa!$"
