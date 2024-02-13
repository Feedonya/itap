#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    ifstream in("input.txt");

    string s,s1;
    int temp = 0, len;

    while (in.peek() != EOF){
        getline(in,s);
        len = s.length();
        if (len > temp)
            temp = len;
            s1 = s;
    }

	cout << s1 << endl;
    cout << temp;

    in.close();
    
    return 0;
}
