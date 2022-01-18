#ifndef ONEBLOCK_H
#define ONEBLOCK_H

#include "randomMove.h"

struct OneBlock: public RandomMove {
	void move(Cell *origin, Cell *dest, Enemy *enemy) override;
};

#endif
