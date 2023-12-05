#include <iostream>

using namespace std;

//находим максимальный -> вставляем после него нашу переменную
//находим индекс последнего максимального элемента -> вставляем нашу переменную на индекс+1

int* insert_in_array(int *arr, int size, int maximum){ // вставляем элемент после каждого максимального
    cout << "Введите желаемый элемент: ";
    int wish;
    cin >> wish;

    for (int i = 0; size >= i ; i++){
        if (maximum == arr[i]){//если элемент максимальный
            for (int j = size-1; i < j; --j){//вставляем после него элемент
                arr[j] = arr[j-1];
            }
            arr[i] = wish;
            ++size;//изменяем длину массива
            i++;
        }
    }

    return arr;
}

void print_array(int *arr, int size){//выводим массив
    for (int i = 0; size > i; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    setlocale(LC_ALL,"Russian");

    int n;
    cout << "Введите размерность одномерного массива: ";
    cin >> n;
    int *a = new int[n+1]; //заранее заводим место под вставку элемента

/*
    cout << "Введите массив: " << endl;
    for (int i=0;i<n;++i){ // находим индекс последнего максимального числа
        cin >> a[i];
        if (a[i] > m){
            m = a[i];
            mi = i;}
    }
*/
    int m = a[0];//максимальный элемент
    int count = 0;//количество максимальных элементов

    cout << "Введите массив: ";
    for (int i = 0; n > i; ++i){// находим максимальный элемент и индекс максимального элемента в массиве
        cin >> a[i]; // вводим элемент массива
        if (m < a[i]){
            m = a[i];
            count++;
        }
    }

    a = insert_in_array(a,n,m);
    n += count;//изменяем кол-во элементов из-за вставки

    print_array(a,n);

    return 0;
}
/*
test_input:
5
1 2 3 2 1 3 1
1

test_output:
1 2 3 1 2 1 3 1 1 если после каждого максимального



1 2 3 2 1 3 1 1 если после всех максимальных
*/