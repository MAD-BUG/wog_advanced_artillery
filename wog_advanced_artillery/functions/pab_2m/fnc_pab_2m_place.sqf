#include "\z\ace\addons\main\script_macros.hpp"

params ["_unit", "_bussoleClass"];

removeBackpackGlobal _unit;

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "AmovPercMstpSrasWrflDnon_diary";
};

[{
    params ["_unit"];

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
    private _bussoleObject = "wog_pab_2m" createVehicle [0, 0, 0];
    _bussoleObject setDir _direction;
    _bussoleObject setPosASL _position;
    _bussoleObject setVectorUp _vectorUp;
    ["ace_common_fixPosition", _bussoleObject, _bussoleObject] call CBA_fnc_targetEvent;
    ["ace_common_fixFloating", _bussoleObject, _bussoleObject] call CBA_fnc_targetEvent;

    _unit reveal _bussoleObject;

}, [_unit], 1, 0] call CBA_fnc_waitAndExecute;