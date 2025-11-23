#ifndef TD1_PLAYER_H
#define TD1_PLAYER_H
#include <string>
#include <vector>

#include "Card.h"
#include "EnergyCard.h"
#include "PokemonCard.h"
#include "TrainerCard.h"

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;
public:
    Player(string playerName);
    ~Player();

    void displayInfo() const;
    string getPlayerName() const;
    void displayAction() const;
    void displayBench() const;
    void addCardToBench(Card * card);
    void activatePokemonCard(int i);
    void attachEnergyCard(int i, int i1);
    void attack(int i, int i1, const Player & player, int i2);
    void useTrainer(int i);
};

#endif //TD1_PLAYER_H