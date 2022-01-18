#include "dwarf.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <cmath>

Dwarf::Dwarf(int x, int y)
    : Enemy(x, y, 100, 20, 30, 2) {}

void Dwarf::strike(Shade &s) {
    int damage = ceil((100/(100 + s.getDef())) * atk);
    s.modifyHealth(-damage);
}

void Dwarf::strike(Drow &d) {
    int damage = ceil((100/(100 + d.getDef())) * atk);
    d.modifyHealth(-damage);
}

void Dwarf::strike(Vampire &v) {
    int damage = ceil((100/(100 + v.getDef())) * atk);
    v.modifyHealth(-damage);
}

void strike(Troll &t) {
    int damage = ceil((100/(100 + t.getDef())) * atk);
    t.modifyHealth(-damage);
}

void Dwarf::strike(Goblin &g) {
    int damage = ceil((100/(100 + g.getDef())) * atk);
    g.modifyHealth(-damage);
}

void Dwarf::beStruckBy(Player &p) {
    p.strike(*this);
}
