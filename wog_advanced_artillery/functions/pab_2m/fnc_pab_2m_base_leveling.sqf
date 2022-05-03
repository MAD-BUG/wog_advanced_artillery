
private ["_phase", "_newPhase", "_gun","_mult","_dir"];
_gun = vehicle player;

if ((_this select 3) != 0) then
{
	_dir = _this select 3;
	_mult = 0.001;

	if (_this select 0) then {_mult=_mult*10};	// shift
	if (_this select 2) then {_mult=_mult*0.5};	// alt
	_phase = _gun animationSourcePhase "sphere_pitch_source";
	_newPhase = _phase+_dir*_mult;
	_gun animateSource ["sphere_pitch_source", _newPhase];
};

if ((_this select 4) != 0) then
{
	_dir = _this select 4;
	_mult = 0.001;

	if (_this select 0) then {_mult=_mult*10};	// shift
	if (_this select 2) then {_mult=_mult*0.5};	// alt
	_phase = _gun animationSourcePhase "sphere_roll_source";
	_newPhase = _phase+_dir*_mult;
	_gun animateSource ["sphere_roll_source", _newPhase];
};

//player setVariable ["wog_advanced_artillery_pab_2m_base_phase",_newPhase];