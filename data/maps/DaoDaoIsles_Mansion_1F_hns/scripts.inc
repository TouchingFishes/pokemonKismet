DaoDaoIsles_Mansion_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DaoDaoIsles_Mansion_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_Mansion_1F_OnTransition
	.byte 0

DaoDaoIsles_Mansion_1F_OnLoad::
	call_if_set FLAG_DAODAO_MANSION_SWITCH_STATE, DaoDaoIsles_Mansion_EventScript_PressSwitch_1F
	call_if_set FLAG_DAODAO_MANSION_SHORTCUT_OPEN, DaoDaoIsles_Mansion_1F_EventScript_OpenShortcut
	end

@ KAREN and the three rags share FLAG_TEMP_1: there until the MIMIKYU has gone with someone.
DaoDaoIsles_Mansion_1F_OnTransition::
	setflag FLAG_TEMP_1
	goto_if_eq VAR_DOLL_SHRINE_STATE, 1, DaoDaoIsles_Mansion_1F_EventScript_DollRoomQuiet
	goto_if_eq VAR_DOLL_SHRINE_STATE, 2, DaoDaoIsles_Mansion_1F_EventScript_DollRoomQuiet
	clearflag FLAG_TEMP_1
	call DaoDaoIsles_Mansion_1F_EventScript_DealDolls
DaoDaoIsles_Mansion_1F_EventScript_DollRoomQuiet:
	end

DaoDaoIsles_Mansion_1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 0
	call DaoDaoIsles_Mansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

DaoDaoIsles_Mansion_1F_EventScript_Hollis::
	trainerbattle_single TRAINER_DAODAO_MANSION_HOLLIS_HNS, DaoDaoIsles_Mansion_1F_Text_HollisIntro, DaoDaoIsles_Mansion_1F_Text_HollisDefeat
	msgbox DaoDaoIsles_Mansion_1F_Text_HollisPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_1F_EventScript_Tamsin::
	trainerbattle_single TRAINER_DAODAO_MANSION_TAMSIN_HNS, DaoDaoIsles_Mansion_1F_Text_TamsinIntro, DaoDaoIsles_Mansion_1F_Text_TamsinDefeat
	msgbox DaoDaoIsles_Mansion_1F_Text_TamsinPostBattle, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_Mansion_1F_EventScript_ItemCarbos::
	finditem ITEM_CARBOS
	end
DaoDaoIsles_Mansion_1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end
DaoDaoIsles_Mansion_1F_EventScript_ItemProtein::
	finditem ITEM_PROTEIN
	end
DaoDaoIsles_Mansion_1F_EventScript_ItemChillDrive::
	finditem ITEM_CHILL_DRIVE
	end

@ The gate in the plant room's west wall, (16,28..32). The east half is only reached by
@ falling from 3F, and FRLG's way back out was a back door, now removed. The gate unlatches
@ from the plant-room side only and then stays open, so the first trip still goes via 3F.
DaoDaoIsles_Mansion_1F_EventScript_ShortcutGate::
	goto_if_set FLAG_DAODAO_MANSION_SHORTCUT_OPEN, DaoDaoIsles_Mansion_1F_EventScript_ShortcutGateOpen
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_lt VAR_0x8004, 16, DaoDaoIsles_Mansion_1F_EventScript_ShortcutLocked
	msgbox DaoDaoIsles_Mansion_1F_Text_ShortcutLatch, MSGBOX_DEFAULT
	closemessage
	call DaoDaoIsles_Mansion_1F_EventScript_OpenShortcut
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	setflag FLAG_DAODAO_MANSION_SHORTCUT_OPEN
	releaseall
	end

DaoDaoIsles_Mansion_1F_EventScript_ShortcutLocked:
	msgbox DaoDaoIsles_Mansion_1F_Text_ShortcutLocked, MSGBOX_DEFAULT
	releaseall
	end

DaoDaoIsles_Mansion_1F_EventScript_ShortcutGateOpen:
	end

