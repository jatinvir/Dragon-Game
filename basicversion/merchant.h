#ifndef Merchant_H
#define Merchant_H
#include "enemy.h"

class Merchant: public Enemy {
public:
    Merchant(int x, int y);
    int dropGold() const override;
    int beStruckBy(Player &) override;
};

#endif
