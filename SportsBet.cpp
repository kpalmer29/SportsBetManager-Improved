//
// Created by Kavi Palmer on 1/4/22.
//

#include "SportsBet.h"

//return Date
Date SportsBet::getDate() const {
    return gameDate;
}

//return odds
int SportsBet::getOdds() const {
    return odds;
}

//return sport
std::string SportsBet::getSport() const {
    return sport;
}

//return team bet Against
std::string SportsBet::getAgainst() const {
    return betAgainst;
}

//return team bet for
std::string SportsBet::getFor() const {
    return betFor;
}

//return direction of odds ('+' or '-')
char SportsBet::getOddsSymbol() const {
    return oddsSymbol;
}

//sets odds symbol ('+' or '-')
void SportsBet::setOddsSymbol(const char &od) {
    oddsSymbol = od;
}

//set team betting against
void SportsBet::setBetAgainst(const std::string &team) {
    betAgainst = team;
}

//set team betting for
void SportsBet::setBetFor(const std::string &team) {
    betFor = team;
}

//set date of game betting on
void SportsBet::setDate(const int &day, const int &month, const int &year) {
    gameDate.setDate(month, day, year);
}

//set the odds of the bet
void SportsBet::setOdds(const int &od) {
    odds = od;
}

//set the sport the bet is in
void SportsBet::setSport(const std::string &spt) {
    sport = spt;
}

//return a string of a Moneyline bet
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

//checks if param Sportsbet rhs is equal to this object
bool SportsBet::equals(const SportsBet &rhs) const {
    return gameDate == rhs.gameDate &&
           betFor == rhs.betFor &&
           betAgainst == rhs.betAgainst &&
           odds == rhs.odds &&
           sport == rhs.sport &&
           oddsSymbol == rhs.oddsSymbol;
}

//operator overload
bool SportsBet::operator==(const SportsBet &rhs) const {
    return equals(rhs);
}