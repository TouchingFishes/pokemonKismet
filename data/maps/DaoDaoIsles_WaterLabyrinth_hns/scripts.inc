DaoDaoIsles_WaterLabyrinth_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DaoDaoIsles_WaterLabyrinth_OnTransition
	.byte 0

DaoDaoIsles_WaterLabyrinth_OnTransition:
	setflag FLAG_TEMP_1
	goto_if_defeated TRAINER_DAODAO_LAB_BIKER_1_HNS, DaoDaoIsles_WaterLabyrinth_OnTransitionEnd
	clearflag FLAG_TEMP_1
DaoDaoIsles_WaterLabyrinth_OnTransitionEnd:
	end

DaoDaoIsles_WaterLabyrinth_EventScript_DoorGuard::
	lock
	faceplayer
	msgbox DaoDaoIsles_WaterLabyrinth_Text_GuardIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DAODAO_LAB_BIKER_1_HNS, DaoDaoIsles_WaterLabyrinth_Text_GuardDefeat
	msgbox DaoDaoIsles_WaterLabyrinth_Text_GuardPost, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DAODAO_LAB_DOORGUARD, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_EXIT
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DAODAO_LAB_DOORGUARD
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

DaoDaoIsles_WaterLabyrinth_Text_GuardIntro:
	.string "Far enough.\p"
	.string "There's nothing out here. No house,\n"
	.string "no door, no nothing.\p"
	.string "And I'm nobody, standing in front\n"
	.string "of it.$"

DaoDaoIsles_WaterLabyrinth_Text_GuardDefeat:
	.string "Augh! Off the bike and everything!$"

DaoDaoIsles_WaterLabyrinth_Text_GuardPost:
	.string "Fine. FINE.\p"
	.string "I'm not getting paid enough to\n"
	.string "stand in the salt for him anyway.\p"
	.string "He's down there. That's all I know.\n" 
	.string "Go bother him instead.$"
