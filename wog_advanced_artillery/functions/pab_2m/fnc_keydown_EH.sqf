if ((_this select 1) == 203) exitWith {[_this select 2,_this select 3,_this select 4,1] call wog_fnc_PAB_2M_base_traverse;};  //LEFT_arrow
if ((_this select 1) == 205) exitWith {[_this select 2,_this select 3,_this select 4,-1] call wog_fnc_PAB_2M_base_traverse;};  //RIGHT_arrow
if ((_this select 1) == 44) exitWith {[_this select 2,_this select 4,1] call wog_fnc_PAB_2M_uglomer_rotation;};  //Z
if ((_this select 1) == 45) exitWith {[_this select 2,_this select 4,-1] call wog_fnc_PAB_2M_uglomer_rotation;};  //X
