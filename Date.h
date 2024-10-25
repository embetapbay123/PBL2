#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if (!isValid()) {
            day = 1, month = 1, year = 2000;
        }
    }
    Date(const string& s) {
        string temp = s;
        string dayStr = extractField(temp, '/');
        string monthStr = extractField(temp, '/');
        string yearStr = temp;
        day = toInt(dayStr);
        month = toInt(monthStr);
        year = toInt(yearStr);
        if (!isValid()) {
            day = 1, month = 1, year = 2000;
        }
}
    Date(const time_t& time) {
        tm* tm = localtime(&time);
        day = tm->tm_mday;
        month = tm->tm_mon + 1; 
        year = tm->tm_year + 1900; 
    }

    static string toString(int number, int len) {
        string result = "";
        while (number > 0) {
            result = static_cast<char>((number % 10) + '0') + result;
            number /= 10;
        }
        while (result.length() < len) {
            result = '0' + result;
        }
        return result;
    }

    string info() const {
        string result = "";
        result += toString(day, 2) + "/";
        result += toString(month, 2) + "/";
        result += toString(year, 4) ;
        return result;
    }
    
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    
    int daysInMonth(int m, int y) const {
        static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && isLeapYear(y)) return 29; // Tháng 2 năm nhuận có 29 ngày
        return daysInMonth[m - 1];
    }
    int daysSinceStart() const;

    int diff(const Date& other) const {
        return other.daysSinceStart() - this->daysSinceStart();
    }

    bool isValid() const {
        if (month < 1 || month > 12) return false; // Kiểm tra tháng
        if (day < 1 || day > daysInMonth(month, year)) return false; // Kiểm tra ngày
        return true;
    }
};

int Date::daysSinceStart() const {
    int totalDays = 0;
    for (int y = 1; y < year; ++y) totalDays += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < month; ++m) totalDays += daysInMonth(m, year);
    totalDays += day;
    return totalDays;
}

#endif