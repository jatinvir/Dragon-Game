#include "dwarf.h"

Dwarf::Dwarf(int x, int y) : Enemy{x, y, 100, 20, 30} {
    movement = std::make_unique<OneBlock>();
}

int Dwarf::beStruckBy(Player &p) {
    int originalHp = hp;
    p.strike(*this);
    return originalHp - hp;
}
