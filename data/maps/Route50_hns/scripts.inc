Route50_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route50_OnTransition
	.byte 0

Route50_OnTransition:
	goto_if_not_defeated TRAINER_EXPERT_SHIZUKO_HNS, Route50_OnTransition_End
	goto_if_not_defeated TRAINER_EXPERT_FUYUKI_HNS, Route50_OnTransition_End
	call Route50_EventScript_ExpertsStandAside
Route50_OnTransition_End:
	end

Route50_EventScript_BlackBelt1::
	msgbox Route50_Text_BlackBelt1, MSGBOX_NPC
	end

Route50_Text_BlackBelt1::
	.string "The body must be hardened\n"
    .string "and the mind strengthened\l"
    .string "in the harshest of conditions!$"

Route50_EventScript_BlackBelt2::
	msgbox Route50_Text_BlackBelt2, MSGBOX_NPC
	end

Route50_Text_BlackBelt2::
    .string "Phew!\p"
    .string "I'm not as hardcore as he is.\p"
	.string "There's really not much else\n"
    .string "to do here but train.$"
  

Route50_EventScript_Wessel::
	goto_if_defeated TRAINER_WESSEL_HNS, Route50_EventScript_WesselAfter
	msgbox Route50_Text_WesselBefore, MSGBOX_NPC
	goto_if_not_defeated TRAINER_WESSEL_HNS, Route50_EventScript_TryWesselBattle
	end
Route50_EventScript_TryWesselBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, Route50_EventScript_WesselBattle
	end
Route50_EventScript_WesselBattle::
	lock
	msgbox Route50_Text_WesselBeforeBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_WESSEL_HNS, Route50_Text_WesselDefeat
	giveitem ITEM_IRON_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox Route50_Text_WesselAfter, MSGBOX_AUTOCLOSE
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
Route50_EventScript_WesselAfter::
	msgbox Route50_Text_WesselAfter, MSGBOX_NPC
	end

Route50_Text_WesselBefore:
	.string "Incredible, a GIGALITH!\p"
	.string "Not one ounce of steel in it.\n"
	.string "Rock and crystal, all the way\l"
	.string "through.\p"
	.string "My hypothesis that this route\n"
	.string "would contain many steel types\l"
	.string "is disproven yet again.\p"
	.string "But why else would I have found\n"
	.string "this IRON PLATE here?\p"
	.string "I must collect more data!$"

Route50_Text_WesselBeforeBattle:
	.string "You want this PLATE?\n"
	.string "But I haven't analyzed it yet!\p"
	.string "Fine, we will battle for it.$"

Route50_Text_WesselDefeat:
	.string "My hypothesis was wrong...$"

Route50_Text_WesselAfter:
	.string "Take the PLATE. I don't want to\n"
	.string "talk about it.$"

Route50_EventScript_Finley::
	goto_if_defeated TRAINER_FINLEY_HNS, Route50_EventScript_FinleyAfter
	msgbox Route50_Text_FinleyBefore, MSGBOX_NPC
	goto_if_not_defeated TRAINER_FINLEY_HNS, Route50_EventScript_TryFinleyBattle
	end
Route50_EventScript_TryFinleyBattle::
	goto_if_eq VAR_SINJOH_STORYLINE, 6, Route50_EventScript_FinleyBattle
	end
Route50_EventScript_FinleyBattle::
	lock
	msgbox Route50_Text_FinleyBeforeBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_FINLEY_HNS, Route50_Text_FinleyDefeat
	giveitem ITEM_DRACO_PLATE
	addvar VAR_PLATECOUNTER, 1
	msgbox Route50_Text_FinleyAfter, MSGBOX_AUTOCLOSE
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	release
	end
Route50_EventScript_FinleyAfter::
	msgbox Route50_Text_FinleyAfter, MSGBOX_NPC
	end

Route50_Text_FinleyBefore:
	.string "How are the villagers treating\n"
    .string "you?\p"
    .string "They can be very unwelcoming to\n"
    .string "strangers.\p"
    .string "But meeting new people is one\n"
    .string "of life's greatest joys.\p"
    .string "One day, I hope to meet CHAMPION\n"
    .string "LANCE.\p"
    .string "He is a legendary dragon tamer,\n"
    .string "much like myself.\l"
    .string "Who am I?\p"
    .string "Well, I am FINLEY, keeper of the\n"
    .string "DRACO PLATE.$"

Route50_Text_FinleyBeforeBattle:
	.string "I know the KIMONO's have sent you\n"
	.string "to collect these PLATES.\p"
	.string "They say you are worthy...\n"
	.string "But can you conquer my dragons?$"

