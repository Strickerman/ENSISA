#ifndef TP_NOTE_ANIMAL_H
#define TP_NOTE_ANIMAL_H

#include <string>
#include <iostream>

class Animal {
private:
    std::string name;
    std::string color;
    std::string diet;
    std::string habitat;
    std::string sounds;
    bool isPet;
    int age;
    double weight;
    double height;

public:
    Animal();
    Animal(std::string name, std::string color, std::string diet, std::string habitat, std::string sounds, bool isPet, int age, double weight, double height);
    Animal(const Animal& other);

    std::string getName() const;
    std::string getColor() const;
    std::string getDiet() const;
    std::string getHabitat() const;
    std::string getSounds() const;
    bool getIsPet() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;

    void setName(std::string name);
    void setColor(std::string color);
    void setDiet(std::string diet);
    void setHabitat(std::string habitat);
    void setSounds(std::string sounds);
    void setIsPet(bool isPet);
    void setAge(int age);
    void setWeight(double weight);
    void setHeight(double height);

    void make_sound() const;
    virtual void printInfo() const;
};

#endif // TP_NOTE_ANIMAL_H