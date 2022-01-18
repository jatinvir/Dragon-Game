#ifndef FLOOR_H
#define FLOOR_H

#include "cell.h"
#include "chamber.h"
#include "gold.h"
#include "potionbox.h"

#include "enemy.h"
#include "player.h"

#include <vector>
#include <memory>
#include <string>

class Floor{
public:
	const int lvl;
private:
	std::vector<std::unique_ptr<Cell>> globalVec;
	std::vector<std::unique_ptr<Chamber>> chamberVec;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<Gold>> gold;
	std::vector<std::unique_ptr<PotionBox>> potions;
	
	Cell* player;
	char prevContent;
	
	Cell* getCell(int x, int y); // Gets the pointer of the cell at (x,y)
	void spawnItems();
	
	
	int cellToChamberMap(Cell * cell);
	bool checkAccounted(Cell* cell, std::vector<Cell *> & cellList);
	void propagateCells(Cell *cell, std::vector<Cell *>& chamberCells, std::vector<Cell *>& accounted);
	Cell* randomCell(int exception = -1); 
	void createChambers();
public:
	Floor(std::string file, int floorHeight, int floorNum, bool randomSpawn);
	
	void render(bool colour = false) const;                      // Renders Floor for user interface 
	//int removeGold(int posX, int posY) USELESS NOW
	Enemy* getEnemy(int posX, int posY) const;// Returns pointer to an Enemy at a certain Cell
	char checkCell(int posX, int posY) const; // Returns the char in the Cell specified by posX and posY 
	void moveEnemies();                 // Makes all enemies on the floor move 1 random cell
	void enemyAttacks(Player *pc, std::string &actionMsg, bool merchantHostile = false); // Has all enemies in vicinity of player attack the player
	bool checkEnemySlayed(Player *pc);

	// Potion methods
	bool usePotion(int x, int y, Player *pc, std::string &potion); // If potion at (x,y) uses that potion 
	// Player methods
	int getPlayerX();
	int getPlayerY();
	bool setPlayer(int changeX, int changeY, Player *pc); 
};

#endif
