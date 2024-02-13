#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int n;
    cout << "Введите размерность одномерного массива: ";
    cin >> n;
    cout << endl;
    int *a = new int[n];

    cout << "Введите массив: " << endl;
    for (int i=0;i<n;++i){
        cin >> a[i];
        if (i%2==0)
            cout << a[i] << " ";
    }

    cout << "\n";

    int n1, m;
    cout << "Введите количество строк двумерного массива: ";
    cin >> n1;
    cout << "Введите количество столбцов двумерного массива: ";
    cin >> m;
    cout << endl;
    int ** b = new int *[n1];
    for (int i=0;i<n;++i){
        b[i] = new int[m];
    }

    for (int i=0; i<n1; ++i){
        for (int j=0; j<m; ++j){
            cin >> b[i][j];
            if ((i+j)%2==0)
                cout << b[i][j] << " ";
        }
    }

    return 0;
}