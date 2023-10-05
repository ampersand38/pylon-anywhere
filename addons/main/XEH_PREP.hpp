// testing, update fncs on the fly
//#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }

PREP(attachForward);
PREP(fireWeapon);
PREP(forceFire);
PREP(input_cyclePylons);
PREP(input_firePylons);
PREP(input_toggleSafety);
PREP(parseMagazineDetail);
PREP(pylonName);
PREP(setTrigger);
