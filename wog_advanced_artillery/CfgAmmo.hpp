//jsrs_sc_arty_flyby_soundshader

class CfgAmmo
{
	//some experimental stuff with air-burst fuze
	class rhs_ammo_of462;
	/*
	class wog_ammo_of462: rhs_ammo_of462
	{
		simulation = "shotSubmunitions";
		submunitionAmmo = "wog_ammo_of462_scripted";
		submunitionConeAngle = 30;
		submunitionConeType[] = {"poissondisc",1};
		triggerDistance = 100;
		deleteParentWhenTriggered = 1;
	};
	class wog_ammo_of462_scripted: rhs_ammo_of462
	{
		explosionTime = 0.001;
		explosionEffects = "HelicopterExplosionEffects2";
	};
	*/
	class wog_ammo_of462_charge_full: rhs_ammo_of462
	{
		soundFly[] = {"\wog_advanced_artillery\sounds\projectile_whistle_longer", 15, 1, 800};
	};
	class wog_ammo_of462_charge_reduced: rhs_ammo_of462
	{
		soundFly[] = {"\wog_advanced_artillery\sounds\projectile_whistle_longer", 15, 1, 750};
	};
	class wog_ammo_of462_charge_1: rhs_ammo_of462
	{
		soundFly[] = {"\wog_advanced_artillery\sounds\projectile_whistle_longer", 15, 1, 650};
	};
	class wog_ammo_of462_charge_2: rhs_ammo_of462
	{
		soundFly[] = {"\wog_advanced_artillery\sounds\projectile_whistle_longer", 15, 1, 600};
	};
	class wog_ammo_of462_charge_3: rhs_ammo_of462
	{
		soundFly[] = {"\wog_advanced_artillery\sounds\projectile_whistle_longer", 15, 1, 575};
	};
	class wog_ammo_of462_charge_4: rhs_ammo_of462
	{
		soundFly[] = {"\wog_advanced_artillery\sounds\projectile_whistle_longer", 15, 1, 550};
	};
};