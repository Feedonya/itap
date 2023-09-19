#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x,y;
    setlocale(LC_ALL,"Russian");
    cout << "Введите x,y: " << endl;
    cin >> x,y;
    
    if (y == -abs(x))
    {
    	cout << "Да";
	}
    else if ((y == -abs(x)) && (y <= -25))
    {
    	cout << "Нет";
	}
	/*
	else
	{
		cout << "На границе";
	}
	*/
    return 0;
}
