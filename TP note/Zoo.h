#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include <string>
#include "Animal.h"

class Zoo {
private:
    std::string name;
    static int MAX_CAPACITY;
    std::vector<Animal*> animals;
    std::string getAnimalType(Animal* animal) const;

public:
    Zoo();
    Zoo(std::string name);
    Zoo(const Zoo& other);

    ~Zoo();

    std::string getName() const;
    void listAnimals() const;
    void addAnimal(Animal* animal);
    int searchAnimalByName(std::string name) const;
    void removeAnimalByName(std::string name);
    double averageAgeForType(std::string type) const;
    std::string predictTypeWithKNN(Animal* target, int k, std::string type_info);
};

#endif