DaoDaoIsles_KilnIsle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_KilnIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DaoDaoIsles_KilnIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

DaoDaoIsles_KilnIsle_EventScript_HideKecleon::
	setvar VAR_TEMP_9, 1
	setflag FLAG_TEMP_1
	removeobject LOCALID_DAODAO_KILN_KECLEON
	end

@ -----------------------------------------------------------------------------------------
@ Moved from AkalaIsle_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_KilnIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_unset FLAG_TRIGGERED_DAODAO_KILN_TOTEM, DaoDaoIsles_KilnIsle_EventScript_HideTotem
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_KilnIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_KilnIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_KilnIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( PROBOPASS )
	clearflag FLAG_DAODAO_KILN_TOTEM_DAY
	call DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_KilnIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( MAGMORTAR )
	setflag FLAG_DAODAO_KILN_TOTEM_DAY
	call DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_KilnIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_C, 0, DaoDaoIsles_KilnIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	.2byte 0

DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing:
	setvar VAR_TEMP_C, 1
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	compare VAR_TEMP_A, 9
	goto_if_ne DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing_End
	compare VAR_TEMP_B, 11
	goto_if_eq DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing_Set
	compare VAR_TEMP_B, 12
	goto_if_eq DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing_Set
	goto DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing_End

DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing_Set:
	setvar VAR_TEMP_C, 0

DaoDaoIsles_KilnIsle_hns_SetTotemSignWarpFacing_End:
	return

DaoDaoIsles_KilnIsle_hns_EventScript_FacePlayerUpAfterTotemWarp::
	setvar VAR_TEMP_C, 1
	applymovement LOCALID_PLAYER, DaoDaoIsles_KilnIsle_hns_Movement_FacePlayerUpAfterTotemWarp
	return


DaoDaoIsles_KilnIsle_Island_FindItem1::
	finditem ITEM_PROTEIN, 1
	end


DaoDaoIsles_KilnIsle_Island_FindItem2::
	finditem ITEM_IRON, 1
	end


DaoDaoIsles_KilnIsle_Sign::
	lock
	msgbox DaoDaoIsles_KilnIsle_Sign_Text_0
	release
	end


DaoDaoIsles_KilnIsle_House_Sign::
	lock
	msgbox DaoDaoIsles_KilnIsle_House_Sign_Text_0
	release
	end


DaoDaoIsles_KilnIsle_Natu::
	lock
	faceplayer
	playmoncry SPECIES_NATU, 0
	msgbox DaoDaoIsles_KilnIsle_Natu_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end


DaoDaoIsles_KilnIsle_OldManOnBench::
	lock
	faceplayer
	msgbox DaoDaoIsles_KilnIsle_OldManOnBench_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_KilnIsle_TotemBattle_Trigger::
	goto_if_unset FLAG_TRIGGERED_DAODAO_KILN_TOTEM, DaoDaoIsles_KilnIsle_TotemBattle_Trigger_1
	end

DaoDaoIsles_KilnIsle_TotemBattle_Trigger_1:
	goto DaoDaoIsles_KilnIsle_TotemBattle_Trigger_4

DaoDaoIsles_KilnIsle_TotemBattle_Trigger_4:
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
	clearflag FLAG_HIDE_DAODAO_KILN_TOTEM
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_Trigger_14
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_Trigger_14
	playmoncry SPECIES_PROBOPASS, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( PROBOPASS )
	clearflag FLAG_DAODAO_KILN_TOTEM_DAY
	addobject LOCALID_DAODAO_KILN_TOTEM
	waitmoncry
DaoDaoIsles_KilnIsle_TotemBattle_Trigger_13:
	special DrawWholeMapView
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 30
	gettimeofday
	compare VAR_0x8000, TIME_MORNING
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_DAY
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_Trigger_20
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_Trigger_20
	playmoncry SPECIES_PROBOPASS, 0
	applymovement LOCALID_DAODAO_KILN_TOTEM, DaoDaoIsles_KilnIsle_TotemBattle_Trigger_Movement_0
	waitmovement 0
	waitmoncry
DaoDaoIsles_KilnIsle_TotemBattle_Trigger_19:
	setflag FLAG_TRIGGERED_DAODAO_KILN_TOTEM
	release
	end

