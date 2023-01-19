#ifndef CELL_H
#define CELL_H

struct Cell {
	const int x;
	const int y;
	char content;
	Cell(int x, int y, char content);
};

#endif
