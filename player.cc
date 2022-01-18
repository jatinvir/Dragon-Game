#include "player.h"
#include "potion.h"
#include <iostream>
using namespace std;

Player::Player(int hp) : hp{hp} {
    cout << "Player character has spwaned." << endl;
}

int Player::getHp() const {
    return hp;
}

int Player::getAtk() const {
    return stats->calcAtk();
}

int Player::getDef() const {
    return stats->calcDef();
}

void Player::modifyHealth(int diff) {
    hp += diff;
}

void applyPotion(std::unique_ptr<Potion> p) {
    p->stats = std::move(stats);
    stats = std::move(p);
}
/*
void clearPotions() {
    std::unique_ptr<Stats> temp = stats;
    stats = 
}
*/