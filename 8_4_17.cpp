#include <iostream>

using namespace std;

float F(float x, float a, float b, float c){

    if (x < 93.0){
        return a+b*x;
    }
    else if (x < 121.0){
        return b-a*c;
    }
    else{
        return a*b*x;
    }

}

void F(float x, float &y){//выводим значения
    cout << "Для x = " << x << " Значение y равно: " << y << endl;
}

int main(){
    setlocale(LC_ALL,"Russian");

    float A, B, h, y;

    cout << "Введите A, B, h: ";
    cin >> A >> B >> h;

    float a,b,c;
    cout << "Введите a, b, c: ";
    cin >> a >> b >> c;

    for (float x = A; x <= B; x += h){

        y = F(x,a,b,c);
        F(x,y);
    }

    return 0;
}