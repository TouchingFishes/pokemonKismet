DaoDaoIsles_BingCurrentCave_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_BingCurrentCave_OnTransition
	.byte 0

DaoDaoIsles_BingCurrentCave_OnTransition:
	setflag FLAG_HIDE_DAODAO_BOSS_REGICE
	goto_if_unset FLAG_DAODAO_REGIS_ENABLED, DaoDaoIsles_BingCurrentCave_Ret
	goto_if_set FLAG_DEFEATED_DAODAO_BOSS_REGICE, DaoDaoIsles_BingCurrentCave_Ret
	clearflag FLAG_HIDE_DAODAO_BOSS_REGICE
DaoDaoIsles_BingCurrentCave_Ret:
	end

DaoDaoIsles_BingCurrentCave_EventScript_BossWalrein::
	lock
	faceplayer
	playmoncry SPECIES_WALREIN, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_BingCurrentCave_Text_BossIntro, MSGBOX_AUTOCLOSE
	setwildbossbattle species=SPECIES_WALREIN, level=70, item=ITEM_NEVER_MELT_ICE, move1_1=MOVE_BLIZZARD, move1_2=MOVE_SURF, move1_3=MOVE_CRUNCH, move1_4=MOVE_YAWN
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 0, 2, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_BingCurrentCave_EventScript_BossStays
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGICE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_BOSS_REGICE
	setflag FLAG_HIDE_DAODAO_BOSS_REGICE
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox DaoDaoIsles_BingCurrentCave_Text_BossBeaten, MSGBOX_DEFAULT
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_BingCurrentCave_EventScript_BossStays::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_BingCurrentCave_EventScript_Klawf::
	lock
	faceplayer
	setflag FLAG_BATTLED_KLAWF
	playmoncry SPECIES_KLAWF, CRY_MODE_NORMAL
	msgbox DaoDaoIsles_BingCurrentCave_Text_Growl, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_KLAWF, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_BingCurrentCave_EventScript_KlawfStays
	setflag FLAG_HIDE_DAODAO_BINGCURRENT_CAVE_KLAWF
	removeobject LOCALID_DAODAO_BINGCURRENT_CAVE_KLAWF
DaoDaoIsles_BingCurrentCave_EventScript_KlawfStays::
	release
	end

DaoDaoIsles_BingCurrentCave_EventScript_Mimikyu::
	lock
	faceplayer
	setflag FLAG_BATTLED_MIMIKYU
	playmoncry SPECIES_MIMIKYU, CRY_MODE_NORMAL
	msgbox DaoDaoIsles_BingCurrentCave_Text_Growl, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_MIMIKYU, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_BingCurrentCave_EventScript_MimikyuStays
	setflag FLAG_HIDE_DAODAO_BINGCURRENT_CAVE_MIMIKYU
	removeobject LOCALID_DAODAO_BINGCURRENT_CAVE_MIMIKYU
DaoDaoIsles_BingCurrentCave_EventScript_MimikyuStays::
	release
	end

DaoDaoIsles_BingCurrentCave_EventScript_FindItem1::
	finditem ITEM_ICE_STONE, 1
	end

DaoDaoIsles_BingCurrentCave_EventScript_FindItem2::
	finditem ITEM_ADRENALINE_ORB, 1
	end

DaoDaoIsles_BingCurrentCave_Text_Growl:
	.string "Graah!$"

DaoDaoIsles_BingCurrentCave_Text_BossIntro:
	.string "The ice at the back of the chamber\n"
	.string "is not ice.\p"
	.string "It heaves itself up off the floor\n"
	.string "and fills the passage.$"

DaoDaoIsles_BingCurrentCave_Text_BossBeaten:
	.string "Meltwater runs off the walls and\n"
	.string "away down the passage.\p"
	.string "Somewhere it is running uphill.$"
