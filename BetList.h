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

    BetList(); //constructor

    BetList(const BetList<T> &src); //overload ctor

    BetList<T> &operator=(const BetList &rhs); //assignment op

    ~BetList(); //destructor

    int getNumBets() const; //return number of bets held by BetList

    void addBet(const T &newBet); //add a bet to BetList

    std::string getBetsOnDate(Date &date) const; //return all bets on a date

    std::string getBetsFor(const std::string &newBet, const Date &date) const; //get all bets for param player/team

    std::string getBetsOfSport(const std::string &spt, const Date &date) const; //get all bets of a certain sport

    std::string getBetsAgainst(const std::string &newBet, const Date &date) const; //get all bets against a param team

    std::string getAllBets() const; //get all bets

    Date getEarliestDate() const; //get date of earliest bet

    Date getLastDate()const; //get date of latest bet

    void deleteAllBets(); //delete all bets in BetList

    void deleteBetsBefore(const Date &date); //delete all bets before a given date

    void deleteBet(const T &oldBet); //delete a given bet from BetList

    void deleteBetsFor(const std::string &oldBet); //delete all bets for a certain team

    void deleteBetsAgainst(const std::string &oldBet); //delete all bets against a certain team

    bool exists(const T &newBet); //check if a bet exists in BetList

    bool isEmpty() const; //check if BetList contains any bets

};

#include "BetList.cpp"

#endif //SPORTSBETMANAGER_IMPROVED_BETLIST_H
