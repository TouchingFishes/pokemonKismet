Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, Route8_EventScript_DwayneFallen
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, Route8_EventScript_DwayneDuring
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
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, Route8_EventScript_HarrisFallen
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, Route8_EventScript_HarrisDuring
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
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, Route8_EventScript_ZekeFallen
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, Route8_EventScript_ZekeDuring
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
	.string "Some guy in a suit was paying us.\p"
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
	.string "TION!\n"
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

Route8_Text_LockedDoor:
	.string "It's locked…$"

Route8_Text_UndergroundPathSign:
	.string "The flyer's torn.\p"
	.string "It's impossible to read…$"
