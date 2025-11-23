#ifndef TD1_ENERGYCARD_H
#define TD1_ENERGYCARD_H

#include "Card.h"
#include <string>

using std::string;

class EnergyCard : public Card {
private:
    string energyType;

public:
    EnergyCard(const string& energyType);
    void displayInfo() const override;
    ~EnergyCard() = default;
    const string& getEnergyType() const;
};

#endif