#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");
    
    int n;
    cout << "Введите размерность одномерного массива: ";
    cin >> n; // 10
    
    int *a = new int[n];

    int m = INT_MIN;

    cout << "Введите массив: " << endl;
    for (int i=0; i<n; ++i){
        cin >> a[i]; // -1 -2 -3 1 2 2 -1 -2 2 1
        if (m < a[i])
            m = a[i];
    }

    for (int i=0; i<n; ++i){
        if (a[i]!=m)
            cout << i << " ";
    }

    return 0;
}