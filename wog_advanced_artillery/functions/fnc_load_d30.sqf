#include "script_component.hpp"

params ["_gun", "_type"];
private ["_mags", "_index"];
_mags = [];

switch (_type) do
{
	case 1:
	{
		{
			if (_x in WOG_ADVANCED_ARTILLERY_SHELLS_ARRAY) then
			{
				_mags pushBack _x;
			};
		} forEach (magazines player);
		if ((count _mags) == 0) exitWith {hint "You have not a shell!"};
		_gun setVariable ["WOG_122_shell_loaded", _mags select 0, true];
		player removeItem (_mags select 0);
		_gun animateSource ['shell_loading', 1];
		player playAction "PutDown";
	};

	case 2:
	{
		{
			if (_x in WOG_ADVANCED_ARTILLERY_CHARGES_ARRAY) then
			{
				_mags pushBack _x;
			};
		} forEach (magazines player);
		if ((count _mags) == 0) exitWith {hint "You have not a casing!"};
		_gun setVariable ["WOG_122_casing_loaded", _mags select 0, true];
		player removeItem (_mags select 0);
		player playAction "PutDown";
		_gun animateSource ['casing_loading', 1];
		[{_this animateSource ['klin_open_source', 0]}, _gun, 0.55] call CBA_fnc_waitAndExecute;
		[{playSound3D ["wog_advanced_artillery\sounds\load_gun.wss", _this, false, AGLToASL (_this modelToWorld (_this selectionPosition "ejector_pos")), 3, 1, 35]}, _gun, 0.25] call CBA_fnc_waitAndExecute;
		waitUntil {(_gun animationSourcePhase "casing_loading") == 1};
		['wog_advanced_artillery_remove_mags_server_event', [_gun]] call CBA_fnc_serverEvent;
		_index = WOG_ADVANCED_ARTILLERY_CHARGES_ARRAY find (_mags select 0);
		["wog_advanced_artillery_load_server_event", [WOG_ADVANCED_ARTILLERY_OF462_ARRAY select _index, [0], 1, _gun]] call CBA_fnc_serverEvent;
	};
	
	case 3:
	{
		if ((_gun getVariable ["WOG_122_shell_loaded", ""]) == "") exitWith {hint "Unload error!"};
		if !(player canAddItemToBackpack [_gun getVariable "WOG_122_shell_loaded", 1]) exitWith {hint "Not enough space in backpack!"};
		_gun animateSource ['shell_loading', 0];
		player playAction "PutDown";
		player addItemToBackpack (_gun getVariable "WOG_122_shell_loaded");
		_gun setVariable ["WOG_122_shell_loaded", "", true];
	};
	
	case 4:
	{
		if ((_gun getVariable ["WOG_122_casing_loaded", ""]) == "") exitWith {hint "Unload error!"};
		if !(player canAddItemToBackpack [_gun getVariable "WOG_122_casing_loaded", 1]) exitWith {hint "Not enough space in backpack!"};
		_gun animateSource ['casing_loading', 0];
		player playAction "PutDown";
		player addItemToBackpack (_gun getVariable "WOG_122_casing_loaded");
		_gun setVariable ["WOG_122_casing_loaded", "", true];
	};
};