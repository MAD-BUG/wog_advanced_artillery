private _particle2 = "#particlesource" createVehicleLocal (position (_this # 0));
_particle2 setParticleClass "WOG_casing122_particles";
_particle2 attachTo [(_this # 0), [0,0,0]];

sleep 10;
deleteVehicle _particle2;