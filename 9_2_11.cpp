#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    ifstream in("input.txt");
    ofstream outg("g.txt");
    ofstream outh("h.txt");

    string s;

    while (in.peek() != EOF){
        get(in,s);
        if (isdigit(s))
            outg << s << " ";
        else{
        	outh << s << " ";
		}
    }
    
    in.close();
    
    return 0;
}
