#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct point {
    int x, y, z;
};


double point::distance() {
    return (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2);
}

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream in("input.txt");

    point coord;

    while (in.peek() != EOF) {
        in >> coord.x;
        in >> coord.y;
        in >> coord.z;
        coord.point();
    }


    in.close();

    return 0;
}