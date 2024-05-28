#include <iostream>
#include <cmath>

using namespace std;

float result_func(float x){
	if (x <= 0){
		throw "Функция не определена";
	}
    return (log(pow(x,4)-1)*log(1+x));
}

int main(){
    setlocale(LC_ALL,"Russian");

    float A,B,h,ans;

    cout << "Введите A,B,h: ";
    cin >> A >> B >> h;


    for (float i = A; i <= B; i += h){
    	try{
    		ans = result_func(i);
    		cout << i << '\t' << ans << endl;
		}
		catch(const char* s){
			cout << i << '\t' << "Функция не определена" << endl;
		}
        
    }
    return 0;
}
