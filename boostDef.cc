#include "boostDef.h"
#include "stats.h"

BoostDef::BoostDef(Stats *stat)
    : stat{stat} {}

int BoostDef::calcDef() {
    return stat->calcDef() + 5;
}
