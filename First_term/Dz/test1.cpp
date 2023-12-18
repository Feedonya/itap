#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void processString(const string& input) {
    string tempString = input;//очередь равна нашей строке - проверяем элементы, если подходят по условию - удаляем 
    string word;
    size_t pos = 0;

    while ((pos = tempString.find(' ')) != string::npos){//пока есть пробелы в нашей строке
        word = tempString.substr(0, pos);//слово
        if (word[0] == word[word.length() - 1]){//если первый элемент выделенного из строки слова равен последнему элементу слова
            tempString.erase(0, pos + 1);//удаляем слово из строки
        }
        else{
            cout << word << " ";//иначе выводим это слово и удаляем из очереди
            tempString.erase(0, pos + 1);
        }
    }

    if (tempString[0] != tempString[tempString.length() - 1]){
        cout << tempString << endl;
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
1) hello level kayak world
2) зима акула собака ломал кидать

test_output:
1) hello world
2) зима собака кидать
*/