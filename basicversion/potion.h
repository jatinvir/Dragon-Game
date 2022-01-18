#ifndef Potion_H
#define Potion_H

#include "stats.h"

struct Potion: public Stats {
    Stats *stats;
    Potion();
    Potion(Stats *stats);
    virtual int calcAtk();
    virtual int calcDef();
    virtual ~Potion() = 0;
};

#endif
