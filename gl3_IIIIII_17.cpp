#include <iostream>

using namespace std;

float result_func(int x, int a, int b, int c){
    if (x < 93){
        return a+b*x;
    }
    else if (92 < x && x < 121){
        return b-a*c;
    }
    else if (x > 120){
        return a*b*x;
    }

}

int main(){
    setlocale(LC_ALL,"Russian");

    float A,B,h,ans;

    cout << "¬ведите A,B,h: ";
    cin >> A >> B >> h;
    cout << endl;
    
    float a,b,c;
    cout << "¬ведите a,b,c: ";
    cin >> a >> b >> c;


    for (int i = A; i < B; i += h){
        ans = result_func(i,a,b,c);
        cout << "ƒл€ x = " << i << " «начение y равно: " << ans << endl;
    }

    return 0;
}
