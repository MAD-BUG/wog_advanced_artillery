#include "script_component.hpp"
/*
 * Author: esteldunedain
 * Update the map tool markers, position, size, rotation and visibility.
 *
 * Arguments:
 * 0: The Map <CONTROL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [CONTROL] call ACE_maptools_fnc_updateMapToolMarkers
 *
 * Public: No
 */

params ["_theMap"];

if ((ace_maptools_mapTool_Shown == 0) || {!("ACE_MapTools" in (ACE_player call ace_common_fnc_uniqueItems))}) exitWith {};

private _rotatingTexture = "";
private _textureWidth = 0;
if ((ace_maptools_mapTool_Shown == 1) || (ace_maptools_mapTool_Shown == 3)) then {
    _rotatingTexture = "\z\ace\addons\maptools\data\mapToolRotatingNormal.paa";
    _textureWidth = TEXTURE_WIDTH_IN_M;
} else {
    _rotatingTexture = "\z\ace\addons\maptools\data\mapToolRotatingSmall.paa";
    _textureWidth = TEXTURE_WIDTH_IN_M / 2;
};

if (ace_maptools_freedrawing) then {[_theMap, _textureWidth] call ace_maptools_fnc_drawLinesOnRoamer;};

// Update scale of both parts
getResolution params ["_resWidth", "_resHeight", "", "", "_aspectRatio"];
private _scaleX = 32 * _textureWidth * CONSTANT_SCALE * (call ace_maptools_fnc_calculateMapScale);
private _scaleY = _scaleX * ((_resWidth / _resHeight) / _aspectRatio); //handle bad aspect ratios

// Position of the fixed part
private _xPos = ace_maptools_mapTool_pos select 0;
private _yPos = (ace_maptools_mapTool_pos select 1) + _textureWidth * CENTER_OFFSET_Y_PERC;

if ((ace_maptools_mapTool_Shown == 1) || (ace_maptools_mapTool_Shown == 2)) then
{
	_theMap drawIcon ["\z\ace\addons\maptools\data\mapToolFixed.paa", [1,1,1,1], [_xPos,_yPos], _scaleX, _scaleY, 0, "", 0];
} else
{
	_theMap drawIcon ["wog_advanced_artillery\resource\data\mapToolFixed_6000.paa", [1,1,1,1], [_xPos,_yPos], _scaleX, _scaleY, 0, "", 0];
};

// Position and rotation of the rotating part
_xPos = (ace_maptools_mapTool_pos select 0) + sin(ace_maptools_mapTool_angle) * _textureWidth * CENTER_OFFSET_Y_PERC;
_yPos = (ace_maptools_mapTool_pos select 1) + cos(ace_maptools_mapTool_angle) * _textureWidth * CENTER_OFFSET_Y_PERC;

_theMap drawIcon [_rotatingTexture, [1,1,1,1], [_xPos,_yPos], _scaleX, _scaleY, ace_maptools_mapTool_angle, "", 0];
