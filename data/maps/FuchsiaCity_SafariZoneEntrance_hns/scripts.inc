FuchsiaCity_SafariZoneEntrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZoneEntrance_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_SafariZoneEntrance_OnTransition
	.byte 0

@ ⚠️ The welcome is keyed on VAR_SAFARI_WELCOME, NOT on
@ VAR_KANTO_SAFARI_ZONE_PROGRESS, and the two are not the same question.
@ PROGRESS is the SAFARI LEVEL (1-4, sold by the attendant, read by the habitat
@ gates). Because the FEDERATION lockdown can fire before the welcome, level 0 is
@ reachable in a staffed lobby after PAXTON, and the two meanings have to be apart.
@
@ The automatic welcome below plays ONLY before the arc (state 0). A player who
@ skipped it is inducted by STEVEN himself: on the road after JANINE
@ (FuchsiaCity_EventScript_StevenSafariAside), or here when they talk to him from
@ state 4 on - both through FuchsiaCity_SafariZoneEntrance_EventScript_StevenInduction.
@
@ ⚠️ And it MUST be a var, not a flag: map_script_2 can only key on a var. That
@ also means this script can never simply bail - TryRunOnFrameMapScript re-tests
@ the key on every input poll (src/field_control_avatar.c:192), so a script that
@ returns without changing it re-fires forever. Suppressing the welcome is done by
@ setting the var elsewhere - in ON_TRANSITION below - never by an early goto here.
@ The three entries are mutually exclusive, so their order carries no meaning:
@ the welcome is disarmed on every load from state 1 on, the siege briefing is
@ only armed from state 1, and VAR_SAFARI_ZONE_STATE is only 2 while the player
@ is inside the safari itself.
FuchsiaCity_SafariZoneEntrance_OnFrame::
	map_script_2 VAR_SAFARI_WELCOME, 0, FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari
	map_script_2 VAR_FUCHSIA_SCENE, 1, FuchsiaCity_SafariZoneEntrance_EventScript_StevenSiegeBriefing
	.2byte 0

@ ⚠️ ONE STEVEN OBJECT, RELOCATED - NOT two objects with complementary flags.
@ Two were tried and produced a visible bug: the moment PAXTON's defeat did
@ `clearflag FLAG_HIDE_SAFARI_STAFF`, TrySpawnObjectEvents spawned the peacetime
@ STEVEN on the player's very next step (it spawns any in-window template whose
@ flag is clear, src/event_object_movement.c:3153) while the siege STEVEN was
@ still on the floor. Two STEVENs, and a scene that had to swap them in front of
@ the player.
@
@ A hide flag only stops FUTURE spawns; it never removes what is already spawned.
@ So "the swap happens on the next map load" is false for anything the player can
@ still be standing on the map for.
@
@ With one object there is nothing to swap: he is at (12,5) in his header, moved to
@ (11,6) for the siege, and he walks out of the fight at the aftermath.
FuchsiaCity_SafariZoneEntrance_OnTransition::
	call_if_ge VAR_FUCHSIA_FEDERATION_STATE, 1, FuchsiaCity_SafariZoneEntrance_DisarmWelcome
	goto_if_unset FLAG_HIDE_SAFARI_FEDERATION, FuchsiaCity_SafariZoneEntrance_SiegeStaging
	call_if_eq VAR_SAFARI_WELCOME, 0, FuchsiaCity_SafariZoneEntrance_FirstTime
	end

@ ⚠️ THE AUTOMATIC WELCOME IS FOR STATE 0 ONLY, and this is what enforces it,
@ whatever left the var at 0 - an old save, the Route 15 test NPC, anything later.
@ ON_TRANSITION runs before ON_FRAME, so the latch is down before it is read.
@ It matters most in the siege: MeetSteven's walk back to his table assumes he
@ starts at FirstTime's (4,10), but during the siege he stands at (11,6), and
@ from there the same up-4/right-7/up-2 took him through the wall to (19,1),
@ off this 15-wide map - scripted movement ignores collision. He vanished until
@ the next load put him back.
FuchsiaCity_SafariZoneEntrance_DisarmWelcome::
	setvar VAR_SAFARI_WELCOME, 1
	return

@ Siege only, and exact: FLAG_HIDE_SAFARI_FEDERATION is clear only while the
@ FEDERATION holds the building. His header tile stays (12,5), and because
@ LoadObjEventTemplatesFromHeader runs BEFORE ON_TRANSITION on every map load
@ (src/overworld.c:924 vs :942) this override is transient - nothing has to put
@ him back afterwards.
FuchsiaCity_SafariZoneEntrance_SiegeStaging::
	setobjectxyperm LOCALID_SAFARIZONEFUCHSIA_STEVEN, 11, 6
	setobjectmovementtype LOCALID_SAFARIZONEFUCHSIA_STEVEN, MOVEMENT_TYPE_FACE_LEFT
	end

