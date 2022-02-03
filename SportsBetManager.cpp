//
// Created by Kavi Palmer on 1/12/22.
//

#include "SportsBetManager.h"

SportsBetManager::SportsBetManager() {}

//adds bet to moneylineArray
void SportsBetManager::addMoneylineBet(const SportsBet &newBet) {
    moneylineArray.addBet(newBet);
}

//adds bet to overUnderArray
void SportsBetManager::addOverUnderBet(const OverUnder &newBet) {
    overUnderArray.addBet(newBet);
}

//adds bet to propArray
void SportsBetManager::addPropBet(const Prop &newBet) {
    propArray.addBet(newBet);
}

//adds bet to spreadArray
void SportsBetManager::addSpreadBet(const Spread &newBet) {
    spreadArray.addBet(newBet);
}

//deletes all bets in the four linked lists
void SportsBetManager::deleteAllBets() {
    spreadArray.deleteAllBets();
    propArray.deleteAllBets();
    overUnderArray.deleteAllBets();
    moneylineArray.deleteAllBets();
}

/**
 * Deletes all bets before a certain date. Checks to make sure each array contains bets before
 * calling deleteBetsBefore function in the BetList Class
 * @param date - Date object
 */
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

/**
 * Deletes all bets placed against a certain team. Checks to make sure each array contains
 * bets before calling the deleteBetsAgainst function in the BetList Class
 * @param oldBet - string of player/team to delete bets against
 */
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

/**
 * Deletes all bets placed against a certain team. Checks to make sure each array contains bets
 * before calling the deleteBetsFor method in the BetList Class
 * @param oldBet - string of player/team to delete bets for
 */
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

/**
 * Accepts a parameter SportsBet object and calls the deleteBet function in the BetList class
 * @param oldBet - SportsBet object
 */
void SportsBetManager::deleteMoneylineBet(const SportsBet &oldBet) {
    moneylineArray.deleteBet(oldBet);
}

/**
 * Accepts a parameter Prop object and calls the deleteBet function in the BetList class
 * @param oldBet - Prop object
 */
void SportsBetManager::deletePropBet(const Prop &oldBet) {
    propArray.deleteBet(oldBet);
}

/**
 * Accepts a parameter OverUnder object and calls the deleteBet function in the BetList class
 * @param oldBet - OverUnder object
 */
void SportsBetManager::deleteOverUnderBet(const OverUnder &oldBet) {
    overUnderArray.deleteBet(oldBet);
}

/**
 * Accepts a parameter Spread object and calls the deleteBet function in the BetList class
 * @param oldBet - Spread object
 */
void SportsBetManager::deleteSpreadBet(const Spread &oldBet) {
    spreadArray.deleteBet(oldBet);
}

/**
 * Returns a string of all bets held by propArray. Calls the getAllBets() function in the
 * BetList class
 * @return - String of all Prop bets
 */
std::string SportsBetManager::getAllPropBets() const {
    if(propArray.isEmpty())
        return "No prop bets stored";
    else
        return propArray.getAllBets();
}

/**
 * This class returns a string of all bets placed in the four BetList arrays
 * on a certain date. The function checks to make sure each array is not empty.
 * If the array contains bets, it checks whether it contains bets on the given date, and if it does
 * appends it to the returnString. This method calls the getBetsOnDate() function in the BetList Class.
 *
 * @param date - Date object
 * @return - string of all bets held by the manager of a given date
 */
