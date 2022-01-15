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

    BetList<SportsBet> moneylineArray;

    BetList<Spread> spreadArray;

    BetList<OverUnder> overUnderArray;

    BetList<Prop> propArray;

    Date getEarliestDate() const;

    Date getLatestDate() const;

public:

    SportsBetManager();

    void addSpreadBet(const Spread &newBet);

    void addMoneylineBet( const SportsBet &newBet);

    void addPropBet(const Prop &newBet);

    void addOverUnderBet(const OverUnder &newBet);

    std::string getBetsOnDate(Date date) const;

    std::string getBetsFor(const std::string &team) const; //get all bets for param player/team

    std::string getBetsOfSport(const std::string &spt) const;

    std::string getBetsAgainst(const std::string &team) const;

    std::string getAllBets() const;

    std::string getAllPropBets() const;

    void deleteAllBets();

    void deleteBetsBefore(const Date &date);

    void deleteMoneylineBet(const SportsBet &oldBet);

    void deleteSpreadBet(const Spread &oldBet);

    void deletePropBet(const Prop &oldBet);

    void deleteOverUnderBet(const OverUnder &oldBet);

    void deleteBetsFor(const std::string &oldBet);

    void deleteBetsAgainst(const std::string &oldBet);

    bool isEmpty();

};


#endif //SPORTSBETMANAGER_IMPROVED_SPORTSBETMANAGER_H
