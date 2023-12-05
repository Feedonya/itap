#include <iostream>

using namespace std;

int main() {
    float e;//вводим епсилон (>0)
    cout << "Введите епсилон: ";// 0.0001
    cin >> e;

    float three = 3, sign = 1;//знаменатель и числитель
    float temp = 1.0 / (three); 
    float ans = 0;//сумма | 0.333333343 | 0.296296299 | ...

    while (e <= abs(temp)) {//считаем бесконечную сумму до точности епсилона | abs - модуль числа (нужен ибо переменная temp может принять отрицательные значения)
        temp = sign / (three);
        three *= 9;
        sign *= -1;
        ans += temp;
    
    }

    cout << ans << std::endl;

    return 0;
}