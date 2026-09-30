FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_OnFrame
	.byte 0

@ Both of the FEDERATION arc's city cutscenes, sequenced by one var. They can
@ never be pending at once, so they share it rather than taking two: each scene
@ advances VAR_FUCHSIA_SCENE as its last act, which is what disarms it. Same latch
@ pattern as ViridianCity_OnFrame and VioletCity_OnFrame.
@   1 set by BeginLockdown   -> 2 by the siege briefing, in the SAFARI building
@   3 set by JANINE's defeat -> 4 by the reveal, below
@
@ ⚠️ SCENE 1 IS NOT HANDLED ON THIS MAP. BeginLockdown arms it, but the scene it
@ arms is FuchsiaCity_SafariZoneEntrance_EventScript_StevenSiegeBriefing - STEVEN
@ briefs the player in person, from inside the fight, the moment they walk through
@ that door. It used to be a pokenavcall on the first step into the city; in person
@ it is the better scene, and it drops the problem that a phone call could reach a
@ player who had never met him.
FuchsiaCity_OnFrame::
	map_script_2 VAR_FUCHSIA_SCENE, 3, FuchsiaCity_EventScript_StevenBackers
	.2byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	call_if_eq VAR_FUCHSIA_FEDERATION_STATE, 0, FuchsiaCity_EventScript_TryBeginLockdown
	@ After the lockdown, which may have just set state 1.
	call FuchsiaCity_EventScript_PlaceDarius
	end

@ ===[ DARIUS, ON THE SAFARI ZONE DOOR ]======================================
@ He stands on (26,6), directly below the SAFARI ZONE door (26,5), only while the
@ siege is on - states 1-3, the same window as IsFederationTakeover in
@ src/overworld.c - and only while he is unbeaten.
@
@ ⚠️ HIS HIDE FLAG IS FLAG_TEMP_2, RECOMPUTED HERE ON EVERY LOAD. Temp flags are
@ wiped on every map load before ON_TRANSITION runs, so his own trainer flag is
@ the single source of truth and nothing can disagree with it: not an old save,
@ not the Route 15 test NPC, which only sets TRAINER_DARIUS_HNS. He used to share
@ FLAG_HIDE_FUCHSIA_FEDERATION with the whole occupation, which put him back on
@ the door every time the player left the SAFARI building to heal - and
@ trainerbattle_no_intro does not check the trainer flag, so he could be fought
@ again. FUCHSIA uses FLAG_TEMP_1 for its cut tree; FLAG_TEMP_2 is free here.
FuchsiaCity_EventScript_PlaceDarius::
	setflag FLAG_TEMP_2
	goto_if_lt VAR_FUCHSIA_FEDERATION_STATE, 1, FuchsiaCity_EventScript_PlaceDariusRet
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, FuchsiaCity_EventScript_PlaceDariusRet
	goto_if_defeated TRAINER_DARIUS_HNS, FuchsiaCity_EventScript_PlaceDariusRet
	clearflag FLAG_TEMP_2
FuchsiaCity_EventScript_PlaceDariusRet::
	return

@ ===[ KANTO POKeMON FEDERATION ]=============================================
@ Same arrangement as GOLDENROD: two populations share the same tiles and also flags
@
@ ⚠️ THE ARC'S TRIGGER LIVES HERE, not in data/scripts/fuchsia_federation.inc.
@ It used to be Common_EventScript_TryArmFederation, called from the three KANTO
@ gyms and the POWER PLANT back room - four ONE-SHOT sites, each inside a
@ first-win branch. So the conditions were tested once apiece and never again,
@ and a player who tripped the last one with a condition unmet lost the arc
@ permanently. See the long note in fuchsia_federation.inc for the full account.
@
@ ON_TRANSITION re-evaluates on EVERY entry to FUCHSIA, so nothing can be missed
@ and no ordering of the four prerequisites can strand the player.
FuchsiaCity_EventScript_TryBeginLockdown::
	goto_if_unset FLAG_DEFEATED_VERMILION_GYM, FuchsiaCity_EventScript_LockdownDefer
	goto_if_unset FLAG_DEFEATED_CELADON_GYM, FuchsiaCity_EventScript_LockdownDefer
	goto_if_unset FLAG_DEFEATED_SAFFRON_GYM, FuchsiaCity_EventScript_LockdownDefer
	@ The POWER PLANT thread must land BEFORE the trip to the ISLES. State 7 is
	@ its last beat - the MACHINE PART returned, TM THUNDER given. It also makes
	@ the theft read as the first, small sign of the backer behind all this.
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 7, FuchsiaCity_EventScript_LockdownDefer
	@ There is deliberately NO check on the SAFARI ZONE welcome here. It used to
	@ gate the whole arc on optional side content, and it was the condition that
	@ made the one-shot bug reachable. A player who skipped the welcome is
	@ inducted after JANINE instead - see FuchsiaCity_EventScript_StevenSafariAside.
	goto FuchsiaCity_EventScript_BeginLockdown

