class CfgFunctions
{
	class WOG_advanced_artillery
	{
		tag = "WOG";
		class Functions
		{
			class fired_D30
			{
				file = "wog_advanced_artillery\effects\wog_d30_fired.sqf";
				description = "Fired effects for D30";
				recompile = 0;
			};
			class pack_D30
			{
				file = "wog_advanced_artillery\effects\wog_d30_pack.sqf";
				description = "Packing D30";
				recompile = 0;
			};
			class take_122_shell
			{
				file = "wog_advanced_artillery\functions\fnc_take_shell.sqf";
				recompile = 0;
			};
			class put_122_shell
			{
				file = "wog_advanced_artillery\functions\fnc_put_shell.sqf";
				recompile = 0;
			};
			class load_d30
			{
				file = "wog_advanced_artillery\functions\fnc_load_d30.sqf";
				recompile = 0;
			};
			class init_casing
			{
				file = "wog_advanced_artillery\effects\fnc_init_casing.sqf";
				recompile = 0;
			};
			class prep_init_d
			{
				file = "wog_advanced_artillery\functions\dialogs\fnc_load_prep_d.sqf";
				recompile = 0;
			};
			class prep_d_canOpen
			{
				file = "wog_advanced_artillery\functions\dialogs\fnc_prep_d_canOpen.sqf";
				recompile = 0;
			};
			class D30_getIn_EH
			{
				file = "wog_advanced_artillery\functions\fnc_getIn.sqf";
				recompile = 0;
			};
			class D30_getOut_EH
			{
				file = "wog_advanced_artillery\functions\fnc_getOut.sqf";
				recompile = 0;
			};
			class D30_keydown_EH
			{
				file = "wog_advanced_artillery\functions\fnc_keydown_EH.sqf";
				recompile = 0;
			};
			class PAB_2M_keydown_EH
			{
				file = "wog_advanced_artillery\functions\pab_2m\fnc_keydown_EH.sqf";
				recompile = 0;
			};
			class D30_traverse
			{
				file = "wog_advanced_artillery\functions\fnc_gun_traverse.sqf";
				recompile = 0;
			};
			class D30_elevate
			{
				file = "wog_advanced_artillery\functions\fnc_gun_elevate.sqf";
				recompile = 0;
			};
			class D30_elevate_sight
			{
				file = "wog_advanced_artillery\functions\fnc_gun_elevate_sight.sqf";
				recompile = 0;
			};
			class D30_elevate_dials
			{
				file = "wog_advanced_artillery\functions\fnc_gun_elevate_dials.sqf";
				recompile = 0;
			};
			class D30_revolve_dials
			{
				file = "wog_advanced_artillery\functions\fnc_gun_revolve_dials.sqf";
				recompile = 0;
			};
			class D30_can_towing
			{
				file = "wog_advanced_artillery\functions\fnc_can_towing.sqf";
				recompile = 0;
			};
			class D30_towing
			{
				file = "wog_advanced_artillery\functions\fnc_towing_d30.sqf";
				recompile = 0;
			};
			class rangeTablePageChange
			{
				file = "wog_advanced_artillery\functions\fnc_rangeTablePageChange.sqf";
				recompile = 0;
			};
			class rangeTableOpen
			{
				file = "wog_advanced_artillery\functions\fnc_rangeTableOpen.sqf";
				recompile = 0;
			};
			class initAmmobox
			{
				file = "wog_advanced_artillery\functions\fnc_init_ammobox.sqf";
				recompile = 0;
			};
			class PAB_2M_base_traverse
			{
				file = "wog_advanced_artillery\functions\pab_2m\fnc_pab_2m_base_traverse.sqf";
				recompile = 0;
			};
			class PAB_2M_uglomer_rotation
			{
				file = "wog_advanced_artillery\functions\pab_2m\fnc_pab_2m_uglomer_rotation.sqf";
				recompile = 0;
			};
			class PAB_2M_place
			{
				file = "wog_advanced_artillery\functions\pab_2m\fnc_pab_2m_place.sqf";
				recompile = 0;
			};
			class PAB_2M_leveling
			{
				file = "wog_advanced_artillery\functions\pab_2m\fnc_pab_2m_leveling.sqf";
				recompile = 0;
			};
			class PAB_2M_pickup
			{
				file = "wog_advanced_artillery\functions\pab_2m\fnc_pab_2m_pickup.sqf";
				recompile = 0;
			};
			class changeLocality
			{
				file = "wog_advanced_artillery\functions\fnc_changeLocality.sqf";
				recompile = 0;
			};
			class closeBreech
			{
				file = "wog_advanced_artillery\functions\fnc_closeBreech.sqf";
				recompile = 0;
			};
			class apost_toggle_light
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_apost_toggle_light.sqf";
				recompile = 0;
			};
			class apost_move_light
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_apost_move_light.sqf";
				recompile = 0;
			};
			class collim_adjust_sight
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_collim_adjust_sight.sqf";
				recompile = 1;
			};
			class collim_toggle_light
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_collim_toggle_light.sqf";
				recompile = 1;
			};
			class collim_handler
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_collim_handler.sqf";
				recompile = 1;
			};
			class collim_addKeys
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_collim_addKeys.sqf";
				recompile = 1;
			};
			class collim_removeKeys
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_collim_removeKeys.sqf";
				recompile = 1;
			};
			class collim_keyEvent
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_collim_keyEvent.sqf";
				recompile = 1;
			};
			class aimingpoints_place
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_aimingpoints_place.sqf";
				recompile = 1;
			};
			class aimingpoints_pickup
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_aimingpoints_pickup.sqf";
				recompile = 1;
			};
			class apost_getDistanceToClosest
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_apost_getDistanceToClosest.sqf";
				recompile = 1;
			};
			class apost_digging
			{
				file = "wog_advanced_artillery\functions\aimingpoints\fnc_apost_digging.sqf";
				recompile = 1;
			};
		};
	};
};