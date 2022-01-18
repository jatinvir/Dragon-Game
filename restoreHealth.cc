#include "restoreHealth.h"
#include "stats.h"

RestoreHealth::RestoreHealth(Stats *stat)
    : stat{stat} {}

int RestoreHealth::calcHp() {
    return stat->calcHp() + 10;
}
