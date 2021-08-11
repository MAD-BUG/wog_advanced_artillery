class CfgMovesBasic {
    class DefaultDie;

    class ManActions {
        wog_pab_2m_gunner = "wog_pab_2m_gunner";
    };
};

class CfgMovesMaleSdr: CfgMovesBasic {
    class States {
        class Crew;
        class wog_pab_2m_gunner: Crew {
            file = "wog_advanced_artillery\pab-2m\anim\pab_2m_gunner.rtm";
            interpolateTo[] = {"ACE_KIA_SpottingScope",1};
        };
    };
};