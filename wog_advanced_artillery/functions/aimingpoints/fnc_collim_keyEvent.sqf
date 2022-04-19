_event = _this select 0;
_parameters = _this select 1;

//if (GVAR(presstime) == time) exitwith {false};
//GVAR(presstime) = time;
switch(_event) do {
	case "KeyDown": {
		_key = _parameters select 1;
		_shift = if (_parameters select 2) then {0.5} else {0.25};
		switch(_key) do {
			case 0xCD: { acex_aimingpoints_collimatorAlignHorz = acex_aimingpoints_collimatorAlignHorz - _shift; };
			case 0xCB: { acex_aimingpoints_collimatorAlignHorz = acex_aimingpoints_collimatorAlignHorz + _shift; };
			case 0xD0: { acex_aimingpoints_collimatorAlignVert = acex_aimingpoints_collimatorAlignVert + _shift; };
			case 0xC8: { acex_aimingpoints_collimatorAlignVert = acex_aimingpoints_collimatorAlignVert - _shift; };
			case 1:  { acex_aimingpoints_aligning = false; };
		};
	};
};
if ((acex_aligningCollimator animationPhase "collimator_rotation") != acex_aimingpoints_collimatorAlignHorz) then {
	acex_aligningCollimator animate ["collimator_rotation", acex_aimingpoints_collimatorAlignHorz];
};
if ((acex_aligningCollimator animationPhase "collimator_elevation") != acex_aimingpoints_collimatorAlignVert) then {
	acex_aligningCollimator animate ["collimator_elevation", acex_aimingpoints_collimatorAlignVert];
};
!(acex_aimingpoints_aligning)