#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");
    ifstream in("input.txt");
    ofstream out("output.txt");
    string s;
    while (in.peek() != EOF){//!in.eof()){
        getline(in,s);
        cout << s;
        out << s << endl;
    }
    
    

    in.close();
    out.close();
    return 0;
}