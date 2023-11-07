#include <iostream>
#include <cmath>
using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int n, S=0;
    cout << "Введите n: ";
    cin >> n;
    
    for (int i = 1; i <=n; ++i){
        S = S + i*i;
    }

    cout << "При n = " << n << " значение S = " << S;

    return 0;
}