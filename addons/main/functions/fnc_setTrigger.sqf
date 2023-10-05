#include "script_component.hpp"
/*
 * Author: Ampersand
 * Attach the given pylon to the given vehicle, pointing forward, at the
 *
 * Arguments:
 * 0: Remote Pylon <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [_pylon, _unit] call pya_main_fnc_setTrigger
 */

params [
    ["_pylon", objNull],
    ["_unit", call CBA_fnc_currentUnit]
];

private _unitsWithTrigger = _pylon getVariable [QGVAR(unitsWithTrigger), []];
private _linkedPylons = _unit getVariable [QGVAR(linkedPylons), []];
private _armedPylons = _unit getVariable [QGVAR(armedPylons), []];
_armedPylons = _armedPylons - [_pylon];

if (_pylon in _linkedPylons) then {
    _unitsWithTrigger = _unitsWithTrigger - [_unit];
    _linkedPylons = _linkedPylons - [_pylon];
    hint format ["Removed remote trigger for:\n%1", [_pylon] call pya_main_fnc_pylonName];
} else {
    _linkedPylons pushBackUnique _pylon;
    _unitsWithTrigger pushBackUnique _unit;
    hint format ["Added and safed remote trigger for:\n%1", [_pylon] call pya_main_fnc_pylonName];
};

_unit setVariable [QGVAR(armedPylons), _armedPylons, true];
_unit setVariable [QGVAR(linkedPylons), _linkedPylons, true];
_pylon setVariable [QGVAR(unitsWithTrigger), _unitsWithTrigger, true];
