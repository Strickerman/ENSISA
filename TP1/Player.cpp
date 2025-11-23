#include "Player.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "PokemonCard.h"
#include <iostream>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::get;

Player::Player(string _playerName):
playerName(std::move(_playerName))
{}

Player::~Player() {
    for (Card* card : benchCards) {
        delete card;
    }
    for (PokemonCard* pokemon : actionCards) {
        delete pokemon;
    }
}

string Player::getPlayerName() const {
    return playerName;
}

void Player::displayInfo() const {
}

void Player::addCardToBench(Card * card) {
    if (benchCards.size() < 5) {
        benchCards.push_back(card);
    }
}

void Player::activatePokemonCard(int benchIndex) {
    if (benchIndex >= 0 && benchIndex < benchCards.size()) {
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[benchIndex]);
        if (pokemon != nullptr) {
            if (actionCards.empty()) {
                actionCards.push_back(pokemon);
                benchCards.erase(benchCards.begin() + benchIndex);
                cout << getPlayerName() << " is activating a Pokemon Card: " << pokemon->getCardName() << endl;
            }
        }
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (actionCards.empty()) return;
    PokemonCard* activePokemon = actionCards[0];
    if (benchIndex >= 0 && benchIndex < benchCards.size()) {
        EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
        if (energy != nullptr) {
            cout << getPlayerName() << " is attaching Energy Card of type " << energy->getEnergyType()
                 << " to the Pokemon " << activePokemon->getCardName() << endl;
            activePokemon->attachEnergy(0);
            delete benchCards[benchIndex];
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << getPlayerName() << ":" << endl;
    if (!actionCards.empty()) {
        actionCards[0]->displayInfo();
    }
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << getPlayerName() << ":" << endl;
    if (!benchCards.empty()) {
        for (Card* card : benchCards) {
            if (dynamic_cast<TrainerCard*>(card) != nullptr) {
                card->displayInfo();
            }
        }
    }
}

void Player::attack(int actionIndex, int attackIndex, const Player & opponent, int opponentActionIndex) {
    if (actionCards.empty() || opponent.actionCards.empty()) return;
    PokemonCard* attacker = actionCards[0];
    PokemonCard* defender = opponent.actionCards[0];
    auto& attacks = attacker->getAttacks();
    if (attackIndex < 0 || attackIndex >= attacks.size()) return;
    const auto& attack = attacks[attackIndex];
    int damage = get<1>(attack);
    string attackName = get<2>(attack);
    cout << getPlayerName() << " attacking " << opponent.getPlayerName() << "'s Pokemon "
         << defender->getCardName() << " with the Pokemon " << attacker->getCardName()
         << " with its attack: " << attackName << endl;

    cout << "Reducing " << damage << " from " << opponent.getPlayerName() << "'s Pokemon's HP" << endl;
    PokemonCard* mutableDefender = const_cast<Player&>(opponent).actionCards[0];
    int newHP = mutableDefender->getHP() - damage;
    mutableDefender->setHP(newHP);
    if (newHP > 0) {
        cout << "Pokemon " << defender->getCardName() << " is still alive" << endl;
    } else {
        cout << "Pokemon " << defender->getCardName() << " is knocked out" << endl;
    }
}

void Player::useTrainer(int benchIndex) {
    if (benchIndex >= 0 && benchIndex < benchCards.size()) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);
        if (trainer != nullptr) {
            cout << getPlayerName() << " is using the Trainer Card to \"" << trainer->getTrainerEffect() << "\"" << endl;
            vector<PokemonCard*>& activePokemons = actionCards;
            trainer->applyEffect(activePokemons);
            delete benchCards[benchIndex];
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}