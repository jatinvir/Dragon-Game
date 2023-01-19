#ifndef baseStats_H
#define baseStats_H

#include "stats.h"

class BaseStats: public Stats {
    const int atk;
    const int def;
public:
    int calcAtk() override;
    int calcDef() override;

    BaseStats(int atk, int def);
};

#endif
