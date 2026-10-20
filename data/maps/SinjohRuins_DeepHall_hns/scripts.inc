@ The Deep Hall of the Sinjoh Ruins dungeon (MIGRATION_DECISIONS.md 85). Once ARCEUS has been met
@ (VAR_SINJOH_STORYLINE 13), the altar on the north wall calls the creation trio, one at a time and
@ in the player's order. Each is a boss battle first (no catching, no running) and then, weakened, a
@ catchable one. The next can be called once the last is caught or knocked out; a knocked-out one
@ can be called again after the next Hall of Fame (PokemonLeague_HallOfFame_EventScript_SpawnSinjohTrio).
SinjohRuins_DeepHall_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SinjohRuins_DeepHall_OnTransition
	.byte 0

SinjohRuins_DeepHall_OnTransition:
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	call_if_eq VAR_SINJOH_TRIO_STATE, 1, SinjohRuins_DeepHall_ShowDialga
	call_if_eq VAR_SINJOH_TRIO_STATE, 4, SinjohRuins_DeepHall_ShowDialga
	call_if_eq VAR_SINJOH_TRIO_STATE, 2, SinjohRuins_DeepHall_ShowPalkia
	call_if_eq VAR_SINJOH_TRIO_STATE, 5, SinjohRuins_DeepHall_ShowPalkia
	call_if_eq VAR_SINJOH_TRIO_STATE, 3, SinjohRuins_DeepHall_ShowGiratina
	call_if_eq VAR_SINJOH_TRIO_STATE, 6, SinjohRuins_DeepHall_ShowGiratina
	end

SinjohRuins_DeepHall_ShowDialga:
	clearflag FLAG_TEMP_12
	return

SinjohRuins_DeepHall_ShowPalkia:
	clearflag FLAG_TEMP_13
	return

SinjohRuins_DeepHall_ShowGiratina:
	clearflag FLAG_TEMP_14
	return

@ ---------------------------------------------------------------- the altar
SinjohRuins_DeepHall_EventScript_Altar::
	lockall
	goto_if_lt VAR_SINJOH_STORYLINE, 13, SinjohRuins_DeepHall_EventScript_AltarSilent
	goto_if_ne VAR_SINJOH_TRIO_STATE, 0, SinjohRuins_DeepHall_EventScript_AltarAnswered
	goto_if_unset FLAG_SINJOH_DIALGA_GONE, SinjohRuins_DeepHall_EventScript_AltarCall
	goto_if_unset FLAG_SINJOH_PALKIA_GONE, SinjohRuins_DeepHall_EventScript_AltarCall
	goto_if_unset FLAG_SINJOH_GIRATINA_GONE, SinjohRuins_DeepHall_EventScript_AltarCall
	msgbox SinjohRuins_DeepHall_Text_AltarDark, MSGBOX_DEFAULT
	releaseall
	end

SinjohRuins_DeepHall_EventScript_AltarSilent::
	msgbox SinjohRuins_DeepHall_Text_AltarSilent, MSGBOX_DEFAULT
	releaseall
	end

SinjohRuins_DeepHall_EventScript_AltarAnswered::
	msgbox SinjohRuins_DeepHall_Text_AltarAnswered, MSGBOX_DEFAULT
	releaseall
	end

SinjohRuins_DeepHall_EventScript_AltarCall::
	msgbox SinjohRuins_DeepHall_Text_AltarCall, MSGBOX_DEFAULT
	call_if_unset FLAG_SINJOH_DIALGA_GONE, SinjohRuins_DeepHall_EventScript_PushDialga
	call_if_unset FLAG_SINJOH_PALKIA_GONE, SinjohRuins_DeepHall_EventScript_PushPalkia
	call_if_unset FLAG_SINJOH_GIRATINA_GONE, SinjohRuins_DeepHall_EventScript_PushGiratina
	dynmultipush SinjohRuins_DeepHall_Text_Cancel, 0
	dynmultistack 20, 4, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 1, SinjohRuins_DeepHall_EventScript_CallDialga
	case 2, SinjohRuins_DeepHall_EventScript_CallPalkia
	case 3, SinjohRuins_DeepHall_EventScript_CallGiratina
	closemessage
	releaseall
	end

SinjohRuins_DeepHall_EventScript_PushDialga:
	dynmultipush SinjohRuins_DeepHall_Text_Dialga, 1
	return

SinjohRuins_DeepHall_EventScript_PushPalkia:
	dynmultipush SinjohRuins_DeepHall_Text_Palkia, 2
	return

SinjohRuins_DeepHall_EventScript_PushGiratina:
	dynmultipush SinjohRuins_DeepHall_Text_Giratina, 3
	return

SinjohRuins_DeepHall_EventScript_CallDialga::
	call SinjohRuins_DeepHall_EventScript_Rumble
	setvar VAR_SINJOH_TRIO_STATE, 1
	clearflag FLAG_TEMP_12
	addobject LOCALID_SINJOHRUINS_DEEPHALL_DIALGA
	call SinjohRuins_DeepHall_EventScript_Arrive
	playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox SinjohRuins_DeepHall_Text_DialgaArrives, MSGBOX_DEFAULT
	releaseall
	end

