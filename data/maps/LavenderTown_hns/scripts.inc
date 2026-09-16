LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, LavenderTown_EventScript_TeacherAfter
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, LavenderTown_EventScript_TeacherDuring
	goto_if_eq VAR_FUCHSIA_FEDERATION_STATE, 1, LavenderTown_EventScript_TeacherRumour
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_TeacherRumour::
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

LavenderTown_Text_Teacher:
	.string "KANTO has many good radio shows.$"

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
