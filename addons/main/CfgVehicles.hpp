#include "config\hardpoints.hpp"

class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F: Helicopter
    {
        class Turrets;
    };
    class UAV_03_base_F: Helicopter_Base_F {
        class AnimationSources;
        class Components;
        class Turrets: Turrets
        {
            class MainTurret;
        };
    };
    class GVAR(pylon_base): UAV_03_base_F
    {
        author = "Ampersand";
        mapSize = 0;
        side = 1;
        faction = "BLU_F";
        crew = "B_UAV_AI";
        editorSubcategory = QGVAR(EdSubcat_pylons);
        _generalMacro = "";
        displayName = "Remote Pylon Base";
        model = QPATHTOF(data\pya_pylon_single.p3d);
        DLC = "";
        icon = "\A3\Static_F_Gamma\data\UI\map_StaticTurret_AA_CA.paa";
        //picture = "\A3\Air_F_Exp\UAV_03\Data\UI\UAV_03_CA.paa";
        //overviewPicture = "\a3\data_f_jets\Images\dlcbrowser_jets_loadouts_ca.paa";
        hasDriver = 0;
        vehicleClass = "Autonomous";
        destrType = "DestructDefault";
        memoryPointTaskMarker = "TaskMarker_1_pos";
        unitInfoType = "RscOptics_AV_pilot";
        fuelExplosionPower = 0;
        fuelCapacity = 0;
        fuelConsumptionRate = 0;
        class Library
        {
            libTextDesc = "";
        };
        driveOnComponent[] = {};
        getInRadius = 0;
        armor = 100;
        cost = 0;
        class HitPoints {};
        threat[] = {0, 0, 0};
        radarTargetSize = 0;
        visualTargetSize = 0;
        irTargetSize = 0;
        lockDetectionSystem = "";
        incomingMissileDetectionSystem = "";
        soundIncommingMissile[] = {};
        weapons[] = {};
        magazines[] = {};
        memoryPointLRocket = "";
        memoryPointRRocket = "";
        memoryPointLMissile = "";
        memoryPointRMissile = "";
        hiddenSelections[] = {};
        hiddenSelectionsTextures[] = {};
        //class Damage {};
        reportRemoteTargets = 1;
        reportOwnPosition = 1;
        showWeaponCargo = 1;
        maximumLoad = 120;
        uavCameraGunnerPos = "PiP_pos";
        uavCameraGunnerDir = "PiP_dir";

        class AnimationSources {};
        class Attributes;
        class Components;
        class Exhausts {};
        class Sounds {};
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                minElev = -85;
                maxElev = 85;
                initElev = 0;
                minTurn = -360;
                maxTurn = 360;
                initTurn = 0;
                laserScanner = 1;
                showAllTargets = 4;
                enableManualFire = 1;
                stabilizedInAxes = 3;
                memoryPointGun = "PiP_pos";
                memoryPointGunnerOptics = "PiP_pos";
            };
        };
        #include "config\UserActions.hpp"

        ace_cargo_space = 0;
        ace_cargo_hasCargo = 0;
        ace_dragging_canDrag = 1;
        ace_dragging_canCarry = 1;
    }; // pylon_base

    class GVAR(camera_tgp): GVAR(pylon_base)
    {
        scope = 2;
        scopeCurator = 2;
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
        displayName = "Remote Camera";

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
        displayName = "Remote Pylon (TGP)";
        #include "config\AnimationSources.hpp"
        #include "config\Components_single.hpp"
    }; // pylon_single_turret

    class GVAR(pylon_single_turret): GVAR(camera_turret)
    {
        displayName = "Remote Pylon (Camera)";
        #include "config\AnimationSources.hpp"
        #include "config\Components_single.hpp"
    }; // pylon_single

    class GVAR(pylon_single_fixed): GVAR(camera_fixed)
    {
        displayName = "Remote Pylon";
        #include "config\AnimationSources.hpp"
        #include "config\Components_single.hpp"
    }; // pylon_single

    class GVAR(pylon_turret_tgp): GVAR(camera_tgp)
    {
        displayName = "Remote Turret (Pylon)";
        model = QPATHTOF(data\pya_pylon_turret.p3d);
        #include "config\AnimationSources.hpp"
        #include "config\Components_single.hpp"
    }; // pylon_turret_tgp

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

    class StaticMGWeapon;
    class HMG_01_base_F: StaticMGWeapon
    {
        class Turrets;
    };
    class HMG_01_A_base_F: HMG_01_base_F {
        class AnimationSources;
        class Components;
        class Turrets: Turrets
        {
            class MainTurret;
        };
    };
    class GVAR(turret_base): HMG_01_A_base_F
    {
        author = "Ampersand";
        mapSize = 0;
        side = 1;
        faction = "BLU_F";
        editorSubcategory = QGVAR(EdSubcat_pylons);
        _generalMacro = "";
        displayName = "Remote Pylon Base";
        model = QPATHTOF(data\pya_pylon_single.p3d);
        DLC = "";
        icon = "\A3\Static_F_Gamma\data\UI\map_StaticTurret_AA_CA.paa";
        //picture = "\A3\Air_F_Exp\UAV_03\Data\UI\UAV_03_CA.paa";
        //overviewPicture = "\a3\data_f_jets\Images\dlcbrowser_jets_loadouts_ca.paa";
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
        armor = 100;
        cost = 0;
        class HitPoints {};
        threat[] = {0, 0, 0};
        radarTargetSize = 0;
        visualTargetSize = 0;
        irTargetSize = 0;
        lockDetectionSystem = "";
        incomingMissileDetectionSystem = "";
        soundIncommingMissile[] = {};
        weapons[] = {};
        magazines[] = {};
        memoryPointLRocket = "";
        memoryPointRRocket = "";
        memoryPointLMissile = "";
        memoryPointRMissile = "";
        hiddenSelections[] = {};
        hiddenSelectionsTextures[] = {};
        //class Damage {};
        reportRemoteTargets = 1;
        reportOwnPosition = 1;
        showWeaponCargo = 1;
        maximumLoad = 120;
        uavCameraGunnerPos = "PiP_pos";
        uavCameraGunnerDir = "PiP_dir";

        class AnimationSources {};
        class Attributes;
        class Components;
        class Exhausts {};
        class Sounds {};
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                minElev = -85;
                maxElev = 85;
                initElev = 0;
                minTurn = -360;
                maxTurn = 360;
                initTurn = 0;
                memoryPointGunnerOutOptics = "gunnerview";
                laserScanner = 1;
                showAllTargets = 4;
                enableManualFire = 1;
			    stabilizedInAxes = 3;
            };
        };
        #include "config\UserActions.hpp"

        ace_cargo_space = 0;
        ace_cargo_hasCargo = 0;
        ace_dragging_canDrag = 1;
        ace_dragging_canCarry = 1;
    }; // turret_base

    class GVAR(smallarms_turret_tgp): GVAR(turret_base)
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "Remote Turret (Small Arms, TGP)";
        crew = "B_UAV_AI";
        model = QPATHTOF(data\pya_smallarms_turret.p3d);
        picture = "\A3\Static_f_gamma\data\ui\gear_StaticTurret_MG_CA.paa";
        showWeaponCargo = 1;
        maximumLoad = 120;
        transportMaxWeapons = 1;
        transportMaxMagazines = 1;
        lxws_droneWeapon[] = {"<Empty>", "<Empty>", "<Empty>"};

        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                ballisticsComputerOverride = "1 + 16";
                discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000};
                discreteDistanceInitIndex = 2;
                gunBeg = "gun_muzzle";
                gunEnd = "gun_chamber";
                memoryPointGun = "gun_muzzle";
                memoryPointLRocket = "gun_muzzle";
                memoryPointRRocket = "gun_muzzle";
                memoryPointLMissile = "gun_muzzle";
                memoryPointRMissile = "gun_muzzle";
                gunnerOpticsModel = "\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F.p3d";
                turretInfoType = "RscOptics_crows";
                weapons[] = {"Laserdesignator_mounted"};
                magazines[] = {"Laserbatteries"};
            };
        };
        #include "config\AnimationSources.hpp"
        #define HOLDINGWEAPON
        #include "config\Attributes.hpp"
        #undef HOLDINGWEAPON
    }; // smallarms_turret_tgp

    class GVAR(smallarms_turret): GVAR(smallarms_turret_tgp)
    {
        displayName = "Remote Turret (Small Arms)";
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                weapons[] = {};
                magazines[] = {};
            };
        };
    }; // smallarms_turret

    class GVAR(smallarms_fixed): GVAR(smallarms_turret)
    {
        displayName = "Remote Pylon (Small Arms)";
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                animationSourceBody = "";
                animationSourceGun = "";
            };
        };
    }; // smallarms_fixed

    class C_Soldier_VR_F;
    class GVAR(smallarms_dummy): C_Soldier_VR_F {
    	_generalMacro = "";
    	scope = 1;
        scopeCurator = 1;
        author = "Ampersand";
    	model = QPATHTOF(data\pya_smallarms_dummy.p3d);
    	displayName = CSTRING(SmallArmsHolder);
    };

