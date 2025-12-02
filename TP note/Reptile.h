#ifndef TP_NOTE_REPTILE_H
#define TP_NOTE_REPTILE_H

#include "Animal.h"
#include <string>
#include <iostream>

class Reptile : public Animal {
private:
    std::string scalePattern;

public:
    Reptile(std::string name, std::string color, std::string diet, std::string habitat,
            std::string sounds, bool isPet, int age, double weight, double height,
            std::string scalePattern);

    void printInfo() const override;
};


#endif //TP_NOTE_REPTILE_H