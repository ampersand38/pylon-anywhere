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
if !(local _pylon) exitWith {};

group _pylon setCombatMode "BLUE";

// Fix pylon weapon assigned to driver
private _magazine = getPylonMagazines _pylon param [0, ""];
if (_magazine != "") then {
    _pylon setPylonLoadout [1, _magazine, true, [0]];
};

private _parentName = _pylon getVariable [QGVAR(attachParent), ""];
private _vehicle = missionNamespace getVariable [_parentName, objNull];

if (isNull _parent) exitWith {};

private _bone = _pylon getVariable [QGVAR(attachBone), ""];
if (_bone == "") exitWith {
    [_pylon, _vehicle] call BIS_fnc_attachToRelative;
};

if (
    _bone select [0, 1] == "["
) then {
    private _turretPath = parseSimpleArray _bone;
    _bone = [_vehicle, [0]] call pya_main_fnc_getTurretBone;
};

private _matchOrientation = _pylon getVariable [QGVAR(matchOrientation), true];
[_pylon, _vehicle, _bone, _matchOrientation] call pya_main_fnc_attachToRelativeBone;
