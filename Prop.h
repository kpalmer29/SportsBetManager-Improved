//
// Created by Kavi Palmer on 1/8/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_PROP_H
#define SPORTSBETMANAGER_IMPROVED_PROP_H


#include "SportsBet.h"

class Prop: public SportsBet {
private:

    std::string propType; //points, rebounds, etc

    double propLine;

    bool over;

public:

    void setOver(bool under);

    bool isOver() const;

    void setPropType(const std::string &type);

    void setPropLine(const double &line);

    std::string getPropType() const;

    double getPropLine() const;

    bool equals(const Prop &rhs) const;

    bool operator==(const Prop &rhs) const;

    std::string toString() const;
};


#endif //SPORTSBETMANAGER_IMPROVED_PROP_H
