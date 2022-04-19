params ["_vehicle", "_unit", "_itemClass"];

if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
    _unit playMove "AmovPercMstpSrasWrflDnon_diary";
};

[{
    params ["_vehicle", "_itemClass"];
	
	private _pos = getPosATL _vehicle;
	private _holder = createVehicle [_itemClass, _pos, [], 0, "NONE"];
	//_holder addItemCargoGlobal [_itemClass, 1];
	_holder setPosATL _pos;
	
	deleteVehicle _vehicle;
	
}, [_vehicle, _itemClass], 1, 0]call CBA_fnc_waitAndExecute;