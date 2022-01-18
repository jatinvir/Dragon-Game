#ifndef boostDef_H
#define boostDef_H

#include "potion.h"

struct BoostDef: public Potion {
    BoostDef(Stats *stat);
    int calcDef() override;
};

#endif
