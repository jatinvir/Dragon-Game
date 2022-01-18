#ifndef Dwarf_H
#define Dwarf_H
#include "enemy.h"

class Dwarf: public Enemy {
public:
    int x;
    int y;
    int hp;
    int atk;
    int def;
    int goldAmt;
    Dwarf(int x, int y);
    int getDef() const;
    int getHp() const;
    void modifyHealth(int damage);
    void move();
    void dropGold() override;
    void strike(Shade &) override;
    void strike(Drow &) override;
    void strike(Vampire &) override;
    void strike(Troll &) override;
    void strike(Goblin &) override;
    void beStruckBy(Player &) override;
};

#endif
