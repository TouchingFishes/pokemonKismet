FuchsiaCity_Route15_Gate_hns_MapScripts::
	.byte 0

Route15_EventScript_Officer::
	msgbox Route15FuchsiaGate_Text_Officer, MSGBOX_NPC
	end

Route15FuchsiaGate_Text_Officer:
	.string "You're working on a POKéDEX? That's\n"
	.string "really something.\p"
	.string "Don't give up!$"

@ ===========================================================================
@ TEMPORARY TEST NPC - REMOVE BEFORE RELEASE.
@ Also delete his object_event from map.json (3,4) and every FedTest text
@ below.
@
@ Jumps VAR_FUCHSIA_FEDERATION_STATE to any point in the KANTO POKeMON
@ FEDERATION arc and writes the object-visibility flags that go with it.
@
@ ⚠️ WHY A GATE HOUSE AND NOT THE CITY. The eight arc flags decide which
@ objects SPAWN, so they only take effect when a map loads.
@ FuchsiaCity_EventScript_BeginLockdown goes out of its way never to
@ rearrange FUCHSIA while the player is standing in it. Setting a stage out
@ here and then walking west into the city gives it a clean load, which is
@ the only way to see a stage the way a player would.
@
@ ⚠️ THE FLAG BLOCKS ARE ABSOLUTE, NOT DELTAS. The shipping arc only writes
@ the flags that CHANGE at each transition, so the live state is the sum of
@ every transition run so far. A tester jumping straight to the aftermath has
@ run none of them, so each block below writes all eight flags explicitly. Do
@ not fold one back into a delta - it would inherit whatever was on screen
@ before and show a half-dressed city.
@
@ ⚠️ THE STATE NUMBERS ARE 0-6, NOT 0-8. Old 0+1 merged into 0 (the arc is
@ live from a new file and the rumour is the default) and old 2+3 merged into
@ 1 (JANINE fights from the lockdown). Anything still expecting 0-8 is stale.
@
@ Derived from, and must stay in step with - cited by LABEL, because line
@ numbers in those files go stale every time this arc is touched:
@   new_game.inc                                        state 0 (defaults)
@   FuchsiaCity_EventScript_BeginLockdown                state 1
@   FuchsiaCity_EventScript_FederationGuard              state 1, DARIUS down
@   FuchsiaCity_SafariZoneEntrance_EventScript_Paxton    states 2-3
@   FuchsiaCity_SafariZoneEntrance_..._FederationAftermath  state 4
@ ===========================================================================
FuchsiaCity_Route15_Gate_EventScript_FedTestNpc::
	lock
	faceplayer
	message FuchsiaCity_Route15_Gate_Text_FedTestAsk
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, FuchsiaCity_Route15_Gate_Text_FedOpt0, FuchsiaCity_Route15_Gate_Text_FedOpt1, FuchsiaCity_Route15_Gate_Text_FedOpt1b, FuchsiaCity_Route15_Gate_Text_FedOpt2, FuchsiaCity_Route15_Gate_Text_FedOpt3, FuchsiaCity_Route15_Gate_Text_FedOpt4, FuchsiaCity_Route15_Gate_Text_FedOpt5, FuchsiaCity_Route15_Gate_Text_FedOpt6, FuchsiaCity_Route15_Gate_Text_FedOptWelcome, FuchsiaCity_Route15_Gate_Text_FedOptCancel
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_Route15_Gate_EventScript_FedStage0
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_Route15_Gate_EventScript_FedStage1
	goto_if_eq VAR_RESULT, 2, FuchsiaCity_Route15_Gate_EventScript_FedStage1Darius
	goto_if_eq VAR_RESULT, 3, FuchsiaCity_Route15_Gate_EventScript_FedStage2
	goto_if_eq VAR_RESULT, 4, FuchsiaCity_Route15_Gate_EventScript_FedStage3
	goto_if_eq VAR_RESULT, 5, FuchsiaCity_Route15_Gate_EventScript_FedStage4
	goto_if_eq VAR_RESULT, 6, FuchsiaCity_Route15_Gate_EventScript_FedStage5
	goto_if_eq VAR_RESULT, 7, FuchsiaCity_Route15_Gate_EventScript_FedStage6
	goto_if_eq VAR_RESULT, 8, FuchsiaCity_Route15_Gate_EventScript_FedToggleWelcome
	goto FuchsiaCity_Route15_Gate_EventScript_FedCancel

@ --- state 0: rumours. The arc is live but nothing has happened in FUCHSIA.
@ New-file defaults. Walking into FUCHSIA from here fires the lockdown IF the
@ three KANTO gyms and the POWER PLANT errand are done - that is the real
@ trigger now, and it is re-tested on every entry rather than once.
FuchsiaCity_Route15_Gate_EventScript_FedStage0::
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsPreArc
	setvar VAR_FUCHSIA_FEDERATION_STATE, 0
	setvar VAR_FUCHSIA_SCENE, 0
	goto FuchsiaCity_Route15_Gate_EventScript_FedDone