@ ⚠️ This exists because objects at y<=5 are NOT spawned when the player stands on
@ the entry warp at y=13 - the spawn window is ty in [py-7, py+9] - and
@ applymovement on a despawned object is a silent no-op (src/script_movement.c:27).
@ So the welcome relocates STEVEN to (4,10) to be inside the window at all.
@ Reached by call_if_eq, so it returns (SiegeStaging above is a goto target and
@ ends the whole ON_TRANSITION script, which is why that one may `end`).
FuchsiaCity_SafariZoneEntrance_FirstTime::
	setobjectxyperm LOCALID_SAFARIZONEFUCHSIA_STEVEN, 4, 10
	setobjectmovementtype LOCALID_SAFARIZONEFUCHSIA_STEVEN, MOVEMENT_TYPE_FACE_LEFT
	return

FuchsiaCity_SafariZoneEntrance_EventScript_ExitSafari::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	release
	end
 
FuchsiaCity_SafariZoneEntrance_EventScript_ReenterSafari::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 0
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MeetSteven::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN
	@ State 0 only - see DisarmWelcome. A player who skips this is inducted later
	@ by StevenInduction below, never by this cutscene.
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase

	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable
	waitmovement 0
	@ PROGRESS 1 is SAFARI LEVEL 1; WELCOME 1 disarms the ON_FRAME latch. Both,
	@ every time - setting only one of them is how this scene fires twice or
	@ strands the player at a counter that wants a case they never got.
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 1
	setvar VAR_SAFARI_WELCOME, 1
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	return

@ ===[ THE LATE INDUCTION - for a player who skipped the welcome ]============
@ Moritz, 2026-09-26: visiting the SAFARI ZONE before the FEDERATION arrive is NOT
@ a requirement, but a player who skipped it is told what the place is and gets
@ the {POKEBLOCK} CASE after JANINE - and only if that has not happened already.
@
@ Shared by two callers, each with its own opener:
@   FuchsiaCity_EventScript_StevenSafariAside  - the road outside the GYM, after
@                                                JANINE (the case Moritz asked for)
@   StevenInductionHere, below                 - his talk script here, from state
@                                                4 on: a player who walks in
@                                                between PAXTON and JANINE, or
@                                                who lost the fight on the road
@ The upgrade clerk tells a level-0 player "Have a word with STEVEN first. He'll
@ see you signed in", and this is what makes that true.
@
@ PROGRESS 1 is SAFARI LEVEL 1 and WELCOME 1 keeps the automatic welcome down;
@ both are set every time, like MeetSteven does.
FuchsiaCity_SafariZoneEntrance_EventScript_StevenInduction::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenInduction, MSGBOX_DEFAULT
	closemessage
	checkitem ITEM_POKEBLOCK_CASE
	call_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenGiveCase
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 1
	setvar VAR_SAFARI_WELCOME, 1
	return

FuchsiaCity_SafariZoneEntrance_EventScript_StevenInductionHere::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenInductionHere, MSGBOX_DEFAULT
	call FuchsiaCity_SafariZoneEntrance_EventScript_StevenInduction
	return

FuchsiaCity_SafariZoneEntrance_Text_StevenGiveCase:
	.string "Oh and you might need this.$"

@ ⚠️ The faceplayer is in the BRANCHES, not here. During the siege he must never
@ look away from the fight; everywhere else facing the player is correct.
FuchsiaCity_SafariZoneEntrance_Steven::
	lock
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, FuchsiaCity_SafariZoneEntrance_EventScript_StevenAfterFederation
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 1, FuchsiaCity_SafariZoneEntrance_EventScript_StevenUnderSiege
	goto FuchsiaCity_SafariZoneEntrance_EventScript_StevenNormal

@ ⚠️ ORDER MATTERS, and every step before the idle lines must be able to fall
@ through. Case first, then the ticket/trade (which ends the script only when it
@ actually has something to offer), then exactly one idle line.
FuchsiaCity_SafariZoneEntrance_EventScript_StevenNormal::
	faceplayer
	@ Recovery path for the case. giveitem prints its own bag-full line and leaves
	@ the outcome in VAR_0x8007, which nothing branches on - so a full Key Items
	@ pocket during the welcome lost the case silently, and the entrance counter
	@ refuses entry without one. Offering it again here means the only way to be
	@ stuck is to never talk to the man standing in the room. It comes FIRST: the
	@ ticket and the trade are optional, the case is the way into the SAFARI.
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenReplaceCase
	call FuchsiaCity_SafariZoneEntrance_EventScript_StevenTicketAndTrade
	@ Idle lines, most recent beat first: the BELDUM once it is traded, GIDEON's
	@ fate once the arc is closed, and the SAFARI small talk before that.
	goto_if_set FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED, FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_SafariZoneEntrance_EventScript_StevenGideonAccountedFor
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Steven, MSGBOX_NPC
	release
	end

