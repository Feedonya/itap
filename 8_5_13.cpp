#include <iostream>

using namespace std;

template <typename T>// Шаблон для ввода двумерного массива
void inputArray(T** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Введите значение для элемента [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

template <typename T>// Шаблон для вывода двумерного массива
void outputArray(T** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>// Шаблон для решения основной задачи - подсчета среднего арифметического ненулевых элементов, расположенных над побочной диагональю
double averageAboveSecondaryDiagonal(T** arr, int rows, int cols) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i + j < cols - 1 && arr[i][j] != 0) {
                sum += arr[i][j];
                count++;
            }
        }
    }
    if (count == 0) {
        return 0.0; 
    } else {
        return sum / count;
    }
}

int main() {
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** arr = new int*[rows];// Создание и заполнение двумерного массива
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    inputArray(arr, rows, cols);

    cout << "Наш массив:" << endl;// Вывод двумерного массива
    outputArray(arr, rows, cols);

    // Подсчет среднего арифметического ненулевых элементов над побочной диагональю 
    double average = averageAboveSecondaryDiagonal(arr, rows, cols);
    cout << "Среднее значение ненулевых элементов над побочной диагональю равно: " << average << endl;

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

/*
побочная диагональ - это 
  _____
  |  /|
  | / |
  |/  |
  _____

input:
3
3
1 2 3 4 5 6 7 8 9

how it works:
1 2 3       1 2
4 5 6 - >   4   -> 7/3 -> 2.33 
7 8 9

output:

2.333333
*/
