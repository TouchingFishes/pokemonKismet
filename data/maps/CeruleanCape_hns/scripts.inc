@ Split out of Route 25. The event scripts these objects run still live in
@ data/maps/Route25_hns/scripts.inc and are referenced across maps.
CeruleanCape_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCape_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CeruleanCape_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	call_if_unset FLAG_IS_KANTO_CHAMPION, CeruleanCape_EventScript_HideHoennLeader
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 7, CeruleanCape_EventScript_SetSuicuneSceneMid
	end

@ Eusine's mid-scene spot. Was Route 25 (98,14); the cut at column 77
@ rebases it to Cape (21,14).
CeruleanCape_EventScript_SetSuicuneSceneMid::
	setobjectxyperm LOCALID_CERULEAN_CAPE_EUSINE, 21, 14
	end

CeruleanCape_EventScript_HideHoennLeader:
	setflag FLAG_TEMP_HIDE_HOENN_LEADER
	return

CeruleanCape_EventScript_Brawly::
	lock
	goto_if_defeated TRAINER_LEADER_BRAWLY_HNS, CeruleanCape_EventScript_BrawlyAfter
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	msgbox CeruleanCape_Text_BrawlyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_BRAWLY_HNS, CeruleanCape_Text_BrawlyDefeat
	msgbox CeruleanCape_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

CeruleanCape_EventScript_BrawlyAfter:
	faceplayer
	msgbox CeruleanCape_Text_BrawlyAfter, MSGBOX_DEFAULT
	release
	end

CeruleanCape_Text_BrawlyIntro:
	.string "Whoa! Didn't see you there, dude.\p"
	.string "I'm BRAWLY, DEWFORD's GYM LEADER.\p"
	.string "The waves around this cape are\n"
	.string "fun, but they're not big enough.\p"
	.string "You look like a gnarly challenge,\n"
	.string "though. Let's ride!$"

CeruleanCape_Text_BrawlyDefeat:
	.string "Wipeout!\n"
	.string "That was one big wave!$"

CeruleanCape_Text_BrawlyPostBattle:
	.string "You're a whole tidal wave, dude!\p"
	.string "I'm gonna hit up the POKéMON\n"
	.string "LEAGUE sometime and ride that\l"
	.string "wave again!$"

CeruleanCape_Text_BrawlyAfter:
	.string "I'm waiting for the perfect wave.\n"
	.string "Some days it just never comes.$"
