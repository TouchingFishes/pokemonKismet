CliffEdgeGate_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CliffEdgeGate_OnTransition
	.byte 0

CliffEdgeGate_OnTransition:
	call_if_ge VAR_SAFARI_ZONE_GATE_STATE, 2, CliffEdgeGate_EventScript_PathOpen
	end

CliffEdgeGate_EventScript_PathOpen:
	setflag FLAG_TEMP_1
	return

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SAFARI_ZONE_GATE_STATE, 2, CliffEdgeGate_EventScript_WomanOpen
	msgbox CliffEdgeGate_Text_IntroClosed, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_WomanOpen:
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroClosed:
	.string "Did you know? They're building a\n"
	.string "SAFARI ZONE just around the corner.\p"
	.string "The path is closed until it's ready,\n"
	.string "but I already can't wait!\p"
	.string "There will be no reason not to go,\n"
	.string "right? Just around the corner.$"

CliffEdgeGate_Text_IntroOpen:
	.string "Did you know? There's a SAFARI ZONE\n"
	.string "just around the corner.\p"
	.string "It's really fun!\n"
	.string "You will see many different kinds of\l"
	.string "POKéMON, and it's all you can catch!\p"
	.string "There is no reason not to go, right?\n"
	.string "Just around the corner.$"

CliffEdgeGate_Text_Expectations:
	.string "I appreciate that everybody is looking\n"
	.string "forward to it.\p"
	.string "But the lady at the reception seems\n"
	.string "a bit too dramatic...\p"
	.string "Don't get your expectations too high!$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	goto_if_ge VAR_SAFARI_ZONE_GATE_STATE, 2, CliffEdgeGate_EventScript_CaveSignOpen
	msgbox CliffEdgeGate_Text_SignClosed, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_EventScript_CaveSignOpen:
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignClosed:
	.string "Everything Will Be Thrilling!\n"
	.string "Explore to Find Wild POKéMON!\l"
	.string "Warden BAOBA's SAFARI ZONE\l"
	.string "Coming Soon!$"

CliffEdgeGate_Text_SignOpen:
	.string "Everything Is Thrilling!\n"
	.string "Explore to Find Wild POKéMON!\l"
	.string "Warden BAOBA's SAFARI ZONE\l"
	.string "Up and Running!$"


CliffEdgeGate_EventScript_Engineer::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end
