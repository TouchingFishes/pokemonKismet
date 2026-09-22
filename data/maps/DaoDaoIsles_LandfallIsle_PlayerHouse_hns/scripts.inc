DaoDaoIsles_LandfallIsle_PlayerHouse_hns_MapScripts::
	.byte 0

DaoDaoIsles_LandfallIsle_PlayerHouse_EventScript_Phoebe::
	trainerbattle_single TRAINER_ELITE_PHOEBE_HNS, DaoDaoIsles_LandfallIsle_PlayerHouse_Text_PhoebeIntro, DaoDaoIsles_LandfallIsle_PlayerHouse_Text_PhoebeDefeat
	msgbox DaoDaoIsles_LandfallIsle_PlayerHouse_Text_PhoebeAfter, MSGBOX_AUTOCLOSE
	end

DaoDaoIsles_LandfallIsle_PlayerHouse_Text_PhoebeIntro:
.string "Oh! Sorry, sorry! I'll move.\n"
.string "This isn't my house, after all.\p"
.string "The man who lived here left in a\n"
.string "hurry. Seems he left his notes behind.\p"
.string "My grandmother keeps a place like\n"
.string "this, too. Mt. PYRE.\p"
.string "You spend enough time looking after\n"
.string "a place, you start to feel like it's\l"
.string "looking after you.\p"
.string "I came to check on the spirits here.\n"
.string "They've been awfully quiet lately.\p"
.string "But you don't look like you're here\n"
.string "just to look around. Hehe.$"

DaoDaoIsles_LandfallIsle_PlayerHouse_Text_PhoebeDefeat:
.string "Hehe! That woke me right up!$"

DaoDaoIsles_LandfallIsle_PlayerHouse_Text_PhoebeAfter:
.string "If you head out to the ruins, just\n"
.string "be respectful, okay?\p"
.string "The spirits have been here longer\n"
.string "than either of us.$"