@ ===[ THE EON TICKET, THEN THE BELDUM TRADE - shared by both STEVENs ]========
@ Moritz, 2026-09-30: the STEVEN here and the one at GIANT'S REST both offer the
@ ticket and then the trade, so the player is free to go after REGIGIGAS or not.
@ He is here until REGIGIGAS is gone (his hide flag is FLAG_HIDE_DAODAO_REGIGIGAS)
@ and at GIANT'S REST from then on, so exactly one of them is ever offering.
@
@ The gates are unchanged: the ticket once the player is KANTO Champion, the
@ trade while they hold it. The trade repeats until it is done - a decline says
@ the offer stands, and a wrong species is asked for again - because BELDUM,
@ METANG and METAGROSS have no other source.
@
@ It ends the script only when it has something to OFFER - the ticket to a
@ Champion without one, the trade to a ticket holder who has not traded - and
@ returns otherwise, so the caller can say its own line.
@ ⚠️ The ticket is a key item and is never consumed, so "holds the ticket" stays
@ true forever. Branching to Steven_Trade on that alone sent every later talk to
@ StevenTradeCompleted's `end`, and everything after the call - the case
@ recovery, the GIDEON line - became unreachable. Hence the explicit
@ trade-completed test.
FuchsiaCity_SafariZoneEntrance_EventScript_StevenTicketAndTrade::
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenTryGiveTicket
	goto_if_unset FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED, FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade
	return

FuchsiaCity_SafariZoneEntrance_EventScript_StevenTryGiveTicket::
	goto_if_set FLAG_IS_KANTO_CHAMPION, FuchsiaCity_SafariZoneEntrance_StevenChamp
	return

FuchsiaCity_SafariZoneEntrance_EventScript_StevenReplaceCase::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenReplaceCase, MSGBOX_DEFAULT
	checkitemspace ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNoRoomForCase
	giveitem ITEM_POKEBLOCK_CASE
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNoRoomForCase::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenNoRoomForCase, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenReplaceCase:
	.string "You came through without a\n"
	.string "{POKEBLOCK} CASE?\p"
	.string "That won't do. The gate won't let\n"
	.string "you past without one.\p"
	.string "Here. Take another.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenNoRoomForCase:
	.string "…There's no room for it.\p"
	.string "Make some space and ask me again.\n"
	.string "I'm not going anywhere.$"

@ ===[ THE SIEGE BRIEFING - fires on walking in, once, during the lockdown ]====
@ Armed by BeginLockdown (VAR_FUCHSIA_SCENE 1) and disarmed here (2). This replaced
@ a pokenavcall that fired on the player's first step into FUCHSIA CITY: in person
@ it is a better scene, and it removes the awkwardness of a phone call from a man
@ the player may never have met - VERMILION's introduction is skippable.
@
@ ⚠️ HE DOES NOT TURN HERE EITHER, for the same reason as his talk script: he
@ cannot disengage. He speaks with his back to the player.
@
@ ⚠️ ONE TILE OF MARGIN ON THE SPAWN WINDOW. The player enters on the warp at
@ (5,13), and objects only spawn for ty in [py-7, py+9] = [6,22]. STEVEN is at
@ (11,6) during the siege, exactly on the top edge, so the applymovement below
@ works - but anything moved in this scene must stay at y>=6. The mons at y=5 are
@ NOT spawned yet when this runs, and applymovement on a despawned object is a
@ silent no-op (src/script_movement.c:27).
FuchsiaCity_SafariZoneEntrance_EventScript_StevenSiegeBriefing::
	lock
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenSiegeBriefing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FUCHSIA_SCENE, 2
	release
	end

@ Absorbs what the deleted PokeNav call carried - the police are all at
@ TANGLEBRUSH and nobody is coming - together with why a former CHAMPION is stuck.
@ Text_StevenUnderSiege stays as the shorter re-read on his talk script.
FuchsiaCity_SafariZoneEntrance_Text_StevenSiegeBriefing:
	.string "STEVEN: Don't come any closer.\p"
	.string "…{PLAYER}. Of course it's you.\p"
	.string "I called the police three days ago.\n"
	.string "Every officer in KANTO is at\l"
	.string "TANGLEBRUSH digging out a cache of\l"
	.string "these people's. Nobody is coming.\p"
	.string "They have my attendants in the back\n"
	.string "room. The one giving the orders has\l"
	.string "not taken his eyes off me since.\p"
	.string "So I hold this spot, and I can do\n"
	.string "nothing else. If I break off, or take\l"
	.string "one step towards him, somebody in\l"
	.string "there pays for it.\p"
	.string "You can move. I can't.\p"
	.string "Please.$"

@ ⚠️ HE NEVER TURNS. No faceplayer and no turnobject anywhere in here: the whole
@ point of the scene is that he cannot disengage, so talking to him must not make
@ him break off and look at the player. The exclamation-mark beat is how he
@ acknowledges them instead - the same device FuchsiaCity_EventScript_JanineFighting
@ uses, minus the turn.
@ ⚠️ MSGBOX_DEFAULT + closemessage for the first line, not AUTOCLOSE: that one
@ releases the player, who could then walk off mid-scene.
FuchsiaCity_SafariZoneEntrance_EventScript_StevenUnderSiege::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenSiegeCommand, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_SAFARIZONEFUCHSIA_STEVEN
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenUnderSiege, MSGBOX_DEFAULT
	closemessage
	release
	end

