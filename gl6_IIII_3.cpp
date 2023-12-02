#include <iostream>

using namespace std;

void print_array(int **arr, int lines, int columns);
int * insert_vector_in_array(int **arr, int lines, int columns);


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

    print_array(b,n,m);

    insert_vector_in_array(b,n,m);

    print_array(b,n,m);

    return 0;
}

int* insert_vector_in_array(int **arr, int lines, int columns){ //вставляем вектор, если столбец(column) четный
    int len_vec;
    cout << "Введите длину вектора: ";
    cin >> len_vec;

    cout << "Введите вектор: ";
    int *vec = new int[len_vec];
    for (int i = 0; i < len_vec; ++i){ //инициализируем вектор
        cin >> vec[i];
    }

    for (int i = 0; i < columns; ++i){ //заменяем четные столбцы на введеный вектор
        if (i%2==0){
            for (int j = 0; j < lines; ++j){
                arr[i][j] = vec[j]; // segmentation error!!! если длина вектора меньше длины столбца -> удаляем элементы четного столбца + вводим шам вектор и приравниванием длину данного столбца на длину вектора.
            }
        }
    }

    return *arr;
}

void print_array(int **arr, int lines, int columns){//выводим массив
    for (int i = 0; lines > i; ++i){
        for (int j = 0; columns > j; ++j){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

/*
test_input:
3
5
1 2 3 1 2 3 1 2 3 1 2 3 1 2 3
1
1
*/