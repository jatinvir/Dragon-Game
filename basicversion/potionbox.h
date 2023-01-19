#ifndef POTIONBOX_H
#define POTIONBOX_H

#include <string>

struct PotionBox {
	int x,y;
	std::string potionType;
	PotionBox(int x, int y, std::string potionType);
};

#endif
