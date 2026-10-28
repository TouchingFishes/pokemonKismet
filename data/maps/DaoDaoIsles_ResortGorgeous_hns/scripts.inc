DaoDaoIsles_ResortGorgeous_hns_MapScripts::
	.byte 0

DaoDaoIsles_ResortGorgeous_EventScript_Bastien::
	trainerbattle_single TRAINER_BASTIEN_HNS, DaoDaoIsles_ResortGorgeous_Text_BastienSeen, DaoDaoIsles_ResortGorgeous_Text_BastienBeaten
	msgbox DaoDaoIsles_ResortGorgeous_Text_BastienAfter, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_ResortGorgeous_Text_BastienSeen:
	.string "This beach is my stage! Let my\n"
	.string "POKéMON play you a tune!$"

DaoDaoIsles_ResortGorgeous_Text_BastienBeaten:
	.string "Whoa… you hit every note.$"

DaoDaoIsles_ResortGorgeous_Text_BastienAfter:
	.string "The waves keep the beat, I just\n"
	.string "play along. Come back for an encore!$"
