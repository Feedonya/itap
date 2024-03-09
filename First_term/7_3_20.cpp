#include <iostream>
#include <string>

int main() {
    std::string sentence;
    
    // вводим строку
    std::cout << "Введите строку: ";
    std::getline(std::cin, sentence);
    
    // считаем кол-во слов в строке
    int wordCount = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n' || sentence[i] == '!' || sentence[i] == '?') {
            wordCount++;
        }
    }


    std::string wordToDelete;
    std::string newSentence = "";
    std::string wordBuffer = "";
    for (int i = 0; i < sentence.length(); i++) { // проходим по всем словам
        if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n' || sentence[i] == '!' || sentence[i] == '?') { // разделяем слова

            if (wordBuffer != wordToDelete) {
                newSentence += wordBuffer + " ";
            }
            wordBuffer = "";
        } else {
            wordBuffer += sentence[i];
        }
    }
    if (wordBuffer != wordToDelete) {
        newSentence += wordBuffer;
    }
    
    std::cout << "Измененная строка: " << newSentence << std::endl;
    
    return 0;
}
/*
Структура программы:
1) считываем строку
2) определяем количество слов в предложении
3) проходим двойным циклом for по всем словам: Если находим слово из буфера - удаляем его
4) выводим строку
*/

/*
Напиши программу на C++ используя только библиотеку string и iostream, которая:
1) считываем строку
2) определяем количество слов в предложении
3) проходим двойным циклом for по всем словам, выбирая i слово за выбранное слово: Если находим выбранное слово - удаляем его
4) выводим строку
*/

// Hello beautiful world, Hello beautiful creature.