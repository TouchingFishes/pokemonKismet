LavenderTown_House2_hns_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_Woman::
	lock
	faceplayer
	msgbox LavenderSpeechHouse_Text_PokefanF, MSGBOX_DEFAULT
	goto MoveTutor_EventScript_CurseTutor_hns
	end

LavenderSpeechHouse_Text_PokefanF:
	.string "LAVENDER is a tiny, quiet town at\n"
	.string "the foot of the mountains.\p"
	.string "It's gotten a bit busier since\n"
	.string "the RADIO TOWER was built.$"
