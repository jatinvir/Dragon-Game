#include "orcs.h"
#include "goblin.h"
#include <cmath>

Orcs::Orcs(int x, int y) : Enemy{x, y, 180, 30, 25} {
    movement = std::make_unique<OneBlock>();
}

void Orcs::strike(Goblin &g) {
    int damage = calcDamage(g.getDef()) * 1.5;
    g.modifyHealth(-damage);
}

int Orcs::beStruckBy(Player &p) {
    int originalHp = hp;
    p.strike(*this);
    return originalHp - hp;
}
