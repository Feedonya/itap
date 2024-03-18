#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\school.sgu\\Zapis-4\\input.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\school.sgu\\Zapis-4\\output.txt");

struct Date {
    unsigned short day, month, year;

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

<<<<<<< HEAD
// возвращает true, если високосный год, false иначе
bool Date::leap_year(unsigned short year){
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

// возвращает количество дней в месяце
unsigned short Date::month_check(unsigned short month, unsigned short year){
    if((month == 2) && (leap_year(year))){
        return 29;
    }
    if ((month == 2) && (!leap_year(year))){
        return 28;
    }
    if ((month >= 3) && (month <= 7)){
        return 30 + (month % 2);
    }
    if ((month >= 8) && (month <= 11)){
        return 31 - (month % 2);
    }
    if ((month == 1) || (month == 12)){
        return 31;
    }
    return 0;
}

// изменяем дату
void Date::change(){
    while (n > 0){
        if (day == month_check(month,year)){
            day = 1;
            month++;
        }
        if (month == 13){
            year++;
            month = 1;
            break;
        }
        day++;
        n--;
    }

    /*
    while (n > 0){
    // идем на год вперед, если n позволяет
    if (n > 364){
        if (Date::leap_year(year)){
            n -= 366;
        }
        else{
            n -= 365;
=======
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
>>>>>>> 38a22907ace337723eea2879b427780bc2e4585b
        }
        year++;
    }
<<<<<<< HEAD
    // рассматриваем перемещение в одном году
    else{
        // проходим по году (скорее всего пройдем несколько лишних шагов, но не более, чем 11 операций)
        for (unsigned short i = 0; i < 12; i++){
            unsigned short date;
            date = Date::month_check(month,year);
            if (month > 12){
                year++;
                month = 1;
            }
            while (n > 0){
                if (n + day == date){
                    day = date;
                    n = 0;
                    break;
                }
                // n < чем кол-во дней в месяце
                if (n < date - day){
                    day += n;
                    n = 0;
                    break;
                }
                // n == чем кол-во дней в месяце
                else if (date == day){
                    month++;
                    n--;
                    day = 1;
                }
                // n > чем кол-во дней в месяце
                else{
                    month++;
                    n -= date - day;
                    day = 1;
                }
=======

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
>>>>>>> 38a22907ace337723eea2879b427780bc2e4585b
            }
        }
        else {
            day++;
        }
    }
<<<<<<< HEAD
    }
    */
=======

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
>>>>>>> 38a22907ace337723eea2879b427780bc2e4585b
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