FuchsiaCity_EventScript_BeginLockdown::
	@ Never while the player is inside the SAFARI ZONE. Exiting the safari
	@ warps to the ENTRANCE map rather than the city, so this should be
	@ unreachable - but a rearranged city and a live safari session at the same
	@ time would be very hard to unpick, so it is asserted rather than assumed.
	goto_if_eq VAR_SAFARI_ZONE_STATE, 2, FuchsiaCity_EventScript_LockdownDefer
	setvar VAR_FUCHSIA_FEDERATION_STATE, 1
	setflag FLAG_HIDE_FUCHSIA_NPCS
	clearflag FLAG_HIDE_FUCHSIA_FEDERATION
	setflag FLAG_HIDE_FUCHSIA_JANINE
	setflag FLAG_HIDE_FUCHSIA_STANDOFF
	clearflag FLAG_HIDE_SAFARI_FEDERATION
	setflag FLAG_HIDE_SAFARI_STAFF
	@ JANINE fights from the lockdown rather than waiting for DARIUS to fall. The
	@ zoo empties to pay for her four objects, and it shares FLAG_HIDE_FUCHSIA_NPCS
	@ to do it - see that flag for the budget arithmetic.
	clearflag FLAG_HIDE_FUCHSIA_JANINE_FIGHT
	@ Disarm STEVEN's SAFARI welcome for good. A player who never took it must not
	@ get "Welcome to the DEVON SAFARI ZONE!" over a hostage scene, and FirstTime
	@ must not drag him off the siege tableau to (4,10). A player who never had it
	@ is inducted after JANINE instead - FuchsiaCity_EventScript_StevenSafariAside.
	@ The SAFARI building's ON_TRANSITION enforces the same thing on its own, so
	@ this line is belt and braces rather than the only guard.
	setvar VAR_SAFARI_WELCOME, 1
	setvar VAR_FUCHSIA_SCENE, 1
	@ ⚠️ The music has to be switched by hand on a walk-in. Crossing a route
	@ border picks the new map's music BEFORE its ON_TRANSITION runs
	@ (LoadMapFromCameraTransition, src/overworld.c: TransitionMapMusic comes
	@ before RunOnTransitionMapScript), so without this the first step into an
	@ occupied FUCHSIA from ROUTE 15, 18 or 19 plays the peacetime theme. On a
	@ warp in, the field callback settles on the same takeover song afterwards.
	fadedefaultbgm
	return

FuchsiaCity_EventScript_LockdownDefer::
	return

