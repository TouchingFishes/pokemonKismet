DaoDaoIsles_TreasureBeach_hns_MapScripts::
	.byte 0

DaoDaoIsles_TreasureBeach_EventScript_Rock1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_1, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_1
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_2, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_2
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock3::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_3, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_3
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock4::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_4, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_4
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock5::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_5, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_5
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock6::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_6, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_6
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock7::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_7, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_7
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock8::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_8, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_8
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock9::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_9, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_9
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock10::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_10, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_10
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock11::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_11, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_11
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

DaoDaoIsles_TreasureBeach_EventScript_Rock12::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_TREASURE_ROCK_12, DaoDaoIsles_TreasureBeach_EventScript_RockSearched
	setflag FLAG_DAILY_TREASURE_ROCK_12
	goto DaoDaoIsles_TreasureBeach_EventScript_RockRoll
	end

@ Shared tail. The daily flag is already set by the time we get here, so a rock
@ that turns up empty still costs the player that rock for the day.
DaoDaoIsles_TreasureBeach_EventScript_RockRoll::
	special RollTreasureBeachItem
	goto_if_eq VAR_RESULT, ITEM_NONE, DaoDaoIsles_TreasureBeach_EventScript_RockEmpty
	msgbox DaoDaoIsles_TreasureBeach_Text_RockTreasure, MSGBOX_DEFAULT
	giveitem VAR_RESULT
	release
	end

DaoDaoIsles_TreasureBeach_EventScript_RockEmpty::
	msgbox DaoDaoIsles_TreasureBeach_Text_RockEmpty, MSGBOX_DEFAULT
	release
	end

DaoDaoIsles_TreasureBeach_EventScript_RockSearched::
	msgbox DaoDaoIsles_TreasureBeach_Text_RockSearched, MSGBOX_DEFAULT
	release
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
