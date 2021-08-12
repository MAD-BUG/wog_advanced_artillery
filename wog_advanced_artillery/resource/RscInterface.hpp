#define WOG_ARTY_GUI_GRID_X	(0)
#define WOG_ARTY_GUI_GRID_Y	(0)
#define WOG_ARTY_GUI_GRID_W	(0.025)
#define WOG_ARTY_GUI_GRID_H	(0.04)

#define SIGHT_GUI_GRID_X safeZoneX + safeZoneH*3/4/2*0.15
#define SIGHT_GUI_GRID_Y safeZoneY
#define SIGHT_GUI_GRID_W safeZoneH*3/4/2
#define SIGHT_GUI_GRID_H safeZoneH

class WOG_ARTY_PREP_D {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "[_this select 0] call WOG_fnc_prep_init_d";
    duration = 1e+011;
    fadein = 0;
    fadeout = 0;
    name = "WOG_ARTY_PREP_D";
	class controls {
		class WOG_Arty_Background {    
			idc = -1;
			type = 0;
			style = 2; //centre text
			x = 5.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 1 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 30 * WOG_ARTY_GUI_GRID_W;
			h = 10 * WOG_ARTY_GUI_GRID_H;
			font = "EtelkaNarrowMediumPro";
			sizeEx = 0.03;
			colorBackground[] = {0,0,0,0.8};
			colorText[] = {0,0,1,1};
			text = "";
		};
		class WOG_Arty_TopBar: WOG_Arty_Background
		{
			h = 1.4 * WOG_ARTY_GUI_GRID_H;
			colorBackground[] = {0,0,0.4,0.8};
		};
		//current charge
		class WOG_Arty_RscCombo_2100: WOG_Arty_RscCombo
		{
			idc = 2100;
			x = 17.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 4 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 16 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
			onLBSelChanged = "[] call wog_advanced_artillery_prep_update;";
		};
		class WOG_Arty_RscText_1000: WOG_Arty_RscText
		{
			idc = 3000;
			text = "$STR_WOG_advanced_artillery_Prep_charges_displayName";
			x = 15.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 1.2 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 12 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
		};
		class WOG_Arty_RscText_1001: WOG_Arty_RscText
		{
			idc = 3001;
			text = "$STR_WOG_advanced_artillery_Current_Charge_displayName";
			x = 6.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 4 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 9 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
		};
		//required charge
		class WOG_Arty_RscCombo_2101: WOG_Arty_RscCombo
		{
			idc = 3101;
			x = 17.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 6 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 16 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
		};
		class WOG_Arty_RscText_1003: WOG_Arty_RscText
		{
			idc = 3003;
			text = "$STR_WOG_advanced_artillery_Required_Charge_displayName";
			x = 6.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 6 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 9 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
		};
		class WOG_Arty_RscButton_1600: WOG_Arty_RscButton
		{
			idc = 3600;
			text = "$STR_WOG_advanced_artillery_Set_Charge_displayName";
			x = 18.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 8 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 6 * WOG_ARTY_GUI_GRID_W;
			h = 2 * WOG_ARTY_GUI_GRID_H;
			soundClick[] = 
			{
				"",
				0.07,
				1
			};
			onMouseButtonClick = "[] call wog_advanced_artillery_start_prep;";
		};
		class WOG_Arty_RscButton_1601: WOG_Arty_RscButton_1600
		{
			idc = 3601;
			text = "$STR_WOG_advanced_artillery_Close_displayName";
			x = 25.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 8 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 6 * WOG_ARTY_GUI_GRID_W;
			h = 2 * WOG_ARTY_GUI_GRID_H;
			onMouseButtonClick = "closeDialog 2;";
		};
	};
};

class WOG_ARTY_LEVEL_D {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    duration = 1e+011;
	onLoad = "[_this select 0] execVM 'wog_advanced_artillery\functions\dialogs\fnc_load_level_d.sqf';";
    fadein = 0;
    fadeout = 0;
    name = "WOG_ARTY_LEVEL_D";
	class controls {
		class WOG_Arty_Background {    
			idc = -1;
			type = 0;
			style = 2; //centre text
			x = 5.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 1 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 30 * WOG_ARTY_GUI_GRID_W;
			h = 15 * WOG_ARTY_GUI_GRID_H;
			font = "EtelkaNarrowMediumPro";
			sizeEx = 0.03;
			colorBackground[] = {0,0,0,0.9};
			colorText[] = {0,0,1,1};
			text = "";
		};
		class WOG_Arty_TopBar: WOG_Arty_Background
		{
			h = 1.4 * WOG_ARTY_GUI_GRID_H;
			colorBackground[] = {0,0,0.6,0.8};
		};
	
