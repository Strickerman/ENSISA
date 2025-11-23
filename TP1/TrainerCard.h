#ifndef TD1_TRAINERCARD_H
#define TD1_TRAINERCARD_H

#include "Card.h"
#include <string>
#include <vector>

class PokemonCard;
using std::string;
using std::vector;

class TrainerCard : public Card {
private:
    string trainerEffect;

public:
    TrainerCard(const string& trainerName, const string& effect);
    void displayInfo() const override;
    ~TrainerCard() = default;
    void applyEffect(vector<PokemonCard*>& activePokemons);
    const string& getTrainerEffect() const;
};

#endif