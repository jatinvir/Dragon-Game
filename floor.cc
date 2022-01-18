#include "floor.h"
#include "concretecreator.h"
//#include "dragonHoard.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>

void Floor::spawnItems() {
	// randomly generate enemies and items and add to floor
	Cell * player = randomCell();
	prevContent = player->content;
	player->content = '@';
	int exception = cellToChamberMap(player);
	cell * staircase = randomCell(exception);
	staircase->content = '\\';

	ConcreteCreator cc{};

	// Creating Potions
	for (int p = 0; p < 10; ++p) {
		Cell * potion = randomCell();
		potion->content = 'P';
		auto potionbox = cc.createPotion();
	       	potionbox->x = potion->x;
	       	potionbox->y = potion->y;
		potions.push_back(std::move(potionbox));
	}

	// Creating Gold
	for (int g = 0; g < 10; ++g){
		Cell * gold = randomCell();
		gold->content = 'G';
		auto goldbox = cc.createGold();
	       	goldbox->x = gold->x;
	       	goldbox->y = gold->y;
		golds.push_back(std::move(goldbox));
	}

	// Creating Enemies
	for (int e = 0; e < 20; ++e) {
		Cell * enemy = randomCell();
		enemy->content = 'E'; // Generic for now but will have to be changed
		auto madeEnemy = cc.createEnemy();
	       	madeEnemy->x = enemy->x;
	       	madeEnemy->y = enemy->y;
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

Cell* Floor::getCell(int x, int y) {
	for (auto it = globalVec.begin(); it != globalVec.end(); ++it) {
		Cell * cell = (*it).get();
		if (cell->x == x && cell->y == y) return cell;
	}
	return nullptr;
}

Cell* Floor::randomCell(int exception) {
	int totalChambers = chamberVec.size();
	if (exception != -1) --totalChambers;
	int randomChamber = std::rand() % totalChambers;
	std::vector<Cell *> availableCells;
	Chamber * ch;

	for (auto it = chamberVec.begin(); it != chamberVec.end(); ++it) {
		if ((*it)->id == exception) continue; 
		if ((*it)->id == randomChamber) ch = (*it).get();
	}
	
	for (auto it = ch->cells.begin(); it != ch->cells.end(); ++it) {
		if ((*it)->content == '.') availableCells.push_back((*it));
	}

	int randomCell = std::rand() % availableCells.size();
	return availableCells.at(randomCell);
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

		if (cellN == '|' || cellS == '|') return;
		if (cellE == '|' || cellW == '|') return;
	}
	chamberCells.push_back(cell);
	accounted.push_back(cell);

	propagateCells(getCell(x,y - 1));
	propagateCells(getCell(x + 1,y - 1));
	propagateCells(getCell(x + 1,y));
	propagateCells(getCell(x + 1,y + 1));
	propagateCells(getCell(x,y + 1));
	propagateCells(getCell(x - 1,y + 1));
	propagateCells(getCell(x - 1,y));
	propagateCells(getCell(x - 1,y - 1));
}

void Floor::createChambers() {
	// reads globalVec and creates Chambers in chamberVec
	int lineNum = 0;
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
			propagateCells((*it).get(), chamber.cells, accounted);

			chamberVec.push_back(std::move(chamber));
		}
	}
}

