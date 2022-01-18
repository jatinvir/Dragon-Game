#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "shade.h"
#include "randomMoveOneBlock.h"
#include <cmath>

Enemy::Enemy(int x, int y, int hp, int atk, int def, bool dropsPile)
    : x{x}, y{y}, hp{hp}, atk{atk}, def{def}, dropsPile{dropsPile} {}

Enemy::~Enemy() {}

int Enemy::getX() const {
    return x;
}

int Enemy::getY() const {
    return y;
}

int Enemy::getDef() const {
    return def;
}

int Enemy::getHp() const {
    return hp;
}

int Enemy::dropGold() const {
    if (std::rand() % 2 == 0) {
        return 1;
    } else {
        return 2;
    }
}

bool Enemy::getDropsPile() const {
    return dropsPile;
}

void Enemy::modifyHealth(int diff) {
    hp += diff;
	if (hp < 0) hp = 0;
}

void Enemy::moveTo(int x, int y) {
    this->x = x;
    this->y = y;
}

RandomMove *Enemy::getMovement() const {
    return movement.get();
}

int Enemy::calcDamage(int victimDef) {
    if (std::rand() % 2 == 0) {
        return std::ceil((100.0/(100 + victimDef)) * atk);
    } else {
        return 0;
    }
}

void Enemy::strike(Shade &s) {
    s.modifyHealth(-calcDamage(s.getDef()));
}

void Enemy::strike(Drow &d) {
    d.modifyHealth(-calcDamage(d.getDef()));
}

void Enemy::strike(Vampire &v) {
    v.modifyHealth(-calcDamage(v.getDef()));
}

void Enemy::strike(Troll &t) {
    t.modifyHealth(-calcDamage(t.getDef()));
}

void Enemy::strike(Goblin &g) {
    g.modifyHealth(-calcDamage(g.getDef()));
}
