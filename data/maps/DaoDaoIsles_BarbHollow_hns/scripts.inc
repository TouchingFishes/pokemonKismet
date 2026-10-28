DaoDaoIsles_BarbHollow_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_BarbHollow_OnTransition
	.byte 0

DaoDaoIsles_BarbHollow_OnTransition:
	setflag FLAG_HIDE_DAODAO_BOSS_REGIDRAGO
	goto_if_unset FLAG_DAODAO_REGIS_ENABLED, DaoDaoIsles_BarbHollow_Ret
	goto_if_set FLAG_DEFEATED_DAODAO_BOSS_REGIDRAGO, DaoDaoIsles_BarbHollow_Ret
	clearflag FLAG_HIDE_DAODAO_BOSS_REGIDRAGO
DaoDaoIsles_BarbHollow_Ret:
	end

DaoDaoIsles_BarbHollow_EventScript_BossGoodra::
	lock
	faceplayer
	playmoncry SPECIES_GOODRA, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox DaoDaoIsles_BarbHollow_Text_BossIntro, MSGBOX_DEFAULT
	closemessage
	setwildbossbattle species=SPECIES_GOODRA, level=70, item=ITEM_DRAGON_FANG, move1_1=MOVE_DRAGON_PULSE, move1_2=MOVE_MUDDY_WATER, move1_3=MOVE_POWER_WHIP, move1_4=MOVE_ACID_ARMOR
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 0, 2, 1, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_BarbHollow_EventScript_BossStays
	@ Your own Roar, Whirlwind, Dragon Tail or Circle Throw ends it as PLAYER_TELEPORTED: running, not a win.
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DaoDaoIsles_BarbHollow_EventScript_BossStays
	setflag FLAG_DEFEATED_DAODAO_BOSS_REGIDRAGO
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_BOSS_REGIDRAGO
	setflag FLAG_HIDE_DAODAO_BOSS_REGIDRAGO
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox DaoDaoIsles_BarbHollow_Text_BossBeaten, MSGBOX_DEFAULT
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_BarbHollow_EventScript_BossStays::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_BarbHollow_Text_BossIntro:
	.string "Drops fall from the ceiling into\n"
	.string "the still pool, one by one.\p"
	.string "Something has been sitting here,\n"
	.string "soaking it all up, for a long time.$"

DaoDaoIsles_BarbHollow_Text_BossBeaten:
	.string "The damp goes out of the walls all\n"
	.string "at once.\p"
	.string "Far behind, in a chamber nobody\n"
	.string "has opened, something answers.$"
