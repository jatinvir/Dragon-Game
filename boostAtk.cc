#include "boostAtk.h"
#include "stats.h"

BoostAtk::BoostAtk(Stats *stat)
    : stat{stat} {}

int BoostAtk::calcAtk() {
    return stat->calcAtk() + 5;
}
