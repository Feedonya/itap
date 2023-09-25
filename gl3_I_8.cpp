#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int r = 25;
    int x,y;
    
    setlocale(LC_ALL,"Russian");
    
    cout << "Введите x,y: " << endl;
    cin >> x >> y;
    
    if (y <= -abs(x) && sqrt(x*x+y*y) <= r) {
        if ( (y < -abs(x)) && (sqrt(x*x+y*y) < r) ) {
    	    cout << "Да";
        }
        else {
            cout << "На границе";
        }
	}
	else {
	    cout << "Нет";
	}
    return 0;
}
