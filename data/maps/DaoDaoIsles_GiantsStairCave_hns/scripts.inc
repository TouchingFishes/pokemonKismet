DaoDaoIsles_GiantsStairCave_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_GiantsStairCave_OnTransition
	.byte 0

DaoDaoIsles_GiantsStairCave_OnTransition:
	call_if_unset FLAG_TRIGGERED_DAODAO_STAIR_TOTEM, DaoDaoIsles_GiantsStairCave_EventScript_HideTotem
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_GiantsStairCave_OnTransition_Day
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_GiantsStairCave_OnTransition_Day
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_GiantsStairCave_OnTransition_Day
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ORANGURU )
	clearflag FLAG_DAODAO_STAIR_TOTEM_DAY
	end

DaoDaoIsles_GiantsStairCave_OnTransition_Day:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( PASSIMIAN )
	setflag FLAG_DAODAO_STAIR_TOTEM_DAY
	end

DaoDaoIsles_GiantsStairCave_EventScript_HideTotem:
	setflag FLAG_HIDE_DAODAO_STAIR_TOTEM
	return

DaoDaoIsles_GiantsStairCave_EventScript_TotemTrigger::
	goto_if_unset FLAG_TRIGGERED_DAODAO_STAIR_TOTEM, DaoDaoIsles_GiantsStairCave_EventScript_TotemAppears
	end

DaoDaoIsles_GiantsStairCave_EventScript_TotemAppears:
	lock
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	fadescreenswapbuffers FADE_TO_BLACK
	delay 30
	clearflag FLAG_HIDE_DAODAO_STAIR_TOTEM
	call DaoDaoIsles_GiantsStairCave_EventScript_TotemCry
	addobject LOCALID_DAODAO_STAIR_TOTEM
	waitmoncry
	special DrawWholeMapView
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 30
	call DaoDaoIsles_GiantsStairCave_EventScript_TotemCry
	applymovement LOCALID_DAODAO_STAIR_TOTEM, DaoDaoIsles_GiantsStairCave_Movement_TotemStamps
	waitmovement 0
	waitmoncry
	setflag FLAG_TRIGGERED_DAODAO_STAIR_TOTEM
	release
	end

DaoDaoIsles_GiantsStairCave_EventScript_TotemCry:
	goto_if_set FLAG_DAODAO_STAIR_TOTEM_DAY, DaoDaoIsles_GiantsStairCave_EventScript_TotemCryDay
	playmoncry SPECIES_ORANGURU, 0
	return

DaoDaoIsles_GiantsStairCave_EventScript_TotemCryDay:
	playmoncry SPECIES_PASSIMIAN, 0
	return

DaoDaoIsles_GiantsStairCave_EventScript_Totem::
	lock
	faceplayer
	call DaoDaoIsles_GiantsStairCave_EventScript_TotemCry
	msgbox DaoDaoIsles_GiantsStairCave_Text_TotemRoar, MSGBOX_AUTOCLOSE
	waitmoncry
	goto_if_set FLAG_DAODAO_STAIR_TOTEM_DAY, DaoDaoIsles_GiantsStairCave_EventScript_TotemDayBattle
	setwildbossbattle species=SPECIES_ORANGURU, level=72, move1_1=MOVE_PSYCHIC, move1_2=MOVE_INSTRUCT, move1_3=MOVE_FOCUS_BLAST, move1_4=MOVE_TAUNT, species2=SPECIES_ORANGURU, level2=74, item2=ITEM_SITRUS_BERRY, move2_1=MOVE_PSYCHIC, move2_2=MOVE_FOUL_PLAY, move2_3=MOVE_CALM_MIND, move2_4=MOVE_TRICK_ROOM
	goto DaoDaoIsles_GiantsStairCave_EventScript_TotemFight

DaoDaoIsles_GiantsStairCave_EventScript_TotemDayBattle:
	setwildbossbattle species=SPECIES_PASSIMIAN, level=72, move1_1=MOVE_BRICK_BREAK, move1_2=MOVE_ROCK_SLIDE, move1_3=MOVE_BULK_UP, move1_4=MOVE_DOUBLE_EDGE, species2=SPECIES_PASSIMIAN, level2=74, item2=ITEM_LUM_BERRY, move2_1=MOVE_CLOSE_COMBAT, move2_2=MOVE_ROCK_SLIDE, move2_3=MOVE_KNOCK_OFF, move2_4=MOVE_DOUBLE_EDGE
DaoDaoIsles_GiantsStairCave_EventScript_TotemFight:
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_GiantsStairCave_EventScript_TotemWon
	@ Any other ending (your Dragon Tail or Circle Throw, say) still undoes the battle flags.
	goto DaoDaoIsles_GiantsStairCave_EventScript_TotemEnd

DaoDaoIsles_GiantsStairCave_EventScript_TotemWon:
	setflag FLAG_HIDE_DAODAO_STAIR_TOTEM
	setflag FLAG_DEFEATED_DAODAO_STAIR_TOTEM
	removeobject LOCALID_DAODAO_STAIR_TOTEM
	goto_if_set FLAG_DAODAO_STAIR_TOTEM_DAY, DaoDaoIsles_GiantsStairCave_EventScript_TotemWonDay
	msgbox DaoDaoIsles_GiantsStairCave_Text_TotemOranguruDefeated, MSGBOX_AUTOCLOSE
	goto DaoDaoIsles_GiantsStairCave_EventScript_TotemEnd

