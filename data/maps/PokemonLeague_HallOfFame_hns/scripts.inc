PokemonLeague_HallOfFame_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_HallOfFame_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame
	.byte 0

@ PROF.OAK registers the title defenses, LANCE the first and second entries. Both stand on
@ (5,11); one temp flag hides whoever is not walking the player in.
PokemonLeague_HallOfFame_OnTransition:
	goto_if_set FLAG_IS_KANTO_CHAMPION, PokemonLeague_HallOfFame_EventScript_OakEscorts
	setflag FLAG_TEMP_13
	end

PokemonLeague_HallOfFame_EventScript_OakEscorts:
	setflag FLAG_TEMP_12
	end

PokemonLeague_HallOfFame_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 6, PokemonLeague_HallOfFame_EventScript_Cutscene
	.2byte 0

@ Branched like LANCE's own script in the CHAMPION's ROOM: a JOHTO champion without the
@ sixteenth badge re-runs the LEAGUE against LANCE's first team, and that win is a repeat,
@ not the KANTO clear. Keying the KANTO clear on FLAG_IS_CHAMPION alone handed out its
@ unlocks early, and falling through to the first clear would rewind NEW BARK to 6
@ (a second call from ELM and a second S.S. TICKET).
PokemonLeague_HallOfFame_EventScript_Cutscene::
	lock
	goto_if_set FLAG_IS_KANTO_CHAMPION, PokemonLeague_HallOfFame_EventScript_CutsceneTitleDefense
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_HallOfFame_EventScript_CutsceneChampion
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_CutsceneChampion:
	goto_if_set FLAG_BADGE16_GET, PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_Repeat_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	setvar VAR_LEAGUE_STATE, 1
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp::
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_Rematch_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_CutsceneTitleDefense::
	@ OAK takes the path LANCE walks for the first two entries
	applymovement LOCALID_HALLOFFAME_OAK, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_OAK
	msgbox PokemonLeague_HallOfFame_TitleDefense_OakText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_SetGameClearFlags
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_HNS
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags::
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_SLOWPOKE_WELL_TAILLESS_SLOWPOKES
	clearflag FLAG_HIDE_AZALEA_TOWN_TAILED_SLOWPOKES
	clearflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setvar VAR_LEAGUE_STATE, 1
	setvar VAR_NEWBARK_TOWN_STATE, 6
	setvar VAR_SSAQUA_STATE, 0
	return

PokemonLeague_HallOfFame_EventScript_SetGameClearFlags::
	setflag FLAG_HIDE_CERULEANCAVE_GUARD
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_SLOWPOKE_WELL_TAILLESS_SLOWPOKES
	clearflag FLAG_HIDE_AZALEA_TOWN_TAILED_SLOWPOKES
	clearflag FLAG_HIDE_LATIOS
	clearflag FLAG_HIDE_LATIAS
	clearflag FLAG_HIDE_RAYQUAZA
	clearflag FLAG_HIDE_GROUDON
	clearflag FLAG_HIDE_KYOGRE
	clearflag FLAG_HIDE_MEWTWO
	clearflag FLAG_HIDE_VERMILION_SNORLAX
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_ARTICUNO
	clearflag FLAG_HIDE_MOLTRES
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setflag FLAG_IS_KANTO_CHAMPION
	@ Refightable trainers
	cleartrainerflag TRAINER_MORI_HNS
	cleartrainerflag TRAINER_SARI_HNS
	cleartrainerflag TRAINER_LORELEI_HNS
	cleartrainerflag TRAINER_AGATHA_HNS
	cleartrainerflag TRAINER_ELITE_SIDNEY_HNS
	cleartrainerflag TRAINER_ELITE_PHOEBE_HNS
	cleartrainerflag TRAINER_ELITE_GLACIA_HNS
	cleartrainerflag TRAINER_ELITE_DRAKE_HNS
	setvar VAR_COMPLETED_LUGIA, 4
	clearflag FLAG_HIDE_LUGIA
	setvar VAR_COMPLETED_HO_OH, 4
	clearflag FLAG_HIDE_HO_OH
	call PokemonLeague_HallOfFame_EventScript_SpawnRoamers
	call_if_ge VAR_SUICUNE_ENCOUNTERS, 8, PokemonLeague_HallOfFame_EventScript_SpawnSuicune
	call_if_set FLAG_CAUGHT_CELEBI, PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi
	call_if_ge VAR_VIRIDIAN_FOREST_PICHU, 4, PokemonLeague_HallOfFame_EventScript_SpawnPichu
	call_if_set FLAG_DEFEATED_DAODAO_LAB_GIDEON, PokemonLeague_HallOfFame_EventScript_SpawnAlolaMons
	call PokemonLeague_HallOfFame_EventScript_SpawnSinjohMons
	call PokemonLeague_HallOfFame_EventScript_SpawnDaoDaoLegendaries
	call_if_ge VAR_SINJOH_STORYLINE, 13 PokemonLeague_HallOfFame_EventScript_SpawnArceus
	call PokemonLeague_HallOfFame_EventScript_SpawnSinjohTrio
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_CAUGHT_MEW
	clearflag FLAG_BATTLED_DEOXYS
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_SUMMONED_MTMOON_JIRACHI
	setvar VAR_LEAGUE_STATE, 1
	return

