#ifndef creator_H
#define creator_H

#include "enemy.h"
#include "potionbox.h"
#include "gold.h"

#include <memory>

class Creator {
    virtual std::unique_ptr<Enemy> createEnemy(char &, int, int) = 0;
    virtual std::unique_ptr<PotionBox> createPotion() = 0;
    virtual std::unique_ptr<Gold> createGold() = 0;
    
    virtual std::unique_ptr<PotionBox> createPotion(char) = 0;
    virtual std::unique_ptr<Gold> createGold(int) = 0;
    virtual std::unique_ptr<Enemy> createEnemyType(char, int, int) = 0;
};

#endif
