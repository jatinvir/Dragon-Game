#include "vampire.h"
#include "stats.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"
#include <cmath>

Vampire::Vampire() : Player(50) {
    //stats = make_unique<BaseStats>(50, 25, 25);
}

void Vampire::strike(Human &h) {
    int damage = ceil((100.0/(100 + h.getDef())) * stats->calcAtk());
    h.modifyHealth(-damage);
}

void Vampire::strike(Dwarf &d) {
    int damage = ceil((100.0/(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
}

void Vampire::strike(Elf &e) {
    int damage = ceil((100.0/(100 + e.getDef())) * stats->calcAtk());
    e.modifyHealth(-damage);
}

void Vampire::strike(Merchant &m) {
    int damage = ceil((100.0/(100 + m.getDef())) * stats->calcAtk());
    m.modifyHealth(-damage);
}

void Vampire::strike(Halfling &ha) {
    int damage = ceil((100.0/(100 + ha.getDef())) * stats->calcAtk());
    ha.modifyHealth(-damage);
}

void Vampire::strike(Dragon &d) {
    int damage = ceil((100.0/(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
}

void beStruckBy(Enemy &e) {
    e.strike(*this);
}