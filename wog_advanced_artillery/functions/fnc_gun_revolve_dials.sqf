private ["_phase", "_newPhase", "_gun","_mult","_dir","_milSys"];
_gun = vehicle player;

_dir = _this select 2;	// +1/-1

_mult = 1;

if (_this select 0) then {_mult=_mult*5};	// shift
if (_this select 1) then {_mult=_mult*10};	// ctrl

_phase = _gun animationSourcePhase "OpticRevolve";
_newPhase = round(_phase+_dir*_mult);
_gun animateSource ["OpticRevolve", _newPhase];
_gun setVariable ["OpticRevolve",_newPhase];