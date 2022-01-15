//
// Created by Kavi Palmer on 1/12/22.
//

#include "SportsBetManager.h"

SportsBetManager::SportsBetManager() {}

void SportsBetManager::addMoneylineBet(const SportsBet &newBet) {
    moneylineArray.addBet(newBet);
}

void SportsBetManager::addOverUnderBet(const OverUnder &newBet) {
    overUnderArray.addBet(newBet);
}

void SportsBetManager::addPropBet(const Prop &newBet) {
    propArray.addBet(newBet);
}

void SportsBetManager::addSpreadBet(const Spread &newBet) {
    spreadArray.addBet(newBet);
}

void SportsBetManager::deleteAllBets() {
    spreadArray.deleteAllBets();
    propArray.deleteAllBets();
    overUnderArray.deleteAllBets();
    moneylineArray.deleteAllBets();
}

void SportsBetManager::deleteBetsBefore(const Date &date) {
    if (!spreadArray.isEmpty())
        spreadArray.deleteBetsBefore(date);
    if (!propArray.isEmpty())
        propArray.deleteBetsBefore(date);
    if (!overUnderArray.isEmpty())
        overUnderArray.deleteBetsBefore(date);
    if (!moneylineArray.isEmpty())
        moneylineArray.deleteBetsBefore(date);
}

void SportsBetManager::deleteBetsAgainst(const std::string &oldBet) {
    if (!spreadArray.isEmpty())
        spreadArray.deleteBetsAgainst(oldBet);
    if (!propArray.isEmpty())
        propArray.deleteBetsAgainst(oldBet);
    if (!overUnderArray.isEmpty())
        overUnderArray.deleteBetsAgainst(oldBet);
    if (!moneylineArray.isEmpty())
        moneylineArray.deleteBetsAgainst(oldBet);
}

void SportsBetManager::deleteBetsFor(const std::string &oldBet) {
    if (!spreadArray.isEmpty())
        spreadArray.deleteBetsFor(oldBet);
    if (!propArray.isEmpty())
        propArray.deleteBetsFor(oldBet);
    if (!overUnderArray.isEmpty())
        overUnderArray.deleteBetsFor(oldBet);
    if (!moneylineArray.isEmpty())
        moneylineArray.deleteBetsFor(oldBet);
}

void SportsBetManager::deleteMoneylineBet(const SportsBet &oldBet) {
    moneylineArray.deleteBet(oldBet);
}

void SportsBetManager::deletePropBet(const Prop &oldBet) {
    propArray.deleteBet(oldBet);
}

void SportsBetManager::deleteOverUnderBet(const OverUnder &oldBet) {
    overUnderArray.deleteBet(oldBet);
}

void SportsBetManager::deleteSpreadBet(const Spread &oldBet) {
    spreadArray.deleteBet(oldBet);
}

std::string SportsBetManager::getAllPropBets() const {
    if(propArray.isEmpty())
        return "No prop bets stored";
    else
        return propArray.getAllBets();
}

std::string SportsBetManager::getBetsOnDate(Date date) const {
    std::string returnString;
    if (!propArray.isEmpty()) {
        if (propArray.getBetsOnDate(date) != "None")
            returnString.append(propArray.getBetsOnDate(date) + "\n");
    }
    if (!spreadArray.isEmpty()) {
        if (spreadArray.getBetsOnDate(date) != "None")
            returnString.append(spreadArray.getBetsOnDate(date) + "\n");
    }

    if (!moneylineArray.isEmpty()) {
        if (moneylineArray.getBetsOnDate(date) != "None")
            returnString.append(moneylineArray.getBetsOnDate(date) + "\n");
    }

    if (!overUnderArray.isEmpty()) {
        if (overUnderArray.getBetsOnDate(date) != "None")
            returnString.append(overUnderArray.getBetsOnDate(date) + "\n");
    }

    return returnString;
}

std::string SportsBetManager::getAllBets() const {
    Date earliestDate = getEarliestDate();
    Date lastDate = getLatestDate();
    std::string returnString;

    for (Date i = earliestDate; i <= lastDate; i.increment()) {
        returnString.append(getBetsOnDate(i));
    }

    return returnString;
}

