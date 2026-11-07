Tanglebrush_hns_MapScripts::
	.byte 0

Tanglebrush_EventScript_Silas::
	trainerbattle_single TRAINER_SILAS_HNS, Tanglebrush_Text_SilasIntro, Tanglebrush_Text_SilasDefeat
	msgbox Tanglebrush_Text_SilasAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET_HNS, Tanglebrush_Text_GarretIntro, Tanglebrush_Text_GarretDefeat
	msgbox Tanglebrush_Text_GarretAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Orrin::
	trainerbattle_single TRAINER_ORRIN_HNS, Tanglebrush_Text_OrrinIntro, Tanglebrush_Text_OrrinDefeat
	msgbox Tanglebrush_Text_OrrinAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Kester::
	trainerbattle_single TRAINER_KESTER_HNS, Tanglebrush_Text_KesterIntro, Tanglebrush_Text_KesterDefeat
	msgbox Tanglebrush_Text_KesterAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Nash::
	trainerbattle_single TRAINER_NASH_HNS, Tanglebrush_Text_NashIntro, Tanglebrush_Text_NashDefeat
	msgbox Tanglebrush_Text_NashAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Cordelia::
	trainerbattle_single TRAINER_CORDELIA_HNS, Tanglebrush_Text_CordeliaIntro, Tanglebrush_Text_CordeliaDefeat
	msgbox Tanglebrush_Text_CordeliaAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Joana::
	trainerbattle_single TRAINER_JOANA_HNS, Tanglebrush_Text_JoanaIntro, Tanglebrush_Text_JoanaDefeat
	msgbox Tanglebrush_Text_JoanaAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Marcy::
	trainerbattle_single TRAINER_MARCY_HNS, Tanglebrush_Text_MarcyIntro, Tanglebrush_Text_MarcyDefeat
	msgbox Tanglebrush_Text_MarcyAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Layton::
	trainerbattle_single TRAINER_LAYTON_HNS, Tanglebrush_Text_LaytonIntro, Tanglebrush_Text_LaytonDefeat
	msgbox Tanglebrush_Text_LaytonAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_Text_SilasIntro:
	.string "I patrol this wood. Nothing gets\npoached on my watch.$"

Tanglebrush_Text_SilasDefeat:
	.string "You clearly respect this place.$"

Tanglebrush_Text_SilasAfter:
	.string "Tread lightly and the forest will\ntreat you kindly.\p"
	.string "There's a gap in the trees along\n"
	.string "the north path. I keep away from it.\p"
	.string "Whatever's in there shakes the\n"
	.string "whole canopy when it moves.$"

Tanglebrush_Text_GarretIntro:
	.string "I've raised every WORMADAM cloak\nthere is. Look at them!$"

Tanglebrush_Text_GarretDefeat:
	.string "Each one is beautiful, isn't it?$"

Tanglebrush_Text_GarretAfter:
	.string "A WORMADAM's cloak depends on where\nit evolved. Fascinating, isn't it?$"

Tanglebrush_Text_OrrinIntro:
	.string "The BUG POKéMON here are only\nactive at this hour.$"

Tanglebrush_Text_OrrinDefeat:
	.string "Amazing! You knew their habits!$"

Tanglebrush_Text_OrrinAfter:
	.string "Come back at dusk. You'll meet\nsomething quite different.$"

Tanglebrush_Text_KesterIntro:
	.string "You got this deep? Then you can\nhandle my best.$"

Tanglebrush_Text_KesterDefeat:
	.string "Incredible… my strongest, beaten.$"

Tanglebrush_Text_KesterAfter:
	.string "You've earned the right to walk\nthis wood.\p"
	.string "The old one in the north clearing\n"
	.string "is another matter, though.$"

Tanglebrush_Text_NashIntro:
	.string "My POKéMON don't need to evolve\nto be strong!$"

Tanglebrush_Text_NashDefeat:
	.string "Perhaps they need a little longer…$"

Tanglebrush_Text_NashAfter:
	.string "I'll raise them my own way, thanks.$"

Tanglebrush_Text_CordeliaIntro:
	.string "I'm raising every one of them\nfrom an egg!$"

Tanglebrush_Text_CordeliaDefeat:
	.string "Oh dear, they're still so young.$"

Tanglebrush_Text_CordeliaAfter:
	.string "They'll grow up big one day.\nYou'll see!$"

Tanglebrush_Text_JoanaIntro:
	.string "I've got lost in here twice already!$"

Tanglebrush_Text_JoanaDefeat:
	.string "And now I've lost a battle too…$"

Tanglebrush_Text_JoanaAfter:
	.string "If you find the way out, come back\nand tell me!\p"
	.string "But stay out of that gap in the\n"
	.string "north trees. Something in there\l"
	.string "growled at me!$"

Tanglebrush_Text_MarcyIntro:
	.string "My TANGELA won't let go of me!$"

Tanglebrush_Text_MarcyDefeat:
	.string "Even holding on, we lost…$"

Tanglebrush_Text_MarcyAfter:
	.string "Their vines are softer than they\nlook, you know.\p"
	.string "Not like the ones up north.\n"
	.string "Those vines are as thick as my arm,\l"
	.string "and they move on their own!$"

Tanglebrush_Text_LaytonIntro:
	.string "There are ruins under these roots.\nI'm certain of it!$"

Tanglebrush_Text_LaytonDefeat:
	.string "Bah! You battle better than I dig.$"

Tanglebrush_Text_LaytonAfter:
	.string "That SUDOWOODO was standing on\nsomething. I know it!$"

Tanglebrush_EventScript_ItemBigMushroom::
	finditem ITEM_BIG_MUSHROOM
	end

Tanglebrush_EventScript_ItemBalmMushroom::
	finditem ITEM_BALM_MUSHROOM
	end

Tanglebrush_EventScript_ItemLeafStone::
	finditem ITEM_LEAF_STONE
	end

Tanglebrush_EventScript_ItemMiracleSeed::
	finditem ITEM_MIRACLE_SEED
	end

Tanglebrush_EventScript_Tangrowth::
	lock
	faceplayer
	playmoncry SPECIES_TANGROWTH, 0
	msgbox Tanglebrush_Text_TangrowthRoar, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_TANGELA, 70, ITEM_NONE, SPECIES_TANGROWTH, 70, ITEM_OCCA_BERRY
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 1, 1, 1, 1
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_SHINY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Tanglebrush_EventScript_TangrowthWon
	@ Any other ending (your Dragon Tail or Circle Throw, say) still undoes the battle flags.
	goto Tanglebrush_EventScript_TangrowthEnd

Tanglebrush_EventScript_TangrowthWon:
	setflag FLAG_HIDE_TANGLEBRUSH_TANGROWTH
	removeobject LOCALID_TANGLEBRUSH_TANGROWTH
	msgbox Tanglebrush_Text_TangrowthDefeated, MSGBOX_AUTOCLOSE
Tanglebrush_EventScript_TangrowthEnd:
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_SHINY
	release
	end

Tanglebrush_Text_TangrowthRoar:
	.string "Graah!$"

Tanglebrush_Text_TangrowthDefeated:
	.string "Totem TANGROWTH was defeated!\n"
	.string "It scampered off somewhere…$"
