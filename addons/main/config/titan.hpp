class Weapon_Bag_Base;
class B_AA_01_weapon_F: Weapon_Bag_Base
{
    class assembleInfo;
};
class GVAR(B_AA_01_weapon): B_AA_01_weapon_F
{
    displayName = "Remote Titan Launcher (AA) [NATO]";
    class assembleInfo: assembleInfo
    {
        assembleTo = QGVAR(B_AA_01);
    };
};
class O_AA_01_weapon_F: Weapon_Bag_Base
{
    class assembleInfo;
};
class GVAR(O_AA_01_weapon): O_AA_01_weapon_F
{
    displayName = "Remote Titan Launcher (AA) [CSAT]";
    class assembleInfo: assembleInfo
    {
        assembleTo = QGVAR(O_AA_01);
    };
};
class I_AA_01_weapon_F: Weapon_Bag_Base
{
    class assembleInfo;
};
class GVAR(I_AA_01_weapon): I_AA_01_weapon_F
{
    displayName = "Remote Titan Launcher (AA) [AAF]";
    class assembleInfo: assembleInfo
    {
        assembleTo = QGVAR(I_AA_01);
    };
};

class B_AT_01_weapon_F: Weapon_Bag_Base
{
    class assembleInfo;
};
class GVAR(B_AT_01_weapon): B_AT_01_weapon_F
{
    displayName = "Remote Titan Launcher (AT) [NATO]";
    class assembleInfo: assembleInfo
    {
        assembleTo = QGVAR(B_AT_01);
    };
};
class O_AT_01_weapon_F: Weapon_Bag_Base
{
    class assembleInfo;
};
class GVAR(O_AT_01_weapon): O_AT_01_weapon_F
{
    displayName = "Remote Titan Launcher (AT) [CSAT]";
    class assembleInfo: assembleInfo
    {
        assembleTo = QGVAR(O_AT_01);
    };
};
class I_AT_01_weapon_F: Weapon_Bag_Base
{
    class assembleInfo;
};
class GVAR(I_AT_01_weapon): I_AT_01_weapon_F
{
    displayName = "Remote Titan Launcher (AT) [AAF]";
    class assembleInfo: assembleInfo
    {
        assembleTo = QGVAR(I_AT_01);
    };
};

class B_static_AA_F;
class GVAR(B_static_AA_F): B_static_AA_F
{
    class Turrets;
};
class GVAR(B_static_AA_F2): GVAR(B_static_AA_F)
{
    class assembleInfo;
    class Turrets: Turrets
    {
        class MainTurret;
    };
};
class GVAR(B_AA_01): GVAR(B_static_AA_F2)
{
    faction = "BLU_F";
    crew = "B_UAV_AI";
    displayName = "Remote Titan Launcher (AA) [NATO]";
    reportRemoteTargets = 1;
    reportOwnPosition = 1;
    isUav = 1;
    uavCameraGunnerPos = "eye";
    uavCameraGunnerDir = "look";
    class assembleInfo: assembleInfo
    {
        dissasembleTo[] = {QGVAR(B_AA_01_weapon), "B_HMG_01_support_F"};
    };
    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            gunnerForceOptics = 1;
        };
    };
};
class GVAR(O_AA_01): GVAR(B_AA_01)
{
    side = 0;
    faction = "OPF_F";
    crew = "O_UAV_AI";
    displayName = "Remote Titan Launcher (AA) [CSAT]";
    class assembleInfo: assembleInfo
    {
        dissasembleTo[] = {QGVAR(O_AA_01_weapon), "O_HMG_01_support_F"};
    };
    class Turrets: Turrets
    {
        class MainTurret: MainTurret {};
    };
};
class GVAR(I_AA_01): GVAR(B_AA_01)
{
    side = 2;
    faction = "IND_F";
    crew = "I_UAV_AI";
    displayName = "Remote Titan Launcher (AA) [AAF]";
    class assembleInfo: assembleInfo
    {
        dissasembleTo[] = {QGVAR(I_AA_01_weapon), "I_HMG_01_support_F"};
    };
    class Turrets: Turrets
    {
        class MainTurret: MainTurret {};
    };
};

class B_static_AT_F;
class GVAR(B_static_AT_F): B_static_AT_F
{
    class Turrets;
};
class GVAR(B_static_AT_F2): GVAR(B_static_AT_F)
{
    class assembleInfo;
    class Turrets: Turrets
    {
        class MainTurret;
    };
};
class GVAR(B_AT_01): GVAR(B_static_AT_F2)
{
    faction = "BLU_F";
    crew = "B_UAV_AI";
    displayName = "Remote Titan Launcher (AT) [NATO]";
    reportRemoteTargets = 1;
    reportOwnPosition = 1;
    isUav = 1;
    uavCameraGunnerPos = "eye";
    uavCameraGunnerDir = "look";
    class assembleInfo: assembleInfo
    {
        dissasembleTo[] = {QGVAR(B_AT_01_weapon), "B_HMG_01_support_F"};
    };
    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            gunnerForceOptics = 1;

        };
    };
};
class GVAR(O_AT_01): GVAR(B_AT_01)
{
    side = 0;
    faction = "OPF_F";
    crew = "O_UAV_AI";
    displayName = "Remote Titan Launcher (AT) [CSAT]";
    class assembleInfo: assembleInfo
    {
        dissasembleTo[] = {QGVAR(O_AT_01_weapon), "O_HMG_01_support_F"};
    };
    class Turrets: Turrets
    {
        class MainTurret: MainTurret {};
    };
};
class GVAR(I_AT_01): GVAR(B_AT_01)
{
    side = 2;
    faction = "IND_F";
    crew = "I_UAV_AI";
    displayName = "Remote Titan Launcher (AT) [AAF]";
    class assembleInfo: assembleInfo
    {
        dissasembleTo[] = {QGVAR(I_AT_01_weapon), "I_HMG_01_support_F"};
    };
    class Turrets: Turrets
    {
        class MainTurret: MainTurret {};
    };
};
