DaoDaoIsles_BerryForest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_BerryForest_OnTransition
	.byte 0

DaoDaoIsles_BerryForest_OnTransition:
	setflag FLAG_HIDE_DAODAO_BOSS_REGIELEKI
	goto_if_unset FLAG_DAODAO_REGIS_ENABLED, DaoDaoIsles_BerryForest_Ret
	goto_if_set FLAG_DEFEATED_DAODAO_BOSS_REGIELEKI, DaoDaoIsles_BerryForest_Ret
	clearflag FLAG_HIDE_DAODAO_BOSS_REGIELEKI
DaoDaoIsles_BerryForest_Ret:
	end

DaoDaoIsles_BerryForest_EventScript_BossGalvantula::
	lock
	faceplayer
	playmoncry SPECIES_GALVANTULA, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_BerryForest_Text_BossIntro, MSGBOX_AUTOCLOSE
	setwildbossbattle species=SPECIES_GALVANTULA, level=70, item=ITEM_MAGNET, move1_1=MOVE_THUNDER, move1_2=MOVE_BUG_BUZZ, move1_3=MOVE_STICKY_WEB, move1_4=MOVE_THUNDER_WAVE
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 2, 2, 0, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_BerryForest_EventScript_BossStays
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGIELEKI
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_BOSS_REGIELEKI
	setflag FLAG_HIDE_DAODAO_BOSS_REGIELEKI
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox DaoDaoIsles_BerryForest_Text_BossBeaten, MSGBOX_DEFAULT
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_BerryForest_EventScript_BossStays::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_BerryForest_Text_BossIntro:
	.string "Every tree in this corner is strung\n"
	.string "with web, and the web is humming.\p"
	.string "It stops. Something at the centre\n"
	.string "has felt the ground move.$"

DaoDaoIsles_BerryForest_Text_BossBeaten:
	.string "The web goes slack and the hum\n"
	.string "drains out of the trees.\p"
	.string "Far away, it starts up again\n"
	.string "under stone.$"

DaoDaoIsles_BerryForest_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER, 1
	end

DaoDaoIsles_BerryForest_EventScript_ItemFullHeal::
	finditem ITEM_FULL_HEAL, 1
	end

DaoDaoIsles_BerryForest_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR, 1
	end

DaoDaoIsles_BerryForest_EventScript_BewareSign::
	msgbox DaoDaoIsles_BerryForest_Text_BewareSign, MSGBOX_SIGN
	end

DaoDaoIsles_BerryForest_EventScript_WelcomeSign::
	msgbox DaoDaoIsles_BerryForest_Text_WelcomeSign, MSGBOX_SIGN
	end

DaoDaoIsles_BerryForest_Text_BewareSign:
	.string "BEWARE!\p"
	.string "The trees here fruit all year, and\n"
	.string "not everything living off them is\l"
	.string "friendly.$"

DaoDaoIsles_BerryForest_Text_WelcomeSign:
	.string "BERRY FOREST\p"
	.string "Pick what you need.\n"
	.string "Leave the rest to ripen.$"
