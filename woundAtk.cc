#include "woundAtk.h"
#include "stats.h"

WoundAtk::WoundAtk(Stats *stat)
    : stat{stat} {}

int WoundAtk::calcAtk() {
    return stat->calcAtk() - 5;
}
