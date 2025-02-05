#include "script_component.hpp"
/*
 * Author: Ampersand
 * Makes the given unit fire their current or their vehicle turret's weapon.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Infinite Ammo <BOOL> (default: false)
 *
 * Return Value:
 * None
 *
 * Example:
 * [_unit] call pya_main_fnc_fireWeapon
 *
 * Public: No
 */

#define SINGLE_FIRE_TIMEOUT 1

params [["_unit", objNull, [objNull]]];

if (CBA_missionTime < _unit getVariable [QGVAR(nextFireTime), 0]) exitWith {};

if (!local _unit) exitWith {
    [QGVAR(fireWeapon), _this, _unit] call CBA_fnc_targetEvent;
};

private _vehicle = vehicle _unit;

private _turretPath = _vehicle unitTurret _unit;
weaponState [_vehicle, _turretPath] params ["_weapon", "_muzzle", "_fireMode", "_magazine"];

GVAR(magazineInfo) getOrDefaultCall [_magazine, {
    private _ammo = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");
    private _missileLockCone = getNumber (configFile >> "CfgAmmo" >> _ammo >> "missileLockCone");
    // Prevent laser weapons from firing too quickly to allow for reliably switching to the desired state
    private _ammoSimulation = getText (configFile >> "CfgAmmo" >> _ammo >> "simulation");

    [_missileLockCone > 0, _ammoSimulation == "laserDesignate"]
}, true] params ["_isGuided", "_isLaser"];

if (_isGuided || {_isLaser}) then {
    _unit setVariable [QGVAR(nextFireTime), CBA_missionTime + SINGLE_FIRE_TIMEOUT];
};

if (_isGuided) then {
    _vehicle addEventHandler ["Fired", FUNC(ehFired)];
};

private _magazine = _vehicle currentMagazineDetailTurret _turretPath;
_magazine call FUNC(parseMagazineDetail) params ["_id", "_owner"];
_vehicle action ["UseMagazine", _vehicle, _unit, _owner, _id];
