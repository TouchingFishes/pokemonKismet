GoldenrodHarbor_hns_MapScripts::
	.byte 0

GoldenrodHarbor_EventScript_Sign::
	lock
	msgbox GoldenrodHarbor_Text_Sign, MSGBOX_SIGN
	end

GoldenrodHarbor_EventScript_AdventurerClerk::
	lock
	faceplayer
	message GoldenrodHarbor_Text_AdventurerIntro
	waitmessage
	pokemart GoldenrodHarbor_Pokemart_Adventurer
	msgbox GoldenrodHarbor_Text_AdventurerComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodHarbor_Pokemart_Adventurer:
	.2byte ITEM_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_DESTINY_KNOT
	pokemartlistend

GoldenrodHarbor_EventScript_BallClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodHarbor_Pokemart_Balls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodHarbor_Pokemart_Balls:
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_NET_BALL
	pokemartlistend

GoldenrodHarbor_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_Lass, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_Fisher, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_Sailor::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_Sailor, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_Paton::
	trainerbattle_single TRAINER_PATON_HNS, GoldenrodHarbor_Text_PatonSeen, GoldenrodHarbor_Text_PatonBeaten
	msgbox GoldenrodHarbor_Text_PatonAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodHarbor_EventScript_Katie::
	trainerbattle_single TRAINER_KATIE_HNS, GoldenrodHarbor_Text_KatieSeen, GoldenrodHarbor_Text_KatieBeaten
	msgbox GoldenrodHarbor_Text_KatieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodHarbor_EventScript_James::
	trainerbattle_single TRAINER_JAMES_HNS, GoldenrodHarbor_Text_JamesSeen, GoldenrodHarbor_Text_JamesBeaten
	msgbox GoldenrodHarbor_Text_JamesAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodHarbor_EventScript_StarPiece::
	finditem ITEM_STAR_PIECE
	end

GoldenrodHarbor_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_PokefanF, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_Gentleman, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_Worker::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_Worker, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_OldMan::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_OldMan, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_RaftSailor::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_RaftSailor, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_Tuber::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_Tuber, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodHarbor_Text_Beauty, MSGBOX_DEFAULT
	release
	end

GoldenrodHarbor_EventScript_Jill::
	trainerbattle_single TRAINER_JILL_HNS, GoldenrodHarbor_Text_JillSeen, GoldenrodHarbor_Text_JillBeaten
	msgbox GoldenrodHarbor_Text_JillAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodHarbor_EventScript_Wattrel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WATTREL, CRY_MODE_NORMAL
	msgbox GoldenrodHarbor_Text_Wattrel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodHarbor_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodHarbor_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodHarbor_Text_Sign:
	.string "GOLDENROD HARBOR$"

GoldenrodHarbor_Text_AdventurerIntro:
	.string "I picked up some rare items\n"
	.string "abroad!$"

GoldenrodHarbor_Text_AdventurerComeAgain:
	.string "Come by again!$"

GoldenrodHarbor_Text_Lass:
	.string "All this water, it's totally…\p"
	.string "bloop-bloop, splish-splish.\p"
	.string "Don't you agree?$"

GoldenrodHarbor_Text_Fisher:
	.string "If you're fishing, you have to\n"
	.string "be quiet so you don't scare\l"
	.string "the POKéMON.\p"
	.string "But to be heard over the waves,\n"
	.string "you have to say things LOUD!$"

GoldenrodHarbor_Text_Sailor:
	.string "Travellers from all over the\n"
	.string "world come to this harbor.\p"
	.string "Whatever the sailors bring in\n"
	.string "ends up on the market stalls!$"

GoldenrodHarbor_Text_PatonSeen:
	.string "The fish I caught was attached\n"
	.string "to another POKéMON!$"

GoldenrodHarbor_Text_PatonBeaten:
	.string "Aren't POKéMON interesting?$"

GoldenrodHarbor_Text_PatonAfter:
	.string "You're working on a POKéDEX?\n"
	.string "That's neat!$"

GoldenrodHarbor_Text_KatieSeen:
	.string "Swimming in the deep blue sea\n"
	.string "feels wonderful!$"

GoldenrodHarbor_Text_KatieBeaten:
	.string "I lost…\n"
	.string "Now I feel blue…$"

GoldenrodHarbor_Text_KatieAfter:
	.string "Why is the sea blue?\p"
	.string "I heard it reflects the sky…\p"
	.string "But then why is the sky blue?$"

GoldenrodHarbor_Text_JamesSeen:
	.string "I can swim, but I can also row!$"

GoldenrodHarbor_Text_JamesBeaten:
	.string "Maybe I can't battle…$"

GoldenrodHarbor_Text_JamesAfter:
	.string "Can't a SWIMMER use a rowboat\n"
	.string "sometimes?$"

GoldenrodHarbor_Text_PokefanF:
	.string "Rare items from abroad, right\n"
	.string "here in GOLDENROD!\p"
	.string "I just can't decide…$"

GoldenrodHarbor_Text_Gentleman:
	.string "A DIVE BALL works wonders on\n"
	.string "POKéMON that live in the sea.\p"
	.string "A fine purchase, I assure you.$"

GoldenrodHarbor_Text_Worker:
	.string "Heave-ho! The morning catch\n"
	.string "won't unload itself!\p"
	.string "And that MEOWTH's been after\n"
	.string "the fish all day…$"

GoldenrodHarbor_Text_OldMan:
	.string "I've fished off this bridge for\n"
	.string "forty years.\p"
	.string "Now they put up this barrier.$"

GoldenrodHarbor_Text_RaftSailor:
	.string "Ahoy! Not many folks SURF out\n"
	.string "this far.\p"
	.string "From here you can watch ships\n"
	.string "sailing towards OLIVINE.$"

GoldenrodHarbor_Text_Tuber:
	.string "I'm gonna swim all the way to\n"
	.string "OLIVINE one day!$"

GoldenrodHarbor_Text_Beauty:
	.string "The sea breeze here is lovely…\p"
	.string "Would you mind not blocking my\n"
	.string "sun?$"

GoldenrodHarbor_Text_JillSeen:
	.string "My CORSOLA love it here by\n"
	.string "the rocks!$"

GoldenrodHarbor_Text_JillBeaten:
	.string "Oh no… They're all tired out.$"

GoldenrodHarbor_Text_JillAfter:
	.string "CORSOLA grow on warm, shallow\n"
	.string "seabeds.\p"
	.string "This harbor is just perfect!$"

GoldenrodHarbor_Text_Wattrel:
	.string "WATTREL: Kyiii! Kyiii!$"

GoldenrodHarbor_Text_Meowth:
	.string "MEOWTH: Meowth!$"
