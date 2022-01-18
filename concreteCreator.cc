#include "concreteCreator.h"
#include <cstdlib>

std::unique_ptr<Enemy> createEnemy() {
	int randomNum = rand() % 18;
	
	if (randomNum < 4) { // (2/9) probability of Human
		return make_unique<Human>(0,0);
	} else if (randomNum < 7) { // (3/18) probability of Dwarf
		//return make_unique<Dwarf>(0,0);
		return make_unique<Human>(0,0);// temp
	} else if (randomNum < 12) { // (5/18) probability of Halfling
		//return make_unique<Halfling>(0,0);
		return make_unique<Human>(0,0);// temp
	} else if (randomNum < 14) { // (1/9) probability of Elf
		//return make_unique<Elf>(0,0);
		return make_unique<Human>(0,0);// temp
	} else if (randomNum < 16) { // (1/9) probability of Orc
		//return make_unique<Orc>(0,0);
		return make_unique<Human>(0,0);// temp
	} else { // (1/9) probability of Merchant
		//return make_unique<Merchant>(0,0);
		return make_unique<Human>(0,0);// temp
	}
}

std::unique_ptr<Enemy> createEnemy(char type) {
	if (type == 'H') {
		auto enemy = std::make_unique<Human>(0, 0);
	} else if (type == 'W') {
		auto enemy = std::make_unique<Dwarf>(0, 0);
	} else if (type == 'E') {
		auto enemy = std::make_unique<Elf>(0, 0);
	} else if (type == 'O') {
		auto enemy = std::make_unique<Orc>(0, 0);
	} else if (type == 'M') {
		auto enemy = std::make_unique<Merchant>(0, 0);
	} else if (type == 'D') {
		auto enemy = std::make_unique<Dragon>(0, 0);
	} else if (type == 'H') {
		auto enemy = std::make_unique<Halfling>(0, 0);
	}
	return enemy;
}


std::unique_ptr<PotionBox> createPotion() {
	int randomNum = rand() % 6;

	if (randomNum < 1) {
		return make_unique<PotionBox>(0,0,"RH");
	} else if (randomNum < 2) {
		return make_unique<PotionBox>(0,0,"PH");
	} else if (randomNum < 3) {
		return make_unique<PotionBox>(0,0,"BA");
	} else if (randomNum < 4) {
		return make_unique<PotionBox>(0,0,"WA");
	} else if (randomNum < 5) {
		return make_unique<PotionBox>(0,0,"BD");
	} else {
		return make_unique<PotionBox>(0,0,"WD");
	}	
}


std::unique_ptr<Gold> createGold() {
	int randomNum = rand() % 8;
	
	if (randomNum < 5) {
		return make_unique<Gold>(0,0,2) // (5/8) probability of normal pile
	} else if (randomNum < 6) {
		//std::unique_ptr<Dragon> d = std::make_unique<Dragon>();
		//return make_unique<Gold>(0,0,6,std::move(d)) // (1/8) probability of dragon hoard
		return make_unique<Gold>(0,0,2) // temp
	} else {
		return make_unique<Gold>(0,0,1) // (1/4) probability of small pile 
	}
}

//void createPotion()
//void createLocation()