@ The 2F barrier's open tiles (PressSwitch_2F), except the end cap stays solid.
DaoDaoIsles_Mansion_1F_EventScript_OpenShortcut::
	setmetatile 16, 28, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 16, 29, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 16, 30, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 16, 31, METATILE_PokemonMansion_Floor, 0
	setmetatile 16, 32, METATILE_PokemonMansion_Wall_EndCap, 1
	return

DaoDaoIsles_Mansion_1F_EventScript_DealDolls:
	random 3
	switch VAR_RESULT
	case 0, DaoDaoIsles_Mansion_1F_EventScript_DealA
	case 1, DaoDaoIsles_Mansion_1F_EventScript_DealB
	goto DaoDaoIsles_Mansion_1F_EventScript_DealC

DaoDaoIsles_Mansion_1F_EventScript_DealA:
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 8
	setvar VAR_0x8006, 6
	setvar VAR_0x8007, 8
	setvar VAR_0x8008, 11
	setvar VAR_0x8009, 7
	goto DaoDaoIsles_Mansion_1F_EventScript_PlaceDolls

DaoDaoIsles_Mansion_1F_EventScript_DealB:
	setvar VAR_0x8004, 6
	setvar VAR_0x8005, 8
	setvar VAR_0x8006, 2
	setvar VAR_0x8007, 8
	setvar VAR_0x8008, 11
	setvar VAR_0x8009, 7
	goto DaoDaoIsles_Mansion_1F_EventScript_PlaceDolls

DaoDaoIsles_Mansion_1F_EventScript_DealC:
	setvar VAR_0x8004, 11
	setvar VAR_0x8005, 7
	setvar VAR_0x8006, 2
	setvar VAR_0x8007, 8
	setvar VAR_0x8008, 6
	setvar VAR_0x8009, 8
DaoDaoIsles_Mansion_1F_EventScript_PlaceDolls:
	setobjectxyperm LOCALID_DAODAO_MANSION_MIMIKYU, VAR_0x8004, VAR_0x8005
	setobjectxy LOCALID_DAODAO_MANSION_MIMIKYU, VAR_0x8004, VAR_0x8005
	setobjectxyperm LOCALID_DAODAO_MANSION_RAG_1, VAR_0x8006, VAR_0x8007
	setobjectxy LOCALID_DAODAO_MANSION_RAG_1, VAR_0x8006, VAR_0x8007
	setobjectxyperm LOCALID_DAODAO_MANSION_RAG_2, VAR_0x8008, VAR_0x8009
	setobjectxy LOCALID_DAODAO_MANSION_RAG_2, VAR_0x8008, VAR_0x8009
	return

@ Swaps the MIMIKYU with the rag whose local id is in VAR_0x8008, templates and live objects.
@ Positions are read from the templates (1 is TEMPLATE_POSITION, a C enum in
@ constants/field_specials.h), which DealDolls keeps in step with the live objects.
DaoDaoIsles_Mansion_1F_EventScript_SwapMimikyu:
	getobjectxy LOCALID_DAODAO_MANSION_MIMIKYU, 1, VAR_0x8004, VAR_0x8005
	getobjectxy VAR_0x8008, 1, VAR_0x8006, VAR_0x8007
	setobjectxyperm LOCALID_DAODAO_MANSION_MIMIKYU, VAR_0x8006, VAR_0x8007
	setobjectxy LOCALID_DAODAO_MANSION_MIMIKYU, VAR_0x8006, VAR_0x8007
	setobjectxyperm VAR_0x8008, VAR_0x8004, VAR_0x8005
	setobjectxy VAR_0x8008, VAR_0x8004, VAR_0x8005
	return

