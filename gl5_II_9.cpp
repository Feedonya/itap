#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    int k, sign = 1, x, t = 4;
    cout << "Введите k: "; 
    cin >> k;
    cout << "Введите x: ";
    cin >> x;

    double znam = 2,chisl = x*x;
    double ans=0;

    
    for (int n=1; n<=k; ++n){
        ans += (sign * chisl) / (znam);
        chisl *= x*x;//4 16 64 256 1024
        znam *= (t * (t-1));//2 24 120 40320
        t += 2;
        sign = -sign;
        cout << "Для n = " << n << " Ответ равен: " << ans << endl;
    }

    //cout << "Для k = " << k << "Ответ равен: " << ans;

    return 0;
}