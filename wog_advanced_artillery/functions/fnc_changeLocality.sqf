/*
	WOG_fnc_changeLocality
*/

if !(isServer) exitWith {};
params ["_veh", ["_unit", 2]];
private "_newOwner";
if (typeName _unit == "SCALAR") then
{
	_newOwner = 2;
} else
{
	_newOwner = owner _unit;
};

_veh setOwner _newOwner;