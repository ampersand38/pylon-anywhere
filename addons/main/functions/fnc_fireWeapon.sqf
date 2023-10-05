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

#define LASER_WEAPON_TIMEOUT 1

params [["_unit", objNull, [objNull]]];

if (!local _unit) exitWith {
    [QGVAR(fireWeapon), _this, _unit] call CBA_fnc_targetEvent;
};

private _vehicle = vehicle _unit;

private _turretPath = _vehicle unitTurret _unit;
weaponState [_vehicle, _turretPath] params ["_weapon", "_muzzle", "_fireMode", "_magazine"];

// Prevent laser weapons from firing too quickly to allow for reliably switching to the desired state
private _ammo = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");
private _ammoSimulation = getText (configFile >> "CfgAmmo" >> _ammo >> "simulation");

if (_ammoSimulation == "laserDesignate") then {
    _unit setVariable [QGVAR(nextFireTime), CBA_missionTime + LASER_WEAPON_TIMEOUT];
};

private _magazine = _vehicle currentMagazineDetailTurret _turretPath;
_magazine call FUNC(parseMagazineDetail) params ["_id", "_owner"];
_vehicle action ["UseMagazine", _vehicle, _unit, _owner, _id];
