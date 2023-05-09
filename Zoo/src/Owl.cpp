#include "Owl.h"

Owl::Owl(const std::string& name, Location& loc) :Animal(name, loc) {}

void Owl::printDetails() const
{
	cout << "My name: " << name_animal << endl;
	cout << "I am Owl" << endl;
	cout << "My location " << location_animal << endl;

}

char Owl::getInitial() const
{
	return 'O';
}

void Owl::step()
{
	if (temp_move)
	{
		location_animal.row += 3 * dirctionHorizontally;
		location_animal.column += 3 * dirctionVertically;	
	}
}

