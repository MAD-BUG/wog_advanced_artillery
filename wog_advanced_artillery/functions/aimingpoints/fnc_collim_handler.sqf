
_gp = positionCameraToWorld [0,0,0];
_gp set[2, getTerrainHeightASL [_gp select 0, _gp select 1]];
_nearCollimators = nearestObjects [positionCameraToWorld [0,0,0], ["acex_artillery_Collimator_F"], 20];
_moved = false;
{
	_lastPos = _x getVariable ["ace_colLastPos", [0,0,0]];
	if(_lastPos distance (getPosASL _x) > 0) exitWith {
		_moved = true;
	};
} forEach _nearCollimators;
_proxies = nearestObjects [positionCameraToWorld [0,0,0], ["ACE_Arty_Collimator_Proxy"], 25];
if((count _proxies) != (count _nearCollimators)) then {
	_moved = true;
};
if(_moved) then {
	ACE_ARTY_COLLIMATORS = [];
	{
		deleteVehicle _x;
	} forEach _proxies;
};
if !(cameraView == "GUNNER") then {
	_nearCollimators = [];
};
_newCollimators = _nearCollimators - ACE_ARTY_COLLIMATORS;
{
	// player sideChat format["creating proxyaaaa"];
	_collimatorProxy = "ACE_Arty_Collimator_Proxy" createVehicleLocal (getPos _x);
	_collimatorProxy setDir 180;
	_collimatorProxy attachTo [_x, [0,0,0], "optic_proxy"];
	_x setVariable ["ace_collimator_proxy", _collimatorProxy];
} forEach _newCollimators;
_oldCollimators = ACE_ARTY_COLLIMATORS - _nearCollimators;
{
	// player sideChat format["deleting proxy"];
	_collimatorProxy = _x getVariable "ace_collimator_proxy";
	detach _collimatorProxy;
	deleteVehicle _collimatorProxy;
} forEach _oldCollimators;
ACE_ARTY_COLLIMATORS = _nearCollimators;
{
	_collimatorProxy = _x getVariable "ace_collimator_proxy";
	_x setVariable ["ace_colLastPos",(getPosASL _x)];
	_colRot = (_x animationPhase "collimator_rotation")/3200*180;
	_colElev = (_x animationPhase"collimator_elevation")/3200*-180;
	_cosElev = cos(_colElev);
	_xdash = -1*(sin _colRot)*_cosElev;
	_ydash = (cos _colRot)*_cosElev;
	_zdash = sin(_colElev);
	_vecuz = _cosElev;
	_collimatorProxy setVectorDirAndUp [[_xdash,_ydash,_zdash],[0,0,_vecuz]];
	_cp = _collimatorProxy modelToWorld (_collimatorProxy selectionPosition "optic");
	_cp set [2, getTerrainHeightASL [_cp select 0, _cp select 1]];
	_dis = (_gp distance _cp);
	//systemChat format["_dis: %1", _dis];
	_offset = 0;
	_disDif = 0;
	_relDir = _cp getDir _gp;
	_relDir = _relDir - (getDir _collimatorProxy);
	_relDir = -1*(sin _relDir)*_dis;
	//systemChat format["-1*(sin _relDir)*_dis: %1", _relDir];
	_relDir = _relDir/0.00796; //0.00796
	//systemChat format["_relDir: %1", _relDir];
	if ((_dis>=16)||(_dis<=4)||(_relDir>100)||(_relDir<-100)) then
	{
		_disDif = -1;
	}else
	{
		_disDif = (_dis-10.192713)*0.11652733; //0.0957946
	};
	//systemChat format["_disDif: %1", _disDif];
	_collimatorProxy animate ["expand_ul", _disDif];
	_collimatorProxy animate ["expand_ur", _disDif];
	_collimatorProxy animate ["expand_ll", _disDif];
	_collimatorProxy animate ["expand_lr", _disDif];
	_collimatorProxy animate ["offset", _relDir];
	
	_illumMode = _x getVariable ["ace_collimator_illum", false];
	if (_illumMode) then
	{
		_collimatorProxy setObjectTexture [0, "\wog_advanced_artillery\aimingpoints\data\collimator_pattern_illum_co.paa"];
		_collimatorProxy setObjectMaterial [0, "\wog_advanced_artillery\aimingpoints\data\c2_illum.rvmat"];
	} else
	{
		_collimatorProxy setObjectTexture [0, "\wog_advanced_artillery\aimingpoints\data\collimator_pattern_ca.paa"];
		_collimatorProxy setObjectMaterial [0, "\wog_advanced_artillery\aimingpoints\data\c2.rvmat"];
	};
} forEach ACE_ARTY_COLLIMATORS;