std::string SportsBetManager::getBetsFor(const std::string &team) const {
    Date earliestDate = getEarliestDate();
    Date lastDate = getLatestDate();
    std::string returnString;

    for (Date i = earliestDate; i <= lastDate; i.increment()) {
        returnString.append(spreadArray.getBetsFor(team, i));
        returnString.append(moneylineArray.getBetsFor(team, i));
        returnString.append(overUnderArray.getBetsFor(team, i));
        returnString.append(propArray.getBetsFor(team, i));
    }

    return returnString;
}

std::string SportsBetManager::getBetsAgainst(const std::string &team) const {
    Date earliestDate = getEarliestDate();
    Date lastDate = getLatestDate();
    std::string returnString;

    for (Date i = earliestDate; i <= lastDate; i.increment()) {
        returnString.append(spreadArray.getBetsAgainst(team, i));
        returnString.append(moneylineArray.getBetsAgainst(team, i));
        returnString.append(overUnderArray.getBetsAgainst(team, i));
        returnString.append(propArray.getBetsAgainst(team, i));
    }

    return returnString;
}

std::string SportsBetManager::getBetsOfSport(const std::string &spt) const {
    Date earliestDate = getEarliestDate();
    Date lastDate = getLatestDate();
    std::string returnString;

    for (Date i = earliestDate; i <= lastDate; i.increment()) {
        returnString.append(spreadArray.getBetsOfSport(spt, i));
        returnString.append(moneylineArray.getBetsOfSport(spt, i));
        returnString.append(overUnderArray.getBetsOfSport(spt, i));
        returnString.append(propArray.getBetsOfSport(spt, i));
    }

    return returnString;
}

Date SportsBetManager::getEarliestDate() const { //bad access, cant get earliest date from empty objects
    Date earliestDate;

    Date spreadDate, moneyDate, overDate, propDate;
    spreadDate.setDate(1, 1, 3000);
    moneyDate.setDate(1, 1, 3000);
    overDate.setDate(1, 1, 3000);
    propDate.setDate(1, 1, 3000);


    if (!spreadArray.isEmpty())
        spreadDate = spreadArray.getEarliestDate();

    if (!moneylineArray.isEmpty())
        moneyDate = moneylineArray.getEarliestDate();

    if (!overUnderArray.isEmpty())
        overDate = overUnderArray.getEarliestDate();

    if (!propArray.isEmpty())
        propDate = propArray.getEarliestDate();

    if (spreadDate <= moneyDate && spreadDate <= propDate && spreadDate <= overDate)
        earliestDate = spreadDate;

    else if (moneyDate <= spreadDate && moneyDate <= propDate && moneyDate <= overDate)
        earliestDate = moneyDate;

    else if (propDate <= moneyDate && propDate <= spreadDate && propDate <= overDate)
        earliestDate = propDate;

    else
        earliestDate = overDate;

    return earliestDate;
}

Date SportsBetManager::getLatestDate() const {
    Date latestDate;

    Date spreadDate, moneyDate, overDate, propDate;
    spreadDate.setDate(1, 1, 1000);
    moneyDate.setDate(1, 1, 1000);
    overDate.setDate(1, 1, 1000);
    propDate.setDate(1, 1, 1000);


    if (!spreadArray.isEmpty())
        spreadDate = spreadArray.getLastDate();

    if (!moneylineArray.isEmpty())
        moneyDate = moneylineArray.getLastDate();

    if (!overUnderArray.isEmpty())
        overDate = overUnderArray.getLastDate();

    if (!propArray.isEmpty())
        propDate = propArray.getLastDate();

    if (spreadDate >= moneyDate && spreadDate >= propDate && spreadDate >= overDate)
        latestDate = spreadDate;

    else if (moneyDate >= spreadDate && moneyDate >= propDate && moneyDate >= overDate)
        latestDate = moneyDate;

    else if (propDate >= moneyDate && propDate >= spreadDate && propDate >= overDate)
        latestDate = propDate;

    else
        latestDate = overDate;

    return latestDate;
}

bool SportsBetManager::isEmpty() {
    return spreadArray.isEmpty() && moneylineArray.isEmpty() && overUnderArray.isEmpty() && propArray.isEmpty();
}