class UserActionGroups
{
	class GVAR(PylonAnywhere) // Unique classname of your category.
	{
		name = CSTRING(PylonAnywhere); // Display name of your category.
		isAddon = 1;
		group[] = { // List of all actions inside this category.
            QGVAR(CyclePylons),
            QGVAR(ToggleSafety),
            QGVAR(FirePylons),
            QGVAR(AimTurret)
        };
	};
};
