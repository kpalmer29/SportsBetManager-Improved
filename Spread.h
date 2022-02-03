//
// Created by Kavi Palmer on 1/5/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_SPREAD_H
#define SPORTSBETMANAGER_IMPROVED_SPREAD_H


#include "SportsBet.h"

class Spread: public SportsBet {

private:

    bool favorite; //true if betting over the spread, false otherwise

    double gameSpread; //spread of the game

public:

    void setSpread(const double &spread); //set the game spread

    void setFavorite(bool fav); //set whether betting over or under the spread

    double getSpread() const; //returns the game spread

    std::string getFavorite() const; //returns whether betting over or under the spread

    bool equals(const Spread &rhs) const; //checks if rhs equals this object

    bool operator==(const Spread &rhs) const; //operator overload

    std::string toString() const; //displays Spread bet as a string

};


#endif //SPORTSBETMANAGER_IMPROVED_SPREAD_H
