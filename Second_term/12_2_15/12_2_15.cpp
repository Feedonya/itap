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
    }
    
    for (int &num : a){
        if (num < 0) {
            num *= 2;
        }
    }

    for (int num : a){
        cout << num << " ";
    }
    return 0;
}