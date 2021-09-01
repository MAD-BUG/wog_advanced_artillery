class RscInGameUI
{
	class RscUnitInfo;
	class rhs_gui_optic_d30_op4: RscUnitInfo
	{
		class CA_IGUI_elements_group;
	};
	
	class wog_gui_optic_d30_op4: rhs_gui_optic_d30_op4
	{
		class CA_IGUI_elements_group: CA_IGUI_elements_group
		{
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 173;
					style = 1;
					sizeEx = "0.068*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "rhs_digital_font";
					text = "$$$$$";
					x = "(-6 + 48) * 		(0.01875 * SafezoneH)";
					y = "0.25 * 		(0.025 * SafezoneH)";
					w = "0 * 		(0.01875 * SafezoneH)";
					h = "0 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsMode: CA_Distance
				{
					idc = 154;
				};
				class RHS_Horizontal: RscPicture
				{
					idc = 4;
					style = "0x30 + 0x800";
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.7,0.0,0.0,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "rhsafrf\addons\rhs_optics\vehicles\data\rhs_1pz3_horizontal.paa";
					x = "3.7 *   (0.01875 * Safezoneh)";
					y = "-9.29 *   (0.025 * SafezoneH)";
					w = "45.9 *   (0.01875 * SafezoneH)";
					h = "45.9 *   (0.025 * SafezoneH)";
				};
				class RHS_Vertical: RHS_Horizontal
				{
					idc = 3;
					text = "rhsafrf\addons\rhs_optics\vehicles\data\rhs_1pz32_vertical.paa";
					x = "13.41 *   (0.01875 * Safezoneh)";
					y = "-8.29 *   (0.025 * SafezoneH)";
				};
				class RHS_Reticle: RHS_Horizontal
				{
					idc = 5;
					text = "rhsafrf\addons\rhs_optics\vehicles\data\rhs_op4m45_ca.paa";
					y = "-11.13 *   (0.025 * SafezoneH)";
				};
			};
		};
	};
};