class CfgMagazines
{
    class 12Rnd_230mm_rockets;
    class 12Rnd_230mm_rockets_cluster;

    class GVAR(6Rnd_230mm_rockets): 12Rnd_230mm_rockets
    {
        count = 6;
    };
    class GVAR(PylonRack_6Rnd_230mm_rockets): GVAR(6Rnd_230mm_rockets)
    {
        displayName = "230mm 6x HE";
        model = "a3\Soft_F_Gamma\Truck_02\MRL_Magazine_01_F.p3d";
        hardpoints[] = {"B_MISSILE_PYLON"};
        pylonWeapon = QGVAR(6Rnd_230mm_rockets);
        mass = 500;
    };

    class GVAR(6Rnd_230mm_rockets_cluster): 12Rnd_230mm_rockets_cluster
    {
        count = 6;
    };
    class GVAR(PylonRack_6Rnd_230mm_rockets_cluster): GVAR(6Rnd_230mm_rockets_cluster)
    {
        displayName = "230mm 6x Cluster";
		descriptionShort = "Unguided rockets with cluster warhead";
        model = "a3\Soft_F_Gamma\Truck_02\MRL_Magazine_01_F.p3d";
        hardpoints[] = {"B_MISSILE_PYLON"};
        pylonWeapon = QGVAR(6Rnd_230mm_rockets_cluster);
        mass = 500;
    };

    class PylonMissile_1Rnd_Missile_AA_04_F;
    class GVAR(PylonMissile_1Rnd_Rocket_03_HE): PylonMissile_1Rnd_Missile_AA_04_F
    {
        displayName = "Tratnyr 1x HE";
        hardpoints[] = {"pya_hardpoint"};
        pylonWeapon = QGVAR(Rocket_03_HE);
        ammo = "Rocket_03_HE_F";
        mass = 10;
    };

};
