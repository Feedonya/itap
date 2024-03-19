#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

// Функция для считывания матрицы из файла
bool read(const char* filename, int**& matrix, int& n){
    // Чтение размера матрицы
    in >> n;

    // Выделение памяти для матрицы
    matrix = new int* [n];
    for (int i = 0; i < n; ++i){
        matrix[i] = new int[n];
    }

    // Чтение матрицы из файла
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            in >> matrix[i][j];
        }
    }
    return true;
}

// Функция для вывода матрицы в файл
void print(int** matrix, int n, ofstream& out){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            out << matrix[i][j] << " ";
        }
        out << endl;
    }
}

// Функция для сортировки массива методом пузырька
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для сортировки диагонали матрицы по возрастанию элементов
void sortDiagonal(int matrix[], int n){
    for (int i = 0; i < n; i++){
        int row = i;
        int col = i;
        int diagonalLength = 0;
        while (row < n && col < n){
            diagonalLength++;
            row++;
            col++;
        }

        int *diagonal = new int[diagonalLength];
        row = i;
        col = i;
        for (int j = 0; j < diagonalLength; j++){
            diagonal[j] = matrix[row * n + col];
            row++;
            col++;
        }

        bubbleSort(diagonal, diagonalLength);

        row = i;
        col = i;
        for (int j = 0; j < diagonalLength; j++){
            matrix[row * n + col] = diagonal[j];
            row++;
            col++;
        }

        delete[] diagonal;
    }
}



int main(){
    
    return 0;
}