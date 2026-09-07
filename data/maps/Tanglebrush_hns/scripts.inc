Tanglebrush_hns_MapScripts::
	.byte 0

Tanglebrush_EventScript_CoupleF::
	trainerbattle_double TRAINER_DEVON_AND_MAY_HNS, Tanglebrush_Text_CoupleFIntro, Tanglebrush_Text_CoupleFDefeat, Tanglebrush_Text_CoupleFNotEnough
	msgbox Tanglebrush_Text_CoupleFAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_CoupleM::
	trainerbattle_double TRAINER_DEVON_AND_MAY_HNS, Tanglebrush_Text_CoupleMIntro, Tanglebrush_Text_CoupleMDefeat, Tanglebrush_Text_CoupleMNotEnough
	msgbox Tanglebrush_Text_CoupleMAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Silas::
	trainerbattle_single TRAINER_SILAS_HNS, Tanglebrush_Text_SilasIntro, Tanglebrush_Text_SilasDefeat
	msgbox Tanglebrush_Text_SilasAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET_HNS, Tanglebrush_Text_GarretIntro, Tanglebrush_Text_GarretDefeat
	msgbox Tanglebrush_Text_GarretAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Orrin::
	trainerbattle_single TRAINER_ORRIN_HNS, Tanglebrush_Text_OrrinIntro, Tanglebrush_Text_OrrinDefeat
	msgbox Tanglebrush_Text_OrrinAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Kester::
	trainerbattle_single TRAINER_KESTER_HNS, Tanglebrush_Text_KesterIntro, Tanglebrush_Text_KesterDefeat
	msgbox Tanglebrush_Text_KesterAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Nash::
	trainerbattle_single TRAINER_NASH_HNS, Tanglebrush_Text_NashIntro, Tanglebrush_Text_NashDefeat
	msgbox Tanglebrush_Text_NashAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Cordelia::
	trainerbattle_single TRAINER_CORDELIA_HNS, Tanglebrush_Text_CordeliaIntro, Tanglebrush_Text_CordeliaDefeat
	msgbox Tanglebrush_Text_CordeliaAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Dalia::
	trainerbattle_single TRAINER_DALIA_HNS, Tanglebrush_Text_DaliaIntro, Tanglebrush_Text_DaliaDefeat
	msgbox Tanglebrush_Text_DaliaAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Joana::
	trainerbattle_single TRAINER_JOANA_HNS, Tanglebrush_Text_JoanaIntro, Tanglebrush_Text_JoanaDefeat
	msgbox Tanglebrush_Text_JoanaAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Barnaby::
	trainerbattle_single TRAINER_BARNABY_HNS, Tanglebrush_Text_BarnabyIntro, Tanglebrush_Text_BarnabyDefeat
	msgbox Tanglebrush_Text_BarnabyAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Marcy::
	trainerbattle_single TRAINER_MARCY_HNS, Tanglebrush_Text_MarcyIntro, Tanglebrush_Text_MarcyDefeat
	msgbox Tanglebrush_Text_MarcyAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_EventScript_Layton::
	trainerbattle_single TRAINER_LAYTON_HNS, Tanglebrush_Text_LaytonIntro, Tanglebrush_Text_LaytonDefeat
	msgbox Tanglebrush_Text_LaytonAfter, MSGBOX_AUTOCLOSE
	end

Tanglebrush_Text_CoupleFIntro:
	.string "We raise our POKéMON together!$"

Tanglebrush_Text_CoupleFDefeat:
	.string "Together we still have much to learn.$"

Tanglebrush_Text_CoupleFNotEnough:
	.string "There's no room for a third here!$"

Tanglebrush_Text_CoupleFAfter:
	.string "Two hearts, one team. That's us.$"

Tanglebrush_Text_CoupleMIntro:
	.string "My partner and I never battle apart!$"

Tanglebrush_Text_CoupleMDefeat:
	.string "We should train harder, love.$"

