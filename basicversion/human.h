#ifndef Human_H
#define Human_H
#include "enemy.h"

class Human: public Enemy {
public:
    Human(int x, int y);
    int dropGold() const override;
    int beStruckBy(Player &) override;
};

#endif
