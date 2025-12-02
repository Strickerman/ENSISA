#include "Zoo.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "KNNDouble.h"
#include "KNNString.h"
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int Zoo::MAX_CAPACITY = 100;

Zoo::Zoo() : name("Zoo Inconnu") {}

Zoo::Zoo(string _name) : name(_name) {}

Zoo::Zoo(const Zoo& other) : name(other.name) {
    for (Animal* animal : other.animals) {
        if (Mammal* m = dynamic_cast<Mammal*>(animal)) {
            animals.push_back(new Mammal(*m));
        }
        else if (Bird* b = dynamic_cast<Bird*>(animal)) {
            animals.push_back(new Bird(*b));
        }
        else if (Reptile* r = dynamic_cast<Reptile*>(animal)) {
            animals.push_back(new Reptile(*r));
        }
    }
    cout << "Zoo copie cree avec succes." << endl;
}

Zoo::~Zoo() {
    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

string Zoo::getName() const { return name; }

void Zoo::listAnimals() const {
    cout << "Liste des animaux du " << name << ":" << endl;
    for (const auto& animal : animals) {
        animal->printInfo();
        cout << endl;
    }
}

void Zoo::addAnimal(Animal* newAnimal) {
    if (animals.size() >= MAX_CAPACITY) {
        cout << "Erreur : Le zoo est plein !" << endl;
        return;
    }
    auto it = lower_bound(animals.begin(), animals.end(), newAnimal,
        [](Animal* a, Animal* b) {
            return a->getName() < b->getName();
        }
    );
    animals.insert(it, newAnimal);
}

int Zoo::searchAnimalByName(string searchName) const {
    int left = 0;
    int right = animals.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        string midName = animals[mid]->getName();

        if (midName == searchName) {
            return mid;
        }
        if (midName < searchName) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void Zoo::removeAnimalByName(string name) {
    int index = searchAnimalByName(name);

    if (index != -1) {
        delete animals[index];
        animals.erase(animals.begin() + index);
        cout << name << " a ete retire du zoo." << endl;
    } else {
        cout << "Impossible de retirer " << name << " : Animal introuvable." << endl;
    }
}

double Zoo::averageAgeForType(string type) const {
    double totalAge = 0;
    int count = 0;

    for (Animal* animal : animals) {
        bool isTargetType = false;

        if (type == "Mammal" && dynamic_cast<Mammal*>(animal)) isTargetType = true;
        else if (type == "Bird" && dynamic_cast<Bird*>(animal)) isTargetType = true;
        else if (type == "Reptile" && dynamic_cast<Reptile*>(animal)) isTargetType = true;

        if (isTargetType) {
            totalAge += animal->getAge();
            count++;
        }
    }

    if (count == 0) {
        cout << "Aucun animal de type " << type << " trouve." << endl;
        return 0.0;
    }

    return totalAge / count;
}

string Zoo::getAnimalType(Animal* animal) const {
    if (dynamic_cast<Mammal*>(animal)) return "Mammal";
    if (dynamic_cast<Bird*>(animal)) return "Bird";
    if (dynamic_cast<Reptile*>(animal)) return "Reptile";
    return "Unknown";
}

string Zoo::predictTypeWithKNN(Animal* target, int k, string type_info) {
    vector<int> nearestIndices;

    if (type_info == "numerical") {
        KNNDouble knn(k);
        vector<pair<double, double>> trainData;

        for (Animal* a : animals) {
            trainData.push_back({a->getWeight(), a->getHeight()});
        }

        pair<double, double> targetData = {target->getWeight(), target->getHeight()};

        nearestIndices = knn.findNearestNeighbors(trainData, targetData);
    }
    else if (type_info == "categorical") {
        KNNString knn(k);
        vector<vector<string>> trainData;

        for (Animal* a : animals) {
            vector<string> features;
            features.push_back(a->getColor());
            features.push_back(a->getDiet());
            features.push_back(a->getHabitat());
            features.push_back(a->getSounds());
            trainData.push_back(features);
        }
        vector<string> targetData;
        targetData.push_back(target->getColor());
        targetData.push_back(target->getDiet());
        targetData.push_back(target->getHabitat());
        targetData.push_back(target->getSounds());

        nearestIndices = knn.findNearestNeighbors(trainData, targetData);
    }
    else {
        return "Error: Unknown method (use 'numerical' or 'categorical')";
    }

    map<string, int> votes;
    votes["Mammal"] = 0;
    votes["Bird"] = 0;
    votes["Reptile"] = 0;

    cout << "Voisins trouves (indices) : ";
    for (int index : nearestIndices) {
        cout << index << " ";
        string type = getAnimalType(animals[index]);
        votes[type]++;
    }
    cout << endl;

    string predictedType = "Unknown";
    int maxVotes = -1;

    for (auto const& [type, count] : votes) {
        if (count > maxVotes) {
            maxVotes = count;
            predictedType = type;
        }
    }

    return predictedType;
}