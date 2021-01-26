private ["_phase", "_newPhase", "_gun","_mult","_dir"];
_gun = vehicle player;

_dir = _this select 2;	// +1/-1
_mult = 1;

if (_this select 0) then {_mult=_mult*10};	// shift
//if (_this select 1) then {_mult=_mult*10};	// ctrl

_phase = _gun animationSourcePhase "OpticElevate";
_newPhase = (round(_phase+_dir*_mult) min 1167) max 0;
_gun animateSource ["OpticElevate", _newPhase];
_gun setVariable ["OpticElevate",_newPhase];