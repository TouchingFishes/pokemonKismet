FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	call_if_eq VAR_FUCHSIA_FEDERATION_STATE, 1, FuchsiaCity_EventScript_BeginLockdown
	end

@ ===[ KANTO POKeMON FEDERATION ]=============================================
@ Same arrangement as GOLDENROD: two populations share the same tiles and also flags
FuchsiaCity_EventScript_BeginLockdown::
	@ Never while the player is inside the SAFARI ZONE. Exiting the safari
	@ warps to the ENTRANCE map rather than the city, so this should be
	@ unreachable - but a rearranged city and a live safari session at the same
	@ time would be very hard to unpick, so it is asserted rather than assumed.
	goto_if_eq VAR_SAFARI_ZONE_STATE, 2, FuchsiaCity_EventScript_LockdownDefer
	setvar VAR_FUCHSIA_FEDERATION_STATE, 2
	setflag FLAG_HIDE_FUCHSIA_NPCS
	clearflag FLAG_HIDE_FUCHSIA_FEDERATION
	setflag FLAG_HIDE_FUCHSIA_JANINE
	@ Inside the SAFARI ZONE ENTRANCE the same swap happens
	clearflag FLAG_HIDE_SAFARI_FEDERATION
	setflag FLAG_HIDE_SAFARI_STAFF
	@ The two holdouts come with the rest, but on their own flag so DARIUS's
	@ cleanup at state 3 does not take them - see the LOAFERS block below.
	clearflag FLAG_HIDE_FUCHSIA_HOLDOUTS
	return

FuchsiaCity_EventScript_LockdownDefer::
	return

FuchsiaCity_Trigger_Music::
	setvar VAR_TEMP_0, 1
	goto_if_lt VAR_FUCHSIA_FEDERATION_STATE, 2, FuchsiaCity_Trigger_MusicEnd
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_Trigger_MusicEnd
	fadenewbgm MUS_HG_ROCKET_TAKEOVER
FuchsiaCity_Trigger_MusicEnd::
	end

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

FuchsiaCity_EventScript_Youngster::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_EventScript_YoungsterAfter
	goto_if_eq VAR_FUCHSIA_FEDERATION_STATE, 1, FuchsiaCity_EventScript_YoungsterRumour
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_YoungsterRumour::
	msgbox FuchsiaCity_Text_Youngster_Rumour, MSGBOX_NPC
	end

FuchsiaCity_EventScript_YoungsterAfter::
	msgbox FuchsiaCity_Text_Youngster_After, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	lock
	faceplayer
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_EventScript_PokefanMAfter
	goto_if_eq VAR_FUCHSIA_FEDERATION_STATE, 1, FuchsiaCity_EventScript_PokefanMRumour
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_EventScript_PokefanMRumour::
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
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_EventScript_TeacherAfter
	goto_if_eq VAR_FUCHSIA_FEDERATION_STATE, 1, FuchsiaCity_EventScript_TeacherRumour
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_TeacherRumour::
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

FuchsiaCity_Text_Youngster:
	.string "One of the ELITE FOUR used to be\n"
	.string "the LEADER of FUCHSIA's GYM.$"

FuchsiaCity_Text_PokefanM:
	.string "KOGA's daughter succeeded him as\n"
	.string "the GYM LEADER after he joined the\l"
	.string "ELITE FOUR.$"

FuchsiaCity_Text_Teacher:
	.string "The SAFARI ZONE is under new\n"
	.string "management.\p"
	.string "And it has tons of new POKéMON!$"

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
	fadescreenswapbuffers FADE_TO_BLACK
	setvar VAR_FUCHSIA_FEDERATION_STATE, 3
	setflag FLAG_HIDE_FUCHSIA_FEDERATION
	removeobject LOCALID_FUCHSIA_FED_GRUNT1
	removeobject LOCALID_FUCHSIA_FED_GRUNT2
	removeobject LOCALID_FUCHSIA_FED_GRUNT3
	removeobject LOCALID_FUCHSIA_FED_GUARD
	removeobject LOCALID_FUCHSIA_FED_LOAFER2
	removeobject LOCALID_FUCHSIA_FED_LOAFER3
	removeobject LOCALID_FUCHSIA_FED_DOOR1
	removeobject LOCALID_FUCHSIA_FED_DOOR2
	removeobject LOCALID_FUCHSIA_FED_DOOR3
	playse SE_EXIT
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

FuchsiaCity_EventScript_FederationLoafer1::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 3, FuchsiaCity_EventScript_FederationLoafer1Held
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
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 3, FuchsiaCity_EventScript_FederationLoafer4Held
	msgbox FuchsiaCity_Text_Loafer4, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FederationLoafer4Held::
	msgbox FuchsiaCity_Text_Loafer4Held, MSGBOX_NPC
	end

FuchsiaCity_Text_Loafer1:
	.string "Every road in and out is ours.\p"
	.string "Took about an hour. Nobody came.\p"
	.string "Nobody's coming.$"

FuchsiaCity_Text_Loafer2:
	.string "Don't look at me, kid. I just watch\n"
	.string "the street.\p"
	.string "PAXTON's up at the SAFARI ZONE with\n"
	.string "the suit guy's money.$"

FuchsiaCity_Text_Loafer3:
	.string "The locals all locked their doors\n"
	.string "the first night.\p"
	.string "Haven't seen one since. Suits me.$"

FuchsiaCity_Text_Loafer4:
	.string "…I thought we were coming here to\n"
	.string "make a point.\p"
	.string "Nobody said anything about keeping\n"
	.string "people in a back room.\p"
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

FuchsiaCity_Text_Doorman3:
	.string "GYM's closed, kid.\p"
	.string "The LEADER went out hunting us\n"
	.string "three nights back.\p"
	.string "Still out there somewhere, far as\n"
	.string "I know. Wasn't much of a hunt.$"
