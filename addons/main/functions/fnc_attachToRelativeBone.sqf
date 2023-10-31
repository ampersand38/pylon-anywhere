#include "script_component.hpp"
/*
 * Author: Ampersand
 * Attach the given pylon to the given vehicle, pointing forward, at the
 *
 * Arguments:
 * 0: Remote Pylon <OBJECT>
 * 1: Turret <ARRAY> Turret path. Driver [-1], Main Turret [0]
 *
 * Return Value:
 * Success
 *
 * Example:
 * [_pylon, _vehicle, _bone] call pya_main_fnc_attachToRelativeBone
 */

#define LOD_MEMORY 1e15

params ["_child", "_parent", ["_bone", ""], ["_matchOrientation", true], ["_lod", LOD_MEMORY]];

if (!isNull attachedTo _child) then {detach _child;}; // Get vectors in world space

private _childPos = _parent worldToModel ASLToAGL getPosWorldVisual _child;
private _childY = _parent vectorWorldToModelVisual vectorDirVisual _child;
private _childZ = _parent vectorWorldToModelVisual vectorUpVisual _child;
private _childX = _childY vectorCrossProduct _childZ;

private _bonePos = _parent selectionPosition [_bone, _lod];
private _offset = _childPos vectorDiff _bonePos;
_parent selectionVectorDirAndUp [_bone, _lod] params ["_boneY", "_boneZ"];
if (_boneY isEqualTo [0, 0, 0]) then {
    _boneY set [1, 1];
    _boneZ set [2, 1];
};
private _boneX = _boneY vectorCrossProduct _boneZ;

private _m = matrixTranspose [_boneX, _boneY, _boneZ];
private _pos = flatten ([_offset] matrixMultiply _m);
_child attachTo [_parent, _pos, _bone, true];

if (_matchOrientation) exitWith {};

_m matrixMultiply [_childX, _childY, _childZ] params ["", "_vY", "_vZ"];
_child setVectorDirAndUp [_vY, _vZ];
