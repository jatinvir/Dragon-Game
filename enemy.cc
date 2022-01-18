#include "enemy.h"
#include "randomMoveOneBlock.h"
#include "gold.h"

Enemy::Enemy(int x, int y, int hp, int atk, int def, int goldAmt)
    : x{x}, y{y}, hp{hp}, atk{atk}, def{def}, goldAmt{goldAmt} {}

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

int Enemy::getAtk() const {
    return atk;
}

void Enemy::modifyHealth(int diff) {
    hp += diff;
}
void Enemy::move(int &currentX, int &currentY, int &destX, int &destY) {
	movement->move(currentX, currentY, destX, destY, x, y);
}