DaoDaoIsles_KilnIsle_TotemBattle_Trigger_14:
	playmoncry SPECIES_MAGMORTAR, 0
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( MAGMORTAR )
	setflag FLAG_DAODAO_KILN_TOTEM_DAY
	addobject LOCALID_DAODAO_KILN_TOTEM
	waitmoncry
	goto DaoDaoIsles_KilnIsle_TotemBattle_Trigger_13

DaoDaoIsles_KilnIsle_TotemBattle_Trigger_20:
	playmoncry SPECIES_MAGMORTAR, 0
	applymovement LOCALID_DAODAO_KILN_TOTEM, DaoDaoIsles_KilnIsle_TotemBattle_Trigger_Movement_0
	waitmovement 0
	waitmoncry
	goto DaoDaoIsles_KilnIsle_TotemBattle_Trigger_19


DaoDaoIsles_KilnIsle_TotemBattle::
	lock
	faceplayer
	goto_if_set FLAG_DAODAO_KILN_TOTEM_DAY, DaoDaoIsles_KilnIsle_TotemBattle_1
	playmoncry SPECIES_PROBOPASS, 0
	msgbox DaoDaoIsles_KilnIsle_TotemBattle_Text_2, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_NOSEPASS, 60, ITEM_NONE, SPECIES_PROBOPASS, 60, ITEM_PETAYA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_7
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_9
	@ Any other ending (your Dragon Tail or Circle Throw, say) still undoes the battle flags.
	goto DaoDaoIsles_KilnIsle_TotemBattle_9

DaoDaoIsles_KilnIsle_TotemBattle_1:
	playmoncry SPECIES_MAGMORTAR, 0
	msgbox DaoDaoIsles_KilnIsle_TotemBattle_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_MAGMAR, 60, ITEM_NONE, SPECIES_MAGMORTAR, 60, ITEM_SITRUS_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_KilnIsle_TotemBattle_4
	@ Any other ending (your Dragon Tail or Circle Throw, say) still undoes the battle flags.
	goto DaoDaoIsles_KilnIsle_TotemBattle_9

DaoDaoIsles_KilnIsle_TotemBattle_4:
	setflag FLAG_HIDE_DAODAO_KILN_TOTEM
	setflag FLAG_DEFEATED_DAODAO_KILN_TOTEM
	removeobject LOCALID_DAODAO_KILN_TOTEM
	msgbox DaoDaoIsles_KilnIsle_TotemBattle_Text_1, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	release
	end

DaoDaoIsles_KilnIsle_TotemBattle_7:
	setflag FLAG_HIDE_DAODAO_KILN_TOTEM
	setflag FLAG_DEFEATED_DAODAO_KILN_TOTEM
	removeobject LOCALID_DAODAO_KILN_TOTEM
	msgbox DaoDaoIsles_KilnIsle_TotemBattle_Text_3, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	release
	end

DaoDaoIsles_KilnIsle_TotemBattle_9:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	release
	end


DaoDaoIsles_KilnIsle_Totem_sign::
	lock
	goto_if_unset FLAG_DEFEATED_DAODAO_LANDFALL_TOTEM, DaoDaoIsles_KilnIsle_Totem_sign_Locked
	goto_if_unset FLAG_DEFEATED_DAODAO_KILN_TOTEM, DaoDaoIsles_KilnIsle_Totem_sign_Locked
	goto_if_unset FLAG_DEFEATED_DAODAO_WAKE_TOTEM, DaoDaoIsles_KilnIsle_Totem_sign_Locked
	msgbox DaoDaoIsles_KilnIsle_Totem_sign_Text_0
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, DaoDaoIsles_KilnIsle_Totem_sign_Text_1, DaoDaoIsles_KilnIsle_Sign_Text_0, DaoDaoIsles_KilnIsle_Totem_sign_Text_3, DaoDaoIsles_KilnIsle_Totem_sign_Text_4
	goto_if_eq VAR_RESULT, 0, DaoDaoIsles_KilnIsle_Totem_sign_Landfall
	goto_if_eq VAR_RESULT, 1, DaoDaoIsles_KilnIsle_Totem_sign_Kiln
	goto_if_eq VAR_RESULT, 2, DaoDaoIsles_KilnIsle_Totem_sign_Wake
	release
	end

DaoDaoIsles_KilnIsle_Totem_sign_Locked:
	msgbox DaoDaoIsles_KilnIsle_Totem_sign_Text_5, MSGBOX_AUTOCLOSE
	release
	end