@ --- state 1: the lockdown. FEDERATION holds the city and the SAFARI gate,
@ JANINE is fighting, the zoo pens are empty.
@ SCENE 1 arms STEVEN's siege briefing, so it fires on the first step into the
@ SAFARI building the way it does in a real run. The SAFARI welcome needs no
@ handling here: that building's ON_TRANSITION disarms it from state 1 on.
FuchsiaCity_Route15_Gate_EventScript_FedStage1::
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsLockdown
	setvar VAR_FUCHSIA_FEDERATION_STATE, 1
	setvar VAR_FUCHSIA_SCENE, 1
	goto FuchsiaCity_Route15_Gate_EventScript_FedDone

@ --- state 1, later: DARIUS beaten. Still state 1 - only a flag tells the two
@ apart now, which is why this needs its own entry.
FuchsiaCity_Route15_Gate_EventScript_FedStage1Darius::
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsLockdown
	@ No visibility flag differs from the stage above - it is the four trainer
	@ flags. DARIUS's own is enough to clear the SAFARI ZONE door: his hide flag
	@ is FLAG_TEMP_2, which FuchsiaCity_EventScript_PlaceDarius recomputes from
	@ it on every load of the city.
	setflag TRAINER_FLAGS_START + TRAINER_MACK_HNS
	setflag TRAINER_FLAGS_START + TRAINER_VERN_HNS
	setflag TRAINER_FLAGS_START + TRAINER_HOYT_HNS
	setflag TRAINER_FLAGS_START + TRAINER_DARIUS_HNS
	setvar VAR_FUCHSIA_FEDERATION_STATE, 1
	setvar VAR_FUCHSIA_SCENE, 2
	goto FuchsiaCity_Route15_Gate_EventScript_FedDone

@ --- state 2: PAXTON's bookmark, set mid-battle. Visibility is still the
@ lockdown's: the city is held until PAXTON falls, not until DARIUS does.
FuchsiaCity_Route15_Gate_EventScript_FedStage2::
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsLockdown
	setflag TRAINER_FLAGS_START + TRAINER_MACK_HNS
	setflag TRAINER_FLAGS_START + TRAINER_VERN_HNS
	setflag TRAINER_FLAGS_START + TRAINER_HOYT_HNS
	setflag TRAINER_FLAGS_START + TRAINER_DARIUS_HNS
	setvar VAR_FUCHSIA_FEDERATION_STATE, 2
	setvar VAR_FUCHSIA_SCENE, 2
	goto FuchsiaCity_Route15_Gate_EventScript_FedDone

@ --- state 3: PAXTON beaten, SAFARI staff back, city still occupied.
FuchsiaCity_Route15_Gate_EventScript_FedStage3::
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsPaxtonDown
	setflag TRAINER_FLAGS_START + TRAINER_MACK_HNS
	setflag TRAINER_FLAGS_START + TRAINER_VERN_HNS
	setflag TRAINER_FLAGS_START + TRAINER_HOYT_HNS
	setflag TRAINER_FLAGS_START + TRAINER_DARIUS_HNS
	setvar VAR_FUCHSIA_FEDERATION_STATE, 3
	setvar VAR_FUCHSIA_SCENE, 2
	goto FuchsiaCity_Route15_Gate_EventScript_FedDone

@ --- state 4: aftermath. FUCHSIA restored, JANINE back in her GYM, zoo back.
@ SCENE stays 2: beating JANINE is what arms STEVEN's reveal.
FuchsiaCity_Route15_Gate_EventScript_FedStage4::
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsAftermath
	setvar VAR_FUCHSIA_FEDERATION_STATE, 4
	setvar VAR_FUCHSIA_SCENE, 2
	goto FuchsiaCity_Route15_Gate_EventScript_FedDone

@ --- state 5: STEVEN's charter. Opens the ROUTE 13 boat to the ISLES.
@ SCENE 4 because the charter cannot be reached without the reveal having run.
FuchsiaCity_Route15_Gate_EventScript_FedStage5::
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsAftermath
	setvar VAR_FUCHSIA_FEDERATION_STATE, 5
	setvar VAR_FUCHSIA_SCENE, 4
	goto FuchsiaCity_Route15_Gate_EventScript_FedDone

