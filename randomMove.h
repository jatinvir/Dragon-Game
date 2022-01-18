#ifndef RANDOMMOVE_H
#define RANDOMMOVE_H

struct RandomMove {
	virtual void move(int &cX, int &cY, int &dX, int &dY, int &eX, int &eY) = 0;
};

#endif
