class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

class Extended_InitPost_EventHandlers  {
    class GVAR(pylon_base) {
        class GVAR(initPylon) {
            init = QUOTE(_this call FUNC(initPylon));
        };
    };
    class GVAR(turret_base) {
        class GVAR(initSmallArms) {
            init = QUOTE(_this call FUNC(initSmallArms));
        };
    };
};
