#include "troll.h"
#include "stats.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include <cmath>

Troll::Troll() : Player(120) {
    //stats = make_unique<BaseStats>(120, 25, 15);
}

void Troll::strike(Human &h) {
    int damage = ceil((100.0/(100 + h.getDef())) * stats->calcAtk());
    h.modifyHealth(-damage);
}

void Troll::strike(Dwarf &d) {
    int damage = ceil((100.0/(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
}

void Troll::strike(Merchant &m) {
    int damage = ceil((100.0/(100 + m.getDef())) * stats->calcAtk());
    m.modifyHealth(-damage);
}

void Troll::strike(Halfling &ha) {
    int damage = ceil((100.0/(100 + ha.getDef())) * stats->calcAtk());
    ha.modifyHealth(-damage);
}

void Troll::strike(Dragon &d) {
    int damage = ceil((100.0/(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
}

void beStruckBy(Enemy &e) {
    e.Troll::strike(*this);
}
