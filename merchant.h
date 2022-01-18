#ifndef Merchant_H
#define Merchant_H
#include "enemy.h"

class Merchant: public Enemy {
public:
    Merchant(int x, int y);
    void strike(Shade &) override;
    void strike(Drow &) override;
    void strike(Vampire &) override;
    void strike(Troll &) override;
    void strike(Goblin &) override;
    void beStruckBy(Player &) override;
};

#endif
