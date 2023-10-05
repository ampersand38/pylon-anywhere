#include "script_component.hpp"
/*
 * Author: Ampersand
 * Attach the given pylon to the given vehicle, pointing forward, at the
 *
 * Arguments:
 * 0: Activated <BOOLEAN>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call pya_main_fnc_input_firePylons
 */

params ["_activated"];

private _unit = call CBA_fnc_currentUnit;
private _units = [];

if (_activated) then {
    private _armedPylons = _unit getVariable [QGVAR(armedPylons), []];
    _units = _armedPylons select {
        alive _x
        && {(_x ammoOnPylon 1) isEqualType 0}
        && {!isNull gunner _x}
    } apply {gunner _x};
};

[QGVAR(forceFire), [_units, CBA_clientID]] call CBA_fnc_globalEvent;
