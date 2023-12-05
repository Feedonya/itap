#include <iostream>

using namespace std;

void insertAfterMax(int* arr, int& size, int value) {
    int max = arr[0];
    int count = 1;

    //находим максимум    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            count = 1;
        } else if (arr[i] == max) {
            count++;
        }
    }

    int newSize = size + count;//новый массив длинной нашего arr + кол-во максимальных элементов
    int* newArr = new int[newSize];
    int index = 0;

    //вводим в новый массив элементы, если они равняются максимальному, то вводим после него желаемый элемент
    for (int i = 0; i < size; i++) {
        newArr[index++] = arr[i];
        if (arr[i] == max) {
            newArr[index++] = value;
        }   
    }

    delete[] arr;//удаляем из памяти старый массив
    arr = newArr;//вводим вместо старого изменненый
    size = newSize;//длина нашего массива равняется длине старого + кол-во максимальных элементов
}

int main() {
    int size = 0;
    cout << "Введите размерность массива: ";
    cin >> size;
    int* arr = new int [size];
    cout <<"Введите элементы массива: ";
    for (int i = 0; i < size; ++i){
        cin >> arr[i];
    }
    int value;
    cout << "Введите желаемое значение: ";
    cin >> value;

    insertAfterMax(arr, size, value);

    // выводим массив
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}