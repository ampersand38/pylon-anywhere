#include "script_component.hpp"

[QGVAR(fireWeapon), FUNC(fireWeapon)] call CBA_fnc_addEventHandler;
[QGVAR(forceFire), FUNC(forceFire)] call CBA_fnc_addEventHandler;

[QGVAR(lockCameraTo), {
    params ["_vehicle", "_target", "_turretPath", "_temporary"];
    _vehicle lockCameraTo [_target, _turretPath, _temporary];
}] call CBA_fnc_addEventHandler;
