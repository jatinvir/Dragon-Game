#ifndef Drow_H
#define Drow_H

#include "player.h"

class Drow: public Player {
public:
    Drow();
    int getAtk() const override;
    int getDef() const override;
    void useHealthPotion(int effect) override;
    int beStruckBy(Enemy &e) override;
};

#endif
