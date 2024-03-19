#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int n;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    vector <int> a(n);   
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < 0){
            auto multi = accumulate(i, i, 1, multiplies<int>());
        }
    }

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    return 0;
}