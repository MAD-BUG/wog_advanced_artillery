//detach gun1; gun1 setDir (getDir truck2); gun1 attachTo [truck2, [0,-6.4,0.13]]; gun1 setVectorUp [0,-0.15,1];

//detach gun1; _newPos = truck2 modelToWorld [0,-7,0]; gun1 setPosATL [_newPos select 0, _newPos select 1, 0.3]; gun1 setVectorUp [0,0,1];
//detach gun1; gun1 setDir (getDir truck4); gun1 attachTo [truck4, [0.07,-6.5,-0.55]]; gun1 setVectorUp [0,-0.17,1];
//detach gun1; gun1 setDir (getDir truck6); gun1 attachTo [truck6, [-0.03,-5.85,-0.11]]; gun1 setVectorUp [0,-0.15,1];
//detach gun1; gun1 setDir (getDir truck8); gun1 attachTo [truck8, [-0.06,-5.33,0.25]]; gun1 setVectorUp [0,-0.11,1];
//detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.02,-6,-0.05]]; gun1 setVectorUp [0,-0.13,1];

/*

Offsets:
Ural		attach[0,-6.4,0.13]			vectorUp[0,-0.15,1]
KamaZ		attach[0.07,-6.5,-0.55]		vectorUp[0,-0.17,1]
Zilok		attach[-0.03,-5.85,-0.11]	vectorUp[0,-0.15,1]
GAZ-66		attach[-0.06,-5.33,0.25]	vectorUp[0,-0.11,1]	
Praga		attach[-0.02,-6,-0.05]		vectorUp[0,-0.13,1]

*/

/*
Towing point:
D30			[0.05, 3, -1.35]
=================================
Zilok		[0, -2.63, -0.98]

*/

/*

_dir = getDir gun1;
_vehDir = getDir truck1;
_minDir = if ((_dir - 45) < 0) then {_dir - 45 + 360} else {_dir - 45};
_maxDir = if ((_dir + 45) > 360) then {(_dir + 45) % 360} else {_dir + 45};
_result = false;
if (_maxDir < _minDir) then
{
	if ((_vehDir >= _minDir) || (_vehDir <= _maxDir)) then {_result = true;};
} else
{
	if ((_vehDir >= _minDir) && (_vehDir <= _maxDir)) then {_result = true;};
};
hint str _result;

*/

/*

_vehPoint = AGLToASL (truck1 modelToWorld [0, -2.63, -0.98]);
_gunPoint = AGLToASL (gun1 modelToWorld [0.05, 3, -1.35]);
hint str (_vehPoint distance _gunPoint);

*/
params ["_gun", "_mode"];
if (_mode == 0) then
{
	[5, [_gun], {	
		private ["_gun", "_vehParams", "_veh", "_vehArray", "_attachPoint", "_attachVector", "_result", "_isTowed", "_isTowing"];
		_gun = _args select 0;
		_isTowed = _gun getVariable ["WOG_D30_isTowed", false];
		if (_isTowed) exitWith {hint "It's already towing!";};
		
		_vehParams = [
			["rhs_zil131_base", [-0.03,-5.85,-0.11], [0,-0.15,1]],
			["RHS_Ural_BaseTurret", [0,-6.4,0.13], [0,-0.15,1]],
			["rhs_kamaz5350", [0.07,-6.5,-0.55], [0,-0.17,1]],
			["rhs_gaz66_vmf", [-0.06,-5.33,0.25], [0,-0.11,1]],
			["CUP_V3S_Open_Base", [-0.02,-6,-0.05], [0,-0.13,1]]
		];

		_vehArray = nearestObjects [_gun, ["Truck_F"], 20];
		if ((count _vehArray) == 0) exitWith {hint "No available truck!";};
		_veh = _vehArray select 0;
		_isTowing = _veh getVariable ["WOG_D30_isTowing", false];
		if (_isTowing) exitWith {hint "Truck is already towing!";};
		_result = false;
		_attachPoint = [];
		_attachVector = [];
		{
			if (_veh isKindOf (_x select 0)) exitWith {_result = true; _attachPoint = _x select 1; _attachVector = _x select 2;};
		} forEach _vehParams;
		if !(_result) exitWith {hint "No available truck!";};

		["wog_advanced_artillery_attach_vehicle_event", [_gun, _veh, _attachVector, _attachPoint]] call CBA_fnc_serverEvent;
		_gun setVariable ["WOG_D30_isTowed", true, true];
		_veh setVariable ["WOG_D30_isTowing", true, true];
		_gun setVariable ["WOG_D30_towingVehicle", _veh, true];
	}, {}, localize "STR_WOG_advanced_artillery_Exec_Attach_displayName"] call ace_common_fnc_progressBar;
} else
{
	[5, [_gun], {	
		private ["_gun", "_veh", "_isTowed", "_isTowing", "_newPos"];
		_gun = _args select 0;
		_isTowed = _gun getVariable ["WOG_D30_isTowed", false];
		if !(_isTowed) exitWith {hint "It's already detached!";};
		
		_veh = _gun getVariable "WOG_D30_towingVehicle";
		_gun disableCollisionWith _veh;
		detach _gun;
		_newPos = _veh modelToWorld [0,-7,0];
		_gun setPosATL [_newPos select 0, _newPos select 1, 0.3];
		_gun setVectorUp [0,0,1];
		_gun enableCollisionWith _veh;
		_gun setVariable ["WOG_D30_isTowed", false, true];
		_veh setVariable ["WOG_D30_isTowing", false, true];
	}, {}, localize "STR_WOG_advanced_artillery_Exec_Detach_displayName"] call ace_common_fnc_progressBar;
};