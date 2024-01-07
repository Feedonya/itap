#include <iostream>

using namespace std;

void print_array(int **arr, int lines, int columns, int len_vec);// инициализируем функции
int * insert_vector_in_array(int **arr, int lines, int columns, int len_vec);


int main(){
    setlocale(LC_ALL,"Russian");

    int n, m; //строки, столбцы
    cout << "Введите количество строк двумерного массива: ";
    cin >> n;
    cout << "Введите количество столбцов двумерного массива: ";
    cin >> m;

    int ** b = new int *[n]; //инициализируем двумерный динамический массив
    for (int i=0;i<n;++i){
        b[i] = new int[m];
    }

    cout << "Введите элементы двумерного массива: ";
    for (int i=0; i<n; ++i){ //вводим элементы массива
        for (int j=0; j<m; ++j){
            cin >> b[i][j];
        }
    }

    int len_vec;
    cout << "Введите длину вектора: ";
    cin >> len_vec;

    insert_vector_in_array(b,n,m,len_vec);

    print_array(b,n,m,len_vec);

    return 0;
}

int* insert_vector_in_array(int **arr, int lines, int columns, int len_vec){ //вставляем вектор, если столбец(column) четный
    cout << "Введите вектор: ";
    int *vec = new int[len_vec];
    for (int i = 0; i < len_vec; ++i){ //инициализируем вектор
        cin >> vec[i];
    }

    for (int i = 0; i < columns; i+=2){ //заменяем четные столбцы на введеный вектор
        for (int j = 0; j < len_vec-1; ++j){
            arr[i][j] = vec[j];
        }
    }

    return *arr;
}

void print_array(int **arr, int lines, int columns, int len_vec){//выводим массив
    for (int i = 0; lines > i; ++i){
        if (i%2==0){// выводим вектор
            for (int j = 0; len_vec > j; ++j){
                cout << arr[i][j] << " ";
            }
        }
        else{// выводим обычный столбец
            for (int j = 0; columns > j; ++j){
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

/*
test_input:
5
3
1 2 3 1 2 3 1 2 3 1 2 3 1 2 3
1
1

test_output:
1 1 2 3 1 1 2 3 1
*/