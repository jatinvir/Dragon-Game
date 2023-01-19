#ifndef POTIONBA_H
#define POTIONBA_H

#include "potion.h"

struct BoostAtk: public Potion {
    BoostAtk();
    BoostAtk(Stats *stats);
    int calcAtk() override;
};

#endif
