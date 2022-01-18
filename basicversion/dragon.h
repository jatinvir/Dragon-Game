#ifndef Dragon_H
#define Dragon_H
#include "enemy.h"

class Gold;

class Dragon: public Enemy {
    Gold *goldPtr;
public:
    Dragon(int x, int y);
    ~Dragon();
    void setGoldPtr(Gold *);
    int dropGold() const override;
    int beStruckBy(Player &) override;
};

#endif
