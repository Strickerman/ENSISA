#include "EnergyCard.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

EnergyCard::EnergyCard(const string& _energyType)
    : Card("Energy"),
      energyType(_energyType)
{}

void EnergyCard::displayInfo() const {
}

const string& EnergyCard::getEnergyType() const {
    return energyType;
}