std::string SportsBetManager::getBetsOnDate(Date date) const {
    std::string returnString;

    if (!propArray.isEmpty()) {
        if (propArray.getBetsOnDate(date) != "None") //no bets on given date
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

/**
 * This function returns all bets held by the Manager. It calls getEarliestDate(), getLatestDate(), and getBetsOnDate()
 * functions in this class. It also calls the increment() function in the Date class for looping.
 * @return - a String containing all bets held by the Manager
 */
std::string SportsBetManager::getAllBets() const {
    Date earliestDate = getEarliestDate();
    Date lastDate = getLatestDate();
    std::string returnString;

    for (Date i = earliestDate; i <= lastDate; i.increment()) {
        returnString.append(getBetsOnDate(i));
    }

    return returnString;
}

/**
 * returns a string containing all bets which have been placed for a certain team. This function calls getEarliestDate()
 * and getLatestDate() in this class, increment() in the Date class, and getBetsFor() in the BetList class.
 * @param team - String denoting player/team
 * @return - string with all appropriate bet objects
 */
std::string SportsBetManager::getBetsFor(const std::string &team) const {
    Date earliestDate = getEarliestDate();
    Date lastDate = getLatestDate();
    std::string returnString;

    for (Date i = earliestDate; i <= lastDate; i.increment()) { //increment function is used for looping
        returnString.append(spreadArray.getBetsFor(team, i));
        returnString.append(moneylineArray.getBetsFor(team, i));
        returnString.append(overUnderArray.getBetsFor(team, i));
        returnString.append(propArray.getBetsFor(team, i));
    }

    return returnString;
}

/**
 * returns a string containing all bets which have been placed against a certain team. This function calls getEarliestDate()
 * and getLatestDate() in this class, increment() in the Date class, and getBetsAgainst() in the BetList class.
 * @param team - String denoting player/team
 * @return - String contianing all appropriate bet objevts
 */
std::string SportsBetManager::getBetsAgainst(const std::string &team) const {
    Date earliestDate = getEarliestDate();
    Date lastDate = getLatestDate();
    std::string returnString;

    for (Date i = earliestDate; i <= lastDate; i.increment()) { //increment used for looping. See Date Class
        returnString.append(spreadArray.getBetsAgainst(team, i));
        returnString.append(moneylineArray.getBetsAgainst(team, i));
        returnString.append(overUnderArray.getBetsAgainst(team, i));
        returnString.append(propArray.getBetsAgainst(team, i));
    }

    return returnString;
}

/**
 * returns a string containing all bets which have been placed for a certain sport. This function calls getEarliestDate()
 * and getLatestDate() in this class, increment() in the Date class, and getBetsOfSport() in the BetList class.
 * @param spt - String denoting the sport
 * @return - String containing all appropriate bet objects
 */
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

/**
 * Private function which gets the earliest date of any bet held by the manager. This function should not be called
 * if the Manager is empty. This function calls getEarliestDate() and isEmpty() in the BetList class and setDate() in
 * the Date Class
 * @return - Date object of the earliest date
 */
Date SportsBetManager::getEarliestDate() const { //bad access, cant get earliest date from empty objects
    Date earliestDate;

    Date spreadDate, moneyDate, overDate, propDate; //declares 4 Date objects
    spreadDate.setDate(1, 1, 3000); // sets objects to high-end date
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

    if (spreadDate <= moneyDate && spreadDate <= propDate && spreadDate <= overDate) //comparisons
        earliestDate = spreadDate;

    else if (moneyDate <= spreadDate && moneyDate <= propDate && moneyDate <= overDate)
        earliestDate = moneyDate;

    else if (propDate <= moneyDate && propDate <= spreadDate && propDate <= overDate)
        earliestDate = propDate;

    else
        earliestDate = overDate;

    return earliestDate;
}

/**
 * Private function which gets the latest date of any bet held by the manager. This function should not be called
 * if the Manager is empty. This function calls getEarliestDate() and isEmpty() in the BetList class and setDate() in
 * the Date Class
 * @return - Date object of the latest date
 */
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

/**
 * Checks if the Manager contains any bets by calling the isEmpty function in the BetList class
 */
bool SportsBetManager::isEmpty() {
    return spreadArray.isEmpty() && moneylineArray.isEmpty() && overUnderArray.isEmpty() && propArray.isEmpty();
}