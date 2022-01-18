#ifndef ONEBLOCK_H
#define ONEBLOCK_H

#include "randomMove.h"

struct OneBlock: public RandomMove {
	void move(int &cX, int &cY, int &dX, int &dY, int &eX, int &eY) override;
};

#endif
