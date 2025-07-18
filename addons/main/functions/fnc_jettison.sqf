#include "script_component.hpp"
/*
 * Author: Ampersand
 * Makes the given units or vehicles fire their current weapons.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Mode <NUMBER>
 *     0 - Jettison all pylons
 *     1 - Jettison only currently selected pylon
 *     2 - Jettison all pylons which are not guns or Air-to-Air missiles
 *
 * Return Value:
 * None
 *
 * Example:
 * [_vehicle, 0] call pya_main_fnc_jettison
 *
 * Public: No
 */

// #define JETTISON_MODE_ALL 0
// #define JETTISON_MODE_SELECTED 1
// #define JETTISON_MODE_DOGFIGHT 2
// addUserActionEventHandler ["transportNightVision", "Activate", {[cameraOn] call pya_main_fnc_jettison}];

params ["_vehicle", ["_mode", 0]];

{
    //_x params ["_pylon", "_name", "_turret", "_magazine", "_ammo", "_magazineDetail", "_position", "_dir", "_up"];
    _x params ["_pylon", "", "", "_magazine", "_ammo", "", "_position"];

    if (_magazine == "") then { continue; };

    private _ammoClass = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");
    private _missileLockMaxSpeed = getNumber (configFile >> "CfgAmmo" >> _ammoClass >> "missileLockMaxSpeed");
    if ( _mode == JETTISON_MODE_SELECTED
        && {_magazine != currentMagazine cameraOn}
    ) then { continue; };
    if ( _mode == JETTISON_MODE_DOGFIGHT
        && {_missileLockMaxSpeed isEqualType 0}
        && {_missileLockMaxSpeed > 100}
    ) then { continue; };

    private _pylonDummy = "pya_main_pylon_detached" createVehicle [0, 0, 0];
    _pylonDummy setPylonLoadout [1, _magazine, true];
    _pylonDummy setAmmoOnPylon [1, _ammo];
    _pylonDummy hideObject true;

    private _offset = GVAR(pylonMagazineOffsetMap) getOrDefaultCall [_magazine, {
        private _model = getText (configFile >> "CfgMagazines" >> _magazine >> "model");
        private _offset = [0, 0, 0];
        if (_model != "") then { // exitWith doesn't work inside getOrDefaultCall
            private _magObj = createSimpleObject [_model, [0, 0, 0], false];

            _selection = selectionNames _magObj select {"proxy" in _x} param [0, ""];
            if ("proxy" in _selection) then {
                _offset = _magObj selectionPosition _selection;
            };
            deleteVehicle _magObj;
        };
        _offset vectorMultiply -1
    }, true];

    _pylonDummy attachTo [_vehicle, [0, 1/3, 0.5] vectorAdd _offset vectorAdd _position # 0];
    _pylonDummy disableCollisionWith _vehicle;
    _pylonDummy allowDamage false;
    _pylonDummy setMass (getNumber (configFile >> "CfgMagazines" >> _magazine >> "mass"));

    [{
        params ["_vehicle", "_pylon", "_pylonDummy"];
        _pylonDummy hideObject false;
        _vehicle setPylonLoadout [_pylon, "", false, []];
        detach _pylonDummy;
        _pylonDummy setVelocity (velocity _vehicle); //  vectorAdd [0,0,-1]
        _pylonDummy addTorque [-5 + random 10, -5 + random 10, -5 + random 10];
    }, [_vehicle, _pylon, _pylonDummy], 1 + random 1] call CBA_fnc_waitAndExecute;
} forEach getAllPylonsInfo _vehicle;
