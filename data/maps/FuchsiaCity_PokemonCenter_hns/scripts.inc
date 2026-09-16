FuchsiaCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_PokemonCenter_OnTransition
	.byte 0

FuchsiaCity_PokemonCenter_OnTransition::
	setflag FLAG_TEMP_1
	setrespawn HEAL_LOCATION_FUCHSIA_CITY_HNS
	end

FuchsiaCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_PokemonCenter_EventScript_CooltrainerMAfter
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, FuchsiaCity_PokemonCenter_EventScript_CooltrainerMDuring
	msgbox FuchsiaCity_PokemonCenter1F_Text_CooltrainerM, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_EventScript_CooltrainerMDuring::
	msgbox FuchsiaCity_PokemonCenter1F_Text_CooltrainerMDuring, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_EventScript_CooltrainerMAfter::
	msgbox FuchsiaCity_PokemonCenter1F_Text_CooltrainerMAfter, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter1F_Text_CooltrainerMDuring:
	.string "My dad says the CENTER is the one\n"
	.string "place they won't touch.\p"
	.string "Because they get hurt too.$"

FuchsiaCity_PokemonCenter1F_Text_CooltrainerMAfter:
	.string "The NURSE was up all night and she\n"
	.string "still won't sit down.\p"
	.string "She patched up both sides, you\n"
	.string "know. Didn't ask which was which.$"

FuchsiaCity_PokemonCenter_EventScript_CooltrainerF::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_PokemonCenter_EventScript_CooltrainerFAfter
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, FuchsiaCity_PokemonCenter_EventScript_CooltrainerFDuring
	msgbox FuchsiaCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_EventScript_CooltrainerFDuring::
	msgbox FuchsiaCity_PokemonCenter1F_Text_CooltrainerFDuring, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_EventScript_CooltrainerFAfter::
	msgbox FuchsiaCity_PokemonCenter1F_Text_CooltrainerFAfter, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter1F_Text_CooltrainerFDuring:
	.string "Those girls from the GYM came in\n"
	.string "asking after their LEADER.\p"
	.string "Nobody could tell them anything.$"

FuchsiaCity_PokemonCenter1F_Text_CooltrainerFAfter:
	.string "JANINE walked in this morning and\n"
	.string "every one of those girls stood up\l"
	.string "at once.\p"
	.string "It was quite a thing to see.$"

FuchsiaCity_PokemonCenter_EventScript_JanineClone::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, FuchsiaCity_PokemonCenter_EventScript_JanineCloneGag
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, FuchsiaCity_PokemonCenter_EventScript_JanineCloneDuring
FuchsiaCity_PokemonCenter_EventScript_JanineCloneGag::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAPOKECENTER_WOMAN, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAPOKECENTER_WOMAN
	clearflag FLAG_TEMP_1
	addobject LOCALID_FUCHSIAPOKECENTER_JASMINE
	applymovement LOCALID_FUCHSIAPOKECENTER_JASMINE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAPOKECENTER_JASMINE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator2, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAPOKECENTER_JASMINE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAPOKECENTER_JASMINE
	clearflag FLAG_TEMP_2
	addobject LOCALID_FUCHSIAPOKECENTER_WOMAN
	applymovement LOCALID_FUCHSIAPOKECENTER_WOMAN, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	release
	closemessage
	end

FuchsiaCity_PokemonCenter1F_Text_CooltrainerM:
	.string "Hey! You have a brand new kind of\n"
	.string "POKéDEX.\p"
	.string "Did PROF.OAK give that to you?$"

FuchsiaCity_PokemonCenter1F_Text_CooltrainerF:
	.string "I got quite a shock at the GYM.\p"
	.string "There were all these girls who\n"
	.string "looked identical.$"

FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1:
	.string "I'm JANINE! Hocus-pocus… Poof!$"

FuchsiaCity_PokemonCenter_EventScript_JanineCloneDuring::
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineCloneDuring, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter1F_Text_JanineCloneDuring:
	.string "I do an impression of JANINE.\p"
	.string "It's very good.\p"
	.string "…I don't feel like doing it today.$"

FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator2:
	.string "See? I look just like her now!$"

