params ["_vehicle", "_unit"];

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "AmovPercMstpSrasWrflDnon_diary";
};

[{
    params ["_vehicle"];
	if isNull(gunner _vehicle) then
	{
		private _pad = _vehicle getVariable ["wog_pab_2m_helper_pad", objNull];
		if !isNull(_pad) then
		{
			detach _vehicle;
			deleteVehicle _pad;
		};

		private _pos = getPosATL _vehicle;
		private _holder = createVehicle ["WeaponHolder_Single_F", _pos, [], 0, "NONE"];
		_holder addBackpackCargoGlobal ["WOG_pab_2m_bag", 1];
		_holder setPosATL _pos;
		
		deleteVehicle _vehicle;
	} else
	{
		hint "Vehicle is not empty!";
	};
}, [_vehicle], 1, 0]call CBA_fnc_waitAndExecute;