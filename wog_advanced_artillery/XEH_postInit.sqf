#include "functions\script_component.hpp"

["wog_advanced_artillery_load_local_event",
{
	params ["_mag", "_turretPath", "_numMags", "_vehicle"];
	_vehicle addMagazineTurret [_mag, _turretPath, _numMags];
}
] call CBA_fnc_addEventHandler;

["wog_advanced_artillery_load_server_event",
{
	params ["_mag", "_turretPath", "_numMags", "_vehicle"];
	if (isServer) then
	{
		private _turretOwnerID = _vehicle turretOwner _turretPath;
		if (_turretOwnerID == 0) then {
        ["wog_advanced_artillery_load_local_event", _this, [_vehicle]] call CBA_fnc_targetEvent;
		} else {
        ["wog_advanced_artillery_load_local_event", _this, _turretOwnerID] call CBA_fnc_ownerEvent;
		};
	};
}
] call CBA_fnc_addEventHandler;

["wog_advanced_artillery_remove_mags_local_event",
{
	params ["_vehicle"];
	{_vehicle removeMagazinesTurret [_x,[0]];} forEach (WOG_ADVANCED_ARTILLERY_OF462_ARRAY + WOG_ADVANCED_ARTILLERY_3BK13_ARRAY);
}
] call CBA_fnc_addEventHandler;

["wog_advanced_artillery_remove_mags_server_event",
{
	params ["_vehicle"];
	if (isServer) then
	{
		private _turretOwnerID = _vehicle turretOwner [0];
		if (_turretOwnerID == 0) then {
        ["wog_advanced_artillery_remove_mags_local_event", _this, [_vehicle]] call CBA_fnc_targetEvent;
		} else {
        ["wog_advanced_artillery_remove_mags_local_event", _this, _turretOwnerID] call CBA_fnc_ownerEvent;
		};
	};
}
] call CBA_fnc_addEventHandler;

["wog_advanced_artillery_attach_vehicle_event",
{
	params ["_gun", "_veh", "_attachVector", "_attachPoint"];
	if (isServer) then
	{
		_gun enableSimulationGlobal false;
		_gun setDir (getDir _veh);
		_gun attachTo [_veh, _attachPoint];
		_gun setVectorUp _attachVector;
		_gun enableSimulationGlobal true;
	};
}
] call CBA_fnc_addEventHandler;