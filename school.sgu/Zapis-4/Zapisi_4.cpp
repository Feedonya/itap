#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct Date{
    unsigned short day, month, year, n;
    void input();
    unsigned short month_check(unsigned short month, unsigned short year);
    bool leap_year(unsigned short year);
    void change();
    void output();
};

// файловый ввод
void Date::input(){
    char temp;
    in >> day >> temp >> month >> temp >> year >> n;
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
    return 0;
}

// изменяем дату
void Date::change(){
    // идем на год вперед, если n позволяет
    if (n > 364){
        if (Date::leap_year(year)){
            n -= 366;
        }
        else{
            n -= 365;
        }
    }
    // рассматриваем перемещение в одном году
    else{
        // проходим по году (скорее всего пройдем несколько лишних шагов, но не более, чем 11 операций)
        for (unsigned short i = 0; i < 12; i++){
            unsigned short date;
            date = Date::month_check(month,year);
            while (n > 0){
                // n < чем кол-во дней в месяце
                if (n < date){
                    day += n;
                    break;
                }
                // n > чем кол-во дней в месяце
                else{
                    month++;
                    n -= date - day;
                    day = 1;
                }
            }
        }
    }
}

// файловый вывод
void Date::output(){
    out << setw(2) << setfill('0') << day << '/' << setw(2) << setfill('0') << month << '/' << setw(4) << setfill('0') << year;
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
