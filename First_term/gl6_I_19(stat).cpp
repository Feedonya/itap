#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int n;
    cout << "Введите размерность одномерного массива: ";
    cin >> n; // 5

    int a[100];

    cout << "Введите массив: " << endl;
    for (int i=0;i<n;++i){
        cin >> a[i]; // 1 2 3 4 5
        if (i%2==0)
            cout << a[i] << " ";
    }

    cout << "\n";

    int n1, m;
    cout << "Введите количество строк двумерного массива: ";
    cin >> n1; // 2
    cout << "Введите количество столбцов двумерного массива: ";
    cin >> m; // 3

    int  b[100][100];

    cout << "Элементы двумерного массива";
    for (int i=0; i<n1; ++i){
        for (int j=0; j<m; ++j){
            cin >> b[i][j]; // -3 5 2 10 7
            if ((i+j)%2==0)
                cout << b[i][j] << " ";
        }
    }

    return 0;
}