//
// Created by Kavi Palmer on 1/9/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_LINKEDLISTNODE_H
#define SPORTSBETMANAGER_IMPROVED_LINKEDLISTNODE_H

template <typename T> class BetList;


template <typename T> class LinkedListNode {

public:

    ~LinkedListNode(); //destructor

    explicit LinkedListNode(const T& newBet = T());

private:
    friend class BetList<T>;

    T bet; //holds bet object
    LinkedListNode<T>* next; //Node pointer to next object

    LinkedListNode(const T& newBet, LinkedListNode<T>* newPtr);




};

#include "LinkedListNode.cpp"


#endif //SPORTSBETMANAGER_IMPROVED_LINKEDLISTNODE_H
