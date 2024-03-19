#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");
    SetConsoleCP(1251);

    vector <int> a;
    int i;
    cout << "Введите элементы массива: ";
    while (cin >> i){
        a.push_back(i);
    }

    vector <int>::iterator max = max_element(a.begin(), a.end()); //возвращает итератор
    replace(a.begin(), a.end(), *max, 0);
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }

    return 0;
}