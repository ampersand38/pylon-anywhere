#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(magazineInfo) = createHashMap;

#ifdef DISABLE_COMPILE_CACHE
    lxws_fnc_droneWeapon = {call compile preprocessFileLineNumbers QPATHTOF(functions\lxws_fnc_DroneWeapon.sqf);};
#else
    lxws_fnc_droneWeapon = compile preprocessFileLineNumbers QPATHTOF(functions\lxws_fnc_DroneWeapon.sqf);
#endif

ADDON = true;
