#include "script_component.hpp"
params ["_target"];

if ((_target animationSourcePhase 'handle_klin_open') == 0) then
{
	_target animateSource ['handle_klin_open', 1];
} else
{
	_target animateSource ['handle_klin_open', 0];
};
[{_this animateSource ['klin_open_source', 0, 0.25]}, _target, 0.6] call CBA_fnc_waitAndExecute;

if ((_target getVariable ["WOG_122_shell_loaded", ""]) == "") exitWith {};
if ((_target getVariable ["WOG_122_casing_loaded", ""]) == "") exitWith {};

waitUntil {(_target animationSourcePhase "klin_open_source") <= 0.1};

['wog_advanced_artillery_remove_mags_server_event', [_target]] call CBA_fnc_serverEvent;
private _index = WOG_ADVANCED_ARTILLERY_CHARGES_ARRAY find (_target getVariable ["WOG_122_casing_loaded", ""]);
switch (_target getVariable ["WOG_122_shell_loaded", ""]) do
{
	case "wog_mag_of462_dummy": {["wog_advanced_artillery_load_server_event", [WOG_ADVANCED_ARTILLERY_OF462_ARRAY select _index, [0], 1, _target]] call CBA_fnc_serverEvent;};
	case "wog_mag_3bk13_dummy": {["wog_advanced_artillery_load_server_event", [WOG_ADVANCED_ARTILLERY_3BK13_ARRAY select _index, [0], 1, _target]] call CBA_fnc_serverEvent;};
};