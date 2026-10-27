YellowForestGate_hns_MapScripts::
	.byte 0

YellowForestGate_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_REST_YELLOW_FOREST_GATE, YellowForestGate_EventScript_SleepyManAfter
	msgbox YellowForestGate_Text_SleepyManWakes, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_REST_YELLOW_FOREST_GATE
	msgbox YellowForestGate_Text_DescribeRest, MSGBOX_DEFAULT
	release
	end

YellowForestGate_EventScript_SleepyManAfter:
	msgbox YellowForestGate_Text_SleepyManAfter, MSGBOX_DEFAULT
	release
	end

YellowForestGate_Text_SleepyManWakes:
	.string "...Zzz... Mm? Oh, sorry.\p"
	.string "The forest air gets me every time\n"
	.string "I pass through here.\p"
	.string "You look like you could use a nap\n"
	.string "yourself. Here, take this.$"

YellowForestGate_Text_DescribeRest:
	.string "...Zzz...\p"
	.string "...Umm... Rest!\p"
	.string "The phrase 'recover fast' became\n"
	.string "shortened to 'Rest,' you see?\p"
	.string "This is a move to sleep and recover\n"
	.string "some HP.$"

YellowForestGate_Text_SleepyManAfter:
	.string "...Zzz... Five more minutes...$"
