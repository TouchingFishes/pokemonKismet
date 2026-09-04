@ Split out of Route 25. The event scripts these objects run still live in
@ data/maps/Route25_hns/scripts.inc and are referenced across maps.
CeruleanCape_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCape_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CeruleanCape_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 7, CeruleanCape_EventScript_SetSuicuneSceneMid
	end

@ Eusine's mid-scene spot. Was Route 25 (98,14); the cut at column 77
@ rebases it to Cape (21,14).
CeruleanCape_EventScript_SetSuicuneSceneMid::
	setobjectxyperm LOCALID_CERULEAN_CAPE_EUSINE, 21, 14
	end
