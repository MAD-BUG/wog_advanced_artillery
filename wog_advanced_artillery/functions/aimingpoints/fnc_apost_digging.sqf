params ["_object"];
private _pos = getPosATL _object;
private _height = _pos select 2;
if (_height > -0.4) then
{
	_pos set [2, getTerrainHeightASL [_pos select 0, _pos select 1] - 0.8];
} else
{
	_pos set [2, getTerrainHeightASL [_pos select 0, _pos select 1]];
};
//systemChat format["_pos: %1", _pos];
_object setPosASL _pos;
