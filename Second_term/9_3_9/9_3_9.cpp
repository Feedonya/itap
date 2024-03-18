#include <fstream>
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");
    
    ofstream out("binary.dat", ios::binary);

    int n, m;
    cout << "Вводим n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> m;

    for (int i = 1; i <= n; i++){
        out.write((char *)&i, sizeof(0));
    }

    out.close();
    
    ifstream in("binary.dat", ios::binary);

    int j = 0;
    while (in.read((char*)&j, sizeof(j))){
        if (j % m != 0){
            cout << j << '\n';
        }
    }

    return 0;
}