@ First visit (state 0), in the room's doorway (13,3)-(13,4): KAREN sees the player come in,
@ walks over, looks back at the dolls while she explains, and returns to her place at (10,4).
DaoDaoIsles_Mansion_1F_EventScript_KarenNotices::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DAODAO_MANSION_KAREN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DAODAO_MANSION_KAREN, Common_Movement_Delay48
	waitmovement 0
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8005, 3, DaoDaoIsles_Mansion_1F_EventScript_KarenToDoorTop
	call_if_ne VAR_0x8005, 3, DaoDaoIsles_Mansion_1F_EventScript_KarenToDoorBottom
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenGreets, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DAODAO_MANSION_KAREN, Common_Movement_FaceLeft
	waitmovement 0
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenDolls, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DAODAO_MANSION_KAREN, Common_Movement_FaceRight
	waitmovement 0
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenAsk, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8005, 3, DaoDaoIsles_Mansion_1F_EventScript_KarenBackTop
	call_if_ne VAR_0x8005, 3, DaoDaoIsles_Mansion_1F_EventScript_KarenBackBottom
	setvar VAR_DOLL_SHRINE_STATE, 3
	releaseall
	end

DaoDaoIsles_Mansion_1F_EventScript_KarenToDoorTop:
	applymovement LOCALID_DAODAO_MANSION_KAREN, DaoDaoIsles_Mansion_1F_Movement_KarenToDoorTop
	waitmovement 0
	return

DaoDaoIsles_Mansion_1F_EventScript_KarenToDoorBottom:
	applymovement LOCALID_DAODAO_MANSION_KAREN, DaoDaoIsles_Mansion_1F_Movement_KarenToDoorBottom
	waitmovement 0
	return

DaoDaoIsles_Mansion_1F_EventScript_KarenBackTop:
	applymovement LOCALID_DAODAO_MANSION_KAREN, DaoDaoIsles_Mansion_1F_Movement_KarenBackTop
	waitmovement 0
	return

DaoDaoIsles_Mansion_1F_EventScript_KarenBackBottom:
	applymovement LOCALID_DAODAO_MANSION_KAREN, DaoDaoIsles_Mansion_1F_Movement_KarenBackBottom
	waitmovement 0
	return

@ She is only here at states 0 and 3. At 0 the player got in without passing the doorway; she has
@ explained now, so the doorway must not greet them again.
DaoDaoIsles_Mansion_1F_EventScript_Karen::
	lock
	faceplayer
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenHint, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DOLL_SHRINE_STATE, 3
	release
	end

@ The teens' dolls, left on the dare.
DaoDaoIsles_Mansion_1F_EventScript_Doll::
	lockall
	msgbox DaoDaoIsles_Mansion_1F_Text_Doll, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ A wrong guess. The doll the player is looking at stays put and stays empty: in the dark the
@ MIMIKYU either stays where it is or swaps with the other rag, so it only ever turns up in a
@ doll the player has walked away from.
DaoDaoIsles_Mansion_1F_EventScript_EmptyRag::
	lockall
	msgbox DaoDaoIsles_Mansion_1F_Text_EmptyRag, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_MIMIKYU, CRY_MODE_HIGH_PITCH
	waitmoncry
	setvar VAR_0x8008, LOCALID_DAODAO_MANSION_RAG_1
	goto_if_ne VAR_LAST_TALKED, LOCALID_DAODAO_MANSION_RAG_1, DaoDaoIsles_Mansion_1F_EventScript_OtherRag
	setvar VAR_0x8008, LOCALID_DAODAO_MANSION_RAG_2
DaoDaoIsles_Mansion_1F_EventScript_OtherRag:
	fadescreenswapbuffers FADE_TO_BLACK
	random 2
	call_if_eq VAR_RESULT, 0, DaoDaoIsles_Mansion_1F_EventScript_SwapMimikyu
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

DaoDaoIsles_Mansion_1F_EventScript_Mimikyu::
	lockall
	playse SE_PIN
	applymovement LOCALID_DAODAO_MANSION_MIMIKYU, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_MIMIKYU, CRY_MODE_NORMAL
	waitmoncry
	msgbox DaoDaoIsles_Mansion_1F_Text_ItMoved, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DAODAO_MANSION_KAREN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenFound, MSGBOX_DEFAULT
	msgbox DaoDaoIsles_Mansion_1F_Text_LetItGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_Mansion_1F_EventScript_KeepIt
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenThanks, MSGBOX_DEFAULT
	giveitem ITEM_REAPER_CLOTH
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenComeAlong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DAODAO_MANSION_MIMIKYU, DaoDaoIsles_Mansion_1F_Movement_Heart
	waitmovement 0
	goto DaoDaoIsles_Mansion_1F_EventScript_GoesWithKaren

