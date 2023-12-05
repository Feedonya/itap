#include <iostream>
#include <string>

using namespace std;

void insertSubstring(string& str, const string& str1, const string& str2) {
    size_t pos = 0;
    while ((pos = str.find(str1, pos)) != -1){//  пока мы находим подстроку (пока .find() != -1)
        str.insert(pos + str1.length(), str2);// вставляем нашу строку после подстроки
        pos += str1.length() + str2.length();// без этой строки мы будем бесконечно добавлять строку после первой подстроки
    }
}

int main() {
    string inputStr, str1, str2;

    cout << "Введите строку, в которую мы будем вставлять другие строки: ";
    getline(cin,inputStr);
    cout << "Введите подстроку, после которой мы вставим строку : ";
    getline(cin,str1);
    cout << "Введите вставляемую строку: ";
    getline(cin,str2);

    insertSubstring(inputStr, str1, str2);

    cout << inputStr << endl;

    return 0;
}

/*
test_input:
abcdabcdad abdd
ab
1

test_output:
ab1cdab1cdad
*/