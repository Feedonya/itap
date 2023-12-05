#include <iostream>
#include <string>

using namespace std;

void insertStringAfterChar(string& mainStr, char c, const string& insertStr) {
    size_t pos = mainStr.find(c);//первое вхождение
    while (pos != string::npos) {//пока в строке есть символ
        mainStr.insert(pos + 1, insertStr);//вставляем элемент после символа
        pos = mainStr.find(c, pos + insertStr.length() + 1);//для поиска следующего символа
    }
}

int main() {
    char c;
    string mainStr, insertStr;

    cout << "Введите последовательность: ";
    getline(cin, mainStr);

    cout << "Введите строку для вставки: ";
    getline(cin, insertStr);

    cout << "Введите символ для поиска в строке: ";
    cin >> c;

    insertStringAfterChar(mainStr, c, insertStr);

    cout << "Преобразованная строка: " << mainStr << endl;

    return 0;
}
/*
tgues vfksgfvikkgjfxjdkjzsgcgzsjfzshjfwh
123
g

tg123ues vfksg123fvikkg123jfxjdkjzsg123cg123zsjfzshjfwh
*/