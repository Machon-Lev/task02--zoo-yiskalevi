#include "Lion.h"


Lion::Lion(const std::string& name, Location& loc) :Animal(name, loc) {}

void Lion::printDetails() const
{
	cout << "My name: " << name_animal <<endl;
	cout << "I am Lion" <<endl;
	cout << "My location " << location_animal <<endl;

}

char Lion::getInitial() const
{
	return 'L';
}

void Lion::step()
{
	if (temp_move)
	{
		location_animal.column += 2* dirctionHorizontally;	
	}
}
