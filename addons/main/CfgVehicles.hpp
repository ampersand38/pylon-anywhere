class Components;
class MainTurret;
class Turrets;
class AnimationSources;

#include "config\hardpoints.hpp"

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
        class UserActions
        {
            class GVAR(setTrigger)
            {
                displayName = "Set Remote Trigger";
                displayNameDefault = "<img image='P:\a3\ui_f\data\GUI\Cfg\Hints\UAVConncetion_ca.paa' size='2.5' />";
                priority = 10;
                radius = 10; // a too small radius might cause the action to not be visible
                position = "";
                showWindow = 1;
                hideOnUse = 1;
                onlyForPlayer = 0;
                shortcut = "";
                condition = "alive this"; // only show if the unit is alive and is not a player
                statement = QUOTE([this] call FUNC(setTrigger));
            };
        };
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
        #include "config\Attributes.hpp"

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
        #include "config\Components_single.hpp"
    }; // pylon_single_turret

    class GVAR(pylon_single_turret): GVAR(camera_turret)
    {
        displayName = "Remote Pylon (Single, Turret)";
        #include "config\AnimationSources.hpp"
        #include "config\Components_single.hpp"
    }; // pylon_single

    class GVAR(pylon_single_fixed): GVAR(camera_fixed)
    {
        displayName = "Remote Pylon (Single, Fixed)";
        #include "config\AnimationSources.hpp"
        #include "config\Components_single.hpp"
    }; // pylon_single

    class GVAR(pylons_tgp): GVAR(camera_tgp)
    {
        scope = 1;
        scopeCurator = 1;
        displayName = "Remote Pylon (Multi, TGP)";
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
                uiPicture = "";
                class Pylons
                {
                    class Pylon1
                    {
                        hardpoints[] = {ALL_HARDPOINTS};
                        attachment = "";
                        priority = 1;
                        turret[] = {0};
                        maxweight = 10000;
                        UIposition[] = {0.35, 0.20};
                    };

                    class Pylon2: Pylon1
                    {
                        priority = 2;
                        UIposition[] = {0.25, 0.25};
                    };
                    class Pylon3: Pylon2
                    {
                        UIposition[] = {0.45, 0.25};
                        mirroredMissilePos = 2;
                    };

                    class Pylon4: Pylon1
                    {
                        priority = 3;
                        UIposition[] = {0.20, 0.3};
                    };
                    class Pylon5: Pylon4
                    {
                        UIposition[] = {0.50, 0.3};
                        mirroredMissilePos = 4;
                    };

                    class Pylon6: Pylon1
                    {
                        priority = 4;
                        UIposition[] = {0.15, 0.35};
                    };
                    class Pylon7: Pylon6
                    {
                        UIposition[] = {0.55, 0.35};
                        mirroredMissilePos = 6;
                    };

                    class Pylon8: Pylon1
                    {
                        priority = 5;
                        UIposition[] = {0.10, 0.4};
                    };
                    class Pylon9: Pylon8
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

    // Other sides
#define SIDE_O side = 0; \
faction = "OPF_F"; \
crew = "O_UAV_AI";

#define SIDE_I side = 2; \
faction = "IND_F"; \
crew = "I_UAV_AI";

#define SIDE_C side = 3; \
faction = "CIV_F"; \
crew = "C_UAV_AI";

    class GVAR(camera_tgp_O): GVAR(camera_tgp) {SIDE_O};
    class GVAR(camera_turret_O): GVAR(camera_turret) {SIDE_O};
    class GVAR(camera_fixed_O): GVAR(camera_fixed) {SIDE_O};
    class GVAR(pylon_single_tgp_O): GVAR(pylon_single_tgp) {SIDE_O};
    class GVAR(pylon_single_turret_O): GVAR(pylon_single_turret) {SIDE_O};
    class GVAR(pylon_single_fixed_O): GVAR(pylon_single_fixed) {SIDE_O};

    class GVAR(camera_tgp_I): GVAR(camera_tgp) {SIDE_I};
    class GVAR(camera_turret_I): GVAR(camera_turret) {SIDE_I};
    class GVAR(camera_fixed_I): GVAR(camera_fixed) {SIDE_I};
    class GVAR(pylon_single_tgp_I): GVAR(pylon_single_tgp) {SIDE_I};
    class GVAR(pylon_single_turret_I): GVAR(pylon_single_turret) {SIDE_I};
    class GVAR(pylon_single_fixed_I): GVAR(pylon_single_fixed) {SIDE_I};

    class GVAR(camera_tgp_C): GVAR(camera_tgp) {SIDE_C};
    class GVAR(camera_turret_C): GVAR(camera_turret) {SIDE_C};
    class GVAR(camera_fixed_C): GVAR(camera_fixed) {SIDE_C};
    class GVAR(pylon_single_tgp_C): GVAR(pylon_single_tgp) {SIDE_C};
    class GVAR(pylon_single_turret_C): GVAR(pylon_single_turret) {SIDE_C};
    class GVAR(pylon_single_fixed_C): GVAR(pylon_single_fixed) {SIDE_C};
};
