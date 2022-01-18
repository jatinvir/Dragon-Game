#ifndef RANDOMMOVE_H
#define RANDOMMOVE_H

class Cell;
class Enemy;

struct RandomMove {
	virtual void move(Cell *origin, Cell *dest, Enemy *enemy) = 0;
};

#endif
