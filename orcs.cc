#include "orcs.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <cmath>

Orcs::Orcs(int x, int y)
    : Enemy(x, y, 180, 30, 25, 2) {}

void Orcs::strike(Shade &s) {
    int damage = ceil((100/(100 + s.getDef())) * atk);
    s.modifyHealth(damage);
}

void Orcs::strike(Drow &d) {
    int damage = ceil((100/(100 + d.getDef())) * atk);
    d.modifyHealth(damage);
}

void Orcs::strike(Vampire &v) {
    int damage = ceil((100/(100 + v.getDef())) * atk);
    v.modifyHealth(damage);
}

void strike(Troll &t) {
    int damage = ceil((100/(100 + t.getDef())) * atk);
    t.modifyHealth(damage);
}

void Orcs::strike(Goblin &g) {
    int damage = ceil((100/(100 + g.getDef())) * atk);
    g.modifyHealth(damage);
}

void Orcs::beStruckBy(Player &p) {
    p.strike(*this);
}