@ ===[ THE SIEGE TABLEAU ]=====================================================
@ A standing scene staged like JANINE's fight in FUCHSIA, not a cutscene, so the
@ y<=5 spawn-window hazard cannot bite it. STEVEN is WINNING and that is the
@ point: a Champion-tier trainer stood idle through four states of his own
@ building being held, and his own dialogue admitted it.
@
@   y=5   BIKER1(8,5 >)  MAGNETON(9,5 v)
@   y=6                      (9,6)        SKARMORY(10,6 <)  STEVEN(11,6 <)
@   y=7   BIKER2(8,7 >)  PRIMEAPE(9,7 ^)
@
@ Each biker stands beside his own mon and watches it. Both mons and the bird all
@ face (9,6), which is left EMPTY on purpose: it is the contested space between
@ them, so the three read as trading blows at range rather than nose to nose.
@ STEVEN is directly behind SKARMORY, facing the same way.
@
@ (9,6) is itself UNREACHABLE - the two mons, the bird and the bikers seal it and
@ (8,6) off - which is the wanted outcome: the player cannot stand in the middle
@ of the battle. SKARMORY is talked to from (10,5) or (10,7) instead.
@
@ ⚠️ SKARMORY MUST KEEP A REACHABLE EMPTY NEIGHBOUR. An earlier arrangement put it
@ on (9,6) with the two mons, STEVEN and a biker boxing it in on all four sides,
@ and since column 8 reaches the rest of the map only through (8,7)/(8,8) its
@ flavour text became unreadable. Re-check with the talkability pass after moving
@ anything in here.
@
@ The bikers and the mons are locked on each other and deliberately do NOT
@ faceplayer, so reading their flavour never breaks the composition. Nobody boasts:
@ the winner gives one clipped order, the losers concede, and the mon text carries
@ the score.
FuchsiaCity_SafariZoneEntrance_EventScript_SiegeBiker1::
	lock
	msgbox FuchsiaCity_SafariZoneEntrance_Text_SiegeBiker1, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_SiegeBiker2::
	lock
	msgbox FuchsiaCity_SafariZoneEntrance_Text_SiegeBiker2, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_SiegeSkarmory::
	lock
	waitse
	playmoncry SPECIES_SKARMORY, CRY_MODE_NORMAL
	msgbox FuchsiaCity_SafariZoneEntrance_Text_SiegeSkarmory, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_SiegeMagneton::
	lock
	msgbox FuchsiaCity_SafariZoneEntrance_Text_SiegeMagneton, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_SiegePrimeape::
	lock
	msgbox FuchsiaCity_SafariZoneEntrance_Text_SiegePrimeape, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenSiegeCommand:
	.string "STEVEN: SKARMORY, hold.\p"
	.string "Neither of them gets past you.$"

@ MAGNETON is Electric and PRIMEAPE is Fighting - both of them beat a Steel/Flying
@ bird on paper. That is deliberate: SKARMORY is winning on handling, not on a
@ type advantage, which is what makes it read as STEVEN rather than as luck.
FuchsiaCity_SafariZoneEntrance_Text_SiegeBiker1:
	.string "Don't talk to me. I'm counting.\p"
	.string "Nine minutes that bird's been up\n"
	.string "there. Hasn't flapped twice.$"

FuchsiaCity_SafariZoneEntrance_Text_SiegeBiker2:
	.string "We had him two on one.\p"
	.string "Two on one, and he tells it to HOLD.\p"
	.string "Not to win. To hold.\p"
	.string "…Who is this guy?$"

FuchsiaCity_SafariZoneEntrance_Text_SiegeSkarmory:
	.string "SKARMORY has not left the tile it\n"
	.string "started on.\p"
	.string "Its wings are set, and both of the\n"
	.string "others are watching them instead of\l"
	.string "each other.$"

FuchsiaCity_SafariZoneEntrance_Text_SiegeMagneton:
	.string "MAGNETON's three eyes are all on the\n"
	.string "SKARMORY.\p"
	.string "It has been holding a charge for a\n"
	.string "long while and has not been given\l"
	.string "anywhere to put it.$"

FuchsiaCity_SafariZoneEntrance_Text_SiegePrimeape:
	.string "PRIMEAPE is shaking with temper.\p"
	.string "Every time it commits, the steel\n"
	.string "wing is already there, and it has to\l"
	.string "begin again.$"

FuchsiaCity_SafariZoneEntrance_EventScript_StevenAfterFederation::
	faceplayer
	@ The late induction, for a player still on SAFARI LEVEL 0 - see StevenInduction.
	call_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_EventScript_StevenInductionHere
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_EventScript_StevenReplaceCase
	@ No ">= 6" branch here: state 6 goes through StevenCharterDone to StevenNormal,
	@ which ends on the GIDEON line after offering the ticket and the trade.
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 5, FuchsiaCity_SafariZoneEntrance_EventScript_StevenCharterDone
	goto_if_unset FLAG_DEFEATED_VERMILION_GYM, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady
	goto_if_unset FLAG_DEFEATED_CELADON_GYM, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady
	goto_if_unset FLAG_DEFEATED_SAFFRON_GYM, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady
	goto_if_unset FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineBattle
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenAccept, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN_KANTO_HNS, FuchsiaCity_SafariZoneEntrance_Text_StevenBattleBeaten
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenBattleAfter, MSGBOX_DEFAULT
	setvar VAR_FUCHSIA_FEDERATION_STATE, 5
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotReady::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenGideonAccountedFor::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenGideonAccountedFor, MSGBOX_DEFAULT
	closemessage
	release
	end

