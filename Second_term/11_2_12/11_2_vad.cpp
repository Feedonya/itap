#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

bool read(int**& matrix, int& n) {
    in >> n;

    matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> matrix[i][j];
        }
    }
    return true;
}

void print(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << matrix[i][j] << " ";
        }
        out << endl;
    }
}

// допилить сортировку и на сдачу
void sortDiagonal(int** matrix, int n, int row, int col) {
    for (int r = row, c = col; r < n && c < n; r++, c++) {
        int tempR = r;
        int tempC = c;
        for (int r2 = r + 1, c2 = c + 1; r2 < n && c2 < n; r2++, c2++) {
            if (matrix[tempR][tempC] < matrix[r2][c2]) {
                tempR = r2; tempC = c2;
            }
        }
        if (matrix[r][c] < matrix[tempR][tempC]) {
            swap(matrix[r][c], matrix[tempR][tempC]);
        }
    }
}

int main() {
    int** matrix = nullptr;
    int n;

    read(matrix, n);

    for (int i = 1; i < n; ++i) {
        sortDiagonal(matrix, n, i, 0); // Сортируем диагональ, параллельную главной, начинающуюся в (i,0)
    }
    for (int j = 1; j < n; ++j) {
        sortDiagonal(matrix, n, 0, j); // Сортируем диагональ, параллельную главной, начинающуюся в (0,j)
    }

    print(matrix, n);

    in.close();
    out.close();
    return 0;
}