@ --- state 6: GIDEON beaten, arc closed. FLAG_DEFEATED_DAODAO_LAB_GIDEON is
@ what DaoDaoIsles_RocketLab_SetGideon recomputes the hideout from on every
@ lab entry, so setting it is enough - the lab needs no other help.
FuchsiaCity_Route15_Gate_EventScript_FedStage6::
	call FuchsiaCity_Route15_Gate_EventScript_FedFlagsAftermath
	setvar VAR_FUCHSIA_FEDERATION_STATE, 6
	setvar VAR_FUCHSIA_SCENE, 4
	setflag FLAG_DEFEATED_DAODAO_LAB_GIDEON
	@ Stands in for GIDEON's defeat script, which is where the KANTO cordon lifts.
	call Common_EventScript_ClearKantoCordon
	goto FuchsiaCity_Route15_Gate_EventScript_FedDone

@ ===[ the SAFARI welcome toggle ]============================================
@ The welcome is optional, and which side of it you are on changes where the
@ induction happens. Both paths need testing, and neither is reachable from the
@ other without this.
@   OWED  - level 0, case taken away. At stage 0 the automatic welcome plays on
@           walking into the SAFARI building. From stage 1 that building disarms
@           it by itself, and STEVEN inducts the player instead: on the road after
@           JANINE, or on talk in the SAFARI building from stage 4.
@   TAKEN - level 1, latch down, case handed back if it is missing. The scene
@           after JANINE stays short.
FuchsiaCity_Route15_Gate_EventScript_FedToggleWelcome::
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_Route15_Gate_EventScript_FedWelcomeTake
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 0
	setvar VAR_SAFARI_WELCOME, 0
	removeitem ITEM_POKEBLOCK_CASE, 1
	msgbox FuchsiaCity_Route15_Gate_Text_FedWelcomeOwed, MSGBOX_DEFAULT
	goto FuchsiaCity_Route15_Gate_EventScript_FedClose

FuchsiaCity_Route15_Gate_EventScript_FedWelcomeTake::
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 1
	setvar VAR_SAFARI_WELCOME, 1
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, FALSE, FuchsiaCity_Route15_Gate_EventScript_FedGiveCase
	msgbox FuchsiaCity_Route15_Gate_Text_FedWelcomeTaken, MSGBOX_DEFAULT
	goto FuchsiaCity_Route15_Gate_EventScript_FedClose

FuchsiaCity_Route15_Gate_EventScript_FedGiveCase::
	additem ITEM_POKEBLOCK_CASE
	return

@ ===[ the five flag configurations ]=========================================
@ Eight flags, written in the same order every time so the blocks can be read
@ against each other. Object events hide when their flag is SET.

@ State 0. Matches new_game.inc: townsfolk and the JANINE standoff on, both
@ FEDERATION populations off, zoo on.
FuchsiaCity_Route15_Gate_EventScript_FedFlagsPreArc::
	clearflag FLAG_HIDE_FUCHSIA_NPCS
	setflag   FLAG_HIDE_FUCHSIA_FEDERATION
	setflag   FLAG_HIDE_FUCHSIA_JANINE
	clearflag FLAG_HIDE_FUCHSIA_STANDOFF
	setflag   FLAG_HIDE_FUCHSIA_JANINE_FIGHT
	setflag   FLAG_HIDE_SAFARI_FEDERATION
	clearflag FLAG_HIDE_SAFARI_STAFF
	setflag   FLAG_HIDE_FUCHSIA_STEVEN
	return

@ State 1. The swap: townsfolk out, FEDERATION in on both maps, JANINE fighting
@ from the start, and the ZOO HIDDEN - which is what pays for her four objects.
@ With the pens full this configuration peaks at 18 of 16 slots and objects
@ silently stop spawning.
FuchsiaCity_Route15_Gate_EventScript_FedFlagsLockdown::
	setflag   FLAG_HIDE_FUCHSIA_NPCS
	clearflag FLAG_HIDE_FUCHSIA_FEDERATION
	setflag   FLAG_HIDE_FUCHSIA_JANINE
	setflag   FLAG_HIDE_FUCHSIA_STANDOFF
	clearflag FLAG_HIDE_FUCHSIA_JANINE_FIGHT
	clearflag FLAG_HIDE_SAFARI_FEDERATION
	setflag   FLAG_HIDE_SAFARI_STAFF
	setflag   FLAG_HIDE_FUCHSIA_STEVEN
	return

@ ⚠️ There is no "DARIUS down" flag configuration. He leaves alone rather than
@ taking the whole city FEDERATION with him, and his hide flag is FLAG_TEMP_2,
@ recomputed from his trainer flag on every load of the city - so the stages
@ above only set TRAINER_DARIUS_HNS. The block that used to live here set
@ FLAG_HIDE_FUCHSIA_FEDERATION and is deleted.

