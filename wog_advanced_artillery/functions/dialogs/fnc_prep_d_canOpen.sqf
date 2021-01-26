#include "..\script_component.hpp"
private "_result";
_result = false;
{
	if (_x in (magazines player)) exitWith {_result = true;};
} forEach WOG_ADVANCED_ARTILLERY_CHARGES_ARRAY;
_result