DaoDaoIsles_KilnIsle_Totem_sign_Landfall:
	warp MAP_DAO_DAO_ISLES_LANDFALL_ISLE_HNS, 34, 26
	waitstate
	end

DaoDaoIsles_KilnIsle_Totem_sign_Kiln:
	warp MAP_DAO_DAO_ISLES_KILN_ISLE_HNS, 9, 11
	waitstate
	end

DaoDaoIsles_KilnIsle_Totem_sign_Wake:
	warp MAP_DAO_DAO_ISLES_WAKE_ISLE_HNS, 13, 8
	waitstate
	end


DaoDaoIsles_KilnIsle_TrainerBattleHiker::
	trainerbattle_single TRAINER_DAODAO_KILN_HIKER_HNS, DaoDaoIsles_KilnIsle_TrainerBattleHiker_Text_0, DaoDaoIsles_KilnIsle_TrainerBattleHiker_Text_1
	msgbox DaoDaoIsles_KilnIsle_TrainerBattleHiker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_KilnIsle_TrainerBattlePicnicker::
	trainerbattle_single TRAINER_DAODAO_KILN_PICNICKER_HNS, DaoDaoIsles_KilnIsle_TrainerBattlePicnicker_Text_0, DaoDaoIsles_KilnIsle_TrainerBattlePicnicker_Text_1
	msgbox DaoDaoIsles_KilnIsle_TrainerBattlePicnicker_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_KilnIsle_TrainerBattleCamper::
	trainerbattle_single TRAINER_DAODAO_KILN_CAMPER_HNS, DaoDaoIsles_KilnIsle_TrainerBattleCamper_Text_0, DaoDaoIsles_KilnIsle_TrainerBattleCamper_Text_1
	msgbox DaoDaoIsles_KilnIsle_TrainerBattleCamper_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_KilnIsle_TrainerBattleSwimmerLand::
	trainerbattle_single TRAINER_DAODAO_KILN_SWIMMER_2_HNS, DaoDaoIsles_KilnIsle_TrainerBattleSwimmerLand_Text_0, DaoDaoIsles_KilnIsle_TrainerBattleSwimmerLand_Text_1
	msgbox DaoDaoIsles_KilnIsle_TrainerBattleSwimmerLand_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWater::
	trainerbattle_single TRAINER_DAODAO_KILN_SWIMMER_1_HNS, DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWater_Text_0, DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWater_Text_1
	msgbox DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWater_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWaterM::
	trainerbattle_single TRAINER_DAODAO_KILN_SWIMMER_3_HNS, DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWaterM_Text_0, DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWaterM_Text_1
	msgbox DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWaterM_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_KilnIsle_Bench_Heal_Right::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq DaoDaoIsles_KilnIsle_Bench_Heal_Skip
	goto DaoDaoIsles_KilnIsle_Bench_Heal

DaoDaoIsles_KilnIsle_Bench_Heal_Left::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq DaoDaoIsles_KilnIsle_Bench_Heal_Skip
	goto DaoDaoIsles_KilnIsle_Bench_Heal

DaoDaoIsles_KilnIsle_Bench_Heal_Skip:
	end

DaoDaoIsles_KilnIsle_Bench_Heal:
	lock
	faceplayer
	msgbox DaoDaoIsles_KilnIsle_Bench_Heal_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DaoDaoIsles_KilnIsle_Bench_Heal_2
DaoDaoIsles_KilnIsle_Bench_Heal_1::
	callnative UpdateFollowingPokemon
	release
	end

DaoDaoIsles_KilnIsle_Bench_Heal_2:
	fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	applymovement LOCALID_PLAYER, DaoDaoIsles_KilnIsle_Bench_Heal_Movement_0
	waitmovement 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto DaoDaoIsles_KilnIsle_Bench_Heal_1


DaoDaoIsles_KilnIsle_TotemBattle_Trigger_Movement_0:
	walk_in_place_down
	walk_in_place_down
	step_end

DaoDaoIsles_KilnIsle_Bench_Heal_Movement_0:
	face_down
	step_end

DaoDaoIsles_KilnIsle_hns_Movement_FacePlayerUpAfterTotemWarp:
	face_up
	step_end


DaoDaoIsles_KilnIsle_Sign_Text_0:
	.string "KILN ISLE$"

DaoDaoIsles_KilnIsle_House_Sign_Text_0:
	.string "KILN VILLA\p"
	.string "A place for visitors to stay while\n"
	.string "on KILN ISLE.$"

