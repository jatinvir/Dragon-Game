#ifndef Orcs_H
#define Orcs_H
#include "enemy.h"

class Orcs: public Enemy {
public:
    Orcs(int x, int y);
    void strike(Goblin &) override;
    int beStruckBy(Player &) override;
};

#endif
