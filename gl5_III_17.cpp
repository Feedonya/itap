#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    float e;
    cout << "Введите Эпсилон: "; 
    cin >> e;

    float ans = 0.04761904762;
    int five = 5 , four = 16;
    
    while (e >= ans){
        ans += 1.0/(five+four);

        five *= 5;
        four *= 4;
    }
    
    cout << ans;

    return 0;
}