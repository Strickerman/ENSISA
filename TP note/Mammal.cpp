#include "Mammal.h"

using namespace std;

Mammal::Mammal(string n, string c, string d, string h, string s, bool p, int a, double w, double he, string _furColor)
    : Animal(n, c, d, h, s, p, a, w, he), furColor(_furColor)
{
}

void Mammal::printInfo() const {
    Animal::printInfo();
    cout << "Type: Mammal" << endl;
    cout << "Fur Color: " << furColor << endl;
}