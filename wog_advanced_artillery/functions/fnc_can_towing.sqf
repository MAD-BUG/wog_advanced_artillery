//detach gun1; gun1 setDir (getDir truck2); gun1 attachTo [truck2, [0,-6.4,0.13]]; gun1 setVectorUp [0,-0.15,1];

//detach gun1; _newPos = truck2 modelToWorld [0,-7,0]; gun1 setPosATL [_newPos select 0, _newPos select 1, 0.3]; gun1 setVectorUp [0,0,1];
//detach gun1; gun1 setDir (getDir truck4); gun1 attachTo [truck4, [0.07,-6.5,-0.55]]; gun1 setVectorUp [0,-0.17,1];
//detach gun1; gun1 setDir (getDir truck6); gun1 attachTo [truck6, [-0.03,-5.85,-0.11]]; gun1 setVectorUp [0,-0.15,1];
//detach gun1; gun1 setDir (getDir truck8); gun1 attachTo [truck8, [-0.06,-5.33,0.25]]; gun1 setVectorUp [0,-0.11,1];
//detach gun1; gun1 setDir (getDir veh1); gun1 attachTo [veh1, [-0.02,-6,-0.05]]; gun1 setVectorUp [0,-0.13,1];
//_pos1 = veh1 worldToModel (gun1 modelToWorld [0.05, 3, -1.35]); sphere1 setPosATL (veh1 modelToWorld _pos1); copyToClipboard str _pos1;

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
======================================================
Zilok							[0, -2.63, -0.98]
GAZ-66							[-0.03, -2.16, -0.76]
Ural							[0, -3.2, -0.7]
Kamaz							[0.113, -3.28, -1.38]
Praga							[0.03, -2.85, -1.01]
MTLB_PKT						[0.03,-2.81,-1.43]
MTLB-ZU-23						[0.03,-2.56,-1.78]
rhs_btr80_msv					[-0.15,-4.26,-0.11]
rhs_btr80a_msv					[-0.15,-4.26,-0.28]
rhs_btr70_vmf					[-0.45,-4.41,-1.01]
rhs_btr60_vmf					[0.01,-3.35,-1.06]
rhs_kraz255b1_base				[-0.05,-3.48,-1.11]
BTR-40							[-0.05,-2.25,-0.78]
BTR-40_DSHK						[-0.05,-2.26,-1.24]
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

/*
Classes:
[rhs_zil131_base, RHS_Ural_BaseTurret, rhs_kamaz5350, rhs_gaz66_vmf, CUP_V3S_Open_Base]

*/
private ["_vehArray", "_result", "_veh", "_dir", "_vehDir", "_vehParams", "_vehParams2", "_vehPoint", "_gunPoint", "_towingPoint", "_isTowing", "_isTowed"];
params ["_gun"];
_isTowed = _gun getVariable ["WOG_D30_isTowed", false];
if (_isTowed) exitWith {false};
if (_gun animationPhase 'leftT' == 0) exitWith {false};

_vehParams = [
	["rhs_zil131_base", [0, -2.63, -0.98]],
	["RHS_Ural_BaseTurret", [0, -3.2, -0.7]],
	["rhs_kamaz5350", [0.113, -3.28, -1.38]],
	["rhs_gaz66_vmf", [-0.03, -2.16, -0.76]],
	["CUP_V3S_Open_Base", [0.03, -2.85, -1.01]],
	["UK3CB_MTLB_Zu23", [0.03,-2.56,-1.78]],
	["rhs_kraz255b1_base", [-0.05,-3.48,-1.11]],
	["CUP_BTR40_Base", [-0.05,-2.25,-0.78]],
	["rhs_btr60_msv", [0.01,-3.35,-1.06]]
];

