#include "shade.h"
#include "enemy.h"

Shade::Shade() : Player{125,25,25} {}

float Shade::calcScore() const { return getGold() * 1.5; }

int Shade::beStruckBy(Enemy &e) {
    int originalHp = hp;
    e.strike(*this);
    return originalHp - hp;
}
