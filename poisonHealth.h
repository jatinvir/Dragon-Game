#ifndef poisonHealth_H
#define poisonHealth_H

#include "potion.h"

struct PoisonHealth: public Potion {
    PoisonHealth(Stats *stat);
    int calcHp() override;
};

#endif
