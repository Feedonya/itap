#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    ifstream in("input.txt");
    ofstream out("output.txt");

    string x, ans;
    
    while (getline(in, x)) {
        ans = "";
        for (int i = 0; i < x.size(); ++i) {
            if (i % 2 == 0) {
                ans += x[i];
            }
        }
        out << ans << endl;
    }
    
    in.close();
    out.close();

    return 0;
}
