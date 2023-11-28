#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int n;
    cout << "Введите размерность одномерного массива: ";
    cin >> n;
    cout << endl;
    int *a = new int[n];
    int m = INT_MAX;
    int mi = 0;//max index

    cout << "Введите массив: " << endl;
    for (int i=0;i<n;++i){
        cin >> a[i];
        if (a[i] > m)
            mi = i
    }

    a[mi]

    return 0;
}