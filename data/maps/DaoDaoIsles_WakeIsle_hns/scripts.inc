DaoDaoIsles_WakeIsle_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_WakeIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DaoDaoIsles_WakeIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

DaoDaoIsles_WakeIsle_EventScript_HideKecleon::
	setvar VAR_TEMP_9, 1
	setflag FLAG_TEMP_1
	removeobject LOCALID_DAODAO_WAKE_KECLEON
	end

DaoDaoIsles_WakeIsle_EventScript_Sidney::
	trainerbattle_single TRAINER_ELITE_SIDNEY_HNS, DaoDaoIsles_WakeIsle_Text_SidneyIntro, DaoDaoIsles_WakeIsle_Text_SidneyDefeat
	msgbox DaoDaoIsles_WakeIsle_Text_SidneyAfter, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_WakeIsle_Text_SidneyIntro:
	.string "Hey. Nobody comes down this end.\p"
	.string "That's the appeal, mostly.\p"
	.string "Gulls in the morning, something with\n"
	.string "worse manners after dark. Suits me\l"
	.string "either way.\p"
	.string "You've got the walk of someone who's\n"
	.string "beaten a few people who mattered.\p"
	.string "I like that. No hard feelings\n"
	.string "whichever way this goes - that's the\l"
	.string "only rule I've got.$"

DaoDaoIsles_WakeIsle_Text_SidneyDefeat:
	.string "Hah! Well, that's that.$"

DaoDaoIsles_WakeIsle_Text_SidneyAfter:
	.string "No hard feelings. Told you.\p"
	.string "Anyway, the sea's not going to\n"
	.string "watch itself.$"

@ -----------------------------------------------------------------------------------------
@ Moved from PoniIsle_hns/scripts.inc (2026-10-08, MIGRATION_DECISIONS 63). Labels kept their
@ names past the prefix; Alola place names in the texts now name the DaoDao isles.
@ -----------------------------------------------------------------------------------------

DaoDaoIsles_WakeIsle_hns_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_unset FLAG_TRIGGERED_DAODAO_WAKE_TOTEM, DaoDaoIsles_WakeIsle_EventScript_HideTotem
	call DaoDaoIsles_WakeIsle_hns_SetTotemSignWarpFacing
	return

DaoDaoIsles_WakeIsle_hns_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_C, 0, DaoDaoIsles_WakeIsle_hns_EventScript_FacePlayerUpAfterTotemWarp
	.2byte 0

DaoDaoIsles_WakeIsle_hns_SetTotemSignWarpFacing:
	setvar VAR_TEMP_C, 1
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	compare VAR_TEMP_A, 13
	goto_if_ne DaoDaoIsles_WakeIsle_hns_SetTotemSignWarpFacing_End
	compare VAR_TEMP_B, 8
	goto_if_eq DaoDaoIsles_WakeIsle_hns_SetTotemSignWarpFacing_Set
	compare VAR_TEMP_B, 9
	goto_if_eq DaoDaoIsles_WakeIsle_hns_SetTotemSignWarpFacing_Set
	goto DaoDaoIsles_WakeIsle_hns_SetTotemSignWarpFacing_End

DaoDaoIsles_WakeIsle_hns_SetTotemSignWarpFacing_Set:
	setvar VAR_TEMP_C, 0

DaoDaoIsles_WakeIsle_hns_SetTotemSignWarpFacing_End:
	return

DaoDaoIsles_WakeIsle_hns_EventScript_FacePlayerUpAfterTotemWarp::
	setvar VAR_TEMP_C, 1
	applymovement LOCALID_PLAYER, DaoDaoIsles_WakeIsle_hns_Movement_FacePlayerUpAfterTotemWarp
	return


DaoDaoIsles_WakeIsle_BattleTsareena::
	lock
	faceplayer
	setflag FLAG_BATTLED_TSAREENA
	playmoncry SPECIES_TSAREENA, 0
	msgbox DaoDaoIsles_WakeIsle_BattleTsareena_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_TSAREENA, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DaoDaoIsles_WakeIsle_BattleTsareena_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_WakeIsle_BattleTsareena_3
	release
	end

	release
	end

DaoDaoIsles_WakeIsle_BattleTsareena_2:
	setflag FLAG_HIDE_TSAREENA
	removeobject LOCALID_DAODAO_WAKE_TSAREENA
	release
	end

DaoDaoIsles_WakeIsle_BattleTsareena_3:
	setflag FLAG_HIDE_TSAREENA
	removeobject LOCALID_DAODAO_WAKE_TSAREENA
	release
	end


DaoDaoIsles_WakeIsle_Island_Sign::
	lock
	msgbox DaoDaoIsles_WakeIsle_Island_Sign_Text_0
	release
	end


DaoDaoIsles_WakeIsle_TotemBattle_Trigger::
	goto_if_unset FLAG_TRIGGERED_DAODAO_WAKE_TOTEM, DaoDaoIsles_WakeIsle_TotemBattle_Trigger_1
	end

