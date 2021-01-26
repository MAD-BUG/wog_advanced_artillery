disableSerialization;
private ["_unit","_def", "_val_left", "_val_right", "_display","_el","_delta_el", "_el_dial", "_milSys", "_digits", "_bubblePos"];
_unit = vehicle player;
_milSys = 6000;
uiNamespace setVariable ["wog_d30_sight_gui", _this select 0];
_display = _this select 0;
if ((isNull _display) || (_unit != (vehicle player))) exitWith {};

waitUntil {
	//deflection
	_def = _unit animationSourcePhase "OpticRevolve";
	// US mils to Russian mils
	_def = round (_def + _milSys/2) % _milSys;
	if (_def<0) then {_def=_def+_milSys};
	
	// bubble level
	_el = floor ((asin ((_unit weaponDirection (weapons _unit select 0)) select 2)) / 360 * _milSys); // прицел фактический, игроку неизвестен
	_el_dial = round(_unit animationSourcePhase "OpticElevate"); // прицел, установленный на барабанчике/ручке
	_delta_el = _el_dial - _el; // отклонение продольного уровня фактическое
	_digits = [_el_dial, 4] call ACE_common_fnc_numberToDigits;
	_val_left = if (str (_digits select 0) == "0") then {str (_digits select 1)} else {str (_digits select 0) + str (_digits select 1)};
	_val_right = str (_digits select 2) + str (_digits select 3);
	(_display displayCtrl 77704) ctrlSetText _val_left;
	(_display displayCtrl 77705) ctrlSetText _val_right;
	
	//отражатель
	(_display displayCtrl 77706) ctrlSetText (str (round(_unit animationSourcePhase "OpticDialElevate")));
	
	//пузырьковый уровень
	_bubblePos = linearConversion [-10, 10, _delta_el, safeZoneY + safeZoneH * (730/2048), safeZoneY + safeZoneH * (866/2048), true];
	(_display displayCtrl 77708) ctrlSetPositionY _bubblePos;
	(_display displayCtrl 77708) ctrlCommit 0.5;
	
	// deflection	dial
	_digits = [_def, 4] call ACE_common_fnc_numberToDigits;
	_val_left = str (_digits select 0) + str (_digits select 1);
	_val_right = str (_digits select 2) + str (_digits select 3);
	(_display displayCtrl 77702) ctrlSetText _val_left;
	(_display displayCtrl 77703) ctrlSetText _val_right;
	if (vehicle player == player) then
	{
		("wog_d30_sight_gui_layer" call BIS_fnc_rscLayer) cutText ["","PLAIN"];
	};
	
	sleep 0.05;	
	isNull(uiNamespace getVariable ["wog_d30_sight_gui", displayNull])
};