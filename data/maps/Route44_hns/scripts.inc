Route44_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_HNS, Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten, Route44_EventScript_RegisterWilton
	goto_if_set FLAG_WILTON_HAS_ITEM_HNS, Route44_EventScript_WiltonGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchWilton
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_HNS
	release
	end

Route44_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_HNS, Route44_Text_WiltonRematchIntro, Route44_Text_WiltonRematchDefeat
	msgbox Route44_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonGiveItem::
	msgbox Route44_Text_WiltonHasItem, MSGBOX_DEFAULT
	giveitem VAR_WILTON_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route44_EventScript_WiltonNoRoom
	clearflag FLAG_WILTON_HAS_ITEM_HNS
	msgbox Route44_Text_WiltonGaveItem, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonNoRoom::
	msgbox Route44_Text_WiltonNoRoom, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR_HNS, Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE_HNS, Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten, Route44_EventScript_RegisterVance
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchVance
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterVance::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_VanceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VANCE_HNS
	release
	end

Route44_EventScript_RematchVance::
	trainerbattle_rematch TRAINER_VANCE_HNS, Route44_Text_VanceRematchIntro, Route44_Text_VanceRematchDefeat
	msgbox Route44_Text_VancePostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL_HNS, Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_HNS, Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN_HNS, Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL_HNS, Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
    .string "Aack!\p"
    .string "You made me lose a POLIWAG!\n"
    .string "What are you going to do about it?$"

Route44_Text_FisherWilton1Beaten:
    .string "Just forget about it.$"

Route44_Text_FisherWiltonHugePoliwag:
    .string "That POLIWAG that got away…\n"
    .string "it was huge.\p"
    .string "I swear it must've been\n"
    .string "16 feet long!$"

Route44_Text_WiltonRegister:
    .string "That POLIWAG that got away…\n"
    .string "it was huge.\p"
    .string "I swear it must've been\n"
    .string "16 feet long!$"

Route44_Text_WiltonRematchIntro:
    .string "Aack!\p"
    .string "You made me lose a POLIWAG!\n"
    .string "What are you going to do about it?$"

Route44_Text_WiltonRematchDefeat:
    .string "Just forget about it.$"

Route44_Text_WiltonPostRematch:
    .string "That POLIWAG that got away…\n"
    .string "it was huge.\p"
    .string "I swear it must've been\n"
    .string "16 feet long!$"

Route44_Text_WiltonHasItem:
    .string "Hey! I reeled in something\n"
    .string "other than a POKéMON!\p"
    .string "Here, you can have it!$"

Route44_Text_WiltonGaveItem:
    .string "I'll let you know if I\n"
    .string "fish up anything else!$"

Route44_Text_WiltonNoRoom:
    .string "Hmm, your BAG is full.\p"
    .string "Come back when you have room.$"

Route44_Text_FisherEdgarSeen:
    .string "I fish until I can't anymore.\p"
    .string "I also battle until I drop.\p"
    .string "That's my relationship with my\n"
    .string "POKéMON.$"

Route44_Text_FisherEdgarBeaten:
    .string "Hmmmm… This isn't right.$"

Route44_Text_FisherEdgarAfter:
    .string "That's 100 wins to 101 losses.\p"
    .string "I won't battle again for a while.$"

Route44_Text_BirdKeeperVance1Seen:
    .string "Do you know about the legendary\n"
    .string "bird POKéMON?$"

Route44_Text_BirdKeeperVance1Beaten:
    .string "Whew! You're hot stuff.$"

Route44_Text_BirdKeeperVanceBirds:
    .string "ARTICUNO, ZAPDOS and MOLTRES are\n"
    .string "the three legendary bird POKéMON.\p"
    .string "I heard there are other legendary\n"
    .string "birds, though.$"

Route44_Text_VanceRegister:
    .string "ARTICUNO, ZAPDOS and MOLTRES are\n"
    .string "the three legendary bird POKéMON.\p"
    .string "I heard there are other legendary\n"
    .string "birds, though.$"

Route44_Text_VanceRematchIntro:
    .string "Do you know about the legendary\n"
    .string "bird POKéMON?$"

Route44_Text_VanceRematchDefeat:
    .string "Whew! You're hot stuff.$"

Route44_Text_VancePostRematch:
    .string "ARTICUNO, ZAPDOS and MOLTRES are\n"
    .string "the three legendary bird POKéMON.\p"
    .string "I heard there are other legendary\n"
    .string "birds, though.$"

Route44_Text_PsychicPhilSeen:
    .string "I'm gonna win, for sure!$"

Route44_Text_PsychicPhilBeaten:
    .string "Arrgh… That's a shocking loss…$"

Route44_Text_PsychicPhilAfter:
    .string "It's important to have conviction\n"
    .string "on your side.$"

Route44_Text_PokemaniacZachSeen:
    .string "I'll do anything to get my hands\n"
    .string "on rare POKéMON!$"

