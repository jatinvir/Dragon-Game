#ifndef Vampire_H
#define Vampire_H

#include "player.h"

class Vampire: public Player {
public:
    Vampire();
    void modifyHealth(int diff) override;
    
    void strike(Human &) override;
    void strike(Dwarf &) override;
    void strike(Elf &) override;
    void strike(Orcs &) override;
    void strike(Halfling &) override;
    void strike(Merchant &) override;
    void strike(Dragon &) override;
    
    int beStruckBy(Enemy &e) override;
};

#endif
