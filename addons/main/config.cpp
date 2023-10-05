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
            QGVAR(pylon_single_fixed)
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
        description     = "Free the Pylons!"; // Probably in context with action

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
