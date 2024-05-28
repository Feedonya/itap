#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

class WordCounter {
private:
    map<string, int> wordCount;
    static int instanceCount;  // Статическое поле для подсчета количества экземпляров класса

public:
    // Конструктор по умолчанию
    WordCounter() {
        instanceCount++;
    }

    // Конструктор, принимающий имя файла
    WordCounter(const string& filename) {
        instanceCount++;
        processFile(filename);
    }

    // Деструктор
    ~WordCounter() {
        instanceCount--;
    }

    // Статический метод для получения количества экземпляров класса
    static int getInstanceCount() {
        return instanceCount;
    }

    // Метод для обработки файла
    void processFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Не удалось открыть файл " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;

            while (ss >> token) {
                if (!isNumber(token)) {
                    wordCount[token]++;
                }
            }
        }

        file.close();
    }

    // Метод для проверки, является ли строка числом
    bool isNumber(const string& str) const {
        for (char ch : str) {
            if (!isdigit(ch)) {
                return false;
            }
        }
        return true;
    }

    // Метод для вывода результата
    void printWordCount() const {
        for (const auto& pair : wordCount) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    // Перегрузка оператора += для добавления слов из другого WordCounter
    WordCounter& operator+=(const WordCounter& other) {
        for (const auto& pair : other.wordCount) {
            wordCount[pair.first] += pair.second;
        }
        return *this;
    }
};

// Инициализация статического поля
int WordCounter::instanceCount = 0;

int main() {
    // Создание первого экземпляра WordCounter
    WordCounter counter1("input1.txt");
    counter1.printWordCount();

    // Создание второго экземпляра WordCounter
    WordCounter counter2("input2.txt");
    counter2.printWordCount();

    // Вывод количества экземпляров класса
    cout << "Количество экземпляров WordCounter: " << WordCounter::getInstanceCount() << endl;

    // Объединение результатов двух экземпляров
    counter1 += counter2;
    cout << "Объединенные результаты:" << endl;
    counter1.printWordCount();

    return 0;
}
