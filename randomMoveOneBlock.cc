#include "randomMoveOneBlock.h"
#include <utility>

void OneBlock::move(int &cX, int &cY, int &dX, int &dY, int &eX, int &eY) {
	int destX = dX;
	int destY = dY;
	
	std::swap(cX, dX);
	std::swap(cY, dY);

	eX = destX;
	eY = destY;
}
