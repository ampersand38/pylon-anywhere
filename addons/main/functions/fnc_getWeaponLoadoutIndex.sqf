#include "script_component.hpp"
/*
 * Author: Ampersand
 * Get the index of the loadout array for the given weapon.
 *
 * Arguments:
 * 0: Weapon <STRING>
 *
 * Return Value:
 * 0: Loadout Index <NUMBER>
 *
 * Example:
 * [_weapon] call pya_main_fnc_getWeaponLoadoutIndex
 */

params ["_weapon"];

[1, 4, 2] find getNumber (configFile >> "CfgWeapons" >> _weapon >> "type"); // Rifle: 1, Pistol: 2, Launcher: 4

