//
// Created by Kavi Palmer on 1/10/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_BETLIST_H
#define SPORTSBETMANAGER_IMPROVED_BETLIST_H

#include "Date.h"
#include "SportsBet.h"
#include "LinkedListNode.h"


template <typename T> class BetList {

private:

    int numBets; //number of bets;
    LinkedListNode<T>* betHead; //pointer to head of list

public:

    BetList();

    BetList(const BetList<T> &src);

    BetList<T> &operator=(const BetList &rhs);

    ~BetList();

    int getNumBets() const;

    void addBet(const T &newBet);

    std::string getBetsOnDate(Date &date) const;

    std::string getBetsFor(const std::string &newBet, const Date &date) const; //get all bets for param player/team

    std::string getBetsOfSport(const std::string &spt, const Date &date) const;

    std::string getBetsAgainst(const std::string &newBet, const Date &date) const;

    std::string getAllBets() const;

    Date getEarliestDate() const;

    Date getLastDate()const;

    void deleteAllBets();

    void deleteBetsBefore(const Date &date);

    void deleteBet(const T &oldBet);

    void deleteBetsFor(const std::string &oldBet);

    void deleteBetsAgainst(const std::string &oldBet);

    bool exists(const T &newBet);

    bool isEmpty() const;


};

#include "BetList.cpp"

#endif //SPORTSBETMANAGER_IMPROVED_BETLIST_H
