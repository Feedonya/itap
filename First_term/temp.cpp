#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

int main() {
    // настройки для программы (чтоб русский работал хоть с одинаковым регистром -_- )
    setlocale(LC_ALL,"Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string sentence, word, result;
    
    // вводим строчку
    getline(cin, sentence);

    // используется для чтения из строки слово за словом.
    istringstream iss(sentence);
    
    // проходим по предложению
    while (iss >> word) {
        size_t found = result.find(word);// поиск подстроки word в строке result и возвращает позицию, с которой она начинается
        if (found == string::npos) { // found будет равно npos (константа, указывающая на отсутствие совпадений) в случае, если подстрока word не найдена в строке result
            result += word + " "; // добавляем в конечную строчку
        }
    }

    // выводим результат
    cout << result << endl;

    return 0;
}