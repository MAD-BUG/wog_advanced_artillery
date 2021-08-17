#include "..\script_component.hpp"

disableSerialization;
private ["_listCurrCtrl", "_listRequiredCtrl", "_availMags"];
uiNamespace setVariable ["WOG_ARTY_PREP_DIALOG", _this select 0];
_listCtrl = (_this select 0) displayCtrl 2100;
_listRequiredCtrl = (_this select 0) displayCtrl 3101;
//WOG_advanced_artillery_chargesArray = ["wog_mag_D30_charge_full_dummy", "wog_mag_D30_charge_reduced_dummy", "wog_mag_D30_charge_1_dummy", "wog_mag_D30_charge_2_dummy", "wog_mag_D30_charge_3_dummy", "wog_mag_D30_charge_4_dummy"];

_availMags = [];
_n = 0;
{
	if (_x in WOG_ADVANCED_ARTILLERY_CHARGES_ARRAY) then
	{
		_availMags pushBack _x;
		_listCtrl lbAdd (getText (configFile >> "CfgMagazines" >> _x >> "displayName"));
		_listCtrl lbSetData [_n, _x];
		_n=_n+1;
	};
} forEach magazines player;

wog_advanced_artillery_prep_update = {
	private ["_dialog", "_currCtrl", "_reqCtrl", "_finalArray"];
	_dialog = uiNamespace getVariable "WOG_ARTY_PREP_DIALOG";
	_currCtrl = _dialog displayCtrl 2100;
	_reqCtrl = _dialog displayCtrl 3101;
	lbClear _reqCtrl;
	_finalArray = WOG_ADVANCED_ARTILLERY_CHARGES_ARRAY;
	_finalArray = _finalArray - [(_currCtrl lbData (lbCurSel _currCtrl))];
	_i = 0;
	{
		_reqCtrl lbAdd (getText (configFile >> "CfgMagazines" >> _x >> "displayName"));
		_reqCtrl lbSetData [_i, _x];
		_i =_i+1;
	} forEach _finalArray;
};

wog_advanced_artillery_start_prep = {
	private ["_dialog", "_currMag", "_reqMag"];
	_dialog = uiNamespace getVariable "WOG_ARTY_PREP_DIALOG";
	_currMag = (_dialog displayCtrl 2100) lbData (lbCurSel (_dialog displayCtrl 2100));
	_reqMag = (_dialog displayCtrl 3101) lbData (lbCurSel (_dialog displayCtrl 3101));
	if ((_currMag == "") || (_reqMag == "")) exitWith {hint "Заполните поля!";};
	if !(_currMag in (magazines player)) exitWith {hint "Отсутствует заряд в инвентаре!";};
	[2, [_currMag, _reqMag], {
		if !((_args select 0) in (magazines player)) exitWith {hint "Отсутствует заряд в инвентаре!";};
		player removeItem (_args select 0);
		player addItemToBackpack (_args select 1);
	}, {}, (localize "STR_WOG_advanced_artillery_Prep_charges_displayName") + "..."] call ace_common_fnc_progressBar;
};