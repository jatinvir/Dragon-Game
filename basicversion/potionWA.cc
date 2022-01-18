#include "potionWA.h"

WoundAtk::WoundAtk() {}

WoundAtk::WoundAtk(Stats *stats) : Potion{stats} {}

int WoundAtk::calcAtk() {
    int atk = stats->calcAtk();
    if (atk < 0) atk = 0;
    return atk - 5;
}