/*
    class StaticWeapon;
    class StaticMGWeapon: StaticWeapon
    {
        class Turrets;
    };
    class HMG_02_base_F: StaticMGWeapon
    {
        class AnimationSources;
        class Attributes;
        class Turrets: Turrets
        {
            class MainTurret;
        };
    };
    class GVAR(smallarms_mount): HMG_02_base_F
    {
        scope = 1;
        scopeCurator = 1;
        author = "Ampersand";
        displayName = "Small Arms Mount (Standing)";
        model = QPATHTOF(data\pya_smallarms_turret.p3d);
        showWeaponCargo = 1;
        maximumLoad = 120;
        hasDriver = 0;
        transportMaxWeapons = 1;
        transportMaxMagazines = 1;
        showNVGGunner = 1;
        faction = "BLU_F";
        crew = "B_Soldier_F";

        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                //ballisticsComputer = 2;
                discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500};
                discreteDistanceInitIndex = 2;
                weapons[] = {};
                magazines[] = {};
                minTurn = -120;
                maxTurn = 120;
                initTurn = 0;
                minElev = -89;
                maxElev = 89;
                //gunnerAction = "gunner_hmg02_standing"; // Gunner weapon is on ground
                gunnerAction = "gunner_lsv_02"; // Gunner weapon is on ground
                gunnerInAction = "gunner_staticlauncher";
                gunnerLeftLegAnimName = "leg_left";
                gunnerRightLegAnimName = "leg_right";
                gunnergetInAction = "";
                gunnergetOutAction = "";
                gunnerOutOpticsModel = "A3\weapons_f\reticle\optics_empty";
                turretInfoType = "RscOptics_Offroad_01";
                gunnerRightHandAnimName = "OtocHlaven_shake";
                gunnerLeftHandAnimName = "OtocHlaven_shake";
                gunBeg = "gun_muzzle";
                gunEnd = "gun_chamber";
                memoryPointGun = "gun_muzzle";
                memoryPointGunnerOutOptics = "gunnerview";
                memoryPointsGetInGunner = "pos_gunner";
                memoryPointsGetInGunnerDir = "pos_gunner_dir";
                ejectDeadGunner = 1;
                hideWeaponsGunner = 0;
                showHMD = 1;
                canHideGunner = 1;
                forceHideGunner = 0;
                inGunnerMayFire = 0;
                viewGunnerInExternal = 1;
                LODTurnedIn = 1;
                LODTurnedOut = 1;
            };
        };

        #define HOLDINGWEAPON
        #include "config\AnimationSources.hpp"
        #include "config\Attributes.hpp"
        #undef HOLDINGWEAPON
    }; // smallarms_mount
*/

    #include "config\titan.hpp"

    // Other sides
    #define SIDE_O side = 0; \
        faction = "OPF_F"; \
        crew = "O_UAV_AI";

    #define SIDE_I side = 2; \
        faction = "IND_F"; \
        crew = "I_UAV_AI";

    #define SIDE_C side = 3; \
        faction = "CIV_F"; \
        crew = "C_UAV_AI_F";

    #define SIDES(name) class GVAR(DOUBLES(name,O)): GVAR(name) {SIDE_O}; \
        class GVAR(DOUBLES(name,I)): GVAR(name) {SIDE_I}; \
        class GVAR(DOUBLES(name,C)): GVAR(name) {SIDE_C}


    SIDES(camera_tgp);
    SIDES(camera_turret);
    SIDES(camera_fixed);
    SIDES(pylon_single_tgp);
    SIDES(pylon_single_turret);
    SIDES(pylon_single_fixed);
    SIDES(pylon_turret_tgp);
    SIDES(smallarms_turret_tgp);
    SIDES(smallarms_turret);
    //SIDES(smallarms_mount);

};
