@ KANTO POKeMON FEDERATION - arming the FUCHSIA takeover.
@
@ The arc starts once the player has beaten SURGE, ERIKA and SABRINA in ANY
@ order AND finished the POWER PLANT machine-part errand. Testing the set rather
@ than a sequence is what keeps that half of KANTO open-world: no gym is ever
@ blocked on another, and FUCHSIA itself stays walkable throughout - the event
@ simply has not armed yet.
@
@ ⚠️ Why this is called from four places instead of checked on a map. There is
@ no map every player passes through after finishing the last of those four
@ things, so there is nowhere to poll. Each of the four endpoints calls this
@ instead, and whichever one completes last is the one that arms the arc. The
@ call is cheap and idempotent: it returns immediately unless the state is still
@ 0 and all four conditions hold.
@
@ Arming only sets state 1 (rumours). The lockdown is state 1 -> 2 and happens in
@ FuchsiaCity_EventScript_BeginLockdown when the player next walks into FUCHSIA,
@ so the city is never rearranged while the player is standing in it.

Common_EventScript_TryArmFederation::
	goto_if_ne VAR_FUCHSIA_FEDERATION_STATE, 0, Common_EventScript_TryArmFederationDone
	goto_if_unset FLAG_DEFEATED_VERMILION_GYM, Common_EventScript_TryArmFederationDone
	goto_if_unset FLAG_DEFEATED_CELADON_GYM, Common_EventScript_TryArmFederationDone
	goto_if_unset FLAG_DEFEATED_SAFFRON_GYM, Common_EventScript_TryArmFederationDone
	@ The POWER PLANT thread must land BEFORE the trip to the ISLES. State 7 is
	@ its last beat - the MACHINE PART returned, TM THUNDER given. It also makes
	@ the theft read as the first, small sign of the backer behind all this.
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 7, Common_EventScript_TryArmFederationDone
	@ ⚠️ The player must have met STEVEN at the SAFARI ZONE at least once.
	@ Two reasons, one fictional and one mechanical. He phones the player below,
	@ which only works if they have met; and his first-visit welcome is an
	@ ON_FRAME cutscene keyed to VAR_KANTO_SAFARI_ZONE_PROGRESS == 0 that also
	@ RELOCATES him to (4,10). Leaving that unfired would either play a cheery
	@ "welcome to the DEVON SAFARI ZONE" over a hostage scene, or strand him
	@ away from the spot the showdown positions him at.
	goto_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, Common_EventScript_TryArmFederationDone
	setvar VAR_FUCHSIA_FEDERATION_STATE, 1
	setspeaker FuchsiaFederation_Text_StevenName
	pokenavcall FuchsiaFederation_Text_StevenWarning
	waitmessage
	delay 30
	closemessage
	return

Common_EventScript_TryArmFederationDone::
	return

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
@ STEVEN's PokeNav call says "the police won't come out this far" and never says
@ why. This is why: TANGLEBRUSH is where the FEDERATION's stash turned up, and
@ it has swallowed the entire KANTO force. The cordon stops being a lock and
@ starts being the reason the player has to do this alone.
@
@ ⚠️ Most players will NOT walk past these officers. ROUTE 17 joins ROUTE 18 at
@ offset 24 and FUCHSIA is east, so the TANGLEBRUSH mouth at x=8-9 is a westward
@ detour. The same information is therefore carried where players actually go -
@ STEVEN's call, and the SAFFRON ROUTE 7 gate guard.
Common_EventScript_TanglebrushCordon::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, Common_EventScript_TanglebrushCordonAfter
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, Common_EventScript_TanglebrushCordonCrisis
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

@ ⚠️ THE SINGLE HOOK THAT REOPENS KANTO. Called from the ALOLA story beat - see
@ the PROVISIONAL note in data/maps/Melemele_PlayerHouse_hns/scripts.inc. If the
@ beat moves, move the one `call` line; everything else keys off these flags.
Common_EventScript_ClearKantoCordon::
	setflag FLAG_ALOLA_CLEARED
	setflag FLAG_HIDE_MTMOON_BLOCKER
	setflag FLAG_HIDE_DIGLETTS_CAVE_BLOCKER
	setflag FLAG_HIDE_TANGLEBRUSH_BLOCKER
	setflag FLAG_HIDE_CINNABAR_BLOCKER
	return

FuchsiaFederation_Text_StevenName:
	.string "STEVEN$"

FuchsiaFederation_Text_StevenWarning:
	.string "STEVEN: {PLAYER}, it's me.\p"
	.string "I'm at the SAFARI ZONE in FUCHSIA.\p"
	.string "We've had bikers at the gate for\n"
	.string "days. The KANTO POKéMON FEDERATION,\l"
	.string "they call themselves.\p"
	.string "I called the police. They're all at\n"
	.string "TANGLEBRUSH, digging out some cache\l"
	.string "of these people's, and there is\l"
	.string "nobody left to send.\p"
	.string "My staff are frightened.\p"
	.string "I wouldn't ask if there were anyone\n"
	.string "else. Please, come to FUCHSIA.$"
