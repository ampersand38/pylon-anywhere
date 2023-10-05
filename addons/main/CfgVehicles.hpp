#define ALL_HARDPOINTS "DAR","DAGR","B_SHIEKER","SCALPEL_1RND_EJECTOR","B_ASRRAM_EJECTOR","O_SKYFIRE","I_ORCA_RIGHT_PYLON","20MM_TWIN_CANNON","SCALPEL_1RND","B_ASRAAM","O_MISSILE_PYLON","O_BOMB_PYLON_HELI","UNI_SCALPEL","B_MISSILE_PYLON","B_ZEPHYR","B_BOMB_PYLON","B_A143_BUZZARD_CENTER_PYLON","O_BOMB_PYLON","B_BIM9X_RAIL","B_BIM9X_DUAL_RAIL","B_AMRAAM_D_RAIL","B_AMRAAM_D_DUAL_RAIL","B_AGM65_RAIL","B_GBU12","B_AGM65_DUAL_RAIL","B_GBU12_DUAL_RAIL","B_HARM_RAIL","B_SDB_QUAD_RAIL","B_BIM9X","B_AMRAAM_D_INT","O_R73","O_R77","O_KH25","O_KAB250_BOMB","O_KH58","O_R77_INT","O_KH25_INT","O_KH58_INT","I_BIM9X","I_AMRAAM_C_RAIL","I_BIM9X_RAIL","I_AGM65_RAIL","I_BIM9X_DUAL_RAIL","I_AMRAAM_C_DUAL_RAIL","I_AGM65_DUAL_RAIL","I_GBU12","B_AGM65_DUAL","B_HARM_INT","UNI_LEAFLETS_PYLON","ANTIMINE_DRONE_PYLON"

class Components;
class MainTurret;
class Turrets;
class AnimationSources;

class CfgVehicles {
    class UAV_03_base_F;
    class GVAR(base): UAV_03_base_F
    {
        author = "Ampersand";
        mapSize = 0;
        editorSubcategory = QGVAR(EdSubcat_pylons);
        _generalMacro = "";
        displayName = "Remote Pylon Base";
        model = QPATHTOF(data\pya_pylon_single.p3d);
        DLC = "";
        icon = "\a3\ui_f_jets\Data\GUI\Cfg\Hints\AircraftTgtCamera_ca.paa";
        picture = "\A3\Air_F_Exp\UAV_03\Data\UI\UAV_03_CA.paa";
        overviewPicture = "\a3\data_f_jets\Images\dlcbrowser_jets_loadouts_ca.paa";
        vehicleClass = "Autonomous";
        destrType = "DestructDefault";
        memoryPointTaskMarker = "TaskMarker_1_pos";
        unitInfoType = "RscOptics_AV_pilot";
        unitInfoTypeRTD = "RscOptics_AV_pilot";
        fuelExplosionPower = 0;
        fuelCapacity = 0;
        fuelConsumptionRate = 0;
        class Library
        {
            libTextDesc = "";
        };
        getInRadius = 0;
        hasDriver = 0;
        armor = 10;
        cost = 0;
        altFullForce = 0;
        altNoForce = 0;
        class HitPoints {};
        selectionHRotorMove = "";
        selectionHRotorStill = "";
        selectionVRotorMove = "";
        selectionVRotorStill = "";
        maxSpeed = 0;
        threat[] = {0, 0, 0};
        maxMainRotorDive = 7;
        minMainRotorDive = -7;
        neutralMainRotorDive = 0;
        driveOnComponent[] = {};
        gearRetracting = 0;
        mainRotorSpeed = -1;
        backRotorSpeed = 1;
        startDuration = 5;
        radarTargetSize = 0;
        visualTargetSize = 0;
        irTargetSize = 0;
        lockDetectionSystem = "";
        incomingMissileDetectionSystem = "";
        soundIncommingMissile[] = {};
        //weapons[] = {"CMFlareLauncher"};
        //magazines[] = {"120Rnd_CMFlare_Chaff_Magazine"};
        weapons[] = {};
        magazines[] = {};
        laserScanner = 1;
        showAllTargets = 4;
        enableManualFire = 1;
        //memoryPointCM[] = {"Flare_launcher_1_pos", "Flare_launcher_2_pos"};
        //memoryPointCMDir[] = {"Flare_launcher_1_dir", "Flare_launcher_2_dir"};
        memoryPointCM[] = {};
        memoryPointCMDir[] = {};
        memoryPointLRocket = "";
        memoryPointRRocket = "";
        memoryPointLMissile = "";
        memoryPointRMissile = "";
        hiddenSelections[] = {};
        hiddenSelectionsTextures[] = {};
        //class Damage {};
        reportRemoteTargets = 1;
        reportOwnPosition = 1;

        class AnimationSources {};
        class Attributes;
        class Components;
        class Exhausts {};
        class Sounds {};
        class Turrets;
        ace_cargo_space = 0;
        ace_cargo_hasCargo = 0;
    }; // base

    class GVAR(camera_tgp): GVAR(base)
    {
        scope = 2;
        scopeCurator = 2;
        side = 1;
        faction = "BLU_F";
        crew = "B_UAV_AI";
        displayName = "Remote Camera (TGP)";
        class Attributes: Attributes // Entity attributes have no categories, they are all defined directly in class Attributes
        {
            class pya_pylonRotation
            {

