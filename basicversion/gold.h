#ifndef GOLD_H
#define GOLD_H

struct Dragon;

struct Gold {
	int x,y;
	int val;
	Dragon *d;
	Gold(int x, int y, int val, Dragon *d);
	Gold(int x, int y, Dragon *d);
	Gold(int x, int y, int val);
	~Gold();
};

#endif
