#ifndef POTIONWD_H
#define POTIONWD_H

#include "potion.h"

struct WoundDef: public Potion {
    WoundDef();
    WoundDef(Stats *stats);
    int calcDef() override;
};

#endif
