#ifndef RULES_H
#define RULES_H

/*
    UT_NONE     = -1,
    UT_INFANTRY     = 0,
    UT_MECH     = 1,
    UT_RECON     = 2,
    UT_TANK     = 3,
    UT_TANKM     = 4,
    UT_NEOTANK     = 5,
    UT_MEGATANK     = 6,
    UT_APC     = 7,
    UT_ARTILLERY     = 8,
    UT_MISSILELAUNCHER     = 9,
    UT_AAMISSILELAUNCHER     = 10,
    UT_AATANK     = 11,
    UT_TRANSPORTHELI     = 12,
    UT_BATTLEHELI     = 13,
    UT_FIGHTER     = 14,
    UT_BOMBER     = 15,
    UT_ASA     = 16,
    UT_LANDER     = 17,
    UT_CRUISER     = 18,
    UT_SUBMARINE     = 19,
    UT_BATTLESHIP     = 20,
    UT_CARRIER     = 21
*/
extern const int dmgRule[22*22];
extern const int maxRangeRule[22];
extern const int minRangeRule[22];
extern const int moveRangeRule[22];

#endif