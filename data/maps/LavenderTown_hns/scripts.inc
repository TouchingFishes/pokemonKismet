LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_HexScholar::
	lock
	faceplayer
	goto_if_unset TRAINER_FLAGS_START + TRAINER_LUNA_HNS, LavenderTown_EventScript_HexScholarNotReady
	goto_if_set FLAG_GOT_TM_HEX_FROM_SCHOLAR, LavenderTown_EventScript_HexScholarRepeat
	checkitemspace ITEM_TM_HEX
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_EventScript_HexScholarBagFull
	msgbox LavenderTown_Text_HexScholarReady, MSGBOX_DEFAULT
	giveitem ITEM_TM_HEX
	setflag FLAG_GOT_TM_HEX_FROM_SCHOLAR
	msgbox LavenderTown_Text_HexScholarAfterGive, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_EventScript_HexScholarNotReady::
	msgbox LavenderTown_Text_HexScholarNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_EventScript_HexScholarRepeat::
	msgbox LavenderTown_Text_HexScholarRepeat, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_EventScript_HexScholarBagFull::
	msgbox LavenderTown_Text_HexScholarBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_EventScript_HexManiac::
	msgbox LavenderTown_Text_HexManiac, MSGBOX_NPC
	end

LavenderTown_Text_HexScholarNotReady:
	.string "…You feel it, don't you?\p"
	.string "Something disturbs ROUTE 8 at\n"
	.string "night.\p"
	.string "Come back after you've witnessed\n"
	.string "it.$"

LavenderTown_Text_HexScholarReady:
	.string "So.\p"
	.string "You stopped their pointless\n"
	.string "séance…\p"
	.string "That is great!\p"
	.string "Then this belongs with you.$"

LavenderTown_Text_HexScholarAfterGive:
	.string "TM HEX grows stronger when the\n"
	.string "target is already suffering.\p"
	.string "Poison.\p"
	.string "Burn.\p"
	.string "Sleep.\p"
	.string "Pain calls to pain.$"

LavenderTown_Text_HexScholarRepeat:
	.string "HEX is very useful. It helped me\n"
	.string "win many battles,\p"
	.string "when I was still young and\n"
	.string "traveled around the world.$"

LavenderTown_Text_HexScholarBagFull:
	.string "Your bag is too heavy.\p"
	.string "Make space.\p"
	.string "Some things don't like being kept\n"
	.string "waiting.$"

LavenderTown_Text_HexManiac:
	.string "They tore down POKéMON TOWER and\p"
	.string "built the RADIO TOWER to boost\n"
	.string "the signal around LAVENDER TOWN.\p"
	.string "Not everyone was happy about it.\p"
	.string "Some folks started dressing like\n"
	.string "witches…\p"
	.string "A quiet way to remember what was\n"
	.string "lost.$"

LavenderTown_EventScript_Teacher::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, LavenderTown_EventScript_TeacherAfter
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 1, LavenderTown_EventScript_TeacherDuring
	msgbox LavenderTown_Text_Teacher_Rumour, MSGBOX_NPC
	end

LavenderTown_EventScript_TeacherDuring::
	msgbox LavenderTown_Text_Teacher_During, MSGBOX_NPC
	end

LavenderTown_EventScript_TeacherAfter::
	msgbox LavenderTown_Text_Teacher_After, MSGBOX_NPC
	end

LavenderTown_Text_Teacher_Rumour:
	.string "Bikes have gone past all week,\n"
	.string "down ROUTE 12 towards FUCHSIA.\p"
	.string "Not one has come back up.$"

LavenderTown_Text_Teacher_During:
	.string "They've taken FUCHSIA, people say.\p"
	.string "The whole city. Just like that.\p"
	.string "And nobody is going to stop them.$"

LavenderTown_Text_Teacher_After:
	.string "FUCHSIA is free again, and they say\n"
	.string "it was a kid from JOHTO.\p"
	.string "…That's you, isn't it?$"

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "That's quite some building, eh?\p"
	.string "It's KANTO's RADIO TOWER.$"


LavenderTown_Text_Gramps:
	.string "People come from all over to pay\n"
	.string "their respects to the departed\l"
	.string "souls of POKéMON.$"

LavenderTown_Text_Youngster:
	.string "You need a POKé FLUTE to wake\n"
	.string "sleeping POKéMON.\p"
	.string "Every trainer has to know that!$"

LavenderTown_Text_Sign:
	.string "LAVENDER TOWN\p"
	.string "The Noble Purple Town$"

LavenderTown_Text_KantoRadioStationSign:
	.string "KANTO RADIO STATION\p"
	.string "Your Favorite Programs On-Air\n"
	.string "Around the Clock!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "LAVENDER VOLUNTEER POKéMON\n"
	.string "HOUSE$"

LavenderTown_Text_SoulHouseSign:
	.string "SOUL HOUSE\p"
	.string "May the Souls of POKéMON Rest\n"
	.string "Easy$"