                //--- Mandatory properties
                displayName = "Pylon Rotation"; // Name assigned to UI control class Title
                tooltip = "Set the rotation of the Pylon to match the attachment surface. The Camera stays upright."; // Tooltip assigned to UI control class Title
                property = "pya_pylonRotation_AttributeUniqueID"; // Unique config property name saved in SQM
                control = "Slider"; // UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

                // Expression called when applying the attribute in Eden and at the scenario start
                // The expression is called twice - first for data validation, and second for actual saving
                // Entity is passed as _this, value is passed as _value
                // %s is replaced by attribute config name
                // In MP scenario, the expression is called only on server.
                expression = "_this setVariable ['%s',_value]; _this animateSource ['pylon_rotate_source', linearConversion [0, 1, _value, -pi, pi, true], true]";

                // Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
                // Entity (unit, group, marker, comment etc.) is passed as _this
                // Returned value is the default value
                // Used when no value is returned, or when it is of other type than NUMBER, STRING or ARRAY
                // Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value
                defaultValue = "0.5";

                //--- Optional properties
                unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
                validate = "number"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
                condition = "object"; // Condition for attribute to appear (see the table below)
                typeName = "NUMBER"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants. This is a scripted feature and has no engine support. See code in (configFile >> "Cfg3DEN" >> "Attributes" >> "Combo" >> "attributeSave")
            };
        };

        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                weapons[] = {"Laserdesignator_mounted"};
                magazines[] = {"Laserbatteries"};
            };
        };
    }; // camera_tgp

    class GVAR(camera_turret): GVAR(camera_tgp)
    {
        displayName = "Remote Camera (Turret)";

        class Components;
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                weapons[] = {};
                magazines[] = {};
            };
        };
    }; // camera_turret

    class GVAR(camera_fixed): GVAR(camera_turret)
    {
        displayName = "Remote Camera (Fixed)";
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                animationSourceBody = "";
                animationSourceGun = "";
            };
        };
    }; // camera_fixed

    class GVAR(pylon_single_tgp): GVAR(camera_tgp)
    {
        displayName = "Remote Pylon (Single, TGP)";
        #include "config\AnimationSources.hpp"
        #include "config\pylon_single.hpp"
    }; // pylon_single_turret

    class GVAR(pylon_single_turret): GVAR(camera_turret)
    {
        displayName = "Remote Pylon (Single, Turret)";
        #include "config\AnimationSources.hpp"
        #include "config\pylon_single.hpp"
    }; // pylon_single

    class GVAR(pylon_single_fixed): GVAR(camera_fixed)
    {
        displayName = "Remote Pylon (Single, Fixed)";
        #include "config\AnimationSources.hpp"
        #include "config\pylon_single.hpp"
    }; // pylon_single

    class GVAR(pylons_tgp): GVAR(camera_tgp)
    {
        scope = 1;
        scopeCurator = 1;
        displayName = "Remote Pylons (Multi, TGP)";
        model = QPATHTOF(data\pya_pylon_multi.p3d);
        class AnimationSources: AnimationSources {

#define HIDE_PYLON_ANIM(index) class Hide_Pylon##index \
{ \
    source = QUOTE(pylonIsEmpty.##index); \
    initPhase = 1; \
    animPeriod = 1; \
}

            HIDE_PYLON_ANIM(1);
            HIDE_PYLON_ANIM(2);
            HIDE_PYLON_ANIM(3);
            HIDE_PYLON_ANIM(4);
            HIDE_PYLON_ANIM(5);
            HIDE_PYLON_ANIM(6);
            HIDE_PYLON_ANIM(7);
            HIDE_PYLON_ANIM(8);
            HIDE_PYLON_ANIM(9);
        }; // AnimationSources
        class Components: Components
        {
            class TransportPylonsComponent
            {
                //uiPicture = "\A3\Air_F_Exp\UAV_03\Data\UI\Map_UAV_03_3DEN_CA.paa";
                uiPicture = "";
                class Pylons
                {
                    class Pylons1
                    {
                        hardpoints[] = {ALL_HARDPOINTS};
                        attachment = "";
                        priority = 1;
                        turret[] = {0};
                        maxweight = 10000;
                        UIposition[] = {0.35, 0.20};
                    };

                    class Pylons2: Pylons1
                    {
                        priority = 2;
                        UIposition[] = {0.25, 0.25};
                    };
                    class Pylons3: Pylons2
                    {
                        UIposition[] = {0.45, 0.25};
                        mirroredMissilePos = 2;
                    };

                    class Pylons4: Pylons1
                    {
                        priority = 3;
                        UIposition[] = {0.20, 0.3};
                    };
                    class Pylons5: Pylons4
                    {
                        UIposition[] = {0.50, 0.3};
                        mirroredMissilePos = 4;
                    };

                    class Pylons6: Pylons1
                    {
                        priority = 4;
                        UIposition[] = {0.15, 0.35};
                    };
                    class Pylons7: Pylons6
                    {
                        UIposition[] = {0.55, 0.35};
                        mirroredMissilePos = 6;
                    };

                    class Pylons8: Pylons1
                    {
                        priority = 5;
                        UIposition[] = {0.10, 0.4};
                    };
                    class Pylons9: Pylons8
                    {
                        UIposition[] = {0.60, 0.4};
                        mirroredMissilePos = 8;
                    };
                };
                class Presets
                {
                    class Empty
                    {
                        displayName = "Empty";
                        attachment[] = {};
                    };
                };
            };
        }; // Components
    };
};
