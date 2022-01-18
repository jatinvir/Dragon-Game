#ifndef Shade_H
#define Shade_H
#include "player.h"

class Shade: public Player {
public:
    Shade();
    void strike(Human &) override;
    void strike(Dwarf &) override;
    void strike(Elf &) override;
    void strike(Orc &) override;
    void strike(Merchant &) override;
    void strike(Dragon &) override;
    void strike(Halfling &) override;
    void beStruckBy(Enemy &) override;
};

#endif
