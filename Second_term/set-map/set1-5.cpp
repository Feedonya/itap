//В текстовом файле даны целые числа, записанные через пробел.
//5) Найти все такие цифры, которые встречаются только в трёхзначных числах.

// 1 2 3 345 238 ->
// 2 3
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\set-map\\input_set1.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\set-map\\output_set1.txt");
//ifstream in("input_set1.txt");
//ofstream out("output_set1.txt");


// Функция для извлечения цифр из числа и добавления их в set
void extractDigits(int number, set<char>& digits){
    string numberStr = to_string(number);
    for (char digit : numberStr){
        digits.insert(digit);
    }
}

// Функция для обработки чисел из файла
void processNumbers(set<char>& threeDigitDigits, set<char>& otherDigits){
    string line;
    while (getline(in, line)){
        stringstream ss(line);
        int number;
        while (ss >> number){
            if (number >= 100 && number <= 999){
                extractDigits(number, threeDigitDigits);
            } else {
                extractDigits(number, otherDigits);
            }
        }
    }

    in.close();
}

// Функция для нахождения уникальных цифр, встречающихся только в трехзначных числах
set<char> findUniqueDigits(const set<char>& threeDigitDigits, const set<char>& otherDigits){
    set<char> uniqueDigits;
    for (char digit : threeDigitDigits){
        if (otherDigits.find(digit) == otherDigits.end()){
            uniqueDigits.insert(digit);
        }
    }
    return uniqueDigits;
}

int main(){
    set<char> threeDigitDigits;
    set<char> otherDigits;

    processNumbers(threeDigitDigits, otherDigits);
    set<char> uniqueDigits = findUniqueDigits(threeDigitDigits, otherDigits);

    for (char digit : uniqueDigits){
        out << digit << ' ';
    }

    return 0;
}