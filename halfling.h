#ifndef Halfling_H
#define Halfling_H
#include "enemy.h"

class Halfling: public Enemy {
public:
    Halfling(int x, int y);
    void strike(Shade &) override;
    void strike(Drow &) override;
    void strike(Vampire &) override;
    void strike(Troll &) override;
    void strike(Goblin &) override;
    void beStruckBy(Player &) override;
};

#endif
