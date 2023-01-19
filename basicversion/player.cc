#include "player.h"
#include "baseStats.h"
#include "potion.h"

#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

Player::Player(int hp, int atk, int def) : baseAtk{atk}, baseDef{def}, gold{0}, baseHp{hp}, hp{hp} {
	auto base = std::make_unique<BaseStats>(atk, def);
	stats = base.get();
	statStorage.push_back(std::move(base));
}

int Player::getHp() const { return hp; }
int Player::getAtk() const { return stats->calcAtk(); }
int Player::getDef() const { return stats->calcDef(); }
void Player::useHealthPotion(int effect) { modifyHealth(effect); }

int Player::getGold() const { return (*this).gold; }
float Player::calcScore() const { return gold; }
void Player::addGold(int g) { gold += g; }

void Player::usePotion(std::unique_ptr<Potion> potion) {
	potion->stats = stats;
	stats = potion.get();
	statStorage.push_back(std::move(potion));
}

void Player::resetPotions() {
	stats = nullptr;
	for (auto it = statStorage.begin(); it != statStorage.end(); ++it) {
		statStorage.erase(it);
	}	
	auto base = std::make_unique<BaseStats>(baseAtk, baseDef);
	stats = base.get();
	statStorage.push_back(std::move(base));
}

void Player::modifyHealth(int diff) {
	hp += diff;
	if (hp < 0) hp = 0;
	if (hp > baseHp) hp = baseHp;
}
void Player::turn() {}
void Player::killBonus() {}

// Strike Functions
void Player::strike(Human &h) {
    int damage = std::ceil((100.0/(100 + h.getDef())) * stats->calcAtk());
    h.modifyHealth(-damage);
}

void Player::strike(Dwarf &d) {
    int damage = std::ceil((100.0/(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
}

void Player::strike(Elf &e) {
    int damage = std::ceil((100.0/(100 + e.getDef())) * stats->calcAtk());
    e.modifyHealth(-damage);
}

void Player::strike(Orcs &o) {
    int damage = std::ceil((100.0/(100 + o.getDef())) * stats->calcAtk());
    o.modifyHealth(-damage);
}

void Player::strike(Halfling &ha) {
    int damage = std::ceil((100.0/(100 + ha.getDef())) * stats->calcAtk());
    ha.modifyHealth(-damage);
}

void Player::strike(Merchant &m) {
    int damage = std::ceil((100.0/(100 + m.getDef())) * stats->calcAtk());
    m.modifyHealth(-damage);
}

void Player::strike(Dragon &d) {
    int damage = std::ceil((100.0/(100 + d.getDef())) * stats->calcAtk());
    d.modifyHealth(-damage);
}