@ NO: the player battles it. Caught, it is theirs; knocked out, KAREN takes it after all; if
@ the player runs, it hides among the dolls again - never in the one it was just found in.
DaoDaoIsles_Mansion_1F_EventScript_KeepIt:
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenNo, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_MIMIKYU, 45
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DaoDaoIsles_Mansion_1F_EventScript_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DaoDaoIsles_Mansion_1F_EventScript_KnockedOut
	msgbox DaoDaoIsles_Mansion_1F_Text_SlippedBack, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8008, LOCALID_DAODAO_MANSION_RAG_1
	random 2
	goto_if_eq VAR_RESULT, 0, DaoDaoIsles_Mansion_1F_EventScript_SlipAway
	setvar VAR_0x8008, LOCALID_DAODAO_MANSION_RAG_2
DaoDaoIsles_Mansion_1F_EventScript_SlipAway:
	fadescreenswapbuffers FADE_TO_BLACK
	call DaoDaoIsles_Mansion_1F_EventScript_SwapMimikyu
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

DaoDaoIsles_Mansion_1F_EventScript_Caught:
	setvar VAR_DOLL_SHRINE_STATE, 2
	removeobject LOCALID_DAODAO_MANSION_MIMIKYU
	applymovement LOCALID_DAODAO_MANSION_KAREN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenCaught, MSGBOX_DEFAULT
	closemessage
	goto DaoDaoIsles_Mansion_1F_EventScript_KarenLeaves

DaoDaoIsles_Mansion_1F_EventScript_KnockedOut:
	applymovement LOCALID_DAODAO_MANSION_KAREN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox DaoDaoIsles_Mansion_1F_Text_KarenKnockedOut, MSGBOX_DEFAULT
	closemessage
DaoDaoIsles_Mansion_1F_EventScript_GoesWithKaren:
	setvar VAR_DOLL_SHRINE_STATE, 1
DaoDaoIsles_Mansion_1F_EventScript_KarenLeaves:
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_DAODAO_MANSION_KAREN
	removeobject LOCALID_DAODAO_MANSION_MIMIKYU
	removeobject LOCALID_DAODAO_MANSION_RAG_1
	removeobject LOCALID_DAODAO_MANSION_RAG_2
	fadescreen FADE_FROM_BLACK
	releaseall
	end

DaoDaoIsles_Mansion_1F_Movement_Heart:
	emote_heart
	step_end

@ From (10,4) to beside the doorway, on whichever row the player came in.
DaoDaoIsles_Mansion_1F_Movement_KarenToDoorTop:
	walk_right
	walk_up
	walk_right
	step_end

DaoDaoIsles_Mansion_1F_Movement_KarenToDoorBottom:
	walk_right
	walk_right
	step_end

DaoDaoIsles_Mansion_1F_Movement_KarenBackTop:
	walk_left
	walk_down
	walk_left
	face_right
	step_end

DaoDaoIsles_Mansion_1F_Movement_KarenBackBottom:
	walk_left
	walk_left
	face_right
	step_end

@ --- the statue switches, shared by all four floors -------------------------------------------

DaoDaoIsles_Mansion_EventScript_SecretSwitch::
	msgbox DaoDaoIsles_Mansion_Text_PressSecretSwitch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DaoDaoIsles_Mansion_EventScript_DontPressSwitch
	msgbox DaoDaoIsles_Mansion_Text_WhoWouldnt
	goto_if_set FLAG_DAODAO_MANSION_SWITCH_STATE, DaoDaoIsles_Mansion_EventScript_ResetSwitch
	setflag FLAG_DAODAO_MANSION_SWITCH_STATE
	switch VAR_0x8004
	case 0, DaoDaoIsles_Mansion_EventScript_PressSwitch_1F
	case 1, DaoDaoIsles_Mansion_EventScript_PressSwitch_2F
	case 2, DaoDaoIsles_Mansion_EventScript_PressSwitch_3F
	case 3, DaoDaoIsles_Mansion_EventScript_PressSwitch_B1F
	end

