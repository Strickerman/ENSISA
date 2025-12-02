#include "Reptile.h"

using namespace std;

Reptile::Reptile(string n, string c, string d, string h, string s, bool p, int a, double w, double he, string _scalePattern)
    : Animal(n, c, d, h, s, p, a, w, he), scalePattern(_scalePattern)
{
}

void Reptile::printInfo() const {
    Animal::printInfo();
    cout << "Type: Reptile" << endl;
    cout << "Scale Pattern: " << scalePattern << endl;
}