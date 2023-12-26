#include <iostream>

using namespace std;

float F(float x){
    if (x < 93.0){
        return a+b*x;
    }
    else if (x < 121.0){
        return b-a*c;
    }
    else {
        return a*b*x;
    }

}

void F(float x, float &y){
    
}

int main(){
    setlocale(LC_ALL,"Russian");

    float A,B,h,ans;

    cout << "Введите A,B,h: ";
    cin >> A >> B >> h;
    
    float a,b,c;
    cout << "Введите a,b,c: ";
    cin >> a >> b >> c;


    for (float i = A; i <= B; i += h){
        ans = result_func(i,a,b,c);
        cout << "Для x = " << i << " Значение y равно: " << ans << endl;
    }

    return 0;
}

