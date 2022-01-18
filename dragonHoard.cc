#include "dragonHoard.h"

DragonHoard::DragonHoard(int x, int y, int val, Dragon* d)
	: Gold(x, y, val), d{d}
{}
