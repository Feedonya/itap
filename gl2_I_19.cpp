#include <iostream>
#include <cmath>

using namespace std;

float distance(){ // возвращает вещественное расстояние между 2-мя координатами
    float x1,x2,y1,y2;
    
    cout << "Введите координаты x1,x2,y1,y2";
    cin >> x1 >> x2 >> y1 >> y2;
    cout << endl;

    return sqrt(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

float t(){ // возвращает true, если возможно, false в противном случае
    float a,b,c;

    cout << "Введите длины сторон a,b,c";
    cin >> a >> b >> c;
    cout << endl;

    if (a < b+c){
        if (b < a+c){
            if (c < a+b){
                return true;
            }

            else{
                return false;
            }
        }

        else{
            return false;
        }
    }
    
    else{
        return false;
    }
}

int main(){
    setlocale(LC_ALL,"Russian");
    

    return 0;    
}