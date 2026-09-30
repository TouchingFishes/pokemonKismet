@ KANTO POKeMON FEDERATION - shared scripts and text for the FUCHSIA takeover.
@
@ THERE IS NO LONGER AN "ARMING" STEP, AND THAT IS DELIBERATE.
@ This file used to hold Common_EventScript_TryArmFederation, called from four
@ endpoints (the three KANTO gyms and the POWER PLANT back room), whichever
@ finished last. It set state 1 = "armed, rumours only", and the lockdown was the
@ state 1 -> 2 step taken on the player's next entry to FUCHSIA.
@
@ Two things were wrong with that:
@
@   1. State 1 was almost never observable. It lasted from the arming call until
@      the player next stepped into FUCHSIA - often seconds - so the rumour
@      dialogue keyed to `== 1` was written and then never read. The arc is live
@      from a new file now and the rumour IS the default, which is what those
@      lines were for.
@
@   2. It could brick a save. All four call sites are one-shot, each sitting
@      inside a first-win branch, so the conditions were tested exactly once
@      apiece and never again. A player who finished all four WITHOUT having met
@      STEVEN at the SAFARI ZONE - optional side content - failed the last check
@      and nothing ever re-checked. The arc never armed, and since
@      FLAG_HIDE_FUCHSIA_JANINE is cleared in exactly one place (the aftermath,
@      which that player can never reach), FUCHSIA GYM had no leader forever: no
@      14th badge, no charter, no ROUTE 13 boat, no DAODAO.
@
@ The conditions now live in FuchsiaCity_EventScript_TryBeginLockdown, called
@ from that map's ON_TRANSITION, so they are re-evaluated on EVERY entry to
@ FUCHSIA and cannot be missed. The SAFARI ZONE condition is gone entirely - see
@ VAR_SAFARI_WELCOME for where the welcome went instead.
@
@ STEVEN's PokeNav call that used to live here is gone too - see the note at the
@ bottom of this file.

@ ===[ THE KANTO CORDON ]=====================================================
@ MT MOON, DIGLETT'S CAVE and TANGLEBRUSH are shut by a police cordon until the
@ player gets back from the ISLES with an answer.
@
@ The fiction is already in the tree and needed no inventing: Route 8's HARRIS
@ complains "The cops shut down our UNDERGROUND PATH! That really fries me!"
@ (data/maps/Route8_hns/scripts.inc:48). So the crackdown on the FEDERATION's
@ tunnels and back roads predates the player, which is why the cordon is up from
@ the moment they reach KANTO rather than appearing after the showdown.
@
@ Blocker objects are hidden when their flag is SET, and hide flags default to
@ CLEAR - so "blocker present" is the default state and nothing needs to set
@ these up on a new file.
Common_EventScript_KantoCordon::
	msgbox Common_Text_KantoCordon, MSGBOX_NPC
	end

Common_Text_KantoCordon:
	.string "Sorry. This way's closed.\p"
	.string "We're still hauling FEDERATION\n"
	.string "contraband out of every tunnel and\l"
	.string "back road in KANTO.\p"
	.string "Soon as we know who was paying\n"
	.string "them, we'll open it up again.$"

@ ===[ TANGLEBRUSH - WHY NOBODY CAME TO HELP STEVEN ]=========================
@ STEVEN's siege briefing says every officer in KANTO is at TANGLEBRUSH. This is
@ why: TANGLEBRUSH is where the FEDERATION's stash turned up, and it has
@ swallowed the entire KANTO force. The cordon stops being a lock and starts
@ being the reason the player has to do this alone.
@
@ ⚠️ Most players will NOT walk past these officers. ROUTE 17 joins ROUTE 18 at
@ offset 24 and FUCHSIA is east, so the TANGLEBRUSH mouth at x=8-9 is a westward
@ detour. The same information is therefore carried where players actually go -
@ STEVEN's briefing in the SAFARI building, and the SAFFRON ROUTE 7 gate guard.
Common_EventScript_TanglebrushCordon::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, Common_EventScript_TanglebrushCordonAfter
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 1, Common_EventScript_TanglebrushCordonCrisis
	msgbox Common_Text_TanglebrushCordon, MSGBOX_NPC
	end

Common_EventScript_TanglebrushCordonCrisis::
	msgbox Common_Text_TanglebrushCordonCrisis, MSGBOX_NPC
	end

Common_EventScript_TanglebrushCordonAfter::
	msgbox Common_Text_TanglebrushCordonAfter, MSGBOX_NPC
	end

