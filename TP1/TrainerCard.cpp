#include "TrainerCard.h"
#include <iostream>

#include "PokemonCard.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

TrainerCard::TrainerCard(const string& _trainerName, const string& _effect)
    : Card(_trainerName),
      trainerEffect(_effect)
{}

void TrainerCard::displayInfo() const {
    cout << "Trainer Card Name: " << getCardName() << ", Effect: " << trainerEffect << endl;
}

void TrainerCard::applyEffect(vector<PokemonCard*>& activePokemons) {
    if (trainerEffect == "heal all your action pokemon") {
        for (PokemonCard* pokemon : activePokemons) {
            if (pokemon != nullptr) {
                int maxHP = pokemon->getMaxHP();
                pokemon->setHP(maxHP);
            }
        }
    }
}

const string& TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}