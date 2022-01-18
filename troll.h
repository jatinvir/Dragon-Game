#ifndef Troll_H
#define Troll_H
#include "player.h"

class Troll: public Player {
public:
    Troll();
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
