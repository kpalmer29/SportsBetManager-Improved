//
// Created by Kavi Palmer on 1/12/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_SPORTSBETMANAGER_H
#define SPORTSBETMANAGER_IMPROVED_SPORTSBETMANAGER_H

#include "BetList.h"
#include "SportsBet.h"
#include "Spread.h"
#include "OverUnder.h"
#include "Prop.h"

class SportsBetManager {

private:

    BetList<SportsBet> moneylineArray; //Linked List to hold Moneyline bets

    BetList<Spread> spreadArray; //Linked list to hold Spread objects

    BetList<OverUnder> overUnderArray; //Linked list to hold OverUnder objects

    BetList<Prop> propArray; //Linked list to hold Prop objects

    Date getEarliestDate() const; //private function which returns the earliest date of a stored bet

    Date getLatestDate() const; //private function which returns the latest date of a stored bet

public:

    SportsBetManager(); //constructor

    void addSpreadBet(const Spread &newBet); //add bet to spreadArray

    void addMoneylineBet( const SportsBet &newBet); //add bet to moneylineArray

    void addPropBet(const Prop &newBet); //add bet to propArray

    void addOverUnderBet(const OverUnder &newBet); //add bet to overUnderArray

    std::string getBetsOnDate(Date date) const; //return all bets on a certain date

    std::string getBetsFor(const std::string &team) const; //get all bets for param player/team

    std::string getBetsOfSport(const std::string &spt) const; //get all bets of a certain sport

    std::string getBetsAgainst(const std::string &team) const; //get all bets placed against a team

    std::string getAllBets() const; //get all bets held by the Manager

    std::string getAllPropBets() const; //return all bets held by propArray

    void deleteAllBets(); //delete all bets held by the Manager

    void deleteBetsBefore(const Date &date); //delete all bets before a certain date

    void deleteMoneylineBet(const SportsBet &oldBet); //delete a bet from moneylineArray

    void deleteSpreadBet(const Spread &oldBet); //delete a bet from spreadArray

    void deletePropBet(const Prop &oldBet); //delete a bet from propArray

    void deleteOverUnderBet(const OverUnder &oldBet); //delete a bet from overUnderArray

    void deleteBetsFor(const std::string &oldBet); //delete all bets placed for a certain player/team

    void deleteBetsAgainst(const std::string &oldBet); //delete all bets placed against a team

    bool isEmpty(); //return if the manager contains any bets

};


#endif //SPORTSBETMANAGER_IMPROVED_SPORTSBETMANAGER_H
