#include "poisonHealth.h"
#include "stats.h"

PoisonHealth::PoisonHealth(Stats *stat)
    : stat{stat} {}

int PoisonHealth::calcHp() {
    int x = stat->calcHp() - 10;
    if (x < 0) {
        x = 0;
    }
    return x;
}
