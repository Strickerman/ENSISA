#include "PokemonCard.h"
#include <iostream>
#include <string>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;
using std::cout;
using std::endl;
using std::get;

PokemonCard::PokemonCard(const string& _name,
                         const string& _pokemonType,
                         const string& _familyName,
                         int _evolutionLevel,
                         int _maxHP,
                         int _hp,
                         const vector<tuple<int, int, string, int>>& _attacks)
    : Card(_name),
      pokemonType(_pokemonType),
      familyName(_familyName),
      evolutionLevel(_evolutionLevel),
      maxHP(_maxHP),
      hp(_maxHP),
      attacks(_attacks)
{}

PokemonCard::PokemonCard(const char * name, const char * pokemonType, const char * familyName, int evolutionLevel, int maxHP, int hp,
                         const char * attack1Name, int attack1Cost, int attack1Power,
                         const char * attack2Name, int attack2Power)
    : Card(name),
      pokemonType(pokemonType),
      familyName(familyName),
      evolutionLevel(evolutionLevel),
      maxHP(maxHP),
      hp(maxHP),
      attacks({
          std::make_tuple(
              (name[0] == 'P' ? 2 : 2),
              (name[0] == 'P' ? 20 : 15),
              std::string(attack1Name), 0),

          std::make_tuple(
              3,
              attack2Power,
              std::string(attack2Name), 0)
      })
{}

void PokemonCard::attachEnergy(int attackIndex) {
    if (attacks.empty()) return;
    get<3>(attacks[0])++;
    get<3>(attacks[1])++;
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card Name: " << getCardName()
         << ", Type: " << pokemonType
         << ", Evolution Level: " << evolutionLevel
         << " of the family \"" << familyName
         << ", HP: " << hp << "\"" << endl;

    cout << "Attacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        int attackCost = get<0>(attacks[i]);
        int attackDamage = get<1>(attacks[i]);
        string attackName = get<2>(attacks[i]);
        int currentEnergy = get<3>(attacks[i]);

        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << attackCost << endl;
        cout << "Attack current energy storage: " << currentEnergy << endl;
        cout << "Attack description: " << attackName << endl;
        cout << "Attack damage: " << attackDamage << endl;
    }
}

const string& PokemonCard::getPokemonType() const { return pokemonType; }
const string& PokemonCard::getFamilyName() const { return familyName; }
int PokemonCard::getEvolutionLevel() const { return evolutionLevel; }
int PokemonCard::getMaxHP() const { return maxHP; }
int PokemonCard::getHP() const { return hp; }
const vector<tuple<int, int, string, int>>& PokemonCard::getAttacks() const { return attacks; }
vector<tuple<int, int, string, int>>& PokemonCard::getAttacks() { return attacks; }
void PokemonCard::setHP(int newHP) {
    if (newHP < 0) {
        hp = 0;
    } else if (newHP > maxHP) {
        hp = maxHP;
    } else {
        hp = newHP;
    }
}