#include "randomMoveOneBlock.h"
#include <utility>
#include "cell.h"
#include "enemy.h"

void OneBlock::move(Cell *origin, Cell *dest, Enemy *enemy) {
	std::swap(origin->content, dest->content);
	enemy->moveTo(dest->x, dest->y);
}