PokemonLeague_HallOfFame_EventScript_SpawnAlolaMons::
	clearflag FLAG_HIDE_CAMERUPT
	clearflag FLAG_HIDE_DAODAO_SCORIA_CAVE_SALAZZLE
	clearflag FLAG_HIDE_TSAREENA
	clearflag FLAG_HIDE_DRAPION
	clearflag FLAG_HIDE_TOXICROAK
	clearflag FLAG_HIDE_PROBOPASS
	clearflag FLAG_HIDE_DAODAO_BARB_HOLLOW_BARBARACLE
	clearflag FLAG_HIDE_DAODAO_BINGCURRENT_CAVE_KLAWF
	clearflag FLAG_HIDE_DAODAO_BINGCURRENT_CAVE_MIMIKYU
	return

@ The DAODAO legendaries, knocked out rather than caught. A caught one keeps its *_TAKEN flag
@ and stays gone; the chambers and the lab re-derive their objects on the next visit.
PokemonLeague_HallOfFame_EventScript_SpawnDaoDaoLegendaries::
	clearflag FLAG_DAODAO_REGIROCK_KNOCKED_OUT
	clearflag FLAG_DAODAO_REGISTEEL_KNOCKED_OUT
	clearflag FLAG_DAODAO_REGICE_KNOCKED_OUT
	clearflag FLAG_DAODAO_REGIELEKI_KNOCKED_OUT
	clearflag FLAG_DAODAO_REGIDRAGO_KNOCKED_OUT
	clearflag FLAG_DAODAO_GENESECT_KNOCKED_OUT
	goto_if_unset FLAG_DAODAO_REGIGIGAS_KNOCKED_OUT, PokemonLeague_HallOfFame_EventScript_SpawnDaoDaoLegendaries_Ret
	clearflag FLAG_DAODAO_REGIGIGAS_KNOCKED_OUT
	setflag FLAG_DAODAO_REGIGIGAS_RESPAWNED
PokemonLeague_HallOfFame_EventScript_SpawnDaoDaoLegendaries_Ret:
	return

PokemonLeague_HallOfFame_EventScript_SpawnSinjohMons::
	clearflag FLAG_HIDE_SINJOHRUINS_REGIROCK
	clearflag FLAG_HIDE_SINJOHRUINS_REGICE
	clearflag FLAG_HIDE_SINJOHRUINS_REGISTEEL
	clearflag FLAG_HIDE_SINJOHRUINS_REGIELEKI
	clearflag FLAG_HIDE_SINJOHRUINS_REGIDRAGO
	clearflag FLAG_HIDE_SINJOHRUINS_REGIGIGAS
	return

PokemonLeague_HallOfFame_EventScript_SpawnArceus::
	clearflag FLAG_HIDE_SINJOHRUINS_ARCEUSROOM_ARCEUS
	return

