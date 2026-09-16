DiglettsCave_EntranceNorth_hns_MapScripts::
	.byte 0

DiglettsCave_EntranceNorth_EventScript_Hiker::
	msgbox DiglettsCave_EntranceNorth_Text_Hiker, MSGBOX_NPC
	end

DiglettsCave_EntranceNorth_Text_Hiker:
	.string "Don't even think about digging\n"
	.string "through that lot.\p"
	.string "There's a researcher on the other\n"
	.string "side who'd have my head for it.\p"
	.string "Rare as anything, he reckons.\p"
	.string "Leave them be and they'll move on\n"
	.string "in their own time.$"


DiglettsCave_EntranceNorth_EventScript_Brock::
    lock
    faceplayer
    msgbox DiglettsCave_EntranceNorth_Text_Brock, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DIGLETT_BROCK
    removeobject LOCALID_DIGLETT_BROCK
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BROCK
    release
    end

DiglettsCave_EntranceNorth_Text_Brock:
    .string "BROCK: Small spaces surrounded by\n"
    .string "rocks make you feel peaceful,\l"
    .string "don't you agree?\p"
	.string "If you want another match, I'll be\n"
	.string "at the FIGHTING DOJO.$"




