#include <iostream>

using namespace std;

int main() {
	
    setlocale(LC_ALL,"Russian");
    
    unsigned day;
    cout<<"Введите день недели: ";
    cin >> day;
    
    
    switch(day) {
    	case 1://Понедельник
    		case 3://Среда
    			case 5: cout << "9:00 - 18:00"<<endl; break;//Пятница
    	case 2://Вторник
			case 4: cout << "7:00 - 16:00"<<endl;break;//Четверг
    	case 6://Суббота
    		case 7: cout <<"Выходной"<<endl;break;//Воскресенье
    	default: cout << "Введите верный день недели"<<endl;//Неверный ввод
	}
    
    return 0;
}
