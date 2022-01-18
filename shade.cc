#include "shade.h"
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
#include <iostream>
using namespace std;

Shade::Shade() : Player(125) {
    //stats = make_unique<BaseStats>(125, 25, 25);
}

void Shade::strike(Human &h) {
    int damage = ceil((100 /(100 + h.getDef())) * stats->calcAtk());
    h.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to H (" << h.getHp() << " HP). H deals 5 damage to PC.";
}

void Shade::strike(Dwarf &d) {
    int damage = ceil((100 /(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
    cout << "PC deals " << damage <<  " damage to D (" << d.getHp() << " HP). D deals 5 damage to PC.";

}

void Shade::strike(Elf &e) {
    int damage = ceil((100 /(100 + e.getDef())) * stats->calcAtk());
    e.modifyHealth(-damage);
    cout << "PC deals " << damage <<  " damage to E (" << e.getHp() << " HP). E deals 5 damage to PC.";
}

void Shade::strike(Orc &o) {
    int damage = ceil((100 /(100 + o.getDef())) * stats->calcAtk());
    o.modifyHealth(-damage);
    cout << "PC deals " << damage << " damage to E (" << o.getHp() << " HP). H deals 5 damage to PC.";
}

void Shade::strike(Merchant &m) {
    int damage = ceil((100 /(100 + m.getDef())) * stats->calcAtk());
    m.modifyHealth(-damage);
    cout << "PC deals " << damage <<  " damage to M (" << m.getHp() << " HP). M deals 5 damage to PC.";
}

void Shade::strike(Halfling &ha) {
    int damage = ceil((100 /(100 + ha.getDef())) * stats->calcAtk());
    ha.modifyHealth(-damage);
    cout << "PC deals " << damage <<  " damage to D (" << ha.getHp() << " HP). D deals 5 damage to PC.";
}

void Shade::strike(Dragon &d) {
    int damage = ceil((100 /(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
    cout << "PC deals " << damage <<  " damage to D (" << d.getHp() << " HP). D deals 5 damage to PC.";
}

void Shade::beStruckBy(Enemy &e) {
    e.strike(*this);
}
