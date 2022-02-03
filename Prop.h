//
// Created by Kavi Palmer on 1/8/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_PROP_H
#define SPORTSBETMANAGER_IMPROVED_PROP_H


#include "SportsBet.h"

class Prop: public SportsBet {
private:

    std::string propType; //points, rebounds, etc

    double propLine; //prop line: i.e. 8.5

    bool over; //betting over or under prop line

public:

    void setOver(bool under); //set if betting over or under prop line

    bool isOver() const; //return if betting over or under prop line

    void setPropType(const std::string &type); //set the prop type

    void setPropLine(const double &line); //set the prop line

    std::string getPropType() const; //return the prop type

    double getPropLine() const; //return the prop line

    bool equals(const Prop &rhs) const; //checks if rhs is equal to this

    bool operator==(const Prop &rhs) const; //operator overload

    std::string toString() const; //display Prop as a string
};


#endif //SPORTSBETMANAGER_IMPROVED_PROP_H
