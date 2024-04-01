#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

// Функция для считывания матрицы из файла
bool read(const char* filename, int**& matrix, int& n) {
    // Чтение размера матрицы
    in >> n;

    // Выделение памяти для матрицы
    matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    // Чтение матрицы из файла
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> matrix[i][j];
        }
    }
    return true;
}

// Функция для вывода матрицы в файл
void print(int** matrix, int n, ofstream& out) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << matrix[i][j] << " ";
        }
        out << endl;
    }
}

// Функция для сортировки диагонали матрицы по возрастанию элементов
void sortDiagonal(int** matrix, int n, int row, int col) {
    
}

int main() {
    int** matrix = nullptr;
    int n;

    read("input.txt", matrix, n);

    for (int i = 1; i < n; ++i) {
        sortDiagonal(matrix, n, i, 0); // Сортируем диагональ, параллельную побочной, начинающуюся в (i,0)
    }
    for (int j = 1; j < n; ++j) {
        sortDiagonal(matrix, n, 0, j); // Сортируем диагональ, параллельную побочной, начинающуюся в (0,j)
    }

    print(matrix, n, out);

    in.close();
    out.close();
    return 0;
}
/*
6 8 3 2
4 9 1 5
7 5 2 3
1 6 4 7
*/