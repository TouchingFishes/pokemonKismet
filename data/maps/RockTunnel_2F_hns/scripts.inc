RockTunnel_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RockTunnel_2F_OnTransition:
	callnative SetTimeBasedEncounters
	end

RockTunnel_2F_EventScript_Lenny::
	trainerbattle_single TRAINER_LENNY_HNS, RockTunnel_2F_Text_LennySeen, RockTunnel_2F_Text_LennyBeaten
	msgbox RockTunnel_2F_Text_LennyAfter, MSGBOX_AUTOCLOSE
	end

RockTunnel_2F_Text_LennySeen:
	.string "These tunnels go on longer than\n"
	.string "they should.\p"
	.string "Rock TUNNEL tests your legs as much\n"
	.string "as your nerves.$"

RockTunnel_2F_Text_LennyBeaten:
	.string "Whew… you've got staying power.$"

RockTunnel_2F_Text_LennyAfter:
	.string "Once you see the light at the end,\p"
	.string "you'll never take daylight for\n"
	.string "granted again.$"


RockTunnel_2F_EventScript_Ron::
	trainerbattle_single TRAINER_ROCK_TUNNEL_RON_HNS, RockTunnel_2F_Text_RonSeen, RockTunnel_2F_Text_RonBeaten
	msgbox RockTunnel_2F_Text_RonAfter, MSGBOX_AUTOCLOSE
	end

RockTunnel_2F_Text_RonSeen:
	.string "Heh… hear that?\p"
	.string "Footsteps echo different in here.\p"
	.string "Perfect place for rare POKéMON!$"

RockTunnel_2F_Text_RonBeaten:
	.string "Wha-already?!$"

RockTunnel_2F_Text_RonAfter:
	.string "Caves bring out the strangest\p"
	.string "and strongest POKéMON.\p"
	.string "I'm not leaving until I find them!$"


RockTunnel_2F_EventScript_Theresa::
	trainerbattle_single TRAINER_THERESA_HNS, RockTunnel_2F_Text_TheresaSeen, RockTunnel_2F_Text_TheresaBeaten
	msgbox RockTunnel_2F_Text_TheresaAfter, MSGBOX_AUTOCLOSE
	end

RockTunnel_2F_Text_TheresaSeen:
	.string "Rock TUNNEL… A fitting place.\p"
	.string "I once trained at VIRIDIAN GYM,\n"
	.string "before its doors fell silent.\p"
	.string "GROUND-type POKéMON endure\n"
	.string "pressure.\p"
	.string "Let me show you what that means.$"

RockTunnel_2F_Text_TheresaBeaten:
	.string "Mm…\n"
	.string "Well done.$"

RockTunnel_2F_Text_TheresaAfter:
	.string "When GIOVANNI disappeared,\p"
	.string "many thought the GYM lost its soul.\p"
	.string "But strength does not vanish.\p"
	.string "It simply waits beneath the earth.$"


RockTunnel_2F_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE_HNS, RockTunnel_2F_Text_BriceSeen, RockTunnel_2F_Text_BriceBeaten
	msgbox RockTunnel_2F_Text_BriceAfter, MSGBOX_AUTOCLOSE
	end

RockTunnel_2F_Text_BriceSeen:
	.string "Rock TUNNEL never gets easier.\p"
	.string "Dark, cramped, and full of turns.\p"
	.string "If you lose focus in here, you're\n"
	.string "done.$"

RockTunnel_2F_Text_BriceBeaten:
	.string "Hah… still solid form.$"

RockTunnel_2F_Text_BriceAfter:
	.string "Some caves test your strength.\p"
	.string "This one tests your nerves.$"

RockTunnel_2F_EventScript_Burt::
	trainerbattle_single TRAINER_ROCK_TUNNEL_BURT_HNS, RockTunnel_2F_Text_BurtSeen, RockTunnel_2F_Text_BurtBeaten
	msgbox RockTunnel_2F_Text_BurtAfter, MSGBOX_AUTOCLOSE
	end

RockTunnel_2F_Text_BurtSeen:
	.string "Step right up and take a look!$"

RockTunnel_2F_Text_BurtBeaten:
	.string "Yow! That's hot!$"

RockTunnel_2F_Text_BurtAfter:
	.string "The greatest firebreather in KANTO,\n"
	.string "that's me.\p"
	.string "But not the best trainer…$"


RockTunnel_2F_EventScript_Dale::
	trainerbattle_single TRAINER_ROCK_TUNNEL_DALE_HNS, RockTunnel_2F_Text_DaleSeen, RockTunnel_2F_Text_DaleBeaten
	msgbox RockTunnel_2F_Text_DaleAfter, MSGBOX_AUTOCLOSE
	end

RockTunnel_2F_Text_DaleSeen:
	.string "I thought camping would toughen me\n"
	.string "up…\p"
	.string "But caves are a whole different\n"
	.string "story.$"

RockTunnel_2F_Text_DaleBeaten:
	.string "Guess I still need practice…$"

RockTunnel_2F_Text_DaleAfter:
	.string "Once I'm through here, the rest of\n"
	.string "KANTO can't scare me anymore.$"
