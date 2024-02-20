#include <fstream>
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    ifstream in("input.txt");
    ofstream outg("g.txt");
    ofstream outh("h.txt");

    char s;

    while (in >> s){
        if (isdigit(s)){
            outg << s << " ";
        }
        else{
        	outh << s << " ";
		}
    }
    
    in.close();
    outg.close();
    outh.close();

    return 0;
}
