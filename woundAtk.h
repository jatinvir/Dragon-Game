#ifndef woundAtk_H
#define woundAtk_H

#include "potion.h"

struct WoundAtk: public Potion {
    WoundAtk(Stats *stat);
    int calcAtk() override;
};

#endif
