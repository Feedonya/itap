#include <iostream>
#include <cmath>
using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    double n, S;
    cout << "Введите n: ";
    cin >> n;
    
    for (double i = 1; i <= n; ++i){
        S += (pow(-1,i+1) / (4*i*i+4*i+1));
    }

    cout << "При n = " << n << " значение S = " << S;

    return 0;
}