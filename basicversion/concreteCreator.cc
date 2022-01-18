#include "concreteCreator.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include <cstdlib>

std::unique_ptr<Enemy> ConcreteCreator::createEnemy(char &enemy, int x, int y) {
	int randomNum = rand() % 18;
	
	if (randomNum < 4) { // (2/9) probability of Human
		enemy = 'H';
		return std::make_unique<Human>(x, y);
	} else if (randomNum < 7) { // (3/18) probability of Dwarf
		enemy = 'W';
		return std::make_unique<Dwarf>(x, y);
	} else if (randomNum < 12) { // (5/18) probability of Halfling
		enemy = 'L';
		return std::make_unique<Halfling>(x, y);
	} else if (randomNum < 14) { // (1/9) probability of Elf
		enemy = 'E';
		return std::make_unique<Elf>(x, y);
	} else if (randomNum < 16) { // (1/9) probability of Orc
		enemy = 'O';
		return std::make_unique<Orcs>(x, y);
	} else { // (1/9) probability of Merchant
		enemy = 'M';
		return std::make_unique<Merchant>(x, y);
	}
}

std::unique_ptr<Enemy> ConcreteCreator::createEnemyType(char type, int x, int y) {
	if (type == 'H') {
		return std::make_unique<Human>(x, y);
	} else if (type == 'W') {
		return std::make_unique<Dwarf>(x, y);
	} else if (type == 'E') {
		return std::make_unique<Elf>(x, y);
	} else if (type == 'O') {
		return std::make_unique<Orcs>(x, y);
	} else if (type == 'M') {
		return std::make_unique<Merchant>(x, y);
	} else if (type == 'D') {
		return std::make_unique<Dragon>(x, y);
	} else if (type == 'L') {
		return std::make_unique<Halfling>(x, y);
	} else {
		return std::make_unique<Human>(x, y);
	}
}


std::unique_ptr<PotionBox> ConcreteCreator::createPotion() {
	int random = rand() % 6;
	char c;
	
	if (random == 0) c = '0';
	if (random == 1) c = '1';
	if (random == 2) c = '2';
	if (random == 3) c = '3';
	if (random == 4) c = '4';
	if (random == 5) c = '5';
	
	return createPotion(c);
}

std::unique_ptr<PotionBox> ConcreteCreator::createPotion(char potion) {
	if (potion == '0') return std::make_unique<PotionBox>(0,0,"RH"); // Restore Health Potion
	if (potion == '1') return std::make_unique<PotionBox>(0,0,"BA"); // Boost Attack Potion
	if (potion == '2') return std::make_unique<PotionBox>(0,0,"BD"); // Boost Defence Potion
	if (potion == '3') return std::make_unique<PotionBox>(0,0,"PH"); // Poison Health Potion
	if (potion == '4') return std::make_unique<PotionBox>(0,0,"WA"); // Wound Attack Potion
	if (potion == '5') return std::make_unique<PotionBox>(0,0,"WD"); // Wound Defence Potion
	
	return std::make_unique<PotionBox>(0,0,"RH"); // Default - Restore Health Potion
}
	
std::unique_ptr<Gold> ConcreteCreator::createGold() {
	int randomNum = rand() % 8;

	if (randomNum < 5) return createGold(6); // (5/8) probability of normal pile
	if (randomNum < 6) return createGold(9); // (1/8) probability of dragon hoard
	
	return createGold(7); // (1/4) probability of small pile 
}

std::unique_ptr<Gold> ConcreteCreator::createGold(int goldAmount) {
	if (goldAmount == 6) return std::make_unique<Gold>(0,0,2); // normal pile
	if (goldAmount == 7) return std::make_unique<Gold>(0,0,1); // small pile 
	if (goldAmount == 8) return std::make_unique<Gold>(0,0,4); // merchant hoard
	if (goldAmount == 9) {
		//return std::make_unique<Gold>(0,0,6); // (1/8) probability of dragon hoard
		return std::make_unique<Gold>(0,0,6); // temp
	}
	return std::make_unique<Gold>(0,0,2); // Default - normal pile
}
