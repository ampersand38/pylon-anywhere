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
};
