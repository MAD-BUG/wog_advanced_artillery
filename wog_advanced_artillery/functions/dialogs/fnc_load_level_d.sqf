params ["_display"];
private ["_long_level_ctrl", "_lat_level_ctrl", "_gun"];
_gun = player getVariable "WOG_D30_gunObj";
_long_level_ctrl = _display displayCtrl 1951;
_lat_level_ctrl = _display displayCtrl 1950;
ctrlEnable [1950, false];
ctrlEnable [1951, false];
sliderSetPosition [3900, _gun animationSourcePhase "leftLiftT_source"];
sliderSetPosition [3901, _gun animationSourcePhase "rightLiftT_source"];
sliderSetPosition [3902, _gun animationSourcePhase "mainLiftT_source"];
[_gun] spawn {
	params ["_gun"];
	{_x action ["Eject", _gun]; unassignVehicle _x}foreach (crew _gun);
	[_gun, true] remoteExecCall ["lock", _gun];
	if !(local _gun) then
	{
		["wog_advanced_artillery_changeLocality", [_gun, player]] call CBA_fnc_serverEvent;
	};
	while {dialog} do {
		["ace_common_fnc_fixFloating", _this select 0, _this select 0] call CBA_fnc_targetEvent;
		//[_this select 0] call ace_common_fnc_fixFloating;
		sleep 1;
	};
	[_gun, false] remoteExecCall ["lock", _gun];
	_gun lock false;
	if (local _gun) then
	{
		["wog_advanced_artillery_changeLocality", [_gun]] call CBA_fnc_serverEvent;
	};
};
[_long_level_ctrl, _lat_level_ctrl] spawn {
	params ["_longCtrl", "_latCtrl"];
	while {dialog} do {
		private ["_long", "_lat", "_gun"];
		_gun = player getVariable "WOG_D30_gunObj";
		_long = asin ((AGLToASL (_gun modelToWorld (_gun selectionPosition "long_level_2")) vectorFromTo AGLToASL (_gun modelToWorld (_gun selectionPosition "long_level_1"))) select 2);
		_lat = asin ((AGLToASL (_gun modelToWorld (_gun selectionPosition "lat_level_1")) vectorFromTo AGLToASL (_gun modelToWorld (_gun selectionPosition "lat_level_2"))) select 2);
		sliderSetPosition [1950, linearConversion [-1, 1, _lat, -1, 1, true]]; //поперечный
		sliderSetPosition [1951, linearConversion [-1, 1, _long, -1, 1, true]]; //продольный
		_longCtrl ctrlSetForegroundColor [
		linearConversion [0, 1, abs(_long), 0, 1, true],
		linearConversion [0, 1, abs(_long), 1, 0, true],
		0,
		1];
		_latCtrl ctrlSetForegroundColor [
		linearConversion [0, 1, abs(_lat), 0, 1, true],
		linearConversion [0, 1, abs(_lat), 1, 0, true],
		0,
		1];
	};
};