#ifndef Orc_H
#define Orc_H
#include "enemy.h"

class Orcs: public Enemy {
public:
    Orcs(int x, int y);
    void strike(Shade &) override;
    void strike(Drow &) override;
    void strike(Vampire &) override;
    void strike(Troll &) override;
    void strike(Goblin &) override;
    void beStruckBy(Player &) override;
};

#endif
