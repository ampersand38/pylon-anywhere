#include "script_component.hpp"
/*
 * Author: Ampersand
 * Toggle the safety on the selected pylon remote trigger.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call pya_main_fnc_input_toggleSafety
 */

private _unit = call CBA_fnc_currentUnit;
private _selectedPylon = _unit getVariable [QGVAR(selectedPylon), objNull];

if (isNull _selectedPylon) exitWith {
    hint "Remote Trigger:\nNone";
};

private _armedPylons = _unit getVariable [QGVAR(armedPylons), []];
private _index = _armedPylons find _selectedPylon;
if (_index > -1) then {
    hint format ["Remote Trigger:\n%1\nStatus: Safe", [_selectedPylon] call pya_main_fnc_pylonName];
    _armedPylons deleteAt _index;
} else {
    hint format ["Remote Trigger:\n%1\nStatus: Armed", [_selectedPylon] call pya_main_fnc_pylonName];
    _armedPylons pushBack _selectedPylon;
};

_unit setVariable [QGVAR(armedPylons), _armedPylons];
