#include "floor.h"
#include "human.h"
#include "dragon.h"
#include "randomMove.h"
#include "concreteCreator.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "potionBA.h"
#include "potionWA.h"
#include "potionBD.h"
#include "potionWD.h"
class Potion;

// CHANGE THESE CONSTANTS IF NECESSARY
const int TOTAL_ENEMY = 20; // Total number of enemies generated per floor (Not including Dragon)
const int TOTAL_POTION = 10; // Total number of potions generated per floor
const int TOTAL_GOLD = 10; // Total number of gold generated per floor


Cell* Floor::getCell(int x, int y) {
	for (auto it = globalVec.begin(); it != globalVec.end(); ++it) {
		Cell * cell = (*it).get();
		if (cell->x == x && cell->y == y) return cell;
	}
	return nullptr;
}

void Floor::spawnItems() {
	// randomly generate enemies and items and add to floor
	Cell* pc = randomCell();
	player = pc;
	prevContent = pc->content;
	pc->content = '@';
	int exception = cellToChamberMap(pc);
	//std::cout << "Chamber#" << exception << std::endl; // TEMP
	Cell* staircase = randomCell(exception);
	//std::cout << "Chamber#" << cellToChamberMap(staircase) << std::endl; //TEMP
	staircase->content = '\\';
        
	ConcreteCreator cc;

	// Creating Potions
	for (int p = 0; p < TOTAL_POTION; ++p) {
		Cell * potion = randomCell();
		potion->content = 'P';
		auto potionbox = cc.createPotion();
	       	potionbox->x = potion->x;
	       	potionbox->y = potion->y;
		potions.push_back(std::move(potionbox));
	}

	// Creating Gold
	for (int g = 0; g < TOTAL_GOLD; ++g){
		Cell * goldC = randomCell();
		goldC->content = 'G';
		auto goldbox = cc.createGold();
	       	goldbox->x = goldC->x;
	       	goldbox->y = goldC->y;
		gold.push_back(std::move(goldbox));
	}

	// Creating Enemies
	for (int e = 0; e < TOTAL_ENEMY; ++e) {
		Cell * enemy = randomCell();
		auto madeEnemy = cc.createEnemy(enemy->content, enemy->x, enemy->y);
		enemies.push_back(std::move(madeEnemy));
	}
}


int Floor::cellToChamberMap(Cell * cell) {
	for (auto it = chamberVec.begin(); it != chamberVec.end(); ++it) {
		Chamber * ch = (*it).get();
		for (auto cl = ch->cells.begin(); cl != ch->cells.end(); ++cl) {
			int x = (*cl)->x;
			int y = (*cl)->y;
			if (cell->x == x && cell->y == y) return ch->id;
		}
	}
	return -1;
}
bool Floor::checkAccounted(Cell* cell, std::vector<Cell *> & cellList) {
	for (auto it = cellList.begin(); it != cellList.end(); ++it) {
		if ((*it) == cell) return true;
	}
	return false;
}
void Floor::propagateCells(Cell *cell, std::vector<Cell *>& chamberCells, std::vector<Cell *>& accounted) {
	if (checkAccounted(cell, accounted)) return;
	char txt = cell->content;
	if (txt == ' '|| txt == '|'|| txt == '-'|| txt == '+'|| txt == '#') return;
	
	int x = cell->x;
	int y = cell->y;
	if (txt == '@') {
		char cellN = checkCell(x, y - 1);
		char cellE = checkCell(x + 1, y);
		char cellS = checkCell(x, y + 1);
		char cellW = checkCell(x - 1, y);

		if (cellN == '#' || cellE == '#' || cellS == '#' || cellW == '#') return;
	}
	chamberCells.push_back(cell);
	accounted.push_back(cell);

	propagateCells(getCell(x,y - 1), chamberCells, accounted);
	propagateCells(getCell(x + 1,y - 1), chamberCells, accounted);
	propagateCells(getCell(x + 1,y), chamberCells, accounted);
	propagateCells(getCell(x + 1,y + 1), chamberCells, accounted);
	propagateCells(getCell(x,y + 1), chamberCells, accounted);
	propagateCells(getCell(x - 1,y + 1), chamberCells, accounted);
	propagateCells(getCell(x - 1,y), chamberCells, accounted);
	propagateCells(getCell(x - 1,y - 1), chamberCells, accounted);
}

