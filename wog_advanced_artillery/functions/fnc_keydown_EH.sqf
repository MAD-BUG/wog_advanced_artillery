if ((_this select 1) == 200) exitWith {[_this select 2,_this select 3,_this select 4,1] call wog_fnc_D30_elevate;};  //UP_arrow
if ((_this select 1) == 208) exitWith {[_this select 2,_this select 3,_this select 4,-1] call wog_fnc_D30_elevate;};  //DOWN_arrow
if ((_this select 1) == 203) exitWith {[_this select 2,_this select 3,_this select 4,1] call wog_fnc_D30_traverse;};  //LEFT_arrow
if ((_this select 1) == 205) exitWith {[_this select 2,_this select 3,_this select 4,-1] call wog_fnc_D30_traverse;};  //RIGHT_arrow
if ((_this select 1) == 44) exitWith {[_this select 2,_this select 3,1] call wog_fnc_D30_revolve_dials;};  //Z
if ((_this select 1) == 45) exitWith {[_this select 2,_this select 3,-1] call wog_fnc_D30_revolve_dials;};  //X
if ((_this select 1) == 201) exitWith {[_this select 2,_this select 3,1] call wog_fnc_D30_elevate_sight;};  //PgUp
if ((_this select 1) == 209) exitWith {[_this select 2,_this select 3,-1] call wog_fnc_D30_elevate_sight;};  //PgDn
if ((_this select 1) == 210) exitWith {[_this select 2,_this select 3,1] call wog_fnc_D30_elevate_dials;};  //Insert
if ((_this select 1) == 211) exitWith {[_this select 2,_this select 3,-1] call wog_fnc_D30_elevate_dials;};  //Delete
if ((_this select 1) == 31) exitWith {
	if (isNull(uiNamespace getVariable ["wog_d30_sight_gui", displayNull]) && (vehicle player != player)) then
	{
		("wog_d30_sight_gui_layer" call BIS_fnc_rscLayer) cutRsc ["WOG_ARTY_D726_45", "PLAIN", 2, false]
	} else 
	{
		("wog_d30_sight_gui_layer" call BIS_fnc_rscLayer) cutText ["","PLAIN"];
	};
}; //S