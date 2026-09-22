DaoDaoIsles_LostCave_Room10_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_LostCave_Room10_OnTransition
	.byte 0

DaoDaoIsles_LostCave_Room10_OnTransition:
	setflag FLAG_HIDE_DAODAO_BOSS_REGIDRAGO
	goto_if_unset FLAG_DAODAO_REGIS_ENABLED, DaoDaoIsles_LostCave_Room10_Ret
	goto_if_set FLAG_DEFEATED_DAODAO_BOSS_REGIDRAGO, DaoDaoIsles_LostCave_Room10_Ret
	clearflag FLAG_HIDE_DAODAO_BOSS_REGIDRAGO
DaoDaoIsles_LostCave_Room10_Ret:
	end

DaoDaoIsles_LostCave_Room10_EventScript_BossGoodra::
	lock
	faceplayer
	playmoncry SPECIES_GOODRA, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_LostCave_Room10_Text_BossIntro, MSGBOX_AUTOCLOSE
	setwildbossbattle species=SPECIES_GOODRA, level=70, item=ITEM_DRAGON_FANG, move1_1=MOVE_DRAGON_PULSE, move1_2=MOVE_MUDDY_WATER, move1_3=MOVE_POWER_WHIP, move1_4=MOVE_ACID_ARMOR
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 0, 2, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_LostCave_Room10_EventScript_BossStays
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGIDRAGO
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_BOSS_REGIDRAGO
	setflag FLAG_HIDE_DAODAO_BOSS_REGIDRAGO
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox DaoDaoIsles_LostCave_Room10_Text_BossBeaten, MSGBOX_DEFAULT
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_LostCave_Room10_EventScript_BossStays::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_LostCave_Room10_Text_BossIntro:
	.string "The air in the last room is wet,\n"
	.string "and it has been wet a long time.\p"
	.string "Something has been sitting here\n"
	.string "since before the maze was cut.$"

DaoDaoIsles_LostCave_Room10_Text_BossBeaten:
	.string "The damp goes out of the walls all\n"
	.string "at once.\p"
	.string "Far behind, in a chamber nobody\n"
	.string "has opened, something answers.$"
