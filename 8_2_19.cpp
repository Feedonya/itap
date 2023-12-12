#include <iostream>

using namespace std;



#include <iostream>

int findMin(int** array, int rows, int cols, int currentRow, int currentCol, int min) {
    // Базовый случай: если мы дошли до конца массива
    if (currentRow == rows) {
        return min;
    }

    // Если дошли до конца текущей строки, переходим на следующую строку
    if (currentCol == cols) {
        return findMin(array, rows, cols, currentRow + 1, 0, min);
    }

    // Если текущий элемент меньше текущего минимального значения, обновляем минимум
    if (array[currentRow][currentCol] < min) {
        min = array[currentRow][currentCol];
    }

    // Рекурсивный вызов для следующего элемента
    return findMin(array, rows, cols, currentRow, currentCol + 1, min);
}

int main(){
    setlocale(LC_ALL,"Russian");
    int n, m;
    cout << "Введите размерность n, m: ";
    cin >> n >> m;

    int ** a = new int * [n];
    for (int i = 0; i < n; ++i){
        a[i] = new int [m];
    }

    cout << "Введите массив: ";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }

    int min = findMin(a, n, m, 0, 0, a[0][0]);
    std::cout << "Наименьшее значение в массиве: " << min << std::endl;

    return 0;
}