DaoDaoIsles_Mansion_EventScript_ResetSwitch::
	clearflag FLAG_DAODAO_MANSION_SWITCH_STATE
	switch VAR_0x8004
	case 0, DaoDaoIsles_Mansion_EventScript_ResetSwitch_1F
	case 1, DaoDaoIsles_Mansion_EventScript_ResetSwitch_2F
	case 2, DaoDaoIsles_Mansion_EventScript_ResetSwitch_3F
	case 3, DaoDaoIsles_Mansion_EventScript_ResetSwitch_B1F
	end

DaoDaoIsles_Mansion_EventScript_DontPressSwitch::
	msgbox DaoDaoIsles_Mansion_Text_NotQuiteYet
	releaseall
	end

DaoDaoIsles_Mansion_EventScript_PressSwitch_1F::
	setmetatile 22, 10, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 23, 10, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 10, METATILE_PokemonMansion_Floor, 0
	setmetatile 22, 11, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 23, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 27, 25, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 28, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 29, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 27, 26, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 28, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 29, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 32, 25, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 33, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 34, 25, METATILE_PokemonMansion_Floor, 0
	setmetatile 32, 26, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 33, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 34, 26, METATILE_PokemonMansion_Floor, 0
	setmetatile 31, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 32, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 33, 18, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 31, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 32, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 33, 19, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile  3, 16, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

DaoDaoIsles_Mansion_EventScript_ResetSwitch_1F::
	setmetatile 22, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 23, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 24, 10, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 22, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 23, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 24, 11, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 27, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 28, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 29, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 27, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 28, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 29, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 32, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 33, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 34, 25, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 32, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 33, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 34, 26, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 31, 18, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 32, 18, METATILE_PokemonMansion_Floor, 0
	setmetatile 33, 18, METATILE_PokemonMansion_Floor, 0
	setmetatile 31, 19, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 32, 19, METATILE_PokemonMansion_Floor, 0
	setmetatile 33, 19, METATILE_PokemonMansion_Floor, 0
	setmetatile  3, 16, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

DaoDaoIsles_Mansion_EventScript_PressSwitch_2F::
	setmetatile 24, 14, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 25, 14, METATILE_PokemonMansion_Floor, 0
	setmetatile 26, 14, METATILE_PokemonMansion_Floor, 0
	setmetatile 24, 15, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 25, 15, METATILE_PokemonMansion_Floor, 0
	setmetatile 26, 15, METATILE_PokemonMansion_Floor, 0
	setmetatile 10, 28, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 10, 29, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 10, 30, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 10, 31, METATILE_PokemonMansion_Floor, 0
	setmetatile 10, 32, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile 12,  4, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 12,  5, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 12,  6, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 12,  7, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 12,  8, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile 19,  4, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

DaoDaoIsles_Mansion_EventScript_ResetSwitch_2F::
	setmetatile 24, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 25, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 26, 14, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 24, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 25, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 26, 15, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 10, 28, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 10, 29, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 10, 30, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 10, 31, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 10, 32, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile 12,  4, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 12,  5, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 12,  6, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 12,  7, METATILE_PokemonMansion_Floor, 0
	setmetatile 12,  8, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile 19,  4, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

DaoDaoIsles_Mansion_EventScript_PressSwitch_3F::
	setmetatile 17, 11, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 18, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 19, 11, METATILE_PokemonMansion_Floor, 0
	setmetatile 17, 12, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 18, 12, METATILE_PokemonMansion_Floor, 0
	setmetatile 19, 12, METATILE_PokemonMansion_Floor, 0
	setmetatile 21,  4, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 21,  5, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 21,  6, METATILE_PokemonMansion_Barrier_Vertical_MidShadow, 1
	setmetatile 21,  7, METATILE_PokemonMansion_Barrier_Vertical_Mid, 1
	setmetatile 21,  8, METATILE_PokemonMansion_Barrier_Vertical_Bottom, 1
	setmetatile 12,  4, METATILE_PokemonMansion_Statue_RedEyes, 0
	return

