AzaleaTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN_HNS
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "Do your POKéMON know HM moves?\p"
	.string "Those moves can be used even if\n"
	.string "your POKéMON has fainted.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "This BILL guy created the system\n"
	.string "for storing POKéMON in a PC.\p"
	.string "BILL's PC can store up to 30\n"
	.string "POKéMON per BOX.$"

AzaleaPokecenter_Text_FishingGuru:
	.string "BILL's PC can store up to 30\n"
	.string "POKéMON per BOX.$"

AzaleaPokecenter_Text_PokefanF:
	.string "Do you know about BERRIES?\p"
	.string "Crack one open, hollow it out and\n"
	.string "fit it with a special device.\p"
	.string "Then you can catch POKéMON with it.\p"
	.string "Before POKé BALLS were invented,\n"
	.string "everyone used BERRIES.$"

AzaleaPokeCenter_EventScript_FuryCutterTutor::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE02_GET, AzaleaPokeCenter_EventScript_FuryCutterTutorNotYet
	move_tutor MOVE_FURY_CUTTER, AzaleaPokeCenter_Text_FuryCutterTeach, MoveTutor_Text_FuryCutterWhichMon, MoveTutor_EventScript_FuryCutterDeclined, MoveTutor_EventScript_FuryCutterTaught, 3500
	end

AzaleaPokeCenter_EventScript_FuryCutterTutorNotYet::
	msgbox AzaleaPokeCenter_Text_FuryCutterTutorNotYet, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_Text_FuryCutterTeach:
	.string "I came out of ILEX FOREST to rest\n"
	.string "my legs a while.\p"
	.string "The bug POKéMON in there never\n"
	.string "stop moving, you know.\p"
	.string "There's a move like that. Weak at\n"
	.string "first-then stronger every time\l"
	.string "it lands.\p"
	.string "It's called FURY CUTTER.\p"
	.string "I'll teach it to a POKéMON of\n"
	.string "yours for just ¥3500.$"

AzaleaPokeCenter_Text_FuryCutterTutorNotYet:
	.string "FURY CUTTER! Every swing that\n"
	.string "lands hits harder than the last.\p"
	.string "I only teach it to trainers who\n"
	.string "have beaten BUGSY, though.\p"
	.string "His GYM is right here in town.\n"
	.string "Come find me after!$"
