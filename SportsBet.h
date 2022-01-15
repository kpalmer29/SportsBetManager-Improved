//
// Created by Kavi Palmer on 1/4/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_SPORTSBET_H
#define SPORTSBETMANAGER_IMPROVED_SPORTSBET_H

#include "Date.h"

class SportsBet {
private:

    int odds;

    char oddsSymbol;

    Date gameDate;

    std::string sport;

    std::string betFor; //team/player betting for

    std::string betAgainst; //teambetagainst

public:

    char getOddsSymbol() const;

    void setOddsSymbol(const char &od);

    int getOdds() const;

    void setOdds(const int &od);

    Date getDate() const;

    void setDate(const int &day, const int &month, const int &year);

    std::string getSport() const;

    void setSport(const std::string &spt);

    std::string getFor() const;

    void setBetFor(const std::string &team);

    std::string getAgainst() const;

    void setBetAgainst(const std::string &team);

    virtual std::string toString();

    virtual bool equals(const SportsBet &rhs) const;

    virtual bool operator==(const SportsBet &rhs) const;
};


#endif //SPORTSBETMANAGER_IMPROVED_SPORTSBET_H
