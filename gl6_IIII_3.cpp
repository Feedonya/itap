#include <iostream>

using namespace std;

int* insert__in_array(int *arr, int m, int n){ // вставляем элемент после последнего максимального
    cin >> arr[n+1]; // вставляем желаемый элемент в массив

    for (int i = n+1; i > m; --i){
        arr[i+1] = arr[i];
    }

    return arr;
}

int main(){
    setlocale(LC_ALL,"Russian");

    int n1, m;
    cout << "Введите количество строк двумерного массива: ";
    cin >> n1;
    cout << "Введите количество столбцов двумерного массива: ";
    cin >> m;

    int ** b = new int *[n1];//инициализируем двумерный динамический массив
    for (int i=0;i<n1;++i){
        b[i] = new int[m];
    }

    for (int i=0; i<n1; ++i){//вводим элементы массива
        for (int j=0; j<m; ++j){
            cin >> b[i][j];
        }
    }

    

    return 0;
}