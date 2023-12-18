#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x;
    setlocale(LC_ALL,"Russian");
    cout << "Введите x: " << endl;
    cin >> x;
    int a,b,c;
    a = x%10;
    b = x/10;
    //cout<<a<<" "<<b << endl;
    c = (a+b)%2;
    if (c == 0)
    {
    	cout<<"Сумма чисел является четной";
    }
	else
	{
		cout<<"Сумма чисел является нечетной";
	}
   
    return 0;
}
