#ifndef Enemy_H
#define Enemy_H

#include "randomMove.h"
#include "randomMoveZeroBlock.h"
#include "randomMoveOneBlock.h"
#include "player.h"
#include <vector>
#include <memory>

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
    bool dropsPile;
    int calcDamage(int victimDef);
public:
    Enemy(int x, int y, int hp, int atk, int def, bool dropsPile = false);
    virtual ~Enemy();
    int getX() const;
    int getY() const;
    int getDef() const;
    int getHp() const;
    virtual int dropGold() const;
    bool getDropsPile() const;
    RandomMove *getMovement() const;
    void modifyHealth(int diff);  // adds diff to health
    void moveTo(int x, int y);
    void virtual strike(Shade &);
    void virtual strike(Drow &);
    void virtual strike(Vampire &);
    void virtual strike(Troll &);
    void virtual strike(Goblin &);
    int virtual beStruckBy(Player &) = 0; // returns damage taken by Enemy after being struck
};

#endif