DaoDaoIsles_Mansion_EventScript_ResetSwitch_3F::
	setmetatile 17, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 18, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 19, 11, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 17, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft, 1
	setmetatile 18, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid, 1
	setmetatile 19, 12, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight, 1
	setmetatile 21,  4, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 21,  5, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 21,  6, METATILE_PokemonMansion_Floor_ShadeFull, 0
	setmetatile 21,  7, METATILE_PokemonMansion_Floor, 0
	setmetatile 21,  8, METATILE_PokemonMansion_Wall_EndCap, 0
	setmetatile 12,  4, METATILE_PokemonMansion_Statue_BlackEyes, 0
	return

DaoDaoIsles_Mansion_EventScript_PressSwitch_B1F::
	setmetatile 33, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 34, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 35, 20, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 33, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft_Basement, 1
	setmetatile 34, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid_Basement, 1
	setmetatile 35, 21, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight_Basement, 1
	setmetatile 16, 26, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 16, 27, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 16, 28, METATILE_PokemonMansion_Barrier_Vertical_MidShadow_Basement, 1
	setmetatile 16, 29, METATILE_PokemonMansion_Barrier_Vertical_Mid_Basement, 1
	setmetatile 16, 30, METATILE_PokemonMansion_Barrier_Vertical_Bottom_Basement, 1
	setmetatile 12,  8, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 12,  9, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 12, 10, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 12, 11, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 12, 12, METATILE_PokemonMansion_Wall_EndCap_Basement, 0
	setmetatile 20, 22, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 21, 22, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 22, 22, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 20, 23, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 21, 23, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 22, 23, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 24, 28, METATILE_PokemonMansion_Statue_RedEyes_Basement, 0
	setmetatile 27,  4, METATILE_PokemonMansion_Statue_RedEyes_Basement, 0
	return

DaoDaoIsles_Mansion_EventScript_ResetSwitch_B1F::
	setmetatile 33, 20, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 34, 20, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 35, 20, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 33, 21, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 34, 21, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 35, 21, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 16, 26, METATILE_PokemonMansion_Wall_EndPost_Mid, 1
	setmetatile 16, 27, METATILE_PokemonMansion_Wall_EndPost_Bottom, 1
	setmetatile 16, 28, METATILE_PokemonMansion_BasementFloor_ShadeFull, 0
	setmetatile 16, 29, METATILE_PokemonMansion_BasementFloor, 0
	setmetatile 16, 30, METATILE_PokemonMansion_Wall_EndCap_Basement, 0
	setmetatile 12,  8, METATILE_PokemonMansion_Barrier_Vertical_TopWall, 1
	setmetatile 12,  9, METATILE_PokemonMansion_Barrier_Vertical_TopBase, 1
	setmetatile 12, 10, METATILE_PokemonMansion_Barrier_Vertical_MidShadow_Basement, 1
	setmetatile 12, 11, METATILE_PokemonMansion_Barrier_Vertical_Mid_Basement, 1
	setmetatile 12, 12, METATILE_PokemonMansion_Barrier_Vertical_Bottom_Basement, 1
	setmetatile 20, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopLeft, 1
	setmetatile 21, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopMid, 1
	setmetatile 22, 22, METATILE_PokemonMansion_Barrier_Horizontal_TopRight, 1
	setmetatile 20, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomLeft_Basement, 1
	setmetatile 21, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomMid_Basement, 1
	setmetatile 22, 23, METATILE_PokemonMansion_Barrier_Horizontal_BottomRight_Basement, 1
	setmetatile 24, 28, METATILE_PokemonMansion_Statue_BlackEyes_Basement, 0
	setmetatile 27,  4, METATILE_PokemonMansion_Statue_BlackEyes_Basement, 0
	return

DaoDaoIsles_Mansion_1F_Text_HollisIntro::
	.string "Who are you?\n"
	.string "There shouldn't be anyone here.$"

DaoDaoIsles_Mansion_1F_Text_HollisDefeat::
	.string "Ouch!$"

DaoDaoIsles_Mansion_1F_Text_HollisPostBattle::
	.string "The basement? Nobody goes down\n"
	.string "there. Nobody sensible, anyway.$"

