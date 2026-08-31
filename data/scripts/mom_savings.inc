@ Mom's gift calls.
@
@ The Item and Rare calls name what she bought, which means every sentence has
@ to survive any item in her tables. BufferMomGiftItemName puts the name in
@ STR_VAR_1 and the correct article in STR_VAR_2 - "a", "an", or "some" for mass
@ nouns like LEFTOVERS.
@ Every naming variant MUST read "{STR_VAR_2} {STR_VAR_1}". Never hard-code an
@ article ("a {STR_VAR_1}" breaks on ANTIDOTE and LEFTOVERS) and never pluralise
@ the name - the item data carries no plural form. A variant that wants to avoid
@ the article entirely must also avoid implying a count.
@ The Berry call deliberately does NOT name the item: berries arrive five at a
@ time, and neither "some PECHA BERRY" nor "5 PECHA BERRYS" can be made to read
@ well without a plural form.

EventScript_MomGiftCall_Item::
	lockall
	special BufferMomGiftItemName
	random 10
	switch VAR_RESULT
	case 0, EventScript_MomGiftCall_Item_0
	case 1, EventScript_MomGiftCall_Item_1
	case 2, EventScript_MomGiftCall_Item_2
	case 3, EventScript_MomGiftCall_Item_3
	case 4, EventScript_MomGiftCall_Item_4
	case 5, EventScript_MomGiftCall_Item_5
	case 6, EventScript_MomGiftCall_Item_6
	case 7, EventScript_MomGiftCall_Item_7
	case 8, EventScript_MomGiftCall_Item_8
	case 9, EventScript_MomGiftCall_Item_9
	goto EventScript_MomGiftCall_Item_0
	end

EventScript_MomGiftCall_Item_0::
	pokenavcall Mom_Text_GiftCall_Item0
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_1::
	pokenavcall Mom_Text_GiftCall_Item1
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_2::
	pokenavcall Mom_Text_GiftCall_Item2
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_3::
	pokenavcall Mom_Text_GiftCall_Item3
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_4::
	pokenavcall Mom_Text_GiftCall_Item4
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_5::
	pokenavcall Mom_Text_GiftCall_Item5
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_6::
	pokenavcall Mom_Text_GiftCall_Item6
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_7::
	pokenavcall Mom_Text_GiftCall_Item7
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_8::
	pokenavcall Mom_Text_GiftCall_Item8
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Item_9::
	pokenavcall Mom_Text_GiftCall_Item9
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Rare::
	lockall
	special BufferMomGiftItemName
	random 4
	switch VAR_RESULT
	case 0, EventScript_MomGiftCall_Rare_0
	case 1, EventScript_MomGiftCall_Rare_1
	case 2, EventScript_MomGiftCall_Rare_2
	case 3, EventScript_MomGiftCall_Rare_3
	goto EventScript_MomGiftCall_Rare_0
	end

EventScript_MomGiftCall_Rare_0::
	pokenavcall Mom_Text_GiftCall_Rare0
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Rare_1::
	pokenavcall Mom_Text_GiftCall_Rare1
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Rare_2::
	pokenavcall Mom_Text_GiftCall_Rare2
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Rare_3::
	pokenavcall Mom_Text_GiftCall_Rare3
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Berry::
	lockall
	random 4
	switch VAR_RESULT
	case 0, EventScript_MomGiftCall_Berry_0
	case 1, EventScript_MomGiftCall_Berry_1
	case 2, EventScript_MomGiftCall_Berry_2
	case 3, EventScript_MomGiftCall_Berry_3
	goto EventScript_MomGiftCall_Berry_0
	end

EventScript_MomGiftCall_Berry_0::
	pokenavcall Mom_Text_GiftCall_Berry0
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Berry_1::
	pokenavcall Mom_Text_GiftCall_Berry1
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Berry_2::
	pokenavcall Mom_Text_GiftCall_Berry2
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Berry_3::
	pokenavcall Mom_Text_GiftCall_Berry3
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Decoration::
	lockall
	pokenavcall Mom_Text_GiftCall_Decoration
	goto EventScript_MomGiftCall_Finish
	end

EventScript_MomGiftCall_Finish::
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end


Mom_Text_GiftCall_Item0:
	.string "MOM: Hi, sweetie!\p"
	.string "I put your savings to good use\n"
	.string "and picked up {STR_VAR_2} {STR_VAR_1}.\p"
	.string "It's waiting in your PC.\n"
	.string "Take care!$"

Mom_Text_GiftCall_Item1:
	.string "MOM: Hello, dear!\p"
	.string "They had {STR_VAR_2} {STR_VAR_1} on sale,\n"
	.string "so I simply had to.\p"
	.string "I sent it to your PC.\n"
	.string "Don't push yourself too hard!$"