Floor::Floor(std::string file, const int floorHeight, int floorNum, bool randomSpawn) {
	std::ifstream infile{file};
	std::string xline;
	// Discard irrelevant lines
	for (int i = 0; i < floorHeight * (floorNum - 1); ++i) {
		std::getline(infile, xline);
	}
	// Read in floor
	//ConcreteCreator cc{};
	for (int lineCount = 0; lineCount < floorHeight; ++lineCount) {
		std::getline(infile, xline);
		std::istringstream lineContent{xline};
		int charCount = 0;
		char c;
		
		lineContent >> std::noskipws;
		while ( lineContent >> c ) {
			char symbol = c;
			// Create item if necessary
			if (c >= '0' && c <= '5') {
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
			} else if (c >= '6' && <= '8') {
				symbol = 'G'
				int val;
				if (c == '6') {
					val = 1;
				} else if (c == '7') {
					val == 2;
				} else if (c == '8') {
					val == 4;
				}
				auto goldPile = std::make_unique<Gold>(charCount, lineCount, val);
				gold.push_back(std::move(goldPile));
			} else if (c == '9') {
				//auto goldPile = std::make_unique<DragonHoard>(charCount, lineCount, dragon); // need to know which dragon...
				//gold.push_back(std::move(goldPile));
			} else if (c == 'H' || c == 'W' || c == 'E' || c == 'O' || c == 'M' || c == 'D' || c == 'L') {
				auto enemy = std::make_unique<Enemy>{std::move(cc.createEnemy(cell))}; // this line may be wrong
				enemy->setX(charCount);
				enemy->setY(lineCount);
				enemies.push_back(std::move(enemy));
			}
			auto cell = std::make_unique<Cell>(charCount, lineCount, symbol);
			globalVec.push_back(std::move(cell));
			if (c == '@') {
				player = globalVec.back().get();
				prevContent = '.';
			}
			++charCount;
		}
	}
	createChambers();
	if (randomSpawn) {
		spawnItems();
	}
}

void Floor::render() {
	int line = 0;
	for (auto cell = globalVec.begin(); cell != globalVec.end(); ++cell) {
		if ((*cell)->y != line) {
			std::cout << std::endl;
			++line;
		}
		std::cout << (*cell)->content;
	}
	std::cout << std::endl;
}

char Floor::checkCell(int posX, int posY) {
	int columns = 0; 
	for (auto cell = globalVec.begin(); cell != globalVec.end(); ++cell) {
		if ((*cell)->y == 0) ++columns;
		else break;
	}

	return globalVec[(posY * columns) + posX]->content;
}

int Floor::removeGold(int posX, int posY) {
	return 0; // not yet done
}

Enemy * internalGetEnemy(int posX, int posY) {
	for (auto enemy = enemies.begin(); enemy != enemies.end(); ++enemy) {
		if ((*enemy)->x == posX && (*enemy)->y == posY) return (*enemy);
	}
}

Enemy * Floor::getEnemy(int posX, int posY) {
	return internalGetEnemy(posX, posY);
}

void Floor::moveEnemies() {
	std::vector<Enemy*> tempEnemy;
	for (auto cell = globalVec.begin(); cell != globalVec.end(); ++cell) {
		char type = (*cell)->content;
		if ( type == 'H' || type == 'W' || type == 'E' || type == 'O' || 
			type == 'M' || type == 'D' || type == 'L' ) {
			Enemy *e = internalGetEnemy((*cell)->x, (*cell)->y);
			tempEnemy.push_back(e);
		}
	}

	for (auto enemy = tempEnemy.begin(); enemy != tempEnemy.end(); ++enemy) {
		Cell * cell = getCell((*enemy)->x, (*enemy)->y);
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
				(*enemy)->move(cell->x, cell->y, c->x, c->y);
			} else {
				++count;
			}
		}
	}	
}

void Floor::checkEnemySlayed() {
	for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++) {
		if (enemy->getHp() <= 0) {
			enemies.erase(enemy);
		}
	}
	render();
}

int Floor::getPlayerX() { return player->x; }
int Floor::getPlayerY() { return player->y; }

bool Floor::setPlayer(int changeX, int changeY) {
	int playerX = player->x;
	int playerY = player->y;

	Cell * dest = getCell(playerX + changeX, playerY + changeY);
	char txt = dest->content;
	if (txt == '.' || txt == 'G' || txt == '+' || txt == '#' || txt == '\\') {
		player->content = prevContent;
		prevContent = txt;
		player = dest;
		player->content = '@';
		return true;
	}
	return false;
} 
