ChallengersCave_B3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ChallengersCave_B3F_OnTransition
	.byte 0

ChallengersCave_B3F_OnTransition:
	goto_if_defeated TRAINER_SHAUN_HNS, ChallengersCave_B3F_HideShaun
	end

ChallengersCave_B3F_HideShaun:
	setflag FLAG_TEMP_2
	end

ChallengersCave_B3F_EventScript_Zed::
	trainerbattle_single TRAINER_ZED_HNS, ChallengersCave_B3F_Text_ZedSeen, ChallengersCave_B3F_Text_ZedBeaten
	msgbox ChallengersCave_B3F_Text_ZedAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B3F_EventScript_Esme::
	trainerbattle_single TRAINER_ESME_HNS, ChallengersCave_B3F_Text_EsmeSeen, ChallengersCave_B3F_Text_EsmeBeaten
	msgbox ChallengersCave_B3F_Text_EsmeAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B3F_EventScript_Shaun::
	trainerbattle_single TRAINER_SHAUN_HNS, ChallengersCave_B3F_Text_ShaunSeen, ChallengersCave_B3F_Text_ShaunBeaten, ChallengersCave_B3F_EventScript_ShaunLeaves
	msgbox ChallengersCave_B3F_Text_ShaunAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B3F_Text_ZedSeen:
	.string "You've come far.\p"
	.string "This is where most challengers\n"
	.string "lose their nerve.\p"
	.string "Dragons don't.\p"
	.string "If you wish to go on, prove you\n"
	.string "can stand your ground.$"

ChallengersCave_B3F_Text_ZedBeaten:
	.string "…Impressive.\p"
	.string "Your spirit does not waver.$"

ChallengersCave_B3F_Text_ZedAfter:
	.string "Beyond me waits the final trial.\p"
	.string "Dragons respect those who\n"
	.string "endure.\p"
	.string "Go.$"

ChallengersCave_B3F_Text_EsmeSeen:
	.string "…You're not alone in this cave.\p"
	.string "So many echoes. Battles long\n"
	.string "finished…$"

ChallengersCave_B3F_Text_EsmeBeaten:
	.string "The voices… they grow quiet.$"

ChallengersCave_B3F_Text_EsmeAfter:
	.string "One presence remains ahead.\p"
	.string "It burns brighter than the rest.$"

ChallengersCave_B3F_EventScript_ShaunLeaves::
	msgbox ChallengersCave_B3F_Text_ShaunAfter, MSGBOX_DEFAULT
	msgbox ChallengersCave_B3F_Text_ShaunPewter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_CHALLENGERS_CAVE_SHAUN
	setflag FLAG_TEMP_2
	fadescreen FADE_FROM_BLACK
	release
	end

ChallengersCave_B3F_Text_ShaunPewter:
	.string "If you want to see it,\n"
	.string "come find me in PEWTER CITY.$"

ChallengersCave_B3F_Text_ShaunSeen:
	.string "So.\p"
	.string "You made it.\p"
	.string "Every battle here was meant to\n"
	.string "wear you down.\p"
	.string "I'm the one who waits for\n"
	.string "whoever endures.\p"
	.string "Let's see if your strength still\n"
	.string "remains.$"

ChallengersCave_B3F_Text_ShaunBeaten:
	.string "…It does.\p"
	.string "You never broke.$"

ChallengersCave_B3F_Text_ShaunAfter:
	.string "This cave wasn't about victory.\p"
	.string "It was about resolve.\p"
	.string "Remember this feeling.\p"
	.string "You've earned what comes next.$"

ChallengersCave_B3F_EventScript_ItemKingsRock::
	finditem ITEM_KINGS_ROCK
	end
