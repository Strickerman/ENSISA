#include <iostream>
#include "Zoo.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"

using namespace std;

int main() {
    Zoo myZoo("Zoo de Mulhouse");

    myZoo.addAnimal(new Mammal("Lion", "Gold", "Carnivore", "Savanna", "Roar", false, 5, 190.0, 1.2, "Short"));
    myZoo.addAnimal(new Mammal("Elephant", "Grey", "Herbivore", "Jungle", "Trumpet", false, 10, 5000.0, 3.0, "None"));
    myZoo.addAnimal(new Mammal("Dog", "Black", "Omnivore", "House", "Bark", true, 3, 30.0, 0.6, "Long"));

    myZoo.addAnimal(new Bird("Eagle", "Brown", "Carnivore", "Mountains", "Screech", false, 4, 6.0, 0.9, 2.0));
    myZoo.addAnimal(new Bird("Parrot", "Green", "Herbivore", "Jungle", "Squawk", true, 2, 1.0, 0.3, 0.5));

    myZoo.addAnimal(new Reptile("Snake", "Green", "Carnivore", "Jungle", "Hiss", false, 2, 5.0, 0.1, "Diamond"));
    myZoo.addAnimal(new Reptile("Lizard", "Brown", "Insectivore", "Desert", "Click", true, 1, 0.5, 0.1, "Rough"));

    myZoo.listAnimals();

    cout << "\n--- TEST PREDICTION ---" << endl;


    Mammal unknown1("Inconnu1", "Grey", "Herbivore", "Jungle", "Unknown", false, 5, 4500.0, 2.8, "?");

    cout << "Prediction pour Inconnu1 (Poids 4500kg) avec Numerical KNN (k=3):" << endl;
    string result1 = myZoo.predictTypeWithKNN(&unknown1, 3, "numerical");
    cout << "Resultat : " << result1 << endl << endl;

    Bird unknown2("Inconnu2", "Dark Brown", "Carnivore", "Mountains", "Screech", false, 2, 0, 0, 0);

    cout << "Prediction pour Inconnu2 (Habitat Mountains, Carnivore) avec Categorical KNN (k=1):" << endl;
    string result2 = myZoo.predictTypeWithKNN(&unknown2, 1, "categorical");
    cout << "Resultat : " << result2 << endl;

    return 0;
}