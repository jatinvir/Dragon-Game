#ifndef woundDef_H
#define woundDef_H

#include "potion.h"

struct WoundDef: public Potion {
    WoundDef(Stats *stat);
    int calcDef() override;
};

#endif
