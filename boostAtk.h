#ifndef boostAtk_H
#define boostAtk_H

#include "potion.h"

struct BoostAtk: public Potion {
    BoostAtk(Stats *stat);
    int calcAtk() override;
};

#endif