Route44_Text_PokemaniacZachBeaten:
    .string "Oooh, your POKéMON are so\n"
    .string "appealing.$"

Route44_Text_PokemaniacZachAfter:
    .string "If a POKéMON has different colors\n"
    .string "from usual, it's more valuable.\p"
    .string "What? You mean that's not true?$"

Route44_Text_CooltrainermAllenSeen:
    .string "I can tell you're a good trainer\n"
    .string "by looking at you.\p"
    .string "I'm good at POKéMON, and I can\n"
    .string "see that you are too.$"

Route44_Text_CooltrainermAllenBeaten:
    .string "Tch! It's a total loss on my part.$"

Route44_Text_CooltrainermAllenAfter:
    .string "Wow. You have a lot of BADGES.\p"
    .string "No wonder you're so tough.\p"
    .string "I wonder if ECRUTEAK GYM's MORTY\n"
    .string "is still in training?\p"
    .string "He really hammered me.$"

Route44_Text_CooltrainerfCybilSeen:
    .string "You look strong.\p"
    .string "Good trainers seek tough\n"
    .string "opponents instinctively.$"

Route44_Text_CooltrainerfCybilBeaten:
    .string "Nope! This won't do at all.$"

Route44_Text_CooltrainerfCybilAfter:
    .string "We all get better by experiencing\n"
    .string "many battles.\p"
    .string "I battled a lot to become what I\n"
    .string "am today--an elite.$"

Route44_Text_Sign1:
    .string "ROUTE 44\n"
    .string "ICE PATH AHEAD$"

Route44_Text_Sign2:
    .string "ROUTE 44\p"
    .string "MAHOGANY TOWN - BLACKTHORN CITY$"

Route44_EventScript_Harvey::
	trainerbattle_single TRAINER_HARVEY_HNS, Route44_Text_CamperHarveySeen, Route44_Text_CamperHarveyBeaten
	msgbox Route44_Text_CamperHarveyAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Darren::
	trainerbattle_single TRAINER_DARREN_HNS, Route44_Text_RichBoyDarrenSeen, Route44_Text_RichBoyDarrenBeaten
	msgbox Route44_Text_RichBoyDarrenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Anders::
	trainerbattle_single TRAINER_ANDERS_HNS, Route44_Text_BirdKeeperAndersSeen, Route44_Text_BirdKeeperAndersBeaten
	msgbox Route44_Text_BirdKeeperAndersAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Nolan::
	trainerbattle_single TRAINER_NOLAN_HNS, Route44_Text_FisherNolanSeen, Route44_Text_FisherNolanBeaten
	msgbox Route44_Text_FisherNolanAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH_HNS, Route44_Text_LadySarahSeen, Route44_Text_LadySarahBeaten
	msgbox Route44_Text_LadySarahAfter, MSGBOX_AUTOCLOSE
	end

Route44_Text_CamperHarveySeen:
	.string "Hiking all the way up here has\n"
	.string "been a blast.\p"
	.string "Let's battle!$"

Route44_Text_CamperHarveyBeaten:
	.string "That was tough!$"

Route44_Text_CamperHarveyAfter:
	.string "I'm so exhausted.$"

Route44_Text_RichBoyDarrenSeen:
	.string "I spent ages looking for my\n"
	.string "team.\p"
	.string "Let's find out if it was worth\n"
	.string "it.$"

Route44_Text_RichBoyDarrenBeaten:
	.string "Seems like the time I spent\n"
	.string "was not worth it.$"

Route44_Text_RichBoyDarrenAfter:
	.string "Someone told me that my POKéMON\n"
	.string "are on the cusp of realizing\l"
	.string "their full potential.$"

Route44_Text_BirdKeeperAndersSeen:
	.string "I love the way my birds can\n"
	.string "tame the wind.\p"
	.string "Let me show you!$"

Route44_Text_BirdKeeperAndersBeaten:
	.string "What a show!$"

Route44_Text_BirdKeeperAndersAfter:
	.string "Bird POKéMON are the strongest.\p"
	.string "Trust me.$"

Route44_Text_FisherNolanSeen:
	.string "I like travelling around and\n"
	.string "enjoying nature.\p"
	.string "How about a battle?$"

Route44_Text_FisherNolanBeaten:
	.string "Darn!$"

Route44_Text_FisherNolanAfter:
	.string "These mountain lakes are so\n"
	.string "pristine.$"

Route44_Text_LadySarahSeen:
	.string "Oh… a challenger?\p"
	.string "How delightful.\p"
	.string "Do be gentle, won't you?\n"
	.string "I so dislike unpleasant battles.$"

Route44_Text_LadySarahBeaten:
	.string "Ah… how gracefully you fight.\p"
	.string "I concede with no regrets.$"

Route44_Text_LadySarahAfter:
	.string "Battles need not be harsh to be\n"
	.string "meaningful.\p"
	.string "A calm heart and steady hand…\n"
	.string "that is true elegance.\p"
	.string "I do hope our encounter brought\n"
	.string "you a measure of peace.$"