@ ⚠️ This used to ANNOUNCE the name, at the arc's close, to a player who had just
@ beaten the man. It is a closing note now: the name was spoken back in FUCHSIA and
@ what is new here is that it is finished.
FuchsiaCity_SafariZoneEntrance_Text_StevenGideonAccountedFor:
	.string "You found him.\p"
	.string "Out past the DAODAO ISLES, of all\n"
	.string "places. The docks had him going\l"
	.string "west, and I did not want to\l"
	.string "believe it.\p"
	.string "He was the last name anyone was\n"
	.string "still carrying.\p"
	.string "The FEDERATION is closed.\n"
	.string "Thank you, {PLAYER}.$"

FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineBattle::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenDecline, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenCharterDone::
	@ GIDEON beaten means the ship has sailed, whatever FLAG_VISITED_DAODAO says.
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNormal
	goto_if_set FLAG_VISITED_DAODAO, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNormal
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenCharterReminder, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_StevenChamp::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenChamp, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenChamp:
	.string "Oh, hey {PLAYER}.\n"
	.string "Or should I say KANTO champion?\p"
	.string "You know, for some time, I was the\n"
	.string "champion of the HOENN region.\p"
	.string "So welcome to the club, {PLAYER}.\p"
	.string "In fact, here.\n"
	.string "Consider this a welcome gift.$"

FuchsiaCity_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	goto_if_lt VAR_FUCHSIA_FEDERATION_STATE, 1, FuchsiaCity_SafariZoneEntrance_EventScript_CounterOpen
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, FuchsiaCity_SafariZoneEntrance_EventScript_CounterOpen
	msgbox FuchsiaCity_SafariZoneEntrance_Text_CounterShut, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter

FuchsiaCity_SafariZoneEntrance_EventScript_CounterOpen::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase
	call FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 4, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft
	call_if_eq VAR_TEMP_0, 6, FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	setflag FLAG_IN_KANTO_SAFARI_ZONE
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_BEACH_HNS, 1
	waitstate
	end

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CorrectionLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	return

FuchsiaCity_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

FuchsiaCity_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_up
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_WalkToPlayer:
	walk_right
	walk_down
	step_end

FuchsiaCity_SafariZoneEntrance_Movement_ReturnToTable:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

FuchsiaCity_SafariZoneEntrance_Text_StevenWelcome:
	.string "Hello again, {PLAYER}!\p"
	.string "Welcome to the DEVON SAFARI ZONE!\p"
	.string "This specially designed safari\n"
	.string "has 4 different habitats that\l"
	.string "attract and house different invasive\l"
	.string "species from the HOENN region.\p"
	.string "We encourage trainers to capture\n"
	.string "as many as they can to safely\l"
	.string "remove them from the environment.\p"
	.string "You'll find very rare POKéMON\n"
	.string "here. Especially if you increase\l"
	.string "your SAFARI LEVEL.\p"
	.string "Just speak to the attendant here\n"
	.string "any time to increase your SAFARI\l"
	.string "LEVEL.$"

@ The opener for StevenInductionHere - talked to in this building. The road
@ outside the GYM has its own, FuchsiaCity_Text_StevenSafariAside.
FuchsiaCity_SafariZoneEntrance_Text_StevenInductionHere:
	.string "{PLAYER}. Good.\p"
	.string "You have been in this building once,\n"
	.string "and it was not at its best.\p"
	.string "Let me do this properly.$"

@ The same four facts as Text_StevenWelcome - four habitats, invasive species from
@ HOENN, rare POKéMON, SAFARI LEVEL and who sells it - in the register of a man
@ showing someone round a place they just helped him get back. It cannot say
@ "Hello again!" or "Welcome to the DEVON SAFARI ZONE!": this player has been in
@ here exactly once, during a hostage situation. Location-neutral, because it is
@ said both in here and out on the road.
FuchsiaCity_SafariZoneEntrance_Text_StevenInduction:
	.string "The DEVON SAFARI ZONE has four\n"
	.string "habitats, built to draw in invasive\l"
	.string "species out of the HOENN region and\l"
	.string "hold them somewhere they can do no\l"
	.string "harm.\p"
	.string "Trainers catch as many as they can\n"
	.string "and we call it a service. It is one.\p"
	.string "There are POKéMON in there you will\n"
	.string "not find anywhere else, and more of\l"
	.string "them the higher your SAFARI LEVEL.\p"
	.string "The attendant by the door raises it,\n"
	.string "whenever you can afford him.\p"
	.string "The pens are being restocked. It is\n"
	.string "the least of what they took.$"

@ ⚠️ A level-0 player can stand in a STAFFED lobby: one who skipped the welcome
@ and walks in after PAXTON. The NotYet branch catches them - the fall-through
@ below would otherwise thank a non-member for their membership - and sends them
@ to STEVEN, whose talk script inducts them (StevenInductionHere).
FuchsiaCity_SafariZoneEntrance_UpgradeGuy::
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotYet
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 1, FuchsiaCity_SafariZoneEntrance_UpgradeGuy1
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 2, FuchsiaCity_SafariZoneEntrance_UpgradeGuy2
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 3, FuchsiaCity_SafariZoneEntrance_UpgradeGuy3
	msgbox FuchsiaCity_SafariZoneEntrance_Text_MaxLevel, MSGBOX_NPC
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy1::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 200000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 200000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 2
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy2::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 300000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 300000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 3
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuy3::
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZoneEntrance_Text_Level3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline
	checkmoney 400000
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney
	removemoney 400000
	updatemoneybox 0
	playse SE_SHOP
	waitse
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted, MSGBOX_NPC
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 4
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotYet::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyNotYet, MSGBOX_NPC
	end

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyNotYet:
	.string "I handle SAFARI LEVELS, but you're\n"
	.string "not on the register yet.\p"
	.string "Have a word with STEVEN first. He'll\n"
	.string "see you signed in.$"

