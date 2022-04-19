class CfgPatches {
	class wog_advanced_artillery {
        name = "WOG Advanced Artillery";
        units[] = {"Item_Arty_AimingPost", "acex_artillery_Collimator_Item"};
        weapons[] = {"WOG_RangeTable_D30", "acex_artillery_AimingPost", "acex_artillery_Collimator"};
        requiredVersion = 1.60;
        requiredAddons[] = {"a3_weapons_f", "ace_interaction", "rhs_c_heavyweapons", "A3_Static_F_Mortar_01", "ruPal_RHS_to_ACE", "rhsgref_c_vehicles_ret", "ace_spottingscope", "rhs_main", "ace_maptools"};
        author = "Lex";
    };
};

#include "CfgFunctions.hpp"
#include "CfgMagazines.hpp"
#include "CfgSounds.hpp"
#include "CfgAmmo.hpp"
#include "CfgMoves.hpp"
#include "resource\common.hpp"
#include "resource\RscInterface.hpp"
#include "resource\RscD30RangeTable.hpp"
#include "RscInGameUI.hpp"
#include "functions\script_component.hpp"
#include "\x\cba\addons\main\script_macros_common.hpp"

class Extended_PreInit_EventHandlers
{
	class ace_maptools
	{
		init = "ace_maptools_fnc_isInsideMapTool = compileScript ['wog_advanced_artillery\functions\fnc_isInsideMapTool.sqf', true]; ace_maptools_fnc_updateMapToolMarkers = compileScript ['wog_advanced_artillery\functions\fnc_updateMapToolMarkers.sqf', true]; call compileScript ['\z\ace\addons\maptools\XEH_preInit.sqf']";
	};
};

class Extended_PostInit_EventHandlers
{
    class wog_advanced_artillery
	{
        init = "call compile preProcessFileLineNumbers 'wog_advanced_artillery\XEH_postInit.sqf'";
    };
};

class CfgCloudlets
{
	class SmallFireS;
	class WOG_casing122_particles: SmallFireS
	{
		lifeTime = 2;
		lifeTimeVar = 5;
		interval = 0.01;
		volume = 0.04;
		weight = 0.05;
		moveVelocity[] = {0,0.05,0};
		MoveVelocityVar[] = {0.01,0.2,0.01};
		size[] = {0.55,0.55};
		color[] = {{0.5,0.5,0.5,0.03},{0.55,0.55,0.55,0.04},{0.65,0.65,0.65,0.03}};
		colorVar[] = {0,0,0,0.08};
		rubbing = 0.02;
	};
	class WOG_D30_Fired_Particles: WOG_casing122_particles
	{
		color[] = {{0.5,0.5,0.5,0.02},{0.55,0.55,0.55,0.03},{0.65,0.65,0.65,0.02}};
		colorVar[] = {0,0,0,0.05};
		lifeTimeVar = 4;
	};
};

class WOG_D30_Fired
{
	class WOG_ejector_smoke
	{
		simulation="particles";
		type="WOG_D30_Fired_Particles";
		//position[]={0,0,0};
		intensity=1;
		interval=1;
		lifeTime=3;
		qualityLevel=-1;
	};
};

class CfgVehicleClasses
{
    class acex_artillery_System
	{
        displayName = "ACEX ARTILLERY Vehicles";
    };
};

class CfgWeapons
{
	class CannonCore;
	class mortar_155mm_AMOS: CannonCore
	{
		class Single5;
	};
	class wog_weap_D30: mortar_155mm_AMOS
	{
		displayName = "$STR_WOG_advanced_artillery_D30_displayName";
		ballisticscomputer = 0;
		reloadTime = 0;
		magazineReloadTime = 0;
		shotFromTurret = 1;
		
		ace_overpressure_angle = 80;
		ace_overpressure_range = 10;
		ace_overpressure_damage = 0.75;

		class GunParticles {
			class Effect1
			{
				directionname = "Konec hlavne";
				positionname = "Usti hlavne";
				effectname = "ArtilleryFired1";
			};
			class Effect2
			{
				directionname = "ejector_pos";
				positionname = "ejector_dir";
				effectname = "RHS_D30_Fired";
			};
			class Effect3
			{
				directionname = "ejector_pos";
				positionname = "ejector_dir";
				effectname = "WOG_D30_Fired";
			};
		};

		modes[] = {"Single5"};
		
		class Single5: Single5
		{
			displayName = "";
			dispersion = 0.0028;
		};

		magazines[] =
		{
			"wog_mag_of462_charge_full",
			"wog_mag_of462_charge_reduced",
			"wog_mag_of462_charge_1",
			"wog_mag_of462_charge_2",
			"wog_mag_of462_charge_3",
			"wog_mag_of462_charge_4",
			"wog_mag_3bk13_charge_full"
		};
	};
	
	class MGun;
	class wog_weap_pab_2m: MGun
	{
		scope = 1;
		cursor = "EmptyCursor";
		cursorAim = "EmptyCursor";
		displayName = "$STR_WOG_advanced_artillery_pab_2m_displayName";
	};
	
	class ItemCore;
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
	class InventoryItem_Base_F;
	
	class WOG_RangeTable_D30: ACE_ItemCore
	{
		scope=2;
		displayName="$STR_WOG_advanced_artillery_D30_RangeTable_displayName";
		descriptionShort="$STR_ace_ruPal_RHS_to_ACE_rangetable_description";
		picture="\z\ace\addons\ruPal_RHS_to_ACE\UI\icon_rangeTable.paa";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=0.5;
		};
	};
    
    class acex_artillery_AimingPost: ACE_ItemCore
	{
        scope = 2;
        displayName = "$STR_WOG_advanced_artillery_aimingpoints_aiming_post";
        author = "$STR_ACE_Common_ACETeam";

        model = "\wog_advanced_artillery\aimingpoints\arty_aimingpost_equip_f.p3d";
        icon = "\wog_advanced_artillery\aimingpoints\data\ui\map_aimingpost_ca.paa";
        picture = "\wog_advanced_artillery\aimingpoints\data\ui\aimingpost_equip_ca.paa";

        class ItemInfo: CBA_MiscItem_ItemInfo
		{
            mass = 50;
            //uniformModel = "wog_advanced_artillery\aimingpoints\arty_aimingpost_equip_f.p3d";
			//allowedSlots[] = {901};
			//type = 0;
        };
    };

    class acex_artillery_Collimator: ACE_ItemCore
	{
        scope = 2;
        displayName = "$STR_WOG_advanced_artillery_aimingpoints_artillery_collimator";
        author = "$STR_ACE_Common_ACETeam";
        
        model = "\wog_advanced_artillery\aimingpoints\arty_collimator_equip_f.p3d";
        icon = "\wog_advanced_artillery\aimingpoints\data\ui\map_collimator_ca.paa";
        picture = "\wog_advanced_artillery\aimingpoints\data\ui\collimator_equip_ca.paa";

        class ItemInfo: CBA_MiscItem_ItemInfo
		{
            mass = 50;
        };
    };
};

