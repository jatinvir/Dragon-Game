#ifndef POTIONBD_H
#define POTIONBD_H

#include "potion.h"

struct BoostDef: public Potion {
    BoostDef();
    BoostDef(Stats *Stats);
    int calcDef() override;
};

#endif
