if !(hasInterface) exitWith {};

_handle = (findDisplay 46) displayAddEventHandler ["KeyDown", {(_this + [vehicle player]) call wog_fnc_D30_keydown_EH}];
player setVariable ["wog_advanced_artillery_gunner_handle", _handle, true];