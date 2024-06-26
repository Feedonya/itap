#include <iostream>

using namespace std;

int findMin(int** arr, int rows, int cols, int currentRow, int currentCol, int minVal){
    if (currentRow == rows){//крайний случай
        return minVal;
    }
    if (currentCol == cols){//проходим дальше по строке
        return findMin(arr, rows, cols, currentRow + 1, 0, minVal);
    }
    if (arr[currentRow][currentCol] < minVal){//проверяем элемент на минимальность
        minVal = arr[currentRow][currentCol];
    }
    return findMin(arr, rows, cols, currentRow, currentCol + 1, minVal);//проходим дальше по столбцу
}

int main() {
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++){
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++){
            cout << "Введите элемент: [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    int minVal = findMin(arr, rows, cols, 0, 0, arr[0][0]);
    cout << "Минимальное значение в массиве: " << minVal << endl;

    for (int i = 0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
/*
input:
3
2
1 2 3 4 5 6

output:
1
*/