EcruteakCity_CatClub_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_CatClub_MapScript_SetCatOnDuty
	.byte 0

@ One object stands in for both of NATSUMI's older cats: ESPEON at night,
@ UMBREON the rest of the day. Driving it from VAR_OBJ_GFX_ID_B instead of a
@ pair of object hide flags keeps this off the flag budget -- the value is
@ recomputed on every map load anyway, so there is nothing worth storing in a
@ saved bit. Same pattern as the Alola totems (MelemeleIsle_hns/map.json:115).
EcruteakCity_CatClub_MapScript_SetCatOnDuty:
	gettimeofday
	goto_if_eq VAR_0x8000, TIME_NIGHT, EcruteakCity_CatClub_MapScript_NightCat
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SPECIES(UMBREON)
	return

EcruteakCity_CatClub_MapScript_NightCat:
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_SPECIES(ESPEON)
	return

EcruteakCity_CatClub_EventScript_Natsumi::
	goto_if_unset FLAG_IS_CHAMPION, EcruteakCity_CatClub_EventScript_NatsumiNoBattle
	goto_if_set FLAG_BADGE16_GET, EcruteakCity_CatClub_EventScript_NatsumiSixteenBadges
	trainerbattle_single TRAINER_NATSUMI_HNS, EcruteakCity_CatClub_Text_NatsumiIntro, EcruteakCity_CatClub_Text_NatsumiDefeat
	msgbox EcruteakCity_CatClub_Text_NatsumiAfter, MSGBOX_AUTOCLOSE
	end

@ Beating the sixteen-badge team is the ONLY source of the STARLIT SHARD in the
@ game, so the hand-over has to survive a full bag: goto_if_defeated sends a
@ player who won but could not carry it back to the give, and only
@ FLAG_RECEIVED_STARLIT_SHARD closes the branch for good.
EcruteakCity_CatClub_EventScript_NatsumiSixteenBadges::
	goto_if_set FLAG_RECEIVED_STARLIT_SHARD, EcruteakCity_CatClub_EventScript_Natsumi2Done
	goto_if_defeated TRAINER_NATSUMI_2_HNS, EcruteakCity_CatClub_EventScript_Natsumi2ShardAgain
	trainerbattle_single TRAINER_NATSUMI_2_HNS, EcruteakCity_CatClub_Text_Natsumi2Intro, EcruteakCity_CatClub_Text_Natsumi2Defeat
	msgbox EcruteakCity_CatClub_Text_Natsumi2Reward, MSGBOX_DEFAULT
	goto EcruteakCity_CatClub_EventScript_Natsumi2GiveShard

EcruteakCity_CatClub_EventScript_Natsumi2ShardAgain::
	lock
	faceplayer
	msgbox EcruteakCity_CatClub_Text_Natsumi2ShardAgain, MSGBOX_DEFAULT
EcruteakCity_CatClub_EventScript_Natsumi2GiveShard::
	giveitem ITEM_STARLIT_SHARD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_STARLIT_SHARD
	msgbox EcruteakCity_CatClub_Text_Natsumi2ShardLore, MSGBOX_AUTOCLOSE
	end

EcruteakCity_CatClub_EventScript_Natsumi2Done::
	msgbox EcruteakCity_CatClub_Text_Natsumi2After, MSGBOX_NPC
	end

EcruteakCity_CatClub_EventScript_NatsumiNoBattle::
	msgbox EcruteakCity_CatClub_Text_NatsumiNoBattle, MSGBOX_NPC
	end

EcruteakCity_CatClub_EventScript_Skitty::
	lock
	faceplayer
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox EcruteakCity_CatClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	getseenmon SPECIES_SKITTY
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_CatClub_EventScript_CatDone
	setseenmon SPECIES_SKITTY
	bufferspeciesname STR_VAR_1, SPECIES_SKITTY
	msgbox EcruteakCity_CatClub_Text_AddedToPokedex, MSGBOX_DEFAULT
	goto EcruteakCity_CatClub_EventScript_CatDone

EcruteakCity_CatClub_EventScript_Cat::
	lock
	faceplayer
	gettimeofday
	goto_if_eq VAR_0x8000, TIME_NIGHT, EcruteakCity_CatClub_EventScript_Espeon
	playmoncry SPECIES_UMBREON, CRY_MODE_NORMAL
	msgbox EcruteakCity_CatClub_Text_Umbreon, MSGBOX_DEFAULT
	waitmoncry
	getseenmon SPECIES_UMBREON
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_CatClub_EventScript_CatDone
	setseenmon SPECIES_UMBREON
	bufferspeciesname STR_VAR_1, SPECIES_UMBREON
	msgbox EcruteakCity_CatClub_Text_AddedToPokedex, MSGBOX_DEFAULT
	goto EcruteakCity_CatClub_EventScript_CatDone

