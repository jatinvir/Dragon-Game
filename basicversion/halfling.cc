#include "halfling.h"

Halfling::Halfling(int x, int y) : Enemy{x, y, 100, 15, 20} {
    movement = std::make_unique<OneBlock>();
}

int Halfling::beStruckBy(Player &p) {
    int originalHp = hp;
    if (std::rand() % 2 == 0) {
        p.strike(*this);
    }
    return originalHp - hp;
}
