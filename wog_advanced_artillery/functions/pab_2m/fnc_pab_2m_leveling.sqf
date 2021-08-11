
[5, _this, {
	_args params ["_vehicle"];
	
	private _pad = "Land_HelipadEmpty_F" createVehicle (getPos _vehicle);
	_pad setVectorUp [0,0,1];
	_pad setPosATL (getPosATL _vehicle);
	_pad setDir (getDir _vehicle);
	_vehicle attachTo [_pad, [0,0,0.95]];
	
	[_vehicle, false] call ace_dragging_fnc_setDraggable;
	[_vehicle, false] call ace_dragging_fnc_setCarryable;

	_vehicle setVariable ["wog_pab_2m_helper_pad", _pad, true];
}, {}, localize "STR_WOG_advanced_artillery_pab_2m_leveling"] call ace_common_fnc_progressBar;