FuchsiaCity_SafariZoneEntrance_UpgradeGuyDecline::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_UpgradeGuyNotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_NPC
	hidemoneybox
	end

FuchsiaCity_SafariZoneEntrance_Text_Steven:
	.string "Oh, hey, {PLAYER}.\p"
	.string "I hope you're enjoying the SAFARI.\p"
	.string "Have you seen any rare stones\n"
	.string "lately?$"

FuchsiaCity_SafariZoneEntrance_Text_Level1:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 2? It will cost you ¥200,000.$"

FuchsiaCity_SafariZoneEntrance_Text_Level2:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 3? It will cost you ¥300,000.$"

FuchsiaCity_SafariZoneEntrance_Text_Level3:
	.string "Hello {PLAYER}, would you\n"
	.string "like to increase your SAFARI LEVEL\l"
	.string "to 4? It will cost you ¥400,000.$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyDeclined:
	.string "Oh, that's too bad, then...$"

FuchsiaCity_SafariZoneEntrance_Text_UpgradeGuyAccepted:
	.string "Enjoy the premium SAFARI ZONE\n"
	.string "experience!$"

FuchsiaCity_SafariZoneEntrance_EventScript_Steven_Trade::
	goto_if_set FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED, FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted
	ingame_trade INGAME_TRADE_BELDUM, FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade, FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon, FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare
	setflag FLAG_FUCHSIA_SAFARI_NPC_TRADE_COMPLETED
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenDeclineTrade::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_EventScript_StevenTradeCompleted::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_StevenWantToTrade:
	.string "Say, {PLAYER}…\n"
	.string "I've been raising this BELDUM\l"
	.string "for a while now.\p"
	.string "But I think it would do better\n"
	.string "with a trainer like you.\p"
	.string "Would you trade me a {STR_VAR_1}\n"
	.string "for my {STR_VAR_2}?$"

FuchsiaCity_SafariZoneEntrance_Text_StevenTakeCare:
	.string "Excellent!\n"
	.string "Please take good care of IRON.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenDeclineTrade:
	.string "That's all right.\n"
	.string "The offer stands if you change\l"
	.string "your mind.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenNotRequestedMon:
	.string "Hmm, that's not a {STR_VAR_1}.\n"
	.string "That's not quite what I had\l"
	.string "in mind.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenTradeCompleted:
	.string "How is IRON doing?\n"
	.string "BELDUM are fascinating POKéMON.\p"
	.string "They communicate with each other\n"
	.string "using magnetic pulses.$"

FuchsiaCity_SafariZoneEntrance_Text_MaxLevel:
	.string "Hello {PLAYER}, thank you for\n"
	.string "continuing to be a premium member\l"
	.string "at the FUCHSIA SAFARI ZONE.$"

@ ===[ THE SHOWDOWN - STATES 3 TO 6 ]=========================================
@ GIL and BRIX can be taken in either order; PAXTON will not fight until both
@ are down, which forces the whole gauntlet without dictating a sequence.
@
@ The PAXTON battle is where the tie lands, and it lands in the AUDIO: his party
@ entry carries `Music: Rocket`, so the TEAM ROCKET battle theme plays before any
@ character has said the words. His team does the rest - CROBAT and WEEZING are
@ biker mon, but RHYDON and NIDOKING are GIOVANNI's. Nobody ever says
@ "TEAM ROCKET" out loud in this whole arc.
@
@ ⚠️ The party itself is Moritz's and is hand-maintained in trainers_hns.party -
@ do not edit it from here. If the team changes, this comment is what goes stale:
@ it already had to drop PERSIAN once when the ace became ANNIHILAPE.

