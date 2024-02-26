#include <fstream>
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    ofstream binaryFile("numbers.bin", ios::binary | ios::out);
    if (binaryFile.is_open()){
        for (int i = 1; i <= n; ++i){
            binaryFile.write(reinterpret_cast<const char*>(&i), sizeof(int));
        }
        binaryFile.close();
    }

        
    char s;

    in.close();
    
    return 0;
}

/*
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Задаем количество целых чисел n
    int n = 5;
    
    // Задаем число, кратность которому нужно проверять
    int divisor = 3;

    // Создаем и записываем числа в двоичный файл
    std::ofstream binaryFile("numbers.bin", std::ios::binary | std::ios::out);
    if (binaryFile.is_open()) {
        for (int i = 1; i <= n; ++i) {
            binaryFile.write(reinterpret_cast<const char*>(&i), sizeof(int));
        }
        binaryFile.close();
    }

    // Читаем числа из файла и выводим на экран те, которые не кратны divisor
    std::ifstream inFile("numbers.bin", std::ios::binary | std::ios::in);
    if (inFile.is_open()) {
        std::vector<int> numbers;
        int num;
        while (inFile.read(reinterpret_cast<char*>(&num), sizeof(int))) {
            if (num % divisor != 0) {
                numbers.push_back(num);
            }
        }
        inFile.close();

        // Выводим числа, не кратные divisor
        std::cout << "Числа в файле, не кратные " << divisor << ":\n";
        for (int num : numbers) {
            std::cout << num << " ";
        }
    } else {
        std::cerr << "Ошибка открытия файла.";
    }

    return 0;
}
*/