LavenderTown_RadioStation_hns_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, LavenderTown_RadioStation_EventScript_FixMissingRadioCard
LavenderTown_RadioStation_EventScript_GiveExpnCard::
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end

@ Fallback plan in case the player never cleared the GOLDENROD quiz
LavenderTown_RadioStation_EventScript_FixMissingRadioCard::
	msgbox LavenderTown_RadioStation_Text_NoRadioCard, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavenderTown_RadioStation_Text_GotRadioCard, MSGBOX_AUTOCLOSE
	waitfanfare
	setflag FLAG_ENABLE_RADIO
	msgbox LavenderTown_RadioStation_Text_NowTheUpgrade, MSGBOX_DEFAULT
	goto LavenderTown_RadioStation_EventScript_GiveExpnCard
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "Welcome! Feel free to look around\n"
	.string "anywhere on this floor.$"

LavenderTown_RadioStation_Text_Officer:
	.string "Sorry, but you can only tour the\n"
	.string "ground floor.\p"
	.string "Ever since JOHTO's RADIO TOWER\n"
	.string "was taken over by a criminal gang,\l"
	.string "we have had to step up our\l"
	.string "security.$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "Many people are hard at work here\n"
	.string "in the RADIO TOWER.\p"
	.string "They must be doing their best to\n"
	.string "put on good shows.$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "Oh, no, no, no!\p"
	.string "We've been off the air ever since\n"
	.string "the POWER PLANT shut down.\p"
	.string "All my efforts to start this\n"
	.string "station would be wasted if I can't\l"
	.string "broadcast.\p"
	.string "I'll be ruined!$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "Ah! So you're the {PLAYER} who\n"
	.string "solved the POWER PLANT's problem?\p"
	.string "Thanks to you, I never lost my\n"
	.string "job.\p"
	.string "I tell you, you're a real\n"
	.string "lifesaver!\p"
	.string "Please take this as my thanks.$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER} obtained the\n"
	.string "RADIO UPGRADE!$"

LavenderTown_RadioStation_Text_NoRadioCard:
	.string "Hm? Hold on. Let me see that\n"
	.string "POKéGEAR of yours.\p"
	.string "Gahahaha! There's no RADIO CARD\n"
	.string "in here at all!\p"
	.string "What have they been doing over in\n"
	.string "GOLDENROD? Never mind, never mind.\p"
	.string "I ran that tower for thirty years.\n"
	.string "I can still sign one of these.$"

LavenderTown_RadioStation_Text_GotRadioCard:
	.string "{PLAYER}'s POKéGEAR can now double as\n"
	.string "a RADIO!$"

LavenderTown_RadioStation_Text_NowTheUpgrade:
	.string "Now then. Where were we?\p"
	.string "Ah, yes. Your reward.$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "With that thing, you can tune into\n"
	.string "the radio programs here in KANTO.\p"
	.string "Gahahahaha!$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "Hey there!\p"
	.string "I am the super MUSIC DIRECTOR!\p"
	.string "Huh? Your RADIO can't tune into\n" @POKéGEAR
	.string "my music programs. How unfortunate!\p"
	.string "If you get an EXPN CARD upgrade,\n"
	.string "you can tune in. You'd better get\l"
	.string "one!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "Hey there!\p"
	.string "I am the super MUSIC DIRECTOR!\p"
	.string "I'm responsible for the gorgeous\n"
	.string "melodies that go out over the air.\p"
	.string "Don't be square. Grab your music\n"
	.string "off the air!$"

LavenderTown_RadioStation_Text_Directory:
	.string "1F RECEPTION 2F SALES\p"
	.string "3F PERSONNEL 4F PRODUCTION\p"
	.string "5F DIRECTOR'S OFFICE$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Perk Up POKéMON with Mellow\n"
	.string "Sounds of the POKé FLUTE on\l"
	.string "CHANNEL 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "Wow! A full rack of POKéMON CDs\n"
	.string "and videos.\p"
	.string "This must be the reference\n"
	.string "library.$"