@ A member of the creation trio that was knocked out in the Sinjoh Ruins' Deep Hall can be called
@ at its altar again. A caught one cannot: the Pokedex caught flag tells the two apart.
PokemonLeague_HallOfFame_EventScript_SpawnSinjohTrio::
	getcaughtmon SPECIES_DIALGA
	call_if_eq VAR_RESULT, FALSE, PokemonLeague_HallOfFame_EventScript_FreeDialga
	getcaughtmon SPECIES_PALKIA
	call_if_eq VAR_RESULT, FALSE, PokemonLeague_HallOfFame_EventScript_FreePalkia
	getcaughtmon SPECIES_GIRATINA
	call_if_eq VAR_RESULT, FALSE, PokemonLeague_HallOfFame_EventScript_FreeGiratina
	return

PokemonLeague_HallOfFame_EventScript_FreeDialga:
	clearflag FLAG_SINJOH_DIALGA_GONE
	return

PokemonLeague_HallOfFame_EventScript_FreePalkia:
	clearflag FLAG_SINJOH_PALKIA_GONE
	return

PokemonLeague_HallOfFame_EventScript_FreeGiratina:
	clearflag FLAG_SINJOH_GIRATINA_GONE
	return

PokemonLeague_HallOfFame_EventScript_SpawnPichu::
	clearflag FLAG_HIDE_VIRIDIAN_FOREST_SPIKY_EARED_PICHU
	return

PokemonLeague_HallOfFame_EventScript_SpawnRoamers::
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	special InitRoamer
	copyvar VAR_0x8004, VAR_ROAMER_POKEMON_HNS
	special InitKantoRoamers
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	return

PokemonLeague_HallOfFame_EventScript_SpawnSuicune::
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

PokemonLeague_HallOfFame_EventScript_SpawnSecondCelebi::
	clearflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
	return

PokemonLeague_HallOfFame_Movement_LanceEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

PokemonLeague_HallOfFame_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

PokemonLeague_HallOfFame_LanceText:
    .string "LANCE: It's been a long time since I\n"
    .string "last came here.\p"
    .string "This is where we honor the LEAGUE\n"
    .string "CHAMPIONS for all eternity.\p"
    .string "Their courageous POKéMON are also\n"
    .string "inducted.\p"
    .string "Here today, we witnessed the rise\n"
    .string "of a new LEAGUE CHAMPION--a\p"
    .string "trainer who feels compassion for,\n"
    .string "and trust toward, all POKéMON.\p"
    .string "A trainer who succeeded through\n"
    .string "perseverance and determination.\p"
    .string "The new LEAGUE CHAMPION who has\n"
    .string "all the makings of greatness!\p"
    .string "{PLAYER}, allow me to register you\n"
    .string "and your partners as CHAMPIONS!$"

PokemonLeague_HallOfFame_Repeat_LanceText:
    .string "LANCE: Back again, {PLAYER}.\p"
    .string "Holding on to a title is harder\n"
    .string "than winning it.\p"
    .string "Your POKéMON will be honored\n"
    .string "here once more.$"

PokemonLeague_HallOfFame_Rematch_LanceText:
    .string "LANCE: I remember, it wasn't long ago\n"
    .string "I stood here, welcoming you as\p"
    .string "the CHAMPION of JOHTO.\p"
    .string "And now, here we are again, in this\n"
    .string "sacred place where we honor the very\p"
    .string "best trainers and their POKéMON.\p"
    .string "Today, you've proven yourself not\n"
    .string "just in JOHTO, but in KANTO as well,\l"
    .string "besting even my strongest team.\p"
    .string "You've shown remarkable compassion\n"
    .string "and trust in your POKéMON,\l"
    .string "a bond that has carried you to\l"
    .string "victory time and again.\p"
    .string "Your journey, marked by\n"
    .string "perseverance and unwavering\l"
    .string "determination,\l"
    .string "speaks to your true spirit as a\l"
    .string "trainer.\p"
    .string "You have all the makings of a true\n"
    .string "great, perhaps even the greatest.\p"
    .string "{PLAYER}, it is my honor to register\n"
    .string "you, and your trusted partners,\l"
    .string "as champions once again.$"

PokemonLeague_HallOfFame_TitleDefense_OakText:
	.string "PROF.OAK: Ah, {PLAYER}!\n"
	.string "Another challenger turned back!\p"
	.string "I came as soon as I heard.\n"
	.string "You've defended the title!\p"
	.string "Let's record this victory, and\n"
	.string "your POKéMON, here in the\l"
	.string "HALL OF FAME.$"
