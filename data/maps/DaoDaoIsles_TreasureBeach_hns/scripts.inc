DaoDaoIsles_TreasureBeach_hns_MapScripts::
	.byte 0

DaoDaoIsles_TreasureBeach_EventScript_Rock1::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_1, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_1
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock2::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_2, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_2
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock3::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_3, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_3
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock4::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_4, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_4
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock5::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_5, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_5
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock6::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_6, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_6
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock7::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_7, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_7
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock8::
	lockall
	goto_if_set FLAG_DAILY_TREASURE_ROCK_8, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_8
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_RockRoll::
	special RollTreasureBeachItem
	goto_if_eq VAR_RESULT, ITEM_NONE, DaoDaoIsles_TreasureBeach_EventScript_RockEmpty
	msgbox DaoDaoIsles_TreasureBeach_Text_RockTreasure, MSGBOX_DEFAULT
	giveitem VAR_RESULT
	releaseall
	end

DaoDaoIsles_TreasureBeach_EventScript_RockEmpty::
	msgbox DaoDaoIsles_TreasureBeach_Text_RockEmpty, MSGBOX_DEFAULT
	releaseall
	end

DaoDaoIsles_TreasureBeach_EventScript_RockSearched::
	msgbox DaoDaoIsles_TreasureBeach_Text_RockSearched, MSGBOX_DEFAULT
	releaseall
	end

DaoDaoIsles_TreasureBeach_Text_RockTreasure:
	.string "Something is wedged in the sand\n"
	.string "beneath the rock!$"

DaoDaoIsles_TreasureBeach_Text_RockEmpty:
	.string "{PLAYER} rolled the rock aside.\p"
	.string "Nothing but damp sand underneath.$"

DaoDaoIsles_TreasureBeach_Text_RockSearched:
	.string "This rock has already been\n"
	.string "turned over today.\p"
	.string "The tide may wash something new\n"
	.string "in by tomorrow.$"
