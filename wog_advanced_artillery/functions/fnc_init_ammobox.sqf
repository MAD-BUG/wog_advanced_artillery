if !(local ((_this select 0) select 0)) exitWith {};
private _type = _this select 1;
private _box = (_this select 0) select 0;
switch (_type) do
{
	case 1: {
		_box setVariable ['WOG_122_boxParams', ['wog_mag_of462_dummy', 'wog_mag_of462_dummy', 'wog_mag_D30_charge_4_dummy', 'wog_mag_D30_charge_4_dummy'], true];
		_box animate ["shell_3bk13_1_hide", 1, true];
		_box animate ["shell_3bk13_2_hide", 1, true];
	};
	case 2: {
		_box setVariable ['WOG_122_boxParams', ['wog_mag_3bk13_dummy', 'wog_mag_3bk13_dummy', 'wog_mag_D30_charge_full_dummy', 'wog_mag_D30_charge_full_dummy'], true];
		_box animate ["shell_1_hide", 1, true];
		_box animate ["shell_2_hide", 1, true];
	};
};
