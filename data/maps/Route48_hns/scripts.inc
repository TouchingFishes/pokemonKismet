Route48_hns_MapScripts::
	.byte 0

Route48_EventScript_RangerIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route48_Text_RangerIvanSeen, Route48_Text_RangerIvanBeaten
	msgbox Route48_Text_RangerIvanAfter, MSGBOX_AUTOCLOSE
	end

Route48_Text_RangerIvanSeen:
	.string "I've been getting POKéMON data off\n"
	.string "my radio. I think I'm good.$"

Route48_Text_RangerIvanBeaten:
	.string "I give!$"

Route48_Text_RangerIvanAfter:
	.string "Music on the radio changes the\n"
	.string "moods of wild POKéMON.$"

