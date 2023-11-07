#include <iostream>

using namespace std;

float result_func(int x){
    float a,b,c;
    cout << "Введите значения a,b,c";
    cin >> a >> b >> c;

    if (x < 93){
        return a+b*x;
    }
    else if (92 < x < 121){
        return b-a*c;
    }
    else if (x > 120){
        return a*b*x;
    }

}

int main(){
    setlocale(LC_ALL,"Russian");

    float A,B,h,ans;

    cout << "Введите начальную A, конечную B и шаг h: ";
    cin >> A >> B >> h;
    cout << endl;

    for (int i = A; i < B; i += h){
        ans = result_func(i);
        cout << "Для" << i << "Значение равно" << ans << endl;
    }

    return 0;
}