DaoDaoIsles_Mansion_1F_Text_TamsinIntro::
	.string "W-w-waah! You startled me!\n"
	.string "I thought you were a ghost.$"

DaoDaoIsles_Mansion_1F_Text_TamsinDefeat::
	.string "Tch!\n"
	.string "I can't get any wins.$"

DaoDaoIsles_Mansion_1F_Text_TamsinPostBattle::
	.string "I was exploring here by myself,\n"
	.string "but I feel spooked.\p"
	.string "I ought to go soon.$"

DaoDaoIsles_Mansion_1F_Text_KarenGreets:
	.string "KAREN: Oh? The CHAMPION.\p"
	.string "Here on a dare as well?$"

DaoDaoIsles_Mansion_1F_Text_KarenDolls:
	.string "KAREN: I was told the island kids\n"
	.string "prove their nerve in this house.\p"
	.string "Each one has to leave a doll\n"
	.string "somewhere inside.\p"
	.string "Rumour has it, that the dolls here\n"
	.string "have started to move by themselves.\p"
	.string "I have a different theory:\p"
	.string "As the dolls piled up, something else\n"
	.string "moved in among them.\p"
	.string "One of those rag dolls isn't a doll.\n"
	.string "But it hides whenever I look for it.$"

DaoDaoIsles_Mansion_1F_Text_KarenAsk:
	.string "KAREN: See if it will come out\n"
	.string "for you.$"

DaoDaoIsles_Mansion_1F_Text_KarenHint:
	.string "KAREN: Every doll in this room was\n"
	.string "left here on a dare.\p"
	.string "One of those rag dolls isn't a doll.\n"
	.string "See if it will come out for you.$"

DaoDaoIsles_Mansion_1F_Text_KarenFound:
	.string "KAREN: So that's where you were.\p"
	.string "Strong POKéMON. Weak POKéMON.\n"
	.string "That is only the selfish\l"
	.string "perception of people.\p"
	.string "It wears that rag so that someone\n"
	.string "will love it.\p"
	.string "Let me take it with me. I'll love\n"
	.string "it best of all.$"

DaoDaoIsles_Mansion_1F_Text_KarenThanks:
	.string "KAREN: Thank you.\p"
	.string "Here. Something for a kind trainer.$"

DaoDaoIsles_Mansion_1F_Text_KarenComeAlong:
	.string "KAREN: Come along, little one.$"

DaoDaoIsles_Mansion_1F_Text_KarenNo:
	.string "KAREN: Then show it you mean it.$"

DaoDaoIsles_Mansion_1F_Text_KarenCaught:
	.string "KAREN: It chose well.\p"
	.string "Look after it.$"

DaoDaoIsles_Mansion_1F_Text_KarenKnockedOut:
	.string "KAREN: Too rough.\p"
	.string "I'll take it from here. It will be\n"
	.string "well by the time we reach home.$"

DaoDaoIsles_Mansion_1F_Text_Doll:
	.string "A doll, left behind on a dare.$"

DaoDaoIsles_Mansion_1F_Text_ShortcutLatch:
	.string "The gate is bolted on this side.\p"
	.string "{PLAYER} slid the bolt back!$"

DaoDaoIsles_Mansion_1F_Text_ShortcutLocked:
	.string "The gate won't budge. It's bolted\n"
	.string "from the other side.$"

DaoDaoIsles_Mansion_1F_Text_EmptyRag:
	.string "A rag doll, stitched to look like a\n"
	.string "PIKACHU. It's empty.\p"
	.string "Something has been sleeping in it.$"

DaoDaoIsles_Mansion_1F_Text_ItMoved:
	.string "The rag doll's head flops over.\n"
	.string "It's a MIMIKYU!$"

DaoDaoIsles_Mansion_1F_Text_LetItGo:
	.string "Let the MIMIKYU go with KAREN?$"

DaoDaoIsles_Mansion_1F_Text_SlippedBack:
	.string "The MIMIKYU slipped back in among\n"
	.string "the dolls.$"