DaoDaoIsles_WakeIsle_TotemBattle_Trigger_1:
	goto DaoDaoIsles_WakeIsle_TotemBattle_Trigger_4

DaoDaoIsles_WakeIsle_TotemBattle_Trigger_4:
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
	clearflag FLAG_HIDE_DAODAO_WAKE_TOTEM
	playmoncry SPECIES_ELECTIVIRE, 0
	addobject LOCALID_DAODAO_WAKE_TOTEM
	waitmoncry
	delay 30
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 30
	playmoncry SPECIES_ELECTIVIRE, 0
	applymovement LOCALID_DAODAO_WAKE_TOTEM, DaoDaoIsles_WakeIsle_TotemBattle_Trigger_Movement_0
	waitmovement 0
	waitmoncry
	setflag FLAG_TRIGGERED_DAODAO_WAKE_TOTEM
	release
	end


DaoDaoIsles_WakeIsle_TotemBattle::
	lock
	faceplayer
	playmoncry SPECIES_ELECTIVIRE, 0
	msgbox DaoDaoIsles_WakeIsle_TotemBattle_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_ELECTABUZZ, 60, ITEM_NONE, SPECIES_ELECTIVIRE, 60, ITEM_SHUCA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DaoDaoIsles_WakeIsle_TotemBattle_2
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq DaoDaoIsles_WakeIsle_TotemBattle_4
	@ Any other ending (your Dragon Tail or Circle Throw, say) still undoes the battle flags.
	goto DaoDaoIsles_WakeIsle_TotemBattle_4

DaoDaoIsles_WakeIsle_TotemBattle_2:
	setflag FLAG_HIDE_DAODAO_WAKE_TOTEM
	setflag FLAG_DEFEATED_DAODAO_WAKE_TOTEM
	removeobject LOCALID_DAODAO_WAKE_TOTEM
	msgbox DaoDaoIsles_WakeIsle_TotemBattle_Text_1, MSGBOX_AUTOCLOSE
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

DaoDaoIsles_WakeIsle_TotemBattle_4:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end


DaoDaoIsles_WakeIsle_Totem_sign::
	lock
	goto_if_unset FLAG_DEFEATED_DAODAO_LANDFALL_TOTEM, DaoDaoIsles_WakeIsle_Totem_sign_Locked
	goto_if_unset FLAG_DEFEATED_DAODAO_KILN_TOTEM, DaoDaoIsles_WakeIsle_Totem_sign_Locked
	goto_if_unset FLAG_DEFEATED_DAODAO_WAKE_TOTEM, DaoDaoIsles_WakeIsle_Totem_sign_Locked
	msgbox DaoDaoIsles_WakeIsle_Totem_sign_Text_0
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, DaoDaoIsles_WakeIsle_Totem_sign_Text_1, DaoDaoIsles_WakeIsle_Totem_sign_Text_2, DaoDaoIsles_WakeIsle_Island_Sign_Text_0, DaoDaoIsles_WakeIsle_Totem_sign_Text_4
	goto_if_eq VAR_RESULT, 0, DaoDaoIsles_WakeIsle_Totem_sign_Landfall
	goto_if_eq VAR_RESULT, 1, DaoDaoIsles_WakeIsle_Totem_sign_Kiln
	goto_if_eq VAR_RESULT, 2, DaoDaoIsles_WakeIsle_Totem_sign_Wake
	release
	end

DaoDaoIsles_WakeIsle_Totem_sign_Locked:
	msgbox DaoDaoIsles_WakeIsle_Totem_sign_Text_5, MSGBOX_AUTOCLOSE
	release
	end

DaoDaoIsles_WakeIsle_Totem_sign_Landfall:
	warp MAP_DAO_DAO_ISLES_LANDFALL_ISLE_HNS, 34, 26
	waitstate
	end

DaoDaoIsles_WakeIsle_Totem_sign_Kiln:
	warp MAP_DAO_DAO_ISLES_KILN_ISLE_HNS, 9, 11
	waitstate
	end

DaoDaoIsles_WakeIsle_Totem_sign_Wake:
	warp MAP_DAO_DAO_ISLES_WAKE_ISLE_HNS, 13, 8
	waitstate
	end


DaoDaoIsles_WakeIsle_TrainerBattleSwimmer1::
	trainerbattle_single TRAINER_DAODAO_WAKE_SWIMMER_1_HNS, DaoDaoIsles_WakeIsle_TrainerBattleSwimmer1_Text_0, DaoDaoIsles_WakeIsle_TrainerBattleSwimmer1_Text_1
	msgbox DaoDaoIsles_WakeIsle_TrainerBattleSwimmer1_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_WakeIsle_TrainerBattleSwimmer2::
	trainerbattle_single TRAINER_DAODAO_WAKE_SWIMMER_2_HNS, DaoDaoIsles_WakeIsle_TrainerBattleSwimmer2_Text_0, DaoDaoIsles_WakeIsle_TrainerBattleSwimmer2_Text_1
	msgbox DaoDaoIsles_WakeIsle_TrainerBattleSwimmer2_Text_2, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_WakeIsle_NPC_girl::
	lock
	faceplayer
	msgbox DaoDaoIsles_WakeIsle_NPC_girl_Text_0, MSGBOX_AUTOCLOSE
	release
	end


