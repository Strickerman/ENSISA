#ifndef TD1_CARD_H
#define TD1_CARD_H
#include <string>

using std::string;

class Card {
private:
    string cardName;
public:
    Card(std::string);
    virtual void displayInfo() const = 0;
    virtual ~Card() = default;
    const std::string& getCardName() const { return cardName; }
};

#endif