#include "elf.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Elf::Elf(int x, int y) : Enemy{x, y, 140, 30, 10} {
    movement = std::make_unique<OneBlock>();
}

void Elf::strike(Shade &s) {
    s.modifyHealth(-calcDamage(s.getDef()));
    s.modifyHealth(-calcDamage(s.getDef()));
}

void Elf::strike(Vampire &v) {
    v.modifyHealth(-calcDamage(v.getDef()));
    v.modifyHealth(-calcDamage(v.getDef()));
}

void Elf::strike(Troll &t) {
    t.modifyHealth(-calcDamage(t.getDef()));
    t.modifyHealth(-calcDamage(t.getDef()));
}

void Elf::strike(Goblin &g) {
    g.modifyHealth(-calcDamage(g.getDef()));
    g.modifyHealth(-calcDamage(g.getDef()));
}


int Elf::beStruckBy(Player &p) {
    int originalHp = hp;
    p.strike(*this);
    return originalHp - hp;
}
