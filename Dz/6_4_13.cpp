#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введите размер массива n*n: ";
    cin >> n;

    int** arr = new int*[n];//вводим и инициализируем массив
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        cout << "Введите " << i+1 << "-ую строку: ";
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int * ans = new int[n];//массив с индексами отрицательных элементов
    

    for (int i = 0; i < n; ++i){//находим первый отрицательный элемент и записываем его индекс в одномерный массив ans
        for (int j = 0; j < n; ++j){
            if (arr[j][i] < 0){
                ans[i] = i;
                break;
            }
        }
    }

    cout << "Результат: " << endl;//выводим массив с индексами
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
/*
Ввод:
4
-1 2 3 4
1 -2 3 4
1 2 -3 4
1 2 3 -4

вывод
0 1 2 3
*/