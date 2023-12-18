#include <iostream>

using namespace std;

// Шаблон для ввода двумерного массива
template <typename T>
void inputArray(T** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Введите значение для элемента [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

// Шаблон для вывода двумерного массива
template <typename T>
void outputArray(T** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Шаблон для решения основной задачи - подсчета среднего арифметического ненулевых элементов, расположенных над побочной диагональю
template <typename T>
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

    // Создание и заполнение двумерного массива
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    inputArray(arr, rows, cols);

    // Вывод двумерного массива
    cout << "Наш массив:" << endl;
    outputArray(arr, rows, cols);

    // Подсчет среднего арифметического ненулевых элементов над побочной диагональю
    double average = averageAboveSecondaryDiagonal(arr, rows, cols);
    cout << "Среднее значение ненулевых элементов над вторичной диагональю равно: " << average << endl;

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
