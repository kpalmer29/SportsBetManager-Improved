//
// Created by Kavi Palmer on 1/4/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_SPORTSBET_H
#define SPORTSBETMANAGER_IMPROVED_SPORTSBET_H

#include "Date.h"

class SportsBet {
private:

    int odds; //odds of bet

    char oddsSymbol; //direction of odds ('+' or '-')

    Date gameDate; //date of bet

    std::string sport; //what sport the bet is for

    std::string betFor; //team/player betting for

    std::string betAgainst; //team/player betting against

public:

    char getOddsSymbol() const; //return oddsSymbol

    void setOddsSymbol(const char &od); //set oddsSymbol

    int getOdds() const; //return odds

    void setOdds(const int &od); //set odds

    Date getDate() const; //return gameDate

    void setDate(const int &day, const int &month, const int &year); //set gameDate

    std::string getSport() const; //return sport

    void setSport(const std::string &spt); //set sport

    std::string getFor() const; //return betFor

    void setBetFor(const std::string &team); //set betFor

    std::string getAgainst() const; //return betAgainst

    void setBetAgainst(const std::string &team); //set betAgainst

    virtual std::string toString(); //display SportsBet object as a String.

    virtual bool equals(const SportsBet &rhs) const; //checks if param SportsBet is equal to this

    virtual bool operator==(const SportsBet &rhs) const; //operator overload
};


#endif //SPORTSBETMANAGER_IMPROVED_SPORTSBET_H
