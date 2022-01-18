#include "dragon.h"
#include "gold.h"

Dragon::Dragon(int x, int y) : Enemy(x, y, 150, 20, 20) {
    movement = std::make_unique<ZeroBlock>();
}

Dragon::~Dragon() {
    if (goldPtr) goldPtr->d = nullptr;
}

void Dragon::setGoldPtr(Gold *g) {
    goldPtr = g;
}

int Dragon::dropGold() const {
    return 0;
}

int Dragon::beStruckBy(Player &p) {
    int originalHp = hp;
    p.strike(*this);
    return originalHp - hp;
}
