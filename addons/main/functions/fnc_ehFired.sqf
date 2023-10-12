#include "script_component.hpp"
/*
 * Author: Ampersand
 * Initilize pylon. Ensure weapon is assigned to gunner. Check for attach attributes.
 *
 * Arguments:
 * 0: Remote Pylon <OBJECT>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call pya_main_fnc_ehFired
 */

params ["_pylon", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

_pylon spawn {sleep 1; _this setVehicleAmmo 1;};
//copyToClipboard _ammo;

private _cfgAmmo = configFile >> "CfgAmmo" >> _ammo;
private _maxAngle = getNumber (_cfgAmmo >> "missileLockCone") / 2;
private _maxDistance = getNumber (_cfgAmmo >> "missileLockMaxDistance");
private _maxSpeed = getNumber (_cfgAmmo >> "missileLockMaxSpeed");
private _minDistance = getNumber (_cfgAmmo >> "missileLockMinDistance");

private _targets = _projectile nearEntities [["LaserTarget", "Air", "Ship", "LandVehicle"], _maxDistance] apply {
    private _v = _projectile worldToModel ASLToAGL getPosASL _x;
    _v params ["_vx", "_vy", "_vz"];
    private _mag = vectorMagnitude _v;
    private _angle = acos (_vy / _mag);
//systemChat str [typeOf _x, _mag, _mag < _minDistance,_angle, _angle > _maxAngle,speed _x toFixed 0, speed _x > _maxSpeed];
    if (
        _mag < _minDistance
        || {_angle > _maxAngle}
        || {speed _x / 3.6 > _maxSpeed}
    ) then {
        []
    } else {
        [_x, _angle / _maxAngle + _mag / _maxDistance] // Score for angle and distance
    };
};
_targets = [_targets, [], {_x # 1}, "ASCEND", {_x isNotEqualTo []}] call BIS_fnc_sortBy;

//systemChat str [count _targets, []];
{
    _x params ["_target", "_score"];
//systemChat str [_target, _score];
    if (_projectile setMissileTarget _target) then {
//        [[["LINE", [ASLToAGL getPosASL _projectile, _target]]], 3] call zen_common_fnc_drawHint;
        //systemChat str [_target, _score toFixed 3];
        break
    };
} forEach _targets;

_pylon removeEventHandler [_thisEvent, _thisEventHandler];
