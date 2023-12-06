#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void processString(const string& input) {
    string tempString = input;//очередь равна нашей строке - проверяем элементы, если подходят по условию - удаляем 
    string word;
    size_t pos = 0;
    int count = 0;

    for (int i = 0; i < tempString.length(); i++)//подсчитываем кол-во пробелов
        if (tempString[i] == ' ')
            count++;

    pos = tempString.find(" ", pos + 1);//ищем первый пробел
    for (int i = 0; i < count; ++i){//пока есть пробелы в нашей строке
        tempString += " " + tempString.substr(0, pos);//слово
        tempString.erase(0, pos + 1);//удаляем слово из строки
        pos = tempString.find(" ", pos + 1);//ищем последующие пробелы
    }

    cout << tempString;//выводим
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
//hello level kayak world -> kayak world hello level