#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");
ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\input.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\output.txt");

void read(int**& matrix, int& n){
    in >> n;

    matrix = new int* [n];
    for (int i = 0; i < n; ++i){
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            in >> matrix[i][j];
        }
    }
}

void print(int** matrix, int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            out << matrix[i][j] << " ";
        }
        out << endl;
    }
}

void sort(int **matrix, int rows, int cols) {
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows - 1; ++i) {
            int minIndex = i;
            for (int k = i + 1; k < rows; ++k) {
                if (matrix[k][j] < matrix[minIndex][j]) {
                    minIndex = k;
                }
            }
            if (minIndex != i) {
                swap(matrix[i][j], matrix[minIndex][j]);
            }
        }
    }
}

int main() { 
    int** matrix;
    int n;

    read(matrix, n);

    sort(matrix, n, n);

    print(matrix, n);

    in.close();
    out.close();
    return 0;
}