SinjohRuins_DeepHall_EventScript_CallPalkia::
	call SinjohRuins_DeepHall_EventScript_Rumble
	setvar VAR_SINJOH_TRIO_STATE, 2
	clearflag FLAG_TEMP_13
	addobject LOCALID_SINJOHRUINS_DEEPHALL_PALKIA
	call SinjohRuins_DeepHall_EventScript_Arrive
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox SinjohRuins_DeepHall_Text_PalkiaArrives, MSGBOX_DEFAULT
	releaseall
	end

SinjohRuins_DeepHall_EventScript_CallGiratina::
	call SinjohRuins_DeepHall_EventScript_Rumble
	setvar VAR_SINJOH_TRIO_STATE, 3
	clearflag FLAG_TEMP_14
	addobject LOCALID_SINJOHRUINS_DEEPHALL_GIRATINA
	call SinjohRuins_DeepHall_EventScript_Arrive
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox SinjohRuins_DeepHall_Text_GiratinaArrives, MSGBOX_DEFAULT
	releaseall
	end

SinjohRuins_DeepHall_EventScript_Rumble:
	closemessage
	playse SE_ORB
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 15  @ num shakes
	setvar VAR_0x8007, 6   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_THUNDER
	fadescreen FADE_TO_WHITE
	return

SinjohRuins_DeepHall_EventScript_Arrive:
	turnobject LOCALID_PLAYER, DIR_SOUTH
	fadescreen FADE_FROM_WHITE
	return

@ ---------------------------------------------------------------- the battles
@ Phase 1 holds its orb and fights boosted; only a win moves it on (whiteout, Roar or Whirlwind
@ leave it at full strength). Phase 2 is at L80 with no boost and can be caught.
SinjohRuins_DeepHall_EventScript_Dialga::
	lock
	faceplayer
	goto_if_eq VAR_SINJOH_TRIO_STATE, 4, SinjohRuins_DeepHall_EventScript_DialgaWeakened
	playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
	waitmoncry
	call SinjohRuins_DeepHall_EventScript_BossRules
	setwildbossbattle species=SPECIES_DIALGA, level=80, item=ITEM_ADAMANT_ORB, move1_1=MOVE_ROAR_OF_TIME, move1_2=MOVE_FLASH_CANNON, move1_3=MOVE_EARTH_POWER, move1_4=MOVE_AURA_SPHERE
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 0, 1, 1
	call SinjohRuins_DeepHall_EventScript_Battle
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, SinjohRuins_DeepHall_EventScript_Stays
	setvar VAR_SINJOH_TRIO_STATE, 4
SinjohRuins_DeepHall_EventScript_DialgaWeakened::
	playmoncry SPECIES_DIALGA, CRY_MODE_WEAK
	msgbox SinjohRuins_DeepHall_Text_DialgaWeakened, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setwildbossbattle species=SPECIES_DIALGA, level=80, move1_1=MOVE_DRAGON_CLAW, move1_2=MOVE_POWER_GEM, move1_3=MOVE_ANCIENT_POWER, move1_4=MOVE_METAL_CLAW
	call SinjohRuins_DeepHall_EventScript_Battle
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SinjohRuins_DeepHall_EventScript_Stays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SinjohRuins_DeepHall_EventScript_Stays
	setflag FLAG_SINJOH_DIALGA_GONE
	setvar VAR_SINJOH_TRIO_STATE, 0
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SINJOHRUINS_DEEPHALL_DIALGA
	setflag FLAG_TEMP_12
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

SinjohRuins_DeepHall_EventScript_Palkia::
	lock
	faceplayer
	goto_if_eq VAR_SINJOH_TRIO_STATE, 5, SinjohRuins_DeepHall_EventScript_PalkiaWeakened
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
	waitmoncry
	call SinjohRuins_DeepHall_EventScript_BossRules
	setwildbossbattle species=SPECIES_PALKIA, level=80, item=ITEM_LUSTROUS_ORB, move1_1=MOVE_SPACIAL_REND, move1_2=MOVE_HYDRO_PUMP, move1_3=MOVE_EARTH_POWER, move1_4=MOVE_AURA_SPHERE
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 1, 1, 1
	call SinjohRuins_DeepHall_EventScript_Battle
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, SinjohRuins_DeepHall_EventScript_Stays
	setvar VAR_SINJOH_TRIO_STATE, 5
