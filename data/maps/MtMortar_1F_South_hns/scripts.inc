MtMortar_1F_South_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_South_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_South_OnTransition: 
	callnative SetTimeBasedEncounters
	end



MtMortar_1F_South_EventScript_Item_Aerial_Ace::
    finditem ITEM_TM_AERIAL_ACE
    end

MtMortar_1F_South_EventScript_Item_Elixir::
    finditem ITEM_ELIXIR
    end

MtMortar_1F_South_EventScript_Ben::
	trainerbattle_single TRAINER_BEN_HNS, MtMortar_1F_South_Text_PokemaniacBenSeen, MtMortar_1F_South_Text_PokemaniacBenBeaten
	msgbox MtMortar_1F_South_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_South_Text_PokemaniacBenSeen:
	.string "I love POKéMON!\p"
	.string "That's why I started--and why I'll\n"
	.string "keep on collecting POKéMON!$"

MtMortar_1F_South_Text_PokemaniacBenBeaten:
	.string "How could you do this to me?$"

MtMortar_1F_South_Text_PokemaniacBenAfter:
	.string "What else do I like besides\n"
	.string "POKéMON?\p"
	.string "MARY on the radio. I bet she's\n"
	.string "cute!$"