DaoDaoIsles_WakeIsle_Bench_Heal_Right::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq DaoDaoIsles_WakeIsle_Bench_Heal_Skip
	goto DaoDaoIsles_WakeIsle_Bench_Heal

DaoDaoIsles_WakeIsle_Bench_Heal_Left::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq DaoDaoIsles_WakeIsle_Bench_Heal_Skip
	goto DaoDaoIsles_WakeIsle_Bench_Heal

DaoDaoIsles_WakeIsle_Bench_Heal_Skip:
	end

DaoDaoIsles_WakeIsle_Bench_Heal:
	lock
	faceplayer
	msgbox DaoDaoIsles_WakeIsle_Bench_Heal_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DaoDaoIsles_WakeIsle_Bench_Heal_2
DaoDaoIsles_WakeIsle_Bench_Heal_1:
	callnative UpdateFollowingPokemon
	release
	end

DaoDaoIsles_WakeIsle_Bench_Heal_2:
	fadescreenswapbuffers FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	applymovement LOCALID_PLAYER, DaoDaoIsles_WakeIsle_Bench_Heal_Movement_0
	waitmovement 0
	fadescreenswapbuffers FADE_FROM_BLACK
	goto DaoDaoIsles_WakeIsle_Bench_Heal_1


DaoDaoIsles_WakeIsle_FindItem1::
	finditem ITEM_ICE_STONE, 1
	end


DaoDaoIsles_WakeIsle_TotemBattle_Trigger_Movement_0:
	walk_in_place_down
	walk_in_place_down
	step_end

DaoDaoIsles_WakeIsle_Bench_Heal_Movement_0:
	face_down
	step_end

DaoDaoIsles_WakeIsle_BattleTsareena_Text_0:
	.string "Gaah-aah!$"

DaoDaoIsles_WakeIsle_Island_Sign_Text_0:
	.string "WAKE ISLE$"

DaoDaoIsles_WakeIsle_TotemBattle_Text_0:
	.string "Buzz!!$"

DaoDaoIsles_WakeIsle_TotemBattle_Text_1:
	.string "Totem ELECTIVIRE was defeated!\n"
	.string "It scampered off somewhere…$"

DaoDaoIsles_WakeIsle_hns_Movement_FacePlayerUpAfterTotemWarp:
	face_up
	step_end


DaoDaoIsles_WakeIsle_Totem_sign_Text_0:
	.string "The totem is emanating a strong\n"
	.string "energy…\p"
	.string "Touch the totem to teleport to another\n"
	.string "Isle?$"

DaoDaoIsles_WakeIsle_Totem_sign_Text_1:
	.string "LANDFALL ISLE$"

DaoDaoIsles_WakeIsle_Totem_sign_Text_2:
	.string "KILN ISLE$"

DaoDaoIsles_WakeIsle_Totem_sign_Text_4:
	.string "CANCEL$"

DaoDaoIsles_WakeIsle_Totem_sign_Text_5:
	.string "A strange totem stands here,\n"
	.string "power is emanating from it…$"

DaoDaoIsles_WakeIsle_TrainerBattleSwimmer1_Text_0:
	.string "Warmer water, no problem!$"

DaoDaoIsles_WakeIsle_TrainerBattleSwimmer1_Text_1:
	.string "Gah, I forgot my sunscreen…$"

DaoDaoIsles_WakeIsle_TrainerBattleSwimmer1_Text_2:
	.string "I've swam into so many cool POKéMON!\n"
	.string "It must be something in the water.$"

DaoDaoIsles_WakeIsle_TrainerBattleSwimmer2_Text_0:
	.string "Hey, don't block my current!$"

DaoDaoIsles_WakeIsle_TrainerBattleSwimmer2_Text_1:
	.string "Ugh, fine,\njust let me swim…$"

DaoDaoIsles_WakeIsle_TrainerBattleSwimmer2_Text_2:
	.string "The current is great for tubing.\n"
	.string "I don't think I'll tube anywhere else!$"

DaoDaoIsles_WakeIsle_NPC_girl_Text_0:
	.string "WAKE ISLE is my favorite.\n"
	.string "The wilderness just speaks for itself!$"

DaoDaoIsles_WakeIsle_Bench_Heal_Text_0:
	.string "Would you like to take a rest on this\n"
	.string "bench?$"

DaoDaoIsles_WakeIsle_EventScript_HideTotem:
	setflag FLAG_HIDE_DAODAO_WAKE_TOTEM
	return
