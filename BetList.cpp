//
// Created by Kavi Palmer on 1/10/22.
//

#include "BetList.h"

//ctor
template <typename T>
BetList<T>::BetList(): numBets(0), betHead(nullptr) {}

//overload ctor
template <typename T>
BetList<T>::BetList (const BetList<T> &src): numBets(src.numBets), betHead(nullptr) {
    if (src.betHead != nullptr) {
        betHead = new LinkedListNode<T>;
        betHead -> bet = src.betHead -> bet;
        betHead->next = nullptr;
        LinkedListNode<T> *newPtr = betHead;
        LinkedListNode<T> *original = src.betHead;
        while (original->next != nullptr) {
            original = original->next;
            newPtr->next = new LinkedListNode<T>;
            newPtr = newPtr->next;
            newPtr->bet = original->bet;
        }
        newPtr->next = nullptr;
    }
}

//assignment op
template <typename T>
BetList<T>& BetList<T>::operator=(const BetList &rhs) {
    if (this != &rhs) {
        BetList<T> temp;
        temp.betHead = rhs.betHead;
        LinkedListNode<T>* tempPtr = temp.betHead;
        LinkedListNode<T>* rhsPtr = rhs.betHead;
        while (rhsPtr != nullptr) {
            tempPtr->bet = rhsPtr ->bet;
            tempPtr->next = rhsPtr -> next;
            tempPtr = tempPtr ->next;
            rhsPtr = rhsPtr -> next;
        }
    }
    return *this;
}

//destructor
template <typename T>
BetList<T>::~BetList() {
    while (betHead != nullptr) {
        LinkedListNode<T>* temp = betHead;
        betHead = betHead -> next;
        delete temp;
    }
}

/**
 * Returns the number of bets held by BetList
 * @return - numBets
 */
template <typename T>
int BetList<T>::getNumBets() const {
    return numBets;
}

/**
 * adds a bet to BetList. Bets are added in order of their Date. If the bet already exists in the BetList an exception
 * is thrown.
 *
 * @param newBet - Bet Objects to add
 */
template <typename T>
void BetList<T>::addBet(const T &newBet) {
    if (exists(newBet)) //bet already exists
        throw std::invalid_argument("Bet Already Exists");


    LinkedListNode<T>* temp = new LinkedListNode<T>; //create node to hold new bet
    temp -> bet = newBet;
    temp -> next = nullptr;

    if (numBets == 0) //edge case
        betHead = temp;

    else {

        Date newDate = newBet.getDate();

        if (newDate < betHead -> bet.getDate()) { //edge case, bet should be inserted at front of list
            temp->next = betHead;
            betHead = temp;
        }

        else {
            LinkedListNode<T>* temp2 = betHead;
            while (temp2 != nullptr && temp2 -> bet.getDate() <= newDate) { //move temp2 to insertion point
                temp2 = temp2 -> next;
            }
            LinkedListNode<T>* prev = betHead;

            if (temp2  == nullptr) { //new bet should be inserted at end of list
                while (prev ->next != nullptr) {
                    prev = prev -> next;
                }
            }

            else {
                while (prev -> next != temp2) { //moves prev to one before temp2
                    prev = prev -> next;
                }

            }

            temp -> next = prev -> next;
            prev -> next = temp;
        }
    }
    numBets++;
}

/**
 * checks if a bet exists in BetList
 * @param newBet - bet to check existence of
 * @return - true if bet exists, false if it doesn't
 */
template <typename T>
bool BetList<T>::exists(const T &newBet) {
    if (numBets == 0) //BetList empty
        return false;

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) { //iterate through linked list
        if (temp -> bet == newBet) //bet exists
            return true;
        temp = temp -> next;
    }
    return false;
}

/**
 * returns a string of all bets held by BetList which occur on a certain date.
 *
 * @param date - Date object
 * @return - Stirng object containing appropriate bets
 */
template <typename T>
std::string BetList<T>::getBetsOnDate(Date &date) const {
    std::string returnString;
    int numBetsOnDate = 0; //counter

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) { //iterate through BetList
        if (temp->bet.getDate() == date) { //check
            returnString.append(temp->bet.toString() + "\n"); //add bet to returnString
            numBetsOnDate++;
        }
        temp = temp -> next;
    }

    if (numBetsOnDate == 0) //no bets exist on given date
        return "None";

    else
        return returnString;
}

/**
 * Returns a String of all bets placed against a given team which occur on a certain date.
 * @param newBet - String of team to check bet against
 * @param date - Date object
 * @return - String of all bets on a given date placed against a given team.
 */
template <typename T>
std::string BetList<T>::getBetsAgainst(const std::string &newBet, const Date &date) const {

    std::string returnString;
    int numBetsAgainst = 0; //counter

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) { //iterate through BetList
        if (temp -> bet.getAgainst() == newBet && temp -> bet.getDate() == date) {
            returnString.append(temp->bet.toString() + "\n"); //append bet to returnString
            numBetsAgainst++;
        }
        temp = temp -> next;
    }

        return returnString;
}
/**
 * Returns a String of all bets placed for a sport which occur on a certain date.
 * @param spt - String of sport
 * @param date - Date object
 * @return - String of all bets on a given date for a given sport.
 */
