IcePath_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

IcePath_1F_EventScript_Item_PpUp::
	finditem ITEM_PP_UP
	end
IcePath_1F_EventScript_Item_Protein::
	finditem ITEM_PROTEIN
	end

IcePath_1F_EventScript_Item_TM_Hex::
	finditem ITEM_TM_HEX
	end

IcePath_1F_EventScript_Alder::
	lock
	playbgm MUS_ENCOUNTER_HIKER, FALSE
	goto_if_eq VAR_FACING, DIR_SOUTH, IcePath_1F_EventScript_AlderPushPrompt
	msgbox IcePath_1F_Text_Stuck1, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

IcePath_1F_Trigger_Alder::
	lock
	msgbox IcePath_1F_Text_NoAnswer, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

IcePath_1F_EventScript_AlderPushPrompt::
	msgbox IcePath_1F_Text_Stuck2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_AlderRefused
IcePath_1F_EventScript_AlderPush::
	msgbox IcePath_1F_Text_Shove, MSGBOX_AUTOCLOSE
	closemessage
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_Movement_PlayerJump
	waitmovement 0
	waitse
	playse SE_M_ICY_WIND
	applymovement LOCALID_ICEPATH1_ALDER, IcePath_Movement_AlderSlide
	waitmovement 0
	msgbox IcePath_1F_Text_Free, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ICEPATH1_ALDER, Common_Movement_FaceDown
	waitmovement 0
	delay 24
	msgbox IcePath_1F_Text_WaterfallGift, MSGBOX_DEFAULT
	giveitem ITEM_HM_WATERFALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox IcePath_1F_Text_WaterfallAfter, MSGBOX_DEFAULT
	closemessage
	delay 24
	msgbox IcePath_1F_Text_GirlBackHome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ICEPATH1_ALDER, IcePath_Movement_AlderLeave
	waitmovement LOCALID_ICEPATH1_ALDER
	setflag FLAG_HIDE_ICE_PATH_ALDER
	removeobject LOCALID_ICEPATH1_ALDER
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_ICE_PATH_STATE, 1
	release
	end

IcePath_1F_EventScript_AlderRefused::
	msgbox IcePath_1F_Text_Refused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IcePath_1F_EventScript_AlderPush
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_AlderRefused

IcePath_Movement_PlayerJump:
	jump_in_place_down
	step_end

IcePath_Movement_AlderSlide:
	slide_down
	slide_down
	slide_down
	slide_down
	walk_in_place_fast_down
	face_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

IcePath_Movement_AlderLeave:
	walk_down
	walk_down
	walk_down
	step_end

IcePath_1F_Text_NoAnswer:
	.string "ALDER: .....................$"

IcePath_1F_Text_Stuck1:
	.string "Well now! The very person.\p"
	.string "Don't laugh.\p"
	.string "I stopped to admire the ice.\n"
	.string "The ice has decided to keep me.\p"
	.string "I go barefoot, youngster. Always\n"
	.string "have. It has cost me nothing at\l"
	.string "all, until about ten minutes ago.\p"
	.string "Come round behind me and put your\n"
	.string "shoulder into my back.$"

IcePath_1F_Text_Stuck2:
	.string "Well now! The very person.\p"
	.string "Don't laugh.\p"
	.string "I stopped to admire the ice.\n"
	.string "The ice has decided to keep me.\p"
	.string "I go barefoot, youngster. Always\n"
	.string "have. It has cost me nothing at\l"
	.string "all, until about ten minutes ago.\p"
	.string "Now then. Could you put your\n"
	.string "shoulder into an old man's back?$"

IcePath_1F_Text_Shove:
	.string "....SHOVE!....$"

IcePath_1F_Text_Refused:
	.string "Hahaha! I'd have refused me too.\p"
	.string "But I cannot feel my toes, and\n"
	.string "pride is a poor blanket.\p"
	.string "Will you push?$"

IcePath_1F_Text_Free:
	.string "Hahaha! Free!\p"
	.string "And my dignity only lightly\n"
	.string "damaged. My thanks, youngster.\p"
	.string "I'm heading for BLACKTHORN, and\n"
	.string "then ROUTE 45. They say it's\l"
	.string "quite the climb. Wish me luck.\p"
	.string "And there is a shrine out that\n"
	.string "way. Dragons in the water,\l"
	.string "dragons cut into the stone.\p"
	.string "I'll sit with them a while. At my\n"
	.string "age that passes for climbing.$"

IcePath_1F_Text_WaterfallGift:
	.string "Now. A man shouldn't take a shove\n"
	.string "for nothing.\p"
	.string "I've carried this since before you\n"
	.string "were born and used it twice.\p"
	.string "Here. WATERFALL.$"

IcePath_1F_Text_WaterfallAfter:
	.string "Up, mind. Not along, not across.\n"
	.string "Up.\p"
	.string "Everyone wants to go round a thing\n"
	.string "like that. The whole trick is\l"
	.string "deciding the water is a road.\p"
	.string "You'll want a strong one to carry\n"
	.string "you. Don't ask a little fellow to\l"
	.string "do it out of politeness.$"

IcePath_1F_Text_GirlBackHome:
	.string "There's a girl back home who would\n"
	.string "bite my hand off for a look at\l"
	.string "that shrine.\p"
	.string "Wild thing. Won't come down out\n"
	.string "of the trees long enough to be\l"
	.string "told anything.\p"
	.string "She'll get here one day.\n"
	.string "They always do.$"
