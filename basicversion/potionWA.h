#ifndef POTIONWA_H
#define POTIONWA_H

#include "potion.h"

struct WoundAtk: public Potion {
    WoundAtk();
    WoundAtk(Stats *stats);
    int calcAtk() override;
};

#endif
