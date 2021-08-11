[_this select 0,_this select 1] spawn {

	params["_t","_p"];

	if(_p == 1)then{
		{_x action ["Eject", _t]; unassignVehicle _x}foreach (crew _t);
		[_t, true] remoteExecCall ["lock", _t];
		{_t animate [_x select 0, _x select 1]}foreach [["rightT",2.3],["leftT",2.3],["szpilki",0.7]];
		sleep 2;
		{_t animate [_x select 0, _x select 1]}foreach [["rightW",0.7],["leftW",0.7]];
		_t animate ["MainTurret", 0];
		_t animate ["MainGun", 0];
		//waitUntil {((_t animationPhase "MainTurret") == 0) && ((_t animationPhase "MainGun") == 0)};
		_t animate ["mainGunT",-157.563];
		_t setmass 2600;
	}else{
		{_t animate [_x select 0, _x select 1]}foreach [["rightW",0],["leftW",0]];
		sleep 1;
		{_t animate [_x select 0, _x select 1]}foreach [["rightT",0],["leftT",0]];
		sleep 3;
		[_t, false] remoteExecCall ["lock", _t];
		_t lock false;
		_t animate ["szpilki",0];
		_t animate ["mainGunT",0];
		//waitUntil {(_t animationPhase "mainGunT") == 0};
		_t setmass 3200;
	};
};