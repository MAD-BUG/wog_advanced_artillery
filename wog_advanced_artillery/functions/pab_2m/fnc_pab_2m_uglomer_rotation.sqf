
private ["_phase", "_newPhase", "_gun","_mult","_dir"];
_gun = vehicle player;

_dir = _this select 2;	// +1/-1
_mult = 1;

if (_this select 0) then {_mult=_mult*10};	// shift
if (_this select 1) then {_mult=_mult*0.5};	// alt

_phase = _gun animationSourcePhase "uglomer_rotation_source";
_newPhase = _phase+_dir*_mult;
_gun animateSource ["uglomer_rotation_source", _newPhase];