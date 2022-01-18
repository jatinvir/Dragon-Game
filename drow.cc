#include "drow.h"
#include "stats.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "dragon.h"
#include "merchant.h"
#include "halfling.h"
#include "orcs.h"
#include <cmath>
#include <iostream>

using namespace std;

Drow::Drow() : Player(150) {
    //stats = make_unique<BaseStats>(150, 25, 15);
}

void Drow::strike(Human &h) {
    int damage = ceil((100 /(100 + h.getDef())) * stats->calcAtk());
    h.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to H (" << h.getHp() << " HP). H deals 5 damage to PC.";
}

void Drow::strike(Dwarf &d) {
    int damage = ceil((100 /(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to D (" << d.getHp() << " HP). D deals 5 damage to PC.";
}

void Drow::strike(Elf &e) {
    int damage = ceil((100 /(100 + e.getDef())) * stats->calcAtk());
    e.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to E (" << e.getHp() << " HP). H deals 5 damage to PC.";
}

void Drow::strike(Orc &o) {
    int damage = ceil((100 /(100 + o.getDef())) * stats->calcAtk());
    o.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to O (" << o.getHp() << " HP). H deals 5 damage to PC.";
}

void Drow::strike(Merchant &m) {
    int damage = ceil((100 /(100 + m.getDef())) * stats->calcAtk());
    m.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to H (" << m.getHp() << " HP). M deals 5 damage to PC.";
}

void Drow::strike(Halfling &ha) {
    int damage = ceil((100 /(100 + ha.getDef())) * stats->calcAtk());
    ha.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to H (" << ha.getHp() << " HP). Ha deals 5 damage to PC.";
}

void Drow::strike(Dragon &d) {
    int damage = ceil((100 /(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to H (" << d.getHp() << " HP). Ha deals 5 damage to PC.";
}

void Drow::beStruckBy(Enemy &e) {
    e.strike(*this);
}
