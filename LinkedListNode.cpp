//
// Created by Kavi Palmer on 1/9/22.
//


template <typename T>
LinkedListNode<T>::~LinkedListNode() {
    next = nullptr;
}

template <typename T>
LinkedListNode<T>::LinkedListNode(const T &newBet): bet(newBet) {
    next = this;
}

template <typename T>
LinkedListNode<T>::LinkedListNode(const T &newBet, LinkedListNode<T> *newPtr): bet(newBet), next(newPtr) {}

