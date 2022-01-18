#ifndef concreteCreator_H
#define concreteCreator_H

#include "creator.h"

class ConcreteCreator: public Creator {
  public:
    std::unique_ptr<Enemy> createEnemy() override;
    std::unique_ptr<Enemy> createEnemy(char type);
    std::unique_ptr<PotionBox> createPotion() override;
    std::unique_ptr<Gold> createGold() override;
};

#endif