@ ===[ THE BACKER, on the road outside the GYM ]===============================
@ Armed by JANINE's defeat (VAR_FUCHSIA_SCENE 3) and disarmed here (4), so it
@ fires on the player's first step out of the GYM and exactly once.
@
@ ⚠️ THIS IS WHERE GIDEON'S NAME IS FIRST SPOKEN. Nothing in KANTO says it before
@ this scene - not PAXTON, who never asked, not the bikers, who only ever saw
@ somebody paying them. Keep it that way: the breadcrumbs point at a scientist,
@ never at a name.
@
@ The name is STEVEN's find - he followed the money, as his aftermath speech in
@ the SAFARI building promised. It used to be credited to JANINE here, at the
@ DAODAO landing and in his closing line; Moritz found her turning up in nearly
@ every character's mouth odd (2026-09-30), so those credits are gone. The scene
@ still waits for her badge, because the charter asks for all four KANTO badges.
FuchsiaCity_EventScript_StevenBackers::
	lock
	clearflag FLAG_HIDE_FUCHSIA_STEVEN
	@ He is added OFF camera at (18,33) and walks on. The player is on the GYM
	@ doorstep (9,33) and the screen shows x 2-16, so adding or removing him at the
	@ old (14,33) made him pop in and out in plain view.
	addobject LOCALID_FUCHSIA_STEVEN
	applymovement LOCALID_FUCHSIA_STEVEN, FuchsiaCity_Movement_StevenApproach
	waitmovement LOCALID_FUCHSIA_STEVEN
	playse SE_PIN
	applymovement LOCALID_FUCHSIA_STEVEN, Common_Movement_ExclamationMark
	waitmovement LOCALID_FUCHSIA_STEVEN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_FUCHSIA_STEVEN, FuchsiaCity_Movement_StevenApproach
	waitmovement LOCALID_FUCHSIA_STEVEN
	@ FacePlayer rather than a turnobject: the player leaves the GYM onto (9,33)
	@ but need not still be standing there, and a movement action resolves the
	@ direction at run time.
	applymovement LOCALID_FUCHSIA_STEVEN, Common_Movement_FacePlayer
	waitmovement LOCALID_FUCHSIA_STEVEN
	msgbox FuchsiaCity_Text_StevenBackers, MSGBOX_DEFAULT
	@ ===[ THE CHARTER HAPPENS HERE, NOT BACK AT THE SAFARI ZONE ]==============
	@ This scene used to end by sending the player to the SAFARI ZONE for a second
	@ conversation that asked for the battle and opened the ROUTE 13 boat. That put
	@ a round trip across town between the reveal and the boat for no reason. The
	@ ask, the fight and the boat all land here; the SAFARI ZONE copy survives only
	@ as the fallback below.
	@
	@ The four gym flags are not re-checked. This scene is armed by JANINE's defeat,
	@ so the fourth badge is the reason it is playing, and the other three are
	@ prerequisites of the lockdown that got us here.
	msgbox FuchsiaCity_Text_StevenCharter, MSGBOX_YESNO
	@ ⚠️ DISARMED BEFORE THE FIGHT, not after it. Losing whites the player out and
	@ ends this script on the spot, so anything left for afterwards never runs:
	@ SCENE would stay 3 and replay the whole scene from wherever the player next
	@ walks in, and FLAG_HIDE_FUCHSIA_STEVEN would leave him standing on the road.
	@ Setting the flag does not remove him now - an active object outlives its
	@ flag, including across the battle - it only stops him spawning again. After
	@ a loss the charter falls to STEVEN at the SAFARI ZONE, like a decline does.
	setvar VAR_FUCHSIA_SCENE, 4
	setflag FLAG_HIDE_FUCHSIA_STEVEN
	goto_if_eq VAR_RESULT, NO, FuchsiaCity_EventScript_StevenCharterDecline
	msgbox FuchsiaCity_Text_StevenCharterAccept, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN_KANTO_HNS, FuchsiaCity_Text_StevenCharterBeaten
	msgbox FuchsiaCity_Text_StevenCharterAfter, MSGBOX_DEFAULT
	setvar VAR_FUCHSIA_FEDERATION_STATE, 5
	goto FuchsiaCity_EventScript_StevenBackersLeave

@ A decline leaves the scene disarmed too - SCENE went to 4 before the branch, and
@ TryRunOnFrameMapScript would otherwise re-fire this cutscene on every input
@ poll. The player picks the charter up from STEVEN at the SAFARI ZONE instead,
@ which is exactly what the branch there is still for.
FuchsiaCity_EventScript_StevenCharterDecline::
	msgbox FuchsiaCity_Text_StevenCharterDecline, MSGBOX_DEFAULT
	goto FuchsiaCity_EventScript_StevenBackersLeave

FuchsiaCity_EventScript_StevenBackersLeave::
	@ The SAFARI induction for a player who skipped the welcome - Moritz's call,
	@ 2026-09-26: after JANINE, and only if it has not happened before. LEVEL 0 is
	@ what "never had it" means. A player who had it gets the short scene.
	call_if_eq VAR_KANTO_SAFARI_ZONE_PROGRESS, 0, FuchsiaCity_EventScript_StevenSafariAside
	closemessage
	applymovement LOCALID_FUCHSIA_STEVEN, FuchsiaCity_Movement_StevenLeave
	waitmovement LOCALID_FUCHSIA_STEVEN
	removeobject LOCALID_FUCHSIA_STEVEN
	release
	end

@ The street opener, then the body and the case, which are shared with his talk
@ script in the SAFARI building (a player who loses this fight, or walks in
@ between PAXTON and JANINE, is inducted there instead).
FuchsiaCity_EventScript_StevenSafariAside::
	msgbox FuchsiaCity_Text_StevenSafariAside, MSGBOX_DEFAULT
	call FuchsiaCity_SafariZoneEntrance_EventScript_StevenInduction
	return