@ State 3. PAXTON down: the SAFARI gate is clear and its staff are back, but
@ the city is STILL HELD - the grunts, both door guards and the mart guard only
@ leave at the aftermath.
FuchsiaCity_Route15_Gate_EventScript_FedFlagsPaxtonDown::
	setflag   FLAG_HIDE_FUCHSIA_NPCS
	clearflag FLAG_HIDE_FUCHSIA_FEDERATION
	setflag   FLAG_HIDE_FUCHSIA_JANINE
	setflag   FLAG_HIDE_FUCHSIA_STANDOFF
	clearflag FLAG_HIDE_FUCHSIA_JANINE_FIGHT
	setflag   FLAG_HIDE_SAFARI_FEDERATION
	clearflag FLAG_HIDE_SAFARI_STAFF
	setflag   FLAG_HIDE_FUCHSIA_STEVEN
	return

@ States 4-6. Everything restored, pens refilled. The standoff does NOT come
@ back: it was a pre-arc scene and stays set from the lockdown onward.
FuchsiaCity_Route15_Gate_EventScript_FedFlagsAftermath::
	clearflag FLAG_HIDE_FUCHSIA_NPCS
	setflag   FLAG_HIDE_FUCHSIA_FEDERATION
	clearflag FLAG_HIDE_FUCHSIA_JANINE
	setflag   FLAG_HIDE_FUCHSIA_STANDOFF
	setflag   FLAG_HIDE_FUCHSIA_JANINE_FIGHT
	setflag   FLAG_HIDE_SAFARI_FEDERATION
	clearflag FLAG_HIDE_SAFARI_STAFF
	setflag   FLAG_HIDE_FUCHSIA_STEVEN
	return

@ ===[ endings ]==============================================================
FuchsiaCity_Route15_Gate_EventScript_FedDone::
	buffernumberstring STR_VAR_1, VAR_FUCHSIA_FEDERATION_STATE
	msgbox FuchsiaCity_Route15_Gate_Text_FedDone, MSGBOX_DEFAULT
	goto FuchsiaCity_Route15_Gate_EventScript_FedClose

FuchsiaCity_Route15_Gate_EventScript_FedCancel::
	msgbox FuchsiaCity_Route15_Gate_Text_FedCancel, MSGBOX_DEFAULT
	goto FuchsiaCity_Route15_Gate_EventScript_FedClose

FuchsiaCity_Route15_Gate_EventScript_FedClose::
	closemessage
	release
	end

FuchsiaCity_Route15_Gate_Text_FedTestAsk:
	.string "TEST: Which FEDERATION stage?$"

FuchsiaCity_Route15_Gate_Text_FedOpt0:
	.string "0 Rumours$"

FuchsiaCity_Route15_Gate_Text_FedOpt1:
	.string "1 Lockdown$"

FuchsiaCity_Route15_Gate_Text_FedOpt1b:
	.string "1 DARIUS down$"

FuchsiaCity_Route15_Gate_Text_FedOpt2:
	.string "2 Mid PAXTON$"

FuchsiaCity_Route15_Gate_Text_FedOpt3:
	.string "3 PAXTON down$"

FuchsiaCity_Route15_Gate_Text_FedOpt4:
	.string "4 Aftermath$"

FuchsiaCity_Route15_Gate_Text_FedOpt5:
	.string "5 Charter$"

FuchsiaCity_Route15_Gate_Text_FedOpt6:
	.string "6 GIDEON down$"

FuchsiaCity_Route15_Gate_Text_FedOptWelcome:
	.string "Toggle SAFARI welcome$"

FuchsiaCity_Route15_Gate_Text_FedOptCancel:
	.string "Cancel$"

FuchsiaCity_Route15_Gate_Text_FedDone:
	.string "TEST: FEDERATION state {STR_VAR_1}.\p"
	.string "Head west and walk into FUCHSIA so\n"
	.string "the city loads fresh.$"

FuchsiaCity_Route15_Gate_Text_FedWelcomeOwed:
	.string "TEST: SAFARI welcome OWED.\p"
	.string "LEVEL 0, {POKEBLOCK} CASE taken\n"
	.string "off you.\p"
	.string "Stage 0: the welcome plays in the\n"
	.string "SAFARI building.\p"
	.string "Later: STEVEN inducts you on the road\n"
	.string "after JANINE, or when you talk to\l"
	.string "him at the SAFARI from stage 4.$"

FuchsiaCity_Route15_Gate_Text_FedWelcomeTaken:
	.string "TEST: SAFARI welcome TAKEN.\p"
	.string "LEVEL 1, latch down, {POKEBLOCK}\n"
	.string "CASE back if you had lost it.\p"
	.string "STEVEN's scene after JANINE stays\n"
	.string "short.$"

FuchsiaCity_Route15_Gate_Text_FedCancel:
	.string "TEST: Talk to me again when\n"
	.string "you're ready.$"
