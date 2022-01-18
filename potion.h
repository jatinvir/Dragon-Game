#ifndef Potion_H
#define Potion_H

#include <memory>
#include "stats.h"

struct Potion: public Stats {
    std::unique_ptr<Stats> stats;
    virtual int calcHp() { return stat->calcHp(); }
    virtual int calcAtk() { return stat->calcAtk(); }
    virtual int calcDef() { return stat->calcDef(); }
    virtual ~Potion() = 0;
};

#endif
