#include "baseStats.h"

BaseStats::BaseStats(int atk, int def): atk{atk}, def{def} {}

int BaseStats::calcAtk() { return atk; }
int BaseStats::calcDef() { return def; }
