Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, Route8_EventScript_DwayneFallen
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 1, Route8_EventScript_DwayneDuring
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_DwayneDuring::
	msgbox Route8_Text_BikerDwayneDuring, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_DwayneFallen::
	msgbox Route8_Text_BikerDwayneFallen, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS_HNS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, Route8_EventScript_HarrisFallen
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 1, Route8_EventScript_HarrisDuring
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_HarrisDuring::
	msgbox Route8_Text_BikerHarrisDuring, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_HarrisFallen::
	msgbox Route8_Text_BikerHarrisFallen, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE_HNS, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 4, Route8_EventScript_ZekeFallen
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 1, Route8_EventScript_ZekeDuring
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_ZekeDuring::
	msgbox Route8_Text_BikerZekeDuring, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_ZekeFallen::
	msgbox Route8_Text_BikerZekeFallen, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneDuring:
	.string "You should see what we're doing\n"
	.string "down in FUCHSIA right now.\p"
	.string "The FEDERATION will never fall!$"

Route8_Text_BikerDwayneFallen:
	.string "PAXTON is finished, and the boss\n"
	.string "won't even take a call.\p"
	.string "So much for never falling…$"

Route8_Text_BikerHarrisDuring:
	.string "The cops shut our UNDERGROUND\n"
	.string "PATH.\p"
	.string "So PAXTON went and took a whole\n"
	.string "city. That's how you answer that.$"

Route8_Text_BikerHarrisFallen:
	.string "You took FUCHSIA back off us.\p"
	.string "…Was the SAFARI ZONE ever really\n"
	.string "ours to take? I don't know now.$"

Route8_Text_BikerZekeDuring:
	.string "Everyone's ridden south to FUCHSIA.\p"
	.string "Me? I like my teeth where they are.$"

Route8_Text_BikerZekeFallen:
	.string "Some lab type was paying us. Coat\n"
	.string "and all.\p"
	.string "Never saw his face.\n"
	.string "Never want to.$"

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM_HNS, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM_HNS, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "We're the KANTO POKéMON FEDERATION\n"
	.string "trainer group.\p"
	.string "We'll drive you under our wheels!$"

Route8_Text_BikerDwayneBeaten:
	.string "S-sorry!$"

Route8_Text_BikerDwayneAfter:
	.string "The KANTO POKéMON FEDERATION will\n"
	.string "never fall!$"

Route8_Text_BikerHarrisSeen:
	.string "The cops shut down our\n"
	.string "UNDERGROUND PATH!\p"
	.string "That really fries me!$"

Route8_Text_BikerHarrisBeaten:
	.string "F-forgive me!$"

Route8_Text_BikerHarrisAfter:
	.string "Wiped out by some punk from\n"
	.string "JOHTO…$"

Route8_Text_BikerZekeSeen:
	.string "We're the KANTO POKéMON FEDERA-\n"
	.string "TION!\l"
	.string "Right on!$"

Route8_Text_BikerZekeBeaten:
	.string "Yikes! Sorry!$"

Route8_Text_BikerZekeAfter:
	.string "We'll try not to disturb anyone\n"
	.string "from now on…$"

Route8_Text_SupernerdSamSeen:
	.string "How does the MAGNET TRAIN work?$"

Route8_Text_SupernerdSamBeaten:
	.string "I just want to see the MAGNET\n"
	.string "TRAIN…$"

Route8_Text_SupernerdSamAfter:
	.string "The power of magnets is awesome!$"

Route8_Text_SupernerdTomSeen:
	.string "Hm… You've got many GYM BADGES.$"

Route8_Text_SupernerdTomBeaten:
	.string "Just as I thought… You're tough!$"

Route8_Text_SupernerdTomAfter:
	.string "GYM BADGES give you advantages in\n"
	.string "battles.$"

Route8_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA_HNS, Route8_Text_TashaSeen, Route8_Text_TashaBeaten
	msgbox Route8_Text_TashaAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Kindra::
	trainerbattle_single TRAINER_KINDRA_HNS, Route8_Text_KindraSeen, Route8_Text_KindraBeaten
	msgbox Route8_Text_KindraAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Luna::
	trainerbattle_single TRAINER_LUNA_HNS, Route8_Text_LunaSeen, Route8_Text_LunaBeaten
	msgbox Route8_Text_LunaAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_TashaSeen:
	.string "You aren't part of the circle.\p"
	.string "That won't do.$"

Route8_Text_TashaBeaten:
	.string "The spirits didn't warn me…$"

Route8_Text_TashaAfter:
	.string "The veil is thin tonight.\p"
	.string "When the sun sets, we begin the\n"
	.string "séance.\p"
	.string "If you keep walking…\p"
	.string "The others will notice you too.$"

Route8_Text_KindraSeen:
	.string "Can you feel the presence?\p"
	.string "I won't just let someone wander\n"
	.string "in.$"

Route8_Text_KindraBeaten:
	.string "No…\p"
	.string "You're disturbing the séance…$"

Route8_Text_KindraAfter:
	.string "Do you hear that?\p"
	.string "No?\p"
	.string "Good.\p"
	.string "It means they're watching us…\p"
	.string "Not you.$"

Route8_Text_LunaSeen:
	.string "So.\p"
	.string "You passed the others.\p"
	.string "Then the spirits have already\n"
	.string "noticed you.$"

Route8_Text_LunaBeaten:
	.string "…As foretold.$"

Route8_Text_LunaAfter:
	.string "This road is connected to spirits.\p"
	.string "At night, they answer when we\n"
	.string "call.\p"
	.string "You should leave.\p"
	.string "Before something answers you\n"
	.string "back.$"

Route8_Text_LockedDoor:
	.string "It's locked…$"

Route8_Text_UndergroundPathSign:
	.string "The flyer's torn.\p"
	.string "It's impossible to read…$"
