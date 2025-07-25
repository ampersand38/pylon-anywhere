#include "script_component.hpp"
/*
 * Author: Ampersand
 * Initilize pylon. Ensure weapon is assigned to gunner. Check for attach attributes.
 *
 * Arguments:
 * 0: Remote Pylon <OBJECT>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call pya_main_fnc_initPylon
 */

params ["_pylon"];


private _combatmode_blue = _pylon getVariable [QGVAR(combatmode_blue), true];
if (_combatmode_blue) then {
    group _pylon setCombatMode "BLUE";
};

if !(local _pylon) exitWith {};

// Fix pylon weapon assigned to driver
private _magazine = getPylonMagazines _pylon param [0, ""];
if (_magazine != "") then {
    _pylon setPylonLoadout [1, _magazine, true, [0]];
};

private _parentName = _pylon getVariable [QGVAR(attachParent), ""];
private _vehicle = missionNamespace getVariable [_parentName, objNull];

if (isNull _vehicle) exitWith {
    #ifdef DEBUG_MODE_FULL
        systemChat "No parent";
    #endif
};

private _bone = _pylon getVariable [QGVAR(attachBone), ""];
if (_bone == "") exitWith {
    #ifdef DEBUG_MODE_FULL
        systemChat "No bone";
    #endif
    [_pylon, _vehicle] call BIS_fnc_attachToRelative;
};

if (_bone select [0, 1] in "[0123456789") then {
private _turretPath = _bone splitString "[,]" apply {parseNumber _x};
_bone = [_vehicle, _turretPath] call pya_main_fnc_getTurretBone;
};

private _matchOrientation = _pylon getVariable [QGVAR(matchOrientation), true];
[_pylon, _vehicle, _bone, _matchOrientation] call pya_main_fnc_attachToRelativeBone;
