#include "potion.h"

Potion::Potion() {}

Potion::Potion(Stats *stats) : stats{stats} {}

Potion::~Potion() {}

int Potion::calcAtk() {
    int atk = stats->calcAtk();
    if (atk < 0) atk = 0;
    return atk;
}

int Potion::calcDef() {
    int def = stats->calcDef();
    if (def < 0) def = 0;
    return def;
}
