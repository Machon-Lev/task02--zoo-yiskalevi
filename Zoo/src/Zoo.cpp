#include "Zoo.h"
#include <sstream>


Zoo::Zoo()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    string n = "Simba";
    Location lo = randomLocation();
    Animal* new_animal = new Lion(n, lo);
    zoos_animal.push_back(new_animal);
    
    n = "Mufasa";
    lo = randomLocation();
    new_animal = new Lion(n, lo);
    zoos_animal.push_back(new_animal);

    n = "Toto";
    lo = randomLocation();
    new_animal = new Dog(n, lo);
    zoos_animal.push_back(new_animal);

    n = "Hedwig";
    lo = randomLocation();
    new_animal = new Owl(n, lo);
    zoos_animal.push_back(new_animal);

}

Zoo::~Zoo() {
    for (std::vector<Animal*>::iterator it = zoos_animal.begin(); it != zoos_animal.end(); ++it) {
        delete* it;
    }
    zoos_animal.clear();
}

void Zoo::stop(int num)
{
    zoos_animal[num]->stop();
}

void Zoo::move(int num)
{
    zoos_animal[num]->move();
    //random diraction
    bool random_bool = rand() % 2 == 0;
    if (random_bool)
        zoos_animal[num]->turnHorizontally();
    random_bool = rand() % 2 == 0;
    if (random_bool)
        zoos_animal[num]->turnVertically();
}

void Zoo::create(string kind, string name)
{
    if (kind == "Lion")
    {
        Location lo = randomLocation();
        Animal*  new_animal = new Lion(name, lo);
        zoos_animal.push_back(new_animal);
    }
    else if (kind == "Dog")
    {
        Location lo = randomLocation();
        Animal* new_animal = new Dog(name, lo);
        zoos_animal.push_back(new_animal);
    }
    else if (kind == "Owl")
    {
        Location lo = randomLocation();
        Animal* new_animal = new Owl(name, lo);
        zoos_animal.push_back(new_animal);
    }
    else {
        cout << "The animal type is incorrect"<<endl;
    }
}

void Zoo::del(int num) {
    zoos_animal.erase(zoos_animal.begin() + num);
}

void Zoo::delAll(string kind) {
    for (auto it = zoos_animal.begin(); it != zoos_animal.end(); ) {
        if ((*it)->getInitial() == kind[0]) {
            delete* it;
            it = zoos_animal.erase(it);
        }
        else {
            ++it;
        }
    }
 
}

void Zoo::help() {
    std::cout << "stop - make the animal stop. The command will receive as a parameter the number of the animal. This animal will not move from here on, unless the move command is applied to it again." << std::endl;
    std::cout << "move – make the animal move. The command will receive as a parameter the number of the animal." << std::endl;
    std::cout << "create - creating another animal The command will receive as parameters the type of animal and a name for it." << std::endl;
    std::cout << "del – delete an animal from the list. Accepts as a parameter the number of the animal." << std::endl;
    std::cout << "delAll – deleting all animals of a certain type. The command will receive as a parameter the type of animal and will delete from the list all animals of this type." << std::endl;
    std::cout << "help - printing help text that explains what the possible commands are, what their parameters are and what they do." << std::endl;
    std::cout << "exit - exit from the program." << std::endl;
    std::cout << ". - This command will be used to make the program advance to the next queue, without changing anything." << std::endl;

}

Location Zoo::randomLocation() const {
    int randomRow = 0 + (std::rand() % (NUM_ROWS - 0 + 1));
    int randomCol = 0 + (std::rand() % (NUM_COLS - 0 + 1));
    return Location(randomRow, randomCol);
}

void Zoo::addZoo(Animal* ani, int row, int col) {
    //int index = getIndex(row, col);
    //zoos_map[index].push_back(ani);
}

int Zoo::getIndex(int row, int col) const{
    return row * NUM_COLS + col;
}

void Zoo::run() {
    bool temp = true;
    while (temp)
    {
        printMap();
        //printall anumals
        for (std::vector<Animal*>::iterator it = zoos_animal.begin(); it != zoos_animal.end(); ++it) {
            int index = std::distance(zoos_animal.begin(), it);
            cout << "Index: " << index << ' ' << endl;
            (*it)->printDetails();
        }
        string input;
        cout << "Enter a choice: ";
        //std::cin >> input;
        std::getline(std::cin, input);
        std::vector<string> tokens = spilt(input);


        if (tokens[0] == "stop" && tokens.size() == 2) {
            stop(std::stoi(tokens[1]));
        }
        else if (tokens[0] == "move" && tokens.size() == 2) {
            move(std::stoi(tokens[1]));
        }
        else if (tokens[0] == "create" && tokens.size() == 3) {
            create(tokens[1], tokens[2]);
        }
        else if (tokens[0] == "del" && tokens.size() == 2) {
            del(std::stoi(tokens[1]));
        }
        else if (tokens[0] == "delAll" && tokens.size() == 2) {
            delAll(tokens[1]);
        }
        else if (tokens[0] == "help" && tokens.size() == 1) {
            help();
        }
        else if (tokens[0] == "exit" && tokens.size() == 1) {
            temp = false;
        }
        else if (tokens[0] == "." && tokens.size() == 1) {
            
        }
        else {
            cout << "No valid action was selected" << endl;
        }

        moveAllAnimals();

    }
   


}

std::vector<string>Zoo::spilt(string input)
{
    std::vector<std::string> tokens;
    int pos = 0;
    std::string delimiter = " ";
    while ((pos = input.find(delimiter)) != std::string::npos) {
        std::string token = input.substr(0, pos);
        tokens.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    tokens.push_back(input); // add the last token
    return tokens;
}

void Zoo::moveAllAnimals()
{
    for (auto animal_ptr : zoos_animal) {
        animal_ptr->step();
        int row = animal_ptr->getLocation().row;
        if (row > NUM_ROWS || row < 0)
        {
            animal_ptr->turnHorizontally();
            animal_ptr->step();
        }
        else  if (row == NUM_ROWS || row == 0) {
            animal_ptr->turnHorizontally();
        }
        int col = animal_ptr->getLocation().column;
        if (col > NUM_COLS || col < 0)
        {
            animal_ptr->turnVertically();
            animal_ptr->step();
        }
        else  if (col == NUM_COLS || col == 0) {
            animal_ptr->turnHorizontally();
        }
    }
}

void Zoo::printMap() {

    std::vector<char> zoos_map;
    zoos_map.resize(NUM_ROWS * NUM_COLS);
    for (auto animal_ptr : zoos_animal) {
        int indx = getIndex(animal_ptr->getLocation().row, animal_ptr->getLocation().column);
        zoos_map[indx] =animal_ptr->getInitial();
    }

    for (int i = 0; i < NUM_ROWS; i++)
    {
        if (i == 0) {
            cout << "  ";
            for (int t = 0; t < NUM_COLS; t++)
            { 
                if (t < 10)
                    cout << ' ';
                cout << " " << t << '|';
 
            }
            cout << endl;
        }
        if(i<10)
            cout << ' ';
        cout << i << '|';
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (zoos_map[getIndex(i, j)] != NULL)
            {
                cout << "  " << zoos_map[getIndex(i, j)] << '|';
            }
            else
            {
                cout << "   |";
            }
        }
        cout << endl;
    }

}