template <typename T>
std::string BetList<T>::getBetsOfSport(const std::string &spt, const Date &date) const {

    std::string returnString;
    int numBetsOfSport = 0; //counter

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) { //iterate through BetList
        if (temp -> bet.getSport() == spt && temp -> bet.getDate() == date) {
            returnString.append(temp->bet.toString() + "\n");
            numBetsOfSport++;
        }
        temp = temp -> next;
    }

        return returnString;
}

/**
 * Returns a String of all bets placed for a given team which occur on a certain date.
 * @param newBet - String of team to check bet for
 * @param date - Date object
 * @return - String of all bets on a given date placed for a given team.
 */
template <typename T>
std::string BetList<T>::getBetsFor(const std::string &newBet, const Date &date) const {

    std::string returnString;
    int numBetsFor = 0; //counter

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) { //iterate through BetList
        if (temp -> bet.getFor() == newBet && temp -> bet.getDate() == date) {
            returnString.append(temp->bet.toString() + "\n");
            numBetsFor++;
        }
        temp = temp -> next;
    }

        return returnString;
}

/**
 * returns a string containing all bets held by BetList
 *
 * @return - string of bets
 */
template <typename T>
std::string BetList<T>::getAllBets() const {

    std::string returnString;

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) {
        returnString.append(temp->bet.toString() + "\n");
        temp = temp -> next;
    }

    return returnString;
}

/**
 * sets betHead equal to nullpoint and resets numBets. Sets empty BetList object
 */
template <typename T>
void BetList<T>::deleteAllBets() {
    numBets = 0;
    betHead = nullptr;
}

/**
 * Deletes a certain bet from the Manager. Throws an exception if that bet does not exist
 * @param oldBet - Template Object will be a bet type
 */
template <typename T>
void BetList<T>::deleteBet(const T &oldBet) {
    if (!exists(oldBet)) //bet does not exist
        throw std::invalid_argument("Bet does not exist in current Manager");

    if (betHead->bet == oldBet) //bet for deletion is first bet in Manager.
        betHead = betHead->next;

    else {

        LinkedListNode<T> *temp;

        for (temp = betHead; temp != nullptr; temp = temp->next) {
            if (temp->bet == oldBet) { //temp points to node to be deleted
                LinkedListNode<T> *prev = betHead;
                while (prev->next != temp) { //move prev to one before temp
                    prev = prev->next;
                }

                prev->next = temp->next; //assignment

            }
        }
    }
    numBets--;
}

/**
 * Deletes all bets placed for a certain player/team. Throws an exception if the BetList is empty
 * @param oldBet - String of player/team
 */
template <typename T>
void BetList<T>::deleteBetsFor(const std::string &oldBet) {
    if (numBets == 0) //empty list
        throw std::invalid_argument("List is empty");

    LinkedListNode<T>* curr;

    for (curr = betHead; curr != nullptr; curr = curr -> next) { //iterate through list
        if (curr->bet.getFor() == oldBet) { //if curr is pointed towards a node to be deleted
            if (betHead == curr) //base case
                betHead = curr -> next;
            else {
                LinkedListNode<T>* prev;
                for (prev = betHead; prev -> next != curr; prev = prev -> next) {}//move ptr to one before curr
                prev->next = curr -> next;
            }
            numBets--;
        }
    }
}

/**
 * Deletes all bets placed against a certain player/team. Throws an exception if the BetList is empty
 * @param oldBet - String of player/team
 */
template <typename T>
void BetList<T>::deleteBetsAgainst(const std::string &oldBet) {
    if (numBets == 0)
        throw std::invalid_argument("Manager is empty");

    LinkedListNode<T>* curr;

    for (curr = betHead; curr != nullptr; curr = curr -> next) {
        if (curr->bet.getAgainst() == oldBet) { //if curr is pointed towards a node to be deleted
            if (betHead == curr) //base case
                betHead = curr -> next;
            else {
                LinkedListNode<T>* prev;
                for (prev = betHead; prev -> next != curr; prev = prev -> next) {}//move ptr to one before curr
                prev->next = curr -> next;
            }
            numBets--;
        }
    }
}

/**
 * Deletes all bets placed before a certain date.  Throws an exception if the BetList is empty
 * @param date - Date object
 */
template <typename T>
void BetList<T>::deleteBetsBefore(const Date &date) {
    if (numBets == 0)
        throw std::invalid_argument("Manager is empty");

    LinkedListNode<T>* temp;
    temp = betHead;
    if (temp->bet.getDate() < date) { //checks that the earliest date is before param date

        int counter = 0;
        while (temp-> bet.getDate() < date) {
            temp = temp -> next;
            counter++;
        }
        //temp now pointing to first node whose date is >= param
        betHead = temp;
        numBets = numBets - counter;

    }
}

/**
 * Returns date of first bet in linked list
 * @return - Date of first bet
 */
template <typename T>
Date BetList<T>::getEarliestDate() const {
    return betHead->bet.getDate();
}

/**
 * returns date of last bet in linked list
 * @return - Date of last bet
 */
template <typename T>
Date BetList<T>::getLastDate() const {
    LinkedListNode<T>* temp = betHead;
    while (temp ->next != nullptr) { //iterate to last object in linked list
        temp = temp ->next;
    }
    return temp ->bet.getDate();
}

/**
 * Checks if BetList is empty
 * @return - true if empty, false if not
 */
template <typename T>
bool BetList<T>::isEmpty() const {
    return numBets == 0;
}