		class WOG_Arty_RscText_1000: WOG_Arty_RscText
		{
			idc = 3000;
			text = "$STR_WOG_advanced_artillery_Leveling_displayName";
			x = 15.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 1.2 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 12 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
		};
		class WOG_Arty_RscText_1001: WOG_Arty_RscText
		{
			idc = 3001;
			text = "$STR_WOG_advanced_artillery_Left_Leg_displayName";
			x = 6.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 7 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 9 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
		};
		class WOG_Arty_RscText_1002: WOG_Arty_RscText
		{
			idc = 3002;
			text = "$STR_WOG_advanced_artillery_Right_Leg_displayName";
			x = 6.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 9 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 9 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
		};
		class WOG_Arty_RscText_1003: WOG_Arty_RscText
		{
			idc = 3003;
			text = "$STR_WOG_advanced_artillery_Central_Leg_displayName";
			x = 6.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 11 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 9 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
		};
		
		class WOG_Arty_RscSlider_1950: WOG_Arty_RscSlider
		{
			idc = 1950;
			x = 18.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 4.3 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 5 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
			color[] = {0,1,0,1};
			colorActive[] = {1,1,1,1};
			sliderPosition = 0;
            sliderRange[] = {-1,1};
            sliderStep = 0.1;
			tooltip = "$STR_WOG_advanced_artillery_Transverse_Level_displayName";
		};
		
		class WOG_Arty_RscSlider_1951: WOG_Arty_RscSlider
		{
			idc = 1951;
			style = 0;
			x = 26.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 2.8 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 1 * WOG_ARTY_GUI_GRID_W;
			h = 3.5 * WOG_ARTY_GUI_GRID_H;
			color[] = {0.8,0.2,0,1};
			colorActive[] = {1,1,1,1};
			sliderPosition = 0;
            sliderRange[] = {-1,1};
            sliderStep = 0.1;
			tooltip = "$STR_WOG_advanced_artillery_Longitudinal_Level_displayName";
		};
		
		class WOG_Arty_RscSlider_1900: WOG_Arty_RscSlider
		{
			idc = 3900;
			x = 15.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 7 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 16 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
			color[] = {1,1,1,1};
			colorActive[] = {1,1,1,1};
			onSliderPosChanged = "(player getVariable 'WOG_D30_gunObj') animateSource ['leftLiftT_source', _this select 1]";
			sliderPosition = 0;
            sliderRange[] = {0,1};
            sliderStep = 0.01;
		};
		class WOG_Arty_RscSlider_1901: WOG_Arty_RscSlider
		{
			idc = 3901;
			x = 15.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 9 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 16 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
			color[] = {1,1,1,1};
			colorActive[] = {1,1,1,1};
			onSliderPosChanged = "(player getVariable 'WOG_D30_gunObj') animateSource ['rightLiftT_source', _this select 1]";
			sliderPosition = 0;
            sliderRange[] = {0,1};
            sliderStep = 0.01;
		};
		class WOG_Arty_RscSlider_1902: WOG_Arty_RscSlider
		{
			idc = 3902;
			x = 15.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 11 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 16 * WOG_ARTY_GUI_GRID_W;
			h = 1 * WOG_ARTY_GUI_GRID_H;
			color[] = {1,1,1,1};
			colorActive[] = {1,1,1,1};
			onSliderPosChanged = "(player getVariable 'WOG_D30_gunObj') animateSource ['mainLiftT_source', _this select 1]";
			sliderPosition = 0;
            sliderRange[] = {0,1};
            sliderStep = 0.01;
		};
		class WOG_Arty_RscButton_1601: WOG_Arty_RscButton
		{
			idc = 3601;
			text = "$STR_WOG_advanced_artillery_Close_displayName";
			x = 25.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 13 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 6 * WOG_ARTY_GUI_GRID_W;
			h = 2 * WOG_ARTY_GUI_GRID_H;
			onMouseButtonClick = "closeDialog 2;";
		};
		class WOG_Arty_RscButton_1602: WOG_Arty_RscButton
		{
			idc = 3602;
			style = 0;
			text = "$STR_WOG_advanced_artillery_Fix_Floating_displayName";
			x = 6.5 * WOG_ARTY_GUI_GRID_W + WOG_ARTY_GUI_GRID_X;
			y = 13 * WOG_ARTY_GUI_GRID_H + WOG_ARTY_GUI_GRID_Y;
			w = 11 * WOG_ARTY_GUI_GRID_W;
			h = 2 * WOG_ARTY_GUI_GRID_H;
			colorText[]={0.7,0.7,0,1};
			onMouseButtonClick = "[player getVariable 'WOG_D30_gunObj', [0,0,0.1]] remoteExecCall ['setVelocity', player getVariable 'WOG_D30_gunObj']";
		};
	};
};

