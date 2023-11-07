#include <iostream>

using namespace std;


int main(){
    setlocale(LC_ALL,"Russian");

    double b = 1, temp;

    int n;
    cout << "Введите до какого числа надо посчитать функцию: ";
    cin >> n;
    cout << "\n";
    
    
    if (n == 1){
        cout << "1";
        exit(0);
	}

    for (int i = 2; i <= n; ++i){
     
        b = 0.25 * (3*b + 1/3*b);

        cout << "Для n = " << i << " значение b равно " << b << endl;
    }

    return 0;
}
