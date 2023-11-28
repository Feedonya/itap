#include <iostream>

using namespace std;

int* insert_in_array(int *arr, int m, int n){ // вставляем элемент после последнего максимального
    cin >> arr[n+1]; // вставляем желаемый элемент в массив

    for (int i = n+1; i > m; --i){
        arr[i+1] = arr[i];
    }

    return arr;
}

void print_array(int *arr, int n){
    for (int i = 0; n > i; ++i){
        cout << arr[i] << " ";
    }
}

int main(){
    setlocale(LC_ALL,"Russian");

    int n;
    cout << "Введите размерность одномерного массива: ";
    cin >> n;
    int *a = new int[n+1]; //заранее заводим место под вставку элемента
    int m = INT_MAX;//max element
    int mi = 0;//max index

    cout << "Введите массив: " << endl;
    for (int i=0;i<n;++i){ // находим индекс последнего максимального числа
        cin >> a[i];
        if (a[i] > m)
            m = a[i];
            mi = i;
    }

    a = insert_in_array(a,mi,n);

    print_array(a,n);

    return 0;
}