#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
//ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_2\\input.txt");
//ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_2\\output.txt");

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


void sort(int *A, int L, int R){
    int i = L;
    int j = R;
    int piv = A[(i + j) / 2];
    while (i <= j){
        while (A[i] > piv)
            i++;
        while (A[j] < piv)
            j--;
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (L < j)
        sort(A, L, j);
    if (i < R)
        sort(A, i, R);
}


int main(){
    int** matrix;
    int n;

    read(matrix, n);
    int* a = new int[n];

    for(int i = 0; i < n; i++){
        for (int j = 0; j< n; j++){
            a[j] = matrix[i][j];
        }

        sort(a,0,n-1);

        for(int j = 0; j < n; j++){
            matrix[i][j] = a[j];
        }
    }

    print(matrix, n);

    in.close();
    out.close();
    return 0;
}
