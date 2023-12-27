#include <iostream>

using namespace std;

template <typename T>//Шаблон для создания и заполнения массива
T** inputArray(int n, int m){
    T **arr = new T *[n];
    for (int i = 0; i < n; i++){
        arr[i] = new T[n];
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    return arr;
}

template <typename T>// Шаблон для вывода двумерного массива
void outputArray(T **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>// Шаблон для решения основной задачи - подсчета среднего арифметического ненулевых элементов, расположенных над побочной диагональю
double averageAboveSecondaryDiagonal(T** arr, int rows, int cols){
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (i + j < cols - 1 && arr[i][j] != 0){
                sum += arr[i][j];
                count++;
            }
        }
    }
    if (count == 0){
        return 0.0; 
    } else{
        return sum / count;
    }
}

int main(){
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    cout << "Целочисленный массив:" << endl;
    int **int_arr = inputArray<int>(rows, cols);
    cout << "Вывод массива: " << endl;
    outputArray(int_arr, rows, cols);
    cout << "Среднее арифметическое отрицательных элементов: " << averageAboveSecondaryDiagonal(int_arr, rows, cols) << endl;

    cout << "Вещественный массив:" << endl;
    double **double_arr = inputArray<double>(rows, cols);
    cout << "Вывод массива: " << endl;
    outputArray(double_arr, rows, cols);
    cout << "Среднее арифметическое отрицательных элементов: " << averageAboveSecondaryDiagonal(double_arr, rows, cols) << endl;

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
