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

void sort(int* arr, int n){
    int temp;
    for (int i = 0; i < n-1; ++i){
        for (int j = n-1; j > i; --j){
            if (arr[j] < arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}



int main(){
    int** matrix;
    int n;

    read(matrix, n);

	int i = 0, j = 1, len_of_mas = 0;
	for (; j < n-1; j++){
        int temp_i = i, temp_j = j;

        len_of_mas = 0;
        int* a = new int[j+1];//обнуляем массив
        for (; j>=0; i++, j--){
            a[len_of_mas] = matrix[i][j];
            len_of_mas++;
        }

        sort(a,len_of_mas); //вызываем сортировку с элементами массива

        i = temp_i;
        j = temp_j;
        for (int l = 0; l < len_of_mas; i++, j--, l++){//выводим отсортированный массив в файл
            matrix[i][j] = a[l];
        }

        i = temp_i;
        j = temp_j;
    }

    i = 1, j = 3, len_of_mas = 0;
	for (; i < n-1; i++){
        int temp_i = i, temp_j = j;

        len_of_mas = 0;
        int* a = new int[i+1];//i+1 or j-1?
        for (; i < n; j--, i++){//обходим с 1 по n (диагонали снизу)
            a[len_of_mas] = matrix[i][j];
            len_of_mas++;
        }

        sort(a,len_of_mas);

        i = temp_i;
        j = temp_j;
        for (int l = 0; l < len_of_mas; i++, j--, l++){//выводим отсортированный массив в файл
            matrix[i][j] = a[l];
        }

        i = temp_i;
        j = temp_j;
    }


    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    print(matrix, n);

    in.close();
    out.close();
    return 0;
}