ChallengersCave_B1F_hns_MapScripts::
	.byte 0

		ChallengersCave_B1F_EventScript_Georgie::
	trainerbattle_single TRAINER_GEORGIE_HNS, ChallengersCave_B1F_Text_GeorgieSeen, ChallengersCave_B1F_Text_GeorgieBeaten
	msgbox ChallengersCave_B1F_Text_GeorgieAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B1F_EventScript_Ivy::
	trainerbattle_single TRAINER_IVY_HNS, ChallengersCave_B1F_Text_IvySeen, ChallengersCave_B1F_Text_IvyBeaten
	msgbox ChallengersCave_B1F_Text_IvyAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B1F_EventScript_Zed::
	trainerbattle_single TRAINER_ZED_HNS, ChallengersCave_B1F_Text_ZedSeen, ChallengersCave_B1F_Text_ZedBeaten
	msgbox ChallengersCave_B1F_Text_ZedAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B1F_EventScript_Esme::
	trainerbattle_single TRAINER_ESME_HNS, ChallengersCave_B1F_Text_EsmeSeen, ChallengersCave_B1F_Text_EsmeBeaten
	msgbox ChallengersCave_B1F_Text_EsmeAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B1F_EventScript_Desmond::
	trainerbattle_single TRAINER_DESMOND_HNS, ChallengersCave_B1F_Text_DesmondSeen, ChallengersCave_B1F_Text_DesmondBeaten
	msgbox ChallengersCave_B1F_Text_DesmondAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B1F_EventScript_Minty::
	trainerbattle_single TRAINER_MINTY_HNS, ChallengersCave_B1F_Text_MintySeen, ChallengersCave_B1F_Text_MintyBeaten
	msgbox ChallengersCave_B1F_Text_MintyAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B1F_EventScript_Shaun::
	trainerbattle_single TRAINER_SHAUN_HNS, ChallengersCave_B1F_Text_ShaunSeen, ChallengersCave_B1F_Text_ShaunBeaten
	msgbox ChallengersCave_B1F_Text_ShaunAfter, MSGBOX_AUTOCLOSE
	end

ChallengersCave_B1F_Text_GeorgieSeen:
	.string "Hey… can you feel that?\p"
	.string "This cave gets quiet in a way I\n"
	.string "don't like.\p"
	.string "Still, I'm not turning back.\p"
	.string "If something's waiting down\n"
	.string "here, I'll face it.$"

ChallengersCave_B1F_Text_GeorgieBeaten:
	.string "Hah… guess I should've listened\n"
	.string "to that feeling.$"

ChallengersCave_B1F_Text_GeorgieAfter:
	.string "Down here, it feels like things\n"
	.string "watch you.\p"
	.string "But fear only wins if you run.\p"
	.string "You're not scared, are you?$"

ChallengersCave_B1F_Text_IvySeen:
	.string "I didn't come all\n"
	.string "this way for looks.\p"
	.string "This cave tests\n"
	.string "more than style.$"

ChallengersCave_B1F_Text_IvyBeaten:
	.string "So… you noticed.$"

ChallengersCave_B1F_Text_IvyAfter:
	.string "True beauty holds up under\n"
	.string "pressure.\p"
	.string "You passed.$"

ChallengersCave_B1F_Text_ZedSeen:
	.string "You've come far.\p"
	.string "This is where most challengers\n"
	.string "lose their nerve.\p"
	.string "Dragons don't.\p"
	.string "If you wish to go on, prove you\n"
	.string "can stand your ground.$"

ChallengersCave_B1F_Text_ZedBeaten:
	.string "…Impressive.\p"
	.string "Your spirit does not waver.$"

ChallengersCave_B1F_Text_ZedAfter:
	.string "Beyond me waits the final trial.\p"
	.string "Dragons respect those who\n"
	.string "endure.\p"
	.string "Go.$"

ChallengersCave_B1F_Text_EsmeSeen:
	.string "…You're not alone in this cave.\p"
	.string "So many echoes. Battles long\n"
	.string "finished…$"

ChallengersCave_B1F_Text_EsmeBeaten:
	.string "The voices… they grow quiet.$"

ChallengersCave_B1F_Text_EsmeAfter:
	.string "One presence remains ahead.\p"
	.string "It burns brighter than the rest.$"

ChallengersCave_B1F_Text_DesmondSeen:
	.string "This cave weeds out hesitation.\p"
	.string "Only trainers who trust their\n"
	.string "teams make it this far.\p"
	.string "Show me yours.$"

ChallengersCave_B1F_Text_DesmondBeaten:
	.string "No doubts. That was clean.$"

ChallengersCave_B1F_Text_DesmondAfter:
	.string "You didn't flinch.\p"
	.string "That's what it\n"
	.string "takes from here on.$"

ChallengersCave_B1F_Text_MintySeen:
	.string "Every step in here filters\n"
	.string "trainers out.\p"
	.string "I collect the ones who make it\n"
	.string "this far.$"

ChallengersCave_B1F_Text_MintyBeaten:
	.string "Heh, another rare loss for me.$"

ChallengersCave_B1F_Text_MintyAfter:
	.string "Strong battles are\n"
	.string "the best keepsakes.\p"
	.string "Yours is one I'll\n"
	.string "remember.$"

ChallengersCave_B1F_Text_ShaunSeen:
	.string "So.\p"
	.string "You made it.\p"
	.string "Every battle here was meant to\n"
	.string "wear you down.\p"
	.string "I'm the one who waits for\n"
	.string "whoever endures.\p"
	.string "Let's see if your strength still\n"
	.string "remains.$"

ChallengersCave_B1F_Text_ShaunBeaten:
	.string "…It does.\p"
	.string "You never broke.$"

ChallengersCave_B1F_Text_ShaunAfter:
	.string "This cave wasn't about victory.\p"
	.string "It was about resolve.\p"
	.string "Remember this feeling.\p"
	.string "You've earned what comes next.$"
