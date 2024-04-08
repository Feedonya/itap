#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ofstream out("binary.dat", ios::binary);

	int n;//вводим кол-во чисел
	cout << "Введите кол-во чисел: ";
	cin >> n;
	cout << "Введите числа: ";
	
	for (int i = 0; i < n; i++) {
		double a;
        cin >> a;//вводим числа, которые пойдут в бинарный файл
		out.write((char *)&a, sizeof(double));// записываем числа в бинарный файл
	}
	out.close();

	ifstream in("binary.dat", ios::binary);

	int index = 0;
	double d, i = 0;
	while (in.read((char*)&d, sizeof(double))) {
        if (index%2 == 0){//считаем сумму четных чисел
            i += d;
        }
        index++;
	}
    cout << '\n' << i / abs(index/2) << ' ';//выводим че нужно по условию

	return 0;
}