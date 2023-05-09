#include "Dog.h"

Dog::Dog(const std::string& name, Location& loc) :Animal(name, loc) { help_step = true; }

void Dog::printDetails() const
{
	cout << "My name: " << name_animal << endl;
	cout << "I am Dog" << endl;
	cout << "My location " << location_animal << endl;

}

char Dog::getInitial() const
{
	return 'D';
}

void Dog::step()
{
	if (temp_move)
	{
		if (help_step)
		{
			location_animal.row += 3 * dirctionVertically;
			help_step = false;
		}
		else
		{
			location_animal.row += -1 * dirctionVertically;
			help_step = true;
		}
	}
}

