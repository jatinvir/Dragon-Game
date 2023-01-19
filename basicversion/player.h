#ifndef Player_H
#define Player_H

#include <memory>
#include <vector>
#include <string>
#include <cmath>
#include "stats.h"

class Potion;
class Enemy;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Player {
    const int baseAtk;
    const int baseDef;
    int gold;
protected:
    const int baseHp;
    int hp;
    std::vector<std::unique_ptr<Stats>> statStorage;
    Stats* stats;
public:
    Player(int hp, int atk, int def);

    // Getters
    virtual int getHp() const;
    virtual int getAtk() const;
    virtual int getDef() const;
    virtual int getGold() const;
    

    virtual void useHealthPotion(int effect);  // Add Health Potion Effect

    virtual float calcScore() const;           // Calculate Score of the Player
    virtual void addGold(int);

    void usePotion(std::unique_ptr<Potion> potion); // Add Potion Effect (Excluding Health Potions)
    void resetPotions(); // NOT COMPLETE

    virtual void modifyHealth(int diff);       // Adds 'diff' to player HP
    virtual void turn();                       // Called after every turn
    virtual void killBonus();                  // Bonus Functionality for killing enemy

    // Strike Enemy Functions
    void virtual strike(Human &);
    void virtual strike(Dwarf &);
    void virtual strike(Elf &);
    void virtual strike(Orcs &);
    void virtual strike(Halfling &);
    void virtual strike(Merchant &);
    void virtual strike(Dragon &);
    
    int virtual beStruckBy(Enemy &) = 0;       // Be Struck By Enemy Function
};

#endif
