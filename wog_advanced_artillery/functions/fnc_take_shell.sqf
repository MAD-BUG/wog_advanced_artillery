#include "script_component.hpp"

params ["_box", "_type", "_pos"];
private ["_magClass", "_boxParam"];
_boxParam = _box getVariable ["WOG_122_boxParams", ["","","",""]];
_magClass = switch (_type) do
{
	case 1: {_boxParam select (_pos - 1)};
	case 2: {_boxParam select (_pos + 1)};
};
if (_magClass == "") exitWith {hint "Error!"};
if !(player canAddItemToBackpack [_magClass, 1]) exitWith {hint "Not enough space in backpack!"};

if (_type == 1) then
{
	switch (_pos) do
	{
		case 1: {
			switch (_magClass) do
			{
				case "wog_mag_of462_dummy": {_box animate ["shell_1_hide", 1, true];};
				case "wog_mag_3bk13_dummy": {_box animate ["shell_3bk13_1_hide", 1, true];};
			};	
		};
		case 2: {
			switch (_magClass) do
			{
				case "wog_mag_of462_dummy": {_box animate ["shell_2_hide", 1, true];};
				case "wog_mag_3bk13_dummy": {_box animate ["shell_3bk13_2_hide", 1, true];};
			};
		};
	};
	_box animate ["covering_1_hide", 1, true];
	_boxParam set [_pos - 1, ""];
	_box setVariable ["WOG_122_boxParams", _boxParam, true];
};

if (_type == 2) then
{
	switch (_pos) do
	{
		case 1: {_box animate ["charge_1_hide", 1, true]};
		case 2: {_box animate ["charge_2_hide", 1, true]};
	};
	_box animate ["covering_2_hide", 1, true];
	_boxParam set [_pos + 1, ""];
	_box setVariable ["WOG_122_boxParams", _boxParam, true];
};

player addItemToBackpack _magClass;