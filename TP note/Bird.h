#ifndef TP_NOTE_BIRD_H
#define TP_NOTE_BIRD_H

#include "Animal.h"
#include <string>
#include <iostream>

class Bird : public Animal {
private:
    double wingspan;

public:
    Bird(std::string name, std::string color, std::string diet, std::string habitat,
         std::string sounds, bool isPet, int age, double weight, double height,
         double wingspan);

    void printInfo() const override;
};


#endif //TP_NOTE_BIRD_H