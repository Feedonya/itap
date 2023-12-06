#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void processString(const string& input) {
    string tempString = input;//очередь равна нашей строке - проверяем элементы, если подходят по условию - удаляем 
    string word;
    size_t pos = 0;
    int countOfWords = 0;

    while ((pos = tempString.find(' ')) != string::npos){//пока есть пробелы в нашей строке добавляем индексы
        ++countOfWords;

        //tempString.erase(0, pos + 1);
        }
    

}

int main() {
    setlocale(LC_ALL,"Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    getline(cin, input);
    processString(input);

    return 0;
}
/*
test_input:
1) cat road vehicle crash
2) судьба злодейка пес батарейка

test_output:
1) vehicle crash cat road
2) пес батарейка судьба злодейка
*/