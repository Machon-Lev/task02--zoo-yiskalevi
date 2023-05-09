#include "Animal.h"

Animal::Animal(const std::string& name, Location& loc){
	name_animal = name;
	location_animal = loc;
	temp_move = true;


	int random_num = rand(); // generate random integer
	int normalized_num = (random_num % 2 == 0) ? 1 : -1; // normalize to 1 or -1
	dirctionVertically= normalized_num;
	random_num = rand(); // generate random integer
	normalized_num = (random_num % 2 == 0) ? 1 : -1; // normalize to 1 or -1
	dirctionHorizontally=normalized_num;
}

Location Animal::getLocation() const {
	return location_animal;
}

void Animal::stop() {
	temp_move = false;
}

void Animal::move() {
	temp_move = true;
}

void Animal::turnVertically() {
	dirctionVertically = dirctionVertically * -1;
}
void Animal::turnHorizontally() {
	dirctionHorizontally= dirctionHorizontally * -1;
}

