#include <iostream>
#include <string>

using namespace std;

void insertSubstring(string& str, const string& str1, const string& str2) {
    /*
    1. Принимаем строку и подстроку, которую нужно вставить, а также индекс, на котором нужно вставить подстроку.
    2. Создаем новую строку, в которую копируем все символы из исходной строки до указанной позиции.
    3. Добавляем подстроку в новую строку.
    4. Добавляем оставшуюся часть исходной строки после указанной позиции в новую строку.
    */
    size_t pos = 0;
    while ((pos = str.find(str1, pos)) != string::npos){//  пока мы находим подстроку (пока .find() != -1)
        str.insert(pos + str1.length(), str2);
        pos += str1.length() + str2.length();
    }
}

int main() {
    string inputStr, str1, str2;

    cout << "Введите строку, в которую мы будем вставлять другие строки: ";
    cin >> inputStr;
    cout << "Введите подстроку, после которой мы вставим строку : ";
    cin >> str1;
    cout << "Введите вставляемую строку: ";
    cin >> str2;

    insertSubstring(inputStr, str1, str2);

    cout << inputStr << endl;

    return 0;
}

/*
test_input:
abcdabcdad
ab
1

test_output:
ab1cdab1cdad
*/