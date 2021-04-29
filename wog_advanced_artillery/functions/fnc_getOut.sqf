if !(hasInterface) exitWith {};
if ((_this select 2) != player) exitWith {};
if (isNil {player getVariable "wog_advanced_artillery_gunner_handle"}) exitWith {};
(findDisplay 46) displayRemoveEventHandler ["KeyDown", (_this select 2) getVariable "wog_advanced_artillery_gunner_handle"];
if !(isNull(uiNamespace getVariable ["wog_d30_sight_gui", displayNull])) then
{
	("wog_d30_sight_gui_layer" call BIS_fnc_rscLayer) cutText ["","PLAIN"];
};
player setVariable ["wog_advanced_artillery_gunner_handle", nil];