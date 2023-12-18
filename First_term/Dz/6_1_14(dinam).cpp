#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int n;//инициализируем и вводим одномерный динамический массив
    cout << "Введите размерность одномерного массива: ";
    cin >> n;
    cout << endl;
    int *a = new int[n];

    cout << "Введите массив: " << endl;
    for (int i=0;i<n;++i){
        cin >> a[i]; // ввод 1 2 3 4 5 6 7
        if (abs(a[i])%2==1)//если элемент нечетный - выводим его
            cout << i << " ";// вывод 0 2 4 6
    }


    cout << "\n";

    int n1, m;//инициализируем и вводим двумерный динамический массив
    cout << "Введите количество строк двумерного массива: ";
    cin >> n1;
    cout << "Введите количество столбцов двумерного массива: ";
    cin >> m;
    cout << endl;
    int ** b = new int *[n1];
    for (int i=0;i<n;++i){
        b[i] = new int[m];
    }

    cout << "Элементы двумерного массива: ";
    for (int i=0; i<n1; ++i){
        for (int j=0; j<m; ++j){
            cin >> b[i][j]; // ввод -3 5 2 10 7 1
            if (abs(b[i][j])%2==1)//если элемент нечетный - выводим его
                cout << i << " " << j << endl;// Вывод 5 10 1
        }
    }

    return 0;
}