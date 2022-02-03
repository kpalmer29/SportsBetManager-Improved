//
// Created by Kavi Palmer on 1/8/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_OVERUNDER_H
#define SPORTSBETMANAGER_IMPROVED_OVERUNDER_H


#include "SportsBet.h"


class OverUnder: public SportsBet {

private:

    bool over; //true if over, false if under

    double points; //point line for over/under

public:

    void setOver(bool under); //set if betting over or under point total

    void setPoints(const double &line); //set point total

    double getPoints() const; //get point total

    bool isOver() const; //get if betting over or under point total

    bool equals(const OverUnder &rhs) const; //checks if rhs is equal to this object

    bool operator==(const OverUnder &rhs) const; //operator overload

    std::string toString() const; //display OverUnder bet to a string

};



#endif //SPORTSBETMANAGER_IMPROVED_OVERUNDER_H
