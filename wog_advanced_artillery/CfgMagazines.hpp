class CfgMagazines
{
	/*
	class Default;

	class CA_Magazine;

	class D30_test_round: CA_Magazine 
	{
		scope = 2; /// or 2, to be precise
		displayName = "D-30 122mm shell";
		//picture = "\A3\Weapons_F\Data\placeholder_co.paa"; /// just some icon
		model = "wog_advanced_artillery\ammobox_122\wog_he_122.p3d";
		ammo = "Sh_120mm_HE";
		count = 1; /// 30 rounds is enough
		initSpeed = 795; /// standard muzzle speed
		tracersEvery = 0; /// disable tracers by default
		lastRoundsTracer = 4; /// tracers to track low ammo
		descriptionShort = "Used to shoot test bullets"; /// on mouse-over in Inventory
		magazineGroup[]	= {"test_mag_group"}; /// all magazines in the same group may be used in weapon that has the group defined as compatible
	};
	
	*/
	
	class 32Rnd_155mm_Mo_shells;
	//Dummies
	//Shells
	class wog_mag_of462_dummy: 32Rnd_155mm_Mo_shells
	{
		scope = 2;
		displayName = "$STR_WOG_advanced_artillery_Shell_OF462_displayName";
        displayNameShort = "";
        descriptionShort = "Используется в 122мм гаубице Д-30";
		picture = "\wog_advanced_artillery\resource\data\HE_122mm_icon";
		model = "wog_advanced_artillery\ammobox_122\wog_he_122.p3d";
		ammo = "rhs_ammo_of462";
		count = 1;
		nameSound = "heat";
		//initSpeed = 651;
		rhs_magazineIndex=3;
		muzzleImpulseFactor = 0.1;
		mass = 128;
	};
	class wog_mag_3bk13_dummy: wog_mag_of462_dummy
	{
		displayName = "$STR_WOG_advanced_artillery_Shell_3BK13_displayName";
		picture = "\wog_advanced_artillery\resource\data\3bk13_icon";
		model = "wog_advanced_artillery\ammobox_122\3bk13.p3d";
		ammo = "rhs_ammo_bk13";
	};
	//Charges
	class wog_mag_D30_charge_full_dummy: 32Rnd_155mm_Mo_shells
	{
		displayName = "$STR_WOG_advanced_artillery_ChargeFull_displayName";
        displayNameShort = "";
        descriptionShort = "Используется в 122мм гаубице Д-30";
		picture = "\wog_advanced_artillery\resource\data\casing_122mm_icon";
		model = "wog_advanced_artillery\ammobox_122\rhs_casing_122mm.p3d";
		ammo = "";
		mass = 128;
	};
	class wog_mag_D30_charge_reduced_dummy: wog_mag_D30_charge_full_dummy
	{
		displayName = "$STR_WOG_advanced_artillery_ChargeReduced_displayName";
	};
	class wog_mag_D30_charge_1_dummy: wog_mag_D30_charge_full_dummy
	{
		displayName = "$STR_WOG_advanced_artillery_ChargeI_displayName";
	};
	class wog_mag_D30_charge_2_dummy: wog_mag_D30_charge_full_dummy
	{
		displayName = "$STR_WOG_advanced_artillery_ChargeII_displayName";
	};
	class wog_mag_D30_charge_3_dummy: wog_mag_D30_charge_full_dummy
	{
		displayName = "$STR_WOG_advanced_artillery_ChargeIII_displayName";
	};
	class wog_mag_D30_charge_4_dummy: wog_mag_D30_charge_full_dummy
	{
		displayName = "$STR_WOG_advanced_artillery_ChargeIV_displayName";
	};
	/*--------------------------------------------------------------------------------------*/
	//D-30 mags
	class wog_mag_of462_charge_full: wog_mag_of462_dummy
	{
		displayNameShort = "$STR_WOG_advanced_artillery_charge_full";
		displayName = "ОФ-462Ж (Полный)";
		scope = 2;
		ammo = "wog_ammo_of462_charge_full";
		initSpeed = 387; //15300m
	};
	class wog_mag_of462_charge_reduced: wog_mag_of462_dummy
	{
		displayNameShort = "$STR_WOG_advanced_artillery_charge_reduced";
		displayName = "ОФ-462Ж (Уменьшенный)";
		scope = 2;
		ammo = "wog_ammo_of462_charge_reduced";
		initSpeed = 353; //12750m
	};
	class wog_mag_of462_charge_1: wog_mag_of462_dummy
	{
		displayNameShort = "$STR_WOG_advanced_artillery_charge_one";
		displayName = "ОФ-462Ж (Первый)";
		scope = 2;
		ammo = "wog_ammo_of462_charge_1";
		initSpeed = 316; //10200m
	};
	class wog_mag_of462_charge_2: wog_mag_of462_dummy
	{
		displayNameShort = "$STR_WOG_advanced_artillery_charge_two";
		displayName = "ОФ-462Ж (Второй)";
		scope = 2;
		ammo = "wog_ammo_of462_charge_2";
		initSpeed = 274; //7650m
	};
	class wog_mag_of462_charge_3: wog_mag_of462_dummy
	{
		displayNameShort = "$STR_WOG_advanced_artillery_charge_three";
		displayName = "ОФ-462Ж (Третий)";
		scope = 2;
		ammo = "wog_ammo_of462_charge_3";
		initSpeed = 224; //5100m
	};
	class wog_mag_of462_charge_4: wog_mag_of462_dummy
	{
		displayNameShort = "$STR_WOG_advanced_artillery_charge_four";
		displayName = "ОФ-462Ж (Четвертый)";
		scope = 2;
		ammo = "wog_ammo_of462_charge_4";
		initSpeed = 158; //2550m
	};
	///////////////////////////////////////////////////////////////////////////////
	class wog_mag_3bk13_charge_full: wog_mag_3bk13_dummy
	{
		displayNameShort = "$STR_WOG_advanced_artillery_charge_full";
		displayName = "3БК13 (Полный)";
		scope = 2;
		ammo = "rhs_ammo_bk13";
		initSpeed = 726; //726
	};
};