Cell* Floor::randomCell(int exception) {
	int totalChambers = chamberVec.size();
	if (exception != -1) --totalChambers;

	int randomCell = 0;
	int randomChamber = 0;
	while (true) {
		randomChamber = rand() % totalChambers + 1;
		std::vector<Cell *> availableCells;
		Chamber * ch = nullptr;
		for (auto it = chamberVec.begin(); it != chamberVec.end(); ++it) {
			if ((*it)->id == exception) continue; 
			if ((*it)->id == randomChamber) ch = (*it).get();
		}
		if (ch == nullptr) continue;
		
		for (auto it = ch->cells.begin(); it != ch->cells.end(); ++it) {
			if ((*it)->content == '.') availableCells.push_back(*it);
		}
		if (availableCells.size() == 0) continue;
		
		randomCell = rand() % availableCells.size();
		return availableCells[randomCell];
	}
} 

void Floor::createChambers() {
	// reads globalVec and creates Chambers in chamberVec
	std::vector<Cell *> accounted;
	for (auto it = globalVec.begin(); it != globalVec.end(); ++it) {
		char txt = (*it)->content;
		if (txt == ' '|| txt == '|'|| txt == '-'|| txt == '+'|| txt == '#') continue;
		if (txt == '@') {
			int x = (*it)->x;
			int y = (*it)->y;
			char cellN = checkCell(x, y - 1);
			char cellE = checkCell(x + 1, y);
			char cellS = checkCell(x, y + 1);
			char cellW = checkCell(x - 1, y);
			if (cellN == '#' || cellE == '#' || cellS == '#' || cellW == '#') continue;
		}
		if(!checkAccounted((*it).get(), accounted)) {
			int size = chamberVec.size() + 1;
			auto chamber = std::make_unique<Chamber>(size);
			
			// code for cell propagate mechanism	
			propagateCells((*it).get(), chamber->cells, accounted);

			chamberVec.push_back(std::move(chamber));
		}
	}
}

Floor::Floor(const std::string file, const int floorHeight, const int floorNum, bool randomSpawn) : lvl{floorNum} {
	std::ifstream infile{file};
	std::string xline;
	
	// Discard irrelevant lines
	for (int i = 0; i < floorHeight * (floorNum - 1); ++i) std::getline(infile, xline);

	// Set prevContent
	prevContent = '.'; 

	// Read in floor
	for (int lineCount = 0; lineCount < floorHeight; ++lineCount) {
		std::getline(infile, xline);
		std::istringstream lineContent{xline};
		int charCount = 0;
		char c;
		ConcreteCreator cc;
		
		lineContent >> std::noskipws;
		while ( lineContent >> c ) {
			//if (c == 'D') continue;
			char symbol = c;
			// Create item if necessary
			if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'L') {
				//auto enemy = std::make_unique<Human>(charCount, lineCount);
				std::unique_ptr<Enemy> enemy = cc.createEnemyType(c, charCount, lineCount);
				enemies.push_back(std::move(enemy));
			} else if (c >= '6' && c <= '8') {
				symbol = 'G';
				
				int val;
				if (c == '6') val = 1;
				if (c == '7') val = 2;
				if (c == '8') val = 4;
				
				auto goldPile = std::make_unique<Gold>(charCount, lineCount, val);
				gold.push_back(std::move(goldPile));
			} else if (c == '9') {
				symbol = 'G';
			} else if (c == 'D') {
				++charCount;
				continue;
			} else if (c >= '0' && c <= '5') {
				symbol = 'P';
				std::string potion;
				if (c == '0') {
					potion = "RH";
				} else if (c == '1') {
					potion = "BA";
				} else if (c == '2') {
					potion = "BD";
				} else if (c == '3') {
					potion = "PH";
				} else if (c == '4') {
					potion = "WA";
				} else if (c == '5') {
					potion = "WD";
				}

				auto potionMade = std::make_unique<PotionBox>(charCount, lineCount, potion);
				potions.push_back(std::move(potionMade));
			}
			// TEMP UNTIL ALL ENEMY CLASSES ADDED
			//if (c== 'E' || c== 'O' || c== 'M' || c== 'L') symbol = '.';

			auto cell = std::make_unique<Cell>(charCount, lineCount, symbol);
			if (c == '@') player = cell.get();
			globalVec.push_back(std::move(cell));
			
			if (c == '9') {
				// Making accompanying dragon for DragonHoard
				auto dragon = std::make_unique<Dragon>(charCount + 1, lineCount);
				auto drCell = std::make_unique<Cell>(charCount + 1, lineCount, 'D');
				globalVec.push_back(std::move(drCell));

				// Making DragonHoard
				auto goldPile = std::make_unique<Gold>(charCount, lineCount, dragon.get());
				dragon->setGoldPtr(goldPile.get());
				enemies.push_back(std::move(dragon));
				gold.push_back(std::move(goldPile));
			}
			++charCount;
		}
	}
	createChambers();
	if (randomSpawn) spawnItems();
}

