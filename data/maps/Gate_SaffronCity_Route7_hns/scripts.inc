Gate_SaffronCity_Route7_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 6, Gate_SaffronCity_Route7_EventScript_GuardFederationOver
	goto_if_ge VAR_FUCHSIA_FEDERATION_STATE, 2, Gate_SaffronCity_Route7_EventScript_GuardFederation
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardFederation::
	msgbox Route7_Text_SaffronGuard_Federation, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardFederationOver::
	msgbox Route7_Text_SaffronGuard_FederationOver, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_Federation:
	.string "Every officer we can spare is out\n"
	.string "at TANGLEBRUSH.\p"
	.string "Whatever they turned up in there,\n"
	.string "it has eaten the whole force.\p"
	.string "And now FUCHSIA is calling for help\n"
	.string "we simply haven't got.$"

Route7_Text_SaffronGuard_FederationOver:
	.string "FUCHSIA's clear, and we didn't do\n"
	.string "it. A trainer did.\p"
	.string "I take my GUARD job seriously.\p"
	.string "Maybe not seriously enough.$"

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "Did you hear about the accident\n"
	.string "at the POWER PLANT?\p"
	.string "It's located in the East, close\n"
	.string "to LAVENDER TOWN.$"

Route7_Text_SaffronGuard_Serious:
	.string "I take my GUARD job seriously.\p"
	.string "Hey! You have a POKéDEX.\p"
	.string "OK. You can go through.$"
