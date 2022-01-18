#ifndef Drow_H
#define Shade_H
#include "player.h"

class Drow: public Player {
public:
    Drow();
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