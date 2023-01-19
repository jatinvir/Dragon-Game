#include "troll.h"
#include "enemy.h"

Troll::Troll() : Player{120,25,15} {}

void Troll::turn() { modifyHealth(5); }

int Troll::beStruckBy(Enemy &e) {
    int originalHp = hp;
    e.strike(*this);
    return originalHp - hp;
}
