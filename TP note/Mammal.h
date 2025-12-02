#ifndef TP_NOTE_MAMMAL_H
#define TP_NOTE_MAMMAL_H

#include "Animal.h"
#include <string>
#include <iostream>

class Mammal : public Animal {
private:
    std::string furColor;

public:
    Mammal(std::string name, std::string color, std::string diet, std::string habitat,
           std::string sounds, bool isPet, int age, double weight, double height,
           std::string furColor);

    void printInfo() const override;
};


#endif //TP_NOTE_MAMMAL_H