class RscTitles 
{
	class WOG_ARTY_D726_45
	{
		idd = -1;
		//idd = 9002;
		duration = 1e+1000;
		movingenable = false;

		fadeIn = 0; 
		fadeOut = 0;
		onLoad = "wog_d30_dials_handle = _this execVM 'wog_advanced_artillery\functions\dialogs\fnc_gun_dials.sqf';";
		class Controls
		{
			class WOG_ARTY_D726_45_background: WOG_Arty_RscPicture
			{
				idc = 77701;
				x = SIGHT_GUI_GRID_X;
				y = SIGHT_GUI_GRID_Y;
				w = SIGHT_GUI_GRID_W;
				h = SIGHT_GUI_GRID_H;
				
				text = "wog_advanced_artillery\resource\data\d-726-45.paa";
			};
			class WOG_ARTY_D726_45_def_large: WOG_Arty_RscText
			{
				idc = 77702;
				style = 2;
				colorText[] = {1,1,1,1};
				colorBackground[] = {0,0,0,0.5};
				font = "PuristaMedium";
				sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.9)";
				shadow = 0;
				text = "00";
				x = SIGHT_GUI_GRID_X + SIGHT_GUI_GRID_W * (645/1024);
				y = SIGHT_GUI_GRID_Y + SIGHT_GUI_GRID_H * (400/2048);
				w = SIGHT_GUI_GRID_W * (45/1024);
				h = SIGHT_GUI_GRID_H * (40/2048);
			};
			class WOG_ARTY_D726_45_def_small: WOG_ARTY_D726_45_def_large
			{
				idc = 77703;
				text = "00";
				x = SIGHT_GUI_GRID_X + SIGHT_GUI_GRID_W * (790/1024);
				y = SIGHT_GUI_GRID_Y + SIGHT_GUI_GRID_H * (535/2048);
			};
			class WOG_ARTY_D726_45_elev_large: WOG_ARTY_D726_45_def_large
			{
				idc = 77704;
				sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.9)";
				text = "0";
				x = SIGHT_GUI_GRID_X + SIGHT_GUI_GRID_W * (527/1024);
				y = SIGHT_GUI_GRID_Y + SIGHT_GUI_GRID_H * (1251/2048);
			};
			class WOG_ARTY_D726_45_elev_small: WOG_ARTY_D726_45_def_large
			{
				idc = 77705;
				sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.9)";
				text = "00";
				x = SIGHT_GUI_GRID_X + SIGHT_GUI_GRID_W * (685/1024);
				y = SIGHT_GUI_GRID_Y + SIGHT_GUI_GRID_H * (1400/2048);
			};
			class WOG_ARTY_D726_45_def_elev: WOG_ARTY_D726_45_def_large
			{
				idc = 77706;
				sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.9)";
				text = "00";
				x = SIGHT_GUI_GRID_X + SIGHT_GUI_GRID_W * (549/1024);
				y = SIGHT_GUI_GRID_Y + SIGHT_GUI_GRID_H * (142/2048);
				w = SIGHT_GUI_GRID_W * (53/1024);
			};
			
			//level
			
			class WOG_ARTY_D726_45_level_background: WOG_Arty_RscPicture
			{
				idc = 77707;
				x = SIGHT_GUI_GRID_X + SIGHT_GUI_GRID_W * (300/1024);
				y = SIGHT_GUI_GRID_Y + SIGHT_GUI_GRID_H * (798/2048);
				w = SIGHT_GUI_GRID_W * (110/1024);
				h = SIGHT_GUI_GRID_H * (220/2048);
				
				text = "wog_advanced_artillery\resource\data\level_background.paa";
			};
			class WOG_ARTY_D726_45_level_bubble: WOG_Arty_RscPicture
			{
				idc = 77708;
				x = SIGHT_GUI_GRID_X + SIGHT_GUI_GRID_W * (300/1024);
				y = SIGHT_GUI_GRID_Y + SIGHT_GUI_GRID_H * (798/2048); //730 - 798 - 866
				w = SIGHT_GUI_GRID_W * (110/1024);
				h = SIGHT_GUI_GRID_H * (220/2048);
				
				text = "wog_advanced_artillery\resource\data\level_bubble.paa";
			};
			class WOG_ARTY_D726_45_level_main: WOG_ARTY_D726_45_level_background
			{
				idc = 77709;
				text = "wog_advanced_artillery\resource\data\level_main.paa";
			};
		};
	};
};