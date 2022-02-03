//
// Created by Kavi Palmer on 1/4/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_DATE_H
#define SPORTSBETMANAGER_IMPROVED_DATE_H

#include <string>

class Date {
private:

    int day, month, year; //variables denoting todays date

public:

    Date(); //ctor

    Date(int mon, int dy, int yr); //alt ctor

    virtual std::string toString() const; //displays date as a string

    virtual bool equals(const Date &rhs) const; //checks if rhs equals this Date object

    void setDate(int mon, int dy, int yr); //sets the date

    int getYear() const; //returns the year

    int getMonth() const; //returns the month

    int getDay() const; //returns the day

    //operator overloads
    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    bool operator <=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;

    //used in looping, increments the date by one day, updating the month and year when appropriate
    void increment();
};


#endif //SPORTSBETMANAGER_IMPROVED_DATE_H
