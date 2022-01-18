#ifndef restoreHealth_H
#define restoreHealth_H

#include "potion.h"

struct RestoreHealth: public Potion {
    RestoreHealth(Stats *stat);
    int calcHp() override;
};

#endif
