#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct Date {
    unsigned short day, month, year;

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int month, int year) {
        switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        default:
            return 31;
        }
    }

    void output() {
        cout << setw(2) << setfill('0') << day << "/" << setw(2) << month << "/" << year << endl;
        out << setw(2) << setfill('0') << day << "/" << setw(2) << month << "/" << year << endl;
    }

    void nextDay() {
        if (day == daysInMonth(month, year)) {
            day = 1;
            if (month == 12) {
                month = 1;
                year++;
            }
            else {
                month++;
            }
        }
        else {
            day++;
        }
    }

    void nextNDays(int m) {
        for (int i = 0; i < m; i++) {
            nextDay();
        }
    }
};

void input(Date &date, int& m) {
    char temp;

    in >> date.day >> temp >> date.month >> temp >> date.year;
    in >> m;
}

int main() {
    Date dat = {};
    int m;
    input(dat, m);
    dat.nextNDays(m);
    dat.output();

    in.close();
    out.close();
    return 0;
}