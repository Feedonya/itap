#include <iostream>

using namespace std;

float result_func(float x, float a, float b, float c){
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

int main(){
    setlocale(LC_ALL,"Russian");

    float A,B,h,ans;

    cout << "¬ведите A,B,h: ";
    cin >> A >> B >> h;
    //cout << endl;
    
    float a,b,c;
    cout << "¬ведите a,b,c: ";
    cin >> a >> b >> c;


    for (float i = A; i <= B; i += h){
        ans = result_func(i,a,b,c);
        cout << "ƒл€ x = " << i << " «начение y равно: " << ans << endl;
    }

    return 0;
}
