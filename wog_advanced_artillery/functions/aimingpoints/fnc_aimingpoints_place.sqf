#include "\z\ace\addons\main\script_macros.hpp"

params ["_unit", "_itemClass"];

_unit removeItem _itemClass;

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "AmovPercMstpSrasWrflDnon_diary";
};

[{
    params ["_unit","_itemClass"];

    // prevent collision damage
    ["ace_common_fixCollision", _unit] call CBA_fnc_localEvent;

    // Check for a place to land the spotting scope
    private _direction = getDir _unit;
    private _position = (getPosASL _unit) vectorAdd [0.8 * sin(_direction), 0.8 * cos(_direction), 0];
    private _vectorUp = [0, 0, 1];
    private _intersections = lineIntersectsSurfaces [_position vectorAdd [0, 0, 1.5], _position vectorDiff [0, 0, 1.5], _unit, objNull, true, 1, "GEOM", "FIRE"];
    if (_intersections isEqualTo []) then {
        TRACE_1("No intersections",_intersections);
    } else {
        (_intersections select 0) params ["_touchingPoint", "_surfaceNormal"];
        _position = _touchingPoint vectorAdd [0, 0, 0.05];
        _vectorUp = _surfaceNormal;
    };

    // Create the scope and set its position and orientation
	private _objectClass = switch (_itemClass) do
	{
		case "acex_artillery_AimingPost": {"acex_artillery_AimingPost_F"};
		case "acex_artillery_Collimator": {"acex_artillery_Collimator_F"};
	};
    private _aimingObject = _objectClass createVehicle [0, 0, 0];
    _aimingObject setDir _direction;
    _aimingObject setPosASL _position;
    _aimingObject setVectorUp _vectorUp;
    ["ace_common_fixPosition", _aimingObject, _aimingObject] call CBA_fnc_targetEvent;
    ["ace_common_fixFloating", _aimingObject, _aimingObject] call CBA_fnc_targetEvent;

    _unit reveal _aimingObject;

}, [_unit,_itemClass], 1, 0] call CBA_fnc_waitAndExecute;