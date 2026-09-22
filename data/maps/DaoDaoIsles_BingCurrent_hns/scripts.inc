DaoDaoIsles_BingCurrent_hns_MapScripts::
	.byte 0

DaoDaoIsles_BingCurrent_EventScript_Glacia::
	trainerbattle_single TRAINER_ELITE_GLACIA_HNS, DaoDaoIsles_BingCurrent_Text_GlaciaIntro, DaoDaoIsles_BingCurrent_Text_GlaciaDefeat
	msgbox DaoDaoIsles_BingCurrent_Text_GlaciaAfter, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_BingCurrent_Text_GlaciaIntro:
	.string "Curious, isn't it?\p"
	.string "An island this warm, and yet this\n"
	.string "cave breathes out air cold enough\l"
	.string "to make you shiver.\p"
	.string "I have traveled through many cold\n"
	.string "places, but I did not expect to find\l"
	.string "one here.\p"
	.string "I wanted to see it for myself.\n"
	.string "I think you understand why.\p"
	.string "Well? Shall we see how far the cold\n"
	.string "continues?$"

DaoDaoIsles_BingCurrent_Text_GlaciaDefeat:
	.string "Hehe. Quite a bit colder than I expected.$"

DaoDaoIsles_BingCurrent_Text_GlaciaAfter:
	.string "Go ahead. The cold grows stronger\n"
	.string "as you go deeper.\p"
	.string "I still cannot explain how a place\n"
	.string "like this exists on an island so warm.\p"
	.string "Perhaps that is reason enough to\n"
	.string "keep looking.$"