@ (18,33) to (10,33) and back, in two legs of four: he walks on camera, gives
@ his "!" at (14,33), then comes the rest of the way. The visible columns with the
@ player on (9,33) are 2-16, so (18,33) is two tiles off the edge. The road is
@ clear along y=33 from x=5 to x=22, and the GYM doorman objects that stand on
@ (9,33) during the occupation are both hidden by the time this runs.
FuchsiaCity_Movement_StevenApproach:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

FuchsiaCity_Movement_StevenLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FuchsiaCity_Text_StevenSafariAside:
	.string "One more thing.\p"
	.string "You never did get a proper welcome\n"
	.string "at the SAFARI ZONE. The one time you\l"
	.string "were inside, it was not at its best.$"

FuchsiaCity_Text_StevenBackers:
	.string "{PLAYER}. I heard about the\n"
	.string "SOULBADGE.\p"
	.string "I have been following the money since\n"
	.string "FUCHSIA. It took a while, but there\l"
	.string "is a name at the end of it.\p"
	.string "GIDEON.\p"
	.string "A scientist. TEAM ROCKET's, once,\n"
	.string "out of GIOVANNI's own lab.\p"
	.string "He paid PAXTON to take my SAFARI\n"
	.string "ZONE so that he could have what was\l"
	.string "living inside it. Specimens.\p"
	.string "And he knew you were coming.\n"
	.string "Before I did.\p"
	.string "Which brings me to what I have to\n"
	.string "ask of you.$"

@ The charter, moved out of the SAFARI ZONE ENTRANCE so nothing sits between this
@ scene and the ROUTE 13 boat. Same beats as the version there, rewritten for a
@ street corner: he cannot gesture at his own building, and he has just named the
@ man, so the reason he cannot follow it up himself is the point.
FuchsiaCity_Text_StevenCharter:
	.string "SURGE, ERIKA, SABRINA, JANINE.\p"
	.string "All four, and the FEDERATION on top\n"
	.string "of it.\p"
	.string "GIDEON is not in KANTO any more, and\n"
	.string "wherever he has gone I cannot reach\l"
	.string "it from here.\p"
	.string "I have chartered a boat out of the\n"
	.string "ROUTE 13 dock. I want you on it.\p"
	.string "But not before I have seen for myself\n"
	.string "that you are ready.\p"
	.string "Show me. Here and now?$"

FuchsiaCity_Text_StevenCharterAccept:
	.string "Good.\p"
	.string "I won't go easy on you. It would be\n"
	.string "no kindness if I did.$"

FuchsiaCity_Text_StevenCharterBeaten:
	.string "…Yes.\n"
	.string "You're ready.$"

FuchsiaCity_Text_StevenCharterAfter:
	.string "That was a fine battle.\p"
	.string "The ship is at the dock on ROUTE 13.\n"
	.string "The captain has his orders.\p"
	.string "Find GIDEON, {PLAYER}.\p"
	.string "And be careful out there.$"

FuchsiaCity_Text_StevenCharterDecline:
	.string "Then come back when you are.\p"
	.string "I'll be at the SAFARI ZONE. Ask me\n"
	.string "again whenever you're ready to go.$"

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "BAOBA$"

FuchsiaCity_Text_Baoba:
	.string "WARDEN BAOBA: {PLAYER}!\p"
	.string "This is WARDEN BAOBA.\p"
	.string "Something awful has happened!\n"
	.string "My old SAFARI ZONE in FUCHSIA CITY\l"
	.string "was bought out and reopened!\p"
	.string "And apparently it has exotic new\n"
	.string "POKéMON!\p"
	.string "It's hurting my business!\p"
	.string "{PLAYER}, you must venture into the\n"
	.string "new SAFARI ZONE and catch a POKéMON\l"
	.string "to show me. I must know about these\l"
	.string "'exotic' POKéMON.\p"
	.string "Please {PLAYER}, my business depends\n"
	.string "on you!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

@ FUCHSIA's own townsfolk need no "during" branch - FLAG_HIDE_FUCHSIA_NPCS hides
@ all of them for the whole occupation, so states 1-3 are unreachable here. The
@ rumour is the default and runs until the arc is solved.
FuchsiaCity_EventScript_Youngster::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, FuchsiaCity_EventScript_YoungsterAfter
	msgbox FuchsiaCity_Text_Youngster_Rumour, MSGBOX_NPC
	end

