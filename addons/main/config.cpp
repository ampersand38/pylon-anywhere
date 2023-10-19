#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(camera_tgp),
            QGVAR(camera_turret),
            QGVAR(camera_fixed),
            QGVAR(pylon_single_tgp),
            QGVAR(pylon_single_turret),
            QGVAR(pylon_single_fixed),
            QGVAR(pylon_turret_tgp),
            QGVAR(camera_tgp_C),
            QGVAR(camera_turret_C),
            QGVAR(camera_fixed_C),
            QGVAR(pylon_single_tgp_C),
            QGVAR(pylon_single_turret_C),
            QGVAR(pylon_single_fixed_C),
            QGVAR(pylon_turret_tgp_C),
            QGVAR(camera_tgp_I),
            QGVAR(camera_turret_I),
            QGVAR(camera_fixed_I),
            QGVAR(pylon_single_tgp_I),
            QGVAR(pylon_single_turret_I),
            QGVAR(pylon_single_fixed_I),
            QGVAR(pylon_turret_tgp_I),
            QGVAR(camera_tgp_O),
            QGVAR(camera_turret_O),
            QGVAR(camera_fixed_O),
            QGVAR(pylon_single_tgp_O),
            QGVAR(pylon_single_turret_O),
            QGVAR(pylon_single_fixed_O),
            QGVAR(pylon_turret_tgp_O)
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
#include "CfgEditorSubcategories.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"

// Keybinds
#include "CfgDefaultKeysPresets.hpp"
#include "CfgUserActions.hpp"
#include "UserActionGroups.hpp"
//#include "UserActionsConflictGroups.hpp"
