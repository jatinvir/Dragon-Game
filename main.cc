#include <iostream>
#include <string>
#include "floor.h"
#include "enemy.h"
#include "player.h"

const std::string DEFAULT_FILE = "default.txt"; // default floor layout
const int FLOOR_HEIGHT = 25;                    // number of rows in each floor

// Renders game interface
void renderGame(const Floor *floor, const Player *pc, int gold, std::string action) {
	floor->render();
	std::cout << "Race: Gold: " << std::endl;
	std::cout << "HP: " << pc->getHp() << std::endl;
	std::cout << "Atk: " << pc->getAtk() << std::endl;
	std::cout << "Def: " << pc->getDef() << std::endl;
	std::cout << "Action: " << action << std::endl;
}

// Modifies x and y to represent the position in the direction indicated by cmd
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

int main(int argc, char *argv[]) {
	std::string file = DEFAULT_FILE;
	bool randomSpawn = true;
	if (argc > 1) {
		file = argv[1];
		randomSpawn = false;
	}
	auto floor = std::make_unique<Floor>(file, FLOOR_HEIGHT, 1, randomSpawn);
    
    auto pc = std::make_unique<Shade>();
    int playerGold = 0;

    // Game loop
    std::string actionMsg = "Player character has spawned.";
	renderGame(floor.get(), pc.get(), playerGold, actionMsg);

    bool quit = false;
    bool enemyMovement = true;
    std::string command;
    while (!quit) {
        // Command
        actionMsg = "";
        std::cin >> command;
        if (command == "q") {
            std::cout << "You have surrendered to the forces of Good.\n---Game Over---" << std::endl;
            quit = true;
            continue;
        } else if (command == "r") {
            std::cout << "Game restarted." << std::endl;
            quit = true;
            continue;
        } else if (command == "f") {
            enemyMovement = !enemyMovement;
            std::cout << "Enemy movement " << enemyMovement ? "on." : "off." << std::endl;
            continue;
        } else if (command == "u") {
            int targetX, targetY;
            std::cin >> command;
            try {
                applyDirection(targetX, targetY, command);
            } catch (...) {
                std::cout << "Invalid command." << std::endl;
                continue;  // allow user to reenter a command
            }
            if (floor.checkCell(targetX, targetY) == 'P') {
                //// use the potion
                //generate a random potion
                //if health potion then apply immediately
                //else add to pc's stats list
                std::string type = floor.getPotionType(targetX, targetY); /////
                if (type == "RH") {
                    pc.modifyHealth(5);
                } else if (type == "PH") {
                    pc.modifyHealth(-5);
                } else if (type = "BA") {
                    auto potion = std::make_unique<BoostAtk>();
                    pc.applyPotion(std::move(potion));
                } else if (type == "WA") {
                    auto potion = std::make_unique<WoundAtk>();
                    pc.applyPotion(std::move(potion));
                } else if (type == "BD") {
                    auto potion = std::make_unique<BoostDef>();
                    pc.applyPotion(std::move(potion));
                } else if (type == "WD") {
                    auto potion = std::make_unique<WoundDef>();
                    pc.applyPotion(std::move(potion));
                }
                actionMsg += "PC uses " + type;
            } else {
                std::cout << "There is no potion in that direction." << std::endl;
                continue;
            }
        } else if (command == "a") { 
            int targetX, targetY;
            std::cin >> command;
            try {
                applyDirection(targetX, targetY, command);
            } catch (...) {
                std::cout << "Invalid command." << std::endl;
                continue;
            }
            char targetChar = floor.checkCell(targetX, targetY);
            if (targetChar == 'H' || targetChar == 'W' || targetChar == 'E' || targetChar == 'O' || 
                targetChar == 'M' || targetChar == 'D' || targetChar == 'L') {
                //// attack the enemy
                //get e to point at the enemy
                //e.beStruckBy(pc);
            } else {
                std::cout << "There is no potion in that direction." << std::endl;
                continue;
            }
        } else {
            int moveX = 0;
            int moveY = 0;
            try {
                actionMsg += "PC moves " + applyDirection(moveX, moveY, command);
            } catch (...) {
                std::cout << "Invalid command." << std::endl;
                continue;
            }
            if ( !floor->setPlayer(moveX, moveY) ) {
                std::cout << "Cannot move in that direction." << std::endl;
                continue;
            }
        }
        // Events

        // If player reached staircase...
        if (floor.checkCell(pc->getX(), pc->getY()) == '\\') {
            //// sth sth (prob nest this while inside a for 1..5)
            break;
        }

        // Update board
        if (enemyMovement) {
            floor.moveEnemies();
        }
	    renderGame(floor.get(), pc.get(), playerGold, actionMsg);

        // Pickup gold
        if (floor.checkCell(pc->getX(), pc->getY()) == 'G') {
            playerGold += floor.removeGold(pc->getX(), pc->getY());
        }
        // Enemy attacks
        char cell;
        for (int r = -1; r <= 1; ++r) {
            for (int c = -1; c <= 1; ++c) {
                cell = floor.checkCell(pc->getX() + c, pc->getY() + r);
                if (cell == 'H' || cell == 'W' || cell == 'E' || cell == 'O' || cell == 'M' || cell == 'D' || cell == 'L') {
                    Enemy *e = floor.getEnemy(pc->getX() + c, pc->getY() + r);
                    pc.beStruckBy(e);
                    //// btw have the strike functions print a message like "A Halfling sees you and attacks.\nYou get hit and lose 5 HP." or "A Halfling sees you and attacks.\nIt misses."
                }
            }
        }
    }
}
