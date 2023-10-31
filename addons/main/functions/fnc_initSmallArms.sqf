#include "script_component.hpp"
/*
 * Author: Ampersand
 * Initilize Small Arms Turret.
 *
 * Arguments:
 * 0: Small Arms Turret <OBJECT>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call pya_main_fnc_initSmallArms
 */

_this call pya_main_fnc_initPylon;
[{
    params ["_turret"];

    if (!isNull (missionNamespace getVariable ["zen_placement_helper", objNull])) exitWith {};

    if (local _turret && {!isNull curatorCamera}) then {
        _turret attachTo [curatorCamera];
    };

    [{
        [_this, 'Init'] call lxws_fnc_droneWeapon;
    }, _turret] call CBA_fnc_execNextFrame;
}, _this] call CBA_fnc_execNextFrame;
