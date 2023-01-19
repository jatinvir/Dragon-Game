#ifndef Dwarf_H
#define Dwarf_H
#include "enemy.h"

class Dwarf: public Enemy {
public:
    Dwarf(int x, int y);
    int beStruckBy(Player &) override;
};

#endif
