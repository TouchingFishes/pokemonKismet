Route7_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "What's this flyer?\p"
	.string "… Uncouth trainers have been\n"
	.string "holding battles in the\l"
	.string "UNDERGROUND PATH.\p"
	.string "Because of rising complaints by\n"
	.string "local residents, the UNDERGROUND\l"
	.string "PATH has been sealed indefinitely.\p"
	.string "CELADON POLICE$"

Route7_Text_LockedDoor:
	.string "It's locked…$"

@ ===[ TRAINERS MOVED OFF TANGLEBRUSH ]======================================
@ DEVON AND MAY, DALIA and BARNABY were on TANGLEBRUSH; the hedge maze here
@ wanted guarding and TANGLEBRUSH still has nine.
@
@ The COUPLE is one trainer with two objects, both calling trainerbattle_double
@ on the same ID - whichever spots the player opens the fight. They stand on the
@ 2-wide corridor the maze empties into, so the player cannot slip past.
@
@ ⚠️ BARNABY was a CAMPER. He is a RICH BOY now, so both his lines are rewritten
@ rather than ported - the originals named TANGLEBRUSH and its bugs.
@ ⚠️ DALIA's intro said "the whole wood is in bloom", which was TANGLEBRUSH. One
@ noun changed for the hedges here; the rest of her dialogue is untouched.
Route7_EventScript_CoupleF::
	trainerbattle_double TRAINER_DEVON_AND_MAY_HNS, Route7_Text_CoupleFIntro, Route7_Text_CoupleFDefeat, Route7_Text_CoupleFNotEnough
	msgbox Route7_Text_CoupleFAfter, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_CoupleM::
	trainerbattle_double TRAINER_DEVON_AND_MAY_HNS, Route7_Text_CoupleMIntro, Route7_Text_CoupleMDefeat, Route7_Text_CoupleMNotEnough
	msgbox Route7_Text_CoupleMAfter, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Dalia::
	trainerbattle_single TRAINER_DALIA_HNS, Route7_Text_DaliaIntro, Route7_Text_DaliaDefeat
	msgbox Route7_Text_DaliaAfter, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Barnaby::
	trainerbattle_single TRAINER_BARNABY_HNS, Route7_Text_BarnabyIntro, Route7_Text_BarnabyDefeat
	msgbox Route7_Text_BarnabyAfter, MSGBOX_AUTOCLOSE
	end

Route7_Text_CoupleFIntro:
	.string "We raise our POKéMON together!$"

Route7_Text_CoupleFDefeat:
	.string "Together we still have much to learn.$"

Route7_Text_CoupleFNotEnough:
	.string "There's no room for a third here!$"

Route7_Text_CoupleFAfter:
	.string "Two hearts, one team. That's us.$"

Route7_Text_CoupleMIntro:
	.string "My partner and I never battle apart!$"

Route7_Text_CoupleMDefeat:
	.string "We should train harder, love.$"

Route7_Text_CoupleMNotEnough:
	.string "You need more POKéMON than that!$"

Route7_Text_CoupleMAfter:
	.string "We'll be back, and stronger.$"

Route7_Text_DaliaIntro:
	.string "Can you smell it? The whole hedge\n"
	.string "is in bloom.$"

Route7_Text_DaliaDefeat:
	.string "My scent didn't slow you at all!$"

Route7_Text_DaliaAfter:
	.string "My BUTTERFREE gathers pollen from\n"
	.string "every flower here.$"

Route7_Text_BarnabyIntro:
	.string "Father had this maze planted for\n"
	.string "me. Do you like it?\p"
	.string "Nobody finds the middle without\n"
	.string "being told the way.$"

Route7_Text_BarnabyDefeat:
	.string "But I was told the way!$"

Route7_Text_BarnabyAfter:
	.string "Money buys a great many things.\p"
	.string "Apparently not this.$"

