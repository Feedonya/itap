#include <fstream>
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\9_2_11\\input.txt");
    ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\9_2_11\\output.txt");

    int a,b;

    while (in.peek()!=EOF){
        in >> a >> b;
        if (a > b)
            out << a << ' ';
        else{
            out << b << ' ';
        }
    }
    
    in.close();
    out.close();
    return 0;
}
