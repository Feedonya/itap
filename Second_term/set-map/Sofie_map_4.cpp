#include <bits/stdc++.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

// Функция для чтения слов из файла и подсчета их вхождений
map<string, int> countWords() {
    map<string, int> wordCount;
    string line, word;

    while (in >> word) {
        wordCount[word]++;
    }

    in.close();
    return wordCount;
}

// Функция для поиска k слов, встречающихся реже остальных
vector<pair<int, string>> findKLeastFrequentWords(const map<string, int>& wordCount, int k) {
    // Переносим данные из map в вектор пар (count, word)
    vector<pair<int, string>> frequencyVec;
    for (const auto& pair : wordCount) {
        frequencyVec.emplace_back(pair.second, pair.first);
    }

    // Сортируем вектор по количеству вхождений
    sort(frequencyVec.begin(), frequencyVec.end());

    // Вектор для хранения k наименее частых слов
    vector<pair<int, string>> leastFrequentWords;
    for (int i = 0; i < k && i < frequencyVec.size(); ++i) {
        leastFrequentWords.push_back(frequencyVec[i]);
    }

    return leastFrequentWords;
}

int main() {
    int k;
    cout << "Введите k: ";
    cin >> k;

    // Подсчет слов
    map<string, int> wordCount = countWords();

    // Нахождение k слов, встречающихся реже остальных
    vector<pair<int, string>> result = findKLeastFrequentWords(wordCount, k);

    // Вывод результата
    cout << "Слова, встречающиеся реже остальных (k = " << k << "):" << endl;
    for (const auto& pair : result) {
        cout << pair.second << ": " << pair.first << endl;
    }

    return 0;
}
