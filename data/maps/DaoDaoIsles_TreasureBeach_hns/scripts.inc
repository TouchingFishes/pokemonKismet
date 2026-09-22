DaoDaoIsles_TreasureBeach_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_TreasureBeach_OnTransition
	.byte 0

DaoDaoIsles_TreasureBeach_OnTransition:
	setflag FLAG_HIDE_DAODAO_BOSS_REGIROCK
	goto_if_unset FLAG_DAODAO_REGIS_ENABLED, DaoDaoIsles_TreasureBeach_Ret
	goto_if_set FLAG_DEFEATED_DAODAO_BOSS_REGIROCK, DaoDaoIsles_TreasureBeach_Ret
	clearflag FLAG_HIDE_DAODAO_BOSS_REGIROCK
DaoDaoIsles_TreasureBeach_Ret:
	end

DaoDaoIsles_TreasureBeach_EventScript_BossKlawf::
	lock
	faceplayer
	playmoncry SPECIES_KLAWF, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_TreasureBeach_Text_BossIntro, MSGBOX_AUTOCLOSE
	setwildbossbattle species=SPECIES_KLAWF, level=70, item=ITEM_ROCKY_HELMET, move1_1=MOVE_STONE_EDGE, move1_2=MOVE_CRABHAMMER, move1_3=MOVE_KNOCK_OFF, move1_4=MOVE_SWORDS_DANCE
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 2, 0, 0, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_TreasureBeach_EventScript_BossStays
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGIROCK
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_BOSS_REGIROCK
	setflag FLAG_HIDE_DAODAO_BOSS_REGIROCK
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox DaoDaoIsles_TreasureBeach_Text_BossBeaten, MSGBOX_DEFAULT
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_TreasureBeach_EventScript_BossStays::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock1::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_1, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_1
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock2::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_2, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_2
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock3::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_3, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_3
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock4::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_4, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_4
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock5::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_5, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_5
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock6::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_6, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_6
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock7::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_7, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_7
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock8::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_8, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_8
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_RockRoll::
	special RollTreasureBeachItem
	goto_if_eq VAR_RESULT, ITEM_NONE, DaoDaoIsles_TreasureBeach_EventScript_RockEmpty
	msgbox DaoDaoIsles_TreasureBeach_Text_RockTreasure, MSGBOX_DEFAULT
	giveitem VAR_RESULT
	releaseall
	end

DaoDaoIsles_TreasureBeach_EventScript_RockEmpty::
	msgbox DaoDaoIsles_TreasureBeach_Text_RockEmpty, MSGBOX_DEFAULT
	releaseall
	end

DaoDaoIsles_TreasureBeach_EventScript_RockSearched::
	msgbox DaoDaoIsles_TreasureBeach_Text_RockSearched, MSGBOX_DEFAULT
	releaseall
	end

DaoDaoIsles_TreasureBeach_Text_RockTreasure:
	.string "Something is wedged in the sand\n"
	.string "beneath the rock!$"

DaoDaoIsles_TreasureBeach_Text_RockEmpty:
	.string "{PLAYER} rolled the rock aside.\p"
	.string "Nothing but damp sand underneath.$"

DaoDaoIsles_TreasureBeach_Text_RockSearched:
	.string "This rock has already been\n"
	.string "turned over today.\p"
	.string "The tide may wash something new\n"
	.string "in by tomorrow.$"

DaoDaoIsles_TreasureBeach_Text_BossIntro:
	.string "One of the rocks on the shelf has\n"
	.string "legs under it.\p"
	.string "It has been waiting a long time\n"
	.string "for something to walk past.$"

DaoDaoIsles_TreasureBeach_Text_BossBeaten:
	.string "The sand drains away between the\n"
	.string "stones, and keeps draining.\p"
	.string "Something out in the ruins has\n"
	.string "started to take water.$"
