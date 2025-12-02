#include "Bird.h"

using namespace std;

Bird::Bird(string n, string c, string d, string h, string s, bool p, int a, double w, double he, double _wingspan)
    : Animal(n, c, d, h, s, p, a, w, he), wingspan(_wingspan)
{
}

void Bird::printInfo() const {
    Animal::printInfo();
    cout << "Type: Bird" << endl;
    cout << "Wingspan: " << wingspan << "m" << endl;
}