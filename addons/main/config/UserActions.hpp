class UserActions
{
    class GVAR(getTrigger)
    {
        displayName = "Set Remote Trigger";
        displayNameDefault = "<img image='\a3\ui_f\data\GUI\Cfg\Hints\UAVConncetion_ca.paa' size='2.5' />";
        priority = 10;
        radius = 6; // a too small radius might cause the action to not be visible
        position = "";
        showWindow = 1;
        hideOnUse = 1;
        onlyForPlayer = 0;
        shortcut = "";
        condition = QUOTE([this] call FUNC(canSetTrigger));
        statement = QUOTE([this] call FUNC(setTrigger));
    };
    class GVAR(removeTrigger)
    {
        displayName = "Remove Remote Trigger";
        displayNameDefault = "";
        priority = 0;
        radius = 6; // a too small radius might cause the action to not be visible
        position = "";
        showWindow = 0;
        hideOnUse = 1;
        onlyForPlayer = 0;
        shortcut = "";
        condition = QUOTE([this] call FUNC(canRemoveTrigger));
        statement = QUOTE([this] call FUNC(setTrigger));
    };
};
