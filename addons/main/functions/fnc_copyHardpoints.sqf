#include "script_component.hpp"
/*
 * Author: Ampersand
 * Returns and copies all CfgMagazines hardpoints except those by BI
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call pya_main_fnc_copyHardpoints
 *
 * Public: No
 */

private _hps = getArray (configFile >> "CfgVehicles" >> QGVAR(pylon_single_tgp) >> "Components" >> "TransportPylonsComponent" >> "Pylons" >> "Pylon1" >> "hardpoints");
private _hardpoints = [];
{
	_hardpoints append getArray (_x >> "hardpoints");
    /*
	private _pylons = getArray (_x >> "hardpoints");
	{
		_hardpoints pushBackUnique _x;
	} forEach _pylons;
    */
} forEach ("true" configClasses (configFile >> "CfgMagazines"));
_hardpoints = _hardpoints - _hps;
_hardpoints = _hardpoints arrayIntersect _hardpoints;
copyToClipboard str _hardpoints;
_hardpoints
