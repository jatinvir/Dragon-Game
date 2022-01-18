#ifndef baseStats_H
#define baseStats_H

#include "stats.h"

class BaseStats: public Stats {

    int hp;
    int atk;
    int def;
public:
    int calcHp() override;
    int calcAtk() override;
    int calcDef() override;

    BaseStats(int hp, int atk, int def);

};

#endif
