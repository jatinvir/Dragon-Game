#ifndef Halfing_H
#define Halfing_H
#include "enemy.h"

class Halfling: public Enemy {
public:
    Halfling(int x, int y);
    int beStruckBy(Player &) override;
};

#endif
