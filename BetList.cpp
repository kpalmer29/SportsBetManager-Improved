//
// Created by Kavi Palmer on 1/10/22.
//

#include "BetList.h"


template <typename T>
BetList<T>::BetList(): numBets(0), betHead(nullptr) {}

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

template <typename T>
BetList<T>::~BetList() {
    while (betHead != nullptr) {
        LinkedListNode<T>* temp = betHead;
        betHead = betHead -> next;
        delete temp;
    }
}

template <typename T>
int BetList<T>::getNumBets() const {
    return numBets;
}

template <typename T>
void BetList<T>::addBet(const T &newBet) {
    if (exists(newBet))
        throw std::invalid_argument("Bet Already Exists");


    LinkedListNode<T>* temp = new LinkedListNode<T>;
    temp -> bet = newBet;
    temp -> next = nullptr;

    if (numBets == 0)
        betHead = temp;

    else {

        Date newDate = newBet.getDate();

        if (newDate < betHead -> bet.getDate()) {
            temp->next = betHead;
            betHead = temp;
        }

        else {
            LinkedListNode<T>* temp2 = betHead;
            while (temp2 != nullptr && temp2 -> bet.getDate() <= newDate) {
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

template <typename T>
bool BetList<T>::exists(const T &newBet) {
    if (numBets == 0)
        return false;

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) {
        if (temp -> bet == newBet)
            return true;
        temp = temp -> next;
    }
    return false;
}

template <typename T>
std::string BetList<T>::getBetsOnDate(Date &date) const {
    std::string returnString;
    int numBetsOnDate = 0; //counter

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) {
        if (temp->bet.getDate() == date) {
            returnString.append(temp->bet.toString() + "\n"); //add bet to returnString
            numBetsOnDate++;
        }
        temp = temp -> next;
    }

    if (numBetsOnDate == 0)
        return "None";

    else
        return returnString;
}

template <typename T>
std::string BetList<T>::getBetsAgainst(const std::string &newBet, const Date &date) const {

    std::string returnString;
    int numBetsAgainst = 0; //counter

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) {
        if (temp -> bet.getAgainst() == newBet && temp -> bet.getDate() == date) {
            returnString.append(temp->bet.toString() + "\n"); //append bet to returnString
            numBetsAgainst++;
        }
        temp = temp -> next;
    }

        return returnString;
}

template <typename T>
std::string BetList<T>::getBetsOfSport(const std::string &spt, const Date &date) const {

    std::string returnString;
    int numBetsOfSport = 0; //counter

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) {
        if (temp -> bet.getSport() == spt && temp -> bet.getDate() == date) {
            returnString.append(temp->bet.toString() + "\n");
            numBetsOfSport++;
        }
        temp = temp -> next;
    }

        return returnString;
}

template <typename T>
std::string BetList<T>::getBetsFor(const std::string &newBet, const Date &date) const {

    std::string returnString;
    int numBetsFor = 0; //counter

    LinkedListNode<T>* temp = betHead;

    while (temp != nullptr) {
        if (temp -> bet.getFor() == newBet && temp -> bet.getDate() == date) {
            returnString.append(temp->bet.toString() + "\n");
            numBetsFor++;
        }
        temp = temp -> next;
    }

        return returnString;
}

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

template <typename T>
void BetList<T>::deleteAllBets() {
    numBets = 0;
    betHead = nullptr;
}

template <typename T>
void BetList<T>::deleteBet(const T &oldBet) {
    if (!exists(oldBet))
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

template <typename T>
void BetList<T>::deleteBetsFor(const std::string &oldBet) {
    if (numBets == 0)
        throw std::invalid_argument("Manager is empty");

    LinkedListNode<T>* curr;

    for (curr = betHead; curr != nullptr; curr = curr -> next) {
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

template <typename T>
void BetList<T>::deleteBetsBefore(const Date &date) {
    if (numBets == 0)
        throw std::invalid_argument("Manager is empty");

    LinkedListNode<T>* temp;
    temp = betHead;
    if (temp->bet.getDate() < date) {

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

template <typename T>
Date BetList<T>::getEarliestDate() const {
    return betHead->bet.getDate();
}

template <typename T>
Date BetList<T>::getLastDate() const {
    LinkedListNode<T>* temp = betHead;
    while (temp ->next != nullptr) {
        temp = temp ->next;
    }
    return temp ->bet.getDate();
}

template <typename T>
bool BetList<T>::isEmpty() const {
    if (numBets == 0)
        return true;
    else
        return false;
}