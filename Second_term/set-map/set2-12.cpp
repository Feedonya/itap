//В текстовом файле дано несколько строк, состоящих из латинских букв, цифр, знаков препинания и пробельных символов.
//12) Для каждой строки вывести те буквы, которые встречаются и в виде прописных, и в виде строчных.

// Lorem Ipsum Dolor Sit Amet Tt
// l i s t

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\set-map\\input_set2.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\set-map\\output_set2.txt");
//ifstream in("input_set2.txt");
//ofstream out("output_set2.txt");

set<char> findCommonLetters(const string& line){
    set<char> lowerLetters;
    set<char> upperLetters;
    set<char> commonLetters;

    // Проходим по каждому символу строки
    for (char ch : line){
        if (islower(ch)){
            lowerLetters.insert(ch);
        } else if (isupper(ch)) {
            upperLetters.insert(ch);
        }
    }

    // Проверяем, какие буквы встречаются и в нижнем, и в верхнем регистре
    for (char ch : lowerLetters){
        if (upperLetters.find(toupper(ch)) != upperLetters.end()){
            commonLetters.insert(ch);
        }
    }

    return commonLetters;
}

int main() {
    string line;
    while (getline(in, line)){
        set<char> commonLetters = findCommonLetters(line);

        for (char ch : commonLetters){
            out << ch << ' ';
        }
    }

    in.close();
    return 0;
}
