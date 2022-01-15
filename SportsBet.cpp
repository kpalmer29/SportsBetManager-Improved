//
// Created by Kavi Palmer on 1/4/22.
//

#include "SportsBet.h"

Date SportsBet::getDate() const {
    return gameDate;
}

int SportsBet::getOdds() const {
    return odds;
}

std::string SportsBet::getSport() const {
    return sport;
}

std::string SportsBet::getAgainst() const {
    return betAgainst;
}

std::string SportsBet::getFor() const {
    return betFor;
}

char SportsBet::getOddsSymbol() const {
    return oddsSymbol;
}

void SportsBet::setOddsSymbol(const char &od) {
    oddsSymbol = od;
}

void SportsBet::setBetAgainst(const std::string &team) {
    betAgainst = team;
}

void SportsBet::setBetFor(const std::string &team) {
    betFor = team;
}

void SportsBet::setDate(const int &day, const int &month, const int &year) {
    gameDate.setDate(month, day, year);
}

void SportsBet::setOdds(const int &od) {
    odds = od;
}

void SportsBet::setSport(const std::string &spt) {
    sport = spt;
}

std::string SportsBet::toString() {
    std::string dt = gameDate.toString();
    std::string odd = std::to_string(odds);
    std::string symbol;
    if (oddsSymbol == '-')
        symbol = "-";
    else
        symbol = "+";
    std::string returnString = sport + "- Moneyline" + "\n" + betFor +" " + symbol + odd +" vs. " + betAgainst + "\nDate: " + dt;
    return returnString;
}

bool SportsBet::equals(const SportsBet &rhs) const {
    return gameDate == rhs.gameDate &&
           betFor == rhs.betFor &&
           betAgainst == rhs.betAgainst &&
           odds == rhs.odds &&
           sport == rhs.sport &&
           oddsSymbol == rhs.oddsSymbol;
}

bool SportsBet::operator==(const SportsBet &rhs) const {
    return equals(rhs);
}