DaoDaoIsles_KilnIsle_Natu_Text_0:
	.string "NATU: TUUUUU!$"

DaoDaoIsles_KilnIsle_OldManOnBench_Text_0:
	.string "Ah the weather is so nice today,\n"
	.string "isn't it?\p"
	.string "I was just feeding the NATU and this\n"
	.string "one decided to join me on my bench!$"

DaoDaoIsles_KilnIsle_TotemBattle_Text_0:
	.string "Mortaar!$"

DaoDaoIsles_KilnIsle_TotemBattle_Text_1:
	.string "Totem MAGMORTAR was defeated!\n"
	.string "It scampered off somewhere…$"

DaoDaoIsles_KilnIsle_TotemBattle_Text_2:
	.string "Prrrob!$"

DaoDaoIsles_KilnIsle_TotemBattle_Text_3:
	.string "Totem PROBOPASS was defeated!\n"
	.string "It scampered off somewhere…$"

DaoDaoIsles_KilnIsle_Totem_sign_Text_0:
	.string "The totem is emanating a strong\n"
	.string "energy…\p"
	.string "Touch the totem to teleport to another\n"
	.string "Isle?$"

DaoDaoIsles_KilnIsle_Totem_sign_Text_1:
	.string "LANDFALL ISLE$"

DaoDaoIsles_KilnIsle_Totem_sign_Text_3:
	.string "WAKE ISLE$"

DaoDaoIsles_KilnIsle_Totem_sign_Text_4:
	.string "CANCEL$"

DaoDaoIsles_KilnIsle_Totem_sign_Text_5:
	.string "A strange totem stands here,\n"
	.string "power is emanating from it…$"

DaoDaoIsles_KilnIsle_TrainerBattleHiker_Text_0:
	.string "I came to the ISLES to hike the\nmountains!$"

DaoDaoIsles_KilnIsle_TrainerBattleHiker_Text_1:
	.string "And down I tumble…$"

DaoDaoIsles_KilnIsle_TrainerBattleHiker_Text_2:
	.string "KILN ISLE has the best hiking!\n"
	.string "It's got lush forests and rugged trails!$"

DaoDaoIsles_KilnIsle_TrainerBattlePicnicker_Text_0:
	.string "Ha! Didn't see me, did you?$"

DaoDaoIsles_KilnIsle_TrainerBattlePicnicker_Text_1:
	.string "I guess the element of surprise isn't\nalways super effective…$"

DaoDaoIsles_KilnIsle_TrainerBattlePicnicker_Text_2:
	.string "It's so lush on KILN ISLE,\n"
	.string "I can easily hide in the trees!$"

DaoDaoIsles_KilnIsle_TrainerBattleCamper_Text_0:
	.string "I want to be the first to prove myself\nto the Totem POKéMON!$"

DaoDaoIsles_KilnIsle_TrainerBattleCamper_Text_1:
	.string "Drat,\nthat's not going to help my case.$"

DaoDaoIsles_KilnIsle_TrainerBattleCamper_Text_2:
	.string "There's a weird Totem further ahead but\n"
	.string "I haven't seen a Totem POKéMON.$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerLand_Text_0:
	.string "Hey! No shoes on the beach!$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerLand_Text_1:
	.string "Ouch,\nwhere's a lifeguard when you need one…$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerLand_Text_2:
	.string "KILN ISLE has the best beaches!\n"
	.string "It's got soft sand and clear waters!$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWater_Text_0:
	.string "Out of my way!\nI'm swimming laps!$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWater_Text_1:
	.string "Not the break I was looking for…$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWater_Text_2:
	.string "GIANT'S REACH has the best beaches!\n"
	.string "Ignore anyone who says otherwise!$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWaterM_Text_0:
	.string "Hah!\nYou need to ride a POKéMON to surf?$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWaterM_Text_1:
	.string "If I hadn't swam myself\nmaybe I would've had the energy to win…$"

DaoDaoIsles_KilnIsle_TrainerBattleSwimmerWaterM_Text_2:
	.string "The current out here is strong!\n"
	.string "A POKéMON must be really powerful to\l"
	.string "migrate all the way out to the ISLES!$"

DaoDaoIsles_KilnIsle_Bench_Heal_Text_0:
	.string "Would you like to take a rest on this\n"
	.string "bench?$"

DaoDaoIsles_KilnIsle_EventScript_HideTotem:
	setflag FLAG_HIDE_DAODAO_KILN_TOTEM
	return
