class RscPicture;
class RscText;
class RscListNBox;
class ScrollBar;
class RscListbox;
class RscActiveText;

class WOG_D30_RangeTable_Dialog
{
	idd=-1;
	movingEnable=1;
	onLoad="uiNamespace setVariable ['WOG_D30_RangeTable_Dialog', _this select 0];";
	objects[]={};
	class ControlsBackground
	{
		class TableBackground: RscPicture
		{
			idc=-1;
			text="\z\ace\addons\ruPal_RHS_to_ACE\UI\RangeTable_background.paa";
			x="18 *(safeZoneH / 40) +       (safezoneX + (safezoneW - safeZoneH)/2)";
			y="1 * ((safeZoneH / 1.2) / 25) +   (safezoneY + (safezoneH - (safeZoneH / 1.2))/2)";
			w="16.2634559672906 * (safeZoneH / 40)";
			h="23 * ((safeZoneH / 1.2) / 25)";
			colorBackground[]={1,1,1,1};
		};
		class ChargeBackground: RscText
		{
			idc=-1;
			x="12 *(safeZoneH / 40) +       (safezoneX + (safezoneW - safeZoneH)/2)";
			y="1 * ((safeZoneH / 1.2) / 25) +   (safezoneY + (safezoneH - (safeZoneH / 1.2))/2)";
			w="6 * (safeZoneH / 40)";
			h="5 * ((safeZoneH / 1.2) / 25)";
			colorBackground[]={0,0,0,1};
		};
	};
	class controls
	{
		class TheTable: RscListNBox
		{
			idc=20001;
			x="18 *(safeZoneH / 40) +       (safezoneX + (safezoneW - safeZoneH)/2)";
			y="3.76 * ((safeZoneH / 1.2) / 25) +   (safezoneY + (safezoneH - (safeZoneH / 1.2))/2)";
			w="16.2634559672906 * (safeZoneH / 40)";
			h="20.24 * ((safeZoneH / 1.2) / 25)";
			columns[]=
			{
				"(10/867)",
				"(86/867)",
				"(171/867)",
				"(238/867)",
				"(320/867)",
				"(405/867)",
				"(485/867)",
				"(546/867)",
				"(607/867)",
				"(668/867)",
				"(729/867)",
				"(790/867)"
			};
			rowHeight="0.015 * safeZoneH";
			sizeEx="0.014 * safeZoneH";
			font="EtelkaMonospacePro";
			drawSideArrows=1;
			idcLeft=14124;
			idcRight=412343243;
			colorText[]={0,0,0,1};
			shadow="0";
			colorSelectBackground[]={0,0,0,0.025};
			colorSelectBackground2[]={0,0,0,0.025};
			colorScrollbar[]={0.94999999,0,0.94999999,1};
			class ListScrollBar: ScrollBar
			{
				color[]={0,0,0,0.60000002};
			};
		};
		class ChargeListBox: RscListbox
		{
			idc=1501;
			style="ST_RIGHT";
			x="12 *(safeZoneH / 40) + (safezoneX + (safezoneW - safeZoneH)/2)";
			y="1 * ((safeZoneH / 1.2) / 25) + (safezoneY + (safezoneH - (safeZoneH / 1.2))/2)";
			w="6 * (safeZoneH / 40)";
			h="5 * ((safeZoneH / 1.2) / 25)";
			onLBSelChanged="_this call WOG_fnc_rangeTablePageChange";
		};
		class CloseBackground: RscText
		{
			idc=-1;
			x="33.7634559672906 *(safeZoneH / 40) + (safezoneX + (safezoneW - safeZoneH)/2)";
			y="1 * ((safeZoneH / 1.2) / 25) + (safezoneY + (safezoneH - (safeZoneH / 1.2))/2)";
			w="0.5 * (safeZoneH / 40)";
			h="0.5 * ((safeZoneH / 1.2) / 25)";
			colorBackground[]={0,0,0,0.5};
		};
		class CloseActiveText: RscActiveText
		{
			idc=-1;
			style=48;
			color[]={1,1,1,0.69999999};
			text="A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
			x="33.7634559672906 *(safeZoneH / 40) + (safezoneX + (safezoneW - safeZoneH)/2)";
			y="1 * ((safeZoneH / 1.2) / 25) +   (safezoneY + (safezoneH - (safeZoneH / 1.2))/2)";
			w="0.5 * (safeZoneH / 40)";
			h="0.5 * ((safeZoneH / 1.2) / 25)";
			colorText[]={1,1,1,0.69999999};
			colorActive[]={1,1,1,1};
			tooltip="Close";
			onButtonClick="closeDialog 0";
		};
	};
};