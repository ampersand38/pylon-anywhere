#include "script_component.hpp"
/*
 * Author: Ampersand
 * Small arms dummy.
 *
 * Arguments:
 * Fired EH
 *
 * Return Value:
 * None
 *
 */

params ["_dummy", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

deleteVehicle _projectile;
