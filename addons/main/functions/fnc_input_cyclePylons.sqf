#include "script_component.hpp"
/*
 * Author: Ampersand
 * Cycle the selected pylon remote trigger.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call pya_main_fnc_input_cyclePylons
 */

private _unit = call CBA_fnc_currentUnit;
private _linkedPylons = _unit getVariable [QGVAR(linkedPylons), []];
_linkedPylons = _linkedPylons - [objNull];

if (_linkedPylons isEqualTo []) exitWith {};

private _selectedPylon = _unit getVariable [QGVAR(selectedPylon), objNull];

private _index = (_linkedPylons find _selectedPylon) + 1;
_selectedPylon = if (_index < count _linkedPylons) then {
    _linkedPylons select _index;
} else {
    objNull
};

private _armedPylons = _unit getVariable [QGVAR(armedPylons), []];
private _status = if (_selectedPylon in _armedPylons) then {
    "Armed"
} else {
    "Safe"
};

if (isNull _selectedPylon) then {
    hint "Remote Trigger:\nNone";
} else {
    hint format ["Remote Trigger:\n%1\nStatus: %2", [_selectedPylon] call pya_main_fnc_pylonName, _status];
};

_unit setVariable [QGVAR(selectedPylon), _selectedPylon];
