#include "script_component.hpp"
/*
 * Author: Ampersand
 * Attach the given pylon to the given vehicle, pointing forward, at the
 *
 * Arguments:
 * 0: Remote Pylon <OBJECT>
 * 1: Parent Vehicle <OBJECT>
 *
 * Return Value:
 * Success
 *
 * Example:
 * [] call pya_main_fnc_attachForward
 */

params [
    ["_pylon", []],
    ["_vehicle", []]
];

private _position0 = positionCameraToWorld [0, 0, 0];
private _position1 = positionCameraToWorld [0, 0, 100];
private _intersections = lineIntersectsSurfaces [
    AGLToASL _position0, AGLToASL _position1,
    call CBA_fnc_currentUnit, objNull, true, 1, "GEOM"
];
_in = _intersections param [0, []];
_in params [["_pos",[]], ["_n",[]], "", ["_obj", objNull]];
_v attachTo [_obj, _obj worldToModelVisual ASLtoAGL _pos];
_n = _obj vectorWorldToModel _n;
_n set [1, 0]; // Orthogonal to forward
_n = vectorNormalized _n vectorMultiply -1;
_v setVectorUp _n;
_n

/* attach selected pylon
_v = call amp_fnc_gv;
private _position0 = positionCameraToWorld [0, 0, 0];
private _position1 = positionCameraToWorld [0, 0, 100];
private _intersections = lineIntersectsSurfaces [AGLToASL _position0, AGLToASL _position1, cameraOn, objNull, true, 1, "GEOM"];
_in = _intersections param [0, []];
_in params [["_pos",[]], ["_n",[]], "", ["_obj", objNull]];
_v attachTo [_obj, _obj worldToModelVisual ASLtoAGL _pos];
_n = _obj vectorWorldToModel _n;
_n set [1, 0]; // Orthogonal to forward
_n = vectorNormalized _n vectorMultiply -1;
_v setVectorUp _n;
_n
*/
