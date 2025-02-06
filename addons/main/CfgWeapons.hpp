class CfgWeapons
{
    class rockets_230mm_GAT;
    class GVAR(6Rnd_230mm_rockets): rockets_230mm_GAT
    {
        magazines[] = {QGVAR(6Rnd_230mm_rockets), QGVAR(PylonRack_6Rnd_230mm_rockets)};
    };
    class GVAR(6Rnd_230mm_rockets_cluster): rockets_230mm_GAT
    {
        magazines[] = {QGVAR(6Rnd_230mm_rockets_cluster), QGVAR(PylonRack_6Rnd_230mm_rockets_cluster)};
    };
};
