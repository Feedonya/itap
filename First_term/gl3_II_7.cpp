#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL,"Russian");

    string day;
    cout << "Введите день недели: ";
    cin >> day;
    
	if (day == "ПН" || day == "Понедельник") {
    	cout << "9:00 - 17:00" << endl;
    }
	else if (day == "ВТ" || day == "Вторник") {
		cout << "8:00 - 20:00" << endl;
	}
    else if (day == "СР" || day == "Среда") {
        cout << "10:00 - 16:00" << endl;
    }
    else if (day == "ЧТ" || day == "Четверг") {
        cout << "9:00 - 17:00" << endl;
    }
    else if (day == "ПТ" || day == "Пятница") {
        cout << "8:00 - 16:00" << endl;
    }
    else if (day == "СБ" || day == "Суббота") {
        cout << "Выходной день" << endl;
    }
    else if (day == "ВС" || day == "Воскресенье") {
        cout << "Выходной день" << endl;
    }
    else {
        cout << "Такого дня недели не существует"<< endl;
    }
    return 0;
}
