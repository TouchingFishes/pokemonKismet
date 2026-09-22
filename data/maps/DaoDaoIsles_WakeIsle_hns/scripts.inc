DaoDaoIsles_WakeIsle_hns_MapScripts::
	.byte 0

DaoDaoIsles_WakeIsle_EventScript_Sidney::
	trainerbattle_single TRAINER_ELITE_SIDNEY_HNS, DaoDaoIsles_WakeIsle_Text_SidneyIntro, DaoDaoIsles_WakeIsle_Text_SidneyDefeat
	msgbox DaoDaoIsles_WakeIsle_Text_SidneyAfter, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_WakeIsle_Text_SidneyIntro:
	.string "Hey. Nobody comes down this end.\p"
	.string "That's the appeal, mostly.\p"
	.string "Gulls in the morning, something with\n"
	.string "worse manners after dark. Suits me\l"
	.string "either way.\p"
	.string "You've got the walk of someone who's\n"
	.string "beaten a few people who mattered.\p"
	.string "I like that. No hard feelings\n"
	.string "whichever way this goes - that's the\l"
	.string "only rule I've got.$"

DaoDaoIsles_WakeIsle_Text_SidneyDefeat:
	.string "Hah! Well, that's that.$"

DaoDaoIsles_WakeIsle_Text_SidneyAfter:
	.string "No hard feelings. Told you.\p"
	.string "Anyway, the sea's not going to\n"
	.string "watch itself.$"
