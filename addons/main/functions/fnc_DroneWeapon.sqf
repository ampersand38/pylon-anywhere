#include "script_component.hpp"
/*
    Author: Ampersand

    Description:
        Controls Small Arms weapons

    Parameter(s):
        0: Vehicle (Object)
        1: Mode (String) One from: "Init", "SetWeapon", "SetWeaponInit"
        2: Arguments (Array)

    Returns:
        Nothing

    Note:
        You can set a drone's weapon via this format:
        [
            uav,
            "SetWeapon",
            [
                primaryWeaponClassName,"","","",
                [primaryMagazine, magCount],
                [secondaryMagazine, magCount],
                ""
            ]
        ] call pya_main_fnc_droneWeapon;

        The parameter #2 is the same format with Unit Loadout Array.
        For more info go check https://community.bistudio.com/wiki/Unit_Loadout_Array.

    Note #2:
        You can stop someone to add or remove weapon via:
            uav setVariable ["DisableRearm",1];    // 1 to disable ability to add/remove
*/

#ifdef DEBUG_MODE_FULL
    systemChat "attribute";
#endif

params ["_uav","_mode","_args"] ;

#define ACTIONDIST 2.75

private _UAVName = getText (configOf _uav >> "displayName");

if (_mode == "Init") exitWith {    // Initialization - adds action
    //removeAllActions _uav ;    // Debug. Todo remove
    //_uav removeAllEventHandlers "Fired" ;    // Same
    //clearWeaponCargoGlobal _uav ;    // Same
    _uav lockInventory true ;
    /*_uav setVariable ["lxws_holdingWeapon",
        _uav getVariable ["lxws_holdingWeapon",[]],
    true] ;*/

    private _initialized = _uav getVariable ["lxws_initialized",false] ;

    // If the drone is deployed ingame for the first time
    if (!is3DEN and time > 1 and !_initialized) then {
        [_uav,"SetWeaponInit",getArray (configOf _uav >> "lxws_droneWeapon")] call pya_main_fnc_droneWeapon ;
    } ;

    // If deployed
    if (!is3DEN and count (_uav getVariable ["lxws_holdingWeapon",[]]) != 0) then {
        [_uav,"SetWeapon",(_uav getVariable ["lxws_holdingWeapon",[]])] call pya_main_fnc_droneWeapon ;
    } ;

    // Eden placed drones
    if (is3DEN) then {
        _uav spawn {
            if (
                count (_this get3DENAttribute "lxws_holdingWeapon") == 0 or {
                    (_this get3DENAttribute "lxws_holdingWeapon")#0 isEqualTo ""
                }
            ) then {
                _this set3DENAttribute ["lxws_holdingWeapon",getArray (configOf _this >> "lxws_droneWeapon")] ;
            } ;
        } ;
    } ;

    // Make sure that EH and actions are not added yet
    if (!_initialized) then {
        _uav addEventHandler ["Fired",{
            params ["_uav","_weapon","_muzzle","","","_magazine","_projectile"] ;

            // Gets weapon info
            private _holdingWeapon = _uav getVariable ["lxws_holdingWeapon",[]] ;

            // Make sure the weapon is the thing that it holds
            if (_holdingWeapon#0 != _weapon) exitWith {} ;

            // Gets ammo count
            private _magazines = magazinesAmmo _uav ;
            private _ammoCount = call {
                private _return = (_magazines findIf {_x#0 == _magazine}) ;
                if (_return == -1) then {
                    0
                } else {
                    _magazines#_return#1
                } ;
            } ;
            _holdingWeapon#(call {
                if (_weapon == _muzzle) then {4} else {5}
            }) set [1,_ammoCount] ;

            // Updates weapon info
            _uav setVariable ["lxws_holdingWeapon",_holdingWeapon,true] ;

            // If is a main muzzle
            private "_recoil" ;
            if (_weapon == _muzzle) then {

                // Muzzle flash
                /*private _zasleh = _uav getVariable ["lxws_muzzleFlash",["",[0,0,0]]] ;
                //private _rot = random 360 ;
                //_zasleh setVectorDirAndUp [[cos _rot,0,sin -_rot],[sin _rot,0,cos _rot]] ;
                // Flash!
                drop [
                    [_zasleh#0,1,0,1,0],"","SpaceObject",
                    1,0.02,[0,0,0],[0,0,0],
                    1,6,1,0,
                    [1],
                    [],
                    [],
                    0.1,0.05,"","",
                    _uav,0,
                    false,-1,
                    [],vectorDir _uav
                ] ;*/

                _recoil = getArray (configFile >> "CfgRecoils" >> getText (configFile >> "CfgWeapons" >> _weapon >> "recoil") >> "kickBack")
            } else {
                _recoil = getArray (configFile >> "CfgRecoils" >> getText (configFile >> "CfgWeapons" >> _weapon >> _muzzle >> "recoil") >> "kickBack")
            } ;

            // Make sure the vars are numbers not strings
            _recoil = _recoil apply {
                if (_x isEqualType "") then {
                    _x call BIS_fnc_parseNumber
                } else {
                    _x
                } ;
            } ;

            // Add recoil
            _uav addForce [(vectorNormalized velocity _projectile) vectorMultiply -1000 vectorMultiply
                linearConversion [0,1,random 1,_recoil#0,_recoil#1]
            ,[0,0,-0.2]] ;

            private _agent = _vehicle getVariable [QGVAR(smallarms_dummy), objNull];
            weaponState _agent params ["", "_muzzle", "_fireMode"];
            _agent forceWeaponFire [_muzzle, _fireMode];
        }] ;

        private _actionID = _uav addAction [localize "STR_A3_C_in1_taskBIS_goArmory_title" + " " + _UAVName,
            {
                params ["_target","_caller","_actionId","_arguments"] ;

                // Animate
                _caller playActionNow "putDown" ;

                // Execute
                private _weapon = currentWeapon _caller;
                private _weaponType = getNumber (configFile >> "CfgWeapons" >> _weapon >> "type"); // Rifle: 1, Pistol: 2, Launcher: 4
                private _loadoutIndex = [1, 4, 2] find _weaponType; // loadout order
                [_target,"SetWeapon",(getUnitLoadout _caller)#_loadoutIndex] call pya_main_fnc_droneWeapon ;

                // Removes weapon from player
                _caller removeWeapon _weapon ;
                // todo remove comment
            },
            [_x],
            1,
            true,
            false,
            "",
            // Condition checks
            format ["
                    if (!alive _target) exitWith {removeAllActions _target ; false} ;
                    if (_target getVariable ['DisableRearm',0] == 1) exitWith {false} ;
                    if (vehicle _this == _target) exitWith {false} ;
                    if (vehicle _this != _this) exitWith {false} ;

                    (currentWeapon _this != '') and
                    {(_target getVariable ['lxws_holdingWeapon',[]]) isEqualTo []}
                ",
                _x
            ],
            ACTIONDIST,
            false,
            "",
            ""
        ] ;

        private _actionID = _uav addAction ["Disarm" + " " + _UAVName,
            {
                params ["_target","_caller","_actionId","_arguments"] ;
                private _weapon = _target getVariable ["lxws_holdingWeapon",[]] ;
                private _weaponType = getNumber (configFile >> "CfgWeapons" >> _weapon#0 >> "type"); // Rifle: 1, Pistol: 2, Launcher: 4
                private _loadoutIndex = [1, 4, 2] find _weaponType; // loadout order

                private _loadout = getUnitLoadout _caller ;
                private _mag1 = _weapon#4 ;
                private _mag2 = _weapon#5 ;

                // Animate
                _caller playActionNow "putDown" ;

                [_target,"SetWeapon",[]] call pya_main_fnc_droneWeapon ;

                if ((_loadout#_loadoutIndex) isEqualTo []) then {    // If you don't have a primary weapon right now
                    _loadout = [
                        nil,
                        nil,
                        nil,
                        nil,
                        nil,
                        nil,
                        nil,
                        nil,
                        nil,
                        nil
                    ] ;
                    _loadout set [_loadoutIndex, _weapon];
                    _caller setUnitLoadout _loadout ;    // Add the primary weapon into your inventory directly
                } else {    // If not
                    private _weaponHolder = createVehicle ["WeaponHolder_Single_F",_caller modelToWorld [0,1,0.025],[],0,"CAN_COLLIDE"] ;
                    _weaponHolder setDir (random 360) ;
                    _weaponHolder addWeaponWithAttachmentsCargoGlobal [_weapon,1] ;    // Drop weapon instead
                } ;
            },
            [_x],
            1,
            true,
            false,
            "",
            // Condition checks
            format ["
                    if (!alive _target) exitWith {removeAllActions _target ; false} ;
                    if (_target getVariable ['DisableRearm',0] == 1) exitWith {false} ;
                    if (vehicle _this == _target) exitWith {false} ;
                    if (vehicle _this != _this) exitWith {false} ;

                    count (_target getVariable ['lxws_holdingWeapon',[]]) != 0
                ",
                _x
            ],
            ACTIONDIST,
            false,
            "",
            ""
        ] ;

        {
            private _actionID = _uav addAction [str _forEachIndex,    // No text since will replace the text later
                {
                    params ["_target","_caller","_actionId","_arguments"] ;
                    private _forEachIndex = _arguments#0 ;
                    private _weapon = _target getVariable ["lxws_holdingWeapon",[]] ;

                    private _magazine = _weapon#([4,5]#_forEachIndex) ;
                    private _oldCount = _magazine#1 ;

                    // Gets the magazine which has the most ammo
                    private _compatibleMags = (((magazinesAmmo _caller) select {
                        _x#0 == (_magazine#0)
                    })) ;
                    private _magCount = selectMax (_compatibleMags apply {_x#1}) ;

                    // Animate
                    _caller playActionNow "putDown" ;

                    // Sets the magazine count on the drone
                    _magazine set [1,_magCount] ;
                    [_target,"SetWeapon",_weapon] call pya_main_fnc_droneWeapon ;

                    // Checks caller's loadout and remove the corresponded magazine
                    private _loadout = getUnitLoadout _caller ;
                    {
                        _loadout set [_x,nil] ;
                    } forEach [0,1,2,6,7,8,9] ;

                    private _foundAndRemoved = false ; // checks if the magazin is there, and removed
                    {
                        if (count (_loadout#_x) != 0) then {
                            private _find = ((_loadout#_x#1) findIf {_x#0 == (_magazine#0) and _x#2 == _magCount}) ;
                            if (_find != -1) exitWith {
                                private _count = (_loadout#_x#1#_find#1) ;
                                if (_count == 1) then {
                                    // remove magazine entry
                                    _loadout#_x#1 deleteAt _find ;
                                } else {
                                    // reduce magazine entry
                                    _loadout#_x#1#_find set [1,_count - 1] ;
                                } ;
                            } ;
                        } ;
                    } forEach [3,4,5] ;

                    // save the connected UAV ;
                    private _currentUAV = getConnectedUAV _caller ;

                    // execute
                    _caller setUnitLoadout _loadout ;

                    // reconnect to the UAV
                    _caller connectTerminalToUAV _currentUAV ;

                    // Adds magazine if the magazine isn't empty
                    if (_oldCount != 0) then {
                        _caller addMagazine [_magazine#0,_oldCount] ;
                    } ;
                },
                [_forEachIndex],
                0.1,
                true,
                false,
                "",
                // Condition checks
                ["
                    if (!alive _target) exitWith {removeAllActions _target ; false} ;
                    if (vehicle _this == _target) exitWith {false} ;
                    if (vehicle _this != _this) exitWith {false} ;

                    private _holdingWeapon = _target getVariable ['lxws_holdingWeapon',[]] ;
                    if (count _holdingWeapon != 0 and {count (_holdingWeapon#4) != 0}) then {
                        private _magazineCount = getNumber (configfile >> 'CfgMagazines' >> (_holdingWeapon#4#0) >> 'count') ;
                        ((_holdingWeapon#4#1) < _magazineCount) and
                        (_holdingWeapon#4#0) in magazines _this
                    } else {
                        false
                    } ;
                ",
                "
                    if (!alive _target) exitWith {removeAllActions _target ; false} ;
                    if (vehicle _this == _target) exitWith {false} ;
                    if (vehicle _this != _this) exitWith {false} ;

                    private _holdingWeapon = _target getVariable ['lxws_holdingWeapon',[]] ;
                    if (count _holdingWeapon != 0 and {count (_holdingWeapon#5) != 0}) then {
                        private _magazineCount = getNumber (configfile >> 'CfgMagazines' >> (_holdingWeapon#5#0) >> 'count') ;
                        ((_holdingWeapon#5#1) < _magazineCount) and
                        (_holdingWeapon#5#0) in magazines _this
                    } else {
                        false
                    } ;
                "]#_forEachIndex,
                ACTIONDIST,
                false,
                "",
                ""
            ] ;
            _uav setVariable [_x,_actionID,true] ;
        } forEach ["lxws_reloadAction","lxws_reloadAction2"] ;

        // Sets a varable to define it is initialized
        _uav setVariable ["lxws_initialized",true] ;
    } ;
} ;

if (_mode == "SetWeapon") exitWith {
    // Gets current primary weapon and magazines
    private _weapon = _args ;

    if (count (_uav getVariable ["lxws_holdingWeapon",[]]) != 0) then {    // If has something right now
        // Clearing what you've got right now
        private _weapon = _uav getVariable ["lxws_holdingWeapon",[]] ;
        private _mag1 = _weapon#4 ;
        private _mag2 = _weapon#5 ;

        [_uav,[_weapon#0,[0]]] remoteExecCall ["removeWeaponTurret",_uav] ;
        {
            if (count _x != 0) then {
                [_uav,[_x#0,[0]]] remoteExecCall ["removeMagazineTurret"] ;
            } ;
        } forEach [_mag1,_mag2] ;
    } ;
    clearWeaponCargoGlobal _uav ;

    if (count _weapon != 0) then {    // If the next weapon is not empty
        private _mag1 = _weapon#4 ;
        private _mag2 = _weapon#5 ;
        // Adds weapon and magazine into uav
        // Visual thing
        private _weaponCargo = [
            _weapon#0,
            "",
            "",
            "",
            _weapon#4,
            _weapon#5,
            ""
        ] ;
        _uav addWeaponWithAttachmentsCargoGlobal [_weaponCargo,1] ;
        //Actual weapon and magazine
        {
            if (count _x != 0) then {
                [_uav,[_x#0,[0],_x#1]] remoteExecCall ["addMagazineTurret"] ;
                [_uav,[
                    _uav getVariable [["lxws_reloadAction","lxws_reloadAction2"]#_forEachIndex,-1],
                    format ["Reload Drone (%1)",getText (configFile >> "CfgMagazines" >> _x#0 >> "displayName")],
                    format ["Reload Drone (%1)",getText (configFile >> "CfgMagazines" >> _x#0 >> "displayName")]
                ]] remoteExecCall ["setUserActionText"] ;    // TODO STRING AND IMAGE
            } ;
        } forEach [_mag1,_mag2] ;
        [_uav,[_weapon#0,[0]]] remoteExecCall ["addWeaponTurret"] ;


        // Make fake muzzleflash object
        /*    Decided not to implement for now
        private _muzzleFlashSelection = "" ;
        private _muzzleFlashPosition = [0,0,0] ;

        // Creates simple object dummy to fetch data
        private _dummyWeapon = createSimpleObject [getText (configFile >> "CfgWeapons" >> _weapon#0 >> "model"),[0,0,6],true] ;
        _dummyWeapon hideObject true ;
        if !(isNull _dummyWeapon) then {
            _dummyWeapon animateSource ["isSelected",1,true] ;
            private _selection = (selectionNames _dummyWeapon) ;
            private _index = (_selection findIf {"muzzle_flash" in toLowerANSI _x}) ;

            // If found
            if (_index >= 0) then {
                // Show zasleh for lxws weapons
                _dummyWeapon animate ["zasleh_hide",1,true] ;

                // Gets position
                _muzzleFlashPosition = selectionPosition [_dummyWeapon,(_selection#_index),0] ;
                // Gets model path
                _selection = (_selection#_index splitString ":.")#1 ;
            } ;
        } ;
        // Delete dummy
        deleteVehicle _dummyWeapon ;*/

        // Sets variable
        _uav setVariable ["lxws_holdingWeapon",_weapon,true] ;
        //_uav setVariable ["lxws_muzzleFlash",[_muzzleFlashSelection,_muzzleFlashPosition]] ;

        //private _mf = createSimpleObject ["a3\data_f\proxies\muzzle_flash\muzzle_flash_GM6.p3d",[0,0,0]] ;
        /*
        private _mf = createSimpleObject ["Logic",[0,0,0]] ;
        _mf attachTo [
            _uav,[0,0,0]
        ] ;
        */
    } else {    // If is meant to set empty
        _uav setVariable ["lxws_holdingWeapon",[],true] ;
        //_uav setVariable ["lxws_muzzleFlash",["",[0,0,0]]] ;
    } ;
} ;

// Sets default weapon at the spawn stage
if (_mode == "SetWeaponInit") exitWith {
    _args params ["_weapon","_mag1","_mag2"] ;

    // Is it empty?
    if (_weapon == "<Empty>") exitWith {
        [_uav,"SetWeapon",""] call pya_main_fnc_droneWeapon;
    } ;

    if (_args isEqualTo "") then {
        // Is it default?
        getArray (configOf _uav >> "lxws_droneWeapon") params ["_weapon","_mag1","_mag2"] ; // sets config default
    } else {
        // Or something else?
        //_weapon = _args ;
    } ;
    private _muzzles = getArray (configfile >> "CfgWeapons" >> _weapon >> "muzzles") ;

    // todo replace with compatibleMagazines once 2.10 hits
    private _getCompatMag = {
        /*private "_muzzle" ;
        if (_this == "this") then {
            _muzzle = configfile >> "CfgWeapons" >> _weapon ;
        } else {
            _muzzle = configfile >> "CfgWeapons" >> _weapon >> _this ;
        } ;

        private _return = getArray (_muzzle >> "magazines") ;
        if (count _return == 0) then {
            private _magWell = getArray (_muzzle >> "magazineWell")#0 ;
            configProperties [configFile >> "CfgMagazineWells" >> _magWell,"isArray _x"]#0#0
        } else {
            _return#0
        } ;*/
        (compatibleMagazines [_weapon,_this])#0
    } ;

    // get primary magazine and its count
    private _primMag = call {
        //private _return = (compatibleMagazines [_weapon,_muzzles#0])#0 ;
        private _return = call {
            if (_mag1 == "") then {
                "this" call _getCompatMag
            } else {
                _mag1
            }
        } ;
        if !(isNil "_return") then {
            [_return,getNumber (configFile >> "CfgMagazines" >> _return >> "count")]
        } else {
            []
        } ;
    } ;

    // get secondary magazine and its count
    private _secMag = call {
        //private _return = (compatibleMagazines [_weapon,_muzzles#(1 max (count _muzzles-1))])#0 ;
        private "_return" ;
        if (count _muzzles >= 2) then {
            _return = call {
                if (_mag2 == "") then {
                    (_muzzles#1) call _getCompatMag
                } else {
                    _mag2
                }
            } ;
        } ;

        if !(isNil "_return") then {
            [_return,getNumber (configFile >> "CfgMagazines" >> _return >> "count")]
        } else {
            []
        } ;
    } ;

    // execution
    [_uav,"SetWeapon",[
        _weapon,"","","",
        _primMag,
        _secMag,
        ""
    ]] call pya_main_fnc_droneWeapon ;
} ;