FuchsiaCity_SafariZoneEntrance_EventScript_Gil::
	trainerbattle_single TRAINER_GIL_HNS, FuchsiaCity_SafariZoneEntrance_Text_GilSeen, FuchsiaCity_SafariZoneEntrance_Text_GilBeaten
	msgbox FuchsiaCity_SafariZoneEntrance_Text_GilAfter, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_SafariZoneEntrance_EventScript_Brix::
	trainerbattle_single TRAINER_BRIX_HNS, FuchsiaCity_SafariZoneEntrance_Text_BrixSeen, FuchsiaCity_SafariZoneEntrance_Text_BrixBeaten
	msgbox FuchsiaCity_SafariZoneEntrance_Text_BrixAfter, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_SafariZoneEntrance_EventScript_Paxton::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_GIL_HNS, FuchsiaCity_SafariZoneEntrance_EventScript_PaxtonWait
	goto_if_not_defeated TRAINER_BRIX_HNS, FuchsiaCity_SafariZoneEntrance_EventScript_PaxtonWait
	msgbox FuchsiaCity_SafariZoneEntrance_Text_PaxtonSeen, MSGBOX_DEFAULT
	@ Bookmark, so a save made mid-scene resumes with the tie already surfaced.
	setvar VAR_FUCHSIA_FEDERATION_STATE, 2
	trainerbattle_no_intro TRAINER_PAXTON_HNS, FuchsiaCity_SafariZoneEntrance_Text_PaxtonBeaten
	msgbox FuchsiaCity_SafariZoneEntrance_Text_PaxtonAfter, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setvar VAR_FUCHSIA_FEDERATION_STATE, 3
	setflag FLAG_HIDE_SAFARI_FEDERATION
	clearflag FLAG_HIDE_SAFARI_STAFF
	removeobject LOCALID_SAFARI_PAXTON
	removeobject LOCALID_SAFARI_GIL
	removeobject LOCALID_SAFARI_BRIX
	@ The fight clears in the SAME fade. These four share
	@ FLAG_HIDE_SAFARI_FEDERATION, but the flag alone only takes effect on the next
	@ map load - without these the player would fade back in to STEVEN giving orders
	@ to nobody, then watch the losers blink out a step later.
	@
	@ STEVEN is not in this list and never needs to be: there is only one of him,
	@ his flag (FLAG_HIDE_DAODAO_REGIGIGAS) cannot be set before the ISLES open at
	@ state 5, and he gives the aftermath speech below.
	removeobject LOCALID_SAFARI_SIEGE_BIKER1
	removeobject LOCALID_SAFARI_SIEGE_BIKER2
	removeobject LOCALID_SAFARI_SIEGE_MAGNETON
	removeobject LOCALID_SAFARI_SIEGE_SKARMORY
	removeobject LOCALID_SAFARI_SIEGE_PRIMEAPE
	@ ⚠️ And the staff have to be ADDED, not merely unflagged. clearflag on its own
	@ left the player fading in to an empty lobby, hearing "my attendants are shaken
	@ but they are safe" addressed to nobody, and then eight NPCs popping in one
	@ step later.
	addobject LOCALID_SAFARI_INFO_ATTENDANT
	addobject LOCALID_SAFARI_BLEND_MASTER
	addobject LOCALID_SAFARI_BLENDER_TWIN
	addobject LOCALID_SAFARI_BLENDER_MAN
	addobject LOCALID_SAFARI_BLENDER_GIRL
	addobject LOCALID_SAFARI_BLENDER_BOY
	addobject LOCALID_SAFARI_BLENDER_POKEFAN
	addobject LOCALID_SAFARI_UPGRADE_GUY
	playse SE_EXIT
	fadescreenswapbuffers FADE_FROM_BLACK
	goto FuchsiaCity_SafariZoneEntrance_EventScript_FederationAftermath

FuchsiaCity_SafariZoneEntrance_EventScript_PaxtonWait::
	msgbox FuchsiaCity_SafariZoneEntrance_Text_PaxtonWait, MSGBOX_DEFAULT
	closemessage
	release
	end

@ State 3 -> 4. Restores FUCHSIA itself: the townsfolk come back, JANINE returns
@ to her GYM, the zoo is restocked, and the takeover BGM stops being selected the
@ next time the city map loads. Done here rather than on the city map so the player
@ never sees a half-restored FUCHSIA.
FuchsiaCity_SafariZoneEntrance_EventScript_FederationAftermath::
	@ STEVEN steps west from (11,6) into (10,6) - the tile SKARMORY has just
	@ vacated - so he walks out of the fight rather than out of nowhere, and then
	@ turns to the player he is thanking.
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SAFARIZONEFUCHSIA_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	@ State 4 BEFORE he speaks, so fadedefaultbgm can pick the SAFARI theme:
	@ IsFederationTakeover (src/overworld.c) selects the takeover song for states
	@ 1-3, and without this it played on in a rescued lobby until the next load.
	setvar VAR_FUCHSIA_FEDERATION_STATE, 4
	fadedefaultbgm
	msgbox FuchsiaCity_SafariZoneEntrance_Text_StevenAftermath, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_FUCHSIA_NPCS
	setflag FLAG_HIDE_FUCHSIA_FEDERATION
	setflag FLAG_HIDE_FUCHSIA_JANINE_FIGHT
	clearflag FLAG_HIDE_FUCHSIA_JANINE
	closemessage
	release
	end

FuchsiaCity_SafariZoneEntrance_Text_CounterShut:
	.string "The SAFARI ZONE is closed.\p"
	.string "Nobody is taking tickets while\n"
	.string "those people are inside.$"

FuchsiaCity_SafariZoneEntrance_Text_GilSeen:
	.string "DEVON walks in, buys the SAFARI\n"
	.string "ZONE, and we're supposed to smile?$"

FuchsiaCity_SafariZoneEntrance_Text_GilBeaten:
	.string "Agh! Fine, fine!$"

FuchsiaCity_SafariZoneEntrance_Text_GilAfter:
	.string "This was our ground before it had\n"
	.string "a gate and a ticket price.$"

