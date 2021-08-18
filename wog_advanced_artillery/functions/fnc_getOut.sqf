if !(hasInterface) exitWith {};
if ((_this select 2) != player) exitWith {};
if (isNil {player getVariable "wog_advanced_artillery_gunner_handle"}) exitWith {};
(findDisplay 46) displayRemoveEventHandler ["KeyDown", (_this select 2) getVariable "wog_advanced_artillery_gunner_handle"];
if (typeOf (_this select 0) == "wog_pab_2m") then
{
	[player getVariable "wog_advanced_artillery_gunner_handleCompass"] call CBA_fnc_removePerFrameHandler;
	player setVariable ["wog_advanced_artillery_gunner_handleCompass", nil];
	if (local (_this select 0)) then
	{
		["wog_advanced_artillery_changeLocality", [_this select 0]] call CBA_fnc_serverEvent;
	};
} else
{
	if (local (_this select 0)) then
	{
		["wog_advanced_artillery_changeLocality", [_this select 0]] call CBA_fnc_serverEvent;
	};
	[player getVariable "wog_advanced_artillery_compassPFH"] call CBA_fnc_removePerFrameHandler;
	showCompass true;
	player enableInfoPanelComponent ["left", "MinimapDisplayComponent", true];
	player enableInfoPanelComponent ["right", "MinimapDisplayComponent", true];
};
if !(isNull(uiNamespace getVariable ["wog_d30_sight_gui", displayNull])) then
{
	("wog_d30_sight_gui_layer" call BIS_fnc_rscLayer) cutText ["","PLAIN"];
};
player setVariable ["wog_advanced_artillery_gunner_handle", nil];