SinjohRuins_DeepHall_EventScript_PalkiaWeakened::
	playmoncry SPECIES_PALKIA, CRY_MODE_WEAK
	msgbox SinjohRuins_DeepHall_Text_PalkiaWeakened, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setwildbossbattle species=SPECIES_PALKIA, level=80, move1_1=MOVE_DRAGON_CLAW, move1_2=MOVE_AQUA_TAIL, move1_3=MOVE_POWER_GEM, move1_4=MOVE_ANCIENT_POWER
	call SinjohRuins_DeepHall_EventScript_Battle
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SinjohRuins_DeepHall_EventScript_Stays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SinjohRuins_DeepHall_EventScript_Stays
	setflag FLAG_SINJOH_PALKIA_GONE
	setvar VAR_SINJOH_TRIO_STATE, 0
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SINJOHRUINS_DEEPHALL_PALKIA
	setflag FLAG_TEMP_13
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

SinjohRuins_DeepHall_EventScript_Giratina::
	lock
	faceplayer
	goto_if_eq VAR_SINJOH_TRIO_STATE, 6, SinjohRuins_DeepHall_EventScript_GiratinaWeakened
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
	waitmoncry
	call SinjohRuins_DeepHall_EventScript_BossRules
	setwildbossbattle species=SPECIES_GIRATINA, level=80, item=ITEM_GRISEOUS_ORB, move1_1=MOVE_SHADOW_FORCE, move1_2=MOVE_DRAGON_CLAW, move1_3=MOVE_EARTH_POWER, move1_4=MOVE_SHADOW_SNEAK
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 0, 0, 1
	call SinjohRuins_DeepHall_EventScript_Battle
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, SinjohRuins_DeepHall_EventScript_Stays
	setvar VAR_SINJOH_TRIO_STATE, 6
SinjohRuins_DeepHall_EventScript_GiratinaWeakened::
	playmoncry SPECIES_GIRATINA, CRY_MODE_WEAK
	msgbox SinjohRuins_DeepHall_Text_GiratinaWeakened, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setwildbossbattle species=SPECIES_GIRATINA, level=80, move1_1=MOVE_SHADOW_CLAW, move1_2=MOVE_DRAGON_CLAW, move1_3=MOVE_ANCIENT_POWER, move1_4=MOVE_SLASH
	call SinjohRuins_DeepHall_EventScript_Battle
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SinjohRuins_DeepHall_EventScript_Stays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SinjohRuins_DeepHall_EventScript_Stays
	setflag FLAG_SINJOH_GIRATINA_GONE
	setvar VAR_SINJOH_TRIO_STATE, 0
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_SINJOHRUINS_DEEPHALL_GIRATINA
	setflag FLAG_TEMP_14
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

SinjohRuins_DeepHall_EventScript_BossRules:
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	return

@ Runs the battle set up by the caller and leaves the outcome in VAR_RESULT.
SinjohRuins_DeepHall_EventScript_Battle:
	special BattleSetup_StartLegendaryBattle
	playbgm MUS_HG_VS_KYOGRE_GROUDON, 0
	waitstate
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	specialvar VAR_RESULT, GetBattleOutcome
	return

SinjohRuins_DeepHall_EventScript_Stays::
	release
	end

@ ---------------------------------------------------------------- text (drafts, MIGRATION_DECISIONS.md 85)
SinjohRuins_DeepHall_Text_AltarSilent:
	.string "An altar of the same stone as\n"
	.string "the PLATES.\p"
	.string "Three hollows are carved into its\n"
	.string "face. Nothing answers.$"

SinjohRuins_DeepHall_Text_AltarCall:
	.string "The hollows in the altar are\n"
	.string "glowing.\p"
	.string "Something on the other side is\n"
	.string "listening.$"

SinjohRuins_DeepHall_Text_AltarAnswered:
	.string "The altar is quiet.\n"
	.string "Its call has been answered.$"

SinjohRuins_DeepHall_Text_AltarDark:
	.string "The hollows in the altar are dark.\n"
	.string "Nothing is left to answer.$"

SinjohRuins_DeepHall_Text_Dialga:
	.string "DIALGA$"

SinjohRuins_DeepHall_Text_Palkia:
	.string "PALKIA$"

SinjohRuins_DeepHall_Text_Giratina:
	.string "GIRATINA$"

SinjohRuins_DeepHall_Text_Cancel:
	.string "CANCEL$"

SinjohRuins_DeepHall_Text_DialgaArrives:
	.string "The air in the hall stops moving.\p"
	.string "For a moment, so does everything\n"
	.string "else.$"

SinjohRuins_DeepHall_Text_PalkiaArrives:
	.string "The far wall is suddenly very close,\n"
	.string "then very far away again.$"

SinjohRuins_DeepHall_Text_GiratinaArrives:
	.string "Every shadow in the hall leans\n"
	.string "the same way.$"

SinjohRuins_DeepHall_Text_DialgaWeakened:
	.string "DIALGA is weakened.\n"
	.string "Now it can be caught!$"

SinjohRuins_DeepHall_Text_PalkiaWeakened:
	.string "PALKIA is weakened.\n"
	.string "Now it can be caught!$"

SinjohRuins_DeepHall_Text_GiratinaWeakened:
	.string "GIRATINA is weakened.\n"
	.string "Now it can be caught!$"
