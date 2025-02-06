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

#ifdef DEBUG_MODE_FULL
    systemChat "init";
#endif

_this call pya_main_fnc_initPylon;

params ["_vehicle"];

if (!local _vehicle) exitWith {};

if (!isNull (missionNamespace getVariable ["zen_placement_helper", objNull])) exitWith {};

if (local _vehicle && {!isNull curatorCamera}) then {
    _vehicle attachTo [curatorCamera];
};

private _agent = createAgent [QGVAR(smallarms_dummy), [0, 0, 0], [], 0, "CAN_COLLIDE"];
//private _agent = createAgent [typeOf player, [0, 0, 0], [], 0, "CAN_COLLIDE"];
_agent attachTo [_vehicle, [0, 0, 0], "mainGun", true];
_vehicle setVariable [QGVAR(smallarms_dummy), _agent, true];
private _weapon = _vehicle getVariable ["lxws_holdingWeapon", []];
[_agent, _weapon] call pya_main_fnc_setWeaponLoadout;
_agent switchMove format ["AmovPercMstpSrasW%1Dnon", ["rfl", "lnr", "pst"] select _loadoutIndex];

//}, _this] call CBA_fnc_execNextFrame;
