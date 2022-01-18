#ifndef CHAMBER_H
#define CHAMBER_H

#include "cell.h"
#include <vector>

struct Chamber{
	int id;
	std::vector<Cell *> cells;
	Chamber(int id);
};

#endif
