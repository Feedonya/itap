#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int n;
    cout << "Введите кол-во элементов массива: ";
    cin >> n;
    vector <int> a(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int max = *max_element(a.begin(), a.end());
    replace(a.begin(), a.end(), max, 0);

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    return 0;
}