#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");
ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\input.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\output.txt");

void read(int**& matrix, int& n) {
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
}

void print(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << matrix[i][j] << " ";
        }
        out << endl;
    }
}



int main() {
    int** matrix;
    int n;

    read(matrix, n);
	int i = 0, j = 1;
	for (int k = 0; k < n/2; k++){
        for (i, j; j>=0; i++, j--){//обходим с 1 по n (диагонали сверху)
            cout << matrix[i][j] << ' ';//ДОБАВЛЯЕМ ЭТО В МАССИВ ДЛЯ ДАЛЬНЕЙШЕЙ СОРТИРОВКИ
        }
        i = 0;
        j = 2+k;
        //вызываем сортировку с элементами массива
        //выводим отсортированный массив в файл
        //обнуляем массив
    }
	//вызываем сортировку с элементами массива
	cout << '\n';
	
	i = 1;
    j = 3;
	for (int k = 0; k < n/2; k++){
        for (i, j; j>2; i++, j--){//обходим с 1 по n (диагонали снизу)
            cout << matrix[i][j] << ' ';
        }
        i = 2;
        j = 3+k;
        //вызываем сортировку с элементами массива
        //выводим отсортированный массив в файл
        //обнуляем массив
    }

    print(matrix, n);

    in.close();
    out.close();
    return 0;
}
