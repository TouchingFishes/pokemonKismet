NewSinjoh_House1_hns_MapScripts::
	.byte 0


NewSinjoh__House1_EventScripts_Elizabeth::
    lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVERIOLU, NewSinjoh_House1_EventScript_Elizabeth_AfterGift
    msgbox NewSinjoh_House1_Text_Looking4Celebi MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_House1_EventScript_Decline
    checkspecies SPECIES_CELEBI
    goto_if_eq VAR_RESULT, TRUE, NewSinjoh_House1_EventScript_GiveRiolu
	msgbox NewSinjoh_House1_Text_NicePokemonButNotCelebi, MSGBOX_DEFAULT
    release
    end

NewSinjoh_House1_EventScript_Decline::
	msgbox NewSinjoh_House1_Text_Decline, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_House1_EventScript_GiveRiolu::
	playse SE_PIN
    applymovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_NEWSINJOH_HOUSE1_ELIZABETH
    msgbox NewSinjoh_House1_OffersRiolu MSGBOX_DEFAULT
    setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RIOLU
    bufferspeciesname STR_VAR_1, SPECIES_RIOLU
    givemon SPECIES_RIOLU, 5
	call Common_EventScript_GiftMon
	setflag FLAG_NEWSINJOH_HOUSE1_ELIZABETH_GAVERIOLU
	closemessage
    release
    end

NewSinjoh_House1_Text_Looking4Celebi:
    .string "Hey there, Trainer!\p"
	.string "You came all the way from\n"
	.string "NEW BARK TOWN?\p"
	.string "I have a request for someone as\n"
	.string "well traveled as you are.\l"
	.string "You see, my favorite POKéMON in the\l"
	.string "whole world just so happens to be\l"
	.string "the mythical POKéMON known as CELEBI.\p"
	.string "If you happen to have one, would\n"
	.string "you mind showing it to me?$"

NewSinjoh_House1_Text_NicePokemonButNotCelebi:
    .string "That's a very wonderful POKéMON\n"
	.string "you have there but that's\l"
	.string "not exactly what I was looking for..$"

NewSinjoh_House1_OffersRiolu:
    .string "That's it! That's a real living CELEBI!!\p"
	.string "Thank you show much for bringing it\n"
	.string "all the way up north for me to see.\p"
    .string "Here, my girlfriend happened to\n"
	.string "catch a few too many of these during\l"
	.string "her trip to a far away region..\p"
    .string "Please take this special RIOLU as\n"
	.string "thanks, {PLAYER}.$"

NewSinjoh_House1_Text_Decline:
	.string "That's too bad. I really wanted\n"
	.string "to see one.$"

NewSinjoh_House1_Text_TakeCareOfRiolu:
    .string "Take good care of that RIOLU\n"
	.string "for me okay?$"

NewSinjoh_House1_EventScript_Elizabeth_AfterGift::
	msgbox NewSinjoh_House1_Text_GoodToSeeYouAgain MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Text_GoodToSeeYouAgain:
    .string "It's good to see you again,\n"
	.string "{PLAYER}.\p"
	.string "How have you been treating that\n"
	.string "that RIOLU?$"

NewSinjoh_House1_Bookshelf::
    lock
	msgbox NewSinjoh_House1_Bookshelf_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House1_Bookshelf_Text:
    .string "It's a shelf packed full of\n"
	.string "computer games and graphic novels!$"

NewSinjoh_House1_Eevee::
    lock
	faceplayer
	playmoncry SPECIES_EEVEE, 0
	msgbox NewSinjoh_House1_Text_Eevee_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_House1_Text_Eevee_Cry:
    .string "Vee Vee?$"
