#include <iostream>

using namespace std;

int main(){
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) 
        arr[i] = new int[cols];
    

    cout << "Введите массив:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){ 
            cin >> arr[i][j];
        }
    }
    /*
    // Вводим значения в двумерный массив
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++){
            cout << "Введите значение в [" << i << "][" << j << "] позиции: ";
            cin >> arr[i][j];
        }
    */

   // Вводим вектор
    int* vec = new int[rows];
    cout << "Enter " << rows << " values for the vector: ";
    for (int i = 0; i < rows; i++) 
        cin >> vec[i];
    
    // Меняем четные столбцы на вектор
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j += 2) 
            arr[i][j] = vec[i];


    // Выводим преобразованный массив
    cout << "Преобразованный массив:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){ 
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
    

    // Очищаем память
    for (int i = 0; i < rows; i++) 
        delete[] arr[i];
    
    delete[] arr;
    delete[] vec;

    return 0;
}
/*
5
3

1) 1 2 3       6 2 6
2) 1 2 3       6 2 6
3) 1 2 3  - >  6 2 6
4) 1 2 3       6 2 6
5) 1 2 3       6 2 6
*/