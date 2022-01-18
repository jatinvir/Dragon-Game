#ifndef Player_H
#define Player_H
#include <memory>

class Stats;
class Potion;
class Enemy;
class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Dragon;
class Halfling;

class Player {
    int x;
    int y;
protected:
    std::unique_ptr<Stats> stats;
public:
    Player(int hp);
    int getHp() const;
    int getAtk() const;
    int getDef() const;
    void modifyHealth(int diff);
    void applyPotion(std::unique_ptr<Potion>);
    void virtual strike(Human &) = 0;
    void virtual strike(Dwarf &) = 0;
    void virtual strike(Elf &) = 0;
    void virtual strike(Orc &) = 0;
    void virtual strike(Merchant &) = 0;
    void virtual strike(Dragon &) = 0;
    void virtual strike(Halfling &) = 0;
    void virtual beStruckBy(Enemy &) = 0;
};

#endif
