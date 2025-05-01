#include "script_component.hpp"

#define SIDES_UNITS(name) ARR_4(QGVAR(name),QGVAR(DOUBLES(name,C)),QGVAR(DOUBLES(name,I)),QGVAR(DOUBLES(name,O)))

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            SIDES_UNITS(camera_tgp),
            SIDES_UNITS(camera_turret),
            SIDES_UNITS(camera_fixed),
            SIDES_UNITS(pylon_single_tgp),
            SIDES_UNITS(pylon_single_turret),
            SIDES_UNITS(pylon_single_fixed),
            SIDES_UNITS(pylon_turret),
            SIDES_UNITS(pylon_turret_tgp),
            SIDES_UNITS(smallarms_turret_tgp),
            SIDES_UNITS(smallarms_turret),

            // Titans
            QGVAR(B_AA_01),
            QGVAR(B_AA_01_weapon),
            QGVAR(B_AT_01),
            QGVAR(B_AT_01_weapon),
            QGVAR(O_AA_01),
            QGVAR(O_AA_01_weapon),
            QGVAR(O_AT_01),
            QGVAR(O_AT_01_weapon),
            QGVAR(I_AA_01),
            QGVAR(I_AA_01_weapon),
            QGVAR(I_AT_01),
            QGVAR(I_AT_01_weapon),

            QGVAR(smallarms_mount),
            QGVAR(smallarms_dummy)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main"};
        author = "Ampersand";
        authors[] = {"Ampersand"};
        VERSION_CONFIG;
    };
};

// information on the whole mod (only needed once)
class CfgMods {
    class PREFIX {
        dir = "@Pylon Anywhere";
        name = "Pylon Anywhere";

        author = "Ampersand";                    // probably shown somewhere in the mods menu, but probably ignored by CBA/HEMTT

        picture         = "logo_ampersand_ca.paa";       // Picture displayed from the expansions menu. Optimal size is 2048x1024
        hideName        = "false";              // Hide the extension name in main menu and extension menu
        hidePicture     = "false";              // Hide the extension picture in the extension menu

        action          = "https://github.com/ampersand38/pylon-anywhere"; // Website URL, that can accessed from the expansions menu
        actionName      = "URL";              // label of button/tooltip in extension menu
        description     = "Free the Pylon!"; // Probably in context with action

        // Color used for DLC stripes and backgrounds (RGBA)
        dlcColor[] =
        {
            1,
            0.0,
            0.86,
            1
        };
    };
};

// Configs go here
#include "CfgAmmo.hpp"
#include "Cfg3DEN.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgNonAIVehicles.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

// Keybinds
#include "CfgDefaultKeysPresets.hpp"
#include "CfgUserActions.hpp"
#include "UserActionGroups.hpp"
//#include "UserActionsConflictGroups.hpp"
