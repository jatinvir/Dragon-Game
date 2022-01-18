#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cstdlib>
#include "floor.h"
#include "enemy.h"
#include "player.h"

#include "shade.h" 
#include "drow.h"  
#include "vampire.h"
#include "troll.h"  
#include "goblin.h" 

// Constants and Defaults
const std::string DEFAULT_FILE = "default.txt";      // default floor layout
const std::string DEFAULT_RACE = "Shade (default)";  // default Player Race
const int FLOOR_HEIGHT = 25;                         // number of rows in each floor
const int NUMBER_LEVELS = 5;                         // number of default levels

// Renders game interface
void renderGame(const Floor *floor, const Player *pc, bool colour, std::string action, std::string race) {
	floor->render(colour);
	std::cout << "Race: " << race << " ";
	
	if (colour) std::cout << "\033[33m";
	std::cout << "Gold: " << pc->getGold();
	if (colour) std::cout << "\033[0m";
	
	for (int i = 0; i < 45; ++i) std::cout << " ";
	
	std::cout << "Level: " << floor->lvl << std::endl;
	std::cout << "HP: " << pc->getHp() << std::endl;
	std::cout << "Atk: " << pc->getAtk() << std::endl;
	std::cout << "Def: " << pc->getDef() << std::endl;
	std::cout << "Action: " << action << std::endl;
}

// Render Game Over Message
void gameOver(bool colour) {
	if (colour) std::cout << "\033[31m";
	std::cout << "---Game Over---";
	if (colour) std::cout << "\033[0m";
	std::cout << std::endl;
}

// Render Welcome Message
void welcome(bool colour) {
	std::ifstream file{"welcome.txt"};
	std::string line;

	for (int i = 0; i < 16; ++i) {
		std::getline(file, line);
		std::cout << line << std::endl;
	}
	
	if (colour) std::cout << "\033[31m";
	for (int i = 16; i < 23; ++i) {
		std::getline(file, line);
		std::cout << line << std::endl;
	}
	
	if (colour) std::cout << "\033[0m";
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
}

// Determines if parameter is a valid direction
bool isDirectionCommand(std::string cmd) {
	return (cmd == "ea" || cmd == "se" || cmd == "so" || cmd == "sw" || 
	    cmd == "we" || cmd == "nw" || cmd == "no" || cmd == "ne");
}

// Modifies x and y to represent the position in the direction indicated by cmd; returns name of direction
std::string applyDirection(int &x, int &y, std::string cmd) {
	if (cmd == "no") {
		--y;
		return "North";
	} else if (cmd == "so") {
		++y;
		return "South";
	} else if (cmd == "ea") {
		++x;
		return "East";
	} else if (cmd == "we") {
		--x;
		return "West";
	} else if (cmd == "ne") {
		--y;
		++x;
		return "Northeast";
	} else if (cmd == "nw") {
		--y;
		--x;
		return "Northwest";
	} else if (cmd == "se") {
		++y;
		++x;
		return "Southeast";
	} else if (cmd == "sw") {
		++y;
		--x;
		return "Southwest";
	} else {
		throw;
	}
}

// Choosing a Player Character
std::unique_ptr<Player> choosePlayer(std::string &race, bool &quit) {
	std::cout << "Please type one of the letters and press Enter to start (q to quit):" << std::endl;
	std::cout << "s -  Shade  (125 HP, 25 ATK, 25 DEF)" << std::endl;
	std::cout << "d -  Drow   (150 HP, 25 ATK, 15 DEF)" << std::endl;
	std::cout << "v - Vampire (50  HP, 25 ATK, 25 DEF)" << std::endl;
	std::cout << "t -  Troll  (120 HP, 25 ATK, 15 DEF)" << std::endl;
	std::cout << "g -  Goblin (110 HP, 15 ATK, 20 DEF)" << std::endl;
	
	char p;
	while (true) {
		if (!(std::cin >> p)) {
			std::cout << "EOF reached" << std::endl;
			quit = true;
			return std::make_unique<Shade>();
		}
		if (p == 's') {
			race = "Shade";
			return std::make_unique<Shade>();
		} else if (p == 'd') {
			race = "Drow";
			return std::make_unique<Drow>();
		} else if (p == 'v') {
			race = "Vampire";
			return std::make_unique<Vampire>();
		} else if (p == 't') {
			race = "Troll";
			return std::make_unique<Troll>();
		} else if (p == 'g') {
			race = "Goblin";
			return std::make_unique<Goblin>();
		} else if (p == 'q') {
			quit = true;
			return std::make_unique<Shade>();
		} else {
			std::cout << "Please Choose one from the above (s,d,v,t,g)" << std::endl;	
		}
	}
}

