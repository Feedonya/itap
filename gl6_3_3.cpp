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

    cout << "Введите вектор: ";
    int *vec = new int[len_vec];
    for (int i = 0; i < len_vec; ++i){ //инициализируем вектор
        cin >> vec[i];
    }

    for (int i = 0; i < n; i+=2){ //заменяем четные столбцы на введеный вектор
        for (int j = 0; j < len_vec-1; ++j){
            b[i][j] = vec[j];
        }
    }



    for (int i = 0; n > i; ++i){
        if (i%2==0){// выводим вектор
            for (int j = 0; len_vec > j; ++j){
                cout << a[i][j] << " ";
            }
        }
        else{// выводим обычный столбец
            for (int j = 0; m > j; ++j){
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;

    return 0;
}

/*
test_input:
3
5
1 2 3 1 2 3 1 2 3 1 2 3 1 2 3
1
1

test_output:
1 1 2 3 1 1 2 3 1
*/

//утечка памяти! надо зарезервировать длину двумерного массива сразу с длиной вектора и добавлять его и менять позицию