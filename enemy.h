#ifndef Enemy_H
#define Enemy_H

#include "randomMove.h"
#include "randomMoveZeroBlock.h"
#include "randomMoveOneBlock.h"
#include <vector>
#include <memory>

class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class RandomMove;

class Enemy {
protected:
    std::unique_ptr<RandomMove> movement;
    int x;
    int y;
    int hp;
    int atk;
    int def;
    int goldAmt;
public:
    Enemy(int x, int y, int hp, int atk, int def, int goldAmt);
    int getX() const;
    int getY() const;
    int getDef() const;
    int getHp() const;
    int getAtk() const;
    void modifyHealth(int diff);  // adds diff to health
    void move(int &currentX, int &currentY, int &destX, int &destY);
    void virtual dropGold() = 0;
    void virtual strike(Shade &) = 0;
    void virtual strike(Drow &) = 0;
    void virtual strike(Vampire &) = 0;
    void virtual strike(Troll &) = 0;
    void virtual strike(Goblin &) = 0;
    void virtual beStruckBy(Player &) = 0;
};

#endif
