#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Введите последовательность: ";// вводим строку
    getline(cin, s);

    size_t pos=s.find(' ');//находим пробел
    while (pos != string::npos) {//пока в строке есть пробелы
        
        s=s.substr(pos+1)+ ' ' + s.substr(0,pos);
    }


    cout << "Преобразованная строка: " << s << endl;//выводим измененную строку

    return 0;
}