Route50_Text_FinleyDefeat:
	.string "My dragons fought well.$"

Route50_Text_FinleyAfter:
	.string "Perhaps you are even strong enough\n"
	.string "to beat LANCE...$"

Route50_EventScript_Item_ULtraBall::
    finditem ITEM_ULTRA_BALL
    end

Route50_EventScript_Item_Big_Nugget::
    finditem ITEM_BIG_NUGGET
    end

Route50_EventScript_ActivateFrosmoth::
	lock
	setobjectxyperm LOCALID_ROUTE50_NOBLE_FROSMOTH, 75, 14
	playse SE_M_DETECT
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	dofieldeffectsparkle VAR_TEMP_1, VAR_TEMP_2, 0
	waitfieldeffect FLDEFF_SPARKLE
	playse SE_PIN
	applymovement2 LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	msgbox SinjohRuins_Lab_Text_PlayFlute, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, FALSE, SinjohRuins_Lab_EventScript_NoOp
	playbgm MUS_DP_AZURE_FLUTE, FALSE
	delay 200
	fadedefaultbgm
	addobject LOCALID_ROUTE50_NOBLE_FROSMOTH
	clearflag FLAG_HIDE_ROUTE50_NOBLE_FROSMOTH
	playse SE_M_GUST
	applymovement2 LOCALID_ROUTE50_NOBLE_FROSMOTH, Route50_Movement_FrosmothFlutters
	waitmovement LOCALID_ROUTE50_NOBLE_FROSMOTH
	playse SE_M_ICY_WIND
	dofieldeffectsparkle 75, 14, 0
	waitfieldeffect FLDEFF_SPARKLE
	playmoncry SPECIES_FROSMOTH, CRY_MODE_NORMAL
	waitmoncry
	setvar VAR_NOBLE_FROSMOTH, 2
	release
	end

Route50_Movement_FrosmothFlutters:
	fly_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	step_end

Route50_EventScript_Frosmoth::
	lock
	faceplayer
	playmoncry SPECIES_FROSMOTH, CRY_MODE_ENCOUNTER
	msgbox Route50_Text_FrosmothCry, MSGBOX_AUTOCLOSE
	waitmoncry
	msgbox Route50_Text_FrosmothPlate, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, Route50_EventScript_FrosmothRan
	setwildbossbattle species=SPECIES_FROSMOTH, level=80, item=ITEM_NEVER_MELT_ICE, move1_1=MOVE_BLIZZARD, move1_2=MOVE_BUG_BUZZ, move1_3=MOVE_QUIVER_DANCE move1_4=MOVE_GIGA_DRAIN
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 3, 1, 0, 3, 0
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
    dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route50_EventScript_FrosmothRan
    bufferspeciesname STR_VAR_1, SPECIES_FROSMOTH
    msgbox SinjohRuins_Lab_Text_DropedItem, MSGBOX_DEFAULT
    giveitem ITEM_INSECT_PLATE
    addvar VAR_PLATECOUNTER, 1
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE50_NOBLE_FROSMOTH
	setflag FLAG_HIDE_ROUTE50_NOBLE_FROSMOTH
	fadescreenswapbuffers FADE_FROM_BLACK
    call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
    call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
    call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
    call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
    call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
    call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Route50_EventScript_FrosmothRan::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Route50_Text_FrosmothCry:
	.string "Frooosss…!$"

Route50_Text_FrosmothPlate:
	.string "The NOBLE FROSMOTH's wings scatter\n"
	.string "glittering frost.\p"
	.string "A PLATE rests on its back.\p"
	.string "Battle it?$"

Route50_EventScript_ExpertShizuko::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_EXPERT_SHIZUKO_HNS, Route50_EventScript_ExpertTrial
	goto_if_not_defeated TRAINER_EXPERT_FUYUKI_HNS, Route50_EventScript_ExpertTrial
	msgbox Route50_Text_ShizukoAfter, MSGBOX_DEFAULT
	release
	end

Route50_EventScript_ExpertFuyuki::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_EXPERT_SHIZUKO_HNS, Route50_EventScript_ExpertTrial
	goto_if_not_defeated TRAINER_EXPERT_FUYUKI_HNS, Route50_EventScript_ExpertTrial
	msgbox Route50_Text_FuyukiAfter, MSGBOX_DEFAULT
	release
	end

