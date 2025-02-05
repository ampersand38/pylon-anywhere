#include "script_component.hpp"
/*
 * Author: Ampersand
 * Initilize Small Arms Dummy.
 *
 * Arguments:
 * 0: Small Arms Dummy <OBJECT>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [_unit] call pya_main_fnc_initSmallArmsDummy
 */

params ["_unit"];

_unit disableAI "ALL";
