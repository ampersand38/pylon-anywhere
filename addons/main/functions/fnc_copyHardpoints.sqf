#include "script_component.hpp"
/*
 * Author: Ampersand
 * Returns and copies all CfgMagazines hardpoints except those by BI
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call pya_main_fnc_copyHardpoints
 *
 * Public: No
 */

private _hps = ["B_MISSILE_PYLON","B_AIM9","B_ASRRAM_EJECTOR","B_ASRAAM","B_ZEPHYR","B_AMRAAM","SCALPEL_1RND_EJECTOR","SCALPEL_1RND","UNI_SCALPEL","SCALPEL_4RND","B_SHIEKER","DAGR","DAR","B_BOMB_PYLON","B_A143_BUZZARD_CENTER_PYLON","20MM_TWIN_CANNON","I_ORCA_RIGHT_PYLON","O_MISSILE_PYLON","O_SKYFIRE","O_SAHR3","O_BOMB_PYLON","O_BOMB_PYLON_HELI","B_AMRAAM_C","I_AMRAAM_C","B_AMRAAM_C_RAIL","I_AMRAAM_C_RAIL","B_AMRAAM_C_DUAL_RAIL","I_AMRAAM_C_DUAL_RAIL","B_AMRAAM_D","B_AMRAAM_D_INT","B_AMRAAM_D_RAIL","I_AMRAAM_D_RAIL","B_AMRAAM_D_DUAL_RAIL","I_AMRAAM_D_DUAL_RAIL","B_BIM9X","I_BIM9X","B_BIM9X_RAIL","I_BIM9X_RAIL","B_BIM9X_DUAL_RAIL","I_BIM9X_DUAL_RAIL","B_AGM65","I_AGM65","B_AGM65_DUAL","I_AGM65_DUAL","B_AGM65_RAIL","I_AGM65_RAIL","B_AGM65_DUAL_RAIL","I_AGM65_DUAL_RAIL","B_GBU12","I_GBU12","B_GBU12_DUAL_RAIL","I_GBU12_DUAL_RAIL","O_R73","O_R77","O_R77_INT","O_KH25","O_KH25_INT","O_KAB250_BOMB","RIFLE_MOUNT","LXWS_IED_DRONE_PYLON","ANTIMINE_DRONE_PYLON","UNI_LEAFLETS_PYLON","B_HARM","I_HARM","B_HARM_RAIL","I_HARM_RAIL","B_HARM_INT","I_HARM_INT","B_SDB_QUAD_RAIL","O_KH58","O_KH58_INT","gm_hardpoint_hot","gm_mi2_9m14","gm_mi2_pylon","gm_mi2_9m32_left","gm_mi2_9m32_right","vn_o_missile_pylon_mi2_04","vn_o_missile_pylon_mi2_05","vn_b_rocket_pylon_oh6","vn_b_rocket_pylon_ah1g_05","vn_b_rocket_pylon_ah1g_01","vn_b_rocket_pylon_ah1g_02","vn_b_rocket_pylon_ah1g_03","vn_b_rocket_pylon_uh1c_01","vn_b_rocket_pylon_o_f4","vn_b_rocket_pylon_c_f4","vn_b_rocket_pylon_uh1c_05","vn_b_rocket_pylon_f4_out","vn_b_rocket_pylon_f4_cl","vn_o_missile_pylon_mi2_01","vn_o_missile_pylon","vn_o_rocket_pylon_mig21_out","vn_o_rocket_pylon_mig19_out","vn_o_rocket_pylon_mig19_in","vn_b_rocket_pylon_uh1c_02","vn_b_rocket_pylon_uh34","vn_b_rocket_pylon_f4_in_usaf","vn_b_rocket_pylon_f100_out","vn_b_rocket_pylon_f100_in","vn_b_rocket_pylon_f4_in","vn_b_rocket_pylon_uh1c_03","vn_b_rocket_pylon_uh1c_04","vn_o_missile_pylon_mi2_07","vn_o_missile_pylon_mi2_06","vn_b_rocket_pylon_f100_mid","vn_b_rocket_pylon_ac119_rear","vn_o_missile_pylon_mi2_02","vn_b_rocket_pylon_f4_lau7","vn_b_rocket_pylon_body","vn_o_missile_pylon_mi2_03","vn_b_nose_pylon_uh1e_01","vn_o_rocket_pylon_mig21_cl","vn_b_rocket_pylon_ac119_gau4","vn_b_rocket_pylon_ach47_02","vn_b_rocket_pylon_ac119_gau2","SPE_MG131_Hardpoint","SPE_MG151_Hardpoint","SPE_M2_50cal_Hardpoint","SPE_GER_Bomb_50","SPE_GER_Bomb_250","SPE_US_Bomb_500","SPE_US_Bomb_1000","SPE_GER_Bomb_500","SPE_M8_Hardpoint","SPE_HP_T34_L60","SPE_HP_T34_L60_direct"];
private _hardpoints = [];
{
	private _pylons = getArray (_x >> "hardpoints");
	{
		_hardpoints pushBackUnique _x;
	} forEach _pylons;
} forEach ("true" configClasses (configFile >> "CfgMagazines"));
_hardpoints = _hardpoints - _hps;
copyToClipboard str _hardpoints;
_hardpoints
