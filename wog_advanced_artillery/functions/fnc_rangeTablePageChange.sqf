/*
 * Author: PabstMirror
 * Called when listbox selection changes.  Updates the rangetable with new values.
 *
 * Arguments:
 * No
 *
 * Return Value:
 * No
 *
 * Example:
 * [] call ace_mk6mortar_fnc_rangeTablePageChange
 *
 * Public: No
 */
#include "script_component.hpp"

#define RANGE_TABLE       ((uiNamespace getVariable "WOG_D30_RangeTable_Dialog") displayCtrl 20001)
#define LIST_CHARGE       ((uiNamespace getVariable "WOG_D30_RangeTable_Dialog") displayCtrl 1501)

private ["_listBoxData", "_muzzleVelocity", "_airFriction", "_precalcArray", "_minDist", "_maxDist", "_maxHigh", "_center"];

_listBoxData = LIST_CHARGE lbData (lbCurSel LIST_CHARGE);
if (isNil "_listBoxData" || {_listBoxData == ""}) exitWith {hint "lbCurSel out of bounds or no data";};
_muzzleVelocity = parseNumber _listBoxData;

switch (_muzzleVelocity) do
{
	case 387: {_minDist = 2650; _maxDist = 15250; _maxHigh = 9850;};
	case 353: {_minDist = 2250; _maxDist = 12700; _maxHigh = 8200;};
	case 316: {_minDist = 1800; _maxDist = 10150; _maxHigh = 6550;};
	case 274: {_minDist = 1350; _maxDist = 7650; _maxHigh = 4950;};
	case 224: {_minDist = 900; _maxDist = 5100; _maxHigh = 3300;};
	case 158: {_minDist = 450; _maxDist = 2500; _maxHigh = 1650;};
};
_precalcArray = [];
while {_minDist <= _maxDist} do
{
	_precalcArray pushBack [
		str _minDist,
		str (floor((atan((_muzzleVelocity^2-sqrt(_muzzleVelocity^4-9.81*((9.81*_minDist^2)+(2*0*_muzzleVelocity^2))))/(9.81*_minDist)))*6000/360)),
		if (finite (floor(abs (((atan((_muzzleVelocity^2-sqrt(_muzzleVelocity^4-9.81*((9.81*_minDist^2)+(2*0*_muzzleVelocity^2))))/(9.81*_minDist))) - (atan((_muzzleVelocity^2-sqrt(_muzzleVelocity^4-9.81*((9.81*_minDist^2)+(2*(-100)*_muzzleVelocity^2))))/(9.81*_minDist))))*6000/360)))) then
		{str (floor(abs (((atan((_muzzleVelocity^2-sqrt(_muzzleVelocity^4-9.81*((9.81*_minDist^2)+(2*0*_muzzleVelocity^2))))/(9.81*_minDist))) - (atan((_muzzleVelocity^2-sqrt(_muzzleVelocity^4-9.81*((9.81*_minDist^2)+(2*(-100)*_muzzleVelocity^2))))/(9.81*_minDist))))*6000/360)))} else {"--"},
		"--",
		(2*_muzzleVelocity*(sin (atan((_muzzleVelocity^2-sqrt(_muzzleVelocity^4-9.81*((9.81*_minDist^2)+(2*0*_muzzleVelocity^2))))/(9.81*_minDist))))/9.81) toFixed 1,
		"--", "--", "--", "--", "--", "--", "--"
	];
	_minDist = _minDist + 50;
};
//max distance
_precalcArray pushBack [
	str (floor(_muzzleVelocity * _muzzleVelocity / 9.81)),
	str (floor(45*6000/360)),
	str (floor (abs((45 - atan((_muzzleVelocity^2-sqrt(_muzzleVelocity^4-9.81*((9.81*(_muzzleVelocity * _muzzleVelocity / 9.81)^2)+(2*(-100)*_muzzleVelocity^2))))/(9.81*(_muzzleVelocity * _muzzleVelocity / 9.81))))*6000/360))),
	"--",
	(2*_muzzleVelocity*(sin 45)/9.81) toFixed 1,
	"--", "--", "--", "--", "--", "--", "--"
];
_center = (count _precalcArray) - 1;

while {_maxDist >= _maxHigh} do
{
	_precalcArray pushBack [
		str _maxDist,
		str (floor((atan((_muzzleVelocity^2+sqrt(_muzzleVelocity^4-9.81*((9.81*_maxDist^2)+(2*0*_muzzleVelocity^2))))/(9.81*_maxDist)))*6000/360)),
		if (finite (floor(abs (((atan((_muzzleVelocity^2+sqrt(_muzzleVelocity^4-9.81*((9.81*_maxDist^2)+(2*0*_muzzleVelocity^2))))/(9.81*_maxDist))) - (atan((_muzzleVelocity^2+sqrt(_muzzleVelocity^4-9.81*((9.81*_maxDist^2)+(2*(-100)*_muzzleVelocity^2))))/(9.81*_maxDist))))*6000/360)))) then
		{str (floor(abs (((atan((_muzzleVelocity^2+sqrt(_muzzleVelocity^4-9.81*((9.81*_maxDist^2)+(2*0*_muzzleVelocity^2))))/(9.81*_maxDist))) - (atan((_muzzleVelocity^2+sqrt(_muzzleVelocity^4-9.81*((9.81*_maxDist^2)+(2*(-100)*_muzzleVelocity^2))))/(9.81*_maxDist))))*6000/360)))} else {"--"},
		"--",
		(2*_muzzleVelocity*(sin (atan((_muzzleVelocity^2+sqrt(_muzzleVelocity^4-9.81*((9.81*_maxDist^2)+(2*0*_muzzleVelocity^2))))/(9.81*_maxDist))))/9.81) toFixed 1,
		"--", "--", "--", "--", "--", "--", "--"
	];
	_maxDist = _maxDist - 50;
};



lnbClear RANGE_TABLE;
{
    RANGE_TABLE lnbAddRow _x;
} forEach _precalcArray;

//put dummy line at end because scrolling is fucked and can't see last line
RANGE_TABLE lnbAddRow ["", "", "", "", "", "", "", "", "", "", "", ""];
for "_i" from 0 to 11 do
{
	RANGE_TABLE lnbSetPictureColor [[_center,_i], [0,0,0,0.2]];
};
