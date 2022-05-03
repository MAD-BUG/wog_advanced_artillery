if ((_this select 1) == 203) exitWith {[_this select 2,_this select 3,_this select 4,1] call wog_fnc_PAB_2M_base_traverse;};  //LEFT_arrow
if ((_this select 1) == 205) exitWith {[_this select 2,_this select 3,_this select 4,-1] call wog_fnc_PAB_2M_base_traverse;};  //RIGHT_arrow
if ((_this select 1) == 44) exitWith {[_this select 2,_this select 4,1] call wog_fnc_PAB_2M_uglomer_rotation;};  //Z
if ((_this select 1) == 45) exitWith {[_this select 2,_this select 4,-1] call wog_fnc_PAB_2M_uglomer_rotation;};  //X
if ((_this select 1) == 17) exitWith {[_this select 2,_this select 3,_this select 4,-1,0] call wog_fnc_PAB_2M_base_leveling;};  //W
if ((_this select 1) == 31) exitWith {[_this select 2,_this select 3,_this select 4,1,0] call wog_fnc_PAB_2M_base_leveling;};  //S
if ((_this select 1) == 30) exitWith {[_this select 2,_this select 3,_this select 4,0,-1] call wog_fnc_PAB_2M_base_leveling;};  //A
if ((_this select 1) == 32) exitWith {[_this select 2,_this select 3,_this select 4,0,1] call wog_fnc_PAB_2M_base_leveling;};  //D