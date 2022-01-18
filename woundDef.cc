#include "woundDef.h"
#include "stats.h"
#include "potion.h"

WoundDef::WoundDef(Stats *stat)
    : stat{stat} {}

int WoundDef::calcDef() {
    return stat->calcDef() - 5;
}
