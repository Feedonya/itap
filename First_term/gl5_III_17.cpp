#include <iostream>

using namespace std;

int main() {
    float e;
    cout << "Введите епсилон: ";
    cin >> e;

    int five = 5;
    int four = 16;
    float temp = 1.0 / (5 + 16); // 0.04761904762 | 0.05885500268 | 0.0614796765
    float ans = 0;

    while (e <= temp) {
        ans += temp;
        five *= 5;
        four *= 4;
        temp = 1.0 / (five + four);
    }
    cout << ans << std::endl;
    return 0;
}