#include <iostream>

using namespace std;

void swapRows(int** arr, int n){
    if (n % 2 == 0) {//Если количество строк в массиве четное
        for (int i = 0; i < n; i += 2) {// меняем строки местами по правилу: первую строку со второй, третью — с четвертой.
            int* temp = arr[i];//переменная для временного хранения заменяемой строки
            arr[i] = arr[i+1];//заменяем четную строку на нечетную
            arr[i+1] = temp;//заменяем нечетную строку на четную
        }
    }
}

int main() {
    int n;
    cout << "Введите размер массива n*n: ";
    cin >> n;

    int** arr = new int*[n];//вводим и инициализируем массив
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        cout << "Введите " << i+1 << "-ую строку: ";
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    swapRows(arr, n);

    cout << "Результат: " << endl;//выводим измененный массив
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
Ввод:
2
1 2
3 4

вывод
3 4
1 2
*/