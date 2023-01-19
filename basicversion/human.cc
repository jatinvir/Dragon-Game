#include "human.h"

Human::Human(int x, int y) : Enemy{x, y, 120, 20, 20, true} {
    movement = std::make_unique<OneBlock>();
}

int Human::dropGold() const {
    return 4;
}

int Human::beStruckBy(Player &p) {
    //int random = rand() % 2;
    int originalHp = hp;
    //if (random == 0) p.strike(*this);
    p.strike(*this);
    return originalHp - hp;
}
