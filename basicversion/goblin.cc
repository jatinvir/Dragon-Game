#include "goblin.h"
#include "enemy.h"

Goblin::Goblin() : Player{110,15,20} {}

void Goblin::killBonus() { addGold(5); }

int Goblin::beStruckBy(Enemy &e) {
    int originalHp = hp;
    e.strike(*this);
    return originalHp - hp;
}
