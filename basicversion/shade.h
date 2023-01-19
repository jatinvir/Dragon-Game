#ifndef Shade_H
#define Shade_H

#include "player.h"

class Shade: public Player {
public:
    Shade();
    float calcScore() const override;
    int beStruckBy(Enemy &e) override;
};

#endif
