#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n){
	for(long long i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}

int main(){
    setlocale(LC_ALL,"Russian");
    unsigned n;
    cout << "Введите N: ";
    cin >> n;
    cout << prime(n) << endl;

    unsigned a, b, ans = 0;
    cout << "Введите a, b через пробел: ";
    cin >> a >> b;
    

    for (int i = a; i < b; ++i){
        if (prime(i))
            ans += i;
    }

    cout << ans;

    return 0;
}