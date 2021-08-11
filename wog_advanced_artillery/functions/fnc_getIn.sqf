if !(hasInterface) exitWith {};
if ((_this select 2) != player) exitWith {};
if ((_this select 1) != "gunner") exitWith {};
private "_handle";
if (typeOf (_this select 0) == "wog_pab_2m") then
{
	_handle = (findDisplay 46) displayAddEventHandler ["KeyDown", {(_this + [vehicle player]) call wog_fnc_PAB_2M_keydown_EH}];
	//player setVariable ["wog_advanced_artillery_pab_2m_base_phase", (_this select 0) animationSourcePhase "base_rotation_source"];
	_handleCompass = [{
		private ["_gun_dir", "_gun"];
		_gun = vehicle player;
		_gun_dir = (AGLToASL (_gun modelToWorld (_gun selectionPosition "south_point"))) getDir (AGLToASL (_gun modelToWorld (_gun selectionPosition "north_point")));
		if (_gun_dir < 180) then
		{
			_gun animateSource ["compass_arrow_rotation_source", linearConversion [0,5,_gun_dir,0,500,true]];
		} else
		{
			_gun animateSource ["compass_arrow_rotation_source", linearConversion [355,360,_gun_dir,-500,0,true]];
		};
	}, 0.1, [_this select 0]] call CBA_fnc_addPerFrameHandler;
	player setVariable ["wog_advanced_artillery_gunner_handleCompass", _handleCompass];
} else
{
_handle = (findDisplay 46) displayAddEventHandler ["KeyDown", {(_this + [vehicle player]) call wog_fnc_D30_keydown_EH}];
};
player setVariable ["wog_advanced_artillery_gunner_handle", _handle];