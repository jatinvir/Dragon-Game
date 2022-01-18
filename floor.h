#ifndef FLOOR_H
#define FLOOR_H

#include "cell.h"
#include "chamber.h"
#include "gold.h"
#include "potionbox.h"
#include "enemy.h"

#include <vector>
#include <memory>
#include <string>

class Floor{
	std::vector<std::unique_ptr<Cell>> globalVec;
	std::vector<std::unique_ptr<Chamber>> chamberVec;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<Gold>> golds;
	std::vector<std::unique_ptr<PotionBox>> potions;
	Cell* player;
	char prevContent; 

	int cellToChamberMap(Cell * cell);
	Cell* getCell(int x, int y); // Gets the pointer of the cell at (x,y)
	bool checkAccounted(Cell* cell, std::vector<Cell *> & cellList);
	void propagateCells(Cell *cell, std::vector<Cell *>& chamberCells, std::vector<Cell *>& accounted);

	void spawnItems();
		
	// Returns position of 1 empty cell with equal probability of it being in any of the 
	// chambers and for each chamber - equal probability of it being in any of its cell
	Cell randomCell(int exception = -1); 

	// Reads the board and adds appropriate Chamber objects to the chamberVec vector 
	// based of the layout
	void createChambers();
public:
	// Constructor requires 1 file with floor layout
	Floor(std::string file, int floorHeight, int floorNum, bool randomSpawn);
	
	void render();                      // Renders Floor for user interface 
	int removeGold(int posX, int posY); // Removes gold pile at a certain Cell and returns its value
	Enemy* getEnemy(int posX, int posY);// Returns pointer to an Enemy at a certain Cell
	char checkCell(int posX, int posY); // Returns the char in the Cell specified by posX and posY 
	void moveEnemies();                 // Makes all enemies on the floor move 1 random cell
	void checkEnemySlayed();

	// Player methods
	int getPlayerX();
	int getPlayerY();
	bool setPlayer(int changeX, int changeY); 
};

#endif
