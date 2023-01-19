#ifndef Troll_H
#define Troll_H

#include "player.h"

class Troll: public Player {
public:
    Troll();
    void turn() override;
    int beStruckBy(Enemy &e) override;
};

#endif
