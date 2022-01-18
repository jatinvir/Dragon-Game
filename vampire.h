#ifndef Vampire_H
#define Vampire_H
#include "player.h"

class Vampire: public Player {
public:
    Vampire();
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
