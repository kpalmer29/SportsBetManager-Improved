//
// Created by Kavi Palmer on 1/4/22.
//

#ifndef SPORTSBETMANAGER_IMPROVED_DATE_H
#define SPORTSBETMANAGER_IMPROVED_DATE_H

#include <string>

class Date {
private:

    int day, month, year;

public:

    Date();

    Date(int mon, int dy, int yr);

    virtual std::string toString() const;

    virtual bool equals(const Date &rhs) const;

    void setDate(int mon, int dy, int yr);

    int getYear() const;

    int getMonth() const;

    int getDay() const;

    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    bool operator <=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;

    void increment();
};


#endif //SPORTSBETMANAGER_IMPROVED_DATE_H
