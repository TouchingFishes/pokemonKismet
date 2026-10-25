SSAqua_RoomNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Landon::
	trainerbattle_single TRAINER_LANDON_HNS, SSAqua_RoomNE_Text_HikerLandonSeen, SSAqua_RoomNE_Text_HikerLandonBeaten
	msgbox SSAqua_RoomNE_Text_HikerLandonAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_HNS, SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerLandonSeen:
    .string "Are you alone?\n"
    .string "Then let's battle!$"

SSAqua_RoomNE_Text_HikerLandonBeaten:
    .string "That's too much to handle!$"

SSAqua_RoomNE_Text_HikerLandonAfterBattle:
    .string "I wonder if there are any\n"
    .string "mountains worth climbing in KANTO?$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "Do you know LILY?\n"
    .string "She's a hot DJ in KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "Gyaaaah!$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "LILY's nice, but\n"
    .string "MARY's the best!\l"
    .string "I want to check\l"
    .string "out JOHTO's radio\l"
    .string "programs!$"
