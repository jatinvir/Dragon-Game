#ifndef concreteCreator_H
#define concreteCreator_H

#include "creator.h"

class ConcreteCreator: public Creator {
  public:
    std::unique_ptr<Enemy> createEnemy(char &, int, int) override;
    std::unique_ptr<PotionBox> createPotion() override;
    std::unique_ptr<Gold> createGold() override;
    
    std::unique_ptr<PotionBox> createPotion(char) override;
    std::unique_ptr<Gold> createGold(int) override;
    std::unique_ptr<Enemy> createEnemyType(char, int, int) override;
};

#endif