FuchsiaCity_EventScript_YoungsterAfter::
	msgbox FuchsiaCity_Text_Youngster_After, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	lock
	faceplayer
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, FuchsiaCity_EventScript_PokefanMAfter
	msgbox FuchsiaCity_Text_PokefanM_Rumour, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_EventScript_PokefanMAfter::
	msgbox FuchsiaCity_Text_PokefanM_After, MSGBOX_DEFAULT
	goto_if_set FLAG_BADGE14_GET, FuchsiaCity_EventScript_PokefanMExtra
	closemessage
	release
	end

FuchsiaCity_EventScript_Teacher::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, FuchsiaCity_EventScript_TeacherAfter
	msgbox FuchsiaCity_Text_Teacher_Rumour, MSGBOX_NPC
	end

FuchsiaCity_EventScript_TeacherAfter::
	msgbox FuchsiaCity_Text_Teacher_After, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster_Rumour:
	.string "One of the ELITE FOUR used to be\n"
	.string "the LEADER of FUCHSIA's GYM.\p"
	.string "Those bikers wouldn't have dared\n"
	.string "show their faces back then!$"

FuchsiaCity_Text_Youngster_After:
	.string "Everyone says you beat the whole\n"
	.string "FEDERATION on your own!\p"
	.string "I'm telling my dad that KOGA\n"
	.string "couldn't have done it better.$"

FuchsiaCity_Text_PokefanM_Rumour:
	.string "KOGA's daughter succeeded him as\n"
	.string "the GYM LEADER after he joined the\l"
	.string "ELITE FOUR.\p"
	.string "She's been out every night this\n"
	.string "week. Something has her worried.$"

FuchsiaCity_Text_PokefanM_After:
	.string "JANINE hunted those bikers for\n"
	.string "weeks and never cornered them.\p"
	.string "You turn up and it's over in a day.\p"
	.string "Don't tell her I said that.$"

FuchsiaCity_Text_Teacher_Rumour:
	.string "The SAFARI ZONE is under new\n"
	.string "management.\p"
	.string "Only now there are bikers loitering\n"
	.string "at the gate, day and night.\p"
	.string "The DEVON staff look terrified.$"

FuchsiaCity_Text_Teacher_After:
	.string "You cleared them out of the SAFARI\n"
	.string "ZONE by yourself!\p"
	.string "The attendants are still shaking.\p"
	.string "Thank you. Truly.$"

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Sign:
	.string "FUCHSIA CITY\p"
	.string "Behold! It's Passion Pink!$"

FuchsiaCity_Text_GymSign:
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: JANINE\p"
	.string "The Poisonous Ninja Master$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "There's a notice here…\p"
	.string "SAFARI ZONE OFFICE is closed until\n"
	.string "further notice.$"

FuchsiaCity_Text_SafariZone:
	.string "SAFARI ZONE\n"
	.string "NOW OWNED BY\l"
	.string "DEVON CORP.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "The WARDEN is traveling abroad.\p"
	.string "Therefore, the SAFARI ZONE is\n"
	.string "closed.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "No littering.\p"
	.string "Please take your waste with you.$"


FuchsiaCity_EventScript_PokefanMExtra::
	msgbox FuchsiaCity_Text_PokefanMExtra, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Text_PokefanMExtra:
	.string "JANINE lost to you?\p"
	.string "KOGA'll hear about it at the LEAGUE.\p"
	.string "Fathers always hear.$"

FuchsiaCity_EventScript_FederationGrunt1::
	trainerbattle_single TRAINER_MACK_HNS, FuchsiaCity_Text_MackSeen, FuchsiaCity_Text_MackBeaten
	msgbox FuchsiaCity_Text_MackAfter, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_FederationGrunt2::
	trainerbattle_single TRAINER_VERN_HNS, FuchsiaCity_Text_VernSeen, FuchsiaCity_Text_VernBeaten
	msgbox FuchsiaCity_Text_VernAfter, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_FederationGrunt3::
	trainerbattle_single TRAINER_HOYT_HNS, FuchsiaCity_Text_HoytSeen, FuchsiaCity_Text_HoytBeaten
	msgbox FuchsiaCity_Text_HoytAfter, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_EventScript_FederationGuard::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_MACK_HNS, FuchsiaCity_EventScript_FederationGuardWait
	goto_if_not_defeated TRAINER_VERN_HNS, FuchsiaCity_EventScript_FederationGuardWait
	goto_if_not_defeated TRAINER_HOYT_HNS, FuchsiaCity_EventScript_FederationGuardWait
	msgbox FuchsiaCity_Text_DariusSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DARIUS_HNS, FuchsiaCity_Text_DariusBeaten
	msgbox FuchsiaCity_Text_DariusAfter, MSGBOX_DEFAULT
	closemessage
	@ ⚠️ ONLY DARIUS LEAVES. The city stays held until PAXTON falls, which is what
	@ the rest of the arc says out loud - an older version faded out all nine city
	@ FEDERATION objects here, and the occupation evaporated around the player.
	@
	@ He fades out rather than stepping aside. He stood on (26,6), directly below
	@ the SAFARI ZONE door at (26,5), so his tile is the lock; walking him to (27,6)
	@ dragged his 32x32 sheet along the building edge, and it looked broken.
	@ removeobject also sets his hide flag, FLAG_TEMP_2, and
	@ FuchsiaCity_EventScript_PlaceDarius keeps him gone on every later load
	@ because his trainer flag is now set. The two loafers test goto_if_defeated.
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_FUCHSIA_FED_GUARD
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

