#ifndef TD1_POKEMONCARD_H
#define TD1_POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;

class PokemonCard: public Card {
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;

    vector<tuple<int, int, string, int>> attacks;

public:
    PokemonCard(const string& name,
                const string& pokemonType,
                const string& familyName,
                int evolutionLevel,
                int maxHP,
                int hp,
                const vector<tuple<int, int, string, int>>& attacks);

    PokemonCard(const char * name, const char * pokemonType, const char * familyName, int evolutionLevel, int maxHP, int hp,
                const char * attack1Name, int attack1Cost, int attack1Power,
                const char * attack2Name, int attack2Power);

    void displayInfo() const override; // CORRECTION : Ajout de const et override
    ~PokemonCard() = default;
    void attachEnergy(int attackIndex); // CORRECTION : Fonction pour l'attachement d'énergie
    const string& getPokemonType() const;
    const string& getFamilyName() const;
    int getEvolutionLevel() const;
    int getMaxHP() const;
    int getHP() const;
    const vector<tuple<int, int, string, int>>& getAttacks() const;
    vector<tuple<int, int, string, int>>& getAttacks();

    void setHP(int newHP);
};

#endif