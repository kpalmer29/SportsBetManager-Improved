//
// Created by Kavi Palmer on 1/5/22.
//

#include "Spread.h"

//returns the spread value
double Spread::getSpread() const {
    return gameSpread;
}

//returns a string indicating whether betting over or under the spread
std::string Spread::getFavorite() const {
    if (favorite)
        return "-";

    else
        return "+";
}

//set the spread for this bet object
void Spread::setSpread(const double &spread) {
    gameSpread = spread;
}

//set if betting over or under spread
void Spread::setFavorite(bool fav) {
    favorite = fav;
}

//returns true if rhs equals this spread object
bool Spread::equals(const Spread &rhs) const {
    return gameSpread == rhs.gameSpread &&
           favorite == rhs.favorite &&
           this->getFor() == rhs.getFor() &&
           this->getSport() == rhs.getSport() &&
           this->getDate() == rhs.getDate() &&
           this->getOdds() == rhs.getOdds() &&
           this->getAgainst() == rhs.getAgainst();
}

//operator overload
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

//returns a string displaying a Spread bet
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
                               getFor() + ": " + getOddsSymbol() + odd +" vs. " + getAgainst() + "\nDate: " + dt;
    return returnString;
}