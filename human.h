#ifndef Human_H
#define Human_H
#include "enemy.h"

class Human: public Enemy {
public:
    Human(int x, int y);
    void strike(Shade &) override;
    void strike(Drow &) override;
    void strike(Vampire &) override;
    void strike(Troll &) override;
    void strike(Goblin &) override;
    void beStruckBy(Player &) override;
};

#endif
