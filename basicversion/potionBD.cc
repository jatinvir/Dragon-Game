#include "potionBD.h"

BoostDef::BoostDef() {}

BoostDef::BoostDef(Stats *stats) : Potion{stats} {}

int BoostDef::calcDef() {
    int def = stats->calcDef();
    if (def < 0) def = 0;
    return def + 5;
}
