#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\9_1_3\\input.txt");
int main(){
    string next;
    int k1,k2, k = 0;
    cout << "Enter k1 ";
    cin >> k1;
    cout << "Enter k2 ";
    cin >> k2;
    while(in.peek()!=EOF){
        getline(in, next);
        if (k >= k1 && k <=2)
            cout << next << '\n';
        k++;
        
    }
    return 0;
}