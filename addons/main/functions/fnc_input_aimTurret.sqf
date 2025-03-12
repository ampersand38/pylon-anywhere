#include "script_component.hpp"
/*
 * Author: Ampersand
 * Aim the selected turret along the camera direction.
 *
 * Arguments:
 * 0: Activated <BOOLEAN>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call pya_main_fnc_input_aimTurret
 */

params ["_activated"];

if !(_activated) exitWith {};

private _unit = call CBA_fnc_currentUnit;
private _selectedPylon = _unit getVariable [QGVAR(selectedPylon), objNull];

if (isNull _selectedPylon) exitWith {
    hint "Remote Turret:\nNone";
};

private _target = if (isNull cursorObject) then {
    positionCameraToWorld [0, 0, 10000]
} else {
    [cursorObject, objNull] select (cursorObject in [_selectedPylon, attachedTo _selectedPylon])
};

[_selectedPylon, _target] call FUNC(forceWatch);
