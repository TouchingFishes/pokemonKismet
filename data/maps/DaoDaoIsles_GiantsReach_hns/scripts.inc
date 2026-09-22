DaoDaoIsles_GiantsReach_hns_MapScripts::
	.byte 0

@ The PHANT cutscene, copied from UlaulaIsle because Giant's Reach cannot
@ share it.
@
@ Two reasons, both silent:
@  - Giant's Reach lost the TAPU object in chunk 1, so PHANT sits at object
@    11/12 here and 12/13 on UlaulaIsle. map_event_ids.h has no namespacing, so
@    the two maps disagreed on what `Phant_Outside` means and one of them
@    despawned the wrong NPC.
@  - Giant's Reach is 47 columns wide against UlaulaIsle's 51 and PHANT stands at
@    x=32 rather than 36, so every hardcoded player-x test was 4 columns out.
@
@ The Text_ and Movement_ labels are still UlaulaIsle's - those are shared data
@ with no coordinates or local ids in them.

DaoDaoIsles_GiantsReach_PhantOutside::
	lock
	faceplayer
	hidefollower
	msgbox Alola_Ulaula_Phant_outside_Text_0, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 31
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_3
DaoDaoIsles_GiantsReach_PhantOutside_1:
	compare VAR_TEMP_0, 32
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_8
DaoDaoIsles_GiantsReach_PhantOutside_6:
	compare VAR_TEMP_0, 33
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_13
DaoDaoIsles_GiantsReach_PhantOutside_11:
	compare VAR_TEMP_0, 32
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_18
DaoDaoIsles_GiantsReach_PhantOutside_16:
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	msgbox Alola_Ulaula_Phant_outside_Text_1, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 31
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_23
DaoDaoIsles_GiantsReach_PhantOutside_22:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, Alola_Ulaula_Phant_outside_Movement_6
	waitmovement 0
	playmoncry SPECIES_NOIVERN, 0
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT_NOIVERN, Alola_Ulaula_Phant_outside_Movement_5
	waitmovement 0
	removeobject LOCALID_DAODAO_GIANTS_REACH_PHANT_NOIVERN
	removeobject LOCALID_DAODAO_GIANTS_REACH_PHANT
	setflag FLAG_HIDE_PHANT_OUTSIDE
	clearflag FLAG_HIDE_PHANT_INSIDE
	release
	end

DaoDaoIsles_GiantsReach_PhantOutside_2:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, Alola_Ulaula_Phant_outside_Movement_0
	goto DaoDaoIsles_GiantsReach_PhantOutside_1

DaoDaoIsles_GiantsReach_PhantOutside_3:
	compare VAR_TEMP_1, 46
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_2
	goto DaoDaoIsles_GiantsReach_PhantOutside_1

DaoDaoIsles_GiantsReach_PhantOutside_7:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, Alola_Ulaula_Phant_outside_Movement_1
	goto DaoDaoIsles_GiantsReach_PhantOutside_6

DaoDaoIsles_GiantsReach_PhantOutside_8:
	compare VAR_TEMP_1, 47
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_7
	goto DaoDaoIsles_GiantsReach_PhantOutside_6

DaoDaoIsles_GiantsReach_PhantOutside_12:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, Alola_Ulaula_Phant_outside_Movement_2
	goto DaoDaoIsles_GiantsReach_PhantOutside_11

DaoDaoIsles_GiantsReach_PhantOutside_13:
	compare VAR_TEMP_1, 46
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_12
	goto DaoDaoIsles_GiantsReach_PhantOutside_11

DaoDaoIsles_GiantsReach_PhantOutside_17:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, Alola_Ulaula_Phant_outside_Movement_3
	goto DaoDaoIsles_GiantsReach_PhantOutside_16

DaoDaoIsles_GiantsReach_PhantOutside_18:
	compare VAR_TEMP_1, 45
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_17
	goto DaoDaoIsles_GiantsReach_PhantOutside_16

DaoDaoIsles_GiantsReach_PhantOutside_21:
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT, Alola_Ulaula_Phant_outside_Movement_4
	waitmovement 0
	playmoncry SPECIES_NOIVERN, 0
	applymovement LOCALID_DAODAO_GIANTS_REACH_PHANT_NOIVERN, Alola_Ulaula_Phant_outside_Movement_5
	waitmovement 0
	removeobject LOCALID_DAODAO_GIANTS_REACH_PHANT_NOIVERN
	removeobject LOCALID_DAODAO_GIANTS_REACH_PHANT
	setflag FLAG_HIDE_PHANT_OUTSIDE
	clearflag FLAG_HIDE_PHANT_INSIDE
	release
	end

DaoDaoIsles_GiantsReach_PhantOutside_23:
	compare VAR_TEMP_1, 46
	goto_if_eq DaoDaoIsles_GiantsReach_PhantOutside_21
	goto DaoDaoIsles_GiantsReach_PhantOutside_22
