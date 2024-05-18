//Во входном файле задан набор слов и целых чисел, разделённых пробелами.
//2) Для каждого слова, не являющегося числом, подсчитать количество его вхождений

// 123 hello hello 123 456 ok good 654 hello ok good goodbye
// hello 3 ok 2 good 2 goodbye 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\set-map\\input_map.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\set-map\\output_map.txt");
//ifstream in("input_map.txt");
//ofstream out("output_map.txt");

// Функция для проверки, является ли строка числом
bool isNumber(const string& str){
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

int main() {
    map<string, int> wordCount;
    string line;

    while (getline(in, line)){
        stringstream ss(line);
        string token;

        while (ss >> token) {
            if (!isNumber(token)){
                wordCount[token]++;
            }
        }
    }

    in.close();

    for (const auto& pair : wordCount){
        out << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
