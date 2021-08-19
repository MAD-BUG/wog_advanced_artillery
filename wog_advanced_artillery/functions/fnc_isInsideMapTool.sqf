#include "script_component.hpp"
/*
 * Author: esteldunedain
 * Return true if the position is inside the map marker (to allow dragging).
 *
 * Arguments:
 * 0: x Position (in meters) <NUMBER>
 * 1: y Position (in meters) <NUMBER>
 *
 * Return Value:
 * Boolean <BOOL>
 *
 * Example:
 * [0, 5] call ACE_maptools_fnc_isInsideMapTool
 *
 * Public: No
 */

if (ace_maptools_mapTool_Shown == 0) exitWith {false};
private "_textureWidth";

if (ace_maptools_mapTool_Shown < 3) then
{
	_textureWidth = [TEXTURE_WIDTH_IN_M, TEXTURE_WIDTH_IN_M / 2] select (ace_maptools_mapTool_Shown - 1);
} else
{
	_textureWidth = [TEXTURE_WIDTH_IN_M, TEXTURE_WIDTH_IN_M / 2] select (ace_maptools_mapTool_Shown - 3);
};

private _pos = [_this select 0, _this select 1, 0];
private _relPos = _pos vectorDiff [ace_maptools_mapTool_pos select 0, ace_maptools_mapTool_pos select 1, 0];
private _dirVector = [sin(ace_maptools_mapTool_angle), cos(ace_maptools_mapTool_angle), 0];

// Projection of the relative position over the longitudinal axis of the map tool
private _lambdaLong = _dirVector vectorDotProduct _relPos;
if (_lambdaLong < DIST_BOTTOM_TO_CENTER_PERC * _textureWidth) exitWith {false};

// Projection of the relative position over the trasversal axis of the map tool
private _lambdaTrasAbs = vectorMagnitude (_relPos vectorDiff (_dirVector vectorMultiply _lambdaLong));
if (_lambdaLong > DIST_TOP_TO_CENTER_PERC * _textureWidth) exitWith {false};
if (_lambdaTrasAbs > DIST_LEFT_TO_CENTER_PERC * _textureWidth) exitWith {false};

true
