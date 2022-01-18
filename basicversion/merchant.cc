#include "merchant.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Merchant::Merchant(int x, int y) : Enemy{x, y, 30, 70, 5, true} {
    movement = std::make_unique<OneBlock>();
}

int Merchant::dropGold() const {
    return 4;
}

int Merchant::beStruckBy(Player &p) {
    int originalHp = hp;
    p.strike(*this);
    return originalHp - hp;
}