class CBA_Extended_EventHandlers_base;

class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class ACE_SelfActions
		{
			class WOG_Arty_Prep_D_Open
			{
				displayName = "$STR_WOG_advanced_artillery_Prep_charges_displayName";
				condition = "call WOG_fnc_prep_d_canOpen";
				statement = "createDialog 'WOG_ARTY_PREP_D'";
				showDisabled = 0;
				exceptions[] = {"notOnMap", "isNotSitting"};
				priority = 5;
				icon = "\z\ace\addons\rearm\ui\icon_rearm_interact.paa";
			};
			
			class ACE_Equipment
			{
				class WOG_D30_Range_Table
				{
                    displayName = "$STR_WOG_advanced_artillery_D30_RangeTable_displayName";
                    condition = "'WOG_RangeTable_D30' in (items (_this select 1))";
                    statement = "_this call WOG_fnc_rangeTableOpen";
                    priority = 0;
                    icon = "\z\ace\addons\ruPal_RHS_to_ACE\UI\icon_rangeTable.paa";
                    exceptions[] = {"notOnMap", "isNotInside", "isNotSitting"};
                };
				
				class WOG_pab_2m_place
				{
                    displayName = "$STR_WOG_advanced_artillery_pab_2m_assemble";
                    condition = "(backpack _player) == 'WOG_pab_2m_bag'";
                    statement = "[_player, 'WOG_pab_2m_bag'] call WOG_fnc_PAB_2M_place";
                    showDisabled = 0;
                    icon = "wog_advanced_artillery\pab-2m\data\w_pab_2m_icon.paa";
                };
				
				class WOG_aiming_post_place
				{
                    displayName = "$STR_WOG_advanced_artillery_aimingpoints_setup_aimingpost";
                    condition = "'acex_artillery_AimingPost' in (items _player)";
                    statement = "[_player, 'acex_artillery_AimingPost'] call wog_fnc_aimingpoints_place";
                    showDisabled = 0;
                    icon = "wog_advanced_artillery\aimingpoints\data\ui\aimingpost_equip_ca.paa";
                };
				
				class WOG_collimator_place
				{
                    displayName = "$STR_WOG_advanced_artillery_aimingpoints_setup_collimator";
                    condition = "'acex_artillery_Collimator' in (items _player)";
                    statement = "[_player, 'acex_artillery_Collimator'] call wog_fnc_aimingpoints_place";
                    showDisabled = 0;
                    icon = "wog_advanced_artillery\aimingpoints\data\ui\collimator_equip_ca.paa";
                };
			};
			
			class ACE_MapTools
			{
				class ACE_MapToolsShowNormal_6000
				{
                    displayName = "$STR_ACE_MapTools_MapToolsShowNormal_6000";
                    condition = "ace_maptools_mapTool_Shown != 3";
                    statement = "ace_maptools_mapTool_Shown = 3;";
                    exceptions[] = {"isNotDragging", "notOnMap", "isNotInside", "isNotSitting"};
                    showDisabled = 1;
                };
				
				class ACE_MapToolsShowSmall_6000
				{
                    displayName = "$STR_ACE_MapTools_MapToolsShowSmall_6000";
                    condition = "ace_maptools_mapTool_Shown != 4";
                    statement = "ace_maptools_mapTool_Shown = 4;";
                    exceptions[] = {"isNotDragging", "notOnMap", "isNotInside", "isNotSitting"};
                    showDisabled = 1;
                };
			};
		};
	};
	
	class Bag_Base;
	class Weapon_Bag_Base: Bag_Base
	{
		class assembleInfo;
	};
	
	class WOG_pab_2m_bag: Weapon_Bag_Base
	{
		dlc="RHS_AFRF";
		scope=2;
		author="$STR_A3_Bohemia_Interactive";
		displayName="$STR_WOG_advanced_artillery_pab_2m_folded_displayName";
		mass=100;
		model="\rhsafrf\addons\rhs_heavyweapons\bags\StaticY.p3d";
		picture="\rhsafrf\addons\rhs_heavyweapons\bags\staticY_CA.paa";
		icon="\rhsafrf\addons\rhs_heavyweapons\bags\mapIcon_backpack_CA.paa";
		class assembleInfo
		{
			primary=0;
			base="";
			assembleTo="";
			dissasembleTo[]={};
			displayName="";
		};
		faction="rhs_faction_msv";
		editorSubcategory="EdSubcat_DismantledWeapons";
	};
	
	class NATO_Box_Base;
	class Box_NATO_Support_F;
	class WOG_Box_pab_2m: Box_NATO_Support_F
	{
		displayName = "$STR_WOG_advanced_artillery_pab_2m_box_displayName";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_Ammo_F.jpg";
		model = "\A3\weapons_F\AmmoBoxes\AmmoBox_F";
		_generalMacro = "Box_NATO_Support_F";
		author = "Bohemia Interactive";
		scope = 2;
		icon = "iconCrateLarge";
		
		class TransportBackpacks
		{
			class _xx_WOG_pab_2m
			{
				backpack = "WOG_pab_2m_bag";
				count = 1;
			};
        };
		class TransportItems {};
		class TransportMagazines {};
	};
	
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
		
		class ACE_Actions
		{
			class ACE_MainActions;
		};
	};
	
	class wog_pab_2m: StaticWeapon
	{
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
		
		author = "Lex";
        scope = 2;
        side = 0;
        faction = "rhs_faction_msv";
        crew = "rhs_msv_emr_efreitor";
        typicalCargo[] = {"Soldier"};
        displayName = "$STR_WOG_advanced_artillery_pab_2m_displayName";
        model = "wog_advanced_artillery\pab-2m\pab_2m.p3d";
		icon = "wog_advanced_artillery\pab-2m\data\icomap\icomap_pab_2m_ca.paa";
        mapSize = 0.5;
        transportSoldier = 0;
        getInAction = "";
        getOutAction = "";
        editorSubcategory = "EdSubcat_Turrets";
		
		ace_cargo_canLoad = 0;

        threat[] = {0.7, 0.3, 0};
        accuracy = 0.12;
        cost = 10000;
		attenuationEffectType = "";
		
		class Hitpoints
		{
			class HitHull
			{
				armor = 1;
				passThrough = 1;
				name = "zbytek";
			};
		};
		
		class Turrets: Turrets
		{
            class MainTurret: MainTurret
			{
				minTurn = -180;
                maxTurn = 180;
                initTurn = 0;
                minElev = -18;
                maxElev = 18;
                initElev = 0;

				class ViewGunner
				{
					initAngleX = -20;
					minAngleX = -60;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.75;
					minFov = 0.25;
					maxFov = 1.25;
				};

				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					minFov = 0.053;
					maxFov = 0.053;
					initFov= 0.053;
				};
				
				class OpticsIn
				{
					class MainOptics
					{
						gunnerOpticsModel = "wog_advanced_artillery\pab-2m\2Dscope_pab_2m.p3d";
						gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
						initAngleX = 0;
						initAngleY = 0;
						initFov = 0.053;
						maxAngleX = 30;
						maxAngleY = 100;
						maxFov = 0.053;
						maxMoveX = 0;
						maxMoveY = 0;
						maxMoveZ = 0;
						minAngleX = -30;
						minAngleY = -100;
						minFov = 0.053;
						minMoveX = 0;
						minMoveY = 0;
						minMoveZ = 0;
						opticsDisplayName = "";
						visionMode[] = {"Normal"};
					};
					class FrontView: MainOptics
					{
						gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
						gunnerOpticsEffect[] = {};
						camPos = "gunnerview2";
						initAngleX = 0;
						minAngleX = -60;
						maxAngleX = 30;
						initAngleY = 10;
						minAngleY = 10;
						maxAngleY = 10;
						initFov = 0.43; //0.75
						minFov = 0.43;
						maxFov = 0.43;
					};
					class CompassView: FrontView
					{
						camPos = "gunnerview3";
						camDir = "gunnerview3_dir";
						initFov = 0.75;
						minFov = 0.75;
						maxFov = 0.75;
					};
				};
		
				weapons[] = {"wog_weap_pab_2m"};
				magazines[] = {};
				optics = 1;
				elevationMode = 1;
				maxHorizontalRotSpeed = 0.5;
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOpticsModel = "wog_advanced_artillery\pab-2m\2Dscope_pab_2m.p3d";
				gunnerOpticsEffect[] = {};
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 0;
				gunnerAction = "wog_pab_2m_gunner";
				gunnerGetInAction = "";
				gunnerGetOutAction = "";
				gunnerForceOptics = 0;
				ejectDeadGunner = 1;
				turretInfoType = "";
				opticsDisablePeripherialVision = 1;
			};
		};
		
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				selection="action_point";
				class WOG_pab_2m_leveling
				{
					selection="";
					distance = 5;
					displayName="$STR_WOG_advanced_artillery_pab_2m_level";
					condition="(alive _target) && isNull (_target getVariable ['wog_pab_2m_helper_pad', objNull]) && (isNull (gunner _target))";
					statement="[_target] call WOG_fnc_PAB_2M_leveling";
					showDisabled=0;
					exceptions[] = {};
				};
				class WOG_pab_2m_pickup
				{
					selection="";
					distance = 5;
					displayName="$STR_WOG_advanced_artillery_pab_2m_fold";
					condition="(alive _target) && isNull (gunner _target)";
					statement="[_target, _player] call WOG_fnc_PAB_2M_pickup";
					showDisabled=0;
					exceptions[] = {};
				};
			};
		};
		
		class AnimationSources
		{
			class uglomer_rotation_source
			{
				source = "user";
				animPeriod = 0.001000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};
			class base_rotation_source
			{
				source = "user";
				animPeriod = 0.001000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};
			class compass_arrow_rotation_source
			{
				source = "user";
				animPeriod = 0.001000;
				initPhase = 0;
				minValue = -500;
				maxValue = 500;
			};
		};
		
		armor = 80;
		
		class Damage
		{
			tex[] = {};
			mat[] =
			{
				"wog_advanced_artillery\pab-2m\data\pab-2m.rvmat",
				"wog_advanced_artillery\pab-2m\data\pab-2m_damage.rvmat",
				"wog_advanced_artillery\pab-2m\data\pab-2m_destruct.rvmat",
				
				"wog_advanced_artillery\pab-2m\data\pab-2m_tripod.rvmat",
				"wog_advanced_artillery\pab-2m\data\pab-2m_tripod_damage.rvmat",
				"wog_advanced_artillery\pab-2m\data\pab-2m_tripod_destruct.rvmat"
			};
		};
	};
	
	class Item_Base_F;
	class Item_Arty_AimingPost: Item_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_WOG_advanced_artillery_aimingpoints_aiming_post";
        author = "$STR_ACE_Common_ACETeam";
		model = "wog_advanced_artillery\aimingpoints\arty_aimingpost_equip_f.p3d";
        icon = "wog_advanced_artillery\aimingpoints\data\ui\map_aimingpost_ca.paa";
        picture = "wog_advanced_artillery\aimingpoints\data\ui\aimingpost_equip_ca.paa";
        vehicleClass = "acex_artillery_System";

        class TransportItems
		{
			class _xx_acex_artillery_AimingPost
			{
				name = "acex_artillery_AimingPost";
				count = 1;
			};
        };
    };
	
	class acex_artillery_Collimator_Item: Item_Base_F
	{
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_WOG_advanced_artillery_aimingpoints_artillery_collimator";
        author = "$STR_ACE_Common_ACETeam";
        model = "wog_advanced_artillery\aimingpoints\Arty_Collimator_Equip_F.p3d";
        icon = "wog_advanced_artillery\aimingpoints\data\ui\map_collimator_ca.paa";
        picture = "wog_advanced_artillery\aimingpoints\data\ui\collimator_equip_ca.paa";
        vehicleClass = "acex_artillery_System";
        class TransportItems
		{
			class _xx_acex_artillery_Collimator
			{
				name = "acex_artillery_Collimator";
				count = 1;
			};
        };
    };
	
	class NonStrategic;
	
	class acex_artillery_AimingPost_F: NonStrategic {
		
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			class WOG_EventHandlers
			{
				init = "[_this select 0] spawn ace_dragging_fnc_initObject";
			};
		};
		
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_WOG_advanced_artillery_aimingpoints_aiming_post";
        author = "$STR_ACE_Common_ACETeam";
        vehicleClass = "acex_artillery_System";

        model="wog_advanced_artillery\aimingpoints\arty_aimingpost_F.p3d";
        icon="wog_advanced_artillery\aimingpoints\data\ui\map_aimingpost_ca.paa";
        picture="wog_advanced_artillery\aimingpoints\data\ui\aimingpost_equip_ca.paa";
		
		ace_dragging_canCarry = 1;  // Can be carried (0-no, 1-yes)
        ace_dragging_carryPosition[] = {0, 1, 1};  // Offset of the model from the body while dragging (same as attachTo) (default: [0, 1, 1])
        ace_dragging_carryDirection = 0;

        class AnimationSources
        {
            class move_post_light {
                source = "user";
                animPeriod = 2.00;
                initPhase = 0;
            };
            class show_post_light {
                source = "user";
                animPeriod = 0.5;
                initPhase = 1;
            };
            class light_base {
                animPeriod = 0;
                initPhase = 0;
                minValue = 0;
                maxValue = 2;
            };
            class light_mode {
                source = "user";
                animPeriod = 0;
                initPhase = 0;
                minValue = 0;
                maxValue = 2;
            };
        };
        class ACE_Actions
		{
			class ACE_MainActions
			{
				displayName = "$STR_ACE_Interaction_MainAction";
                selection = "pos_height";
                distance = 5;
                condition = "true";
				
				class ACE_AimingPost_Leveling
				{
					displayName="$STR_WOG_advanced_artillery_pab_2m_level";
					distance = 2;
					condition = "_target == _target";
					statement = "[_target, [0,0,1]] remoteExec ['setVectorUp', _target]";
					showDisabled = 0;
					icon = "a3\3den\data\displays\display3den\toolbar\snap_on_ca.paa";
				};
				
				class ACE_AimingPost_Pickup
				{
					displayName="$STR_WOG_advanced_artillery_pab_2m_fold";
					distance = 2;
					condition = "alive _target";
					statement = "[_target, _player, 'Item_Arty_AimingPost'] call wog_fnc_aimingpoints_pickup";
					showDisabled = 0;
				};
				
				class ACE_Aimingpost_Move
				{
					displayName="$STR_WOG_advanced_artillery_aimingpoints_move_post_light";
					distance = 2;
					condition = "(_target animationPhase 'show_post_light' == 1)";
					statement = "[_target] call WOG_fnc_apost_move_light";
					showDisabled = 0;
					//selection = "pos_height";
				};
				class ACE_Aimingpost_GetDistance
				{
					displayName="$STR_WOG_advanced_artillery_aimingpoints_apost_getDistance";
					distance = 2;
					condition = "true";
					statement = "[_target] call wog_fnc_apost_getDistanceToClosest;";
					showDisabled = 0;
					//selection = "pos_height";
				};
				class ACE_Aimingpost_digging
				{
					displayName="$STR_WOG_advanced_artillery_aimingpoints_apost_digging";
					distance = 2;
					condition = "true";
					statement = "[_target] call wog_fnc_apost_digging;";
					showDisabled = 0;
					//selection = "pos_height";
				};
			};

			class ACE_Aimingpost_Light
			{
				displayName="$STR_WOG_advanced_artillery_aimingpoints_toggle_light";
				distance = 2;
				condition = "(_target animationPhase 'show_post_light' == 1)";
				statement = "[_target] call WOG_fnc_apost_toggle_light";
				showDisabled = 0;
				selection = "pos_light";
			};
        };
    };
	
	class ThingX;
	
	class acex_artillery_Collimator_F: ThingX {
        
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
		};
		
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_WOG_advanced_artillery_aimingpoints_artillery_collimator";
        author = "$STR_ACE_Common_ACETeam";
		simulation = "house";
        model="wog_advanced_artillery\aimingpoints\Arty_Collimator_F.p3d";
        icon="wog_advanced_artillery\aimingpoints\data\ui\map_collimator_ca.paa";
        picture="wog_advanced_artillery\aimingpoints\data\ui\collimator_equip_ca.paa";
        vehicleClass = "acex_artillery_System";
		ace_dragging_canCarry = 1;  // Can be carried (0-no, 1-yes)
        ace_dragging_carryPosition[] = {0, 1, 1};  // Offset of the model from the body while dragging (same as attachTo) (default: [0, 1, 1])
        ace_dragging_carryDirection = 180;

        class ACE_Actions
		{
			class ACE_MainActions
			{
				displayName = "$STR_ACE_Interaction_MainAction";
                selection = "";
                distance = 5;
                condition = "true";
				
				class ACE_Collimator_Leveling
				{
					displayName="$STR_WOG_advanced_artillery_pab_2m_level";
					distance = 2;
					condition = "alive _target";
					statement = "[_target, [0,0,1]] remoteExec ['setVectorUp', _target]";
					showDisabled = 0;
					icon = "a3\3den\data\displays\display3den\toolbar\snap_on_ca.paa";
					//selection = "action_adjust";
				};
				class ACE_Collimator_Pickup
				{
					displayName="$STR_WOG_advanced_artillery_pab_2m_fold";
					distance = 2;
					condition = "alive _target";
					statement = "[_target, _player, 'acex_artillery_Collimator_Item'] call wog_fnc_aimingpoints_pickup";
					showDisabled = 0;
				};
			};
            class ACE_Collimator_Adjust
			{
                displayName="$STR_WOG_advanced_artillery_aimingpoints_adjust_collimator";
                distance = 1.25;
                condition = "_target == _target";
                statement = "[_target] call WOG_fnc_collim_adjust_sight";
                showDisabled = 0;
                selection = "action_adjust";
            };
			class ACE_Collimator_Toggle_Light
			{
                displayName="$STR_WOG_advanced_artillery_aimingpoints_toggle_light";
                distance = 1.25;
                condition = "_target == _target";
                statement = "[_target] call WOG_fnc_collim_toggle_light";
                showDisabled = 0;
                selection = "glass_dir";
            };
        };

        class AnimationSources {
            class illuminate {
                // Do Not Use In Script - Use 'collimator_illuminate'
                source = "user";
                animPeriod=0;
                initPhase=0;
                minValue=-0;
                maxValue=2;
            };
            class expand {
                // Do Not Use In Script - Use 'collimator_size'
                source = "user";
                animPeriod=0;
                initPhase=0;
                minValue=-0;
                maxValue=1;
            };
            class collimator_illuminate {
                displayName = "Collimator Back-light";
                source = "user";
                animPeriod = 0.01;
                minValue = 0;
                maxValue = 2;
                initPhase = 0;
            };
            class collimator_size {
                displayName = "Collimator Reticule Size";
                source = "user";
                animPeriod = 1.0;
                initPhase = 0;
                minValue = 0;
                maxValue = 1;
            };
            class collimator_offset {
                displayName = "Collimator Offset";
                source="user";
                animPeriod=0.01;
                initPhase = 0;
                minValue = -1;
                maxValue = 1;
            };
            class collimator_rotation {
                // Animation phase loops through rad -360/+360
                displayName = "Collimator Rotation";
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
                minValue = "-6400";
                maxValue = "6400";
            };
            class collimator_elevation {
                // Animation phase 0-1 Loops through rad -90/+30
                displayName = "Collimator Elevation";
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
                minValue = "-300";
                maxValue = "300";
            };
            class fold_legs {
                displayName = "Fold Collimator Legs";
                source = "user";
                animPeriod = 1;
                initPhase = 0;
            };
            class foot_01 {
                displayName = "Extend Collimator Leg 1";
                source = "user";
                animPeriod = 0;
                initPhase = 0;
            };
            class foot_02: foot_01 {
                displayName = "Extend Collimator Leg 2";
            };
            class foot_03: foot_01 {
                displayName = "Extend Collimator Leg 3";
            };
        };
    };
	
	class ACE_Arty_Collimator_Proxy: ThingX { // No idea wether this should be hidden or not
		scope = 1;
		displayName = "Collimator Proxy";
		//destrType = "DestructTree";
		//weight = 1000;
		//simulation = "house";
		model = "wog_advanced_artillery\aimingpoints\collimator_test.p3d";
		//animated = 1;
		//reversed = 0;
		//autocenter = 0;
		//sectionsInherit = "collimator_test";
		hiddenSelections[] = {"pattern"};
		hiddenSelectionsTextures[] = {"wog_advanced_artillery\aimingpoints\data\collimator_pattern_ca.paa"};

		class AnimationSources{
			class offset {
				source = "user";
				animPeriod = 0.00001;
				minValue = -100;
				maxValue = 100;
			};
			class expand_ul {
				source = "user";
				animPeriod = 0.00001;
				minValue = 1;
				maxValue = -1;
			};
			class expand_ur {
				source = "user";
				animPeriod = 0.00001;
				minValue = 1;
				maxValue = -1;
			};
			class expand_ll {
				source = "user";
				animPeriod = 0.00001;
				minValue = 1;
				maxValue = -1;
			};
			class expand_lr {
				source = "user";
				animPeriod = 0.00001;
				minValue = 1;
				maxValue = -1;
			};
			class alpha_hide {
				source = "user";
				animPeriod = 0.00001;
				minValue = 0;
				maxValue = 1;
				initPhase = 0;
			};
		};
	};
	
	class wog_122_ammobox: NATO_Box_Base
	{
		scope=2;
		scopeCurator=1;
		accuracy=1000;
		displayName="$STR_WOG_advanced_artillery_122mm_Ammobox_displayName";
		model="wog_advanced_artillery\ammobox_122\wog_122_ammobox.p3d";
		author="Lex";
		ace_cargo_size=0.5;
		ace_cargo_canLoad=1;
		ace_dragging_carryDirection = 0;
		ace_dragging_dragDirection = 0;
		transportMaxWeapons = 0;
		transportMaxMagazines = 0;
		transportMaxBackpacks = 0;
		editorPreview="\wog_advanced_artillery\resource\data\wog_122_ammobox_editor_preview.jpg";
		icon="\arty_ammo\data\120mm\UI\icon_box_ca.paa";
		
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"wog_advanced_artillery\ammobox_122\data\wog_122_ammobox_of462_decal_ca.paa"};
		
		class AnimationSources
		{
			class lid_rotation
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1.5;
			};
			
			class shell_1_hide
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.001;
			};
			
			class shell_2_hide: shell_1_hide {};
			class shell_3bk13_1_hide: shell_1_hide {};
			class shell_3bk13_2_hide: shell_1_hide {};
			class charge_1_hide: shell_1_hide {};
			class charge_2_hide: shell_1_hide {};
			class covering_1_hide: shell_1_hide {};
			class covering_2_hide: shell_1_hide {};
		};
		
		class ACE_Actions
		{
			class ACE_MainActions
			{
				selection="";
				distance=2;
				condition="(_target animationSourcePhase 'lid_rotation') == 0";
				class WOG_D30_Open_Ammobox_Action
				{
					distance=2;
					displayName="$STR_lex_arty_Open_box";
					condition="(_target animationSourcePhase 'lid_rotation') == 0";
					statement="_target animateSource ['lid_rotation', 1]";
					showDisabled=0;
					exceptions[]={};
					priority=5;
				};
			};
			class WOG_D30_Close_Ammobox_Action
			{
				selection="action_point_open";
				distance=1.5;
				displayName="$STR_lex_arty_Close_box";
				condition="(_target animationSourcePhase 'lid_rotation') == 1";
				statement="_target animateSource ['lid_rotation', 0]";
				showDisabled=0;
				exceptions[]={};
				priority=5;
			};
			class WOG_D30_Take_Shell_1_Action
			{
				selection="action_point_shell_take_1";
				distance=1.5;
				displayName="$STR_lex_arty_Take";
				condition="((_target animationSourcePhase 'lid_rotation') == 1) && (((_target animationPhase 'shell_1_hide') == 0) || ((_target animationPhase 'shell_3bk13_1_hide') == 0))";
				statement="[_target, 1, 1] call wog_fnc_take_122_shell";
				showDisabled=0;
				exceptions[]={};
				priority=5;
				icon="wog_advanced_artillery\resource\data\icon_load_interact.paa";
			};
			class WOG_D30_Take_Shell_2_Action: WOG_D30_Take_Shell_1_Action
			{
				selection="action_point_shell_take_2";
				condition="((_target animationSourcePhase 'lid_rotation') == 1) && (((_target animationPhase 'shell_2_hide') == 0) || ((_target animationPhase 'shell_3bk13_2_hide') == 0))";
				statement="[_target, 1, 2] call wog_fnc_take_122_shell";
			};
			class WOG_D30_Take_Casing_1_Action: WOG_D30_Take_Shell_1_Action
			{
				selection="action_point_charge_take_1";
				condition="((_target animationSourcePhase 'lid_rotation') == 1) && ((_target animationPhase 'charge_1_hide') == 0)";
				statement="[_target, 2, 1] call wog_fnc_take_122_shell";
			};
			class WOG_D30_Take_Casing_2_Action: WOG_D30_Take_Shell_1_Action
			{
				selection="action_point_charge_take_2";
				condition="((_target animationSourcePhase 'lid_rotation') == 1) && ((_target animationPhase 'charge_2_hide') == 0)";
				statement="[_target, 2, 2] call wog_fnc_take_122_shell";
			};
			////////////////////////////////////////////////////////////////////
			class WOG_D30_Put_Shell_1_Action: WOG_D30_Take_Shell_1_Action
			{
				selection="action_point_shell_take_1";
				displayName="$STR_lex_arty_Put";
				condition="((_target animationSourcePhase 'lid_rotation') == 1) && ((_target animationPhase 'shell_1_hide') == 1) && ((_target animationPhase 'shell_3bk13_1_hide') == 1)";
				statement="[_target, 1, 1] call wog_fnc_put_122_shell";
				icon="wog_advanced_artillery\resource\data\icon_unload_interact.paa";
			};
			class WOG_D30_Put_Shell_2_Action: WOG_D30_Put_Shell_1_Action
			{
				selection="action_point_shell_take_2";
				condition="((_target animationSourcePhase 'lid_rotation') == 1) && ((_target animationPhase 'shell_2_hide') == 1) && ((_target animationPhase 'shell_3bk13_2_hide') == 1)";
				statement="[_target, 1, 2] call wog_fnc_put_122_shell";
			};
			class WOG_D30_Put_Casing_1_Action: WOG_D30_Put_Shell_1_Action
			{
				selection="action_point_charge_take_1";
				condition="((_target animationSourcePhase 'lid_rotation') == 1) && ((_target animationPhase 'charge_1_hide') == 1)";
				statement="[_target, 2, 1] call wog_fnc_put_122_shell";
			};
			class WOG_D30_Put_Casing_2_Action: WOG_D30_Put_Shell_1_Action
			{
				selection="action_point_charge_take_2";
				condition="((_target animationSourcePhase 'lid_rotation') == 1) && ((_target animationPhase 'charge_2_hide') == 1)";
				statement="[_target, 2, 2] call wog_fnc_put_122_shell";
			};
		};
		
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			
			class WOG_EventHandlers
			{
				init = "[_this, 1] spawn wog_fnc_initAmmobox";
			};
		};
	};
	
	class wog_122_3bk13_ammobox: wog_122_ammobox
	{
		displayName="$STR_WOG_advanced_artillery_122mm_3bk13_Ammobox_displayName";
		hiddenSelectionsTextures[] = {"wog_advanced_artillery\ammobox_122\data\wog_122_ammobox_3bk13_decal_ca.paa"};
		
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			
			class WOG_EventHandlers: WOG_EventHandlers
			{
				init = "[_this, 2] spawn wog_fnc_initAmmobox";
			};
		};
	};
	
	class StaticCannon;
	class rhs_D30_base: StaticCannon
	{
		class Turrets;
		class MainTurret;
		class AnimationSources;
		class ACE_Actions;
		class ACE_MainActions;
		class EventHandlers;
		class RHS_EventHandlers;
		class UserActions;
		class ViewOptics;
		class TransportItems;
	};
	
	class wog_D30_base: rhs_D30_base
	{
		model = "wog_advanced_artillery\D30\d30.p3d";
		displayName = "$STR_WOG_advanced_artillery_D30_displayName";
		scope = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				animationSourceElevation = "MainGun";
				elevationMode = 0;
				selectionFireAnim = "gun_muzzle";
				gunEnd = "gun_chamber";
				gunBeg = "gun_muzzle";
				turretinfotype = "wog_gui_optic_d30_op4";
				gunnerForceOptics = 0;
				gunnerOpticsModel = "wog_advanced_artillery\D30\2Dscope_D30_panoramic.p3d";
				magazines[] = {};
				weapons[] = {"wog_weap_D30"};
				class ViewOptics: ViewOptics
				{
					initFov = 0.106;
					maxFov = 0.106;
					minFov = 0.106;
				};
				
				class OpticsIn
				{
					class PanoramicSight
					{
						gunnerOpticsModel = "wog_advanced_artillery\D30\2Dscope_D30_panoramic.p3d";
						//hitpoint = "Hit_Optic_PG1M";
						initAngleX = 0;
						initAngleY = 0;
						initFov = 0.106;
						maxAngleX = 30;
						maxAngleY = 100;
						maxFov = 0.106;
						maxMoveX = 0;
						maxMoveY = 0;
						maxMoveZ = 0;
						minAngleX = -30;
						minAngleY = -100;
						minFov = 0.106;
						minMoveX = 0;
						minMoveY = 0;
						minMoveZ = 0;
						opticsDisplayName = "PG1";
						visionMode[] = {"Normal"};
					};
					
					class OP4M_45
					{
						opticsDisplayName 	= "OP4";
						//hitpoint 			= "Hit_Optic_OP4M";
						camPos				= "view_op4m";
						camDir				= "view_op4m_dir";
						initAngleX			= 0;
						minAngleX			= -30;
						maxAngleX			= 30;
						initAngleY			= 0;
						minAngleY			= -100;
						maxAngleY			= 100;
						initFov 			= 0.127273;
						minFov 				= 0.127273;
						maxFov 				= 0.127273;
						visionMode[]		= {"Normal"};
						gunnerOpticsModel	= "\rhsafrf\addons\rhs_optics\vehicles\rhs_empty.p3d";
					};
				};
			};
		};
		
		class TransportItems: TransportItems
		{
			class ACE_RangeTable_D30
			{
				name = "WOG_RangeTable_D30";
				count = 3;
			};
			class _xx_ACE_MapTools
			{
				name = "ACE_Maptools";
				count = 3;
			};
			class _xx_acex_artillery_AimingPost
			{
				name = "acex_artillery_AimingPost";
				count = 2;
			};
			class _xx_acex_artillery_Collimator
			{
				name = "acex_artillery_Collimator";
				count = 1;
			};
		};
		
		class AnimationSources: AnimationSources
		{
			class MainTurret {
				source = "user";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};
			class MainGun {
				source = "user";
				weapon = "wog_weap_D30";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -117;
				maxValue = 1167;
			};
			class klin_open_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.15;
			};
			class handle_klin_open
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1.2;
			};
			class shell_loading
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.7;
			};
			class shell_3bk13_loading: shell_loading {};
			class casing_loading: shell_loading
			{
				animPeriod = 0.55;
			};
			class leftLiftT_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 5;
			};
			class rightLiftT_source: leftLiftT_source {};
			class mainLiftT_source: leftLiftT_source {};
			class maingunT_source {source="user";animPeriod = 0.01;initPhase=0; };
			class mainTurretT_source: maingunT_source {};
			
			class OpticRevolve
			{
				source = "user";
				animPeriod = 0.002000;
				initPhase = 0;
				minValue = -6000;
				maxValue = 6000;
			};
			class OpticElevate
			{
				source = "user";
				animPeriod = 0.002000;
				initPhase = 0;
				minValue = 0;
				maxValue = 1167;
			};
			class OpticDialElevate
			{
				source = "user";
				animPeriod = 0.002000;
				initPhase = 0;
				minValue = -300;
				maxValue = 300;
			};
			class RecoilAnim
			{
				source = "user";
				animPeriod = 7;
				initPhase = 0;
				minValue = 0;
				maxValue = 1;
			};
			class handleelevation
			{
				source = "user";
				animPeriod = 0.010000;
				initPhase = 0;
				minValue = -50;
				maxValue = 50;
			};
			class handlehorizont: handleelevation {};
			class handleelevation2: handleelevation {};
			class handlehorizont2: handleelevation {};
		};
		class UserActions: UserActions
		{
			class ShowSight
			{
				condition = "(gunner this) == player";
				displayName = "$STR_WOG_advanced_artillery_Sight_displayName";
				priority = 3;
				showWindow = 0;
				onlyForPlayer = 1;
				position = "aimpoint";
				radius = 2.51;
				statement = "if (isNull(uiNamespace getVariable ['wog_d30_sight_gui', displayNull])) then {('wog_d30_sight_gui_layer' call BIS_fnc_rscLayer) cutRsc ['WOG_ARTY_D726_45', 'PLAIN', 2, false]} else {('wog_d30_sight_gui_layer' call BIS_fnc_rscLayer) cutText ['','PLAIN'];};";
			};
			class Fold
			{
				displayName = "Fold gun";
				position = "aimpoint";
				radius = 2.51;
				onlyForplayer = 0;
				condition = "(alive this)&& ((count (crew this)) == 0) && (this animationPhase 'leftT' == 0)";
				statement = "[this,1] call WOG_fnc_pack_D30;";
			};
			class Unfold: Fold
			{
				displayName = "Unfold gun";
				condition = "(alive this)&& (this  animationPhase 'leftT' > 2.2) && !(this getVariable ['WOG_D30_isTowed', false])";
				statement = "[this,0] call WOG_fnc_pack_D30;";
			};
		};
		
		class ACE_Actions: ACE_Actions
		{
			class ACE_MainActions: ACE_MainActions
			{
				class WOG_D30_level_d
				{
					distance=5;
					displayName="$STR_WOG_advanced_artillery_Leveling_displayName";
					condition="(alive _target) && (_target animationPhase 'leftT') == 0";
					statement="_player setVariable ['WOG_D30_gunObj', _target]; createDialog 'WOG_ARTY_LEVEL_D';";
					showDisabled=0;
					exceptions[]={};
					priority=5;
					icon = "a3\3den\data\displays\display3den\toolbar\snap_on_ca.paa";
				};
			};
			class WOG_D30_Open_Breech_Action
			{
				selection="action_point_handle";
				distance=1.5;
				displayName="$STR_WOG_advanced_artillery_Open_Breech_displayName";
				condition="(alive _target) && (_target animationSourcePhase 'klin_open_source') == 0";
				statement="['wog_advanced_artillery_remove_mags_server_event', [_target]] call CBA_fnc_serverEvent; if ((_target animationSourcePhase 'handle_klin_open') == 0) then {_target animateSource ['handle_klin_open', 1];} else {_target animateSource ['handle_klin_open', 0];}; [{_this animateSource ['klin_open_source', 1, 0.25]}, _target, 0.6] call CBA_fnc_waitAndExecute; [{playSound3D ['wog_advanced_artillery\sounds\open_breech.wss', _this, false, AGLToASL (_this modelToWorld (_this selectionPosition 'ejector_pos')), 3, 1, 35]}, _target, 0.6] call CBA_fnc_waitAndExecute;";
				showDisabled=0;
				exceptions[]={};
				priority=5;
			};
			class WOG_D30_Close_Breech_Action
			{
				selection="action_point_handle";
				distance=1.5;
				displayName="$STR_WOG_advanced_artillery_Close_Breech_displayName";
				condition="(alive _target) && (_target animationSourcePhase 'klin_open_source') == 1";
				statement="[_target] spawn WOG_fnc_closeBreech";
				showDisabled=0;
				exceptions[]={};
				priority=5;
			};
			class WOG_D30_Load_Actions_Group
			{
				selection="action_point_loading";
				condition="(alive _target) && (_target animationSourcePhase 'klin_open_source') == 1";
				displayName = "";
                statement = "";
                exceptions[] = {"isNotSwimming", "isNotInside"};
                showDisabled = 0;
                distance = 1.5;
				icon = "\z\ace\addons\rearm\ui\icon_rearm_interact.paa";
				
				class WOG_D30_Load_Shell_Action
				{
					selection="action_point_loading";
					distance=1.5;
					displayName="$STR_WOG_advanced_artillery_Load_Shell_displayName";
					condition="(alive _target) && ((_target animationSourcePhase 'klin_open_source') == 1) && ((_target animationSourcePhase 'shell_loading') == 0) && ((_target animationSourcePhase 'shell_3bk13_loading') == 0)";
					statement="[_target, 1] spawn wog_fnc_load_d30";
					showDisabled=0;
					exceptions[]={};
					priority=5;
					icon="wog_advanced_artillery\resource\data\icon_load_interact.paa";
				};
				class WOG_D30_Unload_Shell_Action
				{
					selection="action_point_loading";
					distance=1.5;
					displayName="$STR_WOG_advanced_artillery_Unload_Shell_displayName";
					condition="(alive _target) && ((_target animationSourcePhase 'klin_open_source') == 1) && (((_target animationSourcePhase 'shell_loading') == 1) || ((_target animationSourcePhase 'shell_3bk13_loading') == 1)) && ((_target animationSourcePhase 'casing_loading') == 0)";
					statement="[_target, 3] spawn wog_fnc_load_d30";
					showDisabled=0;
					exceptions[]={};
					priority=4;
					icon="wog_advanced_artillery\resource\data\icon_unload_interact.paa";
				};
				class WOG_D30_Load_Casing_Action
				{
					selection="action_point_loading";
					distance=1.5;
					displayName="$STR_WOG_advanced_artillery_Load_Casing_displayName";
					condition="(alive _target) && ((_target animationSourcePhase 'klin_open_source') == 1) && ((_target animationSourcePhase 'casing_loading') == 0) && (((_target animationSourcePhase 'shell_loading') == 1) || ((_target animationSourcePhase 'shell_3bk13_loading') == 1))";
					statement="[_target, 2] spawn wog_fnc_load_d30";
					showDisabled=0;
					exceptions[]={};
					priority=5;
					icon="wog_advanced_artillery\resource\data\icon_load_interact.paa";
				};
				class WOG_D30_Unload_Casing_Action
				{
					selection="action_point_loading";
					distance=1.5;
					displayName="$STR_WOG_advanced_artillery_Unload_Casing_displayName";
					condition="(alive _target) && ((_target animationSourcePhase 'klin_open_source') == 1) && ((_target animationSourcePhase 'casing_loading') == 1) && (((_target animationSourcePhase 'shell_loading') == 1) || ((_target animationSourcePhase 'shell_3bk13_loading') == 1))";
					statement="[_target, 4] spawn wog_fnc_load_d30";
					showDisabled=0;
					exceptions[]={};
					priority=4;
					icon="wog_advanced_artillery\resource\data\icon_unload_interact.paa";
				};
			};
			class WOG_D30_Towing_Attach_Action
			{
				selection="slingloadcargo3";
				distance=2.5;
				displayName="$STR_WOG_advanced_artillery_Towing_Attach_displayName";
				condition="(alive _target) && ([_target] call WOG_fnc_D30_can_towing)";
				statement="[_target, 0] spawn WOG_fnc_D30_towing";
				showDisabled=0;
				exceptions[]={};
				priority=5;
				icon = "\rhsafrf\addons\rhs_main\data\actions\rhs_tow_attach_ca.paa";
			};
			class WOG_D30_Towing_Detach_Action
			{
				selection="slingloadcargo3";
				distance=2.5;
				displayName="$STR_WOG_advanced_artillery_Towing_Detach_displayName";
				condition="(alive _target) && (_target getVariable ['WOG_D30_isTowed', false])";
				statement="[_target, 1] spawn WOG_fnc_D30_towing";
				showDisabled=0;
				exceptions[]={};
				priority=5;
				icon = "\rhsafrf\addons\rhs_main\data\actions\rhs_tow_detach_ca.paa";
			};
		};
		
		class EventHandlers: EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			
			class RHS_EventHandlers: RHS_EventHandlers
			{
				fired = "_this spawn wog_fnc_fired_d30";
			};
		};
	};
	
	class rhs_D30_msv: wog_D30_base
	{
		editorPreview="rhsafrf\addons\rhs_editorPreviews\data\rhs_D30_msv.paa";
		scope=2;
		side=0;
		author="Red Hammer Studios";
		faction="rhs_faction_msv";
		crew="rhs_msv_rifleman";
		typicalCargo[]=
		{
			"rhs_msv_rifleman"
		};
	};
	
	class rhs_D30_vdv: wog_D30_base
	{
		editorPreview="rhsafrf\addons\rhs_editorPreviews\data\rhs_D30_vdv.paa";
		scope=2;
		side=0;
		author="Red Hammer Studios";
		faction="rhs_faction_vdv";
		crew="rhs_vdv_rifleman";
		typicalCargo[]=
		{
			"rhs_vdv_rifleman"
		};
	};
	class rhs_D30_vmf: wog_D30_base
	{
		editorPreview="rhsafrf\addons\rhs_editorPreviews\data\rhs_D30_vdv.paa";
		scope=2;
		side=0;
		author="Red Hammer Studios";
		faction="rhs_faction_vmf";
		crew="rhs_vmf_flora_rifleman";
		typicalCargo[]=
		{
			"rhs_vmf_flora_rifleman"
		};
	};
	class rhs_D30_ins: wog_D30_base
	{
		editorPreview="rhsafrf\addons\rhs_editorPreviews\data\rhs_D30_vdv.paa";
		scope=1;
		side=2;
		author="Red Hammer Studios";
		faction="rhs_faction_insurgents";
		crew="rhs_g_Soldier_F";
		typicalCargo[]=
		{
			"rhs_g_Soldier_F"
		};
	};
	
	class rhsgref_cdf_reg_d30: wog_D30_base
	{
		editorPreview="rhsgref\addons\rhsgref_editorPreviews\data\rhsgref_cdf_reg_d30.paa";
		crew="rhsgref_cdf_reg_rifleman";
		author="RHS (A2 port)";
		side=2;
		dlc="RHS_GREF";
		faction="rhsgref_faction_cdf_ground";
		scope=2;
	};
	
	class rhsgref_cdf_b_reg_d30: rhsgref_cdf_reg_d30
	{
		author="$STR_RHS_AUTHOR_FULL";
		faction="rhsgref_faction_cdf_ground_b";
		side=1;
		scope=2;
		scopeCurator=2;
		crew="rhsgref_cdf_b_reg_rifleman";
	};
	
	class rhsgref_nat_d30: wog_D30_base
	{
		editorPreview="rhsgref\addons\rhsgref_editorPreviews\data\rhsgref_nat_d30.paa";
		crew="rhsgref_nat_rifleman";
		author="RHS (A2 port)";
		side=2;
		dlc="RHS_GREF";
		faction="rhsgref_faction_nationalist";
		scope=2;
	};
	
	class rhsgref_ins_d30: wog_D30_base
	{
		editorPreview="rhsgref\addons\rhsgref_editorPreviews\data\rhsgref_ins_d30.paa";
		scope=2;
		crew="rhsgref_ins_rifleman";
		author="$STR_RHS_AUTHOR_FULL";
		side=0;
		dlc="RHS_GREF";
		faction="rhsgref_faction_chdkz";
	};
	
	class rhsgref_ins_g_d30: rhsgref_ins_d30
	{
		faction="rhsgref_faction_chdkz_g";
		side=2;
		author="$STR_RHS_AUTHOR_FULL";
		scope=2;
		scopeCurator=2;
		crew="rhsgref_ins_g_rifleman";
	};
	
	class rhs_D30_AT_base;
	class rhs_D30_at_ins: rhs_D30_AT_base
	{
		scope = 0;
	};
	class rhs_D30_at_msv: rhs_D30_AT_base
	{
		scope = 0;
	};
	class rhs_D30_at_vdv: rhs_D30_AT_base
	{
		scope = 0;
	};
	class rhs_D30_at_vmf: rhs_D30_AT_base
	{
		scope = 0;
	};
	class rhsgref_cdf_reg_d30_at: rhs_D30_AT_base
	{
		scope = 0;
	};
	class rhsgref_cdf_b_reg_d30_at: rhsgref_cdf_reg_d30_at
	{
		scope = 0;
	};
	class rhsgref_nat_d30_at: rhs_D30_AT_base
	{
		scope = 0;
	};
	class rhsgref_ins_d30_at: rhs_D30_AT_base
	{
		scope = 0;
	};
	class rhsgref_ins_g_d30_at: rhsgref_ins_d30_at
	{
		scope = 0;
	};	
	
	class rhs_casing_122mm;
	class wog_casing_122mm_used: rhs_casing_122mm
	{
		model = "wog_advanced_artillery\ammobox_122\rhs_casing_122mm_used.p3d";
		
		class EventHandlers
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
			
			class WOG_EventHandlers
			{
				init = "_this spawn wog_fnc_init_casing";
			};
		};
	};
};

class Extended_GetIn_Eventhandlers
{
	class wog_D30_base
	{
		class wog_D30_base_getIn
		{
			GetIn = "_this call WOG_fnc_D30_getIn_EH";
		};
	};
	class wog_pab_2m
	{
		class wog_pab_2m_getIn
		{
			GetIn = "_this call WOG_fnc_D30_getIn_EH";
		};
	};
};

class Extended_GetOut_Eventhandlers
{
	class wog_D30_base
	{
		class wog_D30_base_getOut
		{
			GetOut = "_this call WOG_fnc_D30_getOut_EH";
		};
	};
	class wog_pab_2m
	{
		class wog_pab_2m_getOut
		{
			GetOut = "_this call WOG_fnc_D30_getOut_EH";
		};
	};
};