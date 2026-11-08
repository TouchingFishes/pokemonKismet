ChallengersCave_1F_hns_MapScripts::
	.byte 0

ChallengersCave_1F_EventScript_Vince::
	trainerbattle_single TRAINER_VINCE_HNS, ChallengersCave_1F_Text_VinceSeen, ChallengersCave_1F_Text_VinceBeaten
	msgbox ChallengersCave_1F_Text_VinceAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_1F_EventScript_Nelson::
	trainerbattle_single TRAINER_NELSON_HNS, ChallengersCave_1F_Text_NelsonSeen, ChallengersCave_1F_Text_NelsonBeaten
	msgbox ChallengersCave_1F_Text_NelsonAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_1F_EventScript_Colby::
	trainerbattle_single TRAINER_COLBY_HNS, ChallengersCave_1F_Text_ColbySeen, ChallengersCave_1F_Text_ColbyBeaten
	msgbox ChallengersCave_1F_Text_ColbyAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_1F_EventScript_Terry::
	trainerbattle_single TRAINER_TERRY_HNS, ChallengersCave_1F_Text_TerrySeen, ChallengersCave_1F_Text_TerryBeaten
	msgbox ChallengersCave_1F_Text_TerryAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_1F_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI_HNS, ChallengersCave_1F_Text_NaomiSeen, ChallengersCave_1F_Text_NaomiBeaten
	msgbox ChallengersCave_1F_Text_NaomiAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_1F_EventScript_Newton::
	trainerbattle_single TRAINER_NEWTON_HNS, ChallengersCave_1F_Text_NewtonSeen, ChallengersCave_1F_Text_NewtonBeaten
	msgbox ChallengersCave_1F_Text_NewtonAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_1F_EventScript_Helena::
	trainerbattle_single TRAINER_HELENA_HNS, ChallengersCave_1F_Text_HelenaSeen, ChallengersCave_1F_Text_HelenaBeaten
	msgbox ChallengersCave_1F_Text_HelenaAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_1F_Text_VinceSeen:
	.string "Strong POKéMON are good! But\n"
	.string "battling you seems even better!$"

ChallengersCave_1F_Text_VinceBeaten:
	.string "I'm stunned, like a PARALYZED\n"
	.string "POKéMON!$"

ChallengersCave_1F_Text_VinceAfter:
	.string "If you see any unusual POKéMON,\n"
	.string "tell me!$"

ChallengersCave_1F_Text_NelsonSeen:
	.string "Heh heh! Can you keep up with my\n"
	.string "battle rhythm?$"

ChallengersCave_1F_Text_NelsonBeaten:
	.string "You broke my focus!$"

ChallengersCave_1F_Text_NelsonAfter:
	.string "I juggle moves and strategies…\n"
	.string "sometimes I drop both!$"

ChallengersCave_1F_Text_ColbySeen:
	.string "I train wherever strong POKéMON\n"
	.string "gather! Let's go!$"

ChallengersCave_1F_Text_ColbyBeaten:
	.string "Your power… It's the real deal!$"

ChallengersCave_1F_Text_ColbyAfter:
	.string "Keep battling like that and\n"
	.string "you'll go far, maybe farther\l"
	.string "than me.$"

ChallengersCave_1F_Text_TerrySeen:
	.string "Down here, every battle is a\n"
	.string "test! Are you ready?$"

ChallengersCave_1F_Text_TerryBeaten:
	.string "I slipped up… That cost me!$"

ChallengersCave_1F_Text_TerryAfter:
	.string "Strong trainers learn quickly.\n"
	.string "I'll improve too!$"

ChallengersCave_1F_Text_NaomiSeen:
	.string "CHALLENGER'S CAVE is where we\n"
	.string "prove our strength!$"

ChallengersCave_1F_Text_NaomiBeaten:
	.string "You're even stronger than I\n"
	.string "expected!$"

ChallengersCave_1F_Text_NaomiAfter:
	.string "I come here to push my limits.\n"
	.string "Next time, I'll win for sure!$"

ChallengersCave_1F_Text_NewtonSeen:
	.string "Do you know this cave well? I've\n"
	.string "mapped it!$"

ChallengersCave_1F_Text_NewtonBeaten:
	.string "My calculations were off!$"

ChallengersCave_1F_Text_NewtonAfter:
	.string "The cave shifts seasonally… I\n"
	.string "need more data!$"

ChallengersCave_1F_Text_HelenaSeen:
	.string "This cave tests patience and\n"
	.string "strength. Show me yours!$"

ChallengersCave_1F_Text_HelenaBeaten:
	.string "You've passed my test.$"

ChallengersCave_1F_Text_HelenaAfter:
	.string "Experience guides me forward.\p"
	.string "Keep training! Your journey\n"
	.string "continues!$"

ChallengersCave_1F_EventScript_ItemPPMax::
	finditem ITEM_PP_MAX
	end

ChallengersCave_1F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE
	end

ChallengersCave_1F_EventScript_ItemHeartScale::
	finditem ITEM_HEART_SCALE
	end

ChallengersCave_1F_EventScript_Gramps::
	lock
	faceplayer
	msgbox ChallengersCave_1F_Text_GrampsWelcome, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox ChallengersCave_1F_Text_GrampsHealed, MSGBOX_DEFAULT
	release
	end

ChallengersCave_1F_EventScript_Slaking::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLAKING, CRY_MODE_NORMAL
	msgbox ChallengersCave_1F_Text_Slaking, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ChallengersCave_1F_Text_GrampsWelcome:
	.string "Well, well! Not many find their\n"
	.string "way to this little hollow.\p"
	.string "To come this far through CHALLENGERS\n"
	.string "CAVE takes real grit.\p"
	.string "You and your POKéMON should be\n"
	.string "proud. Let us patch you up.$"

ChallengersCave_1F_Text_GrampsHealed:
	.string "There, all better!\p"
	.string "SLAKING and I will be right here\n"
	.string "whenever you need a rest.$"

ChallengersCave_1F_Text_Slaking:
	.string "SLAKING: Slaaa…\p"
	.string "It's sprawled out on the floor, but\n"
	.string "it opened one eye to watch you.$"
