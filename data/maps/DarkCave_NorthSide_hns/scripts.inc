DarkCave_NorthSide_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DarkCave_NorthSide_OnTransition: 
	callnative SetTimeBasedEncounters
	end

DarkCave2_EventScript_Item_BlackFlute::
	finditem ITEM_BLACK_FLUTE
	end

DarkCave2_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
    .string "Whoa! You startled me there!\p"
    .string "I had my BLACK-GLASSES on, so I\n"
    .string "didn't notice you at all.\p"
    .string "What am I doing here?\p"
    .string "Hey, don't you worry about it.\p"
    .string "I'll give you a pair of BLACK-\n"
    .string "GLASSES, so forget you saw me,\l"
    .string "OK?$"

DarkCave2_Text_Nerd2:
    .string "BLACK-GLASSES ups the power of\n"
    .string "DARK-type moves.$"

DarkCave2_EventScript_Bobby::
	trainerbattle_single TRAINER_BOBBY_HNS, DarkCave2_Text_BobbySeen, DarkCave2_Text_BobbyBeaten
	msgbox DarkCave2_Text_BobbyAfter, MSGBOX_AUTOCLOSE
	end

DarkCave2_Text_BobbySeen:
	.string "Tell you what, the wall\n"
	.string "before me has the perfect\l"
	.string "condition for drilling a\l"
	.string "tunnel.\p"
	.string "Oh, you wanna battle?!$"

DarkCave2_Text_BobbyBeaten:
	.string "Uff. You're good.$"

DarkCave2_Text_BobbyAfter:
	.string "I tell you…\p"
	.string "If people wanted to, me and\n"
	.string "my pals could build a\l"
	.string "tunnel here…$"
