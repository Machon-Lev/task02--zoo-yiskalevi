#pragma once
#include "Animal.h"
#include "LocationS.h"

class Lion : public Animal {

public:
	Lion(const std::string& name, Location& loc);
	virtual ~Lion() = default;

	// Inherited via Animal
	virtual void printDetails() const ;

	virtual char getInitial() const ;

	virtual void step();
	

private:


	

};