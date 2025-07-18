#include "script_component.hpp"
/*
 * Author: Ampersand
 * Handles input to jettison pylons from the vehicle.
 *
 * Arguments:
 * 0: Mode <NUMBER>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [0] call pya_main_fnc_input_jettison
// #define JETTISON_MODE_ALL 0
// #define JETTISON_MODE_SELECTED 1
// #define JETTISON_MODE_DOGFIGHT 2
 */

params ["_mode"];

private _unit = call CBA_fnc_currentUnit;
if (isRemoteControlling _unit) then {
    _unit = remoteControlled _unit;
};
if (
    cameraOn isNotEqualTo objectParent _unit
    || {cameraOn getCargoIndex _unit != -1}
) exitWith {};

[cameraOn, _mode] call pya_main_fnc_jettison;