FuchsiaCity_EventScript_FederationGuardWait::
	msgbox FuchsiaCity_Text_DariusWait, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Text_MackSeen:
	.string "This is FEDERATION road now, kid.\n"
	.string "Turn around.$"

FuchsiaCity_Text_MackBeaten:
	.string "Tch! Lucky shot!$"

FuchsiaCity_Text_MackAfter:
	.string "You think we rode all the way out\n"
	.string "here for fun? We were paid to.\p"
	.string "…Forget I said that.$"

FuchsiaCity_Text_VernSeen:
	.string "The cops shut our UNDERGROUND\n"
	.string "PATH. So we took something back.$"

FuchsiaCity_Text_VernBeaten:
	.string "Ngh… you hit hard…$"

FuchsiaCity_Text_VernAfter:
	.string "FUCHSIA owes us. All of KANTO\n"
	.string "owes us.\p"
	.string "PAXTON says we'll collect.$"

FuchsiaCity_Text_HoytSeen:
	.string "You're that JOHTO punk PAXTON\n"
	.string "warned us about.$"

FuchsiaCity_Text_HoytBeaten:
	.string "H-how…$"

FuchsiaCity_Text_HoytAfter:
	.string "PAXTON doesn't take orders from\n"
	.string "anybody…\p"
	.string "…Well. Almost anybody.$"

FuchsiaCity_Text_DariusWait:
	.string "Nobody gets past me.\p"
	.string "Not the police, not DEVON, and\n"
	.string "definitely not you.$"

FuchsiaCity_Text_DariusSeen:
	.string "You put all three of them down?\p"
	.string "PAXTON said you'd be trouble.\p"
	.string "Let's see it, then!$"

FuchsiaCity_Text_DariusBeaten:
	.string "…Should've stayed on my bike.$"

FuchsiaCity_Text_DariusAfter:
	.string "Go on up, then.\p"
	.string "PAXTON is inside with the DEVON\n"
	.string "people. He won't be as gentle.$"

@ These two comment on DARIUS falling. "DARIUS is down" is not a state, and his
@ hide flag is a temp flag derived from it, so the test is his own trainer flag.
FuchsiaCity_EventScript_FederationLoafer1::
	goto_if_defeated TRAINER_DARIUS_HNS, FuchsiaCity_EventScript_FederationLoafer1Held
	msgbox FuchsiaCity_Text_Loafer1, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FederationLoafer1Held::
	msgbox FuchsiaCity_Text_Loafer1Held, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FederationLoafer2::
	msgbox FuchsiaCity_Text_Loafer2, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FederationLoafer3::
	msgbox FuchsiaCity_Text_Loafer3, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FederationLoafer4::
	goto_if_defeated TRAINER_DARIUS_HNS, FuchsiaCity_EventScript_FederationLoafer4Held
	msgbox FuchsiaCity_Text_Loafer4, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FederationLoafer4Held::
	msgbox FuchsiaCity_Text_Loafer4Held, MSGBOX_NPC
	end

FuchsiaCity_Text_Loafer1:
	.string "Every road in and out is ours.\p"
	.string "Took about an hour. Nobody came.\p"
	.string "Nobody's coming.$"

@ ⚠️ "the suit guy" used to stand here, and in three other lines. GIDEON is a
@ SCIENTIST out of a ROCKET lab, so a man in a suit was pointing at the wrong
@ person entirely - it set up a reveal that never arrives. The bikers call him
@ the boss, which is also what ROCKET's grunts call GIOVANNI all over this tree,
@ and is the same ambiguity PAXTON's party plants by carrying Music: Rocket.
@ It does not collide with PAXTON: Route8_Text_BikerDwayneFallen already
@ separates the two in one breath.
FuchsiaCity_Text_Loafer2:
	.string "Don't look at me, kid. I just watch\n"
	.string "the street.\p"
	.string "PAXTON's up at the SAFARI ZONE\n"
	.string "spending the boss's money.$"

