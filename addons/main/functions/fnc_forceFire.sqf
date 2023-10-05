#include "script_component.hpp"
/*
 * Author: Ampersand
 * Makes the given units or vehicles fire their current weapons.
 *
 * Arguments:
 * 0: Units <ARRAY>
 * 1: ID <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_units, 0] call zen_common_fnc_forceFire
 *
 * Public: No
 */

#define FORCE_FIRE_TIMEOUT 10

params ["_units", "_id"];

if (isNil QGVAR(forceFiringUnits)) then {
    GVAR(forceFiringUnits) = [];
};

// If no units are given, then stop firing
if (_units isEqualTo []) exitWith {
    GVAR(forceFiringUnits) deleteAt (GVAR(forceFiringUnits) find _id);
};

// Track which curators are forcing fire on local machine
GVAR(forceFiringUnits) pushBackUnique _id;

// Repeatedly fire weapons of local units
private _units = _units select {
    local _x
};

[{
    params ["_args", "_pfhID"];
    _args params ["_units", "_id", "_endTime"];

    if (CBA_missionTime >= _endTime || {!(_id in GVAR(forceFiringUnits))}) exitWith {
        [_pfhID] call CBA_fnc_removePerFrameHandler;
    };

    {
        _x call FUNC(fireWeapon);
    } forEach _units;
}, 0.05, [_units, _id, CBA_missionTime + FORCE_FIRE_TIMEOUT]] call CBA_fnc_addPerFrameHandler;
