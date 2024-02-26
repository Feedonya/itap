#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    ifstream in("input.txt");
    ofstream out("output.txt");

    char s;
    string x;

    in.get(s);

    int count = 0;


    while (getline(in, x)){
        if (x[0] == s){
        	cout << x[0];
            ++count;
        }

    }

    out << count;

    in.close();
    out.close();

    return 0;
}