FuchsiaCity_Text_Loafer3:
	.string "The locals all locked their doors\n"
	.string "the first night.\p"
	.string "Haven't seen one since. Suits me.$"

@ He is also the line that explains the empty pens, so the zoo going dark during
@ the occupation reads as the FEDERATION crating specimens for GIDEON rather than
@ as objects quietly failing to spawn. The pens share FLAG_HIDE_FUCHSIA_NPCS with
@ the townsfolk - see that flag for the budget arithmetic.
FuchsiaCity_Text_Loafer4:
	.string "…I thought we were coming here to\n"
	.string "make a point.\p"
	.string "Nobody said anything about keeping\n"
	.string "people in a back room.\p"
	.string "Or about loading up everything that\n"
	.string "was in those pens. They went out on\l"
	.string "a truck the first night.\p"
	.string "I want to go home.$"

FuchsiaCity_Text_Loafer1Held:
	.string "Street's yours. Fine. Take it.\p"
	.string "I'm not going up to that gate after\n"
	.string "what you did to DARIUS.\p"
	.string "PAXTON can shout all he likes.$"

FuchsiaCity_Text_Loafer4Held:
	.string "The others rode out an hour ago.\p"
	.string "He's still up there with those\n"
	.string "DEVON people. Won't come down.\p"
	.string "…Somebody has to make him stop.$"

FuchsiaCity_EventScript_FederationDoorman1::
	msgbox FuchsiaCity_Text_Doorman1, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FederationDoorman2::
	msgbox FuchsiaCity_Text_Doorman2, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FederationDoorman3::
	msgbox FuchsiaCity_Text_Doorman3, MSGBOX_NPC
	end

FuchsiaCity_Text_Doorman1:
	.string "Nobody in, nobody out.\p"
	.string "The folks inside have been very\n"
	.string "sensible about it so far.\p"
	.string "You be sensible too.$"

FuchsiaCity_Text_Doorman2:
	.string "There's a family in this one.\p"
	.string "So no, you're not going in, and\n"
	.string "no, you're not fetching anybody.\p"
	.string "Walk on.$"

FuchsiaCity_EventScript_FederationDoorman4::
	msgbox FuchsiaCity_Text_Doorman4, MSGBOX_NPC
	end

FuchsiaCity_Text_Doorman4:
	.string "Shop's shut.\p"
	.string "Everything on those shelves is ours\n"
	.string "now, far as I'm concerned.\p"
	.string "Try the CENTER if you're bleeding.$"

FuchsiaCity_Text_Doorman3:
	.string "GYM's closed, kid.\p"
	.string "The LEADER went out hunting us\n"
	.string "three nights back.\p"
	.string "Still out there somewhere, far as\n"
	.string "I know. Wasn't much of a hunt.$"

@ ===[ THE STANDOFF - THREE NPCs WHO MUST HOLD THEIR COMPOSITION ]=============
@ JANINE at (26,13) is facing DOWN at the cueball on (26,14); the biker on (25,14)
@ is beside him. MSGBOX_NPC gives every one of them a faceplayer and none of them
@ a way back, so talking to all three used to leave the argument with its two
@ participants looking away from each other.
@
@ ⚠️ MovementType_FaceDirection_Step0 re-seeds from the LIVE facingDirection, not
@ from the map.json template, which is why a facing has to be restored explicitly
@ rather than left to the movement type to reset.
@
@ JANINE turns, but only when her own line earns it. "…Sorry. Not you." is the
@ beat where she registers the player mid-sentence, so the text splits there: she
@ delivers the first half still berating the cueball, turns, finishes, and turns
@ back south onto him.
FuchsiaCity_EventScript_StandoffJanine::
	lock
	msgbox FuchsiaCity_Text_StandoffJanine1, MSGBOX_DEFAULT
	closemessage
	@ FacePlayer as a movement, not turnobject: the player can stand north, east
	@ or west of her, so the direction has to be resolved at run time.
	applymovement LOCALID_FUCHSIA_STANDOFF_JANINE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Text_StandoffJanine2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_FUCHSIA_STANDOFF_JANINE, DIR_SOUTH
	release
	end

