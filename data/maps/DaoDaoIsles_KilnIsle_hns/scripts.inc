DaoDaoIsles_KilnIsle_hns_MapScripts::
	.byte 0

DaoDaoIsles_KilnIsle_EventScript_HideKecleon::
	setvar VAR_TEMP_9, 1
	setflag FLAG_TEMP_1
	removeobject LOCALID_DAODAO_KILN_KECLEON
	end
