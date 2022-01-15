//
// Created by Kavi Palmer on 1/4/22.
//

#include "Date.h"

Date::Date(): day(0), month(0), year(0) {}

Date::Date(int mon, int dy, int yr): day(dy), month(mon), year(yr) {}

void Date::setDate(int mon, int dy, int yr) {
    if (dy < 1 || dy > 31 || mon < 1 || mon > 12) {
        throw std::invalid_argument("Date not in range");
    }
    day = dy;
    month = mon;
    year = yr;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

std::string Date::toString() const {
    std::string date;
    std::string mon = std::to_string(month);
    std::string dy = std::to_string(day);
    std::string yr = std::to_string(year);
    date = mon + "/" + dy + "/" + yr;
    return date;
}

bool Date::equals(const Date &rhs) const {
    return year == rhs.year && month == rhs.month && day == rhs.day;
}

bool Date::operator==(const Date &rhs) const {
    return year == rhs.year && month == rhs.month && day == rhs.day;
}

bool Date::operator!=(const Date &rhs) const {
    return !(year == rhs.year && month == rhs.month && day == rhs.day);
}

bool Date::operator>(const Date &rhs) const {
    if (year >= rhs.year) {
        if (year > rhs. year)
            return true;
        else if (month >= rhs.month){ //year == rhs.year
            if (month > rhs.month)
                return true;
            else { //month == rhs.month
                if (day > rhs.day)
                    return true;
                else
                    return false;
            }

        }
        else  //rhs.month > month
            return false;
    }
    else //rhs.year > year
        return false;
}

bool Date::operator<(const Date &rhs) const {
    if (year < rhs.year)
        return true;
    else {
        if (year == rhs.year) {
            if (month < rhs.month)
                return true;
            else {
                if (month != rhs.month) //month > rhs.month
                    return false;
                else {
                    if (day < rhs.day)
                        return true;
                    else
                        return false;
                }
            }
        }
        else //year > rhs.year
            return false;
    }
}

bool Date::operator<=(const Date &rhs) const {
    if (year < rhs.year)
        return true;
    else {
        if (year > rhs.year)
            return false;
        else {
            if (month < rhs.month)
                return true;
            else {
                if (month > rhs.month)
                    return false;
                else {
                    return day <= rhs.day;
                }
            }
        }
    }
}

bool Date::operator>=(const Date &rhs) const {
    if (year > rhs.year)
        return true;
    else {
        if (year < rhs.year)
            return false;
        else {
            if (month > rhs.month)
                return true;
            else {
                if (month < rhs.month)
                    return false;
                else {
                    return day >= rhs.day;
                }
            }
        }
    }
}

void Date::increment() {

    if (getMonth() == 2) { //February
        if (getYear() % 4 == 0 ) { //leap year
            if (getDay() < 29) {
                day = getDay() + 1;
            }
            else
                setDate(3, 1, getYear());
        }
        else {
            if (getYear() < 28) {
                day = getDay() + 1;
            }
            else
                setDate(3, 1, getYear());
        }
    }

    else if (getMonth() == 4 || getMonth() == 6 || getMonth() == 9|| getMonth() == 11) { //months w/30 days
        if (getDay() < 30){
            day = getDay() + 1;
        }
        else {
            int newMonth = getMonth() + 1;
            setDate(newMonth, 1, getYear());
        }
    }

    else { //days w 31
        if (getDay() < 31){
            day = getDay() + 1;
        }
        else {
            int newMonth = getMonth() + 1;
            setDate(newMonth, 1, getYear());
        }
    }
}
