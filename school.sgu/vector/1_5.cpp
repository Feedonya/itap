#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    int flag = 0;
    vector <double> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > 0){
            flag = i;
        }
    }

    double sum = 0;
    for (int i = 0; i < flag; i++){
        sum += a[i];
    }
    
    cout <<  sum;

    return 0;
}