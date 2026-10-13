RockTunnel_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RockTunnel_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

RockTunnel_B1F_EventScript_ItemFling::
	finditem ITEM_TM_FLING
	end

RockTunnel_B1F_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

RockTunnel_B1F_EventScript_Margret::
	trainerbattle_single TRAINER_MARGRET_HNS, RockTunnel_B1F_Text_MargretSeen, RockTunnel_B1F_Text_MargretBeaten
	msgbox RockTunnel_B1F_Text_MargretAfter, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_MargretSeen:
	.string "The air changes near the exit.\p"
	.string "LAVENDER TOWN is close…\p"
	.string "Many spirits rest there, uneasy\n"
	.string "but not lost.$"

RockTunnel_B1F_Text_MargretBeaten:
	.string "They accept you.$"

RockTunnel_B1F_Text_MargretAfter:
	.string "Treat LAVENDER with respect.\p"
	.string "Its history still whispers to\n"
	.string "those who listen.$"


RockTunnel_B1F_EventScript_Nora::
	trainerbattle_single TRAINER_NORA_HNS, RockTunnel_B1F_Text_NoraSeen, RockTunnel_B1F_Text_NoraBeaten
	msgbox RockTunnel_B1F_Text_NoraAfter, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_NoraSeen:
	.string "I keep watch so no one gets lost.$"

RockTunnel_B1F_Text_NoraBeaten:
	.string "Good awareness.$"

RockTunnel_B1F_Text_NoraAfter:
	.string "Keep going. You almost made it to\n"
	.string "LAVENDER.$"

