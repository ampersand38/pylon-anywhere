#include "script_component.hpp"
/*
 * Author: Ampersand
 * Add the weapon to the unit.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Weapon <STRING>
 *
 * Return Value:
 * 0: Loadout Index <NUMBER>
 *
 * Example:
 * [_unit, _weapon] call pya_main_fnc_setWeaponLoadout
 */

params ["_unit", "_weapon"];

private _loadoutIndex = _weapon call pya_main_fnc_getWeaponLoadoutIndex;
private _loadout = [
    nil,
    nil,
    nil,
    nil,
    nil,
    nil,
    nil,
    nil,
    nil,
    nil
];
_loadout set [_loadoutIndex, _weapon];
_unit setUnitLoadout _loadout;