Route50_EventScript_ExpertTrial:
	msgbox Route50_Text_ExpertTrialAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route50_EventScript_ExpertTrialDeclined
	closemessage
	call Route50_EventScript_ExpertTrialPlacePlayer
	playbgm MUS_HG_ENCOUNTER_SAGE, FALSE
	playse SE_PIN
	applymovement LOCALID_ROUTE50_EXPERT_SHIZUKO, Common_Movement_ExclamationMark
	waitmovement 0
	call_if_eq VAR_TEMP_3, 1, Route50_EventScript_ShizukoStepsForward
	msgbox Route50_Text_ShizukoFirst, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_EXPERT_SHIZUKO_HNS, Route50_Text_ShizukoDefeat
	call_if_eq VAR_TEMP_3, 1, Route50_EventScript_ShizukoStepsBack
	playbgm MUS_HG_ENCOUNTER_SAGE, FALSE
	playse SE_PIN
	applymovement LOCALID_ROUTE50_EXPERT_FUYUKI, Common_Movement_ExclamationMark
	waitmovement 0
	call_if_eq VAR_TEMP_3, 1, Route50_EventScript_FuyukiStepsForward
	msgbox Route50_Text_FuyukiNext, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_EXPERT_FUYUKI_HNS, Route50_Text_FuyukiDefeat
	call_if_eq VAR_TEMP_3, 1, Route50_EventScript_FuyukiStepsBack
	msgbox Route50_Text_ExpertTrialPassed, MSGBOX_DEFAULT
	checkitem ITEM_MEADOW_PLATE
	call_if_eq VAR_RESULT, FALSE, Route50_EventScript_GiveMeadowPlate
	checkitem ITEM_ICICLE_PLATE
	call_if_eq VAR_RESULT, FALSE, Route50_EventScript_GiveIciclePlate
	msgbox Route50_Text_ExpertsStepAside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE50_EXPERT_SHIZUKO, Route50_Movement_ShizukoToPost
	applymovement LOCALID_ROUTE50_EXPERT_FUYUKI, Route50_Movement_FuyukiToPost
	waitmovement LOCALID_ROUTE50_EXPERT_SHIZUKO
	waitmovement LOCALID_ROUTE50_EXPERT_FUYUKI
	call Route50_EventScript_ExpertsStandAside
	goto_if_lt VAR_SINJOH_STORYLINE, 6, Route50_EventScript_ExpertTrialEnd
	call_if_eq VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_3Plates
	call_if_eq VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_6Plates
	call_if_eq VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_9Plates
	call_if_eq VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_12Plates
	call_if_eq VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_15Plates
	call_if_eq VAR_PLATECOUNTER, 16, SinjohRuins_Lab_EventScript_16Plates
Route50_EventScript_ExpertTrialEnd:
	release
	end

Route50_EventScript_ExpertTrialDeclined:
	msgbox Route50_Text_ExpertTrialDeclined, MSGBOX_DEFAULT
	release
	end

Route50_EventScript_ExpertTrialPlacePlayer:
	setvar VAR_TEMP_3, 1
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8005, 0, Route50_EventScript_ExpertTrialFromRuins
	goto_if_eq VAR_0x8005, 1, Route50_EventScript_ExpertTrialFromSide
	goto_if_eq VAR_0x8004, 19, Route50_EventScript_ExpertTrialFrom19
	applymovement OBJ_EVENT_ID_PLAYER, Route50_Movement_PlayerFrom18
	waitmovement 0
	return

Route50_EventScript_ExpertTrialFrom19:
	applymovement OBJ_EVENT_ID_PLAYER, Route50_Movement_PlayerFrom19
	waitmovement 0
	return

Route50_EventScript_ExpertTrialFromSide:
	goto_if_eq VAR_0x8004, 20, Route50_EventScript_ExpertTrialFromEast
	applymovement OBJ_EVENT_ID_PLAYER, Route50_Movement_PlayerFromWest
	waitmovement 0
	return

Route50_EventScript_ExpertTrialFromEast:
	applymovement OBJ_EVENT_ID_PLAYER, Route50_Movement_PlayerFromEast
	waitmovement 0
	return

Route50_EventScript_ExpertTrialFromRuins:
	setvar VAR_TEMP_3, 0
	turnobject LOCALID_ROUTE50_EXPERT_SHIZUKO, DIR_NORTH
	turnobject LOCALID_ROUTE50_EXPERT_FUYUKI, DIR_NORTH
	return

Route50_EventScript_ShizukoStepsForward:
	applymovement LOCALID_ROUTE50_EXPERT_SHIZUKO, Route50_Movement_ShizukoStepsForward
	waitmovement 0
	return

