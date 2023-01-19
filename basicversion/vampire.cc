#include "vampire.h"
#include "enemy.h"

#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

Vampire::Vampire() : Player{50,25,25} {}

void Vampire::strike(Human &h) {
    int damage = std::ceil((100.0/(100 + h.getDef())) * stats->calcAtk());
    h.modifyHealth(-damage);
    modifyHealth(5);
}

void Vampire::strike(Dwarf &d) {
    int damage = std::ceil((100.0/(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
    modifyHealth(-5);
}

void Vampire::strike(Elf &e) {
    int damage = std::ceil((100.0/(100 + e.getDef())) * stats->calcAtk());
    e.modifyHealth(-damage);
    modifyHealth(5);
}

void Vampire::strike(Orcs &o) {
    int damage = std::ceil((100.0/(100 + o.getDef())) * stats->calcAtk());
    o.modifyHealth(-damage);
    modifyHealth(5);
}

void Vampire::strike(Halfling &ha) {
    int damage = std::ceil((100.0/(100 + ha.getDef())) * stats->calcAtk());
    ha.modifyHealth(-damage);
    modifyHealth(5);
}

void Vampire::strike(Merchant &m) {
    int damage = std::ceil((100.0/(100 + m.getDef())) * stats->calcAtk());
    m.modifyHealth(-damage);
    modifyHealth(5);
}

void Vampire::strike(Dragon &d) {
    int damage = std::ceil((100.0/(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
    modifyHealth(5);
}

void Vampire::modifyHealth(int diff) {
	hp += diff;
	if (hp < 0) hp = 0;
}

int Vampire::beStruckBy(Enemy &e) {
    int originalHp = hp;
    e.strike(*this);
    return originalHp - hp;
}
