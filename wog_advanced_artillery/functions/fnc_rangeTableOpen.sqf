/*
 * Author: PabstMirror
 * Opens the rangetable and fills the charge listbox.
 *
 * Arguments:
 * No
 *
 * Return Value:
 * No
 *
 * Example:
 * [] call ace_mk6mortar_fnc_rangeTableOpen
 *
 * Public: No
 */
//#include "script_component.hpp"

#define LIST_CHARGE ((uiNamespace getVariable "WOG_D30_RangeTable_Dialog") displayCtrl 1501)

private ["_weaponName", "_magazines", "_index"];

// _weaponName = getArray (configFile >> "CfgVehicles" >> typeOf (vehicle player) >> "Turrets" >> "MainTurret" >> "weapons") select 0;
_weaponName = "wog_weap_D30";

createDialog "WOG_D30_RangeTable_Dialog";
if (isNull (uiNamespace getVariable ["WOG_D30_RangeTable_Dialog", displayNull])) exitWith {hint "Dialog failed to open";};

//Get Magazine Types
_magazines = getArray (configFile >> "CfgWeapons" >> _weaponName >> "magazines");

//For now just get settings from first mag, all rounds have same flight characteristics:
if ((count _magazines) < 1) exitWith {hint "No Magazines for weapon";};

_index = 0;
{
	LIST_CHARGE lbAdd format ["%1", getText (configFile >> "CfgMagazines" >> _x >> "displayName")];
	LIST_CHARGE lbSetData [_index, str (getNumber (configFile >> "CfgMagazines" >> _x >> "initSpeed"))];
	_index = _index + 1;
} forEach _magazines;

LIST_CHARGE lbSetCurSel 0;
