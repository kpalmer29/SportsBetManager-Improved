//
// Created by Kavi Palmer on 1/5/22.
//

#include "OverUnder.h"

//returns the point total
double OverUnder::getPoints() const {
    return points;
}

//returns true if betting over the point total, false otherwise
bool OverUnder::isOver() const {
    return over;
}

//sets whether betting over or under point total
void OverUnder::setOver(bool under) {
    over = under;
}

//sets the point total
void OverUnder::setPoints(const double &line) {
    points = line;
}

//returns true if rhs is equal to this object, false otherwise
bool OverUnder::equals(const OverUnder &rhs) const {
    return points == rhs.points &&
           over == rhs.over &&
           this->getFor() == rhs.getFor() &&
           this->getSport() == rhs.getSport() &&
           this->getDate() == rhs.getDate() &&
           this->getOdds() == rhs.getOdds() &&
           this->getAgainst() == rhs.getAgainst() &&
           this->getOddsSymbol() == rhs.getOddsSymbol();
}

//operator overload
bool OverUnder::operator==(const OverUnder &rhs) const {
    return equals(rhs);
}

//returns a string displaying a OverUnder object
std::string OverUnder::toString() const {
    std::string dt = getDate().toString();
    std::string odd = std::to_string(getOdds());
    std::string overPoints = std::to_string(points);
    std::string ou;
    if (over == true)
        ou = "Over";
    else
        ou = "Under";
    std::string returnString = getSport() + "- Over/Under: " + ou + " " + overPoints + "\n" +
            getFor() + ": " + getOddsSymbol() + odd +" vs. " + getAgainst() + "\nDate:" + dt;
    return returnString;
}