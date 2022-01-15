//
// Created by Kavi Palmer on 1/5/22.
//

#include "Spread.h"

int Spread::getSpread() const {
    return gameSpread;
}

std::string Spread::getFavorite() const {
    if (favorite == true)
        return "Favorite";

    else
        return "Underdog";
}

void Spread::setSpread(const double &spread) {
    gameSpread = spread;
}

void Spread::setFavorite(bool fav) {
    favorite = fav;
}

bool Spread::equals(const Spread &rhs) const {
    return gameSpread == rhs.gameSpread &&
           favorite == rhs.favorite &&
           this->getFor() == rhs.getFor() &&
           this->getSport() == rhs.getSport() &&
           this->getDate() == rhs.getDate() &&
           this->getOdds() == rhs.getOdds() &&
           this->getAgainst() == rhs.getAgainst();
}

bool Spread::operator==(const Spread &rhs) const {
    return gameSpread == rhs.gameSpread &&
           favorite == rhs.favorite &&
           this->getFor() == rhs.getFor() &&
           this->getSport() == rhs.getSport() &&
           this->getDate() == rhs.getDate() &&
           this->getOdds() == rhs.getOdds() &&
           this->getAgainst() == rhs.getAgainst() &&
           this->getOddsSymbol() == rhs.getOddsSymbol();

}

std::string Spread::toString() const {
    std::string dt = getDate().toString();
    std::string odd = std::to_string(getOdds());
    std::string symbol;
    std::string spreadString = std::to_string(gameSpread);
    spreadString = spreadString.substr(0,4);
    if (favorite)
        symbol = "-";
    else
        symbol = "+";
    std::string returnString = getSport() + "- Spread: " + symbol + spreadString + "\n" +
                               getFor() + ": " + getOddsSymbol() + odd +" vs. " + getAgainst() + "\nDate:" + dt;
    return returnString;
}