int main(int argc, char *argv[]) {
    auto x = time(0);
    srand(x);
    std::string file = DEFAULT_FILE;
    std::string race = DEFAULT_RACE;
    int totalLevels = NUMBER_LEVELS;
    bool merchantHostile = false;
    bool randomSpawn = true;
    bool colourized = false;
    bool welcomeMessage = true;
    bool printSeed = false;
    
    if (argc > 1) {
    	for (int i = 1; i < argc; ++i) {
		if(argv[i][0] != '-') {
			file = argv[i];
			randomSpawn = false;
		}
		if(argv[i][1] == '-') {
			std::string s{argv[i]};
			auto breakPoint = s.find("=");
			std::string lval;
			std::string rval;

			if (breakPoint == std::string::npos) {
				rval = "true";
				lval = s.substr(2);
			} else {
				lval = s.substr(2, breakPoint - 2);
				rval = s.substr(breakPoint + 1);
				
				if (lval == "board") file = rval; 
			}
			
			if (rval == "true") {
				if (lval == "colour") colourized = true;
				if (lval == "print-seed")  printSeed = true;
			}
		} else {
			if(argv[i][1] == 'C') colourized = true;
			if(argv[i][1] == 'W') welcomeMessage = false;
			if(argv[i][1] == 'S') {
				std::string seed{argv[i]};
				x = std::stoi(seed.substr(3));
				srand(x);
			}	
			if(argv[i][1] == 'L') {
				std::string seed{argv[i]};
				int num = std::stoi(seed.substr(3));
				totalLevels = num;
			}	
		}
	}
    }
    if (printSeed) std::cout << "Seed: " << x <<std::endl;
    if (welcomeMessage) welcome(colourized);

    while (true) {
		bool restart = false;
		bool endgame = false;
		bool enemyMovement = true;
		std::unique_ptr<Player> pc = choosePlayer(race, endgame);
		if (endgame) {
			std::cout << "You have surrendered to the forces of Good." << std::endl;
			gameOver(colourized);
			return 0;
		}

		for (int i = 0; i < totalLevels; ++i) {
			int level = i + 1;
			auto floor = std::make_unique<Floor>(file, FLOOR_HEIGHT, level, randomSpawn);
			
			std::string actionMsg = "You arrive at the dungeon.";
			if (level != 1) actionMsg = "Level " + std::to_string(level);
			if (colourized) actionMsg = "\033[34;1m" + actionMsg + "\033[0m";
			renderGame(floor.get(), pc.get(), colourized, actionMsg, race);
			bool quit = false;
			std::string command;
			
			while (!quit) {
				actionMsg = "";
				if (!(std::cin >> command)) {
					std::cout << "EOF reached" << std::endl;
    					std::cout << "Score: " << pc->calcScore() << std::endl;
					gameOver(colourized);
					return 0;
				}
				// Handle command
				if (isDirectionCommand(command)) {
					int moveX = 0;
					int moveY = 0;
					try {
						actionMsg += "PC moves " + applyDirection(moveX, moveY, command) + ".";
					} catch (...) {
						std::cout << "Invalid command." << std::endl;
						continue;
					}
					
					int destX = floor->getPlayerX() + moveX;
					int destY = floor->getPlayerY() + moveY;
					if (floor->checkCell(destX, destY) == '\\') break;
					if ( !floor->setPlayer(moveX, moveY, pc.get()) ) {
						std::cout << "Cannot move in that direction." << std::endl;
						continue; 
					}
					pc->turn();
				} else if (command == "u") {
					std::cin >> command;
					int moveX = 0;
					int moveY = 0;
					std::string potionType;
					try {
						potionType = applyDirection(moveX, moveY, command);
					} catch (...) {
						std::cout << "Invalid command." << std::endl;
						continue;
					}
					if (floor->usePotion(moveX, moveY, pc.get(), potionType)) {
						actionMsg += "PC uses " + potionType + ".";
						pc->turn();
					} else {
						std::cout << "No Potion in that direction." << std::endl;
						continue;
					}
				} else if (command == "a") {
					std::cin >> command;
					int targetX = floor->getPlayerX();
					int targetY = floor->getPlayerY();
					try {
						applyDirection(targetX, targetY, command);
					} catch (...) {
						std::cout << "Invalid command." << std::endl;
						continue;
					}
					char targetChar = floor->checkCell(targetX, targetY);
					
					if (targetChar == 'M' && merchantHostile == false) {
						merchantHostile = true;
					}

					if (targetChar == 'H' || targetChar == 'W' || targetChar == 'E' || targetChar == 'O' || 
						targetChar == 'M' || targetChar == 'D' || targetChar == 'L') {
						Enemy *e = floor->getEnemy(targetX, targetY);
						int damage = e->beStruckBy(*pc);
						pc->turn();
						if (damage) {
							actionMsg += "PC attacks enemy and deals " + std::to_string(damage) + " HP of damage ";
						} else {
							actionMsg += "PC attacks enemy and misses ";
						}
						actionMsg += "(" + std::to_string(e->getHp()) + " HP remaining).";
						
					} else {
						std::cout << "There is no enemy in that direction." << std::endl;
						continue;
					}
				} else if (command == "f") {
					enemyMovement = !enemyMovement;
					std::cout << "Enemy movement ";
					std::cout << (enemyMovement ? "on." : "off.") << std::endl;
					continue;
				} else if (command == "r") {
					// Print stats
					std::cout << std::endl <<"---Game Restart---"<< std::endl << std::endl;
					restart = true;
					break;
				} else if (command == "q") { 
					std::cout << std::endl;
					std::cout << "You have surrendered to the forces of Good.";
				        std::cout << std::endl;

					gameOver(colourized);
					return 0;
				} else {
					continue;
				}
				// Events
				if (floor->checkEnemySlayed(pc.get())) {
					actionMsg += " Enemy is defeated.";
				}
				floor->enemyAttacks(pc.get(), actionMsg, merchantHostile);
				if (enemyMovement) floor->moveEnemies();
				renderGame(floor.get(), pc.get(), colourized, actionMsg, race);
				
				if (pc->getHp() <= 0) {
					std::cout << std::endl << "You have been defeated." << std::endl;
					std::cout << "Score: " << pc->calcScore() << std::endl;
					gameOver(colourized);
					return 0;
				}
			}
			if (restart) break;
			//pc->resetPotions(); // TEMP
    	}
	if (restart) continue;	
	std::cout << "---Congratz! You Finished the Game!---" << std::endl;
    	std::cout << "Score: " << pc->calcScore() << std::endl;
    
	std::cout << "Play Again? (y/n): ";
	char ans;
	std::cin >> ans;
	if (ans != 'y' && ans != 'Y') return 0;
    }
} 
