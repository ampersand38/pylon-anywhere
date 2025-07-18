class CfgUserActions {
    class GVAR(CyclePylons) { // This class name is used for internal representation and also for the inputAction command.
        displayName = CSTRING(CyclePylons);
        tooltip = CSTRING(CyclePylons_Tooltip);
        onActivate = QUOTE(_this call FUNC(input_cyclePylons));
    };
    class GVAR(ToggleSafety) { // This class name is used for internal representation and also for the inputAction command.
        displayName = CSTRING(ToggleSafety);
        tooltip = CSTRING(ToggleSafety_Tooltip);
        onActivate = QUOTE(_this call FUNC(input_toggleSafety));
    };
    class GVAR(FirePylons) { // This class name is used for internal representation and also for the inputAction command.
        displayName = CSTRING(FirePylons);
        tooltip = CSTRING(FirePylons_Tooltip);
        onActivate = QUOTE(_this call FUNC(input_firePylons));		// _this is always true.
        onDeactivate = QUOTE(_this call FUNC(input_firePylons));		// _this is always false.
    };
    class GVAR(AimTurret) { // This class name is used for internal representation and also for the inputAction command.
        displayName = CSTRING(AimTurret);
        tooltip = CSTRING(AimTurret_Tooltip);
        onActivate = QUOTE(_this call FUNC(input_aimTurret));		// _this is always true.
        onDeactivate = QUOTE(_this call FUNC(input_aimTurret));		// _this is always false.
    };
    class GVAR(JettisonSel) { // This class name is used for internal representation and also for the inputAction command.
        displayName = CSTRING(JettisonSel);
        tooltip = CSTRING(JettisonSel_Tooltip);
        onActivate = QUOTE([JETTISON_MODE_SELECTED] call FUNC(input_jettison));
    };
    class GVAR(JettisonDgf) { // This class name is used for internal representation and also for the inputAction command.
        displayName = CSTRING(JettisonDgf);
        tooltip = CSTRING(JettisonDgf_Tooltip);
        onActivate = QUOTE([JETTISON_MODE_DOGFIGHT] call FUNC(input_jettison));
    };
    class GVAR(JettisonAll) { // This class name is used for internal representation and also for the inputAction command.
        displayName = CSTRING(JettisonAll);
        tooltip = CSTRING(JettisonAll_Tooltip);
        onActivate = QUOTE([JETTISON_MODE_ALL] call FUNC(input_jettison));
    };
};
