#include "script_component.hpp"
/*
 * Author: Ampersand
 * Get the gunner view bone of the turret on the vehicle.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Turret Path <ARRAY>
 *
 * Return Value:
 * 0: Bone <STRING>
 *
 * Example:
 * [_vehicle, [0]] call pya_main_fnc_getTurretBone
 */

params ["_vehicle", ["_turretPath", [0]]];

private _turretCfg = [_vehicle, _turretPath] call CBA_fnc_getTurret;
getText (_turretCfg >> "memoryPointGunnerOptics")
