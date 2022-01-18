#include "goblin.h"
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

Goblin::Goblin() : Player(110) {
    //stats = make_unique<BaseStats>(125, 15, 25);
}

void strike(Human &h) {
    int damage = ceil((100.0/(100 + h.getDef())) * stat->calcAtk());
    h.modifyHealth(-damage);
}

void strike(Dwarf &d) {
    int damage = ceil((100.0/(100 + d.getDef())) * stat->calcAtk());
    d.modifyHealth(-damage);
}

void strike(Merchant &m) {
    int damage = ceil((100.0/(100 + m.getDef())) * stat->calcAtk());
    m.modifyHealth(-damage);
}

void strike(Halfling &ha) {
    int damage = ceil((100.0/(100 + ha.getDef())) * stats->calcAtk());
    ha.modifyHealth(-damage);
}

void strike(Human &h) {
    int damage = ceil((100.0/(100 + h.getDef())) * stat->calcAtk());
    h.modifyHealth(-damage);
}

void beStruckBy(Enemy &e) {
    e.strike(*this);
}
