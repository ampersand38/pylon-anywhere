class ctrlListbox;
class ctrlCombo;

class Cfg3DEN
{
    class Attributes
    {
        //class Default;
        class Title;
        class Combo: Title
        {
            class Controls;
        };
        class GVAR(lxws_droneHoldingWeaponCombo): Combo
        {
            h = "(48+6+6) * (pixelH * pixelGrid * 0.50)";
            attributeLoad = " comment 'DO NOT COPY THIS CODE TO YOUR ATTRIBUTE CONFIG UNLESS YOU ARE CHANGING SOMETHING IN THE CODE!'; private _ctrl = _this controlsGroupCtrl 100; _value params ['_weapon','_mag1','_mag2'] ; for '_i' from 0 to (lbSize _ctrl - 1) do { if (_weapon == _ctrl lbData _i) exitwith {_ctrl lbSetCurSel _i;}; }; private _ctrl = _this controlsGroupCtrl 101; for '_i' from 0 to (lbSize _ctrl - 1) do { if (_mag1 == _ctrl lbData _i) exitwith {_ctrl lbSetCurSel _i;}; }; private _ctrl = _this controlsGroupCtrl 102; for '_i' from 0 to (lbSize _ctrl - 1) do { if (_mag2 == _ctrl lbData _i) exitwith {_ctrl lbSetCurSel _i;}; }; ";
            attributeSave = " comment 'DO NOT COPY THIS CODE TO YOUR ATTRIBUTE CONFIG UNLESS YOU ARE CHANGING SOMETHING IN THE CODE!'; [100,101,102] apply { private _ctrl = _this controlsGroupCtrl _x ; _ctrl lbData lbCurSel _ctrl ; } ";
            class Controls: Controls
            {
                class Title: Title
                {
                    w = "24 * (pixelW * pixelGrid * 0.50)";
                };
                class Value: ctrlListbox
                {
                    idc = 100;
                    x = "26 * (pixelW * pixelGrid * 0.50)";
                    y = 0;
                    w = "(130-26) * (pixelW * pixelGrid * 0.50)";
                    h = "48 * (pixelH * pixelGrid * 0.50)";
                    onLoad = " private _ctrl = _this#0 ; private _add = _ctrl lbAdd format [' <%1>',localize 'str_empty'] ; _ctrl lbSetData [_add,'<Empty>'] ; { private _add = _ctrl lbAdd getText (_x >> 'displayName') ; _ctrl lbSetData [_add,configName _x] ; _ctrl lbSetPicture [_add,getText (_x >> 'picture')] ; } forEach ('getNumber (_x >> ''scope'') >= 2 and getNumber (_x >> ''type'') in [1, 4] and ([configName _x] call BIS_fnc_baseWeapon) == configName _x' configClasses (configFile >> 'CfgWeapons')) ; lbSort _ctrl ; ";
                    onLBSelChanged = " params ['_ctrl','_index'] ; private _weapon = _ctrl lbData _index ; private _weaponCfg = configFile >> 'CfgWeapons' >> _weapon ; private _muzzles = getArray (_weaponCfg >> 'muzzles') ; private _ctrlGrp = ctrlParentControlsGroup _ctrl ; { private _combo = _ctrlGrp controlsGroupCtrl _x ; lbClear _combo ; private _add = _combo lbAdd format [' <%1>',localize 'str_empty'] ; if (count _muzzles != 0) then { { private _magCfg = configFile >> 'CfgMagazines' >> _x ; private _add = _combo lbAdd (getText (_magCfg >> 'displayName')) ; _combo lbSetData [_add,_x] ; _combo lbSetPicture [_add,(getText (_magCfg >> 'picture'))] ; } forEach compatibleMagazines [_weapon,(_muzzles#_forEachIndex)] ; } ; _combo lbSetCurSel (lbSize _combo min 1); } forEach [101,102] ; ";
                };
                class Title2: Title
                {
                    w = "48 * (pixelW * pixelGrid * 0.50)";
                    y = "49 * (pixelH * pixelGrid * 0.50)";
                    h = "4 * (pixelH * pixelGrid * 0.50)";
                    text = "Primary Magazine";
                };
                class Value2: ctrlCombo
                {
                    idc = 101;
                    x = "50 * (pixelW * pixelGrid * 0.50)";
                    y = "49 * (pixelH * pixelGrid * 0.50)";
                    w = "(130-50) * (pixelW * pixelGrid * 0.50)";
                    h = "4 * (pixelH * pixelGrid * 0.50)";
                };
                class Title3: Title2
                {
                    y = "54 * (pixelH * pixelGrid * 0.50)";
                    text = "Secondary Magazine";
                };
                class Value3: Value2
                {
                    idc = 102;
                    y = "54 * (pixelH * pixelGrid * 0.50)";
                };
            };
        };
    };
};
