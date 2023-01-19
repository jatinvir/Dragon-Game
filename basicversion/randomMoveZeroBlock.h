#ifndef ZEROBLOCK_H
#define ZEROBLOCK_H

#include "randomMove.h"

struct ZeroBlock: public RandomMove {
	void move(Cell *origin, Cell *dest, Enemy *enemy) override;
};

#endif
