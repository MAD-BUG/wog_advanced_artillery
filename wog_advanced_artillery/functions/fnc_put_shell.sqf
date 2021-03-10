#include "script_component.hpp"

params ["_box", "_type", "_pos"];
private ["_magClass", "_magArray", "_boxParam"];
_boxParam = _box getVariable ["WOG_122_boxParams", ["","","",""]];
_magArray = [];
_magClass = switch (_type) do
{
	case 1: {
		{
			if (_x in WOG_ADVANCED_ARTILLERY_SHELLS_ARRAY) then
			{
				_magArray pushBack _x;
			};
		} forEach (magazines player);
		_magArray
	};
	case 2: {
		{
			if (_x in WOG_ADVANCED_ARTILLERY_CHARGES_ARRAY) then
			{
				_magArray pushBack _x;
			};
		} forEach (magazines player);
		_magArray
	};
};

if (({_x in magazines player} count _magClass) == 0) exitWith {hint "No item to put in ammobox!"};

if (_type == 1) then
{
	switch (_pos) do
	{
		case 1: {
			switch (_magClass select 0) do
			{
				case "wog_mag_of462_dummy": {_box animate ["shell_1_hide", 0, true];};
				case "wog_mag_3bk13_dummy": {_box animate ["shell_3bk13_1_hide", 0, true];};
			};
		};
		case 2: {
			switch (_magClass select 0) do
			{
				case "wog_mag_of462_dummy": {_box animate ["shell_2_hide", 0, true];};
				case "wog_mag_3bk13_dummy": {_box animate ["shell_3bk13_2_hide", 0, true];};
			};
		};
	};
	if (((_box animationPhase "shell_1_hide" != 1) || (_box animationPhase "shell_3bk13_1_hide" != 1)) && ((_box animationPhase "shell_2_hide" != 1) || (_box animationPhase "shell_3bk13_2_hide" != 1))) then
	{
		_box animate ["covering_1_hide", 0, true];
	};
	_boxParam set [_pos - 1, _magClass select 0];
	_box setVariable ["WOG_122_boxParams", _boxParam, true];
};

if (_type == 2) then
{
	switch (_pos) do
	{
		case 1: {_box animate ["charge_1_hide", 0, true]};
		case 2: {_box animate ["charge_2_hide", 0, true]};
	};
	if ((_box animationPhase "charge_1_hide" != 1) && (_box animationPhase "charge_2_hide" != 1)) then
	{
		_box animate ["covering_2_hide", 0, true];
	};
	_boxParam set [_pos + 1, _magClass select 0];
	_box setVariable ["WOG_122_boxParams", _boxParam, true];
};

player removeItem (_magClass select 0);