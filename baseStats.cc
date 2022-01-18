#include "baseStats.h"

BaseStats::BaseStats(int hp, int atk, int def)
    : hp{hp}, atk{atk}, def{def} {}

int BaseStats::calcHp() {
    return hp;
}

int BaseStats::calcAtk() {
    return atk;
}

int BaseStats::calcDef() {
    return def;
}
