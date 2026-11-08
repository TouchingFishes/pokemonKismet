SeafoamIslands_B1F_hns_MapScripts::
	.byte 0

SeafoamIslands_B1F_EventScript_Articuno::
	lock
	faceplayer
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_ARTICUNO, 50
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SeafoamIslands_B1F_EventScript_ArticunoRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SEAFOAM_ARTICUNO
	setflag FLAG_HIDE_ARTICUNO
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

SeafoamIslands_B1F_EventScript_ArticunoRan::
	release
	end

SeafoamIslands_B1F_Text_ArticunoBattle:
	.string "Gyaoo!$"

SeafoamIslands_B1F_EventScript_Item_Ice_Beam::
    finditem ITEM_TM_ICE_BEAM
    end

SeafoamIslands_B1F_EventScript_Beartic::
	lock
	faceplayer
	playmoncry SPECIES_BEARTIC, 0
	msgbox SeafoamIslands_B1F_Text_BearticRoar, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_CUBCHOO, 60, ITEM_NONE, SPECIES_BEARTIC, 60, ITEM_LUM_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SeafoamIslands_B1F_EventScript_BearticWon
	goto SeafoamIslands_B1F_EventScript_BearticEnd

SeafoamIslands_B1F_EventScript_BearticWon:
	setflag FLAG_HIDE_SEAFOAM_BEARTIC
	removeobject LOCALID_SEAFOAM_BEARTIC
	msgbox SeafoamIslands_B1F_Text_BearticDefeated, MSGBOX_AUTOCLOSE
SeafoamIslands_B1F_EventScript_BearticEnd:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

SeafoamIslands_B1F_Text_BearticRoar:
	.string "Grroooar!$"

SeafoamIslands_B1F_Text_BearticDefeated:
	.string "BEARTIC was defeated!\n"
	.string "It lumbered off across the ice…$"
