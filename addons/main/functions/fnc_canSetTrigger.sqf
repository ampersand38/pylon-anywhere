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
 * [_pylon, _unit] call pya_main_fnc_canSetTrigger
 */

params [
    ["_pylon", objNull],
    ["_unit", call CBA_fnc_currentUnit]
];

!(_unit in (_pylon getVariable [QGVAR(unitsWithTrigger), []]))
&& {_pylon != cameraOn}
