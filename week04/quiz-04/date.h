#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;

class Date {
    
    friend ostream & operator<<(ostream & os, const Date date); // can also make the next fields public

    int day, month, year;

    public:
        Date(int _day, int _month, int _year) : day{_day}, month{_month}, year{_year} {}
        void setYear(int _year) { year = _year; }
        int getYear() { return  year; }
         void setMonth(int _month) { month = _month; }
        int getMonth() { return  month; }
        void setDay(int _day) { day = _day; }
        int getDay() { return  day; }        

        void add_days(int _days_to_add) {
            if (day + _days_to_add <= 30) {
                day = day + _days_to_add; // could also use % and other features
            } else {
                day = _days_to_add;
                month += 1;
                if (month > 12) {
                    month = 1;
                    year += 1;
                }
            }
        }

        void IsoOutput() {
            cout << year;
            cout <<  "-";

            if (month < 10) cout << "0" << month;
            else cout << month;
            cout <<  "-";

            if (day < 10) cout << "0" << day;
            else cout << day;
            cout << endl;
        }

};

ostream & operator<<(ostream & os, const Date date) {
    os << date.day << "/" << date.month << "/" << date.year << endl;
    return os;
}


#endif