#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    double k, sign = 1.0; // k - конечное значение суммы; sign - числитель
    cout << "Введите k: ";
    cin >> k;

    double ans = 0.0, square = 0.0;//сумма и числитель

    for (int n = 1; n <= k; ++n){ // 1; 0.75; 0.861111; 0.798611; 0.838611; 0.810833; 0.831241 ...
        square = n*n;
        ans += (sign/square);
        sign = -sign;

        cout << "Для n = " << n << " Ответ равен: " << ans << endl;
    }

    return 0;
}