EcruteakCity_CatClub_EventScript_Espeon::
	playmoncry SPECIES_ESPEON, CRY_MODE_NORMAL
	msgbox EcruteakCity_CatClub_Text_Espeon, MSGBOX_DEFAULT
	waitmoncry
	getseenmon SPECIES_ESPEON
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_CatClub_EventScript_CatDone
	setseenmon SPECIES_ESPEON
	bufferspeciesname STR_VAR_1, SPECIES_ESPEON
	msgbox EcruteakCity_CatClub_Text_AddedToPokedex, MSGBOX_DEFAULT
EcruteakCity_CatClub_EventScript_CatDone::
	closemessage
	release
	end

EcruteakCity_CatClub_EventScript_Notice::
	msgbox EcruteakCity_CatClub_Text_Notice, MSGBOX_SIGN
	end

EcruteakCity_CatClub_Text_NatsumiNoBattle:
	.string "Oh! Mind the tails.\p"
	.string "Welcome to the CAT CLUB. We meet\n"
	.string "here to sit with our cats.\p"
	.string "That is the whole of it. No dues,\n"
	.string "no meetings, no minutes.\p"
	.string "I am NATSUMI. SKITTY here has been\n"
	.string "with me since I was small.\p"
	.string "I gave up battling years ago.\n"
	.string "Nothing left to prove.\p"
	.string "Though if a CHAMPION ever wandered\n"
	.string "in, I might be tempted…$"

EcruteakCity_CatClub_Text_NatsumiIntro:
	.string "Well. The CHAMPION, in my little\n"
	.string "club, on a quiet afternoon.\p"
	.string "I did say I would be tempted.\p"
	.string "Do not let the cushions fool you.\n"
	.string "A cat that is fed is still a cat.$"

EcruteakCity_CatClub_Text_NatsumiDefeat:
	.string "Out-clawed. In my own house!$"

EcruteakCity_CatClub_Text_NatsumiAfter:
	.string "You fight the way a cat lands.\n"
	.string "Nothing wasted.\p"
	.string "Come back when you have every\n"
	.string "badge in both regions.\p"
	.string "There are older cats in this house\n"
	.string "than the ones you have met.$"

EcruteakCity_CatClub_Text_Natsumi2Intro:
	.string "Sixteen badges. Every gym in two\n"
	.string "regions.\p"
	.string "Then I will call down the ones who\n"
	.string "do not come out for guests.\p"
	.string "They have never lost. Be polite\n"
	.string "about it.$"

EcruteakCity_CatClub_Text_Natsumi2Defeat:
	.string "Every last one of them…\p"
	.string "Truly?$"

EcruteakCity_CatClub_Text_Natsumi2Reward:
	.string "…Well.\p"
	.string "Sit down a moment. I have\n"
	.string "something of theirs to give you.\p"
	.string "Years ago the ESPEON kept sitting\n"
	.string "at that window all night long.\p"
	.string "Watching. Waiting on something.\p"
	.string "One morning she carried this in\n"
	.string "and set it by my slippers.$"

EcruteakCity_CatClub_Text_Natsumi2ShardLore:
	.string "They say a POKéMON that carries a\n"
	.string "want big enough will change shape\l"
	.string "around it.\p"
	.string "I never had one that wanted for\n"
	.string "anything. Mine have all they need.\p"
	.string "Perhaps one of yours does.$"

EcruteakCity_CatClub_Text_Natsumi2ShardAgain:
	.string "You walked out without it. Your\n"
	.string "bag was stuffed to the clasp.\p"
	.string "It has been on the mantel ever\n"
	.string "since. Take it properly this time.$"

EcruteakCity_CatClub_Text_Natsumi2After:
	.string "For many years I have kept cats, and\n"
	.string "not one of them had lost before.\p"
	.string "They are sulking. They will get\n"
	.string "over it by supper.\p"
	.string "Stay for tea, {PLAYER}. The cats\n"
	.string "have decided they like you.$"

EcruteakCity_CatClub_Text_Skitty:
	.string "SKITTY is pressed against\n"
	.string "NATSUMI's ankle, one eye open.\p"
	.string "SKITTY: Nyaa!$"

EcruteakCity_CatClub_Text_Umbreon:
	.string "An UMBREON is stretched out along\n"
	.string "the floorboards, taking up rather\l"
	.string "more room than it needs.\p"
	.string "UMBREON: Bui.$"

EcruteakCity_CatClub_Text_Espeon:
	.string "An ESPEON sits bolt upright by the\n"
	.string "window, tail swaying, watching\l"
	.string "something out in the dark.\p"
	.string "ESPEON: Fwee!$"

EcruteakCity_CatClub_Text_AddedToPokedex:
	.string "{STR_VAR_1}'s data was added to\n"
	.string "the POKéDEX.$"

EcruteakCity_CatClub_Text_Notice:
	.string "CAT CLUB HOUSE RULES\p"
	.string "1. The cats decide where they sit.\n"
	.string "2. The cats decide when you leave.\p"
	.string "3. There is no rule three. Take it\n"
	.string "up with the cats.$"
