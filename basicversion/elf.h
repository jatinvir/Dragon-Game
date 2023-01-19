#ifndef Elf_H
#define Elf_H
#include "enemy.h"

class Elf: public Enemy {
public:
    Elf(int x, int y);
    void strike(Shade &) override;
    void strike(Vampire &) override;
    void strike(Troll &) override;
    void strike(Goblin &) override;
    int beStruckBy(Player &) override;
};

#endif