@ The biker SHOULD turn to the player and stay turned - he is a bystander
@ enjoying the show, not a participant. MSGBOX_NPC already faces him and nothing
@ turns him back, which is exactly right. Deliberately unchanged.
FuchsiaCity_EventScript_StandoffBiker1::
	msgbox FuchsiaCity_Text_StandoffBiker1, MSGBOX_NPC
	end

@ The cueball is the one being berated. He never looks away from JANINE, so no
@ faceplayer at all - hence the explicit lock/release instead of MSGBOX_NPC.
FuchsiaCity_EventScript_StandoffBiker2::
	lock
	msgbox FuchsiaCity_Text_StandoffBiker2, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_EventScript_StandoffGymDoor::
	msgbox FuchsiaCity_Text_StandoffGymDoor, MSGBOX_NPC
	end

@ Split at the beat where she notices the player. Part 1 is still aimed at the
@ cueball; part 2 is to the player.
FuchsiaCity_Text_StandoffJanine1:
	.string "JANINE: You have no business on\n"
	.string "this road.\p"
	.string "Neither does anyone you answer to.$"

FuchsiaCity_Text_StandoffJanine2:
	.string "…Sorry. Not you.\p"
	.string "The GYM is shut until I've seen\n"
	.string "these two off my city.$"

FuchsiaCity_Text_StandoffBiker1:
	.string "She's been out here since dawn.\p"
	.string "One of her, telling the lot of us\n"
	.string "where we can and can't ride.\p"
	.string "Admire the nerve, honestly.$"

FuchsiaCity_Text_StandoffBiker2:
	.string "We're just waiting, kid.\p"
	.string "Word came down that the SAFARI\n"
	.string "ZONE changed hands.\p"
	.string "Word came from whoever it is PAXTON\n"
	.string "calls the boss. That's all I know.$"

FuchsiaCity_Text_StandoffGymDoor:
	.string "GYM's shut.\p"
	.string "LEADER's business, not mine.\p"
	.string "She's up the road if you want to\n"
	.string "argue about it.$"

@ ⚠️ MSGBOX_DEFAULT + closemessage, NOT MSGBOX_AUTOCLOSE. Std_MsgboxAutoclose
@ (data/scripts/trainer_battle.inc) ends in `release`, so after the first line
@ the player was free to walk off while the "?" beat and the second line played
@ out. AUTOCLOSE is only right as the LAST thing a script does.
FuchsiaCity_EventScript_JanineFighting::
	lock
	msgbox FuchsiaCity_Text_JanineFight_Command, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_FUCHSIA_JANINE_FIGHT, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_FUCHSIA_JANINE_FIGHT
	faceplayer
	msgbox FuchsiaCity_Text_JanineFight_Notice, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_FUCHSIA_JANINE_FIGHT, DIR_EAST
	release
	end

FuchsiaCity_EventScript_JanineFightBiker::
	msgbox FuchsiaCity_Text_JanineFight_Biker, MSGBOX_NPC
	end

FuchsiaCity_EventScript_JanineFightAriados::
	lock
	msgbox FuchsiaCity_Text_JanineFight_Ariados, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_EventScript_JanineFightGolbat::
	lock
	waitse
	playmoncry SPECIES_GOLBAT, CRY_MODE_NORMAL
	msgbox FuchsiaCity_Text_JanineFight_Golbat, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

FuchsiaCity_Text_JanineFight_Ariados:
	.string "ARIADOS has not taken its eyes off\n"
	.string "the GOLBAT.\p"
	.string "It doesn't so much as twitch when\n"
	.string "you come close.$"

FuchsiaCity_Text_JanineFight_Golbat:
	.string "GOLBAT is flying in ragged loops.\p"
	.string "It has been badly poisoned, and it\n"
	.string "is losing height a little at a time.$"

FuchsiaCity_Text_JanineFight_Command:
	.string "JANINE: ARIADOS, SLUDGE BOMB!\p"
	.string "Don't let it get airborne!$"

FuchsiaCity_Text_JanineFight_Notice:
	.string "JANINE: …You. Don't stop here.\p"
	.string "Whoever gives them their orders is\n"
	.string "up at the SAFARI ZONE, and I can't\l"
	.string "get past this one to reach it yet.\p"
	.string "I'll hold him. You go.$"

FuchsiaCity_Text_JanineFight_Biker:
	.string "Two days she's been at this.\p"
	.string "Hasn't sat down once.\p"
	.string "Starting to think she won't.$"
