DaoDaoIsles_ScoriaCave_hns_MapScripts::
	.byte 0

DaoDaoIsles_ScoriaCave_EventScript_Salazzle::
	lock
	faceplayer
	playmoncry SPECIES_SALAZZLE, CRY_MODE_NORMAL
	msgbox DaoDaoIsles_ScoriaCave_Text_Salazzle, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_SALAZZLE, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DaoDaoIsles_ScoriaCave_EventScript_SalazzleStays
	setflag FLAG_HIDE_DAODAO_SCORIA_CAVE_SALAZZLE
	removeobject LOCALID_DAODAO_SCORIA_CAVE_SALAZZLE
DaoDaoIsles_ScoriaCave_EventScript_SalazzleStays::
	release
	end

DaoDaoIsles_ScoriaCave_Text_Salazzle:
	.string "Sssshaaa!$"
