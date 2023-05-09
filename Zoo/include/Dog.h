#pragma once
#include "Animal.h"

class Dog: public Animal {

public: 
	Dog(const std::string& name, Location& loc);
	virtual ~Dog() = default;

	// Inherited via Animal
	virtual void printDetails() const;

	virtual char getInitial() const;

	virtual void step();



private:
	bool help_step;
};