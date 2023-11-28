#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int n1, m;
    cout << "Введите количество строк двумерного массива: ";
    cin >> n1;
    cout << "Введите количество столбцов двумерного массива: ";
    cin >> m;

    int ** b = new int *[n1];
    for (int i=0;i<n1;++i){
        b[i] = new int[m];
    }

    for (int i=0; i<n1; ++i){
        for (int j=0; j<m; ++j){
            cin >> b[i][j];
            
        }
    }

    return 0;
}