#ifndef creator_H
#define creator_H

#include "enemy.h"
#include "potionbox.h"
#include "gold.h"
#include "dragonHoard.h"

#include <memory>

class Creator {
    virtual std::unique_ptr<Enemy> createEnemy() = 0;
    virtual std::unique_ptr<PotionBox> createPotion() = 0;
    virtual std::unique_ptr<Gold> createGold() = 0;
};

#endif
