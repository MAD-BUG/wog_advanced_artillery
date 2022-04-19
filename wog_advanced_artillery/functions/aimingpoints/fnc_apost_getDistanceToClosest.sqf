params ["_post"];
private _nearArty = nearestObjects [positionCameraToWorld [0,0,0], ["wog_D30_base"], 120];
//systemChat format["_nearArty: %1", _nearArty];
if ((count _nearArty) == 0) exitWith {hint "Поблизости нет орудий!"};
private _excludeArty = [];
{
	private _relDir = player getRelDir _x;
	if ((_relDir < 270) && (_relDir > 90)) then
	{
		_excludeArty pushBack _x;
	};
} forEach _nearArty;
_nearArty = _nearArty - _excludeArty;
//systemChat format["_nearArty: %1", _nearArty];

private _closestObj = _nearArty select 0;
private _relDir = player getRelDir _closestObj;
private _minDelta = if (_relDir >= 180) then {360 - _relDir} else {_relDir};
{
	_relDir = player getRelDir _x;
	private _delta = if (_relDir >= 180) then {360 - _relDir} else {_relDir};
	if (_delta < _minDelta) then
	{
		_minDelta = _delta;
		_closestObj = _x;
	};
} forEach _nearArty;
//systemChat format["_closestObj: %1", _closestObj];
hint format ["Дистанция до орудия: %1 метров", (_post distance _closestObj) toFixed 0];