#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\input.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\output.txt");

// Функция для считывания матрицы из файла
void input(int *n, int ***matrix){
    in >> *n;
}
// Функция для вывода матрицы в файл
// Функция для сортировки массива методом пузырька
// Функция для сортировки диагонали матрицы по возрастанию элементов

int main(){
    int n;
    int** matrix = nullptr;

    input(&n,&matrix);

    return 0;
}

/*
6 8 3 2
4 9 1 5
7 5 2 3
1 6 4 7
*/