Common_Text_TanglebrushCordon:
	.string "Sorry, TANGLEBRUSH is closed.\p"
	.string "We found where the FEDERATION were\n"
	.string "keeping it all. Crates of it.\p"
	.string "Every officer in KANTO who can be\n"
	.string "spared is in here counting.$"

Common_Text_TanglebrushCordonCrisis:
	.string "Still closed. Don't argue.\p"
	.string "Word is FUCHSIA has gone dark and\n"
	.string "there's nobody left to send.\p"
	.string "I know how that sounds.\p"
	.string "If you're headed that way…\n"
	.string "good luck to you.$"

Common_Text_TanglebrushCordonAfter:
	.string "We heard about FUCHSIA.\p"
	.string "A kid walked in and finished it,\n"
	.string "while the whole force stood in\l"
	.string "here counting crates.\p"
	.string "…We'll have this cleared soon.$"

@ ===[ DIGLETT'S CAVE ]=======================================================
@ Not a police cordon - a swarm. Seven DIGLETT wall off both entrance rooms.
@ Blocking only the south end would let a player walk the entire tunnel from
@ ROUTE 2 and be turned back at the far door.
@
@ ⚠️ The two walls are NOT the same shape. South is a straight row at y=4,
@ (2,4) (3,4) (4,4) (5,4). North is an L - (3,3) (3,4) (4,4) - because BROCK
@ stands at (2,3) and a straight row at y=4 sealed him behind it, which killed
@ the only script that moves him to the FIGHTING DOJO. Re-verify either room
@ with `py -3 .claude/walkable.py <map> --reach 3 5`.
@
@ They share FLAG_HIDE_DIGLETTS_CAVE_BLOCKER with the rest of the cordon, so
@ Common_EventScript_ClearKantoCordon still frees them in one place.
Common_EventScript_DiglettSwarm::
	lock
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox Common_Text_DiglettSwarm, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Common_Text_DiglettSwarm:
	.string "A wall of DIGLETT, packed in so\n"
	.string "tight there's no way past.\p"
	.string "Something below has them stirred\n"
	.string "up, and they will not budge.$"

@ ⚠️ THE SINGLE HOOK THAT REOPENS KANTO. Called from exactly one place,
@ DaoDaoIsles_RocketLab_EventScript_GideonDefeated, the moment GIDEON falls (the
@ Route 15 test NPC's stage 6 calls it too, standing in for that script). If the
@ beat moves, move that one `call` line; everything else keys off these flags.
@
@ What it opens: MT MOON, both ends of DIGLETT'S CAVE, both mouths of TANGLEBRUSH,
@ MISTY's GYM (FLAG_ALOLA_CLEARED), and the Route 22 exit of the RECEPTION GATE.
@ That last one is a one-tile plug - the Kanto guard at (14,7) - and behind it
@ lies the whole west of KANTO: VIRIDIAN, PEWTER (BROCK), PALLET, Route 21,
@ CINNABAR and SEAFOAM (BLAINE). Route 19's Kinglers and the unconnected Route
@ 17/18 west water close every other way in, so before GIDEON the player can
@ hold 12 badges and no more (Moritz, 2026-09-30).
Common_EventScript_ClearKantoCordon::
	setflag FLAG_ALOLA_CLEARED
	setflag FLAG_HIDE_MTMOON_BLOCKER
	setflag FLAG_HIDE_DIGLETTS_CAVE_BLOCKER
	setflag FLAG_HIDE_TANGLEBRUSH_BLOCKER
	setflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD
	return

@ ⚠️ STEVEN'S POKENAV CALL IS GONE, deliberately - no speaker name and no call
@ text live here any more.
@
@ It used to fire when the arc armed, from anywhere in KANTO, summoning the player
@ to FUCHSIA. Two problems: with the arc live from a new file there is no arming
@ moment to hang it on, and it could reach a player who had never met him at all,
@ since VERMILION's introduction is skippable (ROUTE 11 runs east to ROUTE 12, not
@ into the cordoned DIGLETT'S CAVE, so the north exit carrying the three
@ VAR_VERMILION_CITY_STEVEN triggers is avoidable).
@
@ He briefs the player IN PERSON instead, on their first step into the occupied
@ SAFARI ZONE building:
@   FuchsiaCity_SafariZoneEntrance_EventScript_StevenSiegeBriefing
@ which absorbed this text's content about the police being at TANGLEBRUSH. The
@ player is pointed up the road by JANINE's fight dialogue and by DARIUS standing
@ on the SAFARI ZONE door, so nothing was lost by dropping the summons.