// Requires globalVec to be in order from top to bottom and left to right
void Floor::render(bool colour) const {
	int line = 0;
	for (auto cell = globalVec.begin(); cell != globalVec.end(); ++cell) {
		char txt = (*cell)->content;
		if ((*cell)->y != line) {
			std::cout << std::endl;
			++line;
		}
		
		if (colour) {
			if (txt == '@') std::cout << "\033[34;1m";
			if (txt == 'G') std::cout << "\033[33m";
			if (txt == 'P') std::cout << "\033[32m";
			if (txt == 'H' || txt == 'W' || txt == 'E' || txt == 'O' || 
				txt == 'M' || txt == 'D' || txt == 'L') std::cout << "\033[31m";
		}

		std::cout << (*cell)->content;
	       	if (colour) std::cout << "\033[0m";
	}
	std::cout << std::endl;
}

char Floor::checkCell(int posX, int posY) const {
	int columns = 0; 
	for (auto cell = globalVec.begin(); cell != globalVec.end(); ++cell) {
		if ((*cell)->y == 0) ++columns;
		else break;
	}

	return globalVec[(posY * columns) + posX]->content;
}

Enemy * Floor::getEnemy(int posX, int posY) const {
	for (auto enemy = enemies.begin(); enemy != enemies.end(); ++enemy) {
		if ((*enemy)->getX() == posX && (*enemy)->getY() == posY) return (*enemy).get();
	}
	return nullptr;
}

void Floor::moveEnemies() {
	std::vector<Enemy*> tempEnemy;
	for (auto cell = globalVec.begin(); cell != globalVec.end(); ++cell) {
		char type = (*cell)->content;
		if ( type == 'H' || type == 'W' || type == 'E' || type == 'O' || 
			type == 'M' || type == 'D' || type == 'L' ) { // NEED UPDATE
			// Do not move enemies that are next to the player
			if (((*cell)->x >= player->x - 1 && (*cell)->x <= player->x + 1) &&
				((*cell)->y >= player->y - 1 && (*cell)->y <= player->y + 1)) {
				continue;
			}
			Enemy *e = getEnemy((*cell)->x, (*cell)->y);
			tempEnemy.push_back(e);
		}
	}

	for (auto enemy = tempEnemy.begin(); enemy != tempEnemy.end(); ++enemy) {
		Cell * cell = getCell((*enemy)->getX(), (*enemy)->getY());
		int x = cell->x;
		int y = cell->y;
		int count = 0;

		while (count < 8) {
			int rand = std::rand() % 8;
			
			int xChange = 0;
			int yChange = 0;
			if (rand < 2 || rand == 7) --yChange;
			if (rand < 6 && rand > 2) ++yChange;
			if (rand < 8 && rand > 4) --xChange;
			if (rand < 4 && rand > 0) ++xChange;

			Cell* c = getCell(x + xChange, y + yChange);
			if (c->content == '.') {
				RandomMove *movement = (*enemy)->getMovement();
				movement->move(cell, c, (*enemy));
				break;
			} else {
				++count;
			}
		}
	}	
}