_vehParams2 = [
	["UK3CB_MTLB_PKT", [0.03,-2.81,-1.43]],
	["UK3CB_B_G_MTLB_PKT", [0.03,-2.81,-1.43]],
	["UK3CB_I_G_MTLB_PKT", [0.03,-2.81,-1.43]],
	["UK3CB_O_G_MTLB_PKT", [0.03,-2.81,-1.43]],
	["rhs_btr70_vmf", [-0.45,-4.41,-1.01]],
	["rhs_btr70_vdv", [-0.45,-4.41,-1.01]],
	["rhs_btr70_vv", [-0.45,-4.41,-1.01]],
	["rhs_btr70_msv", [-0.45,-4.41,-1.01]],
	["fsg_btr_1", [-0.45,-4.41,-1.01]],
	["LOP_BTR70_base", [-0.45,-4.41,-1.01]],
	["LOP_SLA_BTR70", [-0.45,-4.41,-1.01]],
	["LOP_UN_BTR70", [-0.45,-4.41,-1.01]],
	["LOP_US_BTR70", [-0.45,-4.41,-1.01]],
	["LOP_TKA_BTR70", [-0.45,-4.41,-1.01]],
	["rhsgref_cdf_btr70", [-0.45,-4.41,-1.01]],
	["rhsgref_cdf_b_btr70", [-0.45,-4.41,-1.01]],
	["rhsgref_nat_btr70", [-0.45,-4.41,-1.01]],
	["rhsgref_ins_btr70", [-0.45,-4.41,-1.01]],
	["rhsgref_ins_g_btr70", [-0.45,-4.41,-1.01]],
	["rhsgref_un_btr70", [-0.45,-4.41,-1.01]],
	["rhs_btr80_msv", [-0.15,-4.26,-0.11]],
	["rhs_btr80_vdv", [-0.15,-4.26,-0.11]],
	["rhs_btr80_vv", [-0.15,-4.26,-0.11]],
	["rhs_btr80_vmf", [-0.15,-4.26,-0.11]],
	["fsg_btr_2", [-0.15,-4.26,-0.11]],
	["LOP_BTR80_base", [-0.15,-4.26,-0.11]],
	["LOP_UKR_BTR80", [-0.15,-4.26,-0.11]],
	["LOP_IA_BTR80", [-0.15,-4.26,-0.11]],
	["rhsgref_cdf_btr80", [-0.15,-4.26,-0.11]],
	["rhsgref_cdf_b_btr80", [-0.15,-4.26,-0.11]],
	["rhs_btr80a_msv", [-0.15,-4.26,-0.28]],
	["rhs_btr80a_vdv", [-0.15,-4.26,-0.28]],
	["rhs_btr80a_vv", [-0.15,-4.26,-0.28]],
	["rhs_btr80a_vmf", [-0.15,-4.26,-0.28]],
	["fsg_btr_3", [-0.15,-4.26,-0.28]],
	["CUP_BTR40_MG_Base", [-0.05,-2.26,-1.24]],
	["CUP_I_BTR40_MG_TKG", [-0.05,-2.26,-1.24]],
	["CUP_O_BTR40_MG_TKA", [-0.05,-2.26,-1.24]]
];

_vehArray = nearestObjects [_gun, ["Truck_F", "Car_F", "Tank_F"], 20];
if ((count _vehArray) == 0) exitWith {false};
_veh = _vehArray select 0;
_isTowing = _veh getVariable ["WOG_D30_isTowing", false];
if (_isTowing) exitWith {false};
_result = false;
_towingPoint = [];
{
	if (_veh isKindOf (_x select 0)) exitWith {_result = true; _towingPoint = _x select 1;};
} forEach _vehParams;
if !(_result) then
{
	{
		if ((typeOf _veh) == (_x select 0)) exitWith {_result = true; _towingPoint = _x select 1;};
	} forEach _vehParams2;
};
if !(_result) exitWith {false};

_dir = getDir _gun;
_vehDir = getDir _veh;
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
if !(_result) exitWith {false};

_vehPoint = AGLToASL (_veh modelToWorld _towingPoint);
_gunPoint = AGLToASL (_gun modelToWorld [0.05, 3, -1.35]);
if ((_vehPoint distance _gunPoint) > 4) exitWith {false};
true