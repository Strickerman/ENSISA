#include "Card.h"
#include <string>

Card::Card(std::string name) : cardName(std::move(name)) {
}