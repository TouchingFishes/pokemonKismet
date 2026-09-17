DiglettsCave_Tunnel_hns_MapScripts::
	.byte 0

DiglettsCave_Tunnel_EventScript_CaveGuard::
	lock
	faceplayer
	msgbox DiglettsCave_Tunnel_Text_CaveGuard, MSGBOX_DEFAULT
	closemessage
	release
	end

DiglettsCave_Tunnel_Text_CaveGuard:
	.string "Whoa there. That hole drops into\n"
	.string "CHALLENGER'S CAVE.\p"
	.string "Trainers go down there to find out\n"
	.string "what they're actually worth.\p"
	.string "Come back when you've something to\n"
	.string "prove. You'll know when.$"
