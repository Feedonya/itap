#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct point {
    int x, y;
    double distance();
};


double point::distance() {
    return (sqrt(pow(x, 2) + pow(y, 2)));
}

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream in("input.txt");
    ofstream out("output.txt");

    double temp1 = 0, temp;
    point coord;

    int ans_x = 0, ans_y = 0;

    while (in.peek() != EOF) {
        in >> coord.x;
        in >> coord.y;
        temp = coord.distance();
        if (temp1 < temp ){
            temp1 = temp;
            ans_x = coord.x;
            ans_y = coord.y;
        }
    }

    out << ans_x << " " << ans_y;

    in.close();

    return 0;
}