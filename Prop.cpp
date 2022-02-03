//
// Created by Kavi Palmer on 1/5/22.
//

#include "Prop.h"

//return prop line
double Prop::getPropLine() const {
    return propLine;
}

//return prop category
std::string Prop::getPropType() const {
    return propType;
}

//set the line for the prop bet
void Prop::setPropLine(const double &line) {
    propLine = line;
}

//set the category of the prop bet (i.e. rebounds)
void Prop::setPropType(const std::string &type) {
    propType = type;
}

//checks if Prop bet rhs is equal to this object
bool Prop::equals(const Prop &rhs) const {
    return propType == rhs.propType &&
           propLine == rhs.propLine &&
           this->getFor() == rhs.getFor() &&
           this->getSport() == rhs.getSport() &&
           this->getDate() == rhs.getDate() &&
           this->getOdds() == rhs.getOdds() &&
           this->getAgainst() == rhs.getAgainst();
}

//operator overload
bool Prop::operator==(const Prop &rhs) const {
    return equals(rhs);
}

//returns if betting over or under the prop category
bool Prop::isOver() const {
    return over;
}

//sets if betting over or under the prop category
void Prop::setOver(bool under) {
    over = under;
}

//returns a string displaying a prop bet
std::string Prop::toString() const {
    std::string dt = getDate().toString();
    std::string odd = std::to_string(getOdds());
    std::string line = std::to_string(propLine);
    std::string ou;
    if (over == true)
        ou = "Over";
    else
        ou = "Under";

    std::string returnString = getSport() + "- Prop\n" + getFor() + " " + ou + " " + line + " " + propType +
                               "\nOdds: " + getOddsSymbol() + odd + "\n" +
                               "Playing Against: " + getAgainst() + "\nDate: " + dt;

    return returnString;
}