FuchsiaCity_SafariZoneEntrance_Text_BrixSeen:
	.string "PAXTON said to flatten anyone who\n"
	.string "came through that door.$"

FuchsiaCity_SafariZoneEntrance_Text_BrixBeaten:
	.string "…Not paid enough for this.$"

FuchsiaCity_SafariZoneEntrance_Text_BrixAfter:
	.string "We're not thieves. We're owed.\p"
	.string "That's what the man paying us said,\n"
	.string "anyway.$"

FuchsiaCity_SafariZoneEntrance_Text_PaxtonWait:
	.string "Stay back, kid.\p"
	.string "My people are still counting what's\n"
	.string "in this building.$"

FuchsiaCity_SafariZoneEntrance_Text_PaxtonSeen:
	.string "So you're the one knocking my\n"
	.string "people down.\p"
	.string "Look around. DEVON fenced off the\n"
	.string "marsh, sells tickets to what used\l"
	.string "to be ours, and calls it charity.\p"
	.string "I got run off an island once by\n"
	.string "people who talked like that.\p"
	.string "Not again.\p"
	.string "Someone finally offered to help us\n"
	.string "take it back.\p"
	.string "I didn't ask his name.\n"
	.string "I didn't need to.$"

FuchsiaCity_SafariZoneEntrance_Text_PaxtonBeaten:
	.string "…Should've asked his name.$"

FuchsiaCity_SafariZoneEntrance_Text_PaxtonAfter:
	.string "He told us there'd be a kid.\p"
	.string "Said if a kid from JOHTO turned up,\n"
	.string "we were to leave and say nothing.\p"
	.string "…He knew you'd come.$"

@ ⚠️ This used to say "I can't fight him", which was the plot hole rather than an
@ explanation - he is a former CHAMPION and the FEDERATION are bikers. He is
@ winning now, and still stuck, and the reason he is stuck is the reason the player
@ is needed.
FuchsiaCity_SafariZoneEntrance_Text_StevenUnderSiege:
	.string "{PLAYER}! You shouldn't be in here.\p"
	.string "…No. I am glad you are.\p"
	.string "I can keep these two standing there\n"
	.string "all day. That was never the problem.\p"
	.string "They have my attendants in the back\n"
	.string "room, and the one giving the orders\l"
	.string "has not taken his eyes off me since.\p"
	.string "The moment I break off, or take one\n"
	.string "step towards him, somebody in there\l"
	.string "pays for it.\p"
	.string "So I hold. It is the only thing I am\n"
	.string "any use for in here.\p"
	.string "You can do the rest. Please.$"

@ Plants the thread the reveal outside the GYM pays off: he does not have the name
@ yet, says so, and says he will follow the money to it - which is exactly how he
@ gets it (FuchsiaCity_Text_StevenBackers). PAXTON never knew it either.
FuchsiaCity_SafariZoneEntrance_Text_StevenAftermath:
	.string "It's over…\p"
	.string "My attendants are shaken, but they\n"
	.string "are safe. Thank you, {PLAYER}.\p"
	.string "Did you hear him? He kept saying\n"
	.string "'he'. Never a name.\p"
	.string "Someone paid for all this. Someone\n"
	.string "who knew you were coming before\l"
	.string "I did.\p"
	.string "I intend to find out who. DEVON keeps\n"
	.string "records, and money leaves a trail\l"
	.string "even when men are careful.\p"
	.string "Come and find me once FUCHSIA is\n"
	.string "back on its feet. I have a favor\l"
	.string "to ask you.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenNotReady:
	.string "There's something I want to ask\n"
	.string "of you, {PLAYER}.\p"
	.string "But finish what you came here for\n"
	.string "first. JANINE is back at her GYM.$"

@ ⚠️ He has already named GIDEON out on the road by the time this can be read, so
@ this no longer pretends not to know. The out-of-reach point survives - it is
@ GIDEON's whereabouts that KANTO cannot get at, not his identity.
FuchsiaCity_SafariZoneEntrance_Text_StevenChallenge:
	.string "SURGE, ERIKA, SABRINA, JANINE.\p"
	.string "All four, and the FEDERATION too.\p"
	.string "GIDEON is not in KANTO any more, and\n"
	.string "wherever he has gone, I cannot reach\l"
	.string "it from here.\p"
	.string "I have chartered a boat out of the\n"
	.string "ROUTE 13 dock. I want you on it.\p"
	.string "But not before I've seen for myself\n"
	.string "that you're ready.\p"
	.string "Show me. Here and now?$"

FuchsiaCity_SafariZoneEntrance_Text_StevenAccept:
	.string "Good.\p"
	.string "I won't go easy on you. It would\n"
	.string "be no kindness if I did.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenDecline:
	.string "Then come back when you are.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenBattleBeaten:
	.string "…Yes.\n"
	.string "You're ready.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenBattleAfter:
	.string "That was a fine battle.\p"
	.string "The ship is at the dock on\n"
	.string "ROUTE 13. The captain has his\l"
	.string "orders.\p"
	.string "Find GIDEON, {PLAYER}.\p"
	.string "And be careful out there.$"

FuchsiaCity_SafariZoneEntrance_Text_StevenCharterReminder:
	.string "The boat is waiting at the ROUTE 13\n"
	.string "dock whenever you are.$"
