#include "human.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <cmath>

Human::Human(int x, int y)
    : Enemy(x, y, 120, 20, 20, 4) {}

void Human::strike(Shade &s) {
    int damage = ceil((100/(100 + s.getDef())) * atk);
    s.modifyHealth(-damage);
}

void Human::strike(Drow &d) {
    int damage = ceil((100/(100 + d.getDef())) * atk);
    d.modifyHealth(-damage);
}

void Human::strike(Vampire &v) {
    int damage = ceil((100/(100 + v.getDef())) * atk);
    v.modifyHealth(-damage);
}

void strike(Troll &t) {
    int damage = ceil((100/(100 + t.getDef())) * atk);
    t.modifyHealth(-damage);
}

void Human::strike(Goblin &g) {
    int damage = ceil((100/(100 + g.getDef())) * atk);
    g.modifyHealth(-damage);
}

void Human::beStruckBy(Player &p) {
    p.strike(*this);
}
