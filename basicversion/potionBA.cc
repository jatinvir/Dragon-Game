#include "potionBA.h"

BoostAtk::BoostAtk() {}

BoostAtk::BoostAtk(Stats *stats) : Potion{stats} {}

int BoostAtk::calcAtk() {
    int atk = stats->calcAtk();
    if (atk < 0) atk = 0;
    return atk + 5;
}
