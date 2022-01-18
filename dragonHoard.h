#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H

#include "gold.h"

struct DragonHoard: public Gold {
	Dragon * d;
	DragonHoard(int x, int y, int val, Dragon* d);
};

#endif
