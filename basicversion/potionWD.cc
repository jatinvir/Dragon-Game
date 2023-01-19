#include "potionWD.h"

WoundDef::WoundDef() {}

WoundDef::WoundDef(Stats *stats) : Potion{stats} {}

int WoundDef::calcDef() {
    int def = stats->calcDef();
    if (def < 0) def = 0;
    return def - 5;
}
