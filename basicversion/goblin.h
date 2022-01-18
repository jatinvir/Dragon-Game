#ifndef Goblin_H
#define Goblin_H

#include "player.h"

class Goblin: public Player {
public:
    Goblin();
    void killBonus() override;
    int beStruckBy(Enemy &e) override;
};

#endif
