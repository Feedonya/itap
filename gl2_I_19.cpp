#include <iostream>
#include <cmath>

using namespace std;

float distance(float x1, float x2,float y1, float y2){ // возвращает вещественное расстояние между 2-мя координатами
    return sqrt(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

float t(float a, float b, float c){ // возвращает true, если возможно, false в противном случае
    return (a < b+c) &&  (b < a+c) && (c < a+b);
}

/*

1)Вводим x1 x2 x3 y1 y2 y3 для трех точек треугольника
2)Вычисляем длину отрезков
3)Проверяем может ли быть такой треугольник
4)Profit

*/
int main(){
    setlocale(LC_ALL,"Russian");

    bool dist;

    float x1,x2,x3,y1,y2,y3;
    
    cout << "Введите координаты x1,x2,x3,y1,y2,y3: ";
    cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
    cout << endl;

    float dist1, dist2, dist3;
    dist1 = distance(x1,x2,y1,y2);
    dist2 = distance(x3,x2,y3,y2);
    dist3 = distance(x1,x3,y1,y3);

    //cout << dist1 << endl << dist2 << endl << dist3 << endl;

    bool t1;    
    t1 = t(dist1, dist2, dist3);
    
    //cout << t1 << endl;

    if (t1){// проверяем можно ли построить треугольник
        cout << "Треугольник с данными сторонами существует";
    }
    else{
        cout << "Треугольника с данными сторонами не существует";
    }

    return 0;
}