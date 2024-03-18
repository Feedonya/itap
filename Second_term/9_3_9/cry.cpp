#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Открываем файл для записи
    ofstream file("numbers.dat", ios::binary);

    int n; // Количество чисел
    cout << "Введите количество чисел: ";
    cin >> n;

    // Записываем числа в файл
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        file.write((char*)&num, sizeof(num));
    }

    file.close();

    // Открываем файл для чтения
    ifstream inFile("numbers.dat", ios::binary);

    int num, m;
    cout << "Введите m: ";
    cin >> m;
    cout << "Числа файла, не кратные " << m << ": "; 
    while (inFile.read((char*)&num, sizeof(num))){
        if (num % m != 0) { // Проверяем, не кратное ли число
            cout << num << " ";
        }
    }

    inFile.close();

return 0;
}