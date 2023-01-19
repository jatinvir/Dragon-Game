#include "drow.h"
#include "enemy.h"

Drow::Drow() : Player{150,25,15} {}

int Drow::getAtk() const { return stats->calcAtk() * 1.5; } 
int Drow::getDef() const { return stats->calcDef() * 1.5; }

void Drow::useHealthPotion(int effect) {
    hp += (effect * 1.5);
    if (hp < 0) hp = 0;
    if (hp > baseHp) hp = baseHp;
}

int Drow::beStruckBy(Enemy &e) {
    int originalHp = hp;
    e.strike(*this);
    return originalHp - hp;
}
