Route3_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS_HNS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN_HNS, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY_HNS, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT_HNS, Route3_Text_HikerBurt_Seen, Route3_Text_HikerBurt_Beaten
	msgbox Route3_Text_HikerBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "Ah! The weather's as fine as ever.$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "It's sunny, but I'm all wet…$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "When it rains, it's hard to get\n"
	.string "ignition…$"

Route3_Text_YoungsterWarren_Seen:
	.string "Hmmm… I don't know what to do…$"

Route3_Text_YoungsterWarren_Beaten:
	.string "I knew I'd lose…$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "You looked strong.\p"
	.string "I was afraid to take you on…$"

Route3_Text_YoungsterJimmy_Seen:
	.string "I can run like the wind!$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "Blown away!$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "I wear shorts the whole year round.\p"
	.string "That's my fashion policy.$"

Route3_Text_HikerBurt_Seen:
	.string "I came down from MT. MOON just\n"
	.string "to test my POKéMON on you!$"

Route3_Text_HikerBurt_Beaten:
	.string "Whoa! Talk about a rockslide!$"

Route3_Text_HikerBurt_AfterBattle:
	.string "My POKéMON blow smoke to clear\n"
	.string "the dust in the caves. Handy, eh?$"

Route3_Text_MtMoonSquareSign:
	.string "MT.MOON SQUARE\p"
	.string "Just go up the stairs.$"

Route3_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_HNS, Route3_Text_HikerTrentSeen, Route3_Text_HikerTrentBeaten
	msgbox Route3_Text_HikerTrentAfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_HikerTrentSeen:
	.string "Hold it! I'm warming up for\n"
	.string "MT. MOON. You'll do nicely!$"

Route3_Text_HikerTrentBeaten:
	.string "Huff… I'm the one who got\n"
	.string "flattened!$"

Route3_Text_HikerTrentAfterBattle:
	.string "My SUDOWOODO pretends to be a\n"
	.string "tree, and my PROBOPASS always\l"
	.string "points north. Odd rocks, eh?$"
