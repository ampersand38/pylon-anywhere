#include "script_component.hpp"
/*
 * Author: Ampersand
 * Cycle the selected pylon remote trigger.
 *
 * Arguments:
 * 0: Pylon <OBJECT>
 *
 * Return Value:
 * 0: Name <STRING>
 *
 * Example:
 * [py] call pya_main_fnc_pylonName
 */

params ["_pylon"];

private _magazine = getPylonMagazines _pylon select 0;
private _magazineName = getText (configFile >> "CfgMagazines" >> _magazine >> "displayName");
format ["%1\n%2", groupId group _pylon, _magazineName];
