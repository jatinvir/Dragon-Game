#include "merchant.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <cmath>

Merchant::Merchant(int x, int y)
    : Enemy(x, y, 180, 30, 25, 2, true) {}

void Merchant::strike(Shade &s) {
    int damage = ceil((100/(100 + s.getDef())) * atk);
    s.modifyHealth(damage);
}

void Merchant::strike(Drow &d) {
    int damage = ceil((100/(100 + d.getDef())) * atk);
    d.modifyHealth(damage);
}

void Merchant::strike(Vampire &v) {
    int damage = ceil((100/(100 + v.getDef())) * atk);
    v.modifyHealth(damage);
}

void strike(Troll &t) {
    int damage = ceil((100/(100 + t.getDef())) * atk);
    t.modifyHealth(damage);
}

void Merchant::strike(Goblin &g) {
    int damage = ceil((100/(100 + g.getDef())) * atk);
    g.modifyHealth(damage);
}

void Merchant::beStruckBy(Player &p) {
    p.strike(*this);
}
