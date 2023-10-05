class Components: Components
{
    class TransportPylonsComponent
    {
        //uiPicture = "\A3\Air_F_Exp\UAV_03\Data\UI\Map_UAV_03_3DEN_CA.paa";
        uiPicture = "";
        class Pylons
        {
            class Pylons1
            {
                hardpoints[] = {ALL_HARDPOINTS};
                attachment = "";
                priority = 5;
                turret[] = {0};
                maxweight = 10000;
                UIposition[] = {0.35, 0.20};
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
};