DaoDaoIsles_GiantsStairCave_EventScript_TotemWonDay:
	msgbox DaoDaoIsles_GiantsStairCave_Text_TotemPassimianDefeated, MSGBOX_AUTOCLOSE
DaoDaoIsles_GiantsStairCave_EventScript_TotemEnd:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_GiantsStairCave_EventScript_Drapion::
	lock
	faceplayer
	setflag FLAG_BATTLED_DRAPION
	playmoncry SPECIES_DRAPION, 0
	msgbox DaoDaoIsles_GiantsStairCave_Text_Drapion, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_DRAPION, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DaoDaoIsles_GiantsStairCave_EventScript_DrapionGone
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_GiantsStairCave_EventScript_DrapionGone
	release
	end

DaoDaoIsles_GiantsStairCave_EventScript_DrapionGone:
	setflag FLAG_HIDE_DRAPION
	removeobject LOCALID_DAODAO_STAIR_DRAPION
	release
	end

DaoDaoIsles_GiantsStairCave_EventScript_Marik::
	trainerbattle_single TRAINER_MARIK_HNS, DaoDaoIsles_GiantsStairCave_Text_MarikSeen, DaoDaoIsles_GiantsStairCave_Text_MarikDefeat
	msgbox DaoDaoIsles_GiantsStairCave_Text_MarikAfter, MSGBOX_AUTOCLOSE
	release
	end

DaoDaoIsles_GiantsStairCave_EventScript_Dusty::
	trainerbattle_single TRAINER_DUSTY_HNS, DaoDaoIsles_GiantsStairCave_Text_DustySeen, DaoDaoIsles_GiantsStairCave_Text_DustyDefeat
	msgbox DaoDaoIsles_GiantsStairCave_Text_DustyAfter, MSGBOX_AUTOCLOSE
	release
	end

DaoDaoIsles_GiantsStairCave_EventScript_Russ::
	trainerbattle_single TRAINER_RUSS_HNS, DaoDaoIsles_GiantsStairCave_Text_RussSeen, DaoDaoIsles_GiantsStairCave_Text_RussDefeat
	msgbox DaoDaoIsles_GiantsStairCave_Text_RussAfter, MSGBOX_AUTOCLOSE
	release
	end

DaoDaoIsles_GiantsStairCave_EventScript_ToxicOrb::
	finditem ITEM_TOXIC_ORB, 1
	end

DaoDaoIsles_GiantsStairCave_EventScript_FocusSash::
	finditem ITEM_FOCUS_SASH, 1
	end

DaoDaoIsles_GiantsStairCave_Movement_TotemStamps:
	walk_in_place_down
	walk_in_place_down
	step_end

DaoDaoIsles_GiantsStairCave_Text_TotemRoar:
	.string "Graah!$"

DaoDaoIsles_GiantsStairCave_Text_TotemPassimianDefeated:
	.string "Totem PASSIMIAN was defeated!\n"
	.string "It scampered off somewhere…$"

DaoDaoIsles_GiantsStairCave_Text_TotemOranguruDefeated:
	.string "Totem ORANGURU was defeated!\n"
	.string "It scampered off somewhere…$"

DaoDaoIsles_GiantsStairCave_Text_Drapion:
	.string "Gaaah!$"

DaoDaoIsles_GiantsStairCave_Text_MarikSeen:
	.string "You crossed the water to reach me.\p"
	.string "Thirty years I've trained in this\n"
	.string "cave, and few ever made it this far.\p"
	.string "I am MARIK.\n"
	.string "Come. Let's see what you're made of!$"

DaoDaoIsles_GiantsStairCave_Text_MarikDefeat:
	.string "Hah…\n"
	.string "It's been years since I lost.$"

DaoDaoIsles_GiantsStairCave_Text_MarikAfter:
	.string "I came here to grow strong enough\n"
	.string "for what lives in the hall above.\p"
	.string "I'm still not ready.\n"
	.string "You might be.$"

DaoDaoIsles_GiantsStairCave_Text_DustySeen:
	.string "These stairs were cut by hand!\n"
	.string "No cave grows stairs on its own!$"

DaoDaoIsles_GiantsStairCave_Text_DustyDefeat:
	.string "Buried by my own excitement…$"

DaoDaoIsles_GiantsStairCave_Text_DustyAfter:
	.string "Whoever built them knew something\n"
	.string "was waiting up there.$"

DaoDaoIsles_GiantsStairCave_Text_RussSeen:
	.string "My NOSEPASS keeps pointing north.\n"
	.string "Something in this cave pulls at it!$"

DaoDaoIsles_GiantsStairCave_Text_RussDefeat:
	.string "My readings are all over the place!$"

DaoDaoIsles_GiantsStairCave_Text_RussAfter:
	.string "It isn't north it points at.\n"
	.string "It's whatever lives past those stairs.$"