Route50_EventScript_ShizukoStepsBack:
	applymovement LOCALID_ROUTE50_EXPERT_SHIZUKO, Route50_Movement_ShizukoStepsBack
	waitmovement 0
	return

Route50_EventScript_FuyukiStepsForward:
	applymovement LOCALID_ROUTE50_EXPERT_FUYUKI, Route50_Movement_FuyukiStepsForward
	waitmovement 0
	return

Route50_EventScript_FuyukiStepsBack:
	applymovement LOCALID_ROUTE50_EXPERT_FUYUKI, Route50_Movement_FuyukiStepsBack
	waitmovement 0
	return

Route50_EventScript_GiveMeadowPlate:
	giveitem ITEM_MEADOW_PLATE
	addvar VAR_PLATECOUNTER, 1
	return

Route50_EventScript_GiveIciclePlate:
	giveitem ITEM_ICICLE_PLATE
	addvar VAR_PLATECOUNTER, 1
	return

Route50_EventScript_ExpertsStandAside:
	setobjectxyperm LOCALID_ROUTE50_EXPERT_SHIZUKO, 16, 7
	setobjectmovementtype LOCALID_ROUTE50_EXPERT_SHIZUKO, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_ROUTE50_EXPERT_FUYUKI, 22, 7
	setobjectmovementtype LOCALID_ROUTE50_EXPERT_FUYUKI, MOVEMENT_TYPE_FACE_LEFT
	return

Route50_Movement_PlayerFrom18:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	face_up
	step_end

Route50_Movement_PlayerFrom19:
	walk_down
	walk_left
	face_up
	step_end

Route50_Movement_PlayerFromWest:
	walk_down
	walk_down
	walk_right
	face_up
	step_end

Route50_Movement_PlayerFromEast:
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	step_end

Route50_Movement_ShizukoStepsForward:
	walk_down
	step_end

Route50_Movement_ShizukoStepsBack:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

Route50_Movement_FuyukiStepsForward:
	walk_down
	walk_left
	face_down
	step_end

Route50_Movement_FuyukiStepsBack:
	lock_facing_direction
	walk_right
	walk_up
	unlock_facing_direction
	step_end

Route50_Movement_ShizukoToPost:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	face_right
	step_end

Route50_Movement_FuyukiToPost:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_left
	step_end

Route50_Text_ExpertTrialAsk:
	.string "SHIZUKO: The SINJOH RUINS lie\n"
	.string "beyond us.\p"
	.string "FUYUKI: No one takes this road who\n"
	.string "has not passed our trial.\p"
	.string "SHIZUKO: CYNTHIA passed it, and her\n"
	.string "word let the expedition through.\p"
	.string "FUYUKI: Two battles, back to back,\n"
	.string "and no rest between.\p"
	.string "Will you take our trial?$"

Route50_Text_ExpertTrialDeclined:
	.string "SHIZUKO: Then heal, and come back\n"
	.string "when you are ready.$"

Route50_Text_ShizukoFirst:
	.string "SHIZUKO: I am first. Let the sun\n"
	.string "show us what you are made of.$"

Route50_Text_ShizukoDefeat:
	.string "SHIZUKO: The meadow bends to you.$"

Route50_Text_FuyukiNext:
	.string "FUYUKI: Do not catch your breath.\n"
	.string "The cold does not wait.$"

Route50_Text_FuyukiDefeat:
	.string "FUYUKI: …Thawed.$"

Route50_Text_ExpertTrialPassed:
	.string "SHIZUKO: It is done. You passed\n"
	.string "our trial, as CYNTHIA did.\p"
	.string "FUYUKI: We kept these for whoever\n"
	.string "earned the road. Take them.$"

Route50_Text_ExpertsStepAside:
	.string "SHIZUKO: The SINJOH RUINS are open\n"
	.string "to you.$"

Route50_Text_ShizukoAfter:
	.string "SHIZUKO: Walk gently in the ruins.\n"
	.string "They remember every footstep.$"

Route50_Text_FuyukiAfter:
	.string "FUYUKI: The road is yours.\n"
	.string "Do not make us regret it.$"

Route50_EventScript_GigalithRest::
	msgbox Route50_Text_GigalithRest, MSGBOX_SIGN
	end

Route50_Text_GigalithRest:
	.string "The stones here are cracked and\n"
	.string "scattered, and still faintly warm.\p"
	.string "Something enormous slept in this\n"
	.string "grove for a very long time.$"
