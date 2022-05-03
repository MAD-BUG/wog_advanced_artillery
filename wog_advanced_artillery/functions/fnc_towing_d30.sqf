//detach gun1; gun1 setDir (getDir truck2); gun1 attachTo [truck2, [0,-6.4,0.13]]; gun1 setVectorUp [0,-0.15,1];
/*
detach gun1; _newPos = truck2 modelToWorld [0,-7,0]; gun1 setPosATL [_newPos select 0, _newPos select 1, 0.3]; gun1 setVectorUp [0,0,1];
detach gun1; gun1 setDir (getDir truck4); gun1 attachTo [truck4, [0.07,-6.5,-0.55]]; gun1 setVectorUp [0,-0.17,1];
detach gun1; gun1 setDir (getDir truck6); gun1 attachTo [truck6, [-0.03,-5.85,-0.11]]; gun1 setVectorUp [0,-0.15,1];
detach gun1; gun1 setDir (getDir truck8); gun1 attachTo [truck8, [-0.06,-5.33,0.25]]; gun1 setVectorUp [0,-0.11,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.02,-6,-0.05]]; gun1 setVectorUp [0,-0.13,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.02,-5.9,-0.30]]; gun1 setVectorUp [0,-0.07,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.02,-5.65,-0.65]]; gun1 setVectorUp [0,-0.07,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.21,-7.5,0.47]]; gun1 setVectorUp [0,-0.25,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.21,-7.5,0.30]]; gun1 setVectorUp [0,-0.25,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.5,-7.6,-0.22]]; gun1 setVectorUp [0,-0.18,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.03,-6.55,-0.27]]; gun1 setVectorUp [0,-0.18,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.1,-6.68,-0.32]]; gun1 setVectorUp [0,-0.18,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.105,-5.41, 0.17]]; gun1 setVectorUp [0,-0.13,1];
detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.105,-5.41, -0.29]]; gun1 setVectorUp [0,-0.13,1];
*/
/*

Offsets:
Ural							attach[0,-6.4,0.13]			vectorUp[0,-0.15,1]
KamaZ							attach[0.07,-6.5,-0.55]		vectorUp[0,-0.17,1]
Zilok							attach[-0.03,-5.85,-0.11]	vectorUp[0,-0.15,1]
GAZ-66							attach[-0.06,-5.33,0.25]	vectorUp[0,-0.11,1]	
Praga							attach[-0.02,-6,-0.05]		vectorUp[0,-0.13,1]
MTLB-PKT						attach[-0.02,-5.9,-0.30]	vectorUp[0,-0.07,1]
UK3CB_MTLB_Zu23					attach[-0.02,-5.65,-0.65]	vectorUp[0,-0.07,1]
rhs_btr80_msv					attach[-0.21,-7.5,0.47]		vectorUp[0,-0.25,1]
rhs_btr80a_msv					attach[-0.21,-7.5,0.30]		vectorUp[0,-0.25,1]
rhs_btr70_msv					attach[-0.5,-7.6,-0.22]		vectorUp[0,-0.18,1]
rhs_btr60_msv					attach[-0.03,-6.55,-0.27]	vectorUp[0,-0.18,1]
rhs_kraz255b1_base				attach[-0.1,-6.68,-0.32]	vectorUp[0,-0.18,1]
CUP_BTR40_Base					attach[-0.105,-5.41,0.17]	vectorUp[0,-0.13,1]
BTR-40_DSHK						attach[-0.105,-5.41,-0.29]	vectorUp[0,-0.13,1]
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

#include "\z\ace\addons\main\script_macros.hpp"

params ["_gun", "_mode"];
if (_mode == 0) then
{
	[5, [_gun], {	
		private ["_gun", "_vehParams", "_vehParams2", "_veh", "_vehArray", "_attachPoint", "_attachVector", "_result", "_isTowed", "_isTowing"];
		_gun = _args select 0;
		_isTowed = _gun getVariable ["WOG_D30_isTowed", false];
		if (_isTowed) exitWith {hint "It's already towing!";};
		
		_vehParams = [
			["rhs_zil131_base", [-0.03,-5.85,-0.11], [0,-0.15,1]],
			["RHS_Ural_BaseTurret", [0,-6.4,0.13], [0,-0.15,1]],
			["rhs_kamaz5350", [0.07,-6.5,-0.55], [0,-0.17,1]],
			["rhs_gaz66_vmf", [-0.06,-5.33,0.25], [0,-0.11,1]],
			["CUP_V3S_Open_Base", [-0.02,-6,-0.05], [0,-0.13,1]],
			["UK3CB_MTLB_Zu23", [-0.02,-5.65,-0.65], [0,-0.07,1]],
			["rhs_kraz255b1_base", [-0.1,-6.68,-0.32], [0,-0.18,1]],
			["CUP_BTR40_Base", [-0.105,-5.41,0.17], [0,-0.13,1]],
			["rhs_btr60_msv", [-0.03,-6.55,-0.27], [0,-0.18,1]]
		];
		_vehParams2 = [
			["UK3CB_MTLB_PKT", [-0.02,-5.9,-0.30], [0,-0.07,1]],
			["UK3CB_B_G_MTLB_PKT", [-0.02,-5.9,-0.30], [0,-0.07,1]],
			["UK3CB_I_G_MTLB_PKT", [-0.02,-5.9,-0.30], [0,-0.07,1]],
			["UK3CB_O_G_MTLB_PKT", [-0.02,-5.9,-0.30], [0,-0.07,1]],
			["rhs_btr70_vmf", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhs_btr70_vdv", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhs_btr70_vv", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhs_btr70_msv", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["fsg_btr_1", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["LOP_BTR70_base", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["LOP_SLA_BTR70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["LOP_UN_BTR70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["LOP_US_BTR70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["LOP_TKA_BTR70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhsgref_cdf_btr70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhsgref_cdf_b_btr70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhsgref_nat_btr70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhsgref_ins_btr70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhsgref_ins_g_btr70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhsgref_un_btr70", [-0.5,-7.6,-0.22], [0,-0.18,1]],
			["rhs_btr80_msv", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["rhs_btr80_vdv", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["rhs_btr80_vv", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["rhs_btr80_vmf", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["fsg_btr_2", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["LOP_BTR80_base", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["LOP_UKR_BTR80", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["LOP_IA_BTR80", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["rhsgref_cdf_btr80", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["rhsgref_cdf_b_btr80", [-0.21,-7.5,0.47], [0,-0.25,1]],
			["rhs_btr80a_msv", [-0.21,-7.5,0.30], [0,-0.25,1]],
			["rhs_btr80a_vdv", [-0.21,-7.5,0.30], [0,-0.25,1]],
			["rhs_btr80a_vv", [-0.21,-7.5,0.30], [0,-0.25,1]],
			["rhs_btr80a_vmf", [-0.21,-7.5,0.30], [0,-0.25,1]],
			["fsg_btr_3", [-0.21,-7.5,0.30], [0,-0.25,1]],
			["CUP_BTR40_MG_Base", [-0.105,-5.41,-0.29], [0,-0.13,1]],
			["CUP_I_BTR40_MG_TKG", [-0.105,-5.41,-0.29], [0,-0.13,1]],
			["CUP_O_BTR40_MG_TKA", [-0.105,-5.41,-0.29], [0,-0.13,1]]
		];

		_vehArray = nearestObjects [_gun, ["Truck_F", "Car_F", "Tank_F"], 20];
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
		if !(_result) then
		{
			{
			if ((typeOf _veh) == (_x select 0)) exitWith {_result = true; _attachPoint = _x select 1; _attachVector = _x select 2;};
			} forEach _vehParams2;
		};
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
		
		[{
			params ["_gun", "_veh"];
			
			["ace_common_fixCollision", _veh, _veh] call CBA_fnc_targetEvent;
			["ace_common_fixCollision", _gun, _gun] call CBA_fnc_targetEvent;
			
			//detach _gun;

			private _direction = getDir _veh;
			private _position = (_gun modelToWorld [0.05, 3, -1.35]) vectorAdd [-(5.8 * sin(_direction)), -(5.8 * cos(_direction)), 0];
			private _pos2 = (AGLToASL (_gun modelToWorld [0.05, 3, -1.35])) vectorAdd [-(5.8 * sin(_direction)), -(5.8 * cos(_direction)), 0];
			_gun attachTo [_veh, _veh worldToModel _position];
			
			[{
				params ["_gun", "_veh", "_position"];
				
				detach _gun;
				private _direction = getDir _veh;
				private _vectorUp = [0, 0, 1];
				private _intersections = lineIntersectsSurfaces [_position vectorAdd [0, 0, 2.5], _position vectorDiff [0, 0, 2.5], _veh, objNull, true, 1, "GEOM", "FIRE"];
				if (_intersections isEqualTo []) then {
					//TRACE_1("No intersections",_intersections);
					hint "No intersections";
				} else {
					(_intersections select 0) params ["_touchingPoint", "_surfaceNormal"];
					_position = _touchingPoint vectorAdd [0, 0, 0.05];
					_vectorUp = _surfaceNormal;
				};
							
				_gun setPosASL _position;
				_gun setDir _direction;
				
				[_gun, _vectorUp] remoteExecCall ["setVectorUp", _gun];

				["ace_common_fixPosition", _gun, _gun] call CBA_fnc_targetEvent;
				["ace_common_fixFloating", _gun, _gun] call CBA_fnc_targetEvent;
				_gun setVariable ["WOG_D30_isTowed", false, true];
				_veh setVariable ["WOG_D30_isTowing", false, true];
			}, [_gun, _veh, _pos2], 1] call CBA_fnc_waitAndExecute;
		}, [_gun, _veh], 0.5] call CBA_fnc_waitAndExecute;
	}, {}, localize "STR_WOG_advanced_artillery_Exec_Detach_displayName"] call ace_common_fnc_progressBar;
};