private ["_phase", "_newPhase", "_gun","_mult","_dir"];
_gun = vehicle player;

_dir = _this select 3;	// +1/-1
_mult = 1;

if (_this select 0) then {_mult=_mult*10};	// shift
if (_this select 2) then {_mult=_mult*0.5};	// alt

_phase = _gun animationPhase "mainTurret";
_newPhase = _phase+_dir*_mult;
_gun animate ["mainTurret", _newPhase];
_gun animate ["handlehorizont", _newPhase];
_gun animate ["handlehorizont2", _newPhase];
_gun setVariable ["mainTurret",_newPhase];

//point1 setPosASL (AGLToASL (gun1 modelToWorld (gun1 selectionPosition "konec hlavne")));
//point2 setPosASL (AGLToASL (gun1 modelToWorld (gun1 selectionPosition "usti hlavne")));