Tanglebrush_Text_CoupleMNotEnough:
	.string "You need more POKéMON than that!$"

Tanglebrush_Text_CoupleMAfter:
	.string "We'll be back, and stronger.$"

Tanglebrush_Text_SilasIntro:
	.string "I patrol this wood. Nothing gets\npoached on my watch.$"

Tanglebrush_Text_SilasDefeat:
	.string "You clearly respect this place.$"

Tanglebrush_Text_SilasAfter:
	.string "Tread lightly and the forest will\ntreat you kindly.$"

Tanglebrush_Text_GarretIntro:
	.string "I've raised every WORMADAM cloak\nthere is. Look at them!$"

Tanglebrush_Text_GarretDefeat:
	.string "Each one is beautiful, isn't it?$"

Tanglebrush_Text_GarretAfter:
	.string "A WORMADAM's cloak depends on where\nit evolved. Fascinating, isn't it?$"

Tanglebrush_Text_OrrinIntro:
	.string "The BUG POKéMON here are only\nactive at this hour.$"

Tanglebrush_Text_OrrinDefeat:
	.string "Amazing! You knew their habits!$"

Tanglebrush_Text_OrrinAfter:
	.string "Come back at dusk. You'll meet\nsomething quite different.$"

Tanglebrush_Text_KesterIntro:
	.string "You got this deep? Then you can\nhandle my best.$"

Tanglebrush_Text_KesterDefeat:
	.string "Incredible… my strongest, beaten.$"

Tanglebrush_Text_KesterAfter:
	.string "You've earned the right to walk\nthis wood.$"

Tanglebrush_Text_NashIntro:
	.string "My POKéMON don't need to evolve\nto be strong!$"

Tanglebrush_Text_NashDefeat:
	.string "Perhaps they need a little longer…$"

Tanglebrush_Text_NashAfter:
	.string "I'll raise them my own way, thanks.$"

Tanglebrush_Text_CordeliaIntro:
	.string "I'm raising every one of them\nfrom an egg!$"

Tanglebrush_Text_CordeliaDefeat:
	.string "Oh dear, they're still so young.$"

Tanglebrush_Text_CordeliaAfter:
	.string "They'll grow up big one day.\nYou'll see!$"

Tanglebrush_Text_DaliaIntro:
	.string "Can you smell it? The whole wood\nis in bloom.$"

Tanglebrush_Text_DaliaDefeat:
	.string "My scent didn't slow you at all!$"

Tanglebrush_Text_DaliaAfter:
	.string "My BUTTERFREE gathers pollen from\nevery flower here.$"

Tanglebrush_Text_JoanaIntro:
	.string "I've got lost in here twice already!$"

Tanglebrush_Text_JoanaDefeat:
	.string "And now I've lost a battle too…$"

Tanglebrush_Text_JoanaAfter:
	.string "If you find the way out, come back\nand tell me!$"

Tanglebrush_Text_BarnabyIntro:
	.string "Camping in TANGLEBRUSH is a rite\nof passage!$"

Tanglebrush_Text_BarnabyDefeat:
	.string "You're tougher than the bugs here.$"

Tanglebrush_Text_BarnabyAfter:
	.string "Watch the grass after dark.\nThings move in it.$"

Tanglebrush_Text_MarcyIntro:
	.string "My TANGELA won't let go of me!$"

Tanglebrush_Text_MarcyDefeat:
	.string "Even holding on, we lost…$"

Tanglebrush_Text_MarcyAfter:
	.string "Their vines are softer than they\nlook, you know.$"

Tanglebrush_Text_LaytonIntro:
	.string "There are ruins under these roots.\nI'm certain of it!$"

Tanglebrush_Text_LaytonDefeat:
	.string "Bah! You battle better than I dig.$"

Tanglebrush_Text_LaytonAfter:
	.string "That SUDOWOODO was standing on\nsomething. I know it!$"

