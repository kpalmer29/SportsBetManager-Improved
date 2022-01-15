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

    void setOver(bool under);

    void setPoints(const double &line);

    double getPoints() const;

    bool isOver() const;

    bool equals(const OverUnder &rhs) const;

    bool operator==(const OverUnder &rhs) const;

    std::string toString() const;

};



#endif //SPORTSBETMANAGER_IMPROVED_OVERUNDER_H
