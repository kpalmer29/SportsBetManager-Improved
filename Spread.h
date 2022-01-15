//
// Created by Kavi Palmer on 1/5/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_SPREAD_H
#define SPORTSBETMANAGER_IMPROVED_SPREAD_H


#include "SportsBet.h"

class Spread: public SportsBet {

private:

    bool favorite; //favorite or underdog

    double gameSpread;

public:

    void setSpread(const double &spread);

    void setFavorite(bool fav);

    int getSpread() const;

    std::string getFavorite() const;

    bool equals(const Spread &rhs) const;

    bool operator==(const Spread &rhs) const;

    std::string toString() const;

};


#endif //SPORTSBETMANAGER_IMPROVED_SPREAD_H
