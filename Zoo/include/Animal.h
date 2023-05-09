#pragma once

#include "LocationS.h"

using std::string;
using std::cout;
using std::endl;


class Animal
{

public: 
	Animal(const string& name, Location& loc);
	virtual ~Animal()=default;
	virtual void printDetails() const =0;
	virtual char getInitial() const = 0;
	virtual void step() = 0;
	
	Location getLocation() const;
	void stop();
	void move();
	void turnVertically();
	void turnHorizontally();



protected:
	string name_animal;
	Location location_animal;
	bool temp_move;
	int dirctionVertically;
	int dirctionHorizontally;


};