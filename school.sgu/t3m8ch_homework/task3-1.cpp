#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    char firstLetter;
    input.get(firstLetter);

    unsigned count = 0;
    string currentLine;

    while (getline(input, currentLine)) {
        if (currentLine[0] == firstLetter) {
            ++count;
        }
    }

    output << count;

    input.close();
    output.close();

    return 0;
}