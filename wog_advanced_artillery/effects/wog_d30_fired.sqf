/*
	spent case ejection

	a: reyhard
*/
params["_v","","","","_ammo"];

if(!local _v)exitWith{};

//if (!(_ammo isKindOf 'ShellBase')) exitWith {};

_v setVariable ["WOG_122_shell_loaded", "", true];
_v setVariable ["WOG_122_casing_loaded", "", true];

//Recoil effect
private _phase = _v animationPhase "MainGun";
private _newPhase = ((_phase+(selectRandom [-1, 1])*(selectRandom [0, 1, 2])) min 1167) max -117;
_v animate ["MainGun", _newPhase];

_phase = _v animationPhase "mainTurret";
_newPhase = _phase+(selectRandom [-1, 1])*(selectRandom [0, 1, 2]);
_v animate ["mainTurret", _newPhase];

_v animateSource ["RecoilAnim",1,true];
waitUntil {(_v animationSourcePhase "RecoilAnim") == 1};
sleep 0.1;
_v animateSource ["RecoilAnim",0];

waitUntil {(_v animationPhase "recoil_BEGIN")< 0.98};

private _shposmem1 = _v selectionPosition ["ejector_pos", "memory"];
private _shposmem2 = _v selectionPosition ["ejector_dir", "memory"];

private _ejectWorldPos = _v modelToWorldVisual _shposmem1;
private _ejectWorldDir = _v modelToWorldVisual _shposmem2;

private _vector = (_ejectWorldPos vectorFromTo _ejectWorldDir) vectorMultiply (32.2+random(12));
sleep 1.5;
_v animateSource ["klin_open_source", 1, true];
_v animateSource ["shell_loading", 0, true];
_v animateSource ["shell_3bk13_loading", 0, true];
_v animateSource ["casing_loading", 0, true];
sleep 0.3;
private _particle = "wog_casing_122mm_used" createVehicle _ejectWorldPos;
//private _particle2 = "#particlesource" createVehicleLocal (position _particle);
//_particle2 setParticleClass "WOG_casing122_particles";
//_particle2 attachTo [_particle, [0,0,0]];

_particle disableCollisionWith _v;
_particle setposASL (ATLtoASL _ejectWorldDir);

_particle setVectorDirAndUp [
	_vector,
	_vector vectorCrossProduct [-(_vector # 1), _vector # 0, 0]
];
_particle addForce [_vector,[0,0,0]];
_particle addTorque [random[-2,0,2],random[-2,0,2],random[-2,0,2]];

private _sleepTime = _v getVariable ["rhs_caseDeleteTime",120];
if(_sleepTime != -1)then{
	//sleep (15 min _sleepTime);
	//deleteVehicle _particle2;
	//sleep (0 max (_sleepTime - 15));
	sleep _sleepTime;
	deleteVehicle _particle;
};
