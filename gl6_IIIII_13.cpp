#include <iostream>

using namespace std;

int* insert_in_array(int *arr, int index, int size){ // вставляем элемент после последнего максимального
    for (int i = size; i > index; --i){
        arr[i] = arr[i-1];
    }
    
    cout << "Введите желаемый элемент: ";
    cin >> arr[index];// вставляем желаемый элемент в массив

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
    int m = INT_MIN;//max element
    int mi = 0;//max index

    cout << "Введите массив: " << endl;
    for (int i=0;i<n;++i){ // находим индекс последнего максимального числа
        cin >> a[i];
        if (a[i] > m){
            m = a[i];
            mi = i;}
    }

    
    a = insert_in_array(a,mi,n);
    ++n;

    print_array(a,n);

    return 0;
}