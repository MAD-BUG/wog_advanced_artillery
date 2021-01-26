private ["_phase", "_newPhase", "_gun","_mult","_dir"];
_gun = vehicle player;

_dir = _this select 3;	// +1/-1
_mult = 1;

if (_this select 0) then {_mult=_mult*5};	// shift
if (_this select 2) then {_mult=_mult*0.5};	// alt

_phase = _gun animationPhase "MainGun";
_newPhase = ((_phase+_dir*_mult) min 1167) max -117;
_gun animate ["MainGun", _newPhase];
_gun animate ["handleelevation", _newPhase];
_gun animate ["handleelevation2", _newPhase];
_gun setVariable ["mainGun",_newPhase];