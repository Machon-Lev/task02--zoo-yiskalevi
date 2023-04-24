#include "Animal.h"
#include "Lion.h"
#include "Dog.h"
#include "Owl.h"

using std::string;
using std::cout;
using std::endl;

#include <vector>
#include <list>

class Zoo {

public: 
	Zoo();
	~Zoo();
	void run();

private:
	const int NUM_ROWS = 20;
	const int NUM_COLS = 40;
	std::vector<Animal*> zoos_animal;
	void stop(int num);
	void move(int num);
	void create(string kind, string name);
	void printMap();
	void moveAllAnimals();
	std::vector<string> spilt(string input);
	void del(int num);
	void delAll(string kind);
	void help();
	void addZoo(Animal* ani, int row, int col);
	int getIndex(int row, int col) const;
	Location randomLocation() const;

};