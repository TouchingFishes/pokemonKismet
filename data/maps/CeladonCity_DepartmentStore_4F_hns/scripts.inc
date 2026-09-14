CeladonCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "I'm here to buy SURF MAIL to send\n"
	.string "to my girlfriend.\p"
	.string "Wait, they're out of stock?$"

CeladonDeptStore4F_Text_Youngster:
	.string "This is the only place where you\n"
	.string "can buy LOVELY MAIL.\p"
	.string "At least it was. They are saying\n"
	.string "they are out of stock.$"

CeladonDeptStore4F_Text_Directory:
	.string "Express Yourself With Gifts!\p"
	.string "4F: WISEMAN GIFTS$"

CeladonDept_EventScript_Lorelei::
	trainerbattle_single TRAINER_LORELEI_HNS, CeladonDept_Text_LoreleiSeen, CeladonDept_Text_LoreleiBeaten
	msgbox CeladonDept_Text_LoreleiAfter, MSGBOX_AUTOCLOSE
	end

CeladonDept_Text_LoreleiSeen:
	.string "LORELEI: Hello there, trainer. I am\nLORELEI.\p"
	.string "I am just buying some essentials.\p"
	.string "And what are you doing here?\p"
	.string "…………\p"
	.string "So you battled the ELITE FOUR?\p"
	.string "I hope you took KAREN down a peg.\p"
	.string "…………You're the new CHAMPION. I'm\nimpressed.\p"
	.string "Fascinating, allow me to test you and\nyour POKéMON.\p"
	.string "Let's battle! I won't hold back!$"

CeladonDept_Text_LoreleiBeaten:
	.string "As expected of the CHAMPION!$"

CeladonDept_Text_LoreleiAfter:
	.string "You're as good as I thought!$"