Mom_Text_GiftCall_Item2:
	.string "MOM: It's me!\p"
	.string "I was out shopping and thought\n"
	.string "of you, so I got {STR_VAR_2} {STR_VAR_1}.\p"
	.string "It's in your PC now.\n"
	.string "Take care!$"

Mom_Text_GiftCall_Item3:
	.string "MOM: Hi, sweetie!\p"
	.string "You'd been saving so nicely that\n"
	.string "I treated you to {STR_VAR_2} {STR_VAR_1}.\p"
	.string "Check your PC when you get\n"
	.string "the chance!$"

Mom_Text_GiftCall_Item4:
	.string "MOM: Hello!\p"
	.string "{STR_VAR_2} {STR_VAR_1} caught my eye\n"
	.string "at the shop today.\p"
	.string "I sent it along to your PC.\n"
	.string "Do eat properly, won't you?$"

Mom_Text_GiftCall_Item5:
	.string "MOM: Hi, honey!\p"
	.string "The shopkeeper recommended\n"
	.string "{STR_VAR_2} {STR_VAR_1}, so I trusted him.\p"
	.string "It's in your PC.\n"
	.string "I hope it's useful!$"

Mom_Text_GiftCall_Item6:
	.string "MOM: Hello, dear!\p"
	.string "I nearly walked right past\n"
	.string "{STR_VAR_2} {STR_VAR_1} today!\p"
	.string "Well, it's yours now.\n"
	.string "It's in your PC.$"

Mom_Text_GiftCall_Item7:
	.string "MOM: It's your mother!\p"
	.string "A traveller like you can always\n"
	.string "use {STR_VAR_2} {STR_VAR_1}.\p"
	.string "So I bought one.\n"
	.string "It's in your PC. Take care!$"

Mom_Text_GiftCall_Item8:
	.string "MOM: Hi, sweetie!\p"
	.string "Your savings stretched to\n"
	.string "{STR_VAR_2} {STR_VAR_1} this week.\p"
	.string "I've sent it to your PC.\n"
	.string "Don't stay out too late!$"

Mom_Text_GiftCall_Item9:
	.string "MOM: Hello!\p"
	.string "I had a little left over, so\n"
	.string "I got you {STR_VAR_2} {STR_VAR_1}.\p"
	.string "It's in your PC.\n"
	.string "Call me sometime, won't you?$"

Mom_Text_GiftCall_Rare0:
	.string "MOM: Sweetie, you won't believe\n"
	.string "what I found today!\p"
	.string "{STR_VAR_2} {STR_VAR_1}, and hardly\n"
	.string "anything for it!\p"
	.string "It's in your PC. Aren't I lucky?$"

Mom_Text_GiftCall_Rare1:
	.string "MOM: Hello, dear!\p"
	.string "There was {STR_VAR_2} {STR_VAR_1} sitting\n"
	.string "in the corner of the shop.\p"
	.string "Nobody had even noticed it!\n"
	.string "I sent it to your PC.$"

Mom_Text_GiftCall_Rare2:
	.string "MOM: It's me!\p"
	.string "Now, don't be cross, but I spent\n"
	.string "rather a lot today.\p"
	.string "{STR_VAR_2} {STR_VAR_1} was too good\n"
	.string "to leave behind! It's in your PC.$"

Mom_Text_GiftCall_Rare3:
	.string "MOM: Hi, honey!\p"
	.string "Your mother still knows a\n"
	.string "bargain when she sees one.\p"
	.string "{STR_VAR_2} {STR_VAR_1} is waiting\n"
	.string "in your PC. Enjoy it!$"

Mom_Text_GiftCall_Berry0:
	.string "MOM: Hi, sweetie!\p"
	.string "I found some nice BERRIES\n"
	.string "at the store for you!\p"
	.string "I sent them to your PC.\n"
	.string "Take care!$"

Mom_Text_GiftCall_Berry1:
	.string "MOM: Hello, dear!\p"
	.string "The BERRIES looked lovely today,\n"
	.string "so I bought a few for you.\p"
	.string "They're in your PC.\n"
	.string "Don't skip your meals!$"

Mom_Text_GiftCall_Berry2:
	.string "MOM: It's me!\p"
	.string "A handful of BERRIES never hurt\n"
	.string "anyone, so I sent some along.\p"
	.string "They're waiting in your PC.\n"
	.string "Take care out there!$"

Mom_Text_GiftCall_Berry3:
	.string "MOM: Hi, honey!\p"
	.string "The grocer had BERRIES going\n"
	.string "cheap, so I stocked you up.\p"
	.string "They're in your PC.\n"
	.string "Do look after yourself!$"

Mom_Text_GiftCall_Decoration:
	.string "MOM: Hi, sweetie!\p"
	.string "I bought a cute POKé DOLL\n"
	.string "for your room!\p"
	.string "Check your DECORATIONS when you\n"
	.string "come home. Take care!$"
