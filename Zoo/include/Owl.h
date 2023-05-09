#pragma once

#include "Animal.h"

class Owl : public Animal {

public:
	Owl(const std::string& name, Location& loc);
	virtual ~Owl() = default;

	// Inherited via Animal
	virtual void printDetails() const;

	virtual char getInitial() const;

	virtual void step();

private:

};