#ifndef ZEROBLOCK_H
#define ZEROBLOCK_H

#include "randomMove.h"

struct ZeroBlock: public RandomMove {
	void move(int &cX, int &cY, int &dX, int &dY, int &eX, int &eY) override;
};

#endif
