ChillwindCave_hns_MapScripts::
	.byte 0

ChillwindCave_EventScript_SkullFossil::
	finditem ITEM_SKULL_FOSSIL
	end

ChillwindCave_EventScript_ArmorFossil::
	finditem ITEM_ARMOR_FOSSIL
	end

ChillwindCave_EventScript_ItemDuskStone::
	finditem ITEM_DUSK_STONE
	end

ChillwindCave_EventScript_ItemMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

ChillwindCave_EventScript_Baxcalibur::
	lock
	faceplayer
	playmoncry SPECIES_BAXCALIBUR, CRY_MODE_ENCOUNTER
	msgbox ChillwindCave_Text_BaxcaliburCry, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setwildbattle SPECIES_BAXCALIBUR, 70
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ChillwindCave_EventScript_BaxcaliburStays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ChillwindCave_EventScript_BaxcaliburStays
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CHILLWIND_BAXCALIBUR
	setflag FLAG_HIDE_CHILLWIND_BAXCALIBUR
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

ChillwindCave_EventScript_BaxcaliburStays::
	release
	end

ChillwindCave_Text_BaxcaliburCry:
	.string "Frost creeps across the floor as\n"
	.string "the great dragon rises!$"
