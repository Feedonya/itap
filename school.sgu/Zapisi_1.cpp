#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct Date{
    unsigned short day, month, year;
    void input();
    unsigned short month_check(unsigned short month, unsigned short year);
    bool leap_year(unsigned short year);
    void change();
    void output();
};

// файловый ввод
void Date::input(){
    char temp;
    in >> day >> temp >> month >> temp >> year;
    //cout << day << month << year;
}

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
}

// изменяем дату
void Date::change(){
    if (day > 1){
        day--;
    }
    else if ((day == 1) && (month > 1)){
        day = month_check(--month, year);
    }
    else if ((day == 1) && (month == 1)){
        month = 12;
        day = month_check(month, year--);
    }
}

// файловый вывод
void Date::output(){
    //cout << day << month << year;
    out << day << '/' << month << '/' << year;
}

int main(){
    Date dat;
    dat.input();
    dat.change();
    dat.output();

    in.close();
    out.close();
    return 0;
}