void Floor::enemyAttacks(Player *pc, std::string &actionMsg, bool merchantHostile) {
	char cell;
	int damage;
	bool dragonAttacked = false; // prevent dragon from attacking twice
	for (int r = -1; r <= 1; ++r) {
		for (int c = -1; c <= 1; ++c) {
			cell = checkCell(player->x + c, player->y + r);
			if ((cell == 'H' || cell == 'W' || cell == 'E' || cell == 'O' || cell == 'L') ||
				(cell == 'D' && !dragonAttacked) || (cell == 'M' && merchantHostile)) {
				if (cell == 'D') dragonAttacked = true;
				Enemy *e = getEnemy(player->x + c, player->y + r);
				damage = pc->beStruckBy(*e);
				if (damage) {
					actionMsg += " Enemy attacks and deals " + std::to_string(damage) + " HP of damage.";
				} else {
					actionMsg += " Enemy attacks and misses.";
				}
			} else if (cell == 'G' || !dragonAttacked) {
				for (auto it = gold.begin(); it != gold.end(); ++it) {
					if (player->x + c != (*it)->x || player->y + r != (*it)->y) continue;
					if ((*it)->d) {
						// Dragon attack
						dragonAttacked = true;
						damage = pc->beStruckBy(*((*it)->d));
						if (damage) {
							actionMsg += " Enemy attacks and deals " + std::to_string(damage) + " HP of damage.";
						} else {
							actionMsg += " Enemy attacks and misses.";
						}
					} else {
						break;
					}
				}
			}
		}
	}
}

// NEEDS UPDATE
bool Floor::usePotion(int x, int y, Player *pc, std::string &potion) {
	int destX = player->x + x;
	int destY = player->y + y;
	for (auto it = potions.begin(); it != potions.end(); ++it) {
		if ((*it)->x != destX || (*it)->y != destY) continue;
		
		potion = (*it)->potionType;
		potions.erase(it);

		if (potion == "RH") {
			pc->useHealthPotion(5);
		} else if (potion == "PH") {
			pc->useHealthPotion(-5);
		} else {
			std::unique_ptr<Potion> potionObject;
			if (potion == "BA") {
				potionObject = std::make_unique<BoostAtk>();
			} else if (potion == "WA") {
				potionObject = std::make_unique<WoundAtk>();
			} else if (potion == "BD") {
				potionObject = std::make_unique<BoostDef>();
			} else if (potion == "WD") {
				potionObject = std::make_unique<WoundDef>();
			}
			pc->usePotion(std::move(potionObject));
		}
		Cell *potionCell = getCell(destX, destY);
		potionCell->content = '.';
		return setPlayer(x, y, pc);
	}
	return false;
}

// Assumes there will only be a max of one enemy slayed
bool Floor::checkEnemySlayed(Player *pc) {
	for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++) {
		if ((*enemy)->getHp() <= 0) {
			// Drop gold and remove enemy
			Cell *enemyCell = getCell((*enemy)->getX(), (*enemy)->getY());
			if ((*enemy)->getDropsPile()) {
				auto goldDrop = std::make_unique<Gold>((*enemy)->getX(), (*enemy)->getY(), (*enemy)->dropGold());
				gold.push_back(std::move(goldDrop));
				enemyCell->content = 'G';
			} else {
				pc->addGold((*enemy)->dropGold());
				enemyCell->content = '.';
			}
			pc->killBonus(); // NEED BETTER WAY OF DOING THIS 
			enemies.erase(enemy);
			return true;
		}
	}
	return false;
}

int Floor::getPlayerX() { return player->x; }
int Floor::getPlayerY() { return player->y; }

bool Floor::setPlayer(int changeX, int changeY, Player * pc) {
	int playerX = player->x;
	int playerY = player->y;

	Cell * dest = getCell(playerX + changeX, playerY + changeY);
	char txt = dest->content;
	
	if (txt == '.' || txt == '+' || txt == '#' || txt == '\\') {
		player->content = prevContent;
		prevContent = txt;
		player = dest;
		player->content = '@';
		//pc->moved();
		return true;
	} else if (txt == 'G') { // IF PLAYER STEPS ON GOLD
		int destX = dest->x;
		int destY = dest->y;
		for (auto it = gold.begin(); it != gold.end(); ++it) {
			if (destX != (*it)->x || destY != (*it)->y) continue;

			player->content = prevContent;
			if ((*it)->val != 6 || (*it)->d == nullptr) {
				pc->addGold((*it)->val);
				gold.erase(it);
				prevContent = '.';
			} else {
				prevContent = txt;
			}
			player = dest;
			player->content = '@';
			//pc->moved();
			return true;
		}	
	}
	return false;
}
