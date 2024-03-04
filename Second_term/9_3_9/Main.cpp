#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ofstream out("binary.dat", ios::binary);

	int n;
	cout << "Введите число n: ";
	cin >> n;
	cout << "\n";
	
	for (int i = 0; i <= n; i++) {
		int a = rand();
		out.write((char *)&a, sizeof(int));
	}
	out.close();

	ifstream in("binary.dat", ios::binary);

	int i = 0;
	double d;
	while (in.read((char*)&d, sizeof(double))) {
		cout << d << '\n';

		in.seekg(sizeof(double), ios::cur);
	}

	return 0;
}