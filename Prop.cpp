//
// Created by Kavi Palmer on 1/5/22.
//

#include "Prop.h"

double Prop::getPropLine() const {
    return propLine;
}

std::string Prop::getPropType() const {
    return propType;
}

void Prop::setPropLine(const double &line) {
    propLine = line;
}

void Prop::setPropType(const std::string &type) {
    propType = type;
}

bool Prop::equals(const Prop &rhs) const {
    return propType == rhs.propType &&
           propLine == rhs.propLine &&
           this->getFor() == rhs.getFor() &&
           this->getSport() == rhs.getSport() &&
           this->getDate() == rhs.getDate() &&
           this->getOdds() == rhs.getOdds() &&
           this->getAgainst() == rhs.getAgainst();
}

bool Prop::operator==(const Prop &rhs) const {
    return equals(rhs);
}

bool Prop::isOver() const {
    return over;
}

void Prop::setOver(bool under) {
    over = under;
}

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