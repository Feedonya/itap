#include <iostream>
#include <cmath>
using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    double n, S;
    cout << "Введите n: ";
    cin >> n;

    int sign = 1;
    
    for (double i = 1; i <= n; ++i){
        S += (sign / (4*i*i+4*i+1));
        sign = -sign;
    }

    cout << "При n